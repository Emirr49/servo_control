#ifndef servo_h_
#define servo_h_
#ifndef servo_COMMON_INCLUDES_
#define servo_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "sigstream_rtw.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging_simtarget.h"
#include "rt_nonfinite.h"
#include "math.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "servo_types.h"
#include <stddef.h>
#include "rtw_modelmap_simtarget.h"
#include "rt_defines.h"
#include <string.h>
#define MODEL_NAME servo
#define NSAMPLE_TIMES (4) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (14) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (4)   
#elif NCSTATES != 4
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { real_T hyub0brp1k ; real_T mhrjuepwy2 ; real_T grz014atlr ;
real_T pcputk2i3l ; real_T ecraxyuopt ; real_T nw2flz5n5u ; real_T eukirrfpi1
; real_T p2s0ejyxpc ; real_T jck1gjcgrd ; real_T fpfswwk0da ; real_T
jifvn4l4cw ; } B ; typedef struct { struct { void * LoggedData [ 4 ] ; }
mlhnnhbvvu ; struct { void * LoggedData [ 4 ] ; } fz55ppjo5c ; struct { void
* LoggedData ; } kq1rbbg2ch ; int32_T i3lnkr0yfv ; boolean_T iglf1wkzgw ; }
DW ; typedef struct { real_T jun3ewp3xl ; real_T p0jg5xw050 ; real_T
hrlr2r32gb ; real_T pymxjtpeeh ; } X ; typedef struct { real_T jun3ewp3xl ;
real_T p0jg5xw050 ; real_T hrlr2r32gb ; real_T pymxjtpeeh ; } XDot ; typedef
struct { boolean_T jun3ewp3xl ; boolean_T p0jg5xw050 ; boolean_T hrlr2r32gb ;
boolean_T pymxjtpeeh ; } XDis ; typedef struct { rtwCAPI_ModelMappingInfo mmi
; } DataMapInfo ; struct P_ { real_T Bm ; real_T J_sum ; real_T Ld ; real_T
Lq ; real_T N ; real_T Rs ; real_T Ts ; real_T Vdc ; real_T lambda_m ; real_T
Integrator_IC ; real_T Integrator3_IC ; real_T Integrator1_IC ; real_T
Multiply6_Gain ; real_T Step_Time ; real_T Step_Y0 ; real_T Step_YFinal ;
real_T Integrator1_IC_g5lsixmxdm ; real_T Multiply_Gain ; real_T
Multiply1_Gain ; real_T Multiply2_Gain ; real_T Multiply3_Gain ; real_T
Constant2_Value ; real_T Constant5_Value ; real_T Constant2_Value_lz4gklrbyn
; } ; extern const char_T * RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ;
extern X rtX ; extern DW rtDW ; extern P rtP ; extern mxArray *
mr_servo_GetDWork ( ) ; extern void mr_servo_SetDWork ( const mxArray * ssDW
) ; extern mxArray * mr_servo_GetSimStateDisallowedBlocks ( ) ; extern const
rtwCAPI_ModelMappingStaticInfo * servo_GetCAPIStaticMap ( void ) ; extern
SimStruct * const rtS ; extern DataMapInfo * rt_dataMapInfoPtr ; extern
rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr ; void MdlOutputs ( int_T tid )
; void MdlOutputsParameterSampleTime ( int_T tid ) ; void MdlUpdate ( int_T
tid ) ; void MdlTerminate ( void ) ; void MdlInitializeSizes ( void ) ; void
MdlInitializeSampleTimes ( void ) ; SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) ;
#endif
