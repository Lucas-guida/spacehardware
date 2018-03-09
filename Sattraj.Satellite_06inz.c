/* Initialization */
#include "Sattraj.Satellite_model.h"
#include "Sattraj.Satellite_11mix.h"
#include "Sattraj.Satellite_12jac.h"
#if defined(__cplusplus)
extern "C" {
#endif

void Sattraj_Satellite_functionInitialEquations_0(DATA *data, threadData_t *threadData);


/*
 equation index: 1
 type: SIMPLE_ASSIGN
 p_sat_p._z = 0.0
 */
void Sattraj_Satellite_eqFunction_1(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,1};
  data->localData[0]->realVars[21] /* p_sat_p._z variable */ = 0.0;
  TRACE_POP
}

/*
 equation index: 2
 type: SIMPLE_ASSIGN
 M = 0.0174532925199433 * mod(M0, 360.0)
 */
void Sattraj_Satellite_eqFunction_2(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,2};
  modelica_real tmp0;
  tmp0 = 360.0;
  if (tmp0 == 0) {throwStreamPrint(threadData, "Division by zero %s", "mod(M0, 360.0)");}
  data->localData[0]->realVars[14] /* M variable */ = (0.0174532925199433) * (((data->simulationInfo->realParameter[1]) - floor((data->simulationInfo->realParameter[1]) / (tmp0)) * (tmp0)));
  TRACE_POP
}

/*
 equation index: 3
 type: SIMPLE_ASSIGN
 a = 38.61957538422518 * GM ^ 0.3333333333333333 * N0 ^ -0.6666666666666666 * pi ^ -0.6666666666666666 * 31.87975707547833
 */
void Sattraj_Satellite_eqFunction_3(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,3};
  modelica_real tmp1;
  modelica_real tmp2;
  modelica_real tmp3;
  modelica_real tmp4;
  modelica_real tmp5;
  modelica_real tmp6;
  modelica_real tmp7;
  modelica_real tmp8;
  modelica_real tmp9;
  modelica_real tmp10;
  modelica_real tmp11;
  modelica_real tmp12;
  modelica_real tmp13;
  modelica_real tmp14;
  modelica_real tmp15;
  modelica_real tmp16;
  modelica_real tmp17;
  modelica_real tmp18;
  modelica_real tmp19;
  modelica_real tmp20;
  modelica_real tmp21;
  tmp1 = data->simulationInfo->realParameter[0];
  tmp2 = 0.3333333333333333;
  if(tmp1 < 0.0 && tmp2 != 0.0)
  {
    tmp4 = modf(tmp2, &tmp5);
    
    if(tmp4 > 0.5)
    {
      tmp4 -= 1.0;
      tmp5 += 1.0;
    }
    else if(tmp4 < -0.5)
    {
      tmp4 += 1.0;
      tmp5 -= 1.0;
    }
    
    if(fabs(tmp4) < 1e-10)
      tmp3 = pow(tmp1, tmp5);
    else
    {
      tmp7 = modf(1.0/tmp2, &tmp6);
      if(tmp7 > 0.5)
      {
        tmp7 -= 1.0;
        tmp6 += 1.0;
      }
      else if(tmp7 < -0.5)
      {
        tmp7 += 1.0;
        tmp6 -= 1.0;
      }
      if(fabs(tmp7) < 1e-10 && ((unsigned long)tmp6 & 1))
      {
        tmp3 = -pow(-tmp1, tmp4)*pow(tmp1, tmp5);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp1, tmp2);
      }
    }
  }
  else
  {
    tmp3 = pow(tmp1, tmp2);
  }
  if(isnan(tmp3) || isinf(tmp3))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp1, tmp2);
  }tmp8 = data->simulationInfo->realParameter[2];
  tmp9 = -0.6666666666666666;
  if(tmp8 < 0.0 && tmp9 != 0.0)
  {
    tmp11 = modf(tmp9, &tmp12);
    
    if(tmp11 > 0.5)
    {
      tmp11 -= 1.0;
      tmp12 += 1.0;
    }
    else if(tmp11 < -0.5)
    {
      tmp11 += 1.0;
      tmp12 -= 1.0;
    }
    
    if(fabs(tmp11) < 1e-10)
      tmp10 = pow(tmp8, tmp12);
    else
    {
      tmp14 = modf(1.0/tmp9, &tmp13);
      if(tmp14 > 0.5)
      {
        tmp14 -= 1.0;
        tmp13 += 1.0;
      }
      else if(tmp14 < -0.5)
      {
        tmp14 += 1.0;
        tmp13 -= 1.0;
      }
      if(fabs(tmp14) < 1e-10 && ((unsigned long)tmp13 & 1))
      {
        tmp10 = -pow(-tmp8, tmp11)*pow(tmp8, tmp12);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp8, tmp9);
      }
    }
  }
  else
  {
    tmp10 = pow(tmp8, tmp9);
  }
  if(isnan(tmp10) || isinf(tmp10))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp8, tmp9);
  }tmp15 = data->simulationInfo->realParameter[6];
  tmp16 = -0.6666666666666666;
  if(tmp15 < 0.0 && tmp16 != 0.0)
  {
    tmp18 = modf(tmp16, &tmp19);
    
    if(tmp18 > 0.5)
    {
      tmp18 -= 1.0;
      tmp19 += 1.0;
    }
    else if(tmp18 < -0.5)
    {
      tmp18 += 1.0;
      tmp19 -= 1.0;
    }
    
    if(fabs(tmp18) < 1e-10)
      tmp17 = pow(tmp15, tmp19);
    else
    {
      tmp21 = modf(1.0/tmp16, &tmp20);
      if(tmp21 > 0.5)
      {
        tmp21 -= 1.0;
        tmp20 += 1.0;
      }
      else if(tmp21 < -0.5)
      {
        tmp21 += 1.0;
        tmp20 -= 1.0;
      }
      if(fabs(tmp21) < 1e-10 && ((unsigned long)tmp20 & 1))
      {
        tmp17 = -pow(-tmp15, tmp18)*pow(tmp15, tmp19);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp15, tmp16);
      }
    }
  }
  else
  {
    tmp17 = pow(tmp15, tmp16);
  }
  if(isnan(tmp17) || isinf(tmp17))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp15, tmp16);
  }
  data->localData[0]->realVars[15] /* a variable */ = (38.61957538422518) * ((tmp3) * ((tmp10) * ((tmp17) * (31.87975707547833))));
  TRACE_POP
}

void Sattraj_Satellite_eqFunction_4(DATA*,threadData_t*);
/*
 equation index: 5
 indexNonlinear: 0
 type: NONLINEAR
 
 vars: {E}
 eqns: {4}
 */
void Sattraj_Satellite_eqFunction_5(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,5};
  int retValue;
  if(ACTIVE_STREAM(LOG_DT))
  {
    infoStreamPrint(LOG_DT, 1, "Solving nonlinear system 5 (STRICT TEARING SET if tearing enabled) at time = %18.10e", data->localData[0]->timeValue);
    messageClose(LOG_DT);
  }
  /* get old value */
  data->simulationInfo->nonlinearSystemData[0].nlsxOld[0] = data->localData[0]->realVars[13] /* E variable */;
  retValue = solve_nonlinear_system(data, threadData, 0);
  /* check if solution process was successful */
  if (retValue > 0){
    const int indexes[2] = {1,5};
    throwStreamPrintWithEquationIndexes(threadData, indexes, "Solving non-linear system 5 failed at time=%.15g.\nFor more information please use -lv LOG_NLS.", data->localData[0]->timeValue);
  }
  /* write solution */
  data->localData[0]->realVars[13] /* E variable */ = data->simulationInfo->nonlinearSystemData[0].nlsx[0];
  TRACE_POP
}

/*
 equation index: 6
 type: SIMPLE_ASSIGN
 $TMP$VAR$6$0Y$TAN = DIVISION(tan(0.5 * E), sqrt(DIVISION(1.0 - ecc, 1.0 + ecc)))
 */
void Sattraj_Satellite_eqFunction_6(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,6};
  modelica_real tmp0;
  tmp0 = DIVISION_SIM(1.0 - data->simulationInfo->realParameter[5],1.0 + data->simulationInfo->realParameter[5],"1.0 + ecc",equationIndexes);
  if(!(tmp0 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
    throwStreamPrintWithEquationIndexes(threadData, equationIndexes, "Model error: Argument of sqrt(DIVISION(1.0 - ecc, 1.0 + ecc)) was %g should be >= 0", tmp0);
  }
  data->localData[0]->realVars[6] /* $TMP$VAR$6$0Y$TAN variable */ = DIVISION_SIM(tan((0.5) * (data->localData[0]->realVars[13] /* E variable */)),sqrt(tmp0),"sqrt(DIVISION(1.0 - ecc, 1.0 + ecc))",equationIndexes);
  TRACE_POP
}

/*
 equation index: 7
 type: SIMPLE_ASSIGN
 $TMP$VAR$6$0ATAN$TAN = atan($TMP$VAR$6$0Y$TAN)
 */
void Sattraj_Satellite_eqFunction_7(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,7};
  data->localData[0]->realVars[4] /* $TMP$VAR$6$0ATAN$TAN variable */ = atan(data->localData[0]->realVars[6] /* $TMP$VAR$6$0Y$TAN variable */);
  TRACE_POP
}

/*
 equation index: 8
 type: SIMPLE_ASSIGN
 $TMP$VAR$6$0PREX$TAN = if initial() then if pre(theta) == 0.0 then 1.0 else 0.5 * pre(theta) else 0.5 * pre(theta)
 */
void Sattraj_Satellite_eqFunction_8(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,8};
  data->localData[0]->realVars[5] /* $TMP$VAR$6$0PREX$TAN variable */ = (initial()?((data->simulationInfo->realVarsPre[24] /* theta variable */ == 0.0)?1.0:(0.5) * (data->simulationInfo->realVarsPre[24] /* theta variable */)):(0.5) * (data->simulationInfo->realVarsPre[24] /* theta variable */));
  TRACE_POP
}

/*
 equation index: 9
 type: SIMPLE_ASSIGN
 theta = 2.0 * $TMP$VAR$6$0ATAN$TAN + 6.283185307179586 * $_round(($TMP$VAR$6$0PREX$TAN - $TMP$VAR$6$0ATAN$TAN) / 3.141592653589793)
 */
void Sattraj_Satellite_eqFunction_9(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,9};
  modelica_real tmp2;
  tmp2 = 3.141592653589793;
  if (tmp2 == 0) {throwStreamPrint(threadData, "Division by zero %s", "($TMP$VAR$6$0PREX$TAN - $TMP$VAR$6$0ATAN$TAN) / 3.141592653589793");}
  data->localData[0]->realVars[24] /* theta variable */ = (2.0) * (data->localData[0]->realVars[4] /* $TMP$VAR$6$0ATAN$TAN variable */) + (6.283185307179586) * (((modelica_integer)round((modelica_real)((data->localData[0]->realVars[5] /* $TMP$VAR$6$0PREX$TAN variable */ - data->localData[0]->realVars[4] /* $TMP$VAR$6$0ATAN$TAN variable */) / tmp2))));
  TRACE_POP
}

/*
 equation index: 10
 type: SIMPLE_ASSIGN
 r = a * DIVISION(1.0 - ecc ^ 2.0, 1.0 + ecc * cos(theta))
 */
void Sattraj_Satellite_eqFunction_10(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,10};
  modelica_real tmp3;
  tmp3 = data->simulationInfo->realParameter[5];
  data->localData[0]->realVars[22] /* r variable */ = (data->localData[0]->realVars[15] /* a variable */) * (DIVISION_SIM(1.0 - ((tmp3 * tmp3)),1.0 + (data->simulationInfo->realParameter[5]) * (cos(data->localData[0]->realVars[24] /* theta variable */)),"1.0 + ecc * cos(theta)",equationIndexes));
  TRACE_POP
}

/*
 equation index: 11
 type: SIMPLE_ASSIGN
 x = r * cos(theta)
 */
void Sattraj_Satellite_eqFunction_11(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,11};
  data->localData[0]->realVars[26] /* x variable */ = (data->localData[0]->realVars[22] /* r variable */) * (cos(data->localData[0]->realVars[24] /* theta variable */));
  TRACE_POP
}

/*
 equation index: 12
 type: SIMPLE_ASSIGN
 y = r * sin(theta)
 */
void Sattraj_Satellite_eqFunction_12(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,12};
  data->localData[0]->realVars[27] /* y variable */ = (data->localData[0]->realVars[22] /* r variable */) * (sin(data->localData[0]->realVars[24] /* theta variable */));
  TRACE_POP
}

/*
 equation index: 13
 type: SIMPLE_ASSIGN
 $TMP$VAR$13$0X$ABS = pre(h)
 */
void Sattraj_Satellite_eqFunction_13(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,13};
  data->localData[0]->realVars[0] /* $TMP$VAR$13$0X$ABS variable */ = data->simulationInfo->realVarsPre[20] /* h variable */;
  TRACE_POP
}

/*
 equation index: 14
 type: SIMPLE_ASSIGN
 h = $_signNoNull($TMP$VAR$13$0X$ABS) * abs((r * (1.0 + ecc * cos(theta)) * GM) ^ 0.5)
 */
void Sattraj_Satellite_eqFunction_14(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,14};
  modelica_real tmp4;
  tmp4 = (data->localData[0]->realVars[22] /* r variable */) * ((1.0 + (data->simulationInfo->realParameter[5]) * (cos(data->localData[0]->realVars[24] /* theta variable */))) * (data->simulationInfo->realParameter[0]));
  if(!(tmp4 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
    throwStreamPrintWithEquationIndexes(threadData, equationIndexes, "Model error: Argument of sqrt(r * (1.0 + ecc * cos(theta)) * GM) was %g should be >= 0", tmp4);
  }
  data->localData[0]->realVars[20] /* h variable */ = ((data->localData[0]->realVars[0] /* $TMP$VAR$13$0X$ABS variable */ >= 0.0 ? 1.0:-1.0)) * (fabs(sqrt(tmp4)));
  TRACE_POP
}

/*
 equation index: 15
 type: SIMPLE_ASSIGN
 dr = GM * ecc * DIVISION(sin(theta), h)
 */
void Sattraj_Satellite_eqFunction_15(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,15};
  data->localData[0]->realVars[16] /* dr variable */ = (data->simulationInfo->realParameter[0]) * ((data->simulationInfo->realParameter[5]) * (DIVISION_SIM(sin(data->localData[0]->realVars[24] /* theta variable */),data->localData[0]->realVars[20] /* h variable */,"h",equationIndexes)));
  TRACE_POP
}

/*
 equation index: 16
 type: SIMPLE_ASSIGN
 dx = (-GM) * DIVISION(sin(theta), h)
 */
void Sattraj_Satellite_eqFunction_16(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,16};
  data->localData[0]->realVars[18] /* dx variable */ = ((-data->simulationInfo->realParameter[0])) * (DIVISION_SIM(sin(data->localData[0]->realVars[24] /* theta variable */),data->localData[0]->realVars[20] /* h variable */,"h",equationIndexes));
  TRACE_POP
}

/*
 equation index: 17
 type: SIMPLE_ASSIGN
 dy = GM * DIVISION(ecc + cos(theta), h)
 */
void Sattraj_Satellite_eqFunction_17(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,17};
  data->localData[0]->realVars[19] /* dy variable */ = (data->simulationInfo->realParameter[0]) * (DIVISION_SIM(data->simulationInfo->realParameter[5] + cos(data->localData[0]->realVars[24] /* theta variable */),data->localData[0]->realVars[20] /* h variable */,"h",equationIndexes));
  TRACE_POP
}

/*
 equation index: 18
 type: SIMPLE_ASSIGN
 dtheta = N0 * DIVISION(sqrt(1.0 - ecc ^ 2.0), (1.0 - ecc * cos(E)) ^ 2.0)
 */
void Sattraj_Satellite_eqFunction_18(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,18};
  modelica_real tmp5;
  modelica_real tmp6;
  modelica_real tmp7;
  tmp5 = data->simulationInfo->realParameter[5];
  tmp6 = 1.0 - ((tmp5 * tmp5));
  if(!(tmp6 >= 0.0))
  {
    FILE_INFO info = {"",0,0,0,0,0};
    omc_assert_warning(info, "The following assertion has been violated %sat time %f", initial() ? "during initialization " : "", data->localData[0]->timeValue);
    throwStreamPrintWithEquationIndexes(threadData, equationIndexes, "Model error: Argument of sqrt(1.0 - ecc ^ 2.0) was %g should be >= 0", tmp6);
  }tmp7 = 1.0 - ((data->simulationInfo->realParameter[5]) * (cos(data->localData[0]->realVars[13] /* E variable */)));
  data->localData[0]->realVars[17] /* dtheta variable */ = (data->simulationInfo->realParameter[2]) * (DIVISION_SIM(sqrt(tmp6),(tmp7 * tmp7),"(1.0 - ecc * cos(E)) ^ 2.0",equationIndexes));
  TRACE_POP
}

/*
 equation index: 19
 type: SIMPLE_ASSIGN
 t = 0.0
 */
void Sattraj_Satellite_eqFunction_19(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,19};
  data->localData[0]->realVars[23] /* t variable */ = 0.0;
  TRACE_POP
}

/*
 equation index: 20
 type: SIMPLE_ASSIGN
 v_sat_p._z = 0.0
 */
void Sattraj_Satellite_eqFunction_20(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,20};
  data->localData[0]->realVars[25] /* v_sat_p._z variable */ = 0.0;
  TRACE_POP
}
void Sattraj_Satellite_functionInitialEquations_0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  Sattraj_Satellite_eqFunction_1(data, threadData);
  Sattraj_Satellite_eqFunction_2(data, threadData);
  Sattraj_Satellite_eqFunction_3(data, threadData);
  Sattraj_Satellite_eqFunction_5(data, threadData);
  Sattraj_Satellite_eqFunction_6(data, threadData);
  Sattraj_Satellite_eqFunction_7(data, threadData);
  Sattraj_Satellite_eqFunction_8(data, threadData);
  Sattraj_Satellite_eqFunction_9(data, threadData);
  Sattraj_Satellite_eqFunction_10(data, threadData);
  Sattraj_Satellite_eqFunction_11(data, threadData);
  Sattraj_Satellite_eqFunction_12(data, threadData);
  Sattraj_Satellite_eqFunction_13(data, threadData);
  Sattraj_Satellite_eqFunction_14(data, threadData);
  Sattraj_Satellite_eqFunction_15(data, threadData);
  Sattraj_Satellite_eqFunction_16(data, threadData);
  Sattraj_Satellite_eqFunction_17(data, threadData);
  Sattraj_Satellite_eqFunction_18(data, threadData);
  Sattraj_Satellite_eqFunction_19(data, threadData);
  Sattraj_Satellite_eqFunction_20(data, threadData);
  TRACE_POP
}


int Sattraj_Satellite_functionInitialEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->discreteCall = 1;
  Sattraj_Satellite_functionInitialEquations_0(data, threadData);
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}


int Sattraj_Satellite_functionInitialEquations_lambda0(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH

  data->simulationInfo->discreteCall = 1;
  data->simulationInfo->discreteCall = 0;
  
  TRACE_POP
  return 0;
}
int Sattraj_Satellite_functionRemovedInitialEquations(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int *equationIndexes = NULL;
  double res = 0.0;

  
  TRACE_POP
  return 0;
}


#if defined(__cplusplus)
}
#endif

