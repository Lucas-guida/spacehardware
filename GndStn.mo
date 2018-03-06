model GndStn
  parameter Real longitude = 20 "Station longitude (deg)";
  parameter Real latitude = 30 "Station latitude (deg)";
  parameter Real elevation = 50 "Station elevation (m)";
  constant Real polar = 6356.7523 "polar m";
  constant Real equator = 6378.1370 "equator m";
  constant Real pi = 3.141592653589793;
  Real Re,r,a,b,lat,long,x,y,z;
public
  output Vector p_stn_ecf "Station ECF coordinates";
equation
  lat = latitude*pi/180;
  long = longitude*pi/180;
  b = polar*1000;
  a = equator*1000;
  
  Re = a*sqrt((b^4/a^4)*(sin(latitude))^2 + (cos(latitude))^2)/sqrt(1 - (1 - b^2/a^2)*(sin(latitude))^2);
  r = Re + elevation;
  
  p_stn_ecf.x = r*cos(long)*cos(lat);
  p_stn_ecf.y = r*sin(long)*cos(lat);
  p_stm_ecf.z = r*sin(lat);
end GndStn; 
