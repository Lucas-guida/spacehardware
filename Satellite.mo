model Satellite
  parameter Real ecc = 0.0113833 "Eccentriciy";
  parameter Real M0 = 144.0675 "Mean anomaly at epoch (deg)";
  parameter Real N0 = 2.00565231151458 "Mean motion at Epoch (rev/d)";
  parameter Real Ndot2 = 0.00000034 "TLE drag paramter rev/d^2";
  parameter Real Nddot6 = 0.0"TLE paramter rev/d^3";
  parameter Real tstart = 50400 "Simulation start time,seconds since Epoch (s)";
  parameter Real pi = 3.141592653589793;
  parameter Real GM = 398600.4418 "km^3/s^2";
  Real M, E, theta, r, a, x, y, h, dr, dx, dy,n; // removed n and dM
public
  output Vector p_sat_p;
  output Vector v_sat_p;
initial equation
   M = (M0 + N0*(360/86400)*tstart + 360*Ndot2*(tstart/86400)^2 + 360*(Nddot6)*(tstart/86400)^3);
equation
   //working
   der(M) = (N0*(360/86400) + 2*360*Ndot2*((time)/86400^2) + 3*360*(Nddot6)*((time^2)/86400^3));
   n=der(M);
   M*3.141592653589793/180 = E + ecc*sin(E*3.141592653589793/180);
   tan(E/2) = sqrt((1 - ecc)/(1 + ecc))*tan(theta/2);
   n*360/86400 = (180/pi)*sqrt(GM/a^3);
   
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
