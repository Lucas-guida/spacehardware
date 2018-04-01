function theta_t
  input Real din "JD of the time of interst (not time difference since J2000)";
  //input Real t "time of interest";
  input Real tm "JDtime of mindnight of day of interest";
  input Real t "system time";
  output Real theta_t "GMST angle (deg)";
protected
  Real d = din+(t/86400) - 2451545.0;
  Real dm = tm - 2451545.0;
  Real T = d/36525;
  Real theta_mid;
  Real r;
algorithm
 theta_t := mod(18.697374558 + 24.06570982441908*d,24)*360/24;
end theta_t;
