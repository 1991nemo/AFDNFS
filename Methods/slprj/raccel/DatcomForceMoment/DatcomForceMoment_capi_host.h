#include "__cf_DatcomForceMoment.h"
#ifndef RTW_HEADER_DatcomForceMoment_cap_host_h_
#define RTW_HEADER_DatcomForceMoment_cap_host_h_
#ifdef HOST_CAPI_BUILD
#include "rtw_capi.h"
#include "rtw_modelmap.h"
typedef struct { rtwCAPI_ModelMappingInfo mmi ; }
DatcomForceMoment_host_DataMapInfo_T ;
#ifdef __cplusplus
extern "C" {
#endif
void DatcomForceMoment_host_InitializeDataMapInfo (
DatcomForceMoment_host_DataMapInfo_T * dataMap , const char * path ) ;
#ifdef __cplusplus
}
#endif
#endif
#endif
