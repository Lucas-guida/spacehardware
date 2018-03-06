model Satellite
  parameter Real ecc = 0.0086707 "Eccentriciy";
  parameter Real M0 = 224.6824 "Mean anomaly at epoch (deg)";
  parameter Real N0 = 2.00574691105728 "Mean motion at Epoch (rev/d)";
  parameter Real Ndot2 = 0.00000015 "TLE drag paramter rev/d^2";
  parameter Real Nddot6 = 0.0"TLE paramter rev/d^3";
  parameter Real tstart = 0 "Simulation start time,seconds since Epoch (s)";
  parameter Real pi = 3.141592653589793;
  parameter Real GM = 398600.4418 "km^3/s^2";
  Real M, E, theta, dtheta, r, a, x, y, h, dr, dx, dy; // removed n and dM
  Real t = 0;
public
  output Vector p_sat_p;
  output Vector v_sat_p;
equation
   //working
   M = mod(M0 + N0*(360/86400)*t + 360*Ndot2*(t/86400)^2 + 360*(Nddot6)*(t/86400)^3,360)*3.141592653589793/180;
   M = E + ecc*sin(E*3.141592653589793/180);
   tan(E/2) = sqrt((1 - ecc)/(1 + ecc))*tan(theta/2);
   N0*360/24/60/60 = (180/pi)*sqrt(GM/a^3);
   
   //I think are working
   r = a*(1 - ecc^2)/(1 + ecc*cos(theta));
   
   //not working 
   dtheta = N0*sqrt(1 - ecc^2)/(1 - ecc*cos(E))^2;
   
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
