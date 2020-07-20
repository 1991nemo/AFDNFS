#include "rt_logging_mmi.h"
#include "TrimFandM_capi.h"
#include <math.h>
#include "TrimFandM.h"
#include "TrimFandM_private.h"
#include "TrimFandM_dt.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; extern boolean_T
gblExtModeStartPktReceived ; void raccelForceExtModeShutdown ( ) { if ( !
gblExtModeStartPktReceived ) { boolean_T stopRequested = false ;
rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 1 , & stopRequested ) ; }
rtExtModeShutdown ( 1 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 1 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 0 ; int_T gbl_raccel_NumST = 2 ; const char_T
* gbl_raccel_Version = "9.3 (R2020a) 18-Nov-2019" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const char * gblSlvrJacPatternFileName =
"slprj\\raccel\\TrimFandM\\TrimFandM_Jpattern.mat" ; const int_T
gblNumRootInportBlks = 0 ; const int_T gblNumModelInputs = 0 ; extern
rtInportTUtable * gblInportTUtables ; extern const char * gblInportFileName ;
extern void * gblAperiodicPartitionHitTimes ; const int_T
gblInportDataTypeIdx [ ] = { - 1 } ; const int_T gblInportDims [ ] = { - 1 }
; const int_T gblInportComplex [ ] = { - 1 } ; const int_T
gblInportInterpoFlag [ ] = { - 1 } ; const int_T gblInportContinuous [ ] = {
- 1 } ; int_T enableFcnCallFlag [ ] = { 1 , 1 } ; const char *
raccelLoadInputsAndAperiodicHitTimes ( const char * inportFileName , int *
matFileFormat ) { return rt_RapidReadInportsMatFile ( inportFileName ,
matFileFormat , 1 ) ; }
#include "simstruc.h"
#include "fixedpoint.h"
B rtB ; DW rtDW ; static SimStruct model_S ; SimStruct * const rtS = &
model_S ; void MdlStart ( void ) { { void * * slioCatalogueAddr =
rt_slioCatalogueAddr ( ) ; void * r2 = ( NULL ) ; void * *
pOSigstreamManagerAddr = ( NULL ) ; const int maxErrorBufferSize = 16384 ;
char errMsgCreatingOSigstreamManager [ 16384 ] ; bool
errorCreatingOSigstreamManager = false ; const char *
errorAddingR2SharedResource = ( NULL ) ; * slioCatalogueAddr =
rtwGetNewSlioCatalogue ( rt_GetMatSigLogSelectorFileName ( ) ) ;
errorAddingR2SharedResource = rtwAddR2SharedResource (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) , 1 ) ; if (
errorAddingR2SharedResource != ( NULL ) ) { rtwTerminateSlioCatalogue (
slioCatalogueAddr ) ; * slioCatalogueAddr = ( NULL ) ; ssSetErrorStatus ( rtS
, errorAddingR2SharedResource ) ; return ; } r2 = rtwGetR2SharedResource (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) ) ;
pOSigstreamManagerAddr = rt_GetOSigstreamManagerAddr ( ) ;
errorCreatingOSigstreamManager = rtwOSigstreamManagerCreateInstance (
rt_GetMatSigLogSelectorFileName ( ) , r2 , pOSigstreamManagerAddr ,
errMsgCreatingOSigstreamManager , maxErrorBufferSize ) ; if (
errorCreatingOSigstreamManager ) { * pOSigstreamManagerAddr = ( NULL ) ;
ssSetErrorStatus ( rtS , errMsgCreatingOSigstreamManager ) ; return ; } } {
bool externalInputIsInDatasetFormat = false ; void * pISigstreamManager =
rt_GetISigstreamManager ( ) ; rtwISigstreamManagerGetInputIsInDatasetFormat (
pISigstreamManager , & externalInputIsInDatasetFormat ) ; if (
externalInputIsInDatasetFormat ) { } } rtDW . a5dgjvoljo = 0 ; rtDW .
luap051kiq = 0 ; rtDW . e0do2nutvy = 0 ; rtDW . cqqe4ackda = 0 ; rtDW .
czecwii4jn = 0 ; rtDW . fdafrlqdiy = 0 ; rtDW . cepg00qrhs = 0 ; rtDW .
pzbp2jg2ny = 0 ; rtDW . kxhtuldmhk = 0 ; rtDW . gbrl2nobbn = 0 ; { FWksInfo *
fromwksInfo ; if ( ( fromwksInfo = ( FWksInfo * ) calloc ( 1 , sizeof (
FWksInfo ) ) ) == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName = "tuvar" ; fromwksInfo -> origDataTypeId
= 0 ; fromwksInfo -> origIsComplex = 0 ; fromwksInfo -> origWidth = 1 ;
fromwksInfo -> origElSize = sizeof ( real_T ) ; fromwksInfo -> data = ( void
* ) rtP . FromWs_Data0 ; fromwksInfo -> nDataPoints = 6 ; fromwksInfo -> time
= ( double * ) rtP . FromWs_Time0 ; rtDW . ia5ajb52kh . TimePtr = fromwksInfo
-> time ; rtDW . ia5ajb52kh . DataPtr = fromwksInfo -> data ; rtDW .
ia5ajb52kh . RSimInfoPtr = fromwksInfo ; } rtDW . gm1dcsqrzm . PrevIndex = 0
; { int_T * zcTimeIndices = & rtDW . d3azz5z2mq [ 0 ] ; const double *
timePoints = ( double * ) rtDW . ia5ajb52kh . TimePtr ; boolean_T
justHadZcTime = false ; int_T zcIdx = 0 ; int_T i ; for ( i = 0 ; i < 6 - 1 ;
i ++ ) { if ( ! justHadZcTime && timePoints [ i ] == timePoints [ i + 1 ] ) {
zcTimeIndices [ zcIdx ++ ] = i ; justHadZcTime = true ; } else {
justHadZcTime = false ; } } rtDW . nf3duvwzmk = 0 ; } } } void MdlOutputs (
int_T tid ) { real_T iludbqkbqg ; real_T fckcvqcasq ; { real_T * pDataValues
= ( real_T * ) rtDW . ia5ajb52kh . DataPtr ; real_T * pTimeValues = ( real_T
* ) rtDW . ia5ajb52kh . TimePtr ; int_T currTimeIndex = rtDW . gm1dcsqrzm .
PrevIndex ; real_T t = ssGetTaskTime ( rtS , 0 ) ; int numPoints , lastPoint
; FWksInfo * fromwksInfo = ( FWksInfo * ) rtDW . ia5ajb52kh . RSimInfoPtr ;
numPoints = fromwksInfo -> nDataPoints ; lastPoint = numPoints - 1 ; if ( t
<= pTimeValues [ 0 ] ) { currTimeIndex = 0 ; } else if ( t >= pTimeValues [
lastPoint ] ) { currTimeIndex = lastPoint - 1 ; } else { if ( t < pTimeValues
[ currTimeIndex ] ) { while ( t < pTimeValues [ currTimeIndex ] ) {
currTimeIndex -- ; } } else { while ( t >= pTimeValues [ currTimeIndex + 1 ]
) { currTimeIndex ++ ; } } } rtDW . gm1dcsqrzm . PrevIndex = currTimeIndex ;
{ real_T t1 = pTimeValues [ currTimeIndex ] ; real_T t2 = pTimeValues [
currTimeIndex + 1 ] ; if ( t1 == t2 ) { if ( t < t1 ) { iludbqkbqg =
pDataValues [ currTimeIndex ] ; } else { iludbqkbqg = pDataValues [
currTimeIndex + 1 ] ; } } else { real_T f1 = ( t2 - t ) / ( t2 - t1 ) ;
real_T f2 = 1.0 - f1 ; real_T d1 ; real_T d2 ; int_T TimeIndex =
currTimeIndex ; int_T * zcTimeIndices = & rtDW . d3azz5z2mq [ 0 ] ; int_T *
zcTimeIndicesIdx = & rtDW . nf3duvwzmk ; int_T zcIdx = zcTimeIndices [ *
zcTimeIndicesIdx ] ; int_T numZcTimes = 2 ; if ( * zcTimeIndicesIdx <
numZcTimes ) { if ( ssIsMajorTimeStep ( rtS ) ) { if ( t > pTimeValues [
zcIdx ] ) { while ( * zcTimeIndicesIdx < ( numZcTimes - 1 ) && ( t >
pTimeValues [ zcIdx ] ) ) { ( * zcTimeIndicesIdx ) ++ ; zcIdx = zcTimeIndices
[ * zcTimeIndicesIdx ] ; } } } else { if ( t >= pTimeValues [ zcIdx ] && (
ssGetTimeOfLastOutput ( rtS ) < pTimeValues [ zcIdx ] ) ) { t2 = pTimeValues
[ zcIdx ] ; if ( zcIdx == 0 ) { TimeIndex = 0 ; t1 = t2 - 1 ; } else { t1 =
pTimeValues [ zcIdx - 1 ] ; TimeIndex = zcIdx - 1 ; } f1 = ( t2 - t ) / ( t2
- t1 ) ; f2 = 1.0 - f1 ; } } } d1 = pDataValues [ TimeIndex ] ; d2 =
pDataValues [ TimeIndex + 1 ] ; if ( zcIdx == 0 ) { d2 = d1 ; } iludbqkbqg =
( real_T ) rtInterpolate ( d1 , d2 , f1 , f2 ) ; pDataValues += numPoints ; }
} } if ( rtP . ManualSwitch_CurrentSetting == 1 ) { fckcvqcasq = iludbqkbqg ;
} else { fckcvqcasq = rtP . TrimThrust4_Value ; } rtB . cewmuklpud [ 0 ] = (
rtB . dkxpu1nqs1 [ 0 ] * fckcvqcasq + rtB . n20ebdvrmd [ 0 ] ) + rtB .
h5b40zrgbx [ 0 ] ; rtB . cewmuklpud [ 1 ] = ( rtB . dkxpu1nqs1 [ 1 ] *
fckcvqcasq + rtB . n20ebdvrmd [ 1 ] ) + rtB . h5b40zrgbx [ 1 ] ; rtB .
cewmuklpud [ 2 ] = ( rtB . dkxpu1nqs1 [ 2 ] * fckcvqcasq + rtB . n20ebdvrmd [
2 ] ) + rtB . h5b40zrgbx [ 2 ] ; UNUSED_PARAMETER ( tid ) ; } void
MdlOutputsTID1 ( int_T tid ) { boolean_T rEQ0 ; real_T kcqnzeq3ae ; real_T
mopraowr3n ; real_T kyavmd5rbl ; real_T jvionhulh2 ; real_T khpkfzitiv ;
real_T mfbasnsgfx ; real_T kk4ijdw44p [ 9 ] ; real_T emqejpczxk ; real_T
djw4rr1c2t ; real_T jsq1znebmd ; real_T it0ysb3kxv ; real_T ea2nyeoau2 ;
real_T fdvu4rjk1x_p ; int32_T i ; real_T dtjpbfufam_idx_0 ; rtB . c155b3ttul
= muDoubleScalarAtan ( 1.0 / rtP . Constant4_Value [ 0 ] * rtP .
Constant4_Value [ 2 ] ) ; mopraowr3n = muDoubleScalarCos ( rtB . c155b3ttul )
; kcqnzeq3ae = ( rtP . Constant4_Value [ 0 ] * rtP . Constant4_Value [ 0 ] +
rtP . Constant4_Value [ 1 ] * rtP . Constant4_Value [ 1 ] ) + rtP .
Constant4_Value [ 2 ] * rtP . Constant4_Value [ 2 ] ; if ( ssIsMajorTimeStep
( rtS ) ) { if ( rtDW . a5dgjvoljo != 0 ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW . a5dgjvoljo = 0 ;
} kcqnzeq3ae = muDoubleScalarSqrt ( kcqnzeq3ae ) ; } else if ( kcqnzeq3ae <
0.0 ) { kcqnzeq3ae = - muDoubleScalarSqrt ( muDoubleScalarAbs ( kcqnzeq3ae )
) ; rtDW . a5dgjvoljo = 1 ; } else { kcqnzeq3ae = muDoubleScalarSqrt (
kcqnzeq3ae ) ; } it0ysb3kxv = rtP . Constant4_Value [ 1 ] / kcqnzeq3ae ; if (
it0ysb3kxv > 1.0 ) { it0ysb3kxv = 1.0 ; } else { if ( it0ysb3kxv < - 1.0 ) {
it0ysb3kxv = - 1.0 ; } } dtjpbfufam_idx_0 = muDoubleScalarAsin ( it0ysb3kxv )
; mfbasnsgfx = rtP . Gain_Gain * dtjpbfufam_idx_0 ; kyavmd5rbl =
muDoubleScalarCos ( mfbasnsgfx ) ; mfbasnsgfx = muDoubleScalarSin (
mfbasnsgfx ) ; jvionhulh2 = muDoubleScalarSin ( rtB . c155b3ttul ) ;
kk4ijdw44p [ 0 ] = mopraowr3n * kyavmd5rbl ; kk4ijdw44p [ 1 ] = mopraowr3n *
mfbasnsgfx * rtP . ChSign_Gain ; kk4ijdw44p [ 2 ] = rtP . ChSign1_Gain *
jvionhulh2 ; kk4ijdw44p [ 3 ] = mfbasnsgfx ; kk4ijdw44p [ 4 ] = kyavmd5rbl ;
kk4ijdw44p [ 5 ] = rtP . Zero_Value ; kk4ijdw44p [ 6 ] = jvionhulh2 *
kyavmd5rbl ; kk4ijdw44p [ 7 ] = jvionhulh2 * mfbasnsgfx * rtP . ChSign2_Gain
; kk4ijdw44p [ 8 ] = mopraowr3n ; mopraowr3n = - rtP . Constant5_Value [ 2 ]
- rtP . RefAlt_Value ; if ( mopraowr3n > rtP .
Limitaltitudetotroposhere_UpperSat ) { mfbasnsgfx = rtP .
Limitaltitudetotroposhere_UpperSat ; } else if ( mopraowr3n < rtP .
Limitaltitudetotroposhere_LowerSat ) { mfbasnsgfx = rtP .
Limitaltitudetotroposhere_LowerSat ; } else { mfbasnsgfx = mopraowr3n ; }
khpkfzitiv = rtP . SeaLevelTemperature_Value - rtP . LapseRate_Gain *
mfbasnsgfx ; kyavmd5rbl = rtP . uT0_Gain * khpkfzitiv ; mfbasnsgfx = rtP .
clbeta_Gain * dtjpbfufam_idx_0 ; jvionhulh2 = rtP . cldelta_a_Gain * rtP .
Constant3_Value [ 2 ] ; emqejpczxk = rtP . cldelta_r_Gain * rtP .
Constant3_Value [ 3 ] ; djw4rr1c2t = rtP . clp_Gain * rtP . Constant6_Value [
0 ] ; jsq1znebmd = rtP . clr_Gain * rtP . Constant6_Value [ 2 ] ;
fdvu4rjk1x_p = ( rtP . Constant4_Value [ 0 ] * rtP . Constant4_Value [ 0 ] +
rtP . Constant4_Value [ 1 ] * rtP . Constant4_Value [ 1 ] ) + rtP .
Constant4_Value [ 2 ] * rtP . Constant4_Value [ 2 ] ; it0ysb3kxv = rtP .
AltitudeofTroposphere_Value - mopraowr3n ; if ( ( kyavmd5rbl < 0.0 ) && ( rtP
. gLR_Value > muDoubleScalarFloor ( rtP . gLR_Value ) ) ) { ea2nyeoau2 = -
muDoubleScalarPower ( - kyavmd5rbl , rtP . gLR_Value ) ; } else { ea2nyeoau2
= muDoubleScalarPower ( kyavmd5rbl , rtP . gLR_Value ) ; } if ( it0ysb3kxv >
rtP . LimitaltitudetoStratosphere_UpperSat ) { it0ysb3kxv = rtP .
LimitaltitudetoStratosphere_UpperSat ; } else { if ( it0ysb3kxv < rtP .
LimitaltitudetoStratosphere_LowerSat ) { it0ysb3kxv = rtP .
LimitaltitudetoStratosphere_LowerSat ; } } kyavmd5rbl = ea2nyeoau2 /
kyavmd5rbl * rtP . rho0_Gain * muDoubleScalarExp ( 1.0 / khpkfzitiv * ( rtP .
gR_Gain * it0ysb3kxv ) ) * rtP . Gain_Gain_i2ygq2tusg * muDoubleScalarAbs ( (
rtP . Constant4_Value [ 0 ] * rtP . Constant4_Value [ 0 ] + rtP .
Constant4_Value [ 1 ] * rtP . Constant4_Value [ 1 ] ) + rtP . Constant4_Value
[ 2 ] * rtP . Constant4_Value [ 2 ] ) ; if ( ssIsMajorTimeStep ( rtS ) ) { if
( rtDW . luap051kiq != 0 ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS
) ; rtDW . luap051kiq = 0 ; } it0ysb3kxv = muDoubleScalarSqrt ( fdvu4rjk1x_p
) ; } else if ( fdvu4rjk1x_p < 0.0 ) { it0ysb3kxv = - muDoubleScalarSqrt (
muDoubleScalarAbs ( fdvu4rjk1x_p ) ) ; rtDW . luap051kiq = 1 ; } else {
it0ysb3kxv = muDoubleScalarSqrt ( fdvu4rjk1x_p ) ; } jvionhulh2 = ( (
djw4rr1c2t + jsq1znebmd ) * rtP . Wingspan_Value_abjhsc0f24 / ( rtP . u_Gain
* it0ysb3kxv ) + ( ( mfbasnsgfx + jvionhulh2 ) + emqejpczxk ) ) * (
kyavmd5rbl * rtP . Wingarea_Value * rtP . Wingspan_Value ) ; rtB . a3vyc4l10x
= rtP . Cm0_Value ; rtB . oouqhb3v3v = rtP . cmalpha_Gain * rtB . c155b3ttul
; rtB . gqpi3oabc5 = rtP . cmdelta_f_Gain * rtP . Constant3_Value [ 1 ] ; rtB
. lbnjpcgymq = rtP . cmdelta_e_Gain * rtP . Constant3_Value [ 0 ] ;
mfbasnsgfx = ( rtP . Constant1_Value [ 2 ] * rtP . Constant4_Value [ 0 ] -
rtP . Constant1_Value [ 0 ] * rtP . Constant4_Value [ 2 ] ) / (
muDoubleScalarPower ( rtP . Constant4_Value [ 0 ] , 2.0 ) +
muDoubleScalarPower ( rtP . Constant4_Value [ 2 ] , 2.0 ) ) ; rtB .
lqji0le141 = rtP . cmalphadot_Gain * mfbasnsgfx ; rtB . iwltmc0fj1 = rtP .
cmq_Gain * rtP . Constant6_Value [ 1 ] ; emqejpczxk = rtB . lqji0le141 + rtB
. iwltmc0fj1 ; djw4rr1c2t = ( rtP . Constant4_Value [ 0 ] * rtP .
Constant4_Value [ 0 ] + rtP . Constant4_Value [ 1 ] * rtP . Constant4_Value [
1 ] ) + rtP . Constant4_Value [ 2 ] * rtP . Constant4_Value [ 2 ] ; if (
ssIsMajorTimeStep ( rtS ) ) { if ( rtDW . e0do2nutvy != 0 ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW . e0do2nutvy = 0 ;
} jsq1znebmd = muDoubleScalarSqrt ( djw4rr1c2t ) ; } else if ( djw4rr1c2t <
0.0 ) { jsq1znebmd = - muDoubleScalarSqrt ( muDoubleScalarAbs ( djw4rr1c2t )
) ; rtDW . e0do2nutvy = 1 ; } else { jsq1znebmd = muDoubleScalarSqrt (
djw4rr1c2t ) ; } emqejpczxk = emqejpczxk * rtP . Wingchord_Value_pdh1mmrkaf /
( rtP . u_Gain_c3gtfmblii * jsq1znebmd ) ; khpkfzitiv *= rtP . gammaR_Gain ;
if ( ssIsMajorTimeStep ( rtS ) ) { if ( rtDW . cqqe4ackda != 0 ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW . cqqe4ackda = 0 ;
} djw4rr1c2t = muDoubleScalarSqrt ( khpkfzitiv ) ; } else if ( khpkfzitiv <
0.0 ) { djw4rr1c2t = - muDoubleScalarSqrt ( muDoubleScalarAbs ( khpkfzitiv )
) ; rtDW . cqqe4ackda = 1 ; } else { djw4rr1c2t = muDoubleScalarSqrt (
khpkfzitiv ) ; } kcqnzeq3ae /= djw4rr1c2t ; rtB . k1zmldxyil = rtP . cmM_Gain
* kcqnzeq3ae ; khpkfzitiv = ( ( ( ( ( rtB . a3vyc4l10x + rtB . oouqhb3v3v ) +
rtB . gqpi3oabc5 ) + rtB . lbnjpcgymq ) + emqejpczxk ) + rtB . k1zmldxyil ) *
( kyavmd5rbl * rtP . Wingarea_Value * rtP . Wingchord_Value ) ; emqejpczxk =
rtP . cnbeta_Gain * dtjpbfufam_idx_0 ; djw4rr1c2t = rtP . cndelta_a_Gain *
rtP . Constant3_Value [ 2 ] ; jsq1znebmd = rtP . cndelta_r_Gain * rtP .
Constant3_Value [ 3 ] ; fdvu4rjk1x_p = rtP . cnp_Gain * rtP . Constant6_Value
[ 0 ] ; it0ysb3kxv = rtP . cnr_Gain * rtP . Constant6_Value [ 2 ] ;
ea2nyeoau2 = ( rtP . Constant4_Value [ 0 ] * rtP . Constant4_Value [ 0 ] +
rtP . Constant4_Value [ 1 ] * rtP . Constant4_Value [ 1 ] ) + rtP .
Constant4_Value [ 2 ] * rtP . Constant4_Value [ 2 ] ; if ( ssIsMajorTimeStep
( rtS ) ) { if ( rtDW . czecwii4jn != 0 ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW . czecwii4jn = 0 ;
} ea2nyeoau2 = muDoubleScalarSqrt ( ea2nyeoau2 ) ; } else if ( ea2nyeoau2 <
0.0 ) { ea2nyeoau2 = - muDoubleScalarSqrt ( muDoubleScalarAbs ( ea2nyeoau2 )
) ; rtDW . czecwii4jn = 1 ; } else { ea2nyeoau2 = muDoubleScalarSqrt (
ea2nyeoau2 ) ; } emqejpczxk = ( ( fdvu4rjk1x_p + it0ysb3kxv ) * rtP .
Wingspan_Value_e2odjstrw4 / ( rtP . u_Gain_allopj2sjw * ea2nyeoau2 ) + ( (
emqejpczxk + djw4rr1c2t ) + jsq1znebmd ) ) * ( kyavmd5rbl * rtP .
Wingarea_Value * rtP . Wingspan2_Value ) ; for ( i = 0 ; i < 3 ; i ++ ) { rtB
. eitentvc2c [ i ] = ( ( kk4ijdw44p [ i + 6 ] * emqejpczxk + ( kk4ijdw44p [ i
+ 3 ] * khpkfzitiv + kk4ijdw44p [ i ] * jvionhulh2 ) ) + rtP .
TrimThrust5_Value [ i ] ) + rtP . TrimThrust5_Value_aggklib54h [ i ] ; }
jvionhulh2 = rtP . cLalpha_Gain * rtB . c155b3ttul ; khpkfzitiv = rtP .
cLdelta_e_Gain * rtP . Constant3_Value [ 0 ] ; emqejpczxk = rtP .
cLdelta_f_Gain * rtP . Constant3_Value [ 1 ] ; mfbasnsgfx = rtP .
cLalphadot_Gain * mfbasnsgfx + rtP . cLq_Gain * rtP . Constant6_Value [ 1 ] ;
djw4rr1c2t = ( rtP . Constant4_Value [ 0 ] * rtP . Constant4_Value [ 0 ] +
rtP . Constant4_Value [ 1 ] * rtP . Constant4_Value [ 1 ] ) + rtP .
Constant4_Value [ 2 ] * rtP . Constant4_Value [ 2 ] ; if ( ssIsMajorTimeStep
( rtS ) ) { if ( rtDW . fdafrlqdiy != 0 ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW . fdafrlqdiy = 0 ;
} jsq1znebmd = muDoubleScalarSqrt ( djw4rr1c2t ) ; } else if ( djw4rr1c2t <
0.0 ) { jsq1znebmd = - muDoubleScalarSqrt ( muDoubleScalarAbs ( djw4rr1c2t )
) ; rtDW . fdafrlqdiy = 1 ; } else { jsq1znebmd = muDoubleScalarSqrt (
djw4rr1c2t ) ; } jvionhulh2 = ( ( ( ( rtP . LiftCoefficient_cL0 + jvionhulh2
) + khpkfzitiv ) + emqejpczxk ) + mfbasnsgfx * rtP .
LiftCoefficient_meanchord / ( rtP . u_Gain_nvhs5kychw * jsq1znebmd ) ) + rtP
. CLM_Gain * kcqnzeq3ae ; mfbasnsgfx = rtP . ChSign1_Gain_n4wwtfjx2h *
jvionhulh2 ; djw4rr1c2t = rtP . ChSign2_Gain_effoydn3u1 * dtjpbfufam_idx_0 ;
kyavmd5rbl *= rtP . WingArea_Value ; khpkfzitiv = muDoubleScalarCos ( rtB .
c155b3ttul ) ; emqejpczxk = muDoubleScalarCos ( djw4rr1c2t ) ; djw4rr1c2t =
muDoubleScalarSin ( djw4rr1c2t ) ; jsq1znebmd = muDoubleScalarSin ( rtB .
c155b3ttul ) ; kk4ijdw44p [ 0 ] = khpkfzitiv * emqejpczxk ; kk4ijdw44p [ 1 ]
= khpkfzitiv * djw4rr1c2t * rtP . ChSign_Gain_gtanyi5b3f ; kk4ijdw44p [ 2 ] =
rtP . ChSign1_Gain_nkytdev4sk * jsq1znebmd ; kk4ijdw44p [ 3 ] = djw4rr1c2t ;
kk4ijdw44p [ 4 ] = emqejpczxk ; kk4ijdw44p [ 5 ] = rtP .
Zero_Value_mumexc0o4r ; kk4ijdw44p [ 6 ] = jsq1znebmd * emqejpczxk ;
kk4ijdw44p [ 7 ] = jsq1znebmd * djw4rr1c2t * rtP . ChSign2_Gain_knade2nq5x ;
kk4ijdw44p [ 8 ] = khpkfzitiv ; kcqnzeq3ae = ( ( ( ( ( ( ( jvionhulh2 *
jvionhulh2 * rtP . InducedDrag_Gain + rtP . DragCoefficient_cD0 ) +
muDoubleScalarAbs ( rtP . cDalpha_Gain * rtB . c155b3ttul ) ) +
muDoubleScalarAbs ( rtP . cDdelta_f_Gain * rtP . Constant3_Value [ 1 ] ) ) +
muDoubleScalarAbs ( rtP . cDdelta_e_Gain * rtP . Constant3_Value [ 0 ] ) ) +
muDoubleScalarAbs ( rtP . cDdelta_a_Gain * rtP . Constant3_Value [ 2 ] ) ) +
muDoubleScalarAbs ( rtP . cDdelta_r_Gain * rtP . Constant3_Value [ 3 ] ) ) +
rtP . cDM_Gain * kcqnzeq3ae ) * rtP . ChSign_Gain_k0w4nqg0k2 * kyavmd5rbl ;
dtjpbfufam_idx_0 *= rtP . cYbeta_Gain ; jvionhulh2 = rtP . cYdelta_a_Gain *
rtP . Constant3_Value [ 2 ] ; khpkfzitiv = rtP . cYdelta_r_Gain * rtP .
Constant3_Value [ 3 ] ; emqejpczxk = rtP . cYp_Gain * rtP . Constant6_Value [
0 ] ; djw4rr1c2t = rtP . cYr_Gain * rtP . Constant6_Value [ 2 ] ; jsq1znebmd
= ( rtP . Constant4_Value [ 0 ] * rtP . Constant4_Value [ 0 ] + rtP .
Constant4_Value [ 1 ] * rtP . Constant4_Value [ 1 ] ) + rtP . Constant4_Value
[ 2 ] * rtP . Constant4_Value [ 2 ] ; if ( ssIsMajorTimeStep ( rtS ) ) { if (
rtDW . cepg00qrhs != 0 ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS )
; rtDW . cepg00qrhs = 0 ; } fdvu4rjk1x_p = muDoubleScalarSqrt ( jsq1znebmd )
; } else if ( jsq1znebmd < 0.0 ) { fdvu4rjk1x_p = - muDoubleScalarSqrt (
muDoubleScalarAbs ( jsq1znebmd ) ) ; rtDW . cepg00qrhs = 1 ; } else {
fdvu4rjk1x_p = muDoubleScalarSqrt ( jsq1znebmd ) ; } dtjpbfufam_idx_0 = ( (
emqejpczxk + djw4rr1c2t ) * rtP . Wingspan_Value_n3iuon0ekq / ( rtP .
u_Gain_fra5iqtqqa * fdvu4rjk1x_p ) + ( ( dtjpbfufam_idx_0 + jvionhulh2 ) +
khpkfzitiv ) ) * kyavmd5rbl ; mfbasnsgfx *= kyavmd5rbl ; for ( i = 0 ; i < 3
; i ++ ) { rtB . n20ebdvrmd [ i ] = 0.0 ; rtB . n20ebdvrmd [ i ] +=
kk4ijdw44p [ i ] * kcqnzeq3ae ; rtB . n20ebdvrmd [ i ] += kk4ijdw44p [ i + 3
] * dtjpbfufam_idx_0 ; rtB . n20ebdvrmd [ i ] += kk4ijdw44p [ i + 6 ] *
mfbasnsgfx ; } muDoubleScalarSinCos ( 0.017453292519943295 * rtP .
FlatEarthtoLLA_psi , & dtjpbfufam_idx_0 , & kyavmd5rbl ) ; kcqnzeq3ae = rtP .
Constant5_Value [ 0 ] * kyavmd5rbl - rtP . Constant5_Value [ 1 ] *
dtjpbfufam_idx_0 ; mfbasnsgfx = rtP . f_Value - rtP .
Constant_Value_m5g2px2tx2 ; jvionhulh2 = rtP . Constant_Value_cvu4p50c1r -
mfbasnsgfx * mfbasnsgfx ; if ( ssIsMajorTimeStep ( rtS ) ) { if ( rtDW .
pzbp2jg2ny != 0 ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW
. pzbp2jg2ny = 0 ; } mfbasnsgfx = muDoubleScalarSqrt ( jvionhulh2 ) ; } else
if ( jvionhulh2 < 0.0 ) { mfbasnsgfx = - muDoubleScalarSqrt (
muDoubleScalarAbs ( jvionhulh2 ) ) ; rtDW . pzbp2jg2ny = 1 ; } else {
mfbasnsgfx = muDoubleScalarSqrt ( jvionhulh2 ) ; } if ( muDoubleScalarAbs (
rtP . FlatEarthtoLLA_LL0 [ 0 ] ) > rtP . CompareToConstant_const ) {
jvionhulh2 = muDoubleScalarMod ( rtP . FlatEarthtoLLA_LL0 [ 0 ] + rtP .
Bias_Bias , rtP . Constant2_Value_mq0ugbio0d ) + rtP . Bias1_Bias ; } else {
jvionhulh2 = rtP . FlatEarthtoLLA_LL0 [ 0 ] ; } khpkfzitiv =
muDoubleScalarAbs ( jvionhulh2 ) ; if ( khpkfzitiv > rtP .
CompareToConstant_const_lqd2aov4ko ) { jvionhulh2 = ( ( khpkfzitiv + rtP .
Bias_Bias_d2nkgtoec1 ) * rtP . Gain_Gain_hksk452z1z + rtP .
Bias1_Bias_gu4d3m1zk1 ) * muDoubleScalarSign ( jvionhulh2 ) ; } emqejpczxk =
muDoubleScalarSin ( 0.017453292519943295 * jvionhulh2 ) ; emqejpczxk = rtP .
Constant_Value_nc3vt5cgfc - mfbasnsgfx * mfbasnsgfx * emqejpczxk * emqejpczxk
; if ( ssIsMajorTimeStep ( rtS ) ) { if ( rtDW . kxhtuldmhk != 0 ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW . kxhtuldmhk = 0 ;
} djw4rr1c2t = muDoubleScalarSqrt ( emqejpczxk ) ; } else if ( emqejpczxk <
0.0 ) { djw4rr1c2t = - muDoubleScalarSqrt ( muDoubleScalarAbs ( emqejpczxk )
) ; rtDW . kxhtuldmhk = 1 ; } else { djw4rr1c2t = muDoubleScalarSqrt (
emqejpczxk ) ; } djw4rr1c2t = rtP . Constant1_Value_axlwkx0upk / djw4rr1c2t ;
dtjpbfufam_idx_0 = muDoubleScalarAtan2 ( rtP . Constant2_Value , ( rtP .
Constant_Value_ch1bn1coed - mfbasnsgfx * mfbasnsgfx ) * djw4rr1c2t /
emqejpczxk ) * kcqnzeq3ae * 57.295779513082323 + jvionhulh2 ; if (
muDoubleScalarAbs ( dtjpbfufam_idx_0 ) > rtP .
CompareToConstant_const_ohveajuklj ) { dtjpbfufam_idx_0 = muDoubleScalarMod (
dtjpbfufam_idx_0 + rtP . Bias_Bias_kpaulxvgkm , rtP .
Constant2_Value_h4ldodunib ) + rtP . Bias1_Bias_cgno1ebhcg ; } kyavmd5rbl =
muDoubleScalarAbs ( dtjpbfufam_idx_0 ) ; if ( kyavmd5rbl > rtP .
CompareToConstant_const_m35urglgce ) { dtjpbfufam_idx_0 = ( ( kyavmd5rbl +
rtP . Bias_Bias_mvispiykz2 ) * rtP . Gain_Gain_lt1rzsj1bc + rtP .
Bias1_Bias_bohiusfzhl ) * muDoubleScalarSign ( dtjpbfufam_idx_0 ) ; }
jvionhulh2 = dtjpbfufam_idx_0 * 0.017453292519943295 ; emqejpczxk =
mopraowr3n ; dtjpbfufam_idx_0 = muDoubleScalarAbs ( jvionhulh2 ) ; mopraowr3n
= 1.0 ; if ( dtjpbfufam_idx_0 > 3.1415926535897931 ) { if ( jvionhulh2 < -
3.1415926535897931 ) { mopraowr3n = - 1.0 ; } if ( muDoubleScalarIsInf (
dtjpbfufam_idx_0 + 3.1415926535897931 ) ) { kcqnzeq3ae = ( rtNaN ) ; } else {
kcqnzeq3ae = muDoubleScalarRem ( dtjpbfufam_idx_0 + 3.1415926535897931 ,
6.2831853071795862 ) ; rEQ0 = ( kcqnzeq3ae == 0.0 ) ; if ( ! rEQ0 ) {
mfbasnsgfx = ( dtjpbfufam_idx_0 + 3.1415926535897931 ) / 6.2831853071795862 ;
rEQ0 = ! ( muDoubleScalarAbs ( mfbasnsgfx - muDoubleScalarFloor ( mfbasnsgfx
+ 0.5 ) ) > 2.2204460492503131E-16 * mfbasnsgfx ) ; } if ( rEQ0 ) {
kcqnzeq3ae = 0.0 ; } } jvionhulh2 = ( kcqnzeq3ae - 3.1415926535897931 ) *
mopraowr3n ; dtjpbfufam_idx_0 = muDoubleScalarAbs ( jvionhulh2 ) ; } if (
dtjpbfufam_idx_0 > 1.5707963267948966 ) { if ( jvionhulh2 >
1.5707963267948966 ) { jvionhulh2 = 1.5707963267948966 - ( dtjpbfufam_idx_0 -
1.5707963267948966 ) ; } if ( jvionhulh2 < - 1.5707963267948966 ) {
jvionhulh2 = - ( 1.5707963267948966 - ( dtjpbfufam_idx_0 - 1.5707963267948966
) ) ; } } fdvu4rjk1x_p = muDoubleScalarSin ( jvionhulh2 ) ; mopraowr3n =
fdvu4rjk1x_p * fdvu4rjk1x_p ; kcqnzeq3ae = ( ( 1.0 - ( 1.006802597171564 -
2.0 * mopraowr3n / 298.257223563 ) * 2.0 * emqejpczxk / 6.378137E+6 ) + 3.0 *
emqejpczxk * emqejpczxk / 4.0680631590769E+13 ) * ( ( 0.00193185265241 *
mopraowr3n + 1.0 ) * 9.7803253359 / muDoubleScalarSqrt ( 1.0 -
0.00669437999014 * mopraowr3n ) ) ; rtB . dkxpu1nqs1 [ 0 ] = rtP .
Throttle_Gain * rtP . TrimThrust1_Value ; rtB . dkxpu1nqs1 [ 1 ] = rtP .
Throttle_Gain * rtP . TrimThrust2_Value ; rtB . dkxpu1nqs1 [ 2 ] = rtP .
Throttle_Gain * rtP . TrimThrust3_Value ; mopraowr3n = rtP . Gain1_Gain *
muDoubleScalarSin ( rtP . Constant7_Value [ 1 ] ) ; kcqnzeq3ae *= kcqnzeq3ae
; if ( ssIsMajorTimeStep ( rtS ) ) { if ( rtDW . gbrl2nobbn != 0 ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW . gbrl2nobbn = 0 ;
} kyavmd5rbl = muDoubleScalarSqrt ( kcqnzeq3ae ) ; } else if ( kcqnzeq3ae <
0.0 ) { kyavmd5rbl = - muDoubleScalarSqrt ( muDoubleScalarAbs ( kcqnzeq3ae )
) ; rtDW . gbrl2nobbn = 1 ; } else { kyavmd5rbl = muDoubleScalarSqrt (
kcqnzeq3ae ) ; } dtjpbfufam_idx_0 = rtP . mass_Value * kyavmd5rbl ;
kyavmd5rbl = muDoubleScalarCos ( rtP . Constant7_Value [ 1 ] ) ; rtB .
h5b40zrgbx [ 0 ] = mopraowr3n * dtjpbfufam_idx_0 ; rtB . h5b40zrgbx [ 1 ] =
muDoubleScalarSin ( rtP . Constant7_Value [ 0 ] ) * kyavmd5rbl *
dtjpbfufam_idx_0 ; rtB . h5b40zrgbx [ 2 ] = kyavmd5rbl * muDoubleScalarCos (
rtP . Constant7_Value [ 0 ] ) * dtjpbfufam_idx_0 ; UNUSED_PARAMETER ( tid ) ;
} void MdlUpdate ( int_T tid ) { UNUSED_PARAMETER ( tid ) ; } void
MdlUpdateTID1 ( int_T tid ) { UNUSED_PARAMETER ( tid ) ; } void
MdlZeroCrossings ( void ) { { const double * timePtr = ( double * ) rtDW .
ia5ajb52kh . TimePtr ; int_T * zcTimeIndices = & rtDW . d3azz5z2mq [ 0 ] ;
int_T zcTimeIndicesIdx = rtDW . nf3duvwzmk ; ( ( ZCV * )
ssGetSolverZcSignalVector ( rtS ) ) -> k3nj40ncgz = ssGetT ( rtS ) - timePtr
[ zcTimeIndices [ zcTimeIndicesIdx ] ] ; } } void MdlTerminate ( void ) {
rt_FREE ( rtDW . ia5ajb52kh . RSimInfoPtr ) ; if ( rt_slioCatalogue ( ) != (
NULL ) ) { void * * slioCatalogueAddr = rt_slioCatalogueAddr ( ) ;
rtwSaveDatasetsToMatFile ( rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( )
) , rt_GetMatSigstreamLoggingFileName ( ) ) ; rtwTerminateSlioCatalogue (
slioCatalogueAddr ) ; * slioCatalogueAddr = NULL ; } } void
MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS , 0 ) ; ssSetNumY (
rtS , 0 ) ; ssSetNumU ( rtS , 0 ) ; ssSetDirectFeedThrough ( rtS , 0 ) ;
ssSetNumSampleTimes ( rtS , 1 ) ; ssSetNumBlocks ( rtS , 328 ) ;
ssSetNumBlockIO ( rtS , 13 ) ; ssSetNumBlockParams ( rtS , 162 ) ; } void
MdlInitializeSampleTimes ( void ) { ssSetSampleTime ( rtS , 0 , 0.0 ) ;
ssSetOffsetTime ( rtS , 0 , 0.0 ) ; } void raccel_set_checksum ( ) {
ssSetChecksumVal ( rtS , 0 , 252174475U ) ; ssSetChecksumVal ( rtS , 1 ,
3684857294U ) ; ssSetChecksumVal ( rtS , 2 , 833005927U ) ; ssSetChecksumVal
( rtS , 3 , 3066074947U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
SimStruct * raccel_register_model ( void ) { static struct _ssMdlInfo mdlInfo
; ( void ) memset ( ( char * ) rtS , 0 , sizeof ( SimStruct ) ) ; ( void )
memset ( ( char * ) & mdlInfo , 0 , sizeof ( struct _ssMdlInfo ) ) ;
ssSetMdlInfoPtr ( rtS , & mdlInfo ) ; { static time_T mdlPeriod [
NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T
mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ;
static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T
mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits
[ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [
NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) {
mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ;
mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } } ssSetSampleTimePtr ( rtS ,
& mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , &
mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ;
ssSetTNextWasAdjustedPtr ( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ;
ssSetPerTaskSampleHitsPtr ( rtS , & mdlPerTaskSampleHits [ 0 ] ) ;
ssSetTimeOfNextSampleHitPtr ( rtS , & mdlTimeOfNextSampleHit [ 0 ] ) ; }
ssSetSolverMode ( rtS , SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS ,
( ( void * ) & rtB ) ) ; ( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof
( B ) ) ; } { void * dwork = ( void * ) & rtDW ; ssSetRootDWork ( rtS , dwork
) ; ( void ) memset ( dwork , 0 , sizeof ( DW ) ) ; } { static
DataTypeTransInfo dtInfo ; ( void ) memset ( ( char_T * ) & dtInfo , 0 ,
sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS , & dtInfo ) ; dtInfo .
numDataTypes = 14 ; dtInfo . dataTypeSizes = & rtDataTypeSizes [ 0 ] ; dtInfo
. dataTypeNames = & rtDataTypeNames [ 0 ] ; dtInfo . BTransTable = &
rtBTransTable ; dtInfo . PTransTable = & rtPTransTable ; dtInfo .
dataTypeInfoTable = rtDataTypeInfoTable ; } TrimFandM_InitializeDataMapInfo (
) ; ssSetIsRapidAcceleratorActive ( rtS , true ) ; ssSetRootSS ( rtS , rtS )
; ssSetVersion ( rtS , SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS ,
"TrimFandM" ) ; ssSetPath ( rtS , "TrimFandM" ) ; ssSetTStart ( rtS , 0.0 ) ;
ssSetTFinal ( rtS , 10.0 ) ; { static RTWLogInfo rt_DataLoggingInfo ;
rt_DataLoggingInfo . loggingInterval = NULL ; ssSetRTWLogInfo ( rtS , &
rt_DataLoggingInfo ) ; } { rtliSetLogT ( ssGetRTWLogInfo ( rtS ) , "tout" ) ;
rtliSetLogX ( ssGetRTWLogInfo ( rtS ) , "" ) ; rtliSetLogXFinal (
ssGetRTWLogInfo ( rtS ) , "" ) ; rtliSetLogVarNameModifier ( ssGetRTWLogInfo
( rtS ) , "none" ) ; rtliSetLogFormat ( ssGetRTWLogInfo ( rtS ) , 4 ) ;
rtliSetLogMaxRows ( ssGetRTWLogInfo ( rtS ) , 0 ) ; rtliSetLogDecimation (
ssGetRTWLogInfo ( rtS ) , 1 ) ; rtliSetLogY ( ssGetRTWLogInfo ( rtS ) , "" )
; rtliSetLogYSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; } { static
ssSolverInfo slvrInfo ; static uint8_T zcAttributes [ 1 ] = { (
ZC_EVENT_ALL_UP ) } ; ssSetStepSize ( rtS , 0.2 ) ; ssSetMinStepSize ( rtS ,
0.0 ) ; ssSetMaxNumMinSteps ( rtS , - 1 ) ; ssSetMinStepViolatedError ( rtS ,
0 ) ; ssSetMaxStepSize ( rtS , 0.2 ) ; ssSetSolverMaxOrder ( rtS , - 1 ) ;
ssSetSolverRefineFactor ( rtS , 1 ) ; ssSetOutputTimes ( rtS , ( NULL ) ) ;
ssSetNumOutputTimes ( rtS , 0 ) ; ssSetOutputTimesOnly ( rtS , 0 ) ;
ssSetOutputTimesIndex ( rtS , 0 ) ; ssSetZCCacheNeedsReset ( rtS , 0 ) ;
ssSetDerivCacheNeedsReset ( rtS , 0 ) ; ssSetNumNonContDerivSigInfos ( rtS ,
0 ) ; ssSetNonContDerivSigInfos ( rtS , ( NULL ) ) ; ssSetSolverInfo ( rtS ,
& slvrInfo ) ; ssSetSolverName ( rtS , "VariableStepDiscrete" ) ;
ssSetVariableStepSolver ( rtS , 1 ) ; ssSetSolverConsistencyChecking ( rtS ,
0 ) ; ssSetSolverAdaptiveZcDetection ( rtS , 0 ) ;
ssSetSolverRobustResetMethod ( rtS , 0 ) ; ssSetSolverStateProjection ( rtS ,
0 ) ; ssSetSolverMassMatrixType ( rtS , ( ssMatrixType ) 0 ) ;
ssSetSolverMassMatrixNzMax ( rtS , 0 ) ; ssSetModelOutputs ( rtS , MdlOutputs
) ; ssSetModelLogData ( rtS , rt_UpdateTXYLogVars ) ;
ssSetModelLogDataIfInInterval ( rtS , rt_UpdateTXXFYLogVars ) ;
ssSetModelUpdate ( rtS , MdlUpdate ) ; ssSetSolverZcSignalAttrib ( rtS ,
zcAttributes ) ; ssSetSolverNumZcSignals ( rtS , 1 ) ;
ssSetModelZeroCrossings ( rtS , MdlZeroCrossings ) ;
ssSetSolverConsecutiveZCsStepRelTol ( rtS , 2.8421709430404007E-13 ) ;
ssSetSolverMaxConsecutiveZCs ( rtS , 1000 ) ; ssSetSolverConsecutiveZCsError
( rtS , 2 ) ; ssSetSolverMaskedZcDiagnostic ( rtS , 1 ) ;
ssSetSolverIgnoredZcDiagnostic ( rtS , 1 ) ; ssSetTNextTid ( rtS , INT_MIN )
; ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ;
ssSetNumNonsampledZCs ( rtS , 1 ) ; } ssSetChecksumVal ( rtS , 0 , 252174475U
) ; ssSetChecksumVal ( rtS , 1 , 3684857294U ) ; ssSetChecksumVal ( rtS , 2 ,
833005927U ) ; ssSetChecksumVal ( rtS , 3 , 3066074947U ) ; { static const
sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo
rt_ExtModeInfo ; static const sysRanDType * systemRan [ 1 ] ;
gblRTWExtModeInfo = & rt_ExtModeInfo ; ssSetRTWExtModeInfo ( rtS , &
rt_ExtModeInfo ) ; rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo ,
systemRan ) ; systemRan [ 0 ] = & rtAlwaysEnabled ;
rteiSetModelMappingInfoPtr ( ssGetRTWExtModeInfo ( rtS ) , &
ssGetModelMappingInfo ( rtS ) ) ; rteiSetChecksumsPtr ( ssGetRTWExtModeInfo (
rtS ) , ssGetChecksums ( rtS ) ) ; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS )
, ssGetTPtr ( rtS ) ) ; } return rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = 1 ; void MdlOutputsParameterSampleTime (
int_T tid ) { MdlOutputsTID1 ( tid ) ; }
