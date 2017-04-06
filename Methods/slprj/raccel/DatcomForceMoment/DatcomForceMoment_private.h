#include "__cf_DatcomForceMoment.h"
#ifndef RTW_HEADER_DatcomForceMoment_private_h_
#define RTW_HEADER_DatcomForceMoment_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#if !defined(rt_VALIDATE_MEMORY)
#define rt_VALIDATE_MEMORY(S, ptr)   if(!(ptr)) {\
  ssSetErrorStatus(rtS, RT_MEMORY_ALLOCATION_ERROR);\
  }
#endif
#if !defined(rt_FREE)
#if !defined(_WIN32)
#define rt_FREE(ptr)   if((ptr) != (NULL)) {\
  free((ptr));\
  (ptr) = (NULL);\
  }
#else
#define rt_FREE(ptr)   if((ptr) != (NULL)) {\
  free((void *)(ptr));\
  (ptr) = (NULL);\
  }
#endif
#endif
#ifndef rtInterpolate
#define rtInterpolate(v1,v2,f1,f2)   (((v1)==(v2))?((double)(v1)):  (((f1)*((double)(v1)))+((f2)*((double)(v2)))))
#endif
#ifndef rtRound
#define rtRound(v) ( ((v) >= 0) ?   muDoubleScalarFloor((v) + 0.5) :   muDoubleScalarCeil((v) - 0.5) )
#endif
extern int32_T plook_s32dd_bincp ( real_T u , const real_T bp [ ] , uint32_T
maxIndex , real_T * fraction , int32_T * prevIndex ) ; extern real_T
intrp3d_s32dl_pw ( const int32_T bpIndex [ ] , const real_T frac [ ] , const
real_T table [ ] , const uint32_T stride [ ] ) ; extern real_T
intrp4d_s32dl_pw ( const int32_T bpIndex [ ] , const real_T frac [ ] , const
real_T table [ ] , const uint32_T stride [ ] ) ; extern int32_T
binsearch_s32d_prevIdx ( real_T u , const real_T bp [ ] , uint32_T startIndex
, uint32_T maxIndex ) ;
#if defined(MULTITASKING)
#error Model (DatcomForceMoment) was built in \SingleTasking solver mode, however the MULTITASKING define is \present. If you have multitasking (e.g. -DMT or -DMULTITASKING) \defined on the Code Generation page of Simulation parameter dialog, please \remove it and on the Solver page, select solver mode \MultiTasking. If the Simulation parameter dialog is configured \correctly, please verify that your template makefile is \configured correctly.
#endif
#endif
