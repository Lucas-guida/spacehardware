/* Linearization */
#include "Sattraj.Satellite_model.h"
#if defined(__cplusplus)
extern "C" {
#endif

const char *Sattraj_Satellite_linear_model_frame()
{
  return "model linear_Sattraj_Satellite\n  parameter Integer n = 0; // states\n  parameter Integer k = 0; // top-level inputs\n  parameter Integer l = 0; // top-level outputs\n"
  "  parameter Real x0[0] = {%s};\n"
  "  parameter Real u0[0] = {%s};\n"
  "  parameter Real A[0,0] = zeros(0,0);%s\n"
  "  parameter Real B[0,0] = zeros(0,0);%s\n"
  "  parameter Real C[0,0] = zeros(0,0);%s\n"
  "  parameter Real D[0,0] = zeros(0,0);%s\n"
  "  Real x[0];\n"
  "  input Real u[0];\n"
  "  output Real y[0];\n"
  "\n  \n"
  "equation\n  der(x) = A * x + B * u;\n  y = C * x + D * u;\nend linear_Sattraj_Satellite;\n";
}
const char *Sattraj_Satellite_linear_model_datarecovery_frame()
{
  return "model linear_Sattraj_Satellite\n  parameter Integer n = 0; // states\n  parameter Integer k = 0; // top-level inputs\n  parameter Integer l = 0; // top-level outputs\n  parameter Integer nz = 28; // data recovery variables\n"
  "  parameter Real x0[0] = {%s};\n"
  "  parameter Real u0[0] = {%s};\n"
  "  parameter Real z0[28] = {%s};\n"
  "  parameter Real A[0,0] = zeros(0,0);%s\n"
  "  parameter Real B[0,0] = zeros(0,0);%s\n"
  "  parameter Real C[0,0] = zeros(0,0);%s\n"
  "  parameter Real D[0,0] = zeros(0,0);%s\n"
  "  parameter Real Cz[28,0] = zeros(28,0);%s\n"
  "  parameter Real Dz[28,0] = zeros(28,0);%s\n"
  "  Real x[0];\n"
  "  input Real u[0];\n"
  "  output Real y[0];\n"
  "  output Real z[28];\n"
  "\nReal 'z_$TMP$VAR$13$0X$ABS' = z[1];\nReal 'z_$TMP$VAR$30$0ATAN$TAN' = z[2];\nReal 'z_$TMP$VAR$30$0PREX$TAN' = z[3];\nReal 'z_$TMP$VAR$39$0X$ABS' = z[4];\nReal 'z_$TMP$VAR$6$0ATAN$TAN' = z[5];\nReal 'z_$TMP$VAR$6$0PREX$TAN' = z[6];\nReal 'z_$TMP$VAR$6$0Y$TAN' = z[7];\nReal 'z_$cse3' = z[8];\nReal 'z_$cse4' = z[9];\nReal 'z_$cse5' = z[10];\nReal 'z_$cse6' = z[11];\nReal 'z_$cse7' = z[12];\nReal 'z_$cse8' = z[13];\nReal 'z_E' = z[14];\nReal 'z_M' = z[15];\nReal 'z_a' = z[16];\nReal 'z_dr' = z[17];\nReal 'z_dtheta' = z[18];\nReal 'z_dx' = z[19];\nReal 'z_dy' = z[20];\nReal 'z_h' = z[21];\nReal 'z_p_sat_p.z' = z[22];\nReal 'z_r' = z[23];\nReal 'z_t' = z[24];\nReal 'z_theta' = z[25];\nReal 'z_v_sat_p.z' = z[26];\nReal 'z_x' = z[27];\nReal 'z_y' = z[28];\n\n"
  "equation\n  der(x) = A * x + B * u;\n  y = C * x + D * u;\n  z = Cz * x + Dz * u;\nend linear_Sattraj_Satellite;\n";
}
#if defined(__cplusplus)
}
#endif

