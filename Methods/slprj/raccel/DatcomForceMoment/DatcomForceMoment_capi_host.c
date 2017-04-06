#include "DatcomForceMoment_capi_host.h"
static DatcomForceMoment_host_DataMapInfo_T root;
static int initialized = 0;
__declspec( dllexport ) rtwCAPI_ModelMappingInfo *getRootMappingInfo()
{
    if (initialized == 0) {
        initialized = 1;
        DatcomForceMoment_host_InitializeDataMapInfo(&(root), "DatcomForceMoment");
    }
    return &root.mmi;
}

rtwCAPI_ModelMappingInfo *mexFunction() {return(getRootMappingInfo());}
