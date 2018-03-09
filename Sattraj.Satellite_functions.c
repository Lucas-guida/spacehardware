#include "Sattraj.Satellite_functions.h"
#ifdef __cplusplus
extern "C" {
#endif

#include "Sattraj.Satellite_includes.h"


Sattraj_Vector omc_Sattraj_Vector(threadData_t *threadData, modelica_real omc_x, modelica_real omc_y, modelica_real omc_z)
{
  Sattraj_Vector tmp1;
  tmp1._x = omc_x;
  tmp1._y = omc_y;
  tmp1._z = omc_z;
  return tmp1;
}

modelica_metatype boxptr_Sattraj_Vector(threadData_t *threadData, modelica_metatype _x, modelica_metatype _y, modelica_metatype _z)
{
  return mmc_mk_box4(3, &Sattraj_Vector__desc, _x, _y, _z);
}

#ifdef __cplusplus
}
#endif
