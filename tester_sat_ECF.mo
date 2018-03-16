model tester_sat_ECF
  Vector p_sat_eci;
  Vector v_sat_eci;
  Vector p;
  Vector v;
  Real theta;
equation
  p_sat_eci.x = -628447;
  p_sat_eci.y = -68402.8;
  p_sat_eci.z = -819089;
  v_sat_eci.x = 2.10256;
  v_sat_eci.y = 0.645829;
  v_sat_eci.z = 3.16007;
  // This is the JD of the STK sim 2453423.166416;
  (theta) = theta_t(2458192.906171,2458192.5);
  (p,v) = sat_ECF(p_sat_eci,v_sat_eci,theta);
end tester_sat_ECF;
