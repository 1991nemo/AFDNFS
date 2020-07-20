#ifndef RTW_HEADER_TrimFandM_h_
#define RTW_HEADER_TrimFandM_h_
#include <stddef.h>
#include <string.h>
#include "rtw_modelmap.h"
#ifndef TrimFandM_COMMON_INCLUDES_
#define TrimFandM_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "sigstream_rtw.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "TrimFandM_types.h"
#include "multiword_types.h"
#include "mwmathutil.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"
#include "rtGetInf.h"
#define MODEL_NAME TrimFandM
#define NSAMPLE_TIMES (2) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (13) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (0)   
#elif NCSTATES != 0
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
typedef struct { real_T cewmuklpud [ 3 ] ; real_T c155b3ttul ; real_T
a3vyc4l10x ; real_T oouqhb3v3v ; real_T gqpi3oabc5 ; real_T lbnjpcgymq ;
real_T lqji0le141 ; real_T iwltmc0fj1 ; real_T k1zmldxyil ; real_T eitentvc2c
[ 3 ] ; real_T n20ebdvrmd [ 3 ] ; real_T dkxpu1nqs1 [ 3 ] ; real_T h5b40zrgbx
[ 3 ] ; } B ; typedef struct { struct { void * TimePtr ; void * DataPtr ;
void * RSimInfoPtr ; } ia5ajb52kh ; struct { void * LoggedData ; } ntnvdan4mi
; struct { void * LoggedData ; } pmbbvmnd0u ; struct { void * LoggedData ; }
h0d5pw5l3d ; struct { void * LoggedData ; } gjule5o53k ; struct { void *
LoggedData ; } hdjci4ngew ; struct { void * LoggedData ; } nzn2mnjcf5 ;
struct { void * LoggedData ; } hco40fajyi ; struct { void * LoggedData ; }
p25wj4xuuk ; int_T d3azz5z2mq [ 2 ] ; int_T nf3duvwzmk ; struct { int_T
PrevIndex ; } gm1dcsqrzm ; int8_T a5dgjvoljo ; int8_T luap051kiq ; int8_T
e0do2nutvy ; int8_T cqqe4ackda ; int8_T czecwii4jn ; int8_T fdafrlqdiy ;
int8_T cepg00qrhs ; int8_T pzbp2jg2ny ; int8_T kxhtuldmhk ; int8_T gbrl2nobbn
; } DW ; typedef struct { real_T k3nj40ncgz ; } ZCV ; typedef struct {
rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ; struct P_ { real_T
FlatEarthtoLLA_LL0 [ 2 ] ; real_T DragCoefficient_cD0 ; real_T
LiftCoefficient_cL0 ; real_T CompareToConstant_const ; real_T
CompareToConstant_const_lqd2aov4ko ; real_T
CompareToConstant_const_gbmczedm2k ; real_T
CompareToConstant_const_ohveajuklj ; real_T
CompareToConstant_const_m35urglgce ; real_T
CompareToConstant_const_nfpclnqcaz ; real_T LiftCoefficient_meanchord ;
real_T FlatEarthtoLLA_psi ; real_T FromWs_Time0 [ 6 ] ; real_T FromWs_Data0 [
6 ] ; real_T Constant4_Value [ 3 ] ; real_T Gain_Gain ; real_T ChSign_Gain ;
real_T ChSign1_Gain ; real_T Zero_Value ; real_T ChSign2_Gain ; real_T
SeaLevelTemperature_Value ; real_T RefAlt_Value ; real_T Constant5_Value [ 3
] ; real_T Limitaltitudetotroposhere_UpperSat ; real_T
Limitaltitudetotroposhere_LowerSat ; real_T LapseRate_Gain ; real_T uT0_Gain
; real_T gLR_Value ; real_T rho0_Gain ; real_T AltitudeofTroposphere_Value ;
real_T LimitaltitudetoStratosphere_UpperSat ; real_T
LimitaltitudetoStratosphere_LowerSat ; real_T gR_Gain ; real_T
Gain_Gain_i2ygq2tusg ; real_T Wingarea_Value ; real_T Wingspan_Value ; real_T
clbeta_Gain ; real_T Constant3_Value [ 4 ] ; real_T cldelta_a_Gain ; real_T
cldelta_r_Gain ; real_T Constant6_Value [ 3 ] ; real_T clp_Gain ; real_T
clr_Gain ; real_T Wingspan_Value_abjhsc0f24 ; real_T u_Gain ; real_T
Wingchord_Value ; real_T Cm0_Value ; real_T cmalpha_Gain ; real_T
cmdelta_f_Gain ; real_T cmdelta_e_Gain ; real_T Constant1_Value [ 3 ] ;
real_T cmalphadot_Gain ; real_T cmq_Gain ; real_T Wingchord_Value_pdh1mmrkaf
; real_T u_Gain_c3gtfmblii ; real_T gammaR_Gain ; real_T cmM_Gain ; real_T
Wingspan2_Value ; real_T cnbeta_Gain ; real_T cndelta_a_Gain ; real_T
cndelta_r_Gain ; real_T cnp_Gain ; real_T cnr_Gain ; real_T
Wingspan_Value_e2odjstrw4 ; real_T u_Gain_allopj2sjw ; real_T
TrimThrust5_Value [ 3 ] ; real_T TrimThrust5_Value_aggklib54h [ 3 ] ; real_T
Constant7_Value [ 3 ] ; real_T cLalpha_Gain ; real_T cLdelta_e_Gain ; real_T
cLdelta_f_Gain ; real_T cLalphadot_Gain ; real_T cLq_Gain ; real_T
u_Gain_nvhs5kychw ; real_T CLM_Gain ; real_T InducedDrag_Gain ; real_T
cDalpha_Gain ; real_T cDdelta_f_Gain ; real_T cDdelta_e_Gain ; real_T
cDdelta_a_Gain ; real_T cDdelta_r_Gain ; real_T cDM_Gain ; real_T
ChSign_Gain_k0w4nqg0k2 ; real_T ChSign1_Gain_n4wwtfjx2h ; real_T
ChSign2_Gain_effoydn3u1 ; real_T WingArea_Value ; real_T
ChSign_Gain_gtanyi5b3f ; real_T ChSign1_Gain_nkytdev4sk ; real_T
Zero_Value_mumexc0o4r ; real_T ChSign2_Gain_knade2nq5x ; real_T cYbeta_Gain ;
real_T cYdelta_a_Gain ; real_T cYdelta_r_Gain ; real_T cYp_Gain ; real_T
cYr_Gain ; real_T Wingspan_Value_n3iuon0ekq ; real_T u_Gain_fra5iqtqqa ;
real_T Constant_Value ; real_T Constant1_Value_gzve1ir0t2 ; real_T
Constant2_Value ; real_T Constant1_Value_axlwkx0upk ; real_T
Constant_Value_nc3vt5cgfc ; real_T Constant_Value_cvu4p50c1r ; real_T
Constant_Value_m5g2px2tx2 ; real_T f_Value ; real_T Bias_Bias ; real_T
Constant2_Value_mq0ugbio0d ; real_T Bias1_Bias ; real_T Bias_Bias_d2nkgtoec1
; real_T Gain_Gain_hksk452z1z ; real_T Bias1_Bias_gu4d3m1zk1 ; real_T
Constant_Value_ch1bn1coed ; real_T Constant3_Value_g2ewzhwyko ; real_T
Constant_Value_mxa0cv5de4 ; real_T Constant1_Value_pwlq2ttr5w ; real_T
Bias_Bias_b2ra0lewbe ; real_T Constant2_Value_mqqkn141fi ; real_T
Bias1_Bias_eoswi2rhti ; real_T Bias_Bias_kpaulxvgkm ; real_T
Constant2_Value_h4ldodunib ; real_T Bias1_Bias_cgno1ebhcg ; real_T
Bias_Bias_mvispiykz2 ; real_T Gain_Gain_lt1rzsj1bc ; real_T
Bias1_Bias_bohiusfzhl ; real_T Bias_Bias_hfb13vpfjg ; real_T
Constant2_Value_a3oznwkh02 ; real_T Bias1_Bias_hdwwrgv0bw ; real_T
TrimThrust1_Value ; real_T TrimThrust2_Value ; real_T TrimThrust3_Value ;
real_T Throttle_Gain ; real_T TrimThrust4_Value ; real_T Gain1_Gain ; real_T
mass_Value ; uint8_T ManualSwitch_CurrentSetting ; } ; extern const char *
RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern DW rtDW ; extern P rtP ;
extern const rtwCAPI_ModelMappingStaticInfo * TrimFandM_GetCAPIStaticMap (
void ) ; extern SimStruct * const rtS ; extern const int_T gblNumToFiles ;
extern const int_T gblNumFrFiles ; extern const int_T gblNumFrWksBlocks ;
extern rtInportTUtable * gblInportTUtables ; extern const char *
gblInportFileName ; extern const int_T gblNumRootInportBlks ; extern const
int_T gblNumModelInputs ; extern const int_T gblInportDataTypeIdx [ ] ;
extern const int_T gblInportDims [ ] ; extern const int_T gblInportComplex [
] ; extern const int_T gblInportInterpoFlag [ ] ; extern const int_T
gblInportContinuous [ ] ; extern const int_T gblParameterTuningTid ; extern
DataMapInfo * rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo *
rt_modelMapInfoPtr ; void MdlOutputs ( int_T tid ) ; void
MdlOutputsParameterSampleTime ( int_T tid ) ; void MdlUpdate ( int_T tid ) ;
void MdlTerminate ( void ) ; void MdlInitializeSizes ( void ) ; void
MdlInitializeSampleTimes ( void ) ; SimStruct * raccel_register_model ( void
) ;
#endif
