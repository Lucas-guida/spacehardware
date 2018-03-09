function theta_t
  input Real din "JD of the time of interst (not time difference since J2000)";
  input Real t "time of interest";
  input Real tm "time of mindnight of day of interest";
  output Real theta_t "GMST angle (deg)";
protected
  Real d = din - 2451545.0;
  Real T = d/36525;
  Real theta_mid,r;
algorithm
  theta_mid := mod(24110.54841 + 8640184.812866*T +0.093104*T^2 - 0.0000062*T^3,86400)*360/86400;
  r:=1.002737909350795 + 5.9006*10^(-11)*T -5.9*10^(-15)*T^2;
  //theta_t := theta_mid + 360*r*(2453424.416366-2453423.500000)/86400;//(time of interest ... in this case start of tracking time - tmidnight of start of tracking period)
  theta_t := theta_mid + 360*r*(t-tm)/86400;//(time of interest ... in this case start of tracking time - tmidnight of start of tracking period)
end theta_t; 
