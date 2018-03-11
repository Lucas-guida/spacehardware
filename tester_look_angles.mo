model tester_look_angles
    Vector p_sat_topo;
    Vector v_sat_topo;
    Real azimuth;
    Real elevation;
    Real alimit;
    Real dlimit;
equation
  p_sat_topo.x = -2;
  p_sat_topo.y = 5804.5;
  p_sat_topo.z = -12103.1+6378;
  v_sat_topo.x = -0.0530933;
  v_sat_topo.y = 2.02571;
  v_sat_topo.z = 2.4426;
  (azimuth, elevation, alimit, dlimit) = range_topo2look_angles(0.5, 0.6, p_sat_topo,v_sat_topo);
  //(azimuth, elevation) = range_topo2look_angles(p_sat_topo,v_sat_topo);
end tester_look_angles;
