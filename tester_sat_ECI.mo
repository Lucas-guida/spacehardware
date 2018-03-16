model tester_sat_ECI
    Vector p_sat_ecf;
    Vector v_sat_ecf;
    Vector p;
    Vector v;
equation
  p_sat_ecf.x = -795340;
  p_sat_ecf.y = -661789;
  p_sat_ecf.z = 0;

  v_sat_ecf.x = 2.70578;
  v_sat_ecf.y = -2.73909;
  v_sat_ecf.z = 0;
  (p,v) = sat_ECI(p_sat_ecf,v_sat_ecf,0.0033859,216.4710,55.5029,92.7613,2.00565231151458);
end tester_sat_ECI;
