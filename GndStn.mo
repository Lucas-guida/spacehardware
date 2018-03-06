model GndStn
  parameter Real longitude = 20 "Station longitude (deg)";
  parameter Real latitude = 30 "Station latitude (deg)";
  parameter Real elevation = 50 "Station elevation (m)";
  constant Real a = 6378137 "Earth reference ellipsoid equatorial radius (m)";
  constant Real f = 1/298.257223563 "Earth reference ellipsoid flattening";
  constant Real pi = 3.141592653589793;
  Real N, lat, long, x, y, z;
public
  output Vector p_stn_ecf "Station ECF coordinates";
equation
  lat = latitude*pi/180;
  long = longitude*pi/180;
  N = a/(sqrt(1-(2*f-f^2)*(sin(lat))^2)); 
  x = (N+elevation)*cos(lat)*cos(long);
  y = (N+elevation)*cos(lat)*sin(long);
  z = ((1-(2*f-f^2))*N+elevation)*sin(lat);
  p_stn_ecf.x = (N+elevation)*cos(lat)*cos(long);
  p_stn_ecf.y = (N+elevation)*cos(lat)*sin(long);
  p_stn_ecf.z = ((1-(2*f-f^2))*N+elevation)*sin(lat);
end GndStn; 
