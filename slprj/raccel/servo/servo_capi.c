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
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , TARGET_STRING ( "servo/Step" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 1 , 0 , TARGET_STRING ( "servo/Open Loop Motor Model/Motor Electrical Model1/Multiply1" ) , TARGET_STRING ( "Id_dot" ) , 0 , 0 , 0 , 0 , 1 } , { 2 , 0 , TARGET_STRING ( "servo/Open Loop Motor Model/Motor Electrical Model1/Multiply5" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 3 , 0 , TARGET_STRING ( "servo/Open Loop Motor Model/Motor Electrical Model1/Multiply6" ) , TARGET_STRING ( "Torque" ) , 0 , 0 , 0 , 0 , 1 } , { 4 , 0 , TARGET_STRING ( "servo/Open Loop Motor Model/Motor Electrical Model1/Integrator1" ) , TARGET_STRING ( "Id" ) , 0 , 0 , 0 , 0 , 1 } , { 5 , 0 , TARGET_STRING ( "servo/Open Loop Motor Model/Motor Electrical Model1/Integrator3" ) , TARGET_STRING ( "Iq" ) , 0 , 0 , 0 , 0 , 1 } , { 6 , 0 , TARGET_STRING ( "servo/Open Loop Motor Model/Motor Electrical Model1/Product2" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 7 , 0 , TARGET_STRING ( "servo/Open Loop Motor Model/Motor Electrical Model1/Product3" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 8 , 0 , TARGET_STRING ( "servo/Open Loop Motor Model/Motor Mechanical Model1/Multiply" ) , TARGET_STRING ( "Wm_dot" ) , 0 , 0 , 0 , 0 , 1 } , { 9 , 0 , TARGET_STRING ( "servo/Open Loop Motor Model/Motor Mechanical Model1/Integrator" ) , TARGET_STRING ( "Wm" ) , 0 , 0 , 0 , 0 , 1 } , { 10 , 0 , TARGET_STRING ( "servo/Open Loop Motor Model/Park Transform1/Subtract" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_BlockParameters rtBlockParameters [ ] = { { 11 , TARGET_STRING ( "servo/Constant2" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 12 , TARGET_STRING ( "servo/Constant5" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 13 , TARGET_STRING ( "servo/Step" ) , TARGET_STRING ( "Time" ) , 0 , 0 , 0 } , { 14 , TARGET_STRING ( "servo/Step" ) , TARGET_STRING ( "Before" ) , 0 , 0 , 0 } , { 15 , TARGET_STRING ( "servo/Step" ) , TARGET_STRING ( "After" ) , 0 , 0 , 0 } , { 16 , TARGET_STRING ( "servo/Open Loop Motor Model/Averaged Inverter Model1/Constant2" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 17 , TARGET_STRING ( "servo/Open Loop Motor Model/Clarke Transform1/Multiply" ) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 18 , TARGET_STRING ( "servo/Open Loop Motor Model/Clarke Transform1/Multiply1" ) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 19 , TARGET_STRING ( "servo/Open Loop Motor Model/Clarke Transform1/Multiply2" ) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 20 , TARGET_STRING ( "servo/Open Loop Motor Model/Clarke Transform1/Multiply3" ) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 21 , TARGET_STRING ( "servo/Open Loop Motor Model/Motor Electrical Model1/Multiply6" ) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 22 , TARGET_STRING ( "servo/Open Loop Motor Model/Motor Electrical Model1/Integrator1" ) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 23 , TARGET_STRING ( "servo/Open Loop Motor Model/Motor Electrical Model1/Integrator3" ) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 24 , TARGET_STRING ( "servo/Open Loop Motor Model/Motor Mechanical Model1/Integrator" ) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 25 , TARGET_STRING ( "servo/Open Loop Motor Model/Motor Mechanical Model1/Integrator1" ) , TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 } } ; static int_T rt_LoggedStateIdxList [ ] = { - 1 } ; static const rtwCAPI_Signals rtRootInputs [ ] = { { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_Signals rtRootOutputs [ ] = { { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_ModelParameters rtModelParameters [ ] = { { 26 , TARGET_STRING ( "Bm" ) , 0 , 0 , 0 } , { 27 , TARGET_STRING ( "J_sum" ) , 0 , 0 , 0 } , { 28 , TARGET_STRING ( "Ld" ) , 0 , 0 , 0 } , { 29 , TARGET_STRING ( "Lq" ) , 0 , 0 , 0 } , { 30 , TARGET_STRING ( "N" ) , 0 , 0 , 0 } , { 31 , TARGET_STRING ( "Rs" ) , 0 , 0 , 0 } , { 32 , TARGET_STRING ( "Ts" ) , 0 , 0 , 0 } , { 33 , TARGET_STRING ( "Vdc" ) , 0 , 0 , 0 } , { 34 , TARGET_STRING ( "lambda_m" ) , 0 , 0 , 0 } , { 0 , ( NULL ) , 0 , 0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . eukirrfpi1 , & rtB . jck1gjcgrd ,
& rtB . fpfswwk0da , & rtB . nw2flz5n5u , & rtB . grz014atlr , & rtB .
mhrjuepwy2 , & rtB . pcputk2i3l , & rtB . ecraxyuopt , & rtB . jifvn4l4cw , &
rtB . hyub0brp1k , & rtB . p2s0ejyxpc , & rtP . Constant2_Value , & rtP .
Constant5_Value , & rtP . Step_Time , & rtP . Step_Y0 , & rtP . Step_YFinal ,
& rtP . Constant2_Value_lz4gklrbyn , & rtP . Multiply_Gain , & rtP .
Multiply1_Gain , & rtP . Multiply2_Gain , & rtP . Multiply3_Gain , & rtP .
Multiply6_Gain , & rtP . Integrator1_IC , & rtP . Integrator3_IC , & rtP .
Integrator_IC , & rtP . Integrator1_IC_g5lsixmxdm , & rtP . Bm , & rtP .
J_sum , & rtP . Ld , & rtP . Lq , & rtP . N , & rtP . Rs , & rtP . Ts , & rtP
. Vdc , & rtP . lambda_m , } ; static int32_T * rtVarDimsAddrMap [ ] = { ( NULL
) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , ( uint8_T ) SS_DOUBLE , 0 , 0 , 0 } }
;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } } ; static const uint_T rtDimensionArray [ ] = {
1 , 1 } ; static const real_T rtcapiStoredFloats [ ] = { 5.0 , 0.0 } ; static
const rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) ,
rtwCAPI_FIX_RESERVED , 0 , 0 , ( boolean_T ) 0 } , } ; static const
rtwCAPI_SampleTimeMap rtSampleTimeMap [ ] = { { ( const void * ) &
rtcapiStoredFloats [ 0 ] , ( const void * ) & rtcapiStoredFloats [ 1 ] , ( int8_T ) 2 , ( uint8_T ) 0 } , { ( const void * ) & rtcapiStoredFloats [ 1 ] , ( const void * ) & rtcapiStoredFloats [ 1 ] , ( int8_T ) 0 , ( uint8_T ) 0 } } ; static rtwCAPI_ModelMappingStaticInfo mmiStatic = { { rtBlockSignals , 11 , rtRootInputs , 0 , rtRootOutputs , 0 } , { rtBlockParameters , 15 , rtModelParameters , 9 } , { ( NULL ) , 0 } , { rtDataTypeMap , rtDimensionMap , rtFixPtMap , rtElementMap , rtSampleTimeMap , rtDimensionArray } , "float" , { 3709002849U , 1308600995U , 1079983357U , 830233603U } , ( NULL ) , 0 , ( boolean_T ) 0 , rt_LoggedStateIdxList } ; const rtwCAPI_ModelMappingStaticInfo * servo_GetCAPIStaticMap ( void ) { return & mmiStatic ; }
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
