/* Jacobians */
#include "Sattraj.Satellite_model.h"
#include "Sattraj.Satellite_12jac.h"

int Sattraj_Satellite_initialAnalyticJacobianNLSJac3(void* inData, threadData_t *threadData)
{
  TRACE_PUSH
  DATA* data = ((DATA*)inData);
  int index = Sattraj_Satellite_INDEX_JAC_NLSJac3;
  const int colPtrIndex[1+1] = {0,1};
  const int rowIndex[1] = {0};
  int i = 0;
  
  data->simulationInfo->analyticJacobians[index].sizeCols = 1;
  data->simulationInfo->analyticJacobians[index].sizeRows = 1;
  data->simulationInfo->analyticJacobians[index].sizeTmpVars = 3;
  data->simulationInfo->analyticJacobians[index].seedVars = (modelica_real*) calloc(1,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].resultVars = (modelica_real*) calloc(1,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].tmpVars = (modelica_real*) calloc(3,sizeof(modelica_real));
  data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex = (unsigned int*) malloc((1+1)*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.index = (unsigned int*) malloc(1*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.numberOfNoneZeros = 1;
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols = (unsigned int*) malloc(1*sizeof(int));
  data->simulationInfo->analyticJacobians[index].sparsePattern.maxColors = 1;
  data->simulationInfo->analyticJacobians[index].jacobian = NULL;
  
  /* write lead index of compressed sparse column */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex, colPtrIndex, (1+1)*sizeof(int));
  
  for(i=2;i<1+1;++i)
    data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i] += data->simulationInfo->analyticJacobians[index].sparsePattern.leadindex[i-1];
  
  /* call sparse index */
  memcpy(data->simulationInfo->analyticJacobians[index].sparsePattern.index, rowIndex, 1*sizeof(int));
  
  /* write color array */
  data->simulationInfo->analyticJacobians[index].sparsePattern.colorCols[0] = 1;
  TRACE_POP
  return 0;
}
int Sattraj_Satellite_initialAnalyticJacobianA(void* inData, threadData_t *threadData)
{
  TRACE_PUSH
  TRACE_POP
  return 1;
}
int Sattraj_Satellite_initialAnalyticJacobianB(void* inData, threadData_t *threadData)
{
  TRACE_PUSH
  TRACE_POP
  return 1;
}
int Sattraj_Satellite_initialAnalyticJacobianC(void* inData, threadData_t *threadData)
{
  TRACE_PUSH
  TRACE_POP
  return 1;
}
int Sattraj_Satellite_initialAnalyticJacobianD(void* inData, threadData_t *threadData)
{
  TRACE_PUSH
  TRACE_POP
  return 1;
}


/*
 equation index: 23
 type: SIMPLE_ASSIGN
 $cse9 = cos(0.0174532925199433 * E)
 */
void Sattraj_Satellite_eqFunction_23(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,23};
  $P$cse9 = cos((0.0174532925199433) * (data->localData[0]->realVars[13] /* E variable */));
  TRACE_POP
}

/*
 equation index: 24
 type: SIMPLE_ASSIGN
 $cse8._$pDERNLSJac3._dummyVarNLSJac3 = 0.0174532925199433 * $cse9 * ESeedNLSJac3
 */
void Sattraj_Satellite_eqFunction_24(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,24};
  $P$cse8$P$pDERNLSJac3$PdummyVarNLSJac3 = (0.0174532925199433) * (($P$cse9) * ($PESeedNLSJac3));
  TRACE_POP
}

/*
 equation index: 25
 type: SIMPLE_ASSIGN
 $res._1._$pDERNLSJac3._dummyVarNLSJac3 = ecc * $cse8.$pDERNLSJac3.dummyVarNLSJac3 + ESeedNLSJac3
 */
void Sattraj_Satellite_eqFunction_25(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int clockIndex = 0;
  const int equationIndexes[2] = {1,25};
  $P$res$P1$P$pDERNLSJac3$PdummyVarNLSJac3 = (data->simulationInfo->realParameter[5]) * ($P$cse8$P$pDERNLSJac3$PdummyVarNLSJac3) + $PESeedNLSJac3;
  TRACE_POP
}
int Sattraj_Satellite_functionJacNLSJac3_column(void* inData, threadData_t *threadData)
{
  TRACE_PUSH

  DATA* data = ((DATA*)inData);
  int index = Sattraj_Satellite_INDEX_JAC_NLSJac3;
  Sattraj_Satellite_eqFunction_23(data, threadData);

  Sattraj_Satellite_eqFunction_24(data, threadData);

  Sattraj_Satellite_eqFunction_25(data, threadData);
  
  TRACE_POP
  return 0;
}
int Sattraj_Satellite_functionJacA_column(void* data, threadData_t *threadData)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}
int Sattraj_Satellite_functionJacB_column(void* data, threadData_t *threadData)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}
int Sattraj_Satellite_functionJacC_column(void* data, threadData_t *threadData)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}
int Sattraj_Satellite_functionJacD_column(void* data, threadData_t *threadData)
{
  TRACE_PUSH
  TRACE_POP
  return 0;
}


