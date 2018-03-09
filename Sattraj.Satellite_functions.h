#ifndef Sattraj_Satellite__H
#define Sattraj_Satellite__H
#include "meta/meta_modelica.h"
#include "util/modelica.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "simulation/simulation_runtime.h"
#ifdef __cplusplus
extern "C" {
#endif

typedef struct Sattraj_Vector_s {
  modelica_real _x;
  modelica_real _y;
  modelica_real _z;
} Sattraj_Vector;
typedef base_array_t Sattraj_Vector_array;
extern struct record_description Sattraj_Vector__desc;

DLLExport
Sattraj_Vector omc_Sattraj_Vector (threadData_t *threadData, modelica_real omc_x, modelica_real omc_y, modelica_real omc_z);

DLLExport
modelica_metatype boxptr_Sattraj_Vector(threadData_t *threadData, modelica_metatype _x, modelica_metatype _y, modelica_metatype _z);
static const MMC_DEFSTRUCTLIT(boxvar_lit_Sattraj_Vector,2,0) {(void*) boxptr_Sattraj_Vector,0}};
#define boxvar_Sattraj_Vector MMC_REFSTRUCTLIT(boxvar_lit_Sattraj_Vector)
#include "Sattraj.Satellite_model.h"


#ifdef __cplusplus
}
#endif
#endif

