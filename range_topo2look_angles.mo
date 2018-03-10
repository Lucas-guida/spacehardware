function range_topo2look_angles
  input Real az_vel_lim "Azimuth velocity limit (deg/s)";
  input Real el_vel_lim "Elevation velocity limit (deg/s)";
  input Vector p_sat_topo "Satellite position in topo coords (km)";
  input Vector v_sat_topo "Satellite velocity in topo coords (km/s)";
  
  output Real azimuth "Azimuth angle (deg)";
  output Real elevation "Elevation angle (deg)";
protected
  Real Rxy[2,1] = [p_sat_topo.x;p_sat_topo.y];
  Real vxy[2,1] = [v_sat_topo.x;v_sat_topo.y];
  Real R = sqrt(p_sat_topo.x^2 + p_sat_topo.y^2);
  Real dAz;
  Real dEl;
algorithm
  azimuth := atan(p_sat_topo.x/p_sat_topo.y);
  elevation := atan(p_sat_topo.z/(sqrt(p_sat_topo.x^2 + p_sat_topo.x^2)));
  dAz := (1/(R^2))*cross(vxy,Rxy);
  dEl := (R*v_sat_topo.z-(p_sat_topo.z/R)*dot(Rxy,vxy))/(R^2);
  // perform limits check
  if dAz > az_vel_lim or dEl > el_vel_lim then
    azimuth := None; 
    elevation := None; 
  end if;
end range_topo2look_angles;
