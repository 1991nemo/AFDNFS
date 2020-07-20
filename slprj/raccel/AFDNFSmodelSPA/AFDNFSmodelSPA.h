#ifndef RTW_HEADER_AFDNFSmodelSPA_h_
#define RTW_HEADER_AFDNFSmodelSPA_h_
#include <stddef.h>
#include <string.h>
#include "rtw_modelmap.h"
#ifndef AFDNFSmodelSPA_COMMON_INCLUDES_
#define AFDNFSmodelSPA_COMMON_INCLUDES_
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
#include "AFDNFSmodelSPA_types.h"
#include "multiword_types.h"
#include "mwmathutil.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"
#include "rtGetInf.h"
#define MODEL_NAME AFDNFSmodelSPA
#define NSAMPLE_TIMES (3) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (61) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (15)   
#elif NCSTATES != 15
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
typedef struct { real_T mbeszndpzw [ 3 ] ; real_T pxlcyjc0py [ 3 ] ; real_T
ddodrccvry ; real_T prll55li14 [ 3 ] ; real_T jxiqnugoaw ; real_T hjeoespy50
; real_T lf41qcir2i ; real_T g2bzvajzvm [ 3 ] ; real_T nxlyj2r2ke ; real_T
igulonupg4 ; real_T iluz41jmye [ 2 ] ; real_T lbzm4w3kvc [ 4 ] ; real_T
odqjhpytke ; real_T n51upk5du5 ; real_T b4lvv4thsq ; real_T j4qce2ejgk ;
real_T j2ppwxwj2v ; real_T puqzbadmna [ 2 ] ; real_T p43ilaklx2 ; real_T
ebdsowrcxw ; real_T aa5dhjvrml ; real_T fl2tbgohhi ; real_T kf1oc12ha5 ;
real_T ltejiu1rdi ; real_T nc2kd2edsn ; real_T paumsm4ucv [ 3 ] ; real_T
pd3h1ffkcz [ 3 ] ; real_T aiijml5ggp ; real_T mlb2v0rqr4 ; real_T mmcuu43erm
; real_T babk200cg1 ; real_T eimam0aysg ; real_T n4ytkvk2rz ; real_T
hc3hgdwtyb [ 3 ] ; real_T axza31sfxm [ 3 ] ; real_T ej5pw05q3j [ 3 ] ; real_T
hhdivriu54 [ 3 ] ; real_T nco05nrykr [ 3 ] ; real_T l2let5yzu1 [ 3 ] ; real_T
bt44u1ruqs [ 3 ] ; real_T ewosjguuu0 [ 3 ] ; real_T iexmvyr4r4 [ 3 ] ; real_T
gel1pzm210 ; real_T l3nhcgjbby ; real_T obrryzou3p ; real_T l4k2a5bsh4 ;
real_T kzv3jtixuu ; real_T hcthdqledv ; real_T n5jin1c2zm ; real_T ladmdwvset
; real_T fqj3t5j0hs ; real_T gor1ljyslz [ 3 ] ; real_T bh40mgxfug ; real_T
ft1rv4ttnm [ 3 ] ; real_T hbmslxdafy [ 3 ] ; real_T lnbo3dn5b5 [ 3 ] ; real_T
mai2btwwwy [ 3 ] ; real_T dorju0mbfg ; boolean_T ar551zz3kn ; boolean_T
ku1qygrkrl ; boolean_T ao5xxbupqa ; } B ; typedef struct { struct { void *
LoggedData ; } ncc32vf3v1 ; struct { void * LoggedData ; } d0d4erxb4a ;
struct { void * TimePtr ; void * DataPtr ; void * RSimInfoPtr ; } nyrbrzpro5
; struct { void * TimePtr ; void * DataPtr ; void * RSimInfoPtr ; }
knfsqkbog3 ; struct { void * TimePtr ; void * DataPtr ; void * RSimInfoPtr ;
} k2h3rugqu1 ; struct { void * TimePtr ; void * DataPtr ; void * RSimInfoPtr
; } hcmwiu4oc2 ; struct { void * TimePtr ; void * DataPtr ; void *
RSimInfoPtr ; } ezztmokhxt ; struct { void * LoggedData ; } bz2cs2h00t ;
struct { void * LoggedData ; } ivp2ovxafm ; struct { void * LoggedData ; }
bv4ffxq4cc ; struct { void * LoggedData ; } ayqwng4oox ; struct { void *
LoggedData ; } harm20pwft ; struct { void * LoggedData ; } l0rvcjwiw5 ;
struct { void * LoggedData ; } id40jhylbg ; struct { void * LoggedData ; }
bcymmb43pv ; struct { void * LoggedData ; } fuuads50cc ; struct { void *
LoggedData ; } bh30qlhvht ; struct { void * LoggedData ; } f5t4pm1vqz ;
struct { void * LoggedData ; } etvjiflaud ; struct { void * LoggedData ; }
m425ywdp4l ; struct { void * LoggedData ; } f0ngxdtb50 ; struct { void *
LoggedData ; } gierlz4kga ; struct { void * LoggedData ; } jmgxordfxn ;
struct { void * LoggedData ; } juhedu4p0x ; struct { void * LoggedData ; }
btibqafi5k ; struct { void * LoggedData ; } bsc5lo3qxl ; struct { void *
LoggedData ; } e4fzd23hst ; struct { void * LoggedData ; } ewjd54ti05 ;
struct { void * LoggedData ; } h14pe03ska ; int_T j5skdyoj5i ; int_T
hwhk0plcbm ; int_T dgdkommmsd ; int_T bn4dbem3va [ 4 ] ; int_T kwtny14ets ;
struct { int_T PrevIndex ; } kue5d1kul0 ; struct { int_T PrevIndex ; }
exkkab2tvc ; int_T c2y55kstcc [ 4 ] ; int_T bfzneoincq ; struct { int_T
PrevIndex ; } m2zkbzyhlz ; int_T lgjhv10zvc [ 4 ] ; int_T aivemugqf1 ; struct
{ int_T PrevIndex ; } jqiesixgdv ; int_T j4k0h2foay ; int_T auwndvyfpq [ 2 ]
; int_T hqdpuh5bh4 ; struct { int_T PrevIndex ; } dfcv1ogrid ; int_T
kv4lnrjne2 ; int_T hgmvbytvsp ; int_T fb0tpkibfq ; int_T nslzihk2f5 ; int_T
hveldcssno ; int_T ef2fks3n4u ; int_T o3c1xdpheq ; int_T amfzu1el4q ; int_T
gdmux55hjy ; int_T csi2mijlzp [ 2 ] ; int_T h43rirlooy ; int_T jk5xksjzsk ;
int_T eb0yxld54a ; int_T d4kppgermp ; int_T awptayczte ; int_T chwk0ea5er ;
int_T hmcvrdlbiw ; int_T mujtalxvpm ; int_T kxe4uaswic ; int8_T i3ztellsjl ;
int8_T kdajnepqa5 ; int8_T euxjrceybc ; int8_T lq4r04u54d ; int8_T jro3w2jetk
; int8_T fciwvikpdr ; int8_T n5ngktfrhq ; int8_T dxc22zb0w3 ; int8_T
mqarvij1wr ; int8_T dkeirtfvst ; int8_T arnvx1x5wb ; int8_T f5ilhbx002 ;
boolean_T ligunf0r1k ; boolean_T mug4q33r34 ; boolean_T bzoc2ge3pm ; } DW ;
typedef struct { real_T hkxwzleotw [ 3 ] ; real_T md4byhppt3 [ 3 ] ; real_T
jwktqmf5nt [ 3 ] ; real_T a2thzvctjt [ 3 ] ; real_T ag4giqb3jg ; real_T
papl5plp0u ; real_T kzigeirre3 ; } X ; typedef struct { real_T hkxwzleotw [ 3
] ; real_T md4byhppt3 [ 3 ] ; real_T jwktqmf5nt [ 3 ] ; real_T a2thzvctjt [ 3
] ; real_T ag4giqb3jg ; real_T papl5plp0u ; real_T kzigeirre3 ; } XDot ;
typedef struct { boolean_T hkxwzleotw [ 3 ] ; boolean_T md4byhppt3 [ 3 ] ;
boolean_T jwktqmf5nt [ 3 ] ; boolean_T a2thzvctjt [ 3 ] ; boolean_T
ag4giqb3jg ; boolean_T papl5plp0u ; boolean_T kzigeirre3 ; } XDis ; typedef
struct { real_T hkxwzleotw [ 3 ] ; real_T md4byhppt3 [ 3 ] ; real_T
jwktqmf5nt [ 3 ] ; real_T a2thzvctjt [ 3 ] ; real_T ag4giqb3jg ; real_T
papl5plp0u ; real_T kzigeirre3 ; } CStateAbsTol ; typedef struct { real_T
hkxwzleotw [ 3 ] ; real_T md4byhppt3 [ 3 ] ; real_T jwktqmf5nt [ 3 ] ; real_T
a2thzvctjt [ 3 ] ; real_T ag4giqb3jg ; real_T papl5plp0u ; real_T kzigeirre3
; } CXPtMin ; typedef struct { real_T hkxwzleotw [ 3 ] ; real_T md4byhppt3 [
3 ] ; real_T jwktqmf5nt [ 3 ] ; real_T a2thzvctjt [ 3 ] ; real_T ag4giqb3jg ;
real_T papl5plp0u ; real_T kzigeirre3 ; } CXPtMax ; typedef struct { real_T
esxwhjpixn ; real_T jl3mbtekoy ; real_T m1ecruo3jg ; real_T cfdlx3be1l ;
real_T kiryj23le1 ; real_T cdzkij01l3 ; real_T lnafym5qo0 ; real_T dvyvvk0pax
; real_T a0x5kr2xu1 ; real_T fo2a53r5z4 ; real_T p0wuzgany1 ; real_T
jlivwyxcs1 ; real_T kxfxfrzymu ; real_T cqtewcutcm ; real_T jea0fndtzq [ 2 ]
; real_T fnqiehf0iq [ 2 ] ; real_T ksjmic4fui ; real_T ozr3k2rs0z ; real_T
fzrm0x3g5u ; real_T hwhadsnigc ; real_T miseu2fsh3 ; real_T jsx5vij2em ;
real_T nkmzx4dpc2 ; real_T d3j52t4cdu ; real_T jgjmx24uez ; real_T ajsprelrkn
; real_T icmmjkv3h0 ; real_T pqje4iwe4y ; real_T nlsfj3nrys ; real_T
agxt5l3hh0 ; } ZCV ; typedef struct { rtwCAPI_ModelMappingInfo mmi ; }
DataMapInfo ; struct P_ { real_T FlatEarthtoLLA_LL0 [ 2 ] ; real_T
Doublet_T_start ; real_T Doublet_amp ; real_T DragCoefficient_cD0 ; real_T
LiftCoefficient_cL0 ; real_T CompareToConstant_const ; real_T
CompareToConstant_const_b0xas2jkq3 ; real_T
CompareToConstant_const_kmoxadnhb5 ; real_T
CompareToConstant_const_nifrvxypha ; real_T
CompareToConstant_const_lrvr5wm4my ; real_T
CompareToConstant_const_obwydhle4i ; real_T LiftCoefficient_meanchord ;
real_T FlatEarthtoLLA_psi ; real_T Doublet_span ; real_T Bias_Bias ; real_T
Gain_Gain ; real_T Bias1_Bias ; real_T Bias_Bias_egwxvvuqi5 ; real_T
Bias1_Bias_hhxbgizgvm ; real_T Bias_Bias_eiu2cdruu3 ; real_T
Bias1_Bias_hfpwrebp0l ; real_T Gain_Gain_mxsmwhuwrc ; real_T Gain7_Gain ;
real_T Gain1_Gain ; real_T Gain6_Gain ; real_T Gain2_Gain ; real_T Gain5_Gain
; real_T Gain3_Gain ; real_T Gain4_Gain ; real_T Gain2_Gain_ntnvl1cqpn ;
real_T ChSign2_Gain ; real_T ChSign_Gain ; real_T ChSign1_Gain ; real_T
ChSign2_Gain_blrwynkzlu ; real_T Limitaltitudetotroposhere_UpperSat ; real_T
Limitaltitudetotroposhere_LowerSat ; real_T LapseRate_Gain ; real_T uT0_Gain
; real_T rho0_Gain ; real_T LimitaltitudetoStratosphere_UpperSat ; real_T
LimitaltitudetoStratosphere_LowerSat ; real_T gR_Gain ; real_T
Gain_Gain_d31dqzkeif ; real_T cLalpha_Gain ; real_T Step_Y0 ; real_T Step1_Y0
; real_T Step2_Y0 ; real_T Step3_Y0 ; real_T FromWs_Time0 [ 13 ] ; real_T
FromWs_Data0 [ 13 ] ; real_T FromWs_Time0_elms23aku5 [ 9 ] ; real_T
FromWs_Data0_epwwwxrf5p [ 9 ] ; real_T FromWs_Time0_dbgr3faoo4 [ 13 ] ;
real_T FromWs_Data0_gk1j2xmtdn [ 13 ] ; real_T FromWs_Time0_l0kcnhlhti [ 13 ]
; real_T FromWs_Data0_pabez3hm0f [ 13 ] ; real_T LongLQR_Gain [ 4 ] ; real_T
Gain_Gain_is0it0xd34 ; real_T Saturation1_UpperSat ; real_T
Saturation1_LowerSat ; real_T LatLQR_Gain [ 10 ] ; real_T
Gain1_Gain_mfxdzqt1sa ; real_T Saturation2_UpperSat ; real_T
Saturation2_LowerSat ; real_T cLdelta_e_Gain ; real_T cLdelta_f_Gain ; real_T
TransferFcn_A ; real_T TransferFcn_C ; real_T cLalphadot_Gain ; real_T
cLq_Gain ; real_T u_Gain ; real_T gammaR_Gain ; real_T CLM_Gain ; real_T
InducedDrag_Gain ; real_T cDalpha_Gain ; real_T cDdelta_f_Gain ; real_T
cDdelta_e_Gain ; real_T cDdelta_a_Gain ; real_T cDdelta_r_Gain ; real_T
cDM_Gain ; real_T ChSign_Gain_pd02wcxouh ; real_T cYbeta_Gain ; real_T
cYdelta_a_Gain ; real_T cYdelta_r_Gain ; real_T cYp_Gain ; real_T cYr_Gain ;
real_T u_Gain_pb5qen5bq2 ; real_T ChSign1_Gain_jgqy0alfoa ; real_T
FromWs_Time0_i2ajdr5pty [ 6 ] ; real_T FromWs_Data0_hempjedlcs [ 6 ] ; real_T
Gain1_Gain_jlinvxtcyq ; real_T Gain_Gain_fldlnfjp4b ; real_T
ChSign_Gain_jrexwz533r ; real_T ChSign1_Gain_p1dv1gzhg0 ; real_T
ChSign2_Gain_mg4y2ieuqq ; real_T clbeta_Gain ; real_T cldelta_a_Gain ; real_T
cldelta_r_Gain ; real_T clp_Gain ; real_T clr_Gain ; real_T u_Gain_dzcqhyfoug
; real_T cmalpha_Gain ; real_T cmdelta_f_Gain ; real_T cmdelta_e_Gain ;
real_T cmalphadot_Gain ; real_T cmq_Gain ; real_T u_Gain_kpl0cbpinj ; real_T
cmM_Gain ; real_T cnbeta_Gain ; real_T cndelta_a_Gain ; real_T cndelta_r_Gain
; real_T cnp_Gain ; real_T cnr_Gain ; real_T u_Gain_p0db5lqo0p ; real_T
Gain1_Gain_b1hf4hkty0 ; real_T Gain_Gain_dqhhuexjt5 ; real_T
Gain5_Gain_lm3oic4sdo ; real_T Gain3_Gain_hjbg4mtw5c [ 3 ] ; real_T
Gain4_Gain_l0vaw0ty4p [ 3 ] ; real_T TransferFcn1_A ; real_T TransferFcn1_C ;
real_T Constant_Value ; real_T AltitudeofTroposphere_Value ; real_T
SeaLevelTemperature_Value ; real_T gLR_Value ; real_T Zero_Value ; real_T
WingArea_Value ; real_T Wingspan_Value ; real_T Zero_Value_dhaiu1n4hb ;
real_T Wingarea_Value ; real_T Wingchord_Value ; real_T
Wingspan_Value_cr0bafp5uf ; real_T Wingspan2_Value ; real_T Cm0_Value ;
real_T Wingchord_Value_emuwkezyaz ; real_T Wingspan_Value_drrojpryp4 ; real_T
Wingspan_Value_erx3lkovhx ; real_T Constant_Value_o10wbquf15 ; real_T
Constant1_Value ; real_T Constant2_Value ; real_T Constant2_Value_aoptzpbs55
; real_T Constant_Value_bx2r5flqh4 ; real_T Constant1_Value_folsuaqk2w ;
real_T Bias_Bias_lfg1tbgilu ; real_T Constant2_Value_muoeisyhao ; real_T
Bias1_Bias_dxmrixcsmx ; real_T Bias_Bias_f2s41qt1rc ; real_T
Gain_Gain_p3bohr0orw ; real_T Bias1_Bias_h3sn5uls4z ; real_T
Bias_Bias_d5zpfez5uz ; real_T Constant2_Value_ir4n4t0fex ; real_T
Bias1_Bias_ewxdzezg00 ; real_T Constant_Value_lljga3nj5j ; real_T
Constant1_Value_d1hfa5vt1i ; real_T Constant2_Value_pkofftudxg ; real_T
Constant3_Value ; real_T Constant_Value_mibaoj2rgl ; real_T
Constant_Value_enfqz0alpl ; real_T Constant_Value_mjz5zpttx1 ; real_T f_Value
; real_T RefAlt_Value ; real_T TrimThrust1_Value ; real_T TrimThrust2_Value ;
real_T TrimThrust3_Value ; real_T Throttle_Gain ; real_T TrimThrust4_Value ;
real_T TrimThrust5_Value [ 3 ] ; real_T mass_Value ; real_T
TrimThrust5_Value_pghqg4ahuq [ 3 ] ; real_T Constant_Value_ki5yoscsu1 ;
real_T Constant1_Value_old4tikkcg ; real_T Constant2_Value_lh0btpjb3l [ 9 ] ;
real_T Constant3_Value_f1k1adieba [ 9 ] ; real_T Constant4_Value [ 3 ] ;
real_T Constant6_Value [ 3 ] ; real_T Constant7_Value [ 3 ] ; real_T
Constant8_Value [ 3 ] ; real_T Constant2_Value_eiuvnldjii [ 4 ] ; real_T
Constant_Value_ldaynjj304 ; real_T Constant1_Value_aja1fvk5dn [ 2 ] ; real_T
Constant2_Value_gm0og1aigu ; real_T dF_Value ; real_T ControlledPlant_Value [
4 ] ; real_T Constant_Value_iltbyzakku [ 3 ] ; real_T
Constant2_Value_bvlfok2r5u ; real_T FreePlant_Value [ 4 ] ; real_T
Constant1_Value_of0klte1gr ; real_T Constant2_Value_ol34lh25j4 ; real_T
Constant3_Value_ey1nyz4g22 ; real_T Constant4_Value_iwlbmt1pf3 ; uint8_T
ManualSwitch1_CurrentSetting ; uint8_T ManualSwitch_CurrentSetting ; uint8_T
ManualSwitch2_CurrentSetting ; uint8_T
ManualSwitch1_CurrentSetting_g2n2m14h1o ; uint8_T
ManualSwitch_CurrentSetting_mbegp1wenu ; } ; extern const char *
RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern X rtX ; extern DW rtDW ;
extern P rtP ; extern const rtwCAPI_ModelMappingStaticInfo *
AFDNFSmodelSPA_GetCAPIStaticMap ( void ) ; extern SimStruct * const rtS ;
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
