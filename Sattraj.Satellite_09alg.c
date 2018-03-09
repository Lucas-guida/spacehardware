/* Algebraic */
#include "Sattraj.Satellite_model.h"

#ifdef __cplusplus
extern "C" {
#endif


/* forwarded equations */
extern void Sattraj_Satellite_eqFunction_26(DATA* data, threadData_t *threadData);
extern void Sattraj_Satellite_eqFunction_27(DATA* data, threadData_t *threadData);
extern void Sattraj_Satellite_eqFunction_28(DATA* data, threadData_t *threadData);
extern void Sattraj_Satellite_eqFunction_29(DATA* data, threadData_t *threadData);
extern void Sattraj_Satellite_eqFunction_30(DATA* data, threadData_t *threadData);
extern void Sattraj_Satellite_eqFunction_31(DATA* data, threadData_t *threadData);
extern void Sattraj_Satellite_eqFunction_32(DATA* data, threadData_t *threadData);
extern void Sattraj_Satellite_eqFunction_33(DATA* data, threadData_t *threadData);
extern void Sattraj_Satellite_eqFunction_34(DATA* data, threadData_t *threadData);
extern void Sattraj_Satellite_eqFunction_35(DATA* data, threadData_t *threadData);
extern void Sattraj_Satellite_eqFunction_36(DATA* data, threadData_t *threadData);
extern void Sattraj_Satellite_eqFunction_37(DATA* data, threadData_t *threadData);
extern void Sattraj_Satellite_eqFunction_38(DATA* data, threadData_t *threadData);
extern void Sattraj_Satellite_eqFunction_39(DATA* data, threadData_t *threadData);
extern void Sattraj_Satellite_eqFunction_40(DATA* data, threadData_t *threadData);
extern void Sattraj_Satellite_eqFunction_41(DATA* data, threadData_t *threadData);
extern void Sattraj_Satellite_eqFunction_42(DATA* data, threadData_t *threadData);
extern void Sattraj_Satellite_eqFunction_43(DATA* data, threadData_t *threadData);

static void functionAlg_system0(DATA *data, threadData_t *threadData)
{
  Sattraj_Satellite_eqFunction_26(data, threadData);

  Sattraj_Satellite_eqFunction_27(data, threadData);

  Sattraj_Satellite_eqFunction_28(data, threadData);

  Sattraj_Satellite_eqFunction_29(data, threadData);

  Sattraj_Satellite_eqFunction_30(data, threadData);

  Sattraj_Satellite_eqFunction_31(data, threadData);

  Sattraj_Satellite_eqFunction_32(data, threadData);

  Sattraj_Satellite_eqFunction_33(data, threadData);

  Sattraj_Satellite_eqFunction_34(data, threadData);

  Sattraj_Satellite_eqFunction_35(data, threadData);

  Sattraj_Satellite_eqFunction_36(data, threadData);

  Sattraj_Satellite_eqFunction_37(data, threadData);

  Sattraj_Satellite_eqFunction_38(data, threadData);

  Sattraj_Satellite_eqFunction_39(data, threadData);

  Sattraj_Satellite_eqFunction_40(data, threadData);

  Sattraj_Satellite_eqFunction_41(data, threadData);

  Sattraj_Satellite_eqFunction_42(data, threadData);

  Sattraj_Satellite_eqFunction_43(data, threadData);
}
/* for continuous time variables */
int Sattraj_Satellite_functionAlgebraics(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  
  data->simulationInfo->callStatistics.functionAlgebraics++;
  
  functionAlg_system0(data, threadData);

  Sattraj_Satellite_function_savePreSynchronous(data, threadData);
  
  TRACE_POP
  return 0;
}

#ifdef __cplusplus
}
#endif
