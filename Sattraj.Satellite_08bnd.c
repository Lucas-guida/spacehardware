/* update bound parameters and variable attributes (start, nominal, min, max) */
#include "Sattraj.Satellite_model.h"
#if defined(__cplusplus)
extern "C" {
#endif

int Sattraj_Satellite_updateBoundVariableAttributes(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  /* min ******************************************************** */
  
  infoStreamPrint(LOG_INIT, 1, "updating min-values");
  if (ACTIVE_STREAM(LOG_INIT)) messageClose(LOG_INIT);
  
  /* max ******************************************************** */
  
  infoStreamPrint(LOG_INIT, 1, "updating max-values");
  if (ACTIVE_STREAM(LOG_INIT)) messageClose(LOG_INIT);
  
  /* nominal **************************************************** */
  
  infoStreamPrint(LOG_INIT, 1, "updating nominal-values");
  if (ACTIVE_STREAM(LOG_INIT)) messageClose(LOG_INIT);
  
  /* start ****************************************************** */
  infoStreamPrint(LOG_INIT, 1, "updating primary start-values");
  if (ACTIVE_STREAM(LOG_INIT)) messageClose(LOG_INIT);
  
  TRACE_POP
  return 0;
}


/*
 equation index: 44
 type: SIMPLE_ASSIGN
 v_sat_p._z = 0.0
 */
void Sattraj_Satellite_eqFunction_44(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,44};
  data->localData[0]->realVars[25] /* v_sat_p._z variable */ = 0.0;
  TRACE_POP
}

/*
 equation index: 45
 type: SIMPLE_ASSIGN
 a = 38.61957538422518 * GM ^ 0.3333333333333333 * N0 ^ -0.6666666666666666 * pi ^ -0.6666666666666666 * 31.87975707547833
 */
void Sattraj_Satellite_eqFunction_45(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,45};
  modelica_real tmp0;
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
  tmp0 = data->simulationInfo->realParameter[0];
  tmp1 = 0.3333333333333333;
  if(tmp0 < 0.0 && tmp1 != 0.0)
  {
    tmp3 = modf(tmp1, &tmp4);
    
    if(tmp3 > 0.5)
    {
      tmp3 -= 1.0;
      tmp4 += 1.0;
    }
    else if(tmp3 < -0.5)
    {
      tmp3 += 1.0;
      tmp4 -= 1.0;
    }
    
    if(fabs(tmp3) < 1e-10)
      tmp2 = pow(tmp0, tmp4);
    else
    {
      tmp6 = modf(1.0/tmp1, &tmp5);
      if(tmp6 > 0.5)
      {
        tmp6 -= 1.0;
        tmp5 += 1.0;
      }
      else if(tmp6 < -0.5)
      {
        tmp6 += 1.0;
        tmp5 -= 1.0;
      }
      if(fabs(tmp6) < 1e-10 && ((unsigned long)tmp5 & 1))
      {
        tmp2 = -pow(-tmp0, tmp3)*pow(tmp0, tmp4);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp0, tmp1);
      }
    }
  }
  else
  {
    tmp2 = pow(tmp0, tmp1);
  }
  if(isnan(tmp2) || isinf(tmp2))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp0, tmp1);
  }tmp7 = data->simulationInfo->realParameter[2];
  tmp8 = -0.6666666666666666;
  if(tmp7 < 0.0 && tmp8 != 0.0)
  {
    tmp10 = modf(tmp8, &tmp11);
    
    if(tmp10 > 0.5)
    {
      tmp10 -= 1.0;
      tmp11 += 1.0;
    }
    else if(tmp10 < -0.5)
    {
      tmp10 += 1.0;
      tmp11 -= 1.0;
    }
    
    if(fabs(tmp10) < 1e-10)
      tmp9 = pow(tmp7, tmp11);
    else
    {
      tmp13 = modf(1.0/tmp8, &tmp12);
      if(tmp13 > 0.5)
      {
        tmp13 -= 1.0;
        tmp12 += 1.0;
      }
      else if(tmp13 < -0.5)
      {
        tmp13 += 1.0;
        tmp12 -= 1.0;
      }
      if(fabs(tmp13) < 1e-10 && ((unsigned long)tmp12 & 1))
      {
        tmp9 = -pow(-tmp7, tmp10)*pow(tmp7, tmp11);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp7, tmp8);
      }
    }
  }
  else
  {
    tmp9 = pow(tmp7, tmp8);
  }
  if(isnan(tmp9) || isinf(tmp9))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp7, tmp8);
  }tmp14 = data->simulationInfo->realParameter[6];
  tmp15 = -0.6666666666666666;
  if(tmp14 < 0.0 && tmp15 != 0.0)
  {
    tmp17 = modf(tmp15, &tmp18);
    
    if(tmp17 > 0.5)
    {
      tmp17 -= 1.0;
      tmp18 += 1.0;
    }
    else if(tmp17 < -0.5)
    {
      tmp17 += 1.0;
      tmp18 -= 1.0;
    }
    
    if(fabs(tmp17) < 1e-10)
      tmp16 = pow(tmp14, tmp18);
    else
    {
      tmp20 = modf(1.0/tmp15, &tmp19);
      if(tmp20 > 0.5)
      {
        tmp20 -= 1.0;
        tmp19 += 1.0;
      }
      else if(tmp20 < -0.5)
      {
        tmp20 += 1.0;
        tmp19 -= 1.0;
      }
      if(fabs(tmp20) < 1e-10 && ((unsigned long)tmp19 & 1))
      {
        tmp16 = -pow(-tmp14, tmp17)*pow(tmp14, tmp18);
      }
      else
      {
        throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp14, tmp15);
      }
    }
  }
  else
  {
    tmp16 = pow(tmp14, tmp15);
  }
  if(isnan(tmp16) || isinf(tmp16))
  {
    throwStreamPrint(threadData, "%s:%d: Invalid root: (%g)^(%g)", __FILE__, __LINE__, tmp14, tmp15);
  }
  data->localData[0]->realVars[15] /* a variable */ = (38.61957538422518) * ((tmp2) * ((tmp9) * ((tmp16) * (31.87975707547833))));
  TRACE_POP
}

/*
 equation index: 46
 type: SIMPLE_ASSIGN
 t = 0.0
 */
void Sattraj_Satellite_eqFunction_46(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,46};
  data->localData[0]->realVars[23] /* t variable */ = 0.0;
  TRACE_POP
}

/*
 equation index: 47
 type: SIMPLE_ASSIGN
 M = 0.0174532925199433 * mod(M0, 360.0)
 */
void Sattraj_Satellite_eqFunction_47(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,47};
  modelica_real tmp21;
  tmp21 = 360.0;
  if (tmp21 == 0) {throwStreamPrint(threadData, "Division by zero %s", "mod(M0, 360.0)");}
  data->localData[0]->realVars[14] /* M variable */ = (0.0174532925199433) * (((data->simulationInfo->realParameter[1]) - floor((data->simulationInfo->realParameter[1]) / (tmp21)) * (tmp21)));
  TRACE_POP
}

/*
 equation index: 48
 type: SIMPLE_ASSIGN
 p_sat_p._z = 0.0
 */
void Sattraj_Satellite_eqFunction_48(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,48};
  data->localData[0]->realVars[21] /* p_sat_p._z variable */ = 0.0;
  TRACE_POP
}
int Sattraj_Satellite_updateBoundParameters(DATA *data, threadData_t *threadData)
{
  TRACE_PUSH
  Sattraj_Satellite_eqFunction_44(data, threadData);

  Sattraj_Satellite_eqFunction_45(data, threadData);

  Sattraj_Satellite_eqFunction_46(data, threadData);

  Sattraj_Satellite_eqFunction_47(data, threadData);

  Sattraj_Satellite_eqFunction_48(data, threadData);
  
  TRACE_POP
  return 0;
}

#if defined(__cplusplus)
}
#endif

