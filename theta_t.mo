function theta_t
  input Real d "Time since J2000 (d)";
  output Real theta_t "GMST angle (deg)";
protected
  //Real d = time - 2451545.0;
  Real T = d/36525;
algorithm
  theta_t := mod(24110.54841 + 8640184.812866*T +0.093104*T^2 - 0.0000062*T^3,86400)*360/86400;
end theta_t; 