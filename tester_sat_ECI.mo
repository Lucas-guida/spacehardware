model tester_sat_ECI
    Vector p_sat_ecf;
    Vector v_sat_ecf;
    Vector p;
    Vector v;
equation
  p_sat_ecf.x = -19125.5;
  p_sat_ecf.y = -18664;
  p_sat_ecf.z = 0;

  v_sat_ecf.x = 2.70578;
  v_sat_ecf.y = -2.73909;
  v_sat_ecf.z = 0;
  (p,v) = sat_ECI(p_sat_ecf,v_sat_ecf,0.0086707,285.7420,55.1681,136.112,2.0074691105728);
end tester_sat_ECI;
