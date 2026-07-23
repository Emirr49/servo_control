#ifndef servo_h_
#define servo_h_
#ifndef servo_COMMON_INCLUDES_
#define servo_COMMON_INCLUDES_
#include <stdlib.h>
#include "sl_AsyncioQueue/AsyncioQueueCAPI.h"
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
#define NSAMPLE_TIMES (3) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (25) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (7)   
#elif NCSTATES != 7
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
typedef struct { real_T atc3xhmllx ; real_T lnrtrglc4z ; real_T mjcqqm2pms ;
real_T bxevubdttn ; real_T fmlpro40do ; real_T iq3grwz0as ; real_T gske0imb1f
; real_T n3mqj32cnq ; real_T abx3k51gem ; real_T lahjpij2n5 ; real_T
h1v2icqlmx ; real_T jhwb452g4q ; real_T orceq2buae ; real_T jw40zlt24t ;
real_T i1yh31mebw ; real_T ckm4zgqin4 ; real_T d4kl1mzlse ; real_T nidigvcht2
; real_T e4l3fvmiu0 ; real_T jzwnvza20q ; real_T fg5b5up20g ; real_T
cvgzubrmp1 ; real_T j34ymogrcu [ 2 ] ; real_T oanek01vmk ; real_T kacohxj0j0
; } B ; typedef struct { real_T o1j00ekvl1 ; real_T mrftz4gumf ; real_T
moimlsnvau ; real_T jfgfo5upea ; real_T le1n4nwhuf ; real_T fpmrsqwzzy [ 2 ]
; real_T f4w2ycii55 ; real_T ck1oumkeph ; real_T f5vp5pcpxx ; real_T
dwusab4qff ; real_T fposlr0hvk ; real_T a0ywqnj2x4 ; struct { void *
AQHandles ; } fnfqo2f2cg ; struct { void * AQHandles ; } dmww05evfq ; struct
{ void * AQHandles ; } bs3xvotlpv ; struct { void * AQHandles ; } pzkkyqu4bb
; struct { void * AQHandles ; } i2rar1avq5 ; struct { void * AQHandles ; }
aqdjwmxp2k ; struct { void * AQHandles ; } pdhy40avvz ; struct { void *
AQHandles ; } pwd4f2ufpa ; struct { void * AQHandles ; } kijkyhopib ; struct
{ void * AQHandles ; } lc5w1b42mf ; struct { void * AQHandles ; } elqz1jc2rh
; struct { void * AQHandles ; } ohoqwkgi25 ; struct { void * AQHandles ; }
f1hhsuw3b4 ; struct { void * AQHandles ; } h3cihd0dbu ; struct { void *
AQHandles ; } emimjd5vxl ; struct { void * AQHandles ; } ksgl5gesjr ; struct
{ void * AQHandles ; } m5gksresiq ; struct { void * AQHandles ; } hnzsmeitia
; int32_T d2hwqanywq ; uint32_T cmyta1nt05 ; uint32_T enm5gbilgj ; uint32_T
pnu0jnt2je ; boolean_T mjuwjteeb1 ; boolean_T bbvdczg4gy ; boolean_T
nmgmc4ky0r ; boolean_T ag2dnkoaij ; boolean_T kuppo2ntmw ; boolean_T
jwlbn0rzsm ; boolean_T lvlmeyko0j ; boolean_T h4ndyhsi1g ; boolean_T
lrxn2ft4f1 ; boolean_T mexj5hhpa3 ; } DW ; typedef struct { real_T lj4dhrjbtj
; real_T jtrkravcyu ; real_T m1debj0n30 ; real_T k5vuytyb3d ; real_T
g43v5vnx2q ; real_T hmc1eg101a ; real_T mgu525whyd ; } X ; typedef struct {
real_T lj4dhrjbtj ; real_T jtrkravcyu ; real_T m1debj0n30 ; real_T k5vuytyb3d
; real_T g43v5vnx2q ; real_T hmc1eg101a ; real_T mgu525whyd ; } XDot ;
typedef struct { boolean_T lj4dhrjbtj ; boolean_T jtrkravcyu ; boolean_T
m1debj0n30 ; boolean_T k5vuytyb3d ; boolean_T g43v5vnx2q ; boolean_T
hmc1eg101a ; boolean_T mgu525whyd ; } XDis ; typedef struct {
rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ; struct P_ { real_T Bm ; real_T
J_sum ; real_T Ld ; real_T Lq ; real_T N ; real_T Rs ; real_T lambda_m ;
real_T Ramp_InitialOutput ; real_T PIBlock1_Ki ; real_T PIBlock2_Ki ; real_T
PIBlock_Ki ; real_T PIBlock1_Kp ; real_T PIBlock2_Kp ; real_T PIBlock_Kp ;
real_T PIBlock1_Limit_Lower ; real_T PIBlock1_Limit_Upper ; real_T Ramp_slope
; real_T Ramp_start ; real_T Integrator1_IC ; real_T Quantizer_Interval ;
real_T Integrator1_IC_ev05p02mrn ; real_T RandomNumber1_Mean ; real_T
RandomNumber1_StdDev ; real_T RandomNumber1_Seed ; real_T Integrator3_IC ;
real_T RandomNumber_Mean ; real_T RandomNumber_StdDev ; real_T
RandomNumber_Seed ; real_T DiscreteTransferFcn_NumCoef [ 2 ] ; real_T
DiscreteTransferFcn_DenCoef [ 2 ] ; real_T DiscreteTransferFcn_InitialStates
; real_T Integrator_IC ; real_T Integrator_IC_cumx5taaxw ; real_T Step_Y0 ;
real_T Saturation2_UpperSat ; real_T Saturation2_LowerSat ; real_T
Integrator_IC_pfyyjjaerm ; real_T Saturation_UpperSat ; real_T
Saturation_LowerSat ; real_T Integrator_IC_khphwxipqv ; real_T
Saturation1_UpperSat ; real_T Saturation1_LowerSat ; real_T
RandomNumber2_Mean ; real_T RandomNumber2_StdDev ; real_T RandomNumber2_Seed
; real_T Step3_Time ; real_T Step3_Y0 ; real_T Step3_YFinal ; real_T
Constant1_Value ; real_T Constant_Value ; real_T Constant6_Value ; real_T
Constant7_Value ; real_T Constant8_Value ; real_T Constant_Value_a3ug1bpdkn ;
real_T Constant_Value_owzyl12gaw ; real_T Constant_Value_kvqmu1fbb1 ; } ;
extern const char_T * RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern X
rtX ; extern DW rtDW ; extern P rtP ; extern mxArray * mr_servo_GetDWork ( )
; extern void mr_servo_SetDWork ( const mxArray * ssDW ) ; extern mxArray *
mr_servo_GetSimStateDisallowedBlocks ( ) ; extern const
rtwCAPI_ModelMappingStaticInfo * servo_GetCAPIStaticMap ( void ) ; extern
SimStruct * const rtS ; extern DataMapInfo * rt_dataMapInfoPtr ; extern
rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr ; void MdlOutputs ( int_T tid )
; void MdlOutputsParameterSampleTime ( int_T tid ) ; void MdlUpdate ( int_T
tid ) ; void MdlTerminate ( void ) ; void MdlInitializeSizes ( void ) ; void
MdlInitializeSampleTimes ( void ) ; SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) ;
#endif
