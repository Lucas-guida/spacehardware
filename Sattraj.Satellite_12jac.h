/* Jacobians */
static const REAL_ATTRIBUTE dummyREAL_ATTRIBUTE = omc_dummyRealAttribute;
/* Jacobian Variables */
#if defined(__cplusplus)
extern "C" {
#endif
  #define Sattraj_Satellite_INDEX_JAC_NLSJac3 0
  int Sattraj_Satellite_functionJacNLSJac3_column(void* data, threadData_t *threadData);
  int Sattraj_Satellite_initialAnalyticJacobianNLSJac3(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* NLSJac3 */
#define $PESeedNLSJac3 data->simulationInfo->analyticJacobians[0].seedVars[0]
#define _$P$cse8$P$pDERNLSJac3$PdummyVarNLSJac3(i) data->simulationInfo->analyticJacobians[0].tmpVars[0]
#define $P$cse8$P$pDERNLSJac3$PdummyVarNLSJac3 _$P$cse8$P$pDERNLSJac3$PdummyVarNLSJac3(0)

#define _$P$res$P1$P$pDERNLSJac3$PdummyVarNLSJac3(i) data->simulationInfo->analyticJacobians[0].resultVars[0]
#define $P$res$P1$P$pDERNLSJac3$PdummyVarNLSJac3 _$P$res$P1$P$pDERNLSJac3$PdummyVarNLSJac3(0)

#define _$P$cse9(i) data->simulationInfo->analyticJacobians[0].tmpVars[2]
#define $P$cse9 _$P$cse9(0)

#if defined(__cplusplus)
extern "C" {
#endif
  #define Sattraj_Satellite_INDEX_JAC_A 4
  int Sattraj_Satellite_functionJacA_column(void* data, threadData_t *threadData);
  int Sattraj_Satellite_initialAnalyticJacobianA(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* A */

#if defined(__cplusplus)
extern "C" {
#endif
  #define Sattraj_Satellite_INDEX_JAC_B 3
  int Sattraj_Satellite_functionJacB_column(void* data, threadData_t *threadData);
  int Sattraj_Satellite_initialAnalyticJacobianB(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* B */

#if defined(__cplusplus)
extern "C" {
#endif
  #define Sattraj_Satellite_INDEX_JAC_C 2
  int Sattraj_Satellite_functionJacC_column(void* data, threadData_t *threadData);
  int Sattraj_Satellite_initialAnalyticJacobianC(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* C */

#if defined(__cplusplus)
extern "C" {
#endif
  #define Sattraj_Satellite_INDEX_JAC_D 1
  int Sattraj_Satellite_functionJacD_column(void* data, threadData_t *threadData);
  int Sattraj_Satellite_initialAnalyticJacobianD(void* data, threadData_t *threadData);
#if defined(__cplusplus)
}
#endif
/* D */


