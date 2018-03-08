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
