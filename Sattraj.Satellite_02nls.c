/* Non Linear Systems */
#include "Sattraj.Satellite_model.h"
#include "Sattraj.Satellite_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif

/* inner equations */

void residualFunc5(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,5};
  /* iteration variables */
  data->localData[0]->realVars[13] /* E variable */ = xloc[0];
  /* backup outputs */
  /* pre body */
  /* body */
  res[0] = data->localData[0]->realVars[13] /* E variable */ + (data->simulationInfo->realParameter[5]) * (sin((0.0174532925199433) * (data->localData[0]->realVars[13] /* E variable */))) - data->localData[0]->realVars[14] /* M variable */;
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS5(NONLINEAR_SYSTEM_DATA* inSysData)
{
  /* no sparsity pattern available */
  inSysData->isPatternAvailable = 0;
}
void initializeStaticDataNLS5(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for E */
  sysData->nominal[i] = data->modelData->realVarsData[13].attribute /* E */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[13].attribute /* E */.min;
  sysData->max[i++]   = data->modelData->realVarsData[13].attribute /* E */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS5(sysData);
}

void getIterationVarsNLS5(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[13] /* E variable */;
}

/* inner equations */

/*
 equation index: 21
 type: SIMPLE_ASSIGN
 $cse8 = sin(0.0174532925199433 * E)
 */
void Sattraj_Satellite_eqFunction_21(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,21};
  data->localData[0]->realVars[12] /* $cse8 variable */ = sin((0.0174532925199433) * (data->localData[0]->realVars[13] /* E variable */));
  TRACE_POP
}

void residualFunc26(void** dataIn, const double* xloc, double* res, const int* iflag)
{
  TRACE_PUSH
  DATA *data = (DATA*) ((void**)dataIn[0]);
  threadData_t *threadData = (threadData_t*) ((void**)dataIn[1]);
  const int equationIndexes[2] = {1,26};
  /* iteration variables */
  data->localData[0]->realVars[13] /* E variable */ = xloc[0];
  /* backup outputs */
  /* pre body */
  /* local constraints */
  Sattraj_Satellite_eqFunction_21(data, threadData);
  /* body */
  res[0] = (data->simulationInfo->realParameter[5]) * (data->localData[0]->realVars[12] /* $cse8 variable */) + data->localData[0]->realVars[13] /* E variable */ - data->localData[0]->realVars[14] /* M variable */;
  /* restore known outputs */
  TRACE_POP
}
void initializeSparsePatternNLS26(NONLINEAR_SYSTEM_DATA* inSysData)
{
  int i=0;
  const int colPtrIndex[1+1] = {0,1};
  const int rowIndex[1] = {0};
  /* sparsity pattern available */
  inSysData->isPatternAvailable = 'T';
  inSysData->sparsePattern.leadindex = (unsigned int*) malloc((1+1)*sizeof(int));
  inSysData->sparsePattern.index = (unsigned int*) malloc(1*sizeof(int));
  inSysData->sparsePattern.numberOfNoneZeros = 1;
  inSysData->sparsePattern.colorCols = (unsigned int*) malloc(1*sizeof(int));
  inSysData->sparsePattern.maxColors = 1;
  
  /* write lead index of compressed sparse column */
  memcpy(inSysData->sparsePattern.leadindex, colPtrIndex, (1+1)*sizeof(int));
  
  for(i=2;i<1+1;++i)
    inSysData->sparsePattern.leadindex[i] += inSysData->sparsePattern.leadindex[i-1];
  
  /* call sparse index */
  memcpy(inSysData->sparsePattern.index, rowIndex, 1*sizeof(int));
  
  /* write color array */
  inSysData->sparsePattern.colorCols[0] = 1;
}
void initializeStaticDataNLS26(void *inData, threadData_t *threadData, void *inSystemData)
{
  DATA* data = (DATA*) inData;
  NONLINEAR_SYSTEM_DATA* sysData = (NONLINEAR_SYSTEM_DATA*) inSystemData;
  int i=0;
  /* static nls data for E */
  sysData->nominal[i] = data->modelData->realVarsData[13].attribute /* E */.nominal;
  sysData->min[i]     = data->modelData->realVarsData[13].attribute /* E */.min;
  sysData->max[i++]   = data->modelData->realVarsData[13].attribute /* E */.max;
  /* initial sparse pattern */
  initializeSparsePatternNLS26(sysData);
}

void getIterationVarsNLS26(struct DATA *inData, double *array)
{
  DATA* data = (DATA*) inData;
  array[0] = data->localData[0]->realVars[13] /* E variable */;
}

/* Prototypes for the strict sets (Dynamic Tearing) */

/* Global constraints for the casual sets */
/* function initialize non-linear systems */
void Sattraj_Satellite_initialNonLinearSystem(int nNonLinearSystems, NONLINEAR_SYSTEM_DATA* nonLinearSystemData)
{
  
  nonLinearSystemData[0].equationIndex = 5;
  nonLinearSystemData[0].size = 1;
  nonLinearSystemData[0].homotopySupport = 0;
  nonLinearSystemData[0].mixedSystem = 0;
  nonLinearSystemData[0].residualFunc = residualFunc5;
  nonLinearSystemData[0].strictTearingFunctionCall = NULL;
  nonLinearSystemData[0].analyticalJacobianColumn = NULL;
  nonLinearSystemData[0].initialAnalyticalJacobian = NULL;
  nonLinearSystemData[0].jacobianIndex = -1;
  nonLinearSystemData[0].initializeStaticNLSData = initializeStaticDataNLS5;
  nonLinearSystemData[0].getIterationVars = getIterationVarsNLS5;
  nonLinearSystemData[0].checkConstraints = NULL;
  
  nonLinearSystemData[1].equationIndex = 26;
  nonLinearSystemData[1].size = 1;
  nonLinearSystemData[1].homotopySupport = 0;
  nonLinearSystemData[1].mixedSystem = 0;
  nonLinearSystemData[1].residualFunc = residualFunc26;
  nonLinearSystemData[1].strictTearingFunctionCall = NULL;
  nonLinearSystemData[1].analyticalJacobianColumn = Sattraj_Satellite_functionJacNLSJac3_column;
  nonLinearSystemData[1].initialAnalyticalJacobian = Sattraj_Satellite_initialAnalyticJacobianNLSJac3;
  nonLinearSystemData[1].jacobianIndex = 0;
  nonLinearSystemData[1].initializeStaticNLSData = initializeStaticDataNLS26;
  nonLinearSystemData[1].getIterationVars = getIterationVarsNLS26;
  nonLinearSystemData[1].checkConstraints = NULL;
}

#if defined(__cplusplus)
}
#endif

