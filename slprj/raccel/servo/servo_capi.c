#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "servo_capi_host.h"
#define sizeof(...) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)
#ifndef SS_UINT64
#define SS_UINT64 17
#endif
#ifndef SS_INT64
#define SS_INT64 18
#endif
#else
#include "builtin_typeid_types.h"
#include "servo.h"
#include "servo_capi.h"
#include "servo_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST
#define TARGET_STRING(s)               ((NULL))
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 1 , TARGET_STRING ( "servo/SMO/SMO (5 States)" ) , TARGET_STRING ( "x_hat_out5" ) , 0 , 0 , 0 , 0 , 0 } , { 1 , 1 , TARGET_STRING ( "servo/SMO/SMO (5 States)" ) , TARGET_STRING ( "w_m_est" ) , 1 , 0 , 1 , 0 , 0 } , { 2 , 1 , TARGET_STRING ( "servo/SMO/SMO (5 States)" ) , TARGET_STRING ( "theta_m_est" ) , 2 , 0 , 1 , 0 , 0 } , { 3 , 0 , TARGET_STRING ( "servo/SMO/Quantizer" ) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 1 } , { 4 , 0 , TARGET_STRING ( "servo/SMO/Random Number" ) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 5 , 0 , TARGET_STRING ( "servo/SMO/Random Number1" ) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 6 , 0 , TARGET_STRING ( "servo/SMO/Saturation" ) , TARGET_STRING ( "Iq_ref" ) , 0 , 0 , 1 , 0 , 1 } , { 7 , 0 , TARGET_STRING ( "servo/SMO/Saturation1" ) , TARGET_STRING ( "Vq" ) , 0 , 0 , 1 , 0 , 1 } , { 8 , 0 , TARGET_STRING ( "servo/SMO/Saturation2" ) , TARGET_STRING ( "W_setpoint" ) , 0 , 0 , 1 , 0 , 1 } , { 9 , 0 , TARGET_STRING ( "servo/SMO/Step3" ) , TARGET_STRING ( "T_load" ) , 0 , 0 , 1 , 0 , 1 } , { 10 , 0 , TARGET_STRING ( "servo/SMO/Add12" ) , TARGET_STRING ( "y_theta" ) , 0 , 0 , 1 , 0 , 1 } , { 11 , 0 , TARGET_STRING ( "servo/SMO/Add5" ) , TARGET_STRING ( "y_Id" ) , 0 , 0 , 1 , 0 , 1 } , { 12 , 0 , TARGET_STRING ( "servo/SMO/Add6" ) , TARGET_STRING ( "y_Iq" ) , 0 , 0 , 1 , 0 , 1 } , { 13 , 0 , TARGET_STRING ( "servo/SMO/Motor Electrical Model1/Gain3" ) , TARGET_STRING ( "T_e" ) , 0 , 0 , 1 , 0 , 1 } , { 14 , 0 , TARGET_STRING ( "servo/SMO/Motor Electrical Model1/Multiply1" ) , TARGET_STRING ( "Id_dot" ) , 0 , 0 , 1 , 0 , 1 } , { 15 , 0 , TARGET_STRING ( "servo/SMO/Motor Electrical Model1/Multiply5" ) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 1 } , { 16 , 0 , TARGET_STRING ( "servo/SMO/Motor Electrical Model1/Integrator1" ) , TARGET_STRING ( "Id" ) , 0 , 0 , 1 , 0 , 1 } , { 17 , 0 , TARGET_STRING ( "servo/SMO/Motor Electrical Model1/Integrator3" ) , TARGET_STRING ( "Iq" ) , 0 , 0 , 1 , 0 , 1 } , { 18 , 0 , TARGET_STRING ( "servo/SMO/Motor Mechanical Model1/Gain" ) , TARGET_STRING ( "Wm_dot" ) , 0 , 0 , 1 , 0 , 1 } , { 19 , 0 , TARGET_STRING ( "servo/SMO/Motor Mechanical Model1/Integrator" ) , TARGET_STRING ( "Wm" ) , 0 , 0 , 1 , 0 , 1 } , { 20 , 0 , TARGET_STRING ( "servo/SMO/Motor Mechanical Model1/Integrator1" ) , TARGET_STRING ( "theta_m" ) , 0 , 0 , 1 , 0 , 1 } , { 21 , 0 , TARGET_STRING ( "servo/SMO/PI Block/Switch" ) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 1 } , { 22 , 0 , TARGET_STRING ( "servo/SMO/PI Block1/Saturation" ) , TARGET_STRING ( "u_sat" ) , 0 , 0 , 1 , 0 , 1 } , { 23 , 0 , TARGET_STRING ( "servo/SMO/PI Block1/Switch" ) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 1 } , { 24 , 0 , TARGET_STRING ( "servo/SMO/PI Block2/Switch" ) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 1 } , { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_BlockParameters rtBlockParameters [ ] = { { 25 , TARGET_STRING ( "servo/SMO/PI Block" ) , TARGET_STRING ( "Kp" ) , 0 , 1 , 0 } , { 26 , TARGET_STRING ( "servo/SMO/PI Block" ) , TARGET_STRING ( "Ki" ) , 0 , 1 , 0 } , { 27 , TARGET_STRING ( "servo/SMO/PI Block1" ) , TARGET_STRING ( "Kp" ) , 0 , 1 , 0 } , { 28 , TARGET_STRING ( "servo/SMO/PI Block1" ) , TARGET_STRING ( "Ki" ) , 0 , 1 , 0 } , { 29 , TARGET_STRING ( "servo/SMO/PI Block1" ) , TARGET_STRING ( "Limit_Upper" ) , 0 , 1 , 0 } , { 30 , TARGET_STRING ( "servo/SMO/PI Block1" ) , TARGET_STRING ( "Limit_Lower" ) , 0 , 1 , 0 } , { 31 , TARGET_STRING ( "servo/SMO/PI Block2" ) , TARGET_STRING ( "Kp" ) , 0 , 1 , 0 } , { 32 , TARGET_STRING ( "servo/SMO/PI Block2" ) , TARGET_STRING ( "Ki" ) , 0 , 1 , 0 } , { 33 , TARGET_STRING ( "servo/SMO/Ramp" ) , TARGET_STRING ( "slope" ) , 0 , 1 , 0 } , { 34 , TARGET_STRING ( "servo/SMO/Ramp" ) , TARGET_STRING ( "start" ) , 0 , 1 , 0 } , { 35 , TARGET_STRING ( "servo/SMO/Ramp" ) , TARGET_STRING ( "InitialOutput" ) , 0 , 1 , 0 } , { 36 , TARGET_STRING ( "servo/SMO/Constant" ) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 37 , TARGET_STRING ( "servo/SMO/Constant1" ) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 38 , TARGET_STRING ( "servo/SMO/Constant6" ) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 39 , TARGET_STRING ( "servo/SMO/Constant7" ) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 40 , TARGET_STRING ( "servo/SMO/Constant8" ) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 41 , TARGET_STRING ( "servo/SMO/Quantizer" ) , TARGET_STRING ( "QuantizationInterval" ) , 0 , 1 , 0 } , { 42 , TARGET_STRING ( "servo/SMO/Random Number" ) , TARGET_STRING ( "Mean" ) , 0 , 1 , 0 } , { 43 , TARGET_STRING ( "servo/SMO/Random Number" ) , TARGET_STRING ( "StdDev" ) , 0 , 1 , 0 } , { 44 , TARGET_STRING ( "servo/SMO/Random Number" ) , TARGET_STRING ( "Seed" ) , 0 , 1 , 0 } , { 45 , TARGET_STRING ( "servo/SMO/Random Number1" ) , TARGET_STRING ( "Mean" ) , 0 , 1 , 0 } , { 46 , TARGET_STRING ( "servo/SMO/Random Number1" ) , TARGET_STRING ( "StdDev" ) , 0 , 1 , 0 } , { 47 , TARGET_STRING ( "servo/SMO/Random Number1" ) , TARGET_STRING ( "Seed" ) , 0 , 1 , 0 } , { 48 , TARGET_STRING ( "servo/SMO/Random Number2" ) , TARGET_STRING ( "Mean" ) , 0 , 1 , 0 } , { 49 , TARGET_STRING ( "servo/SMO/Random Number2" ) , TARGET_STRING ( "StdDev" ) , 0 , 1 , 0 } , { 50 , TARGET_STRING ( "servo/SMO/Random Number2" ) , TARGET_STRING ( "Seed" ) , 0 , 1 , 0 } , { 51 , TARGET_STRING ( "servo/SMO/Saturation" ) , TARGET_STRING ( "UpperLimit" ) , 0 , 1 , 0 } , { 52 , TARGET_STRING ( "servo/SMO/Saturation" ) , TARGET_STRING ( "LowerLimit" ) , 0 , 1 , 0 } , { 53 , TARGET_STRING ( "servo/SMO/Saturation1" ) , TARGET_STRING ( "UpperLimit" ) , 0 , 1 , 0 } , { 54 , TARGET_STRING ( "servo/SMO/Saturation1" ) , TARGET_STRING ( "LowerLimit" ) , 0 , 1 , 0 } , { 55 , TARGET_STRING ( "servo/SMO/Saturation2" ) , TARGET_STRING ( "UpperLimit" ) , 0 , 1 , 0 } , { 56 , TARGET_STRING ( "servo/SMO/Saturation2" ) , TARGET_STRING ( "LowerLimit" ) , 0 , 1 , 0 } , { 57 , TARGET_STRING ( "servo/SMO/Step3" ) , TARGET_STRING ( "Time" ) , 0 , 1 , 0 } , { 58 , TARGET_STRING ( "servo/SMO/Step3" ) , TARGET_STRING ( "Before" ) , 0 , 1 , 0 } , { 59 , TARGET_STRING ( "servo/SMO/Step3" ) , TARGET_STRING ( "After" ) , 0 , 1 , 0 } , { 60 , TARGET_STRING ( "servo/SMO/Discrete Transfer Fcn" ) , TARGET_STRING ( "Numerator" ) , 0 , 2 , 0 } , { 61 , TARGET_STRING ( "servo/SMO/Discrete Transfer Fcn" ) , TARGET_STRING ( "Denominator" ) , 0 , 2 , 0 } , { 62 , TARGET_STRING ( "servo/SMO/Discrete Transfer Fcn" ) , TARGET_STRING ( "InitialStates" ) , 0 , 1 , 0 } , { 63 , TARGET_STRING ( "servo/SMO/Motor Electrical Model1/Integrator1" ) , TARGET_STRING ( "InitialCondition" ) , 0 , 1 , 0 } , { 64 , TARGET_STRING ( "servo/SMO/Motor Electrical Model1/Integrator3" ) , TARGET_STRING ( "InitialCondition" ) , 0 , 1 , 0 } , { 65 , TARGET_STRING ( "servo/SMO/Motor Mechanical Model1/Integrator" ) , TARGET_STRING ( "InitialCondition" ) , 0 , 1 , 0 } , { 66 , TARGET_STRING ( "servo/SMO/Motor Mechanical Model1/Integrator1" ) , TARGET_STRING ( "InitialCondition" ) , 0 , 1 , 0 } , { 67 , TARGET_STRING ( "servo/SMO/PI Block/Constant" ) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 68 , TARGET_STRING ( "servo/SMO/PI Block/Integrator" ) , TARGET_STRING ( "InitialCondition" ) , 0 , 1 , 0 } , { 69 , TARGET_STRING ( "servo/SMO/PI Block1/Constant" ) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 70 , TARGET_STRING ( "servo/SMO/PI Block1/Integrator" ) , TARGET_STRING ( "InitialCondition" ) , 0 , 1 , 0 } , { 71 , TARGET_STRING ( "servo/SMO/PI Block2/Constant" ) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 72 , TARGET_STRING ( "servo/SMO/PI Block2/Integrator" ) , TARGET_STRING ( "InitialCondition" ) , 0 , 1 , 0 } , { 73 , TARGET_STRING ( "servo/SMO/Ramp/Step" ) , TARGET_STRING ( "Before" ) , 0 , 1 , 0 } , { 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 } } ; static int_T rt_LoggedStateIdxList [ ] = { - 1 } ; static const rtwCAPI_Signals rtRootInputs [ ] = { { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_Signals rtRootOutputs [ ] = { { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_ModelParameters rtModelParameters [ ] = { { 74 , TARGET_STRING ( "Bm" ) , 0 , 1 , 0 } , { 75 , TARGET_STRING ( "J_sum" ) , 0 , 1 , 0 } , { 76 , TARGET_STRING ( "Ld" ) , 0 , 1 , 0 } , { 77 , TARGET_STRING ( "Lq" ) , 0 , 1 , 0 } , { 78 , TARGET_STRING ( "N" ) , 0 , 1 , 0 } , { 79 , TARGET_STRING ( "Rs" ) , 0 , 1 , 0 } , { 80 , TARGET_STRING ( "lambda_m" ) , 0 , 1 , 0 } , { 0 , ( NULL ) , 0 , 0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . j34ymogrcu [ 0 ] , & rtB .
oanek01vmk , & rtB . kacohxj0j0 , & rtB . lnrtrglc4z , & rtB . n3mqj32cnq , &
rtB . fmlpro40do , & rtB . jw40zlt24t , & rtB . i1yh31mebw , & rtB .
orceq2buae , & rtB . ckm4zgqin4 , & rtB . mjcqqm2pms , & rtB . iq3grwz0as , &
rtB . abx3k51gem , & rtB . lahjpij2n5 , & rtB . d4kl1mzlse , & rtB .
nidigvcht2 , & rtB . bxevubdttn , & rtB . gske0imb1f , & rtB . e4l3fvmiu0 , &
rtB . h1v2icqlmx , & rtB . atc3xhmllx , & rtB . jzwnvza20q , & rtB .
jhwb452g4q , & rtB . fg5b5up20g , & rtB . cvgzubrmp1 , & rtP . PIBlock_Kp , &
rtP . PIBlock_Ki , & rtP . PIBlock1_Kp , & rtP . PIBlock1_Ki , & rtP .
PIBlock1_Limit_Upper , & rtP . PIBlock1_Limit_Lower , & rtP . PIBlock2_Kp , &
rtP . PIBlock2_Ki , & rtP . Ramp_slope , & rtP . Ramp_start , & rtP .
Ramp_InitialOutput , & rtP . Constant_Value , & rtP . Constant1_Value , & rtP
. Constant6_Value , & rtP . Constant7_Value , & rtP . Constant8_Value , & rtP
. Quantizer_Interval , & rtP . RandomNumber_Mean , & rtP .
RandomNumber_StdDev , & rtP . RandomNumber_Seed , & rtP . RandomNumber1_Mean
, & rtP . RandomNumber1_StdDev , & rtP . RandomNumber1_Seed , & rtP .
RandomNumber2_Mean , & rtP . RandomNumber2_StdDev , & rtP .
RandomNumber2_Seed , & rtP . Saturation_UpperSat , & rtP .
Saturation_LowerSat , & rtP . Saturation1_UpperSat , & rtP .
Saturation1_LowerSat , & rtP . Saturation2_UpperSat , & rtP .
Saturation2_LowerSat , & rtP . Step3_Time , & rtP . Step3_Y0 , & rtP .
Step3_YFinal , & rtP . DiscreteTransferFcn_NumCoef [ 0 ] , & rtP .
DiscreteTransferFcn_DenCoef [ 0 ] , & rtP . DiscreteTransferFcn_InitialStates
, & rtP . Integrator1_IC_ev05p02mrn , & rtP . Integrator3_IC , & rtP .
Integrator_IC , & rtP . Integrator1_IC , & rtP . Constant_Value_a3ug1bpdkn ,
& rtP . Integrator_IC_khphwxipqv , & rtP . Constant_Value_owzyl12gaw , & rtP
. Integrator_IC_cumx5taaxw , & rtP . Constant_Value_kvqmu1fbb1 , & rtP .
Integrator_IC_pfyyjjaerm , & rtP . Step_Y0 , & rtP . Bm , & rtP . J_sum , &
rtP . Ld , & rtP . Lq , & rtP . N , & rtP . Rs , & rtP . lambda_m , } ;
static int32_T * rtVarDimsAddrMap [ ] = { ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , ( uint8_T ) SS_DOUBLE , 0 , 0 , 0 } }
;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_MATRIX_COL_MAJOR , 0 , 2 , 0 } , { rtwCAPI_SCALAR , 2 , 2 , 0 } , {
rtwCAPI_VECTOR , 4 , 2 , 0 } } ; static const uint_T rtDimensionArray [ ] = {
2 , 1 , 1 , 1 , 1 , 2 } ; static const real_T rtcapiStoredFloats [ ] = {
0.0001 , 0.0 } ; static const rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL )
, ( NULL ) , rtwCAPI_FIX_RESERVED , 0 , 0 , ( boolean_T ) 0 } , } ; static
const rtwCAPI_SampleTimeMap rtSampleTimeMap [ ] = { { ( const void * ) &
rtcapiStoredFloats [ 0 ] , ( const void * ) & rtcapiStoredFloats [ 1 ] , ( int8_T ) 1 , ( uint8_T ) 0 } , { ( const void * ) & rtcapiStoredFloats [ 1 ] , ( const void * ) & rtcapiStoredFloats [ 1 ] , ( int8_T ) 0 , ( uint8_T ) 0 } } ; static rtwCAPI_ModelMappingStaticInfo mmiStatic = { { rtBlockSignals , 25 , rtRootInputs , 0 , rtRootOutputs , 0 } , { rtBlockParameters , 49 , rtModelParameters , 7 } , { ( NULL ) , 0 } , { rtDataTypeMap , rtDimensionMap , rtFixPtMap , rtElementMap , rtSampleTimeMap , rtDimensionArray } , "float" , { 3658945554U , 3655046140U , 774138903U , 1263221075U } , ( NULL ) , 0 , ( boolean_T ) 0 , rt_LoggedStateIdxList } ; const rtwCAPI_ModelMappingStaticInfo * servo_GetCAPIStaticMap ( void ) { return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void servo_InitializeDataMapInfo ( void ) { rtwCAPI_SetVersion ( ( *
rt_dataMapInfoPtr ) . mmi , 1 ) ; rtwCAPI_SetStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ; rtwCAPI_SetLoggingStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ; rtwCAPI_SetDataAddressMap ( ( *
rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ; rtwCAPI_SetVarDimsAddressMap ( ( *
rt_dataMapInfoPtr ) . mmi , rtVarDimsAddrMap ) ;
rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi , 0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void servo_host_InitializeDataMapInfo ( servo_host_DataMapInfo_T * dataMap ,
const char * path ) { rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ;
rtwCAPI_SetStaticMap ( dataMap -> mmi , & mmiStatic ) ;
rtwCAPI_SetDataAddressMap ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , ( NULL ) ) ; rtwCAPI_SetPath
( dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , ( NULL ) )
; rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
