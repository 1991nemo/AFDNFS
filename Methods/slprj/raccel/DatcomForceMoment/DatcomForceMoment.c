#include "__cf_DatcomForceMoment.h"
#include "rt_logging_mmi.h"
#include "DatcomForceMoment_capi.h"
#include <math.h>
#include "DatcomForceMoment.h"
#include "DatcomForceMoment_private.h"
#include "DatcomForceMoment_dt.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 1 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 1 ; int_T gbl_raccel_NumST = 3 ; const char_T
* gbl_raccel_Version = "8.11 (R2016b) 25-Aug-2016" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const char * gblSlvrJacPatternFileName =
"slprj\\raccel\\DatcomForceMoment\\DatcomForceMoment_Jpattern.mat" ; const
int_T gblNumRootInportBlks = 0 ; const int_T gblNumModelInputs = 0 ; extern
rtInportTUtable * gblInportTUtables ; extern const char * gblInportFileName ;
const int_T gblInportDataTypeIdx [ ] = { - 1 } ; const int_T gblInportDims [
] = { - 1 } ; const int_T gblInportComplex [ ] = { - 1 } ; const int_T
gblInportInterpoFlag [ ] = { - 1 } ; const int_T gblInportContinuous [ ] = {
- 1 } ;
#include "simstruc.h"
#include "fixedpoint.h"
B rtB ; DW rtDW ; static SimStruct model_S ; SimStruct * const rtS = &
model_S ; int32_T plook_s32dd_bincp ( real_T u , const real_T bp [ ] ,
uint32_T maxIndex , real_T * fraction , int32_T * prevIndex ) { int32_T
bpIndex ; if ( u <= bp [ 0U ] ) { bpIndex = 0 ; * fraction = 0.0 ; } else if
( u < bp [ maxIndex ] ) { bpIndex = binsearch_s32d_prevIdx ( u , bp , (
uint32_T ) * prevIndex , maxIndex ) ; * fraction = ( u - bp [ ( uint32_T )
bpIndex ] ) / ( bp [ bpIndex + 1U ] - bp [ ( uint32_T ) bpIndex ] ) ; } else
{ bpIndex = ( int32_T ) ( maxIndex - 1U ) ; * fraction = 1.0 ; } * prevIndex
= bpIndex ; return bpIndex ; } real_T intrp3d_s32dl_pw ( const int32_T
bpIndex [ ] , const real_T frac [ ] , const real_T table [ ] , const uint32_T
stride [ ] ) { real_T yL_2d ; uint32_T offset_2d ; real_T yL_1d ; uint32_T
offset_0d ; offset_2d = ( ( uint32_T ) ( bpIndex [ 2U ] * ( int32_T ) stride
[ 2U ] ) + bpIndex [ 1U ] * ( int32_T ) stride [ 1U ] ) + bpIndex [ 0U ] ;
yL_1d = ( table [ offset_2d + 1U ] - table [ offset_2d ] ) * frac [ 0U ] +
table [ offset_2d ] ; offset_0d = offset_2d + stride [ 1U ] ; yL_2d = ( ( (
table [ offset_0d + 1U ] - table [ offset_0d ] ) * frac [ 0U ] + table [
offset_0d ] ) - yL_1d ) * frac [ 1U ] + yL_1d ; offset_2d += stride [ 2U ] ;
yL_1d = ( table [ offset_2d + 1U ] - table [ offset_2d ] ) * frac [ 0U ] +
table [ offset_2d ] ; offset_0d = offset_2d + stride [ 1U ] ; return ( ( ( (
( table [ offset_0d + 1U ] - table [ offset_0d ] ) * frac [ 0U ] + table [
offset_0d ] ) - yL_1d ) * frac [ 1U ] + yL_1d ) - yL_2d ) * frac [ 2U ] +
yL_2d ; } real_T intrp4d_s32dl_pw ( const int32_T bpIndex [ ] , const real_T
frac [ ] , const real_T table [ ] , const uint32_T stride [ ] ) { real_T
yL_3d ; uint32_T offset_3d ; real_T yL_2d ; real_T yL_1d ; uint32_T offset_0d
; uint32_T offset_1d ; offset_3d = ( ( ( uint32_T ) ( bpIndex [ 3U ] * (
int32_T ) stride [ 3U ] ) + bpIndex [ 2U ] * ( int32_T ) stride [ 2U ] ) +
bpIndex [ 1U ] * ( int32_T ) stride [ 1U ] ) + bpIndex [ 0U ] ; yL_1d = (
table [ offset_3d + 1U ] - table [ offset_3d ] ) * frac [ 0U ] + table [
offset_3d ] ; offset_0d = offset_3d + stride [ 1U ] ; yL_2d = ( ( ( table [
offset_0d + 1U ] - table [ offset_0d ] ) * frac [ 0U ] + table [ offset_0d ]
) - yL_1d ) * frac [ 1U ] + yL_1d ; offset_1d = offset_3d + stride [ 2U ] ;
yL_1d = ( table [ offset_1d + 1U ] - table [ offset_1d ] ) * frac [ 0U ] +
table [ offset_1d ] ; offset_0d = offset_1d + stride [ 1U ] ; yL_3d = ( ( ( (
( table [ offset_0d + 1U ] - table [ offset_0d ] ) * frac [ 0U ] + table [
offset_0d ] ) - yL_1d ) * frac [ 1U ] + yL_1d ) - yL_2d ) * frac [ 2U ] +
yL_2d ; offset_1d = offset_3d + stride [ 3U ] ; yL_1d = ( table [ offset_1d +
1U ] - table [ offset_1d ] ) * frac [ 0U ] + table [ offset_1d ] ; offset_0d
= offset_1d + stride [ 1U ] ; yL_2d = ( ( ( table [ offset_0d + 1U ] - table
[ offset_0d ] ) * frac [ 0U ] + table [ offset_0d ] ) - yL_1d ) * frac [ 1U ]
+ yL_1d ; offset_1d += stride [ 2U ] ; yL_1d = ( table [ offset_1d + 1U ] -
table [ offset_1d ] ) * frac [ 0U ] + table [ offset_1d ] ; offset_0d =
offset_1d + stride [ 1U ] ; return ( ( ( ( ( ( ( table [ offset_0d + 1U ] -
table [ offset_0d ] ) * frac [ 0U ] + table [ offset_0d ] ) - yL_1d ) * frac
[ 1U ] + yL_1d ) - yL_2d ) * frac [ 2U ] + yL_2d ) - yL_3d ) * frac [ 3U ] +
yL_3d ; } int32_T binsearch_s32d_prevIdx ( real_T u , const real_T bp [ ] ,
uint32_T startIndex , uint32_T maxIndex ) { uint32_T iRght ; uint32_T iLeft ;
uint32_T bpIdx ; uint32_T found ; bpIdx = startIndex ; iLeft = 0U ; iRght =
maxIndex ; found = 0U ; while ( found == 0U ) { if ( u < bp [ bpIdx ] ) {
iRght = bpIdx - 1U ; bpIdx = ( iRght + iLeft ) >> 1U ; } else if ( u < bp [
bpIdx + 1U ] ) { found = 1U ; } else { iLeft = bpIdx + 1U ; bpIdx = ( iRght +
iLeft ) >> 1U ; } } return ( int32_T ) bpIdx ; } void MdlInitialize ( void )
{ rtDW . lshsqezqdg = ( rtInf ) ; rtDW . noao4ocazt = ( rtInf ) ; rtDW .
ou0twhytn5 = ( rtInf ) ; rtDW . hgbmrfgo34 = ( rtInf ) ; } void MdlStart (
void ) { { void * * pOSigstreamManagerAddr = rt_GetOSigstreamManagerAddr ( )
; const char * errorCreatingOSigstreamManager =
rtwOSigstreamManagerCreateInstance ( rt_GetMatSigLogSelectorFileName ( ) ,
pOSigstreamManagerAddr ) ; if ( errorCreatingOSigstreamManager != ( NULL ) )
{ * pOSigstreamManagerAddr = ( NULL ) ; ssSetErrorStatus ( rtS ,
errorCreatingOSigstreamManager ) ; return ; } } { FWksInfo * fromwksInfo ; if
( ( fromwksInfo = ( FWksInfo * ) calloc ( 1 , sizeof ( FWksInfo ) ) ) == (
NULL ) ) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName = "tuvar" ; fromwksInfo -> origDataTypeId
= 0 ; fromwksInfo -> origIsComplex = 0 ; fromwksInfo -> origWidth = 1 ;
fromwksInfo -> origElSize = sizeof ( real_T ) ; fromwksInfo -> data = ( void
* ) rtP . FromWs_Data0 ; fromwksInfo -> nDataPoints = 6 ; fromwksInfo -> time
= ( double * ) rtP . FromWs_Time0 ; rtDW . l43hqho0yh . TimePtr = fromwksInfo
-> time ; rtDW . l43hqho0yh . DataPtr = fromwksInfo -> data ; rtDW .
l43hqho0yh . RSimInfoPtr = fromwksInfo ; } rtDW . cffy3oatmx . PrevIndex = 0
; } { int_T dimensions [ 2 ] = { 6 , 1 } ; rtDW . kr5bwg1sps . LoggedData =
rt_CreateLogVar ( ssGetRTWLogInfo ( rtS ) , ssGetTStart ( rtS ) , ssGetTFinal
( rtS ) , 0.0 , ( & ssGetErrorStatus ( rtS ) ) , "y" , SS_DOUBLE , 0 , 0 , 0
, 6 , 2 , dimensions , NO_LOGVALDIMS , ( NULL ) , ( NULL ) , 0 , 1 , 0.1 , 1
) ; if ( rtDW . kr5bwg1sps . LoggedData == ( NULL ) ) return ; }
MdlInitialize ( ) ; { bool externalInputIsInDatasetFormat = false ; void *
pISigstreamManager = rt_GetISigstreamManager ( ) ;
rtwISigstreamManagerGetInputIsInDatasetFormat ( pISigstreamManager , &
externalInputIsInDatasetFormat ) ; if ( externalInputIsInDatasetFormat ) { }
} } void MdlOutputs ( int_T tid ) { real_T ds3ggkdp1h ; real_T * lastU ;
real_T lvyyjswlr1 ; real_T gafwq3v551 [ 3 ] ; real_T apo3hxmmry [ 3 ] ;
int32_T i ; real_T ekgfbdlmsd_idx_1 ; real_T ekgfbdlmsd_idx_3 ; real_T
ekgfbdlmsd_idx_4 ; if ( ( rtDW . lshsqezqdg >= ssGetT ( rtS ) ) && ( rtDW .
noao4ocazt >= ssGetT ( rtS ) ) ) { lvyyjswlr1 = 0.0 ; } else { lvyyjswlr1 =
rtDW . lshsqezqdg ; lastU = & rtDW . glhg1qagai ; if ( rtDW . lshsqezqdg <
rtDW . noao4ocazt ) { if ( rtDW . noao4ocazt < ssGetT ( rtS ) ) { lvyyjswlr1
= rtDW . noao4ocazt ; lastU = & rtDW . davtpmukf5 ; } } else { if ( rtDW .
lshsqezqdg >= ssGetT ( rtS ) ) { lvyyjswlr1 = rtDW . noao4ocazt ; lastU = &
rtDW . davtpmukf5 ; } } lvyyjswlr1 = ( rtB . nhxk0ib0lj - * lastU ) / (
ssGetT ( rtS ) - lvyyjswlr1 ) ; } if ( lvyyjswlr1 > rtP .
BetaSaturation1_UpperSat ) { rtB . ookv2bvvls = rtP .
BetaSaturation1_UpperSat ; } else if ( lvyyjswlr1 < rtP .
BetaSaturation1_LowerSat ) { rtB . ookv2bvvls = rtP .
BetaSaturation1_LowerSat ; } else { rtB . ookv2bvvls = lvyyjswlr1 ; }
lvyyjswlr1 = rtB . f2a4bnffor + rtP . u [ 3 ] ; ekgfbdlmsd_idx_4 = - rtB .
ookv2bvvls + rtP . u [ 4 ] ; ekgfbdlmsd_idx_3 = rtB . phcwtlgyip + rtP . u [
5 ] ; for ( i = 0 ; i < 3 ; i ++ ) { gafwq3v551 [ i ] = rtB . hbts5j1pqq [ i
+ 6 ] * ekgfbdlmsd_idx_3 + ( rtB . hbts5j1pqq [ i + 3 ] * ekgfbdlmsd_idx_4 +
rtB . hbts5j1pqq [ i ] * lvyyjswlr1 ) ; } ekgfbdlmsd_idx_1 = rtB . mml2ndjd5d
* gafwq3v551 [ 0 ] * rtP . Gain1_Gain [ 1 ] / rtP . u_Value_agropua0cl / rtB
. lanxaiurnw ; ekgfbdlmsd_idx_3 = ( ( rtB . mxt20vlpck * gafwq3v551 [ 0 ] +
rtB . ianx2c50xl * gafwq3v551 [ 1 ] ) + rtB . n3teuvsdd5 * gafwq3v551 [ 2 ] )
* rtP . Gain1_Gain [ 3 ] / rtP . u_Value_agropua0cl / rtB . lanxaiurnw ;
ekgfbdlmsd_idx_4 = ( rtB . kacxif5qn0 * gafwq3v551 [ 1 ] + rtB . oxq5mf1mg3 *
rtB . ookv2bvvls ) * rtP . Gain1_Gain [ 4 ] / rtP . u_Value_agropua0cl / rtB
. lanxaiurnw ; lvyyjswlr1 = ( rtB . iayveggtaq * gafwq3v551 [ 0 ] + rtB .
il1zzs3oim * gafwq3v551 [ 2 ] ) * rtP . Gain1_Gain [ 5 ] / rtP .
u_Value_agropua0cl / rtB . lanxaiurnw ; gafwq3v551 [ 0 ] = rtP . Gain1_Gain [
0 ] * rtP . zero_Value / rtP . u_Value_agropua0cl / rtB . lanxaiurnw * rtP .
coefAdjust_Gain_blqcdygkok [ 0 ] * rtB . idhxicsqcr ; gafwq3v551 [ 1 ] = rtP
. coefAdjust_Gain_blqcdygkok [ 1 ] * ekgfbdlmsd_idx_1 * rtB . idhxicsqcr ;
gafwq3v551 [ 2 ] = rtB . bbuiyhe1o5 * rtB . ookv2bvvls * rtP . Gain1_Gain [ 2
] / rtP . u_Value_agropua0cl / rtB . lanxaiurnw * rtP .
coefAdjust_Gain_blqcdygkok [ 2 ] * rtB . idhxicsqcr ; for ( i = 0 ; i < 3 ; i
++ ) { apo3hxmmry [ i ] = ( ( ( rtB . fsutp3ayo3 [ i + 3 ] * gafwq3v551 [ 1 ]
+ rtB . fsutp3ayo3 [ i ] * gafwq3v551 [ 0 ] ) + rtB . fsutp3ayo3 [ i + 6 ] *
gafwq3v551 [ 2 ] ) + rtB . hxsqezn2an [ i ] ) + rtB . pw5gjuojru [ i ] ; } {
real_T * pDataValues = ( real_T * ) rtDW . l43hqho0yh . DataPtr ; real_T *
pTimeValues = ( real_T * ) rtDW . l43hqho0yh . TimePtr ; int_T currTimeIndex
= rtDW . cffy3oatmx . PrevIndex ; real_T t = ssGetTaskTime ( rtS , 0 ) ; int
numPoints , lastPoint ; FWksInfo * fromwksInfo = ( FWksInfo * ) rtDW .
l43hqho0yh . RSimInfoPtr ; numPoints = fromwksInfo -> nDataPoints ; lastPoint
= numPoints - 1 ; if ( t <= pTimeValues [ 0 ] ) { currTimeIndex = 0 ; } else
if ( t >= pTimeValues [ lastPoint ] ) { currTimeIndex = lastPoint - 1 ; }
else { if ( t < pTimeValues [ currTimeIndex ] ) { while ( t < pTimeValues [
currTimeIndex ] ) { currTimeIndex -- ; } } else { while ( t >= pTimeValues [
currTimeIndex + 1 ] ) { currTimeIndex ++ ; } } } rtDW . cffy3oatmx .
PrevIndex = currTimeIndex ; { real_T t1 = pTimeValues [ currTimeIndex ] ;
real_T t2 = pTimeValues [ currTimeIndex + 1 ] ; if ( t1 == t2 ) { if ( t < t1
) { ds3ggkdp1h = pDataValues [ currTimeIndex ] ; } else { ds3ggkdp1h =
pDataValues [ currTimeIndex + 1 ] ; } } else { real_T f1 = ( t2 - t ) / ( t2
- t1 ) ; real_T f2 = 1.0 - f1 ; real_T d1 ; real_T d2 ; int_T TimeIndex =
currTimeIndex ; d1 = pDataValues [ TimeIndex ] ; d2 = pDataValues [ TimeIndex
+ 1 ] ; ds3ggkdp1h = ( real_T ) rtInterpolate ( d1 , d2 , f1 , f2 ) ;
pDataValues += numPoints ; } } } if ( rtP . ManualSwitch_CurrentSetting == 1
) { ekgfbdlmsd_idx_1 = ds3ggkdp1h ; } else { ekgfbdlmsd_idx_1 = rtP .
TrimThrust4_Value ; } rtB . jwtgtch3mu [ 0 ] = ( apo3hxmmry [ 0 ] + rtB .
n2spnyfef4 ) + rtB . igwvaibikt [ 0 ] * ekgfbdlmsd_idx_1 ; rtB . jwtgtch3mu [
1 ] = ( apo3hxmmry [ 1 ] + rtB . ab5d34lf4o ) + rtB . igwvaibikt [ 1 ] *
ekgfbdlmsd_idx_1 ; rtB . jwtgtch3mu [ 2 ] = ( apo3hxmmry [ 2 ] + rtB .
jjpibu4asu ) + rtB . igwvaibikt [ 2 ] * ekgfbdlmsd_idx_1 ; ekgfbdlmsd_idx_3 =
( gafwq3v551 [ 1 ] * rtB . dp5pi2avlk [ 2 ] - gafwq3v551 [ 2 ] * rtB .
dp5pi2avlk [ 1 ] ) + ekgfbdlmsd_idx_3 * rtB . ilvgb1vukq [ 0 ] ;
ekgfbdlmsd_idx_4 = ( gafwq3v551 [ 2 ] * rtB . dp5pi2avlk [ 0 ] - gafwq3v551 [
0 ] * rtB . dp5pi2avlk [ 2 ] ) + ekgfbdlmsd_idx_4 * rtB . ilvgb1vukq [ 1 ] ;
lvyyjswlr1 = ( gafwq3v551 [ 0 ] * rtB . dp5pi2avlk [ 1 ] - gafwq3v551 [ 1 ] *
rtB . dp5pi2avlk [ 0 ] ) + lvyyjswlr1 * rtB . ilvgb1vukq [ 2 ] ; for ( i = 0
; i < 3 ; i ++ ) { rtB . pg2hzggfwd [ i ] = ( ( ( ( ( rtB . bdzrxsq0jb [ i +
3 ] * ekgfbdlmsd_idx_4 + rtB . bdzrxsq0jb [ i ] * ekgfbdlmsd_idx_3 ) + rtB .
bdzrxsq0jb [ i + 6 ] * lvyyjswlr1 ) + rtB . kies3oo3id [ i ] ) + rtB .
m1nsvprq1z [ i ] ) + rtP . WeightMoment_Value [ i ] ) + rtP .
TrimThrust5_Value [ i ] ; rtB . lzr1wnncjo [ i ] = rtB . jwtgtch3mu [ i ] ;
rtB . lzr1wnncjo [ i + 3 ] = rtB . pg2hzggfwd [ i ] ; } if ( ssGetLogOutput (
rtS ) ) { { double locTime = ssGetTaskTime ( rtS , 1 ) ; ; if (
rtwTimeInLoggingInterval ( rtliGetLoggingInterval ( ssGetRootSS ( rtS ) ->
mdlInfo -> rtwLogInfo ) , locTime ) ) { rt_UpdateLogVar ( ( LogVar * ) (
LogVar * ) ( rtDW . kr5bwg1sps . LoggedData ) , & rtB . lzr1wnncjo [ 0 ] , 0
) ; } } } if ( ( rtDW . ou0twhytn5 >= ssGetT ( rtS ) ) && ( rtDW . hgbmrfgo34
>= ssGetT ( rtS ) ) ) { rtB . jvmj3dgdoq = 0.0 ; } else { lvyyjswlr1 = rtDW .
ou0twhytn5 ; lastU = & rtDW . iub22gul40 ; if ( rtDW . ou0twhytn5 < rtDW .
hgbmrfgo34 ) { if ( rtDW . hgbmrfgo34 < ssGetT ( rtS ) ) { lvyyjswlr1 = rtDW
. hgbmrfgo34 ; lastU = & rtDW . bdnvmlo1qe ; } } else { if ( rtDW .
ou0twhytn5 >= ssGetT ( rtS ) ) { lvyyjswlr1 = rtDW . hgbmrfgo34 ; lastU = &
rtDW . bdnvmlo1qe ; } } rtB . jvmj3dgdoq = ( rtB . jf5nt45ccr - * lastU ) / (
ssGetT ( rtS ) - lvyyjswlr1 ) ; } UNUSED_PARAMETER ( tid ) ; } void
MdlOutputsTID2 ( int_T tid ) { real_T kswxbn4zh3 ; real_T anego2jgcz ;
int32_T hmvrnu2ba1 ; real_T gv4idl0wui ; int32_T nl5ggx5dex ; real_T
le0egpvzyq ; int32_T cydulixisl ; real_T fszxvc31p3 ; real_T bkx0y4tsw1 ;
real_T au4h5lcbek ; real_T k3pv4ckac2 ; real_T cfl1pts4xh ; real_T or5cpd2orf
[ 9 ] ; real_T cyn1gfolyx ; real_T cndhwyxedo ; real_T nwi2cgk4yo [ 3 ] ;
real_T eveu35hvyy [ 9 ] ; real_T oh3kzqorel [ 9 ] ; real_T gmajytn1hv [ 9 ] ;
real_T igpg4wawt5 [ 9 ] ; real_T cduwu2tvxq [ 9 ] ; real_T gcextsrvtd [ 9 ] ;
real_T olbxomfkfq [ 9 ] ; real_T cgh3d1u4d2 [ 9 ] ; real_T frac [ 3 ] ;
int32_T bpIndex [ 3 ] ; real_T frac_p [ 3 ] ; int32_T bpIndex_p [ 3 ] ;
real_T frac_e [ 3 ] ; int32_T bpIndex_e [ 3 ] ; real_T frac_i [ 3 ] ; int32_T
bpIndex_i [ 3 ] ; real_T frac_m [ 3 ] ; int32_T bpIndex_m [ 3 ] ; real_T
frac_g [ 3 ] ; int32_T bpIndex_g [ 3 ] ; real_T frac_j [ 3 ] ; int32_T
bpIndex_j [ 3 ] ; real_T frac_f [ 3 ] ; int32_T bpIndex_f [ 3 ] ; real_T
frac_c [ 3 ] ; int32_T bpIndex_c [ 3 ] ; real_T frac_k [ 4 ] ; int32_T
bpIndex_k [ 4 ] ; real_T frac_b [ 4 ] ; int32_T bpIndex_b [ 4 ] ; real_T
frac_n [ 4 ] ; int32_T bpIndex_n [ 4 ] ; real_T frac_l [ 4 ] ; int32_T
bpIndex_l [ 4 ] ; real_T frac_d [ 4 ] ; int32_T bpIndex_d [ 4 ] ; real_T
f4djcyowey ; real_T frac_o [ 4 ] ; int32_T bpIndex_o [ 4 ] ; real_T frac_dz [
4 ] ; int32_T bpIndex_dz [ 4 ] ; real_T ll2axnx4w0 ; real_T frac_fs [ 4 ] ;
int32_T bpIndex_fs [ 4 ] ; real_T frac_ck [ 3 ] ; int32_T bpIndex_ck [ 3 ] ;
int32_T bpIndex_idx_0 ; int32_T bpIndex_idx_1 ; int32_T bpIndex_idx_2 ;
int32_T bpIndex_idx_0_p ; int32_T bpIndex_idx_1_p ; int32_T bpIndex_idx_2_p ;
int32_T bpIndex_idx_0_e ; int32_T bpIndex_idx_1_e ; int32_T bpIndex_idx_2_e ;
real_T kxuzc0nr10_idx_4 ; real_T fpx55updk4_idx_0 ; real_T fpx55updk4_idx_1 ;
real_T mhgelec5v1_idx_1 ; real_T mhgelec5v1_idx_0 ; real_T tmp ; real_T tmp_p
; real_T frac_idx_1 ; muDoubleScalarSinCos ( muDoubleScalarAtan2 ( rtP . u [
2 ] , rtP . u [ 0 ] ) , & kswxbn4zh3 , & anego2jgcz ) ; or5cpd2orf [ 0 ] =
anego2jgcz ; or5cpd2orf [ 1 ] = rtP . Constant1_Value ; or5cpd2orf [ 2 ] = -
kswxbn4zh3 ; or5cpd2orf [ 3 ] = rtP . Constant_Value ; or5cpd2orf [ 4 ] = rtP
. Constant2_Value ; or5cpd2orf [ 5 ] = rtP . Constant4_Value ; or5cpd2orf [ 6
] = kswxbn4zh3 ; or5cpd2orf [ 7 ] = rtP . Constant3_Value ; or5cpd2orf [ 8 ]
= anego2jgcz ; if ( rtP . u [ 12 ] > rtP . Limitaltitudetotroposhere_UpperSat
) { cyn1gfolyx = rtP . Limitaltitudetotroposhere_UpperSat ; } else if ( rtP .
u [ 12 ] < rtP . Limitaltitudetotroposhere_LowerSat ) { cyn1gfolyx = rtP .
Limitaltitudetotroposhere_LowerSat ; } else { cyn1gfolyx = rtP . u [ 12 ] ; }
cyn1gfolyx = rtP . SeaLevelTemperature_Value - rtP . LapseRate_Gain *
cyn1gfolyx ; kswxbn4zh3 = rtP . uT0_Gain * cyn1gfolyx ; cndhwyxedo = rtP .
AltitudeofTroposphere_Value - rtP . u [ 12 ] ; if ( ( kswxbn4zh3 < 0.0 ) && (
rtP . gLR_Value > muDoubleScalarFloor ( rtP . gLR_Value ) ) ) { anego2jgcz =
- muDoubleScalarPower ( - kswxbn4zh3 , rtP . gLR_Value ) ; } else {
anego2jgcz = muDoubleScalarPower ( kswxbn4zh3 , rtP . gLR_Value ) ; } if (
cndhwyxedo > rtP . LimitaltitudetoStratosphere_UpperSat ) { cndhwyxedo = rtP
. LimitaltitudetoStratosphere_UpperSat ; } else { if ( cndhwyxedo < rtP .
LimitaltitudetoStratosphere_LowerSat ) { cndhwyxedo = rtP .
LimitaltitudetoStratosphere_LowerSat ; } } anego2jgcz = anego2jgcz /
kswxbn4zh3 * rtP . rho0_Gain * muDoubleScalarExp ( 1.0 / cyn1gfolyx * ( rtP .
gR_Gain * cndhwyxedo ) ) * rtP . Gain_Gain * muDoubleScalarAbs ( ( rtP . u [
0 ] * rtP . u [ 0 ] + rtP . u [ 1 ] * rtP . u [ 1 ] ) + rtP . u [ 2 ] * rtP .
u [ 2 ] ) ; kswxbn4zh3 = anego2jgcz * rtP . Constant_Value_cddtuuqxak ; rtB .
nhxk0ib0lj = muDoubleScalarAtan ( 1.0 / rtP . u [ 0 ] * rtP . u [ 2 ] ) ;
hmvrnu2ba1 = plook_s32dd_bincp ( rtB . nhxk0ib0lj , rtP .
alpha_BreakpointsData , 8U , & gv4idl0wui , & rtDW . eavb5jrhyr ) ;
cndhwyxedo = muDoubleScalarSqrt ( ( rtP . u [ 0 ] * rtP . u [ 0 ] + rtP . u [
1 ] * rtP . u [ 1 ] ) + rtP . u [ 2 ] * rtP . u [ 2 ] ) ; nl5ggx5dex =
plook_s32dd_bincp ( cndhwyxedo / muDoubleScalarSqrt ( rtP . gammaR_Gain *
cyn1gfolyx ) , rtP . Mach_BreakpointsData , 1U , & le0egpvzyq , & rtDW .
hod3grnuyb ) ; cydulixisl = plook_s32dd_bincp ( rtP . u [ 12 ] , rtP .
altitude_BreakpointsData , 2U , & fszxvc31p3 , & rtDW . m54rowgddh ) ;
bpIndex_idx_0 = hmvrnu2ba1 ; bpIndex_idx_1 = nl5ggx5dex ; bpIndex_idx_2 =
cydulixisl ; if ( ( ( uint32_T ) hmvrnu2ba1 == 7U ) && ( gv4idl0wui >= 1.0 )
) { bpIndex_idx_0 = hmvrnu2ba1 + 1 ; } if ( ( ( uint32_T ) nl5ggx5dex == 0U )
&& ( le0egpvzyq >= 1.0 ) ) { bpIndex_idx_1 = nl5ggx5dex + 1 ; } if ( ( (
uint32_T ) cydulixisl == 1U ) && ( fszxvc31p3 >= 1.0 ) ) { bpIndex_idx_2 =
cydulixisl + 1 ; } bpIndex_idx_0_p = hmvrnu2ba1 ; bpIndex_idx_1_p =
nl5ggx5dex ; bpIndex_idx_2_p = cydulixisl ; if ( ( ( uint32_T ) hmvrnu2ba1 ==
7U ) && ( gv4idl0wui >= 1.0 ) ) { bpIndex_idx_0_p = hmvrnu2ba1 + 1 ; } if ( (
( uint32_T ) nl5ggx5dex == 0U ) && ( le0egpvzyq >= 1.0 ) ) { bpIndex_idx_1_p
= nl5ggx5dex + 1 ; } if ( ( ( uint32_T ) cydulixisl == 1U ) && ( fszxvc31p3
>= 1.0 ) ) { bpIndex_idx_2_p = cydulixisl + 1 ; } cndhwyxedo = rtP . u [ 1 ]
/ cndhwyxedo ; if ( cndhwyxedo > 1.0 ) { cndhwyxedo = 1.0 ; } else { if (
cndhwyxedo < - 1.0 ) { cndhwyxedo = - 1.0 ; } } rtB . jf5nt45ccr =
muDoubleScalarAsin ( cndhwyxedo ) ; if ( rtB . jf5nt45ccr > rtP .
BetaSaturation_UpperSat ) { rtB . hzbuxpmezj = rtP . BetaSaturation_UpperSat
; } else if ( rtB . jf5nt45ccr < rtP . BetaSaturation_LowerSat ) { rtB .
hzbuxpmezj = rtP . BetaSaturation_LowerSat ; } else { rtB . hzbuxpmezj = rtB
. jf5nt45ccr ; } bpIndex_idx_0_e = hmvrnu2ba1 ; bpIndex_idx_1_e = nl5ggx5dex
; bpIndex_idx_2_e = cydulixisl ; if ( ( ( uint32_T ) hmvrnu2ba1 == 7U ) && (
gv4idl0wui >= 1.0 ) ) { bpIndex_idx_0_e = hmvrnu2ba1 + 1 ; } if ( ( (
uint32_T ) nl5ggx5dex == 0U ) && ( le0egpvzyq >= 1.0 ) ) { bpIndex_idx_1_e =
nl5ggx5dex + 1 ; } if ( ( ( uint32_T ) cydulixisl == 1U ) && ( fszxvc31p3 >=
1.0 ) ) { bpIndex_idx_2_e = cydulixisl + 1 ; } nwi2cgk4yo [ 0 ] = rtP .
CD_Table [ ( ( uint32_T ) ( bpIndex_idx_1 * 9 ) + bpIndex_idx_0 ) +
bpIndex_idx_2 * 18 ] * rtP . coefAdjust_Gain [ 0 ] * kswxbn4zh3 ; nwi2cgk4yo
[ 1 ] = rtP . CYb_Table [ ( ( uint32_T ) ( bpIndex_idx_1_p * 9 ) +
bpIndex_idx_0_p ) + bpIndex_idx_2_p * 18 ] * rtB . hzbuxpmezj * rtP .
coefAdjust_Gain [ 1 ] * kswxbn4zh3 ; nwi2cgk4yo [ 2 ] = rtP . CL_Table [ ( (
uint32_T ) ( bpIndex_idx_1_e * 9 ) + bpIndex_idx_0_e ) + bpIndex_idx_2_e * 18
] * rtP . coefAdjust_Gain [ 2 ] * kswxbn4zh3 ; for ( bpIndex_idx_0 = 0 ;
bpIndex_idx_0 < 3 ; bpIndex_idx_0 ++ ) { rtB . pw5gjuojru [ bpIndex_idx_0 ] =
0.0 ; rtB . pw5gjuojru [ bpIndex_idx_0 ] += or5cpd2orf [ 3 * bpIndex_idx_0 ]
* nwi2cgk4yo [ 0 ] ; rtB . pw5gjuojru [ bpIndex_idx_0 ] += or5cpd2orf [ 3 *
bpIndex_idx_0 + 1 ] * nwi2cgk4yo [ 1 ] ; rtB . pw5gjuojru [ bpIndex_idx_0 ]
+= or5cpd2orf [ 3 * bpIndex_idx_0 + 2 ] * nwi2cgk4yo [ 2 ] ; }
muDoubleScalarSinCos ( muDoubleScalarAtan2 ( rtP . u [ 2 ] , rtP . u [ 0 ] )
, & cyn1gfolyx , & cndhwyxedo ) ; eveu35hvyy [ 0 ] = cndhwyxedo ; eveu35hvyy
[ 1 ] = rtP . Constant1_Value_n0vvf1ru2i ; eveu35hvyy [ 2 ] = - cyn1gfolyx ;
eveu35hvyy [ 3 ] = rtP . Constant_Value_gzdzpzihxe ; eveu35hvyy [ 4 ] = rtP .
Constant2_Value_eqjwl24tzr ; eveu35hvyy [ 5 ] = rtP .
Constant4_Value_bijw4dwdaf ; eveu35hvyy [ 6 ] = cyn1gfolyx ; eveu35hvyy [ 7 ]
= rtP . Constant3_Value_emiujykzul ; eveu35hvyy [ 8 ] = cndhwyxedo ; for (
bpIndex_idx_0 = 0 ; bpIndex_idx_0 < 3 ; bpIndex_idx_0 ++ ) { rtB . fsutp3ayo3
[ 3 * bpIndex_idx_0 ] = eveu35hvyy [ bpIndex_idx_0 ] ; rtB . fsutp3ayo3 [ 1 +
3 * bpIndex_idx_0 ] = eveu35hvyy [ bpIndex_idx_0 + 3 ] ; rtB . fsutp3ayo3 [ 2
+ 3 * bpIndex_idx_0 ] = eveu35hvyy [ bpIndex_idx_0 + 6 ] ; } rtB . idhxicsqcr
= anego2jgcz * rtP . Constant6_Value ; frac [ 0 ] = gv4idl0wui ; frac [ 1 ] =
le0egpvzyq ; frac [ 2 ] = fszxvc31p3 ; bpIndex [ 0 ] = hmvrnu2ba1 ; bpIndex [
1 ] = nl5ggx5dex ; bpIndex [ 2 ] = cydulixisl ; rtB . mml2ndjd5d =
intrp3d_s32dl_pw ( bpIndex , frac , rtP . CYp1_Table , rtP . CYp1_dimSize ) ;
cyn1gfolyx = muDoubleScalarAtan2 ( rtP . u [ 2 ] , rtP . u [ 0 ] ) ;
cndhwyxedo = rtP . u_Value ; muDoubleScalarSinCos ( cyn1gfolyx , &
mhgelec5v1_idx_0 , & fpx55updk4_idx_0 ) ; muDoubleScalarSinCos ( cndhwyxedo ,
& mhgelec5v1_idx_1 , & fpx55updk4_idx_1 ) ; rtB . hbts5j1pqq [ 0 ] =
fpx55updk4_idx_0 * fpx55updk4_idx_1 ; rtB . hbts5j1pqq [ 1 ] = - (
mhgelec5v1_idx_1 * fpx55updk4_idx_0 ) ; rtB . hbts5j1pqq [ 2 ] = -
mhgelec5v1_idx_0 ; rtB . hbts5j1pqq [ 3 ] = mhgelec5v1_idx_1 ; rtB .
hbts5j1pqq [ 4 ] = fpx55updk4_idx_1 ; rtB . hbts5j1pqq [ 5 ] = rtP .
Constant_Value_fhedlbhuxr ; rtB . hbts5j1pqq [ 6 ] = mhgelec5v1_idx_0 *
fpx55updk4_idx_1 ; rtB . hbts5j1pqq [ 7 ] = - ( mhgelec5v1_idx_0 *
mhgelec5v1_idx_1 ) ; rtB . hbts5j1pqq [ 8 ] = fpx55updk4_idx_0 ;
muDoubleScalarSinCos ( cyn1gfolyx , & cndhwyxedo , & bkx0y4tsw1 ) ; rtB .
f2a4bnffor = - ( rtP . u_Value_jauwwxrr5h * cndhwyxedo ) ; rtB . phcwtlgyip =
rtP . u_Value_jauwwxrr5h * bkx0y4tsw1 ; frac_p [ 0 ] = gv4idl0wui ; frac_p [
1 ] = le0egpvzyq ; frac_p [ 2 ] = fszxvc31p3 ; bpIndex_p [ 0 ] = hmvrnu2ba1 ;
bpIndex_p [ 1 ] = nl5ggx5dex ; bpIndex_p [ 2 ] = cydulixisl ; rtB .
bbuiyhe1o5 = intrp3d_s32dl_pw ( bpIndex_p , frac_p , rtP . CLad1_Table , rtP
. CLad1_dimSize ) ; frac_e [ 0 ] = gv4idl0wui ; frac_e [ 1 ] = le0egpvzyq ;
frac_e [ 2 ] = fszxvc31p3 ; bpIndex_e [ 0 ] = hmvrnu2ba1 ; bpIndex_e [ 1 ] =
nl5ggx5dex ; bpIndex_e [ 2 ] = cydulixisl ; rtB . mxt20vlpck =
intrp3d_s32dl_pw ( bpIndex_e , frac_e , rtP . Clp1_Table , rtP . Clp1_dimSize
) ; frac_i [ 0 ] = gv4idl0wui ; frac_i [ 1 ] = le0egpvzyq ; frac_i [ 2 ] =
fszxvc31p3 ; bpIndex_i [ 0 ] = hmvrnu2ba1 ; bpIndex_i [ 1 ] = nl5ggx5dex ;
bpIndex_i [ 2 ] = cydulixisl ; rtB . ianx2c50xl = intrp3d_s32dl_pw (
bpIndex_i , frac_i , rtP . Clq1_Table , rtP . Clq1_dimSize ) ; frac_m [ 0 ] =
gv4idl0wui ; frac_m [ 1 ] = le0egpvzyq ; frac_m [ 2 ] = fszxvc31p3 ;
bpIndex_m [ 0 ] = hmvrnu2ba1 ; bpIndex_m [ 1 ] = nl5ggx5dex ; bpIndex_m [ 2 ]
= cydulixisl ; rtB . n3teuvsdd5 = intrp3d_s32dl_pw ( bpIndex_m , frac_m , rtP
. Clr1_Table , rtP . Clr1_dimSize ) ; frac_g [ 0 ] = gv4idl0wui ; frac_g [ 1
] = le0egpvzyq ; frac_g [ 2 ] = fszxvc31p3 ; bpIndex_g [ 0 ] = hmvrnu2ba1 ;
bpIndex_g [ 1 ] = nl5ggx5dex ; bpIndex_g [ 2 ] = cydulixisl ; rtB .
kacxif5qn0 = intrp3d_s32dl_pw ( bpIndex_g , frac_g , rtP . Cmq1_Table , rtP .
Cmq1_dimSize ) ; frac_j [ 0 ] = gv4idl0wui ; frac_j [ 1 ] = le0egpvzyq ;
frac_j [ 2 ] = fszxvc31p3 ; bpIndex_j [ 0 ] = hmvrnu2ba1 ; bpIndex_j [ 1 ] =
nl5ggx5dex ; bpIndex_j [ 2 ] = cydulixisl ; rtB . oxq5mf1mg3 =
intrp3d_s32dl_pw ( bpIndex_j , frac_j , rtP . Cmad1_Table , rtP .
Cmad1_dimSize ) ; frac_f [ 0 ] = gv4idl0wui ; frac_f [ 1 ] = le0egpvzyq ;
frac_f [ 2 ] = fszxvc31p3 ; bpIndex_f [ 0 ] = hmvrnu2ba1 ; bpIndex_f [ 1 ] =
nl5ggx5dex ; bpIndex_f [ 2 ] = cydulixisl ; rtB . iayveggtaq =
intrp3d_s32dl_pw ( bpIndex_f , frac_f , rtP . Cnp1_Table , rtP . Cnp1_dimSize
) ; frac_c [ 0 ] = gv4idl0wui ; frac_c [ 1 ] = le0egpvzyq ; frac_c [ 2 ] =
fszxvc31p3 ; bpIndex_c [ 0 ] = hmvrnu2ba1 ; bpIndex_c [ 1 ] = nl5ggx5dex ;
bpIndex_c [ 2 ] = cydulixisl ; rtB . il1zzs3oim = intrp3d_s32dl_pw (
bpIndex_c , frac_c , rtP . Cnr1_Table , rtP . Cnr1_dimSize ) ; rtB .
lanxaiurnw = muDoubleScalarSqrt ( ( rtP . u [ 0 ] * rtP . u [ 0 ] + rtP . u [
1 ] * rtP . u [ 1 ] ) + rtP . u [ 2 ] * rtP . u [ 2 ] ) ;
muDoubleScalarSinCos ( muDoubleScalarAtan2 ( rtP . u [ 2 ] , rtP . u [ 0 ] )
, & cyn1gfolyx , & cndhwyxedo ) ; oh3kzqorel [ 0 ] = cndhwyxedo ; oh3kzqorel
[ 1 ] = rtP . Constant1_Value_e4b4arvsx4 ; oh3kzqorel [ 2 ] = - cyn1gfolyx ;
oh3kzqorel [ 3 ] = rtP . Constant_Value_epkxnw5b5k ; oh3kzqorel [ 4 ] = rtP .
Constant2_Value_i0tusarllo ; oh3kzqorel [ 5 ] = rtP .
Constant4_Value_ebczl1p2kp ; oh3kzqorel [ 6 ] = cyn1gfolyx ; oh3kzqorel [ 7 ]
= rtP . Constant3_Value_n2bp44blge ; oh3kzqorel [ 8 ] = cndhwyxedo ;
anego2jgcz *= rtP . Constant1_Value_f1v4g1iait ; bpIndex_idx_0 =
plook_s32dd_bincp ( rtP . u [ 6 ] , rtP . delta_f_BreakpointsData , 8U , &
au4h5lcbek , & rtDW . c3s1ykl5ma ) ; frac_k [ 0 ] = gv4idl0wui ; frac_k [ 1 ]
= le0egpvzyq ; frac_k [ 2 ] = fszxvc31p3 ; frac_k [ 3 ] = au4h5lcbek ;
bpIndex_k [ 0 ] = hmvrnu2ba1 ; bpIndex_k [ 1 ] = nl5ggx5dex ; bpIndex_k [ 2 ]
= cydulixisl ; bpIndex_k [ 3 ] = bpIndex_idx_0 ; cyn1gfolyx =
intrp4d_s32dl_pw ( bpIndex_k , frac_k , rtP . DCDI_Table , rtP . DCDI_dimSize
) ; frac_b [ 0 ] = gv4idl0wui ; frac_b [ 1 ] = le0egpvzyq ; frac_b [ 2 ] =
fszxvc31p3 ; frac_b [ 3 ] = au4h5lcbek ; bpIndex_b [ 0 ] = hmvrnu2ba1 ;
bpIndex_b [ 1 ] = nl5ggx5dex ; bpIndex_b [ 2 ] = cydulixisl ; bpIndex_b [ 3 ]
= bpIndex_idx_0 ; cndhwyxedo = intrp4d_s32dl_pw ( bpIndex_b , frac_b , rtP .
DCL_Table , rtP . DCL_dimSize ) ; frac_n [ 0 ] = gv4idl0wui ; frac_n [ 1 ] =
le0egpvzyq ; frac_n [ 2 ] = fszxvc31p3 ; frac_n [ 3 ] = au4h5lcbek ;
bpIndex_n [ 0 ] = hmvrnu2ba1 ; bpIndex_n [ 1 ] = nl5ggx5dex ; bpIndex_n [ 2 ]
= cydulixisl ; bpIndex_n [ 3 ] = bpIndex_idx_0 ; au4h5lcbek =
intrp4d_s32dl_pw ( bpIndex_n , frac_n , rtP . DCm_Table , rtP . DCm_dimSize )
; bpIndex_idx_0 = plook_s32dd_bincp ( rtP . u [ 7 ] , rtP .
delta_e_BreakpointsData , 8U , & k3pv4ckac2 , & rtDW . htx1g0xx41 ) ; frac_l
[ 0 ] = gv4idl0wui ; frac_l [ 1 ] = le0egpvzyq ; frac_l [ 2 ] = fszxvc31p3 ;
frac_l [ 3 ] = k3pv4ckac2 ; bpIndex_l [ 0 ] = hmvrnu2ba1 ; bpIndex_l [ 1 ] =
nl5ggx5dex ; bpIndex_l [ 2 ] = cydulixisl ; bpIndex_l [ 3 ] = bpIndex_idx_0 ;
bkx0y4tsw1 = intrp4d_s32dl_pw ( bpIndex_l , frac_l , rtP .
DCDI_Table_ectqqf4lpu , rtP . DCDI_dimSize_hvypykhf0h ) ; frac_d [ 0 ] =
gv4idl0wui ; frac_d [ 1 ] = le0egpvzyq ; frac_d [ 2 ] = fszxvc31p3 ; frac_d [
3 ] = k3pv4ckac2 ; bpIndex_d [ 0 ] = hmvrnu2ba1 ; bpIndex_d [ 1 ] =
nl5ggx5dex ; bpIndex_d [ 2 ] = cydulixisl ; bpIndex_d [ 3 ] = bpIndex_idx_0 ;
f4djcyowey = intrp4d_s32dl_pw ( bpIndex_d , frac_d , rtP .
DCL_Table_b2ogh4jov4 , rtP . DCL_dimSize_i0jbywo0xh ) ; frac_o [ 0 ] =
gv4idl0wui ; frac_o [ 1 ] = le0egpvzyq ; frac_o [ 2 ] = fszxvc31p3 ; frac_o [
3 ] = k3pv4ckac2 ; bpIndex_o [ 0 ] = hmvrnu2ba1 ; bpIndex_o [ 1 ] =
nl5ggx5dex ; bpIndex_o [ 2 ] = cydulixisl ; bpIndex_o [ 3 ] = bpIndex_idx_0 ;
k3pv4ckac2 = intrp4d_s32dl_pw ( bpIndex_o , frac_o , rtP .
DCm_Table_jpppnjjyiv , rtP . DCm_dimSize_oju4dybify ) ; bpIndex_idx_0 =
plook_s32dd_bincp ( rtP . u [ 8 ] , rtP . delta_a_BreakpointsData , 8U , &
cfl1pts4xh , & rtDW . mi4wxn4zbd ) ; frac_dz [ 0 ] = gv4idl0wui ; frac_dz [ 1
] = le0egpvzyq ; frac_dz [ 2 ] = fszxvc31p3 ; frac_dz [ 3 ] = cfl1pts4xh ;
bpIndex_dz [ 0 ] = hmvrnu2ba1 ; bpIndex_dz [ 1 ] = nl5ggx5dex ; bpIndex_dz [
2 ] = cydulixisl ; bpIndex_dz [ 3 ] = bpIndex_idx_0 ; ll2axnx4w0 =
intrp4d_s32dl_pw ( bpIndex_dz , frac_dz , rtP . DCl_Table , rtP . DCl_dimSize
) ; frac_fs [ 0 ] = gv4idl0wui ; frac_fs [ 1 ] = le0egpvzyq ; frac_fs [ 2 ] =
fszxvc31p3 ; frac_fs [ 3 ] = cfl1pts4xh ; bpIndex_fs [ 0 ] = hmvrnu2ba1 ;
bpIndex_fs [ 1 ] = nl5ggx5dex ; bpIndex_fs [ 2 ] = cydulixisl ; bpIndex_fs [
3 ] = bpIndex_idx_0 ; cfl1pts4xh = intrp4d_s32dl_pw ( bpIndex_fs , frac_fs ,
rtP . DCn_Table , rtP . DCn_dimSize ) ; ll2axnx4w0 = ( rtP .
Constant2_Value_old3zd5smi + rtP . Constant2_Value_n1gt4skuej ) + rtP .
Gain_Gain_gtonf3ckiq * ll2axnx4w0 ; kxuzc0nr10_idx_4 = ( au4h5lcbek +
k3pv4ckac2 ) + rtP . Gain_Gain_gtonf3ckiq * rtP . Constant4_Value_bxodvzr3wv
; au4h5lcbek = ( rtP . Constant3_Value_nvs1o44prj + rtP .
Constant3_Value_ammrq4bbzx ) + rtP . Gain_Gain_gtonf3ckiq * cfl1pts4xh ; frac
[ 0 ] = ( ( cyn1gfolyx + bkx0y4tsw1 ) + rtP . Gain_Gain_gtonf3ckiq * rtP .
Constant6_Value_o2itzcqfbo ) * rtP . coefAdjust_Gain_jhgwt4xcre [ 0 ] *
anego2jgcz ; frac [ 1 ] = ( ( rtP . Constant1_Value_bhkzpq4cm3 + rtP .
Constant1_Value_dvrrjd2vth ) + rtP . Gain_Gain_gtonf3ckiq * rtP .
Constant1_Value_jj4sc0nzo2 ) * rtP . coefAdjust_Gain_jhgwt4xcre [ 1 ] *
anego2jgcz ; frac [ 2 ] = ( ( cndhwyxedo + f4djcyowey ) + rtP .
Gain_Gain_gtonf3ckiq * rtP . Constant5_Value ) * rtP .
coefAdjust_Gain_jhgwt4xcre [ 2 ] * anego2jgcz ; for ( bpIndex_idx_0 = 0 ;
bpIndex_idx_0 < 3 ; bpIndex_idx_0 ++ ) { rtB . hxsqezn2an [ bpIndex_idx_0 ] =
0.0 ; rtB . hxsqezn2an [ bpIndex_idx_0 ] += oh3kzqorel [ 3 * bpIndex_idx_0 ]
* frac [ 0 ] ; rtB . hxsqezn2an [ bpIndex_idx_0 ] += oh3kzqorel [ 3 *
bpIndex_idx_0 + 1 ] * frac [ 1 ] ; rtB . hxsqezn2an [ bpIndex_idx_0 ] +=
oh3kzqorel [ 3 * bpIndex_idx_0 + 2 ] * frac [ 2 ] ; } rtB . n2spnyfef4 = rtP
. Gain1_Gain_gk1wozgh1p * muDoubleScalarSin ( rtP . u [ 10 ] ) * rtP .
WeightForce_Value ; cfl1pts4xh = muDoubleScalarCos ( rtP . u [ 10 ] ) ; rtB .
ab5d34lf4o = muDoubleScalarSin ( rtP . u [ 9 ] ) * cfl1pts4xh * rtP .
WeightForce_Value ; rtB . jjpibu4asu = cfl1pts4xh * muDoubleScalarCos ( rtP .
u [ 9 ] ) * rtP . WeightForce_Value ; rtB . igwvaibikt [ 0 ] = rtP .
TrimThrust1_Value * rtP . u [ 13 ] * rtP . Throttle_Gain ; rtB . igwvaibikt [
1 ] = rtP . u [ 13 ] * rtP . TrimThrust2_Value * rtP . Throttle_Gain ; rtB .
igwvaibikt [ 2 ] = rtP . Throttle_Gain * rtP . TrimThrust3_Value ;
muDoubleScalarSinCos ( muDoubleScalarAtan2 ( rtP . u [ 2 ] , rtP . u [ 0 ] )
, & cfl1pts4xh , & k3pv4ckac2 ) ; gmajytn1hv [ 0 ] = k3pv4ckac2 ; gmajytn1hv
[ 1 ] = rtP . Constant1_Value_bylbexapfl ; gmajytn1hv [ 2 ] = - cfl1pts4xh ;
gmajytn1hv [ 3 ] = rtP . Constant_Value_gi4rxypddg ; gmajytn1hv [ 4 ] = rtP .
Constant2_Value_ntj1nxsmyj ; gmajytn1hv [ 5 ] = rtP .
Constant4_Value_g531dn02hg ; gmajytn1hv [ 6 ] = cfl1pts4xh ; gmajytn1hv [ 7 ]
= rtP . Constant3_Value_irkjubdpiu ; gmajytn1hv [ 8 ] = k3pv4ckac2 ;
muDoubleScalarSinCos ( muDoubleScalarAtan2 ( rtP . u [ 2 ] , rtP . u [ 0 ] )
, & cfl1pts4xh , & k3pv4ckac2 ) ; igpg4wawt5 [ 0 ] = k3pv4ckac2 ; igpg4wawt5
[ 1 ] = rtP . Constant1_Value_ic5cse51j2 ; igpg4wawt5 [ 2 ] = - cfl1pts4xh ;
igpg4wawt5 [ 3 ] = rtP . Constant_Value_hfw2vld21b ; igpg4wawt5 [ 4 ] = rtP .
Constant2_Value_iq4hlvezb4 ; igpg4wawt5 [ 5 ] = rtP .
Constant4_Value_p1gsoflfkl ; igpg4wawt5 [ 6 ] = cfl1pts4xh ; igpg4wawt5 [ 7 ]
= rtP . Constant3_Value_bfs2kyqhyj ; igpg4wawt5 [ 8 ] = k3pv4ckac2 ; frac_ck
[ 0 ] = gv4idl0wui ; frac_ck [ 1 ] = le0egpvzyq ; frac_ck [ 2 ] = fszxvc31p3
; bpIndex_ck [ 0 ] = hmvrnu2ba1 ; bpIndex_ck [ 1 ] = nl5ggx5dex ; bpIndex_ck
[ 2 ] = cydulixisl ; cfl1pts4xh = intrp3d_s32dl_pw ( bpIndex_ck , frac_ck ,
rtP . Xcp_Table , rtP . Xcp_dimSize ) ; cfl1pts4xh *= rtP .
Constant4_Value_lvvzxuwh5z ; k3pv4ckac2 = rtP . u [ 14 ] - cfl1pts4xh ; tmp =
rtP . u [ 15 ] - rtP . zero1_Value ; tmp_p = rtP . u [ 16 ] - rtP .
zero1_Value ; for ( bpIndex_idx_0 = 0 ; bpIndex_idx_0 < 3 ; bpIndex_idx_0 ++
) { frac_ck [ bpIndex_idx_0 ] = igpg4wawt5 [ 3 * bpIndex_idx_0 + 2 ] * tmp_p
+ ( igpg4wawt5 [ 3 * bpIndex_idx_0 + 1 ] * tmp + igpg4wawt5 [ 3 *
bpIndex_idx_0 ] * k3pv4ckac2 ) ; } bpIndex_idx_0 = hmvrnu2ba1 ; bpIndex_idx_1
= nl5ggx5dex ; bpIndex_idx_2 = cydulixisl ; if ( ( ( uint32_T ) hmvrnu2ba1 ==
7U ) && ( gv4idl0wui >= 1.0 ) ) { bpIndex_idx_0 = hmvrnu2ba1 + 1 ; } if ( ( (
uint32_T ) nl5ggx5dex == 0U ) && ( le0egpvzyq >= 1.0 ) ) { bpIndex_idx_1 =
nl5ggx5dex + 1 ; } if ( ( ( uint32_T ) cydulixisl == 1U ) && ( fszxvc31p3 >=
1.0 ) ) { bpIndex_idx_2 = cydulixisl + 1 ; } bpIndex_idx_0_p = hmvrnu2ba1 ;
bpIndex_idx_1_p = nl5ggx5dex ; bpIndex_idx_2_p = cydulixisl ; if ( ( (
uint32_T ) hmvrnu2ba1 == 7U ) && ( gv4idl0wui >= 1.0 ) ) { bpIndex_idx_0_p =
hmvrnu2ba1 + 1 ; } if ( ( ( uint32_T ) nl5ggx5dex == 0U ) && ( le0egpvzyq >=
1.0 ) ) { bpIndex_idx_1_p = nl5ggx5dex + 1 ; } if ( ( ( uint32_T ) cydulixisl
== 1U ) && ( fszxvc31p3 >= 1.0 ) ) { bpIndex_idx_2_p = cydulixisl + 1 ; } if
( ( ( uint32_T ) hmvrnu2ba1 == 7U ) && ( gv4idl0wui >= 1.0 ) ) { hmvrnu2ba1
++ ; } if ( ( ( uint32_T ) nl5ggx5dex == 0U ) && ( le0egpvzyq >= 1.0 ) ) {
nl5ggx5dex ++ ; } if ( ( ( uint32_T ) cydulixisl == 1U ) && ( fszxvc31p3 >=
1.0 ) ) { cydulixisl ++ ; } gv4idl0wui = rtP . Clb_Table [ ( ( uint32_T ) (
bpIndex_idx_1 * 9 ) + bpIndex_idx_0 ) + bpIndex_idx_2 * 18 ] * rtB .
hzbuxpmezj * ( rtP . Constant2_Value_mwviqzbxqh * kswxbn4zh3 ) + ( nwi2cgk4yo
[ 1 ] * frac_ck [ 2 ] - nwi2cgk4yo [ 2 ] * frac_ck [ 1 ] ) ; le0egpvzyq = rtP
. Cm_Table [ ( ( uint32_T ) ( bpIndex_idx_1_p * 9 ) + bpIndex_idx_0_p ) +
bpIndex_idx_2_p * 18 ] * ( rtP . Constant4_Value_lvvzxuwh5z * kswxbn4zh3 ) +
( nwi2cgk4yo [ 2 ] * frac_ck [ 0 ] - nwi2cgk4yo [ 0 ] * frac_ck [ 2 ] ) ;
kswxbn4zh3 = rtP . Cnb_Table [ ( ( uint32_T ) ( nl5ggx5dex * 9 ) + hmvrnu2ba1
) + cydulixisl * 18 ] * rtB . hzbuxpmezj * ( rtP . Constant2_Value_mwviqzbxqh
* kswxbn4zh3 ) + ( nwi2cgk4yo [ 0 ] * frac_ck [ 1 ] - nwi2cgk4yo [ 1 ] *
frac_ck [ 0 ] ) ; for ( bpIndex_idx_0 = 0 ; bpIndex_idx_0 < 3 ; bpIndex_idx_0
++ ) { rtB . m1nsvprq1z [ bpIndex_idx_0 ] = 0.0 ; rtB . m1nsvprq1z [
bpIndex_idx_0 ] += gmajytn1hv [ 3 * bpIndex_idx_0 ] * gv4idl0wui ; rtB .
m1nsvprq1z [ bpIndex_idx_0 ] += gmajytn1hv [ 3 * bpIndex_idx_0 + 1 ] *
le0egpvzyq ; rtB . m1nsvprq1z [ bpIndex_idx_0 ] += gmajytn1hv [ 3 *
bpIndex_idx_0 + 2 ] * kswxbn4zh3 ; } muDoubleScalarSinCos (
muDoubleScalarAtan2 ( rtP . u [ 2 ] , rtP . u [ 0 ] ) , & gv4idl0wui , &
le0egpvzyq ) ; cduwu2tvxq [ 0 ] = le0egpvzyq ; cduwu2tvxq [ 1 ] = rtP .
Constant1_Value_g0n03q330k ; cduwu2tvxq [ 2 ] = - gv4idl0wui ; cduwu2tvxq [ 3
] = rtP . Constant_Value_ejuc1rn4ry ; cduwu2tvxq [ 4 ] = rtP .
Constant2_Value_oqrmwaotar ; cduwu2tvxq [ 5 ] = rtP .
Constant4_Value_jl0l41uur4 ; cduwu2tvxq [ 6 ] = gv4idl0wui ; cduwu2tvxq [ 7 ]
= rtP . Constant3_Value_gaexcfymgv ; cduwu2tvxq [ 8 ] = le0egpvzyq ; for (
bpIndex_idx_0 = 0 ; bpIndex_idx_0 < 3 ; bpIndex_idx_0 ++ ) { rtB . bdzrxsq0jb
[ 3 * bpIndex_idx_0 ] = cduwu2tvxq [ bpIndex_idx_0 ] ; rtB . bdzrxsq0jb [ 1 +
3 * bpIndex_idx_0 ] = cduwu2tvxq [ bpIndex_idx_0 + 3 ] ; rtB . bdzrxsq0jb [ 2
+ 3 * bpIndex_idx_0 ] = cduwu2tvxq [ bpIndex_idx_0 + 6 ] ; }
muDoubleScalarSinCos ( muDoubleScalarAtan2 ( rtP . u [ 2 ] , rtP . u [ 0 ] )
, & gv4idl0wui , & le0egpvzyq ) ; gcextsrvtd [ 0 ] = le0egpvzyq ; gcextsrvtd
[ 1 ] = rtP . Constant1_Value_hei4fwlj0u ; gcextsrvtd [ 2 ] = - gv4idl0wui ;
gcextsrvtd [ 3 ] = rtP . Constant_Value_fbwwe2lmsk ; gcextsrvtd [ 4 ] = rtP .
Constant2_Value_d4ghahoovd ; gcextsrvtd [ 5 ] = rtP .
Constant4_Value_iw11bz0kqi ; gcextsrvtd [ 6 ] = gv4idl0wui ; gcextsrvtd [ 7 ]
= rtP . Constant3_Value_pp0fbeghm2 ; gcextsrvtd [ 8 ] = le0egpvzyq ;
k3pv4ckac2 = rtP . u [ 14 ] - cfl1pts4xh ; tmp = rtP . u [ 15 ] - rtP .
zero1_Value ; tmp_p = rtP . u [ 16 ] - rtP . zero1_Value ; for (
bpIndex_idx_0 = 0 ; bpIndex_idx_0 < 3 ; bpIndex_idx_0 ++ ) { rtB . dp5pi2avlk
[ bpIndex_idx_0 ] = 0.0 ; rtB . dp5pi2avlk [ bpIndex_idx_0 ] += gcextsrvtd [
3 * bpIndex_idx_0 ] * k3pv4ckac2 ; rtB . dp5pi2avlk [ bpIndex_idx_0 ] +=
gcextsrvtd [ 3 * bpIndex_idx_0 + 1 ] * tmp ; rtB . dp5pi2avlk [ bpIndex_idx_0
] += gcextsrvtd [ 3 * bpIndex_idx_0 + 2 ] * tmp_p ; } rtB . ilvgb1vukq [ 0 ]
= rtP . Constant7_Value * rtB . idhxicsqcr ; rtB . ilvgb1vukq [ 1 ] = rtP .
Constant8_Value * rtB . idhxicsqcr ; rtB . ilvgb1vukq [ 2 ] = rtP .
Constant7_Value * rtB . idhxicsqcr ; muDoubleScalarSinCos (
muDoubleScalarAtan2 ( rtP . u [ 2 ] , rtP . u [ 0 ] ) , & gv4idl0wui , &
le0egpvzyq ) ; olbxomfkfq [ 0 ] = le0egpvzyq ; olbxomfkfq [ 1 ] = rtP .
Constant1_Value_ol4tirigyp ; olbxomfkfq [ 2 ] = - gv4idl0wui ; olbxomfkfq [ 3
] = rtP . Constant_Value_kouoqvqr2q ; olbxomfkfq [ 4 ] = rtP .
Constant2_Value_gjwptupmqz ; olbxomfkfq [ 5 ] = rtP .
Constant4_Value_cbj5azvbu2 ; olbxomfkfq [ 6 ] = gv4idl0wui ; olbxomfkfq [ 7 ]
= rtP . Constant3_Value_pwsvvqm1ni ; olbxomfkfq [ 8 ] = le0egpvzyq ;
muDoubleScalarSinCos ( muDoubleScalarAtan2 ( rtP . u [ 2 ] , rtP . u [ 0 ] )
, & gv4idl0wui , & le0egpvzyq ) ; cgh3d1u4d2 [ 0 ] = le0egpvzyq ; cgh3d1u4d2
[ 1 ] = rtP . Constant1_Value_knfpzjs1ar ; cgh3d1u4d2 [ 2 ] = - gv4idl0wui ;
cgh3d1u4d2 [ 3 ] = rtP . Constant_Value_huxzftueqj ; cgh3d1u4d2 [ 4 ] = rtP .
Constant2_Value_oqyl4nphju ; cgh3d1u4d2 [ 5 ] = rtP .
Constant4_Value_ijxamwyxru ; cgh3d1u4d2 [ 6 ] = gv4idl0wui ; cgh3d1u4d2 [ 7 ]
= rtP . Constant3_Value_idex1eazwv ; cgh3d1u4d2 [ 8 ] = le0egpvzyq ;
k3pv4ckac2 = rtP . u [ 14 ] - cfl1pts4xh ; tmp = rtP . u [ 15 ] - rtP .
zero1_Value ; tmp_p = rtP . u [ 16 ] - rtP . zero1_Value ; for (
bpIndex_idx_0 = 0 ; bpIndex_idx_0 < 3 ; bpIndex_idx_0 ++ ) { nwi2cgk4yo [
bpIndex_idx_0 ] = cgh3d1u4d2 [ 3 * bpIndex_idx_0 + 2 ] * tmp_p + ( cgh3d1u4d2
[ 3 * bpIndex_idx_0 + 1 ] * tmp + cgh3d1u4d2 [ 3 * bpIndex_idx_0 ] *
k3pv4ckac2 ) ; } cfl1pts4xh = ( frac [ 1 ] * nwi2cgk4yo [ 2 ] - frac [ 2 ] *
nwi2cgk4yo [ 1 ] ) + rtP . Constant3_Value_c0ie4jx1vv * anego2jgcz *
ll2axnx4w0 ; frac_idx_1 = ( frac [ 2 ] * nwi2cgk4yo [ 0 ] - frac [ 0 ] *
nwi2cgk4yo [ 2 ] ) + rtP . Constant5_Value_hu2bresth1 * anego2jgcz *
kxuzc0nr10_idx_4 ; anego2jgcz = ( frac [ 0 ] * nwi2cgk4yo [ 1 ] - frac [ 1 ]
* nwi2cgk4yo [ 0 ] ) + rtP . Constant3_Value_c0ie4jx1vv * anego2jgcz *
au4h5lcbek ; for ( bpIndex_idx_0 = 0 ; bpIndex_idx_0 < 3 ; bpIndex_idx_0 ++ )
{ rtB . kies3oo3id [ bpIndex_idx_0 ] = 0.0 ; rtB . kies3oo3id [ bpIndex_idx_0
] += olbxomfkfq [ 3 * bpIndex_idx_0 ] * cfl1pts4xh ; rtB . kies3oo3id [
bpIndex_idx_0 ] += olbxomfkfq [ 3 * bpIndex_idx_0 + 1 ] * frac_idx_1 ; rtB .
kies3oo3id [ bpIndex_idx_0 ] += olbxomfkfq [ 3 * bpIndex_idx_0 + 2 ] *
anego2jgcz ; } UNUSED_PARAMETER ( tid ) ; } void MdlUpdate ( int_T tid ) {
real_T * lastU ; if ( rtDW . lshsqezqdg == ( rtInf ) ) { rtDW . lshsqezqdg =
ssGetT ( rtS ) ; lastU = & rtDW . glhg1qagai ; } else if ( rtDW . noao4ocazt
== ( rtInf ) ) { rtDW . noao4ocazt = ssGetT ( rtS ) ; lastU = & rtDW .
davtpmukf5 ; } else if ( rtDW . lshsqezqdg < rtDW . noao4ocazt ) { rtDW .
lshsqezqdg = ssGetT ( rtS ) ; lastU = & rtDW . glhg1qagai ; } else { rtDW .
noao4ocazt = ssGetT ( rtS ) ; lastU = & rtDW . davtpmukf5 ; } * lastU = rtB .
nhxk0ib0lj ; if ( rtDW . ou0twhytn5 == ( rtInf ) ) { rtDW . ou0twhytn5 =
ssGetT ( rtS ) ; lastU = & rtDW . iub22gul40 ; } else if ( rtDW . hgbmrfgo34
== ( rtInf ) ) { rtDW . hgbmrfgo34 = ssGetT ( rtS ) ; lastU = & rtDW .
bdnvmlo1qe ; } else if ( rtDW . ou0twhytn5 < rtDW . hgbmrfgo34 ) { rtDW .
ou0twhytn5 = ssGetT ( rtS ) ; lastU = & rtDW . iub22gul40 ; } else { rtDW .
hgbmrfgo34 = ssGetT ( rtS ) ; lastU = & rtDW . bdnvmlo1qe ; } * lastU = rtB .
jf5nt45ccr ; UNUSED_PARAMETER ( tid ) ; } void MdlUpdateTID2 ( int_T tid ) {
UNUSED_PARAMETER ( tid ) ; } void MdlTerminate ( void ) { rt_FREE ( rtDW .
l43hqho0yh . RSimInfoPtr ) ; rtwOSigstreamManagerSaveDatasetsToMatFile (
rt_GetOSigstreamManager ( ) , rt_GetMatSigstreamLoggingFileName ( ) ) ;
rtwOSigstreamManagerDestroyInstance ( rt_GetOSigstreamManager ( ) ) ; } void
MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS , 0 ) ; ssSetNumY (
rtS , 0 ) ; ssSetNumU ( rtS , 0 ) ; ssSetDirectFeedThrough ( rtS , 0 ) ;
ssSetNumSampleTimes ( rtS , 2 ) ; ssSetNumBlocks ( rtS , 392 ) ;
ssSetNumBlockIO ( rtS , 34 ) ; ssSetNumBlockParams ( rtS , 5019 ) ; } void
MdlInitializeSampleTimes ( void ) { ssSetSampleTime ( rtS , 0 , 0.0 ) ;
ssSetSampleTime ( rtS , 1 , 0.1 ) ; ssSetOffsetTime ( rtS , 0 , 0.0 ) ;
ssSetOffsetTime ( rtS , 1 , 0.0 ) ; } void raccel_set_checksum ( SimStruct *
rtS ) { ssSetChecksumVal ( rtS , 0 , 309997958U ) ; ssSetChecksumVal ( rtS ,
1 , 4152278500U ) ; ssSetChecksumVal ( rtS , 2 , 3176591357U ) ;
ssSetChecksumVal ( rtS , 3 , 2740593875U ) ; } SimStruct *
raccel_register_model ( void ) { static struct _ssMdlInfo mdlInfo ; ( void )
memset ( ( char * ) rtS , 0 , sizeof ( SimStruct ) ) ; ( void ) memset ( (
char * ) & mdlInfo , 0 , sizeof ( struct _ssMdlInfo ) ) ; ssSetMdlInfoPtr (
rtS , & mdlInfo ) ; { static time_T mdlPeriod [ NSAMPLE_TIMES ] ; static
time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T mdlTaskTimes [
NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ; static int_T
mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T mdlTNextWasAdjustedPtr [
NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits [ NSAMPLE_TIMES *
NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [ NSAMPLE_TIMES ] ; {
int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) { mdlPeriod [ i ] = 0.0 ;
mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ; mdlTsMap [ i ] = i ;
mdlSampleHits [ i ] = 1 ; } } ssSetSampleTimePtr ( rtS , & mdlPeriod [ 0 ] )
; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ; ssSetSampleTimeTaskIDPtr (
rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , & mdlTaskTimes [ 0 ] ) ;
ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ; ssSetTNextWasAdjustedPtr
( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ; ssSetPerTaskSampleHitsPtr ( rtS ,
& mdlPerTaskSampleHits [ 0 ] ) ; ssSetTimeOfNextSampleHitPtr ( rtS , &
mdlTimeOfNextSampleHit [ 0 ] ) ; } ssSetSolverMode ( rtS ,
SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS , ( ( void * ) & rtB ) ) ;
( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof ( B ) ) ; }
ssSetDefaultParam ( rtS , ( real_T * ) & rtP ) ; { void * dwork = ( void * )
& rtDW ; ssSetRootDWork ( rtS , dwork ) ; ( void ) memset ( dwork , 0 ,
sizeof ( DW ) ) ; } { static DataTypeTransInfo dtInfo ; ( void ) memset ( (
char_T * ) & dtInfo , 0 , sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS ,
& dtInfo ) ; dtInfo . numDataTypes = 14 ; dtInfo . dataTypeSizes = &
rtDataTypeSizes [ 0 ] ; dtInfo . dataTypeNames = & rtDataTypeNames [ 0 ] ;
dtInfo . BTransTable = & rtBTransTable ; dtInfo . PTransTable = &
rtPTransTable ; } DatcomForceMoment_InitializeDataMapInfo ( rtS ) ;
ssSetIsRapidAcceleratorActive ( rtS , true ) ; ssSetRootSS ( rtS , rtS ) ;
ssSetVersion ( rtS , SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS ,
"DatcomForceMoment" ) ; ssSetPath ( rtS , "DatcomForceMoment" ) ; ssSetTStart
( rtS , 0.0 ) ; ssSetTFinal ( rtS , 0.1 ) ; ssSetStepSize ( rtS , 0.1 ) ;
ssSetFixedStepSize ( rtS , 0.1 ) ; { static RTWLogInfo rt_DataLoggingInfo ;
rt_DataLoggingInfo . loggingInterval = NULL ; ssSetRTWLogInfo ( rtS , &
rt_DataLoggingInfo ) ; } { rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) ,
( NULL ) ) ; rtliSetLogXSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogT ( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX (
ssGetRTWLogInfo ( rtS ) , "" ) ; rtliSetLogXFinal ( ssGetRTWLogInfo ( rtS ) ,
"" ) ; rtliSetLogVarNameModifier ( ssGetRTWLogInfo ( rtS ) , "none" ) ;
rtliSetLogFormat ( ssGetRTWLogInfo ( rtS ) , 4 ) ; rtliSetLogMaxRows (
ssGetRTWLogInfo ( rtS ) , 0 ) ; rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS
) , 1 ) ; rtliSetLogY ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogYSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; } { static
ssSolverInfo slvrInfo ; ssSetSolverInfo ( rtS , & slvrInfo ) ;
ssSetSolverName ( rtS , "FixedStepDiscrete" ) ; ssSetVariableStepSolver ( rtS
, 0 ) ; ssSetSolverConsistencyChecking ( rtS , 0 ) ;
ssSetSolverAdaptiveZcDetection ( rtS , 0 ) ; ssSetSolverRobustResetMethod (
rtS , 0 ) ; ssSetSolverStateProjection ( rtS , 0 ) ;
ssSetSolverMassMatrixType ( rtS , ( ssMatrixType ) 0 ) ;
ssSetSolverMassMatrixNzMax ( rtS , 0 ) ; ssSetModelOutputs ( rtS , MdlOutputs
) ; ssSetModelLogData ( rtS , rt_UpdateTXYLogVars ) ;
ssSetModelLogDataIfInInterval ( rtS , rt_UpdateTXXFYLogVars ) ;
ssSetModelUpdate ( rtS , MdlUpdate ) ; ssSetTNextTid ( rtS , INT_MIN ) ;
ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ;
ssSetNumNonsampledZCs ( rtS , 0 ) ; } ssSetChecksumVal ( rtS , 0 , 309997958U
) ; ssSetChecksumVal ( rtS , 1 , 4152278500U ) ; ssSetChecksumVal ( rtS , 2 ,
3176591357U ) ; ssSetChecksumVal ( rtS , 3 , 2740593875U ) ; { static const
sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo
rt_ExtModeInfo ; static const sysRanDType * systemRan [ 1 ] ;
ssSetRTWExtModeInfo ( rtS , & rt_ExtModeInfo ) ;
rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo , systemRan ) ;
systemRan [ 0 ] = & rtAlwaysEnabled ; rteiSetModelMappingInfoPtr (
ssGetRTWExtModeInfo ( rtS ) , & ssGetModelMappingInfo ( rtS ) ) ;
rteiSetChecksumsPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetChecksums ( rtS ) )
; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS ) , ssGetTPtr ( rtS ) ) ; } return
rtS ; } const int_T gblParameterTuningTid = 2 ; void
MdlOutputsParameterSampleTime ( int_T tid ) { MdlOutputsTID2 ( tid ) ; }
