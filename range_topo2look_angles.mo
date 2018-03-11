function range_topo2look_angles
  input Real az_vel_lim "Azimuth velocity limit (deg/s)";
  input Real el_vel_lim "Elevation velocity limit (deg/s)";
  input Vector p_sat_topo "Satellite position in topo coords (km)";
  input Vector v_sat_topo "Satellite velocity in topo coords (km/s)";
  output Real azimuth "Azimuth angle (deg)";
  output Real elevation "Elevation angle (deg)";
  output Real dAz;
  output Real dEl;
protected
  Real Rxy[3] = {p_sat_topo.x,p_sat_topo.y,0};
  Real vxy[3] = {v_sat_topo.x,v_sat_topo.y,0};
  Real R = sqrt(p_sat_topo.x^2 + p_sat_topo.y^2);
  Real pi = 3.141592653589793;
  Real dAzTemp[3];
algorithm
  azimuth := (atan(p_sat_topo.x/p_sat_topo.y))*180/pi;
  elevation := (atan(p_sat_topo.z/(sqrt(p_sat_topo.x^2 + p_sat_topo.y^2))))*180/pi;
  dAzTemp := (1/(R^2))*cross(vxy,Rxy);
  dAz := dAzTemp[3];
  dEl := (R*v_sat_topo.z-(p_sat_topo.z/R)*(Rxy[1]*vxy[1]+Rxy[2]*vxy[2]))/(R^2);
  //perform limits check
  if dAz > az_vel_lim or dEl > el_vel_lim then
    azimuth := 1.e+60; 
    elevation := 1.e+60; 
  end if;
end range_topo2look_angles;
