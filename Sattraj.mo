package Sattraj
record Vector
  Real x;
  Real y;
  Real z; 
end Vector;
model Satellite
  parameter Real ecc = 0.0086707 "Eccentriciy";
  parameter Real M0 = 224.6824 "Mean anomaly at epoch (deg)";
  parameter Real N0 = 2.00574691105728 "Mean motion at Epoch (rev/d)";
  parameter Real Ndot2 = 0.00000015 "TLE drag paramter rev/d^2";
  parameter Real Nddot6 = 0.0"TLE paramter rev/d^3";
  parameter Real tstart = 0 "Simulation start time,seconds since Epoch (s)";
  parameter Real pi = 3.141592653589793;
  parameter Real GM = 398600.4418 "km^3/s^2";
  Real M, E, theta, r, a, x, y, h, dr, dx, dy,n, Mean; // removed n and dM
public
  output Vector p_sat_p;
  output Vector v_sat_p;
initial equation
   M = (M0 + N0*(360/86400)*tstart + 360*Ndot2*(tstart/86400)^2 + 360*(Nddot6)*(tstart/86400)^3);
equation
   //working
   der(M) = (N0*(360/86400) + 2*360*Ndot2*((time)/86400^2) + 3*360*(Nddot6)*((time^2)/86400^3));
   n=der(M);
   M*3.141592653589793/180 = E + ecc*sin(E);
   Mean = mod(M, 360);
   tan(E/2) = sqrt((1 - ecc)/(1 + ecc))*tan(theta/2);
   n*3.141592653589793/180 = sqrt(GM/a^3);
   r = a*(1 - ecc^2)/(1 + ecc*cos(theta));
   x = r*cos(theta);
   y = r*sin(theta);
   r = (h^2/GM)/(1 + ecc*cos(theta));
   dr = (GM/h)*ecc*sin(theta);
   dx = -(GM/h)*sin(theta);
   dy = (GM/h)*(ecc + cos(theta));
   
   p_sat_p.x = x;
   p_sat_p.y = y;
   p_sat_p.z = 0;
   v_sat_p.x = dx;
   v_sat_p.y = dy;
   v_sat_p.z = 0;
end Satellite;

model GndStn
  parameter Real longitude = 20 "Station longitude (deg)";
  parameter Real latitude = 30 "Station latitude (deg)";
  parameter Real elevation = 50 "Station elevation (m)";
  constant Real a = 6378137 "Earth reference ellipsoid equatorial radius (m)";
  constant Real f = 1/298.257223563 "Earth reference ellipsoid flattening";
  constant Real pi = 3.141592653589793;
  Real N, lat, long, x, y, z;
public
  output Vector p_stn_ecf "Station ECF coordinates";
equation
  lat = latitude*pi/180;
  long = longitude*pi/180;
  N = a/(sqrt(1-(2*f-f^2)*(sin(lat))^2)); 
  x = (N+elevation)*cos(lat)*cos(long);
  y = (N+elevation)*cos(lat)*sin(long);
  z = ((1-(2*f-f^2))*N+elevation)*sin(lat);
  p_stn_ecf.x = (N+elevation)*cos(lat)*cos(long);
  p_stn_ecf.y = (N+elevation)*cos(lat)*sin(long);
  p_stn_ecf.z = ((1-(2*f-f^2))*N+elevation)*sin(lat);
end GndStn; 
function theta_t
  input Real din "JD of the time of interst (not time difference since J2000)";
  //input Real t "time of interest";
  input Real tm "time of mindnight of day of interest";
  output Real theta_t "GMST angle (deg)";
protected
  Real d = din - 2451545.0;
 // Real d = 1879.386107;
  Real T = d/36525;
  Real theta_mid;
  Real r;
algorithm
  theta_mid := mod(24110.54841 + 8640184.812866*T +0.093104*T^2 - 0.0000062*T^3,86400)*360/86400;
  r:=1.002737909350795 + 5.9006*10^(-11)*T -5.9*10^(-15)*T^2;
  //theta_t := theta_mid + 360*r*(2453424.416366-2453423.500000)/86400;//(time of interest ... in this case start of tracking time - tmidnight of start of tracking period)
  theta_t := mod(theta_mid + 360*r*((din-tm)*86400)/86400,360);//(time of interest ... in this case start of tracking time - tmidnight of start of tracking period)
end theta_t; 
function sat_ECF
  input Vector p_sat_eci "Satellite position, ECI coords (km)";
  input Vector v_sat_eci "Satellite velocity, ECI coords (km/s)";
  input Real theta_t "GMST (deg)";
  
  output Vector p_sat_ecf "Satellite position, ECF coords (km)";
  output Vector v_sat_ecf "Satellite velocity, ECF coords (km/s)";
protected
  Real pi = 3.141592653589793;
  Real p[3,1];
  Real v[3,1];
  Real theta_rad = theta_t*pi/180; // convert to radians
  Real side_time = 23*3600 + 56*60 + 4.091; // sidereal time
  Real sidereal_rot_rate = 2*pi/side_time; //sidereal rotation rate
  Real R1[3,3] = [ cos(theta_rad),sin(theta_rad),0; -sin(theta_rad),cos(theta_rad),0; 0,0,1];
  Real R2[3,3] = [ -sin(theta_rad),cos(theta_rad),0; -cos(theta_rad),-sin(theta_rad),0; 0,0,0];
algorithm
  p := R1* [p_sat_eci.x;p_sat_eci.y;p_sat_eci.z]; // p_ecf = R1*p_eci
  v := R1* [v_sat_eci.x;v_sat_eci.y;v_sat_eci.z] - (-sidereal_rot_rate)*R2* [p_sat_eci.x;p_sat_eci.y;p_sat_eci.z]; //v_ecf = R1*v_eci - vrel; vrel = -sidereal rotation rate*R2*p_eci
  p_sat_ecf.x := p[1,1];
  p_sat_ecf.y := p[2,1];
  p_sat_ecf.z := p[3,1];
  v_sat_ecf.x := v[1,1];
  v_sat_ecf.y := v[2,1];
  v_sat_ecf.z := v[3,1];
end sat_ECF;
function sat_ECI
  input Vector p_sat_pf "Satellite position, PF coords (km)";
  input Vector v_sat_pf "Satellite velocity, PF coords (km/s)";
  input Real ecc "Eccentricity";
  input Real raan "Right Ascension of ascending node (deg)";
  input Real inc "Inclination angle (deg)";
  input Real argper "Argument of Perigee (deg)";
  input Real N "Mean Motion (rev/d)";
  output Vector p_sat_eci "Satellite position ECI coords (km)";
  output Vector v_sat_eci "Satellite velocity ECI coords (km)";
protected
  Real pi = 3.141592653589793;
  Real w = argper*pi/180;
  Real r = raan*pi/180;
  Real i = inc*pi/180;
  Real pTemp[3,1];
  Real vTemp[3,1];
  Real transformation_matrix[3,3] = [cos(w)*cos(r)-cos(i)*sin(w)*sin(r), -sin(w)*cos(r)-cos(i)*cos(w)*sin(r), sin(i)*sin(r); cos(i)*cos(r)*sin(w)+cos(w)*sin(r), cos(i)*cos(w)*cos(r)-sin(w)*sin(r), -sin(i)*cos(r); sin(i)*sin(w), sin(i)*cos(w), cos(i)];
algorithm
  pTemp := transformation_matrix * [p_sat_pf.x; p_sat_pf.y; p_sat_pf.z];
  vTemp := transformation_matrix * [v_sat_pf.x; v_sat_pf.y; v_sat_pf.z];
  p_sat_eci.x := pTemp[1,1];
  p_sat_eci.y := pTemp[2,1];
  p_sat_eci.z := pTemp[3,1];
  v_sat_eci.x := vTemp[1,1];
  v_sat_eci.y := vTemp[2,1];
  v_sat_eci.z := vTemp[3,1];
end sat_ECI;
function range_topo2look_angles
  input Real az_vel_lim "Azimuth velocity limit (deg/s)";
  input Real el_vel_lim "Elevation velocity limit (deg/s)";
  input Vector p_sat_topo "Satellite position in topo coords (km)";
  input Vector v_sat_topo "Satellite velocity in topo coords (km/s)";
  output Real azimuth "Azimuth angle (deg)";
  output Real elevation "Elevation angle (deg)";
  output Real dAz;
  output Real dEl;
protected
  Real Rxy[3] = {p_sat_topo.x,p_sat_topo.y,0};
  Real vxy[3] = {v_sat_topo.x,v_sat_topo.y,0};
  Real R = sqrt(p_sat_topo.x^2 + p_sat_topo.y^2);
  Real pi = 3.141592653589793;
  Real dAzTemp[3];
algorithm
  azimuth := (atan(p_sat_topo.x/p_sat_topo.y))*180/pi;
  elevation := (atan(p_sat_topo.z/(sqrt(p_sat_topo.x^2 + p_sat_topo.y^2))))*180/pi;
  dAzTemp := (1/(R^2))*cross(vxy,Rxy);
  dAz := dAzTemp[3];
  dEl := (R*v_sat_topo.z-(p_sat_topo.z/R)*(Rxy[1]*vxy[1]+Rxy[2]*vxy[2]))/(R^2);
  //perform limits check
  if dAz > az_vel_lim or dEl > el_vel_lim then
    azimuth := 1.e+60; 
    elevation := 1.e+60; 
  end if;
end range_topo2look_angles;
function range_ECF2topo
  input Vector p_sat_ecf "Satellite position in ECF coords (km)";
  input Vector v_sat_ecf "Satellite velocity in ECF coords (km/s)";
  input Vector p_stn_ecf "Station position in ECF coords (km)";
  input Real longitude "Station longitude (deg)";
  input Real latitude "Station latitude (deg)";
  
  output Vector p_sat_topo "Satellite position in topo coords (km)";
  output Vector v_sat_topo "Satellite velocity in topo coords (km/s)";

protected
  Real p[3,1];
  Real v[3,1];
  Real long = longitude*pi/180; //convert to radians
  Real lat = latitude*pi/180; //convert to radians
  Real R[3,3] = [-sin(long), cos(long), 0; -cos(long)*sin(lat), -sin(long)*cos(lat), cos(lat); cos(long)*cos(lat), sin(long)*cos(lat), sin(lat)];

algorithm
  // p_topo = R*p_ecf - T; T = R*stn_coords
  p := R * [p_sat_ecf.x; p_sat_ecf.y; p_sat_ecf.z] - R * [p_stn_ecf.x; p_stn_ecf.y; p_stn_ecf.z];
  v := R * [v_sat_ecf.x; v_sat_ecf.y; v_sat_ecf.z] ; //v_topo = R*v_ecf
  p_sat_topo.x := p[1,1];
  p_sat_topo.y := p[2,1];
  p_sat_topo.z := p[3,1];
  v_sat_topo.x := v[1,1];
  v_sat_topo.y := v[2,1];
  v_sat_topo.z := v[3,1];

end range_ECF2topo;
end Sattraj;
