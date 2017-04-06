#include "__cf_DatcomForceMoment.h"
#ifndef RTW_HEADER_DatcomForceMoment_h_
#define RTW_HEADER_DatcomForceMoment_h_
#include <stddef.h>
#include <string.h>
#include "rtw_modelmap.h"
#ifndef DatcomForceMoment_COMMON_INCLUDES_
#define DatcomForceMoment_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "sigstream_rtw.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "rt_logging.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "DatcomForceMoment_types.h"
#include "multiword_types.h"
#include "mwmathutil.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"
#define MODEL_NAME DatcomForceMoment
#define NSAMPLE_TIMES (3) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (34) 
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
typedef struct { real_T nhxk0ib0lj ; real_T jf5nt45ccr ; real_T hzbuxpmezj ;
real_T pw5gjuojru [ 3 ] ; real_T fsutp3ayo3 [ 9 ] ; real_T idhxicsqcr ;
real_T mml2ndjd5d ; real_T hbts5j1pqq [ 9 ] ; real_T f2a4bnffor ; real_T
ookv2bvvls ; real_T phcwtlgyip ; real_T bbuiyhe1o5 ; real_T mxt20vlpck ;
real_T ianx2c50xl ; real_T n3teuvsdd5 ; real_T kacxif5qn0 ; real_T oxq5mf1mg3
; real_T iayveggtaq ; real_T il1zzs3oim ; real_T lanxaiurnw ; real_T
hxsqezn2an [ 3 ] ; real_T n2spnyfef4 ; real_T ab5d34lf4o ; real_T jjpibu4asu
; real_T igwvaibikt [ 3 ] ; real_T jwtgtch3mu [ 3 ] ; real_T m1nsvprq1z [ 3 ]
; real_T bdzrxsq0jb [ 9 ] ; real_T dp5pi2avlk [ 3 ] ; real_T ilvgb1vukq [ 3 ]
; real_T kies3oo3id [ 3 ] ; real_T pg2hzggfwd [ 3 ] ; real_T lzr1wnncjo [ 6 ]
; real_T jvmj3dgdoq ; } B ; typedef struct { real_T lshsqezqdg ; real_T
glhg1qagai ; real_T noao4ocazt ; real_T davtpmukf5 ; real_T ou0twhytn5 ;
real_T iub22gul40 ; real_T hgbmrfgo34 ; real_T bdnvmlo1qe ; struct { void *
TimePtr ; void * DataPtr ; void * RSimInfoPtr ; } l43hqho0yh ; struct { void
* LoggedData ; } kr5bwg1sps ; struct { void * LoggedData ; } f2fmemooxc ;
struct { void * LoggedData ; } ir3clx43vq ; struct { void * LoggedData ; }
ntqydpj2su ; struct { void * LoggedData ; } hjm1dzxvpi ; int32_T eavb5jrhyr ;
int32_T hod3grnuyb ; int32_T m54rowgddh ; int32_T c3s1ykl5ma ; int32_T
htx1g0xx41 ; int32_T mi4wxn4zbd ; struct { int_T PrevIndex ; } cffy3oatmx ; }
DW ; typedef struct { rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ; struct
P_ { real_T u [ 17 ] ; real_T Constant1_Value ; real_T Constant_Value ;
real_T Constant2_Value ; real_T Constant4_Value ; real_T Constant3_Value ;
real_T SeaLevelTemperature_Value ; real_T Limitaltitudetotroposhere_UpperSat
; real_T Limitaltitudetotroposhere_LowerSat ; real_T LapseRate_Gain ; real_T
uT0_Gain ; real_T gLR_Value ; real_T rho0_Gain ; real_T
AltitudeofTroposphere_Value ; real_T LimitaltitudetoStratosphere_UpperSat ;
real_T LimitaltitudetoStratosphere_LowerSat ; real_T gR_Gain ; real_T
Gain_Gain ; real_T Constant_Value_cddtuuqxak ; real_T alpha_BreakpointsData [
9 ] ; real_T gammaR_Gain ; real_T Mach_BreakpointsData [ 2 ] ; real_T
altitude_BreakpointsData [ 3 ] ; real_T CD_Table [ 54 ] ; real_T CYb_Table [
54 ] ; real_T BetaSaturation_UpperSat ; real_T BetaSaturation_LowerSat ;
real_T CL_Table [ 54 ] ; real_T coefAdjust_Gain [ 3 ] ; real_T
Constant1_Value_n0vvf1ru2i ; real_T Constant_Value_gzdzpzihxe ; real_T
Constant2_Value_eqjwl24tzr ; real_T Constant4_Value_bijw4dwdaf ; real_T
Constant3_Value_emiujykzul ; real_T Constant6_Value ; real_T zero_Value ;
real_T CYp1_Table [ 54 ] ; real_T u_Value ; real_T Constant_Value_fhedlbhuxr
; real_T u_Value_jauwwxrr5h ; real_T BetaSaturation1_UpperSat ; real_T
BetaSaturation1_LowerSat ; real_T CLad1_Table [ 54 ] ; real_T Clp1_Table [ 54
] ; real_T Clq1_Table [ 54 ] ; real_T Clr1_Table [ 54 ] ; real_T Cmq1_Table [
54 ] ; real_T Cmad1_Table [ 54 ] ; real_T Cnp1_Table [ 54 ] ; real_T
Cnr1_Table [ 54 ] ; real_T Gain1_Gain [ 6 ] ; real_T u_Value_agropua0cl ;
real_T coefAdjust_Gain_blqcdygkok [ 3 ] ; real_T Constant1_Value_e4b4arvsx4 ;
real_T Constant_Value_epkxnw5b5k ; real_T Constant2_Value_i0tusarllo ; real_T
Constant4_Value_ebczl1p2kp ; real_T Constant3_Value_n2bp44blge ; real_T
Constant1_Value_f1v4g1iait ; real_T delta_f_BreakpointsData [ 9 ] ; real_T
DCDI_Table [ 486 ] ; real_T Constant1_Value_bhkzpq4cm3 ; real_T DCL_Table [
486 ] ; real_T Constant2_Value_old3zd5smi ; real_T DCm_Table [ 486 ] ; real_T
Constant3_Value_nvs1o44prj ; real_T delta_e_BreakpointsData [ 9 ] ; real_T
DCDI_Table_ectqqf4lpu [ 486 ] ; real_T Constant1_Value_dvrrjd2vth ; real_T
DCL_Table_b2ogh4jov4 [ 486 ] ; real_T Constant2_Value_n1gt4skuej ; real_T
DCm_Table_jpppnjjyiv [ 486 ] ; real_T Constant3_Value_ammrq4bbzx ; real_T
Constant6_Value_o2itzcqfbo ; real_T Constant1_Value_jj4sc0nzo2 ; real_T
Constant5_Value ; real_T delta_a_BreakpointsData [ 9 ] ; real_T DCl_Table [
486 ] ; real_T Constant4_Value_bxodvzr3wv ; real_T DCn_Table [ 486 ] ; real_T
Gain_Gain_gtonf3ckiq ; real_T coefAdjust_Gain_jhgwt4xcre [ 3 ] ; real_T
Gain1_Gain_gk1wozgh1p ; real_T WeightForce_Value ; real_T TrimThrust1_Value ;
real_T TrimThrust2_Value ; real_T TrimThrust3_Value ; real_T Throttle_Gain ;
real_T FromWs_Time0 [ 6 ] ; real_T FromWs_Data0 [ 6 ] ; real_T
TrimThrust4_Value ; real_T Constant1_Value_bylbexapfl ; real_T
Constant_Value_gi4rxypddg ; real_T Constant2_Value_ntj1nxsmyj ; real_T
Constant4_Value_g531dn02hg ; real_T Constant3_Value_irkjubdpiu ; real_T
Constant1_Value_ic5cse51j2 ; real_T Constant_Value_hfw2vld21b ; real_T
Constant2_Value_iq4hlvezb4 ; real_T Constant4_Value_p1gsoflfkl ; real_T
Constant3_Value_bfs2kyqhyj ; real_T Xcp_Table [ 54 ] ; real_T
Constant4_Value_lvvzxuwh5z ; real_T zero1_Value ; real_T Clb_Table [ 54 ] ;
real_T Cm_Table [ 54 ] ; real_T Cnb_Table [ 54 ] ; real_T
Constant2_Value_mwviqzbxqh ; real_T Constant1_Value_g0n03q330k ; real_T
Constant_Value_ejuc1rn4ry ; real_T Constant2_Value_oqrmwaotar ; real_T
Constant4_Value_jl0l41uur4 ; real_T Constant3_Value_gaexcfymgv ; real_T
Constant1_Value_hei4fwlj0u ; real_T Constant_Value_fbwwe2lmsk ; real_T
Constant2_Value_d4ghahoovd ; real_T Constant4_Value_iw11bz0kqi ; real_T
Constant3_Value_pp0fbeghm2 ; real_T Constant7_Value ; real_T Constant8_Value
; real_T Constant1_Value_ol4tirigyp ; real_T Constant_Value_kouoqvqr2q ;
real_T Constant2_Value_gjwptupmqz ; real_T Constant4_Value_cbj5azvbu2 ;
real_T Constant3_Value_pwsvvqm1ni ; real_T Constant1_Value_knfpzjs1ar ;
real_T Constant_Value_huxzftueqj ; real_T Constant2_Value_oqyl4nphju ; real_T
Constant4_Value_ijxamwyxru ; real_T Constant3_Value_idex1eazwv ; real_T
Constant3_Value_c0ie4jx1vv ; real_T Constant5_Value_hu2bresth1 ; real_T
WeightMoment_Value [ 3 ] ; real_T TrimThrust5_Value [ 3 ] ; uint32_T
CD_dimSize [ 3 ] ; uint32_T CYb_dimSize [ 3 ] ; uint32_T CL_dimSize [ 3 ] ;
uint32_T CYp1_dimSize [ 3 ] ; uint32_T CLad1_dimSize [ 3 ] ; uint32_T
Clp1_dimSize [ 3 ] ; uint32_T Clq1_dimSize [ 3 ] ; uint32_T Clr1_dimSize [ 3
] ; uint32_T Cmq1_dimSize [ 3 ] ; uint32_T Cmad1_dimSize [ 3 ] ; uint32_T
Cnp1_dimSize [ 3 ] ; uint32_T Cnr1_dimSize [ 3 ] ; uint32_T DCDI_dimSize [ 4
] ; uint32_T DCL_dimSize [ 4 ] ; uint32_T DCm_dimSize [ 4 ] ; uint32_T
DCDI_dimSize_hvypykhf0h [ 4 ] ; uint32_T DCL_dimSize_i0jbywo0xh [ 4 ] ;
uint32_T DCm_dimSize_oju4dybify [ 4 ] ; uint32_T DCl_dimSize [ 4 ] ; uint32_T
DCn_dimSize [ 4 ] ; uint32_T Xcp_dimSize [ 3 ] ; uint32_T Clb_dimSize [ 3 ] ;
uint32_T Cm_dimSize [ 3 ] ; uint32_T Cnb_dimSize [ 3 ] ; uint8_T
ManualSwitch_CurrentSetting ; } ; extern const char *
RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern DW rtDW ; extern P rtP ;
extern const rtwCAPI_ModelMappingStaticInfo *
DatcomForceMoment_GetCAPIStaticMap ( void ) ; extern SimStruct * const rtS ;
extern const int_T gblNumToFiles ; extern const int_T gblNumFrFiles ; extern
const int_T gblNumFrWksBlocks ; extern rtInportTUtable * gblInportTUtables ;
extern const char * gblInportFileName ; extern const int_T
gblNumRootInportBlks ; extern const int_T gblNumModelInputs ; extern const
int_T gblInportDataTypeIdx [ ] ; extern const int_T gblInportDims [ ] ;
extern const int_T gblInportComplex [ ] ; extern const int_T
gblInportInterpoFlag [ ] ; extern const int_T gblInportContinuous [ ] ;
extern const int_T gblParameterTuningTid ; extern DataMapInfo *
rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr ;
void MdlOutputs ( int_T tid ) ; void MdlOutputsParameterSampleTime ( int_T
tid ) ; void MdlUpdate ( int_T tid ) ; void MdlTerminate ( void ) ; void
MdlInitializeSizes ( void ) ; void MdlInitializeSampleTimes ( void ) ;
SimStruct * raccel_register_model ( void ) ;
#endif
