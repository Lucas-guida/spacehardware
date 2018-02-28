model Satellite
  parameter Real ecc "Eccentriciy";
  parameter Real M0 "Mean anomaly at epoch (deg)";
  parameter Real N0 "Mean motion at Epoch (rev/d)";
  parameter Real Ndot2 "TLE drag paramter rev/d^2";
  parameter Real Nddot6 "TLE paramter rev/d^3";
  parameter Real tstart "Simulation start time,seconds since Epoch (s)";
  
  output Vector p_sat_pf "Position, Perifocal coords";
  output Vector v_sat_pf "Velocity Peerifocal coords";

end Satellite;
