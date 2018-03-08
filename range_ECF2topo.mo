function range_ECF2topo
  input Vector p_sat_ecf "Satellite position in ECF coords (km)";
  input Vector v_sat_ecf "Satellite velocity in ECF coords (km/s)";
  input Vector p_stn_ecf "Station position in ECF coords (km)";
  input Real longitude "Station longitude (deg)";
  input Real latitude "Station latitude (deg)";
  
  output Vector p_sat_topo "Satellite position in topo coords (km)";
  output Vector v_sat_topo "Satellite velocity in topo coords (km/s)";

protected
  Real p[3,1];
  Real v[3,1];
  Real long = longitude*pi/180; //convert to radians
  Real lat = latitude*pi/180; //convert to radians
  Real R[3,3] = [-sin(long), cos(long), 0; -cos(long)*sin(lat), -sin(long)*cos(lat), cos(lat); cos(long)*cos(lat), sin(long)*cos(lat), sin(lat)];

algorithm
  // p_topo = R*p_ecf - T; T = R*stn_coords
  p := R * [p_sat_ecf.x; p_sat_ecf.y; p_sat_ecf.z] - R * [p_stn_ecf.x; p_stn_ecf.y; p_stn_ecf.z];
  v := R * [v_sat_ecf.x; v_sat_ecf.y; v_sat_ecf.z] ; //v_topo = R*v_ecf
  p_sat_topo.x := p[1,1];
  p_sat_topo.y := p[2,1];
  p_sat_topo.z := p[3,1];
  v_sat_topo.x := v[1,1];
  v_sat_topo.y := v[2,1];
  v_sat_topo.z := v[3,1];

end range_ECF2topo;
