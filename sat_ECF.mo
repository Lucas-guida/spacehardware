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
