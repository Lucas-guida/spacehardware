/* Main Simulation File */
#include "Sattraj.Satellite_model.h"

#define prefixedName_performSimulation Sattraj_Satellite_performSimulation
#define prefixedName_updateContinuousSystem Sattraj_Satellite_updateContinuousSystem
#include <simulation/solver/perform_simulation.c>

#define prefixedName_performQSSSimulation Sattraj_Satellite_performQSSSimulation
#include <simulation/solver/perform_qss_simulation.c>

/* dummy VARINFO and FILEINFO */
const FILE_INFO dummyFILE_INFO = omc_dummyFileInfo;
const VAR_INFO dummyVAR_INFO = omc_dummyVarInfo;
#if defined(__cplusplus)
extern "C" {
#endif

int Sattraj_Satellite_input_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int Sattraj_Satellite_input_function_init(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int Sattraj_Satellite_input_function_updateStartValues(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int Sattraj_Satellite_inputNames(DATA *data, char ** names){
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}

int Sattraj_Satellite_output_function(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


void Sattraj_Satellite_eqFunction_21(DATA*,threadData_t*);
void Sattraj_Satellite_eqFunction_22(DATA*,threadData_t*);
/*
 equation index: 26
 indexNonlinear: 1
 type: NONLINEAR
 
 vars: {E}
 eqns: {21, 22}
 */
void Sattraj_Satellite_eqFunction_26(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,26};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 26 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[1].nlsxOld[0] = data->localData[0]->realVars[13] /* E variable */;
  retValue = solve_nonlinear_system(data, threadData, 1);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,26};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 26 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[13] /* E variable */ = data->simulationInfo->nonlinearSystemData[1].nlsx[0];
  TRACE_POP
}
/*
 equation index: 27
 type: SIMPLE_ASSIGN
 $cse6 = tan(0.5 * E)
 */
void Sattraj_Satellite_eqFunction_27(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,27};
  data->localData[0]->realVars[10] /* $cse6 variable */ = tan((0.5) * (data->localData[0]->realVars[13] /* E variable */));
  TRACE_POP
}
/*
 equation index: 28
 type: SIMPLE_ASSIGN
 $cse5 = cos(E)
 */
void Sattraj_Satellite_eqFunction_28(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,28};
  data->localData[0]->realVars[9] /* $cse5 variable */ = cos(data->localData[0]->realVars[13] /* E variable */);
  TRACE_POP
}
/*
 equation index: 29
 type: SIMPLE_ASSIGN
 $cse7 = DIVISION($cse6, sqrt(DIVISION(1.0 - ecc, 1.0 + ecc)))
 */
void Sattraj_Satellite_eqFunction_29(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,29};
  modelica_real tmp0;
  tmp0 = DIVISION_SIM(1.0 - data->simulationInfo->realParameter[5],1.0 + data->simulationInfo->realParameter[5],"1.0 + ecc",equationIndexes);
  if(!(tmp0 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
    throwStreamPrintWithEquationIndexes(threadData, equationIndexes, "Model error: Argument of sqrt(DIVISION(1.0 - ecc, 1.0 + ecc)) was %g should be >= 0", tmp0);
  }
  data->localData[0]->realVars[11] /* $cse7 variable */ = DIVISION_SIM(data->localData[0]->realVars[10] /* $cse6 variable */,sqrt(tmp0),"sqrt(DIVISION(1.0 - ecc, 1.0 + ecc))",equationIndexes);
  TRACE_POP
}
/*
 equation index: 30
 type: SIMPLE_ASSIGN
 $TMP$VAR$30$0ATAN$TAN = atan($cse7)
 */
void Sattraj_Satellite_eqFunction_30(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,30};
  data->localData[0]->realVars[1] /* $TMP$VAR$30$0ATAN$TAN variable */ = atan(data->localData[0]->realVars[11] /* $cse7 variable */);
  TRACE_POP
}
/*
 equation index: 31
 type: SIMPLE_ASSIGN
 $TMP$VAR$30$0PREX$TAN = if initial() then if pre(theta) == 0.0 then 1.0 else 0.5 * pre(theta) else 0.5 * pre(theta)
 */
void Sattraj_Satellite_eqFunction_31(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,31};
  data->localData[0]->realVars[2] /* $TMP$VAR$30$0PREX$TAN variable */ = (initial()?((data->simulationInfo->realVarsPre[24] /* theta variable */ == 0.0)?1.0:(0.5) * (data->simulationInfo->realVarsPre[24] /* theta variable */)):(0.5) * (data->simulationInfo->realVarsPre[24] /* theta variable */));
  TRACE_POP
}
/*
 equation index: 32
 type: SIMPLE_ASSIGN
 theta = 2.0 * $TMP$VAR$30$0ATAN$TAN + 6.283185307179586 * $_round(($TMP$VAR$30$0PREX$TAN - $TMP$VAR$30$0ATAN$TAN) / 3.141592653589793)
 */
void Sattraj_Satellite_eqFunction_32(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,32};
  modelica_real tmp2;
  tmp2 = 3.141592653589793;
  if (tmp2 == 0) {throwStreamPrint(threadData, "Division by zero %s", "($TMP$VAR$30$0PREX$TAN - $TMP$VAR$30$0ATAN$TAN) / 3.141592653589793");}
  data->localData[0]->realVars[24] /* theta variable */ = (2.0) * (data->localData[0]->realVars[1] /* $TMP$VAR$30$0ATAN$TAN variable */) + (6.283185307179586) * (((modelica_integer)round((modelica_real)((data->localData[0]->realVars[2] /* $TMP$VAR$30$0PREX$TAN variable */ - data->localData[0]->realVars[1] /* $TMP$VAR$30$0ATAN$TAN variable */) / tmp2))));
  TRACE_POP
}
/*
 equation index: 33
 type: SIMPLE_ASSIGN
 $cse4 = sin(theta)
 */
void Sattraj_Satellite_eqFunction_33(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,33};
  data->localData[0]->realVars[8] /* $cse4 variable */ = sin(data->localData[0]->realVars[24] /* theta variable */);
  TRACE_POP
}
/*
 equation index: 34
 type: SIMPLE_ASSIGN
 $cse3 = cos(theta)
 */
void Sattraj_Satellite_eqFunction_34(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,34};
  data->localData[0]->realVars[7] /* $cse3 variable */ = cos(data->localData[0]->realVars[24] /* theta variable */);
  TRACE_POP
}
/*
 equation index: 35
 type: SIMPLE_ASSIGN
 r = a * DIVISION(1.0 - ecc ^ 2.0, 1.0 + ecc * $cse3)
 */
void Sattraj_Satellite_eqFunction_35(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,35};
  modelica_real tmp3;
  tmp3 = data->simulationInfo->realParameter[5];
  data->localData[0]->realVars[22] /* r variable */ = (data->localData[0]->realVars[15] /* a variable */) * (DIVISION_SIM(1.0 - ((tmp3 * tmp3)),1.0 + (data->simulationInfo->realParameter[5]) * (data->localData[0]->realVars[7] /* $cse3 variable */),"1.0 + ecc * $cse3",equationIndexes));
  TRACE_POP
}
/*
 equation index: 36
 type: SIMPLE_ASSIGN
 dtheta = N0 * DIVISION(sqrt(1.0 - ecc ^ 2.0), (1.0 - ecc * $cse5) ^ 2.0)
 */
void Sattraj_Satellite_eqFunction_36(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,36};
  modelica_real tmp4;
  modelica_real tmp5;
  modelica_real tmp6;
  tmp4 = data->simulationInfo->realParameter[5];
  tmp5 = 1.0 - ((tmp4 * tmp4));
  if(!(tmp5 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
    throwStreamPrintWithEquationIndexes(threadData, equationIndexes, "Model error: Argument of sqrt(1.0 - ecc ^ 2.0) was %g should be >= 0", tmp5);
  }tmp6 = 1.0 - ((data->simulationInfo->realParameter[5]) * (data->localData[0]->realVars[9] /* $cse5 variable */));
  data->localData[0]->realVars[17] /* dtheta variable */ = (data->simulationInfo->realParameter[2]) * (DIVISION_SIM(sqrt(tmp5),(tmp6 * tmp6),"(1.0 - ecc * $cse5) ^ 2.0",equationIndexes));
  TRACE_POP
}
/*
 equation index: 37
 type: SIMPLE_ASSIGN
 x = r * $cse3
 */
void Sattraj_Satellite_eqFunction_37(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,37};
  data->localData[0]->realVars[26] /* x variable */ = (data->localData[0]->realVars[22] /* r variable */) * (data->localData[0]->realVars[7] /* $cse3 variable */);
  TRACE_POP
}
/*
 equation index: 38
 type: SIMPLE_ASSIGN
 y = r * $cse4
 */
void Sattraj_Satellite_eqFunction_38(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,38};
  data->localData[0]->realVars[27] /* y variable */ = (data->localData[0]->realVars[22] /* r variable */) * (data->localData[0]->realVars[8] /* $cse4 variable */);
  TRACE_POP
}
/*
 equation index: 39
 type: SIMPLE_ASSIGN
 $TMP$VAR$39$0X$ABS = pre(h)
 */
void Sattraj_Satellite_eqFunction_39(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,39};
  data->localData[0]->realVars[3] /* $TMP$VAR$39$0X$ABS variable */ = data->simulationInfo->realVarsPre[20] /* h variable */;
  TRACE_POP
}
/*
 equation index: 40
 type: SIMPLE_ASSIGN
 h = $_signNoNull($TMP$VAR$39$0X$ABS) * abs((r * (1.0 + ecc * $cse3) * GM) ^ 0.5)
 */
void Sattraj_Satellite_eqFunction_40(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,40};
  modelica_real tmp7;
  tmp7 = (data->localData[0]->realVars[22] /* r variable */) * ((1.0 + (data->simulationInfo->realParameter[5]) * (data->localData[0]->realVars[7] /* $cse3 variable */)) * (data->simulationInfo->realParameter[0]));
  if(!(tmp7 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
    throwStreamPrintWithEquationIndexes(threadData, equationIndexes, "Model error: Argument of sqrt(r * (1.0 + ecc * $cse3) * GM) was %g should be >= 0", tmp7);
  }
  data->localData[0]->realVars[20] /* h variable */ = ((data->localData[0]->realVars[3] /* $TMP$VAR$39$0X$ABS variable */ >= 0.0 ? 1.0:-1.0)) * (fabs(sqrt(tmp7)));
  TRACE_POP
}
/*
 equation index: 41
 type: SIMPLE_ASSIGN
 dr = GM * ecc * DIVISION($cse4, h)
 */
void Sattraj_Satellite_eqFunction_41(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,41};
  data->localData[0]->realVars[16] /* dr variable */ = (data->simulationInfo->realParameter[0]) * ((data->simulationInfo->realParameter[5]) * (DIVISION_SIM(data->localData[0]->realVars[8] /* $cse4 variable */,data->localData[0]->realVars[20] /* h variable */,"h",equationIndexes)));
  TRACE_POP
}
/*
 equation index: 42
 type: SIMPLE_ASSIGN
 dx = (-GM) * DIVISION($cse4, h)
 */
void Sattraj_Satellite_eqFunction_42(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,42};
  data->localData[0]->realVars[18] /* dx variable */ = ((-data->simulationInfo->realParameter[0])) * (DIVISION_SIM(data->localData[0]->realVars[8] /* $cse4 variable */,data->localData[0]->realVars[20] /* h variable */,"h",equationIndexes));
  TRACE_POP
}
/*
 equation index: 43
 type: SIMPLE_ASSIGN
 dy = GM * DIVISION(ecc + $cse3, h)
 */
void Sattraj_Satellite_eqFunction_43(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,43};
  data->localData[0]->realVars[19] /* dy variable */ = (data->simulationInfo->realParameter[0]) * (DIVISION_SIM(data->simulationInfo->realParameter[5] + data->localData[0]->realVars[7] /* $cse3 variable */,data->localData[0]->realVars[20] /* h variable */,"h",equationIndexes));
  TRACE_POP
}


int Sattraj_Satellite_functionDAE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  int equationIndexes[1] = {0};
  
  data->simulationInfo->needToIterate = 0;
  data->simulationInfo->discreteCall = 1;
  Sattraj_Satellite_functionLocalKnownVars(data, threadData);
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
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}


int Sattraj_Satellite_functionLocalKnownVars(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  TRACE_POP
  return 0;
}


int Sattraj_Satellite_functionODE(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  
  data->simulationInfo->callStatistics.functionODE++;
  
  Sattraj_Satellite_functionLocalKnownVars(data, threadData);
  /* no ODE systems */

  
  TRACE_POP
  return 0;
}

#ifdef FMU_EXPERIMENTAL
#endif
/* forward the main in the simulation runtime */
extern int _main_SimulationRuntime(int argc, char**argv, DATA *data, threadData_t *threadData);

#include "Sattraj.Satellite_12jac.h"
#include "Sattraj.Satellite_13opt.h"

struct OpenModelicaGeneratedFunctionCallbacks Sattraj_Satellite_callback = {
   (int (*)(DATA *, threadData_t *, void *)) Sattraj_Satellite_performSimulation,
   (int (*)(DATA *, threadData_t *, void *)) Sattraj_Satellite_performQSSSimulation,
   Sattraj_Satellite_updateContinuousSystem,
   Sattraj_Satellite_callExternalObjectDestructors,
   Sattraj_Satellite_initialNonLinearSystem,
   NULL,
   NULL,
   #if !defined(OMC_NO_STATESELECTION)
   Sattraj_Satellite_initializeStateSets,
   #else
   NULL,
   #endif
   Sattraj_Satellite_initializeDAEmodeData,
   Sattraj_Satellite_functionODE,
   Sattraj_Satellite_functionAlgebraics,
   Sattraj_Satellite_functionDAE,
   Sattraj_Satellite_functionLocalKnownVars,
   Sattraj_Satellite_input_function,
   Sattraj_Satellite_input_function_init,
   Sattraj_Satellite_input_function_updateStartValues,
   Sattraj_Satellite_output_function,
   Sattraj_Satellite_function_storeDelayed,
   Sattraj_Satellite_updateBoundVariableAttributes,
   Sattraj_Satellite_functionInitialEquations,
   0, /* useHomotopy - 0: no homotopy or local homotopy, 1: global homotopy, 2: new global homotopy approach */
   Sattraj_Satellite_functionInitialEquations_lambda0,
   Sattraj_Satellite_functionRemovedInitialEquations,
   Sattraj_Satellite_updateBoundParameters,
   Sattraj_Satellite_checkForAsserts,
   Sattraj_Satellite_function_ZeroCrossingsEquations,
   Sattraj_Satellite_function_ZeroCrossings,
   Sattraj_Satellite_function_updateRelations,
   Sattraj_Satellite_checkForDiscreteChanges,
   Sattraj_Satellite_zeroCrossingDescription,
   Sattraj_Satellite_relationDescription,
   Sattraj_Satellite_function_initSample,
   Sattraj_Satellite_INDEX_JAC_A,
   Sattraj_Satellite_INDEX_JAC_B,
   Sattraj_Satellite_INDEX_JAC_C,
   Sattraj_Satellite_INDEX_JAC_D,
   Sattraj_Satellite_initialAnalyticJacobianA,
   Sattraj_Satellite_initialAnalyticJacobianB,
   Sattraj_Satellite_initialAnalyticJacobianC,
   Sattraj_Satellite_initialAnalyticJacobianD,
   Sattraj_Satellite_functionJacA_column,
   Sattraj_Satellite_functionJacB_column,
   Sattraj_Satellite_functionJacC_column,
   Sattraj_Satellite_functionJacD_column,
   Sattraj_Satellite_linear_model_frame,
   Sattraj_Satellite_linear_model_datarecovery_frame,
   Sattraj_Satellite_mayer,
   Sattraj_Satellite_lagrange,
   Sattraj_Satellite_pickUpBoundsForInputsInOptimization,
   Sattraj_Satellite_setInputData,
   Sattraj_Satellite_getTimeGrid,
   Sattraj_Satellite_symbolicInlineSystem,
   Sattraj_Satellite_function_initSynchronous,
   Sattraj_Satellite_function_updateSynchronous,
   Sattraj_Satellite_function_equationsSynchronous,
   NULL,
   #ifdef FMU_EXPERIMENTAL
   Sattraj_Satellite_functionODE_Partial,
   Sattraj_Satellite_functionFMIJacobian,
   #endif
   Sattraj_Satellite_inputNames
};

void Sattraj_Satellite_setupDataStruc(DATA *data, threadData_t *threadData)
{
  assertStreamPrint(threadData,0!=data, "Error while initialize Data");
  data->callback = &Sattraj_Satellite_callback;
  data->modelData->modelName = "Sattraj.Satellite";
  data->modelData->modelFilePrefix = "Sattraj.Satellite";
  data->modelData->resultFileName = NULL;
  data->modelData->modelDir = "C:/Users/Lucas/Desktop/trackingARO";
  data->modelData->modelGUID = "{199cbaf0-e97b-4789-99e5-ac430e09f659}";
  #if defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME)
  data->modelData->initXMLData = NULL;
  data->modelData->modelDataXml.infoXMLData = NULL;
  #else
  #if defined(_MSC_VER) /* handle joke compilers */
  {
  /* for MSVC we encode a string like char x[] = {'a', 'b', 'c', '\0'} */
  /* because the string constant limit is 65535 bytes */
  static const char contents_init[] =
    #include "Sattraj.Satellite_init.c"
    ;
  static const char contents_info[] =
    #include "Sattraj.Satellite_info.c"
    ;
    data->modelData->initXMLData = contents_init;
    data->modelData->modelDataXml.infoXMLData = contents_info;
  }
  #else /* handle real compilers */
  data->modelData->initXMLData =
  #include "Sattraj.Satellite_init.c"
    ;
  data->modelData->modelDataXml.infoXMLData =
  #include "Sattraj.Satellite_info.c"
    ;
  #endif /* defined(_MSC_VER) */
  #endif /* defined(OPENMODELICA_XML_FROM_FILE_AT_RUNTIME) */
  
  data->modelData->nStates = 0;
  data->modelData->nVariablesReal = 28;
  data->modelData->nDiscreteReal = 0;
  data->modelData->nVariablesInteger = 0;
  data->modelData->nVariablesBoolean = 0;
  data->modelData->nVariablesString = 0;
  data->modelData->nParametersReal = 8;
  data->modelData->nParametersInteger = 0;
  data->modelData->nParametersBoolean = 0;
  data->modelData->nParametersString = 0;
  data->modelData->nInputVars = 0;
  data->modelData->nOutputVars = 0;
  
  data->modelData->nAliasReal = 4;
  data->modelData->nAliasInteger = 0;
  data->modelData->nAliasBoolean = 0;
  data->modelData->nAliasString = 0;
  
  data->modelData->nZeroCrossings = 0;
  data->modelData->nSamples = 0;
  data->modelData->nRelations = 0;
  data->modelData->nMathEvents = 0;
  data->modelData->nExtObjs = 0;
  data->modelData->modelDataXml.fileName = "Sattraj.Satellite_info.json";
  data->modelData->modelDataXml.modelInfoXmlLength = 0;
  data->modelData->modelDataXml.nFunctions = 1;
  data->modelData->modelDataXml.nProfileBlocks = 0;
  data->modelData->modelDataXml.nEquations = 49;
  data->modelData->nMixedSystems = 0;
  data->modelData->nLinearSystems = 0;
  data->modelData->nNonLinearSystems = 2;
  data->modelData->nStateSets = 0;
  data->modelData->nJacobians = 5;
  data->modelData->nOptimizeConstraints = 0;
  data->modelData->nOptimizeFinalConstraints = 0;
  
  data->modelData->nDelayExpressions = 0;
  
  data->modelData->nClocks = 0;
  data->modelData->nSubClocks = 0;
  
  data->modelData->nSensitivityVars = 0;
  data->modelData->nSensitivityParamVars = 0;
}

#ifdef __cplusplus
}
#endif

static int rml_execution_failed()
{
  fflush(NULL);
  fprintf(stderr, "Execution failed!\n");
  fflush(NULL);
  return 1;
}

#if defined(threadData)
#undef threadData
#endif
/* call the simulation runtime main from our main! */
int main(int argc, char**argv)
{
  int res;
  DATA data;
  MODEL_DATA modelData;
  SIMULATION_INFO simInfo;
  data.modelData = &modelData;
  data.simulationInfo = &simInfo;
  measure_time_flag = 0;
  compiledInDAEMode = 0;
  compiledWithSymSolver = 0;
  MMC_INIT(0);
  omc_alloc_interface.init();
  {
    MMC_TRY_TOP()
  
    MMC_TRY_STACK()
  
    Sattraj_Satellite_setupDataStruc(&data, threadData);
    res = _main_SimulationRuntime(argc, argv, &data, threadData);
    
    MMC_ELSE()
    rml_execution_failed();
    fprintf(stderr, "Stack overflow detected and was not caught.\nSend us a bug report at https://trac.openmodelica.org/OpenModelica/newticket\n    Include the following trace:\n");
    printStacktraceMessages();
    fflush(NULL);
    return 1;
    MMC_CATCH_STACK()
    
    MMC_CATCH_TOP(return rml_execution_failed());
  }

  fflush(NULL);
  EXIT(res);
  return res;
}

