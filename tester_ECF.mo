model tester_ECF
  Vector p_sat_eci;
  Vector v_sat_eci;
  Vector p;
  Vector v;
  Real theta,day,r;
equation
  p_sat_eci.x = 7355.7;
  p_sat_eci.y = -25690.4;
  p_sat_eci.z = 157.851;
  v_sat_eci.x = 2.10256;
  v_sat_eci.y = 0.645829;
  v_sat_eci.z = 3.16007;
  // This is the JD of the STK sim 2453423.166416;
  (theta,day,r) = theta_t(2453424.386106,2453423.500000);
  (p,v) = sat_ECF(p_sat_eci,v_sat_eci,theta);
end tester_ECF;
