model Satellite
  parameter Real ecc "Eccentriciy";
  parameter Real M0 "Mean anomaly at epoch (deg)";
  parameter Real N0 "Mean motion at Epoch (rev/d)";
  parameter Real Ndot2 "TLE drag paramter rev/d^2";
  parameter Real Nddot6 "TLE paramter rev/d^3";
  parameter Real tstart "Simulation start time,seconds since Epoch (s)";
  
  //parameter Vector p_sat_pf(x=x,y=y,z=0.0); 
  
  final constant Real pi=2*Modelica.Math.asin(1.0);
  final constant Real GM = 398600.4418 "km^3/s^2";
  
  Real M "mean anomoly";
  Real dM;
  Real t = tstart;
  Real E;
  Real theta;
  Real dtheta;
  Real r;
  Real dr;
  Real n;
  Real h;
  Real a;
  
  Real x,y,dx,dy;
  
  //output Vector p_sat_pf "Position, Perifocal coords";
  //output Vector v_sat_pf "Velocity, Perifocal coords";
  
  output Vector p_sat_pf;
  output Vector v_sat_pf;
  
equation
    M = mod(M0 + N0*(360/86400)*t + 360*Ndot2*(t/86400)^2 + 360*(Nddot6)*(t/86400)^3,360);
    dM = mod(N0*(360/86400) + 2*360*Ndot2*(t/86400) + 3*360*(Nddot6)*(t/86400),360);
    M = E + ecc*sin(E);
    tan(E/2) = sqrt((1-ecc)/(1+ecc))*tan(theta/2);
    dM*n = mod(N0*(360/86400) + 2*360*Ndot2*(t/86400^2) + 3*360*(Nddot6)*(t^2/86400^3),360);
    dtheta = n*sqrt(1-ecc^2)/(1-ecc*cos(E))^2;
    n = (180/pi)*sqrt(GM/a^3);
    
    r = a*(1-ecc^2)/(1+ecc*cos(theta));
    x = r*cos(theta);
    y = r*sin(theta);
    
    r = (h^2/GM)/(1+ecc*cos(theta));
    
    dr = (GM/h)*ecc*sin(theta);
    
    dx = -(GM/h)*sin(theta);
    dy = (GM/h)*(ecc + cos(theta));
    
    p_sat_pf.x = x;
    p_sat_pf.y = y;
    p_sat_pf.z = 0;
    
    v_sat_pf.x = dx;
    v_sat_pf.y = dy;
    v_sat_pf.z = 0;
    
end Satellite;
