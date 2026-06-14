#ifndef servo_cap_host_h__
#define servo_cap_host_h__
#ifdef HOST_CAPI_BUILD
#include "rtw_capi.h"
#include "rtw_modelmap_simtarget.h"
typedef struct { rtwCAPI_ModelMappingInfo mmi ; } servo_host_DataMapInfo_T ;
#ifdef __cplusplus
extern "C" {
#endif
void servo_host_InitializeDataMapInfo ( servo_host_DataMapInfo_T * dataMap ,
const char * path ) ;
#ifdef __cplusplus
}
#endif
#endif
#endif
