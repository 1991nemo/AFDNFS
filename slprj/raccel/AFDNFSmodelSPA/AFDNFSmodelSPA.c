#include "rt_logging_mmi.h"
#include "AFDNFSmodelSPA_capi.h"
#include <math.h>
#include "AFDNFSmodelSPA.h"
#include "AFDNFSmodelSPA_private.h"
#include "AFDNFSmodelSPA_dt.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; extern boolean_T
gblExtModeStartPktReceived ; void raccelForceExtModeShutdown ( ) { if ( !
gblExtModeStartPktReceived ) { boolean_T stopRequested = false ;
rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 2 , & stopRequested ) ; }
rtExtModeShutdown ( 2 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 5 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 0 ; int_T gbl_raccel_NumST = 3 ; const char_T
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
"slprj\\raccel\\AFDNFSmodelSPA\\AFDNFSmodelSPA_Jpattern.mat" ; const int_T
gblNumRootInportBlks = 0 ; const int_T gblNumModelInputs = 0 ; extern
rtInportTUtable * gblInportTUtables ; extern const char * gblInportFileName ;
extern void * gblAperiodicPartitionHitTimes ; const int_T
gblInportDataTypeIdx [ ] = { - 1 } ; const int_T gblInportDims [ ] = { - 1 }
; const int_T gblInportComplex [ ] = { - 1 } ; const int_T
gblInportInterpoFlag [ ] = { - 1 } ; const int_T gblInportContinuous [ ] = {
- 1 } ; int_T enableFcnCallFlag [ ] = { 1 , 1 , 1 } ; const char *
raccelLoadInputsAndAperiodicHitTimes ( const char * inportFileName , int *
matFileFormat ) { return rt_RapidReadInportsMatFile ( inportFileName ,
matFileFormat , 1 ) ; }
#include "simstruc.h"
#include "fixedpoint.h"
B rtB ; X rtX ; DW rtDW ; static SimStruct model_S ; SimStruct * const rtS =
& model_S ; void rt_mldivide_U1d3x3_U2d3x1_Yd3x1_snf ( const real_T u0 [ 9 ]
, const real_T u1 [ 3 ] , real_T y [ 3 ] ) { real_T A [ 9 ] ; int32_T r1 ;
int32_T r2 ; int32_T r3 ; real_T maxval ; real_T a21 ; int32_T rtemp ; memcpy
( & A [ 0 ] , & u0 [ 0 ] , 9U * sizeof ( real_T ) ) ; r1 = 0 ; r2 = 1 ; r3 =
2 ; maxval = muDoubleScalarAbs ( u0 [ 0 ] ) ; a21 = muDoubleScalarAbs ( u0 [
1 ] ) ; if ( a21 > maxval ) { maxval = a21 ; r1 = 1 ; r2 = 0 ; } if (
muDoubleScalarAbs ( u0 [ 2 ] ) > maxval ) { r1 = 2 ; r2 = 1 ; r3 = 0 ; } A [
r2 ] = u0 [ r2 ] / u0 [ r1 ] ; A [ r3 ] /= A [ r1 ] ; A [ r2 + 3 ] -= A [ r1
+ 3 ] * A [ r2 ] ; A [ r3 + 3 ] -= A [ r1 + 3 ] * A [ r3 ] ; A [ r2 + 6 ] -=
A [ r1 + 6 ] * A [ r2 ] ; A [ r3 + 6 ] -= A [ r1 + 6 ] * A [ r3 ] ; if (
muDoubleScalarAbs ( A [ r3 + 3 ] ) > muDoubleScalarAbs ( A [ r2 + 3 ] ) ) {
rtemp = r2 + 1 ; r2 = r3 ; r3 = rtemp - 1 ; } A [ r3 + 3 ] /= A [ r2 + 3 ] ;
A [ r3 + 6 ] -= A [ r3 + 3 ] * A [ r2 + 6 ] ; y [ 1 ] = u1 [ r2 ] - u1 [ r1 ]
* A [ r2 ] ; y [ 2 ] = ( u1 [ r3 ] - u1 [ r1 ] * A [ r3 ] ) - A [ r3 + 3 ] *
y [ 1 ] ; y [ 2 ] /= A [ r3 + 6 ] ; y [ 0 ] = u1 [ r1 ] - A [ r1 + 6 ] * y [
2 ] ; y [ 1 ] -= A [ r2 + 6 ] * y [ 2 ] ; y [ 1 ] /= A [ r2 + 3 ] ; y [ 0 ]
-= A [ r1 + 3 ] * y [ 1 ] ; y [ 0 ] /= A [ r1 ] ; } void MdlInitialize ( void
) { boolean_T tmp ; rtDW . j5skdyoj5i = 1 ; if ( ssIsFirstInitCond ( rtS ) )
{ rtX . hkxwzleotw [ 0 ] = 0.0 ; rtX . hkxwzleotw [ 1 ] = 0.0 ; rtX .
hkxwzleotw [ 2 ] = 0.0 ; tmp = slIsRapidAcceleratorSimulating ( ) ; if ( tmp
) { tmp = ssGetGlobalInitialStatesAvailable ( rtS ) ; rtDW . j5skdyoj5i = !
tmp ; } else { rtDW . j5skdyoj5i = 1 ; } rtX . md4byhppt3 [ 0 ] = 0.0 ; rtX .
md4byhppt3 [ 1 ] = 0.0 ; rtX . md4byhppt3 [ 2 ] = 0.0 ; } rtDW . hwhk0plcbm =
1 ; if ( ssIsFirstInitCond ( rtS ) ) { tmp = slIsRapidAcceleratorSimulating (
) ; if ( tmp ) { tmp = ssGetGlobalInitialStatesAvailable ( rtS ) ; rtDW .
hwhk0plcbm = ! tmp ; } else { rtDW . hwhk0plcbm = 1 ; } rtX . jwktqmf5nt [ 0
] = 0.0 ; rtX . jwktqmf5nt [ 1 ] = 0.0 ; rtX . jwktqmf5nt [ 2 ] = 0.0 ; }
rtDW . dgdkommmsd = 1 ; if ( ssIsFirstInitCond ( rtS ) ) { tmp =
slIsRapidAcceleratorSimulating ( ) ; if ( tmp ) { tmp =
ssGetGlobalInitialStatesAvailable ( rtS ) ; rtDW . dgdkommmsd = ! tmp ; }
else { rtDW . dgdkommmsd = 1 ; } rtX . a2thzvctjt [ 0 ] = 0.0 ; rtX .
a2thzvctjt [ 1 ] = 0.0 ; rtX . a2thzvctjt [ 2 ] = 0.0 ; } rtDW . j4k0h2foay =
1 ; if ( ssIsFirstInitCond ( rtS ) ) { tmp = slIsRapidAcceleratorSimulating (
) ; if ( tmp ) { tmp = ssGetGlobalInitialStatesAvailable ( rtS ) ; rtDW .
j4k0h2foay = ! tmp ; } else { rtDW . j4k0h2foay = 1 ; } rtX . papl5plp0u =
0.0 ; } rtX . ag4giqb3jg = 0.0 ; rtDW . kv4lnrjne2 = 1 ; if (
ssIsFirstInitCond ( rtS ) ) { tmp = slIsRapidAcceleratorSimulating ( ) ; if (
tmp ) { tmp = ssGetGlobalInitialStatesAvailable ( rtS ) ; rtDW . kv4lnrjne2 =
! tmp ; } else { rtDW . kv4lnrjne2 = 1 ; } } rtX . kzigeirre3 = 0.0 ; } void
MdlStart ( void ) { { void * * slioCatalogueAddr = rt_slioCatalogueAddr ( ) ;
void * r2 = ( NULL ) ; void * * pOSigstreamManagerAddr = ( NULL ) ; const int
maxErrorBufferSize = 16384 ; char errMsgCreatingOSigstreamManager [ 16384 ] ;
bool errorCreatingOSigstreamManager = false ; const char *
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
externalInputIsInDatasetFormat ) { } } { int_T dimensions [ 1 ] = { 3 } ;
rtDW . ayqwng4oox . LoggedData = rt_CreateLogVar ( ssGetRTWLogInfo ( rtS ) ,
ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( & ssGetErrorStatus ( rtS
) ) , "euler_angles" , SS_DOUBLE , 0 , 0 , 0 , 3 , 1 , dimensions ,
NO_LOGVALDIMS , ( NULL ) , ( NULL ) , 0 , 1 , 0.0 , 1 ) ; if ( rtDW .
ayqwng4oox . LoggedData == ( NULL ) ) return ; } { int_T dimensions [ 1 ] = {
3 } ; rtDW . l0rvcjwiw5 . LoggedData = rt_CreateLogVar ( ssGetRTWLogInfo (
rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , ( &
ssGetErrorStatus ( rtS ) ) , "ned_position" , SS_DOUBLE , 0 , 0 , 0 , 3 , 1 ,
dimensions , NO_LOGVALDIMS , ( NULL ) , ( NULL ) , 0 , 1 , 0.0 , 1 ) ; if (
rtDW . l0rvcjwiw5 . LoggedData == ( NULL ) ) return ; } { int_T dimensions [
1 ] = { 4 } ; rtDW . juhedu4p0x . LoggedData = rt_CreateLogVar (
ssGetRTWLogInfo ( rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , (
& ssGetErrorStatus ( rtS ) ) , "control_commands" , SS_DOUBLE , 0 , 0 , 0 , 4
, 1 , dimensions , NO_LOGVALDIMS , ( NULL ) , ( NULL ) , 0 , 1 , 0.0 , 1 ) ;
if ( rtDW . juhedu4p0x . LoggedData == ( NULL ) ) return ; } rtDW .
dkeirtfvst = 0 ; rtDW . arnvx1x5wb = 0 ; rtB . bh40mgxfug = rtP .
Constant_Value_ki5yoscsu1 ; rtB . ft1rv4ttnm [ 0 ] = rtP . Constant4_Value [
0 ] ; rtB . hbmslxdafy [ 0 ] = rtP . Constant6_Value [ 0 ] ; rtB . lnbo3dn5b5
[ 0 ] = rtP . Constant7_Value [ 0 ] ; rtB . mai2btwwwy [ 0 ] = rtP .
Constant8_Value [ 0 ] ; rtB . ft1rv4ttnm [ 1 ] = rtP . Constant4_Value [ 1 ]
; rtB . hbmslxdafy [ 1 ] = rtP . Constant6_Value [ 1 ] ; rtB . lnbo3dn5b5 [ 1
] = rtP . Constant7_Value [ 1 ] ; rtB . mai2btwwwy [ 1 ] = rtP .
Constant8_Value [ 1 ] ; rtB . ft1rv4ttnm [ 2 ] = rtP . Constant4_Value [ 2 ]
; rtB . hbmslxdafy [ 2 ] = rtP . Constant6_Value [ 2 ] ; rtB . lnbo3dn5b5 [ 2
] = rtP . Constant7_Value [ 2 ] ; rtB . mai2btwwwy [ 2 ] = rtP .
Constant8_Value [ 2 ] ; rtDW . i3ztellsjl = 0 ; { FWksInfo * fromwksInfo ; if
( ( fromwksInfo = ( FWksInfo * ) calloc ( 1 , sizeof ( FWksInfo ) ) ) == (
NULL ) ) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName = "tuvar" ; fromwksInfo -> origDataTypeId
= 0 ; fromwksInfo -> origIsComplex = 0 ; fromwksInfo -> origWidth = 1 ;
fromwksInfo -> origElSize = sizeof ( real_T ) ; fromwksInfo -> data = ( void
* ) rtP . FromWs_Data0 ; fromwksInfo -> nDataPoints = 13 ; fromwksInfo ->
time = ( double * ) rtP . FromWs_Time0 ; rtDW . nyrbrzpro5 . TimePtr =
fromwksInfo -> time ; rtDW . nyrbrzpro5 . DataPtr = fromwksInfo -> data ;
rtDW . nyrbrzpro5 . RSimInfoPtr = fromwksInfo ; } rtDW . kue5d1kul0 .
PrevIndex = 0 ; { int_T * zcTimeIndices = & rtDW . bn4dbem3va [ 0 ] ; const
double * timePoints = ( double * ) rtDW . nyrbrzpro5 . TimePtr ; boolean_T
justHadZcTime = false ; int_T zcIdx = 0 ; int_T i ; for ( i = 0 ; i < 13 - 1
; i ++ ) { if ( ! justHadZcTime && timePoints [ i ] == timePoints [ i + 1 ] )
{ zcTimeIndices [ zcIdx ++ ] = i ; justHadZcTime = true ; } else {
justHadZcTime = false ; } } rtDW . kwtny14ets = 0 ; } } { FWksInfo *
fromwksInfo ; if ( ( fromwksInfo = ( FWksInfo * ) calloc ( 1 , sizeof (
FWksInfo ) ) ) == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName = "tuvar" ; fromwksInfo -> origDataTypeId
= 0 ; fromwksInfo -> origIsComplex = 0 ; fromwksInfo -> origWidth = 1 ;
fromwksInfo -> origElSize = sizeof ( real_T ) ; fromwksInfo -> data = ( void
* ) rtP . FromWs_Data0_epwwwxrf5p ; fromwksInfo -> nDataPoints = 9 ;
fromwksInfo -> time = ( double * ) rtP . FromWs_Time0_elms23aku5 ; rtDW .
knfsqkbog3 . TimePtr = fromwksInfo -> time ; rtDW . knfsqkbog3 . DataPtr =
fromwksInfo -> data ; rtDW . knfsqkbog3 . RSimInfoPtr = fromwksInfo ; } rtDW
. exkkab2tvc . PrevIndex = 0 ; } { FWksInfo * fromwksInfo ; if ( (
fromwksInfo = ( FWksInfo * ) calloc ( 1 , sizeof ( FWksInfo ) ) ) == ( NULL )
) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName = "tuvar" ; fromwksInfo -> origDataTypeId
= 0 ; fromwksInfo -> origIsComplex = 0 ; fromwksInfo -> origWidth = 1 ;
fromwksInfo -> origElSize = sizeof ( real_T ) ; fromwksInfo -> data = ( void
* ) rtP . FromWs_Data0_gk1j2xmtdn ; fromwksInfo -> nDataPoints = 13 ;
fromwksInfo -> time = ( double * ) rtP . FromWs_Time0_dbgr3faoo4 ; rtDW .
k2h3rugqu1 . TimePtr = fromwksInfo -> time ; rtDW . k2h3rugqu1 . DataPtr =
fromwksInfo -> data ; rtDW . k2h3rugqu1 . RSimInfoPtr = fromwksInfo ; } rtDW
. m2zkbzyhlz . PrevIndex = 0 ; { int_T * zcTimeIndices = & rtDW . c2y55kstcc
[ 0 ] ; const double * timePoints = ( double * ) rtDW . k2h3rugqu1 . TimePtr
; boolean_T justHadZcTime = false ; int_T zcIdx = 0 ; int_T i ; for ( i = 0 ;
i < 13 - 1 ; i ++ ) { if ( ! justHadZcTime && timePoints [ i ] == timePoints
[ i + 1 ] ) { zcTimeIndices [ zcIdx ++ ] = i ; justHadZcTime = true ; } else
{ justHadZcTime = false ; } } rtDW . bfzneoincq = 0 ; } } { FWksInfo *
fromwksInfo ; if ( ( fromwksInfo = ( FWksInfo * ) calloc ( 1 , sizeof (
FWksInfo ) ) ) == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName = "tuvar" ; fromwksInfo -> origDataTypeId
= 0 ; fromwksInfo -> origIsComplex = 0 ; fromwksInfo -> origWidth = 1 ;
fromwksInfo -> origElSize = sizeof ( real_T ) ; fromwksInfo -> data = ( void
* ) rtP . FromWs_Data0_pabez3hm0f ; fromwksInfo -> nDataPoints = 13 ;
fromwksInfo -> time = ( double * ) rtP . FromWs_Time0_l0kcnhlhti ; rtDW .
hcmwiu4oc2 . TimePtr = fromwksInfo -> time ; rtDW . hcmwiu4oc2 . DataPtr =
fromwksInfo -> data ; rtDW . hcmwiu4oc2 . RSimInfoPtr = fromwksInfo ; } rtDW
. jqiesixgdv . PrevIndex = 0 ; { int_T * zcTimeIndices = & rtDW . lgjhv10zvc
[ 0 ] ; const double * timePoints = ( double * ) rtDW . hcmwiu4oc2 . TimePtr
; boolean_T justHadZcTime = false ; int_T zcIdx = 0 ; int_T i ; for ( i = 0 ;
i < 13 - 1 ; i ++ ) { if ( ! justHadZcTime && timePoints [ i ] == timePoints
[ i + 1 ] ) { zcTimeIndices [ zcIdx ++ ] = i ; justHadZcTime = true ; } else
{ justHadZcTime = false ; } } rtDW . aivemugqf1 = 0 ; } } rtDW . kdajnepqa5 =
0 ; rtDW . euxjrceybc = 0 ; rtDW . lq4r04u54d = 0 ; { FWksInfo * fromwksInfo
; if ( ( fromwksInfo = ( FWksInfo * ) calloc ( 1 , sizeof ( FWksInfo ) ) ) ==
( NULL ) ) { ssSetErrorStatus ( rtS ,
"from workspace STRING(Name) memory allocation error" ) ; } else {
fromwksInfo -> origWorkspaceVarName = "tuvar" ; fromwksInfo -> origDataTypeId
= 0 ; fromwksInfo -> origIsComplex = 0 ; fromwksInfo -> origWidth = 1 ;
fromwksInfo -> origElSize = sizeof ( real_T ) ; fromwksInfo -> data = ( void
* ) rtP . FromWs_Data0_hempjedlcs ; fromwksInfo -> nDataPoints = 6 ;
fromwksInfo -> time = ( double * ) rtP . FromWs_Time0_i2ajdr5pty ; rtDW .
ezztmokhxt . TimePtr = fromwksInfo -> time ; rtDW . ezztmokhxt . DataPtr =
fromwksInfo -> data ; rtDW . ezztmokhxt . RSimInfoPtr = fromwksInfo ; } rtDW
. dfcv1ogrid . PrevIndex = 0 ; { int_T * zcTimeIndices = & rtDW . auwndvyfpq
[ 0 ] ; const double * timePoints = ( double * ) rtDW . ezztmokhxt . TimePtr
; boolean_T justHadZcTime = false ; int_T zcIdx = 0 ; int_T i ; for ( i = 0 ;
i < 6 - 1 ; i ++ ) { if ( ! justHadZcTime && timePoints [ i ] == timePoints [
i + 1 ] ) { zcTimeIndices [ zcIdx ++ ] = i ; justHadZcTime = true ; } else {
justHadZcTime = false ; } } rtDW . hqdpuh5bh4 = 0 ; } } rtDW . jro3w2jetk = 0
; rtDW . fciwvikpdr = 0 ; rtDW . n5ngktfrhq = 0 ; rtDW . dxc22zb0w3 = 0 ;
rtDW . mqarvij1wr = - 1 ; MdlInitialize ( ) ; } void MdlOutputs ( int_T tid )
{ real_T gdtjsop22x ; real_T cm14bug4k0 ; real_T gzalpjf3ls ; real_T
d45dppdybq ; real_T h0f0nzijlv ; boolean_T rEQ0 ; real_T gs11owd144 [ 3 ] ;
real_T nfadndiksa [ 3 ] ; real_T hp5pw2ydpn ; real_T brocf3ytq0 ; real_T
ixdhbjnct0 ; int8_T rtAction ; int8_T rtPrevAction ; real_T igxneew1le ;
real_T nfwdvadjxh ; real_T hlrngpk0qn [ 9 ] ; real_T ggbjmbjroo ; real_T
evub4310g5 ; real_T kdx1mgofh3 ; real_T bg2cz1r4a0 ; real_T tmp [ 5 ] ;
real_T tmp_p [ 2 ] ; real_T ikf1a42anw_p [ 3 ] ; real_T ikf1a42anw_e [ 3 ] ;
real_T tmp_e [ 3 ] ; real_T kzghw22rl3_p ; int32_T i ; int32_T i_p ; real_T
ikf1a42anw_idx_2 ; real_T ikf1a42anw_idx_1 ; real_T ikf1a42anw_idx_0 ; real_T
hcjz2yyqjx_idx_3 ; real_T hcjz2yyqjx_idx_2 ; real_T hcjz2yyqjx_idx_0 ;
srClearBC ( rtDW . f5ilhbx002 ) ; if ( rtDW . j5skdyoj5i != 0 ) { rtX .
hkxwzleotw [ 0 ] = rtB . ft1rv4ttnm [ 0 ] ; rtX . hkxwzleotw [ 1 ] = rtB .
ft1rv4ttnm [ 1 ] ; rtX . hkxwzleotw [ 2 ] = rtB . ft1rv4ttnm [ 2 ] ; } rtB .
mbeszndpzw [ 0 ] = rtX . hkxwzleotw [ 0 ] ; rtB . mbeszndpzw [ 1 ] = rtX .
hkxwzleotw [ 1 ] ; rtB . mbeszndpzw [ 2 ] = rtX . hkxwzleotw [ 2 ] ; if (
rtDW . hwhk0plcbm != 0 ) { rtX . md4byhppt3 [ 0 ] = rtB . hbmslxdafy [ 0 ] ;
rtX . md4byhppt3 [ 1 ] = rtB . hbmslxdafy [ 1 ] ; rtX . md4byhppt3 [ 2 ] =
rtB . hbmslxdafy [ 2 ] ; } ikf1a42anw_idx_0 = rtX . md4byhppt3 [ 0 ] ; rtB .
pxlcyjc0py [ 0 ] = rtP . Gain2_Gain_ntnvl1cqpn * rtX . md4byhppt3 [ 0 ] ;
ikf1a42anw_idx_1 = rtX . md4byhppt3 [ 1 ] ; rtB . pxlcyjc0py [ 1 ] = rtP .
Gain2_Gain_ntnvl1cqpn * rtX . md4byhppt3 [ 1 ] ; ikf1a42anw_idx_2 = rtX .
md4byhppt3 [ 2 ] ; rtB . pxlcyjc0py [ 2 ] = rtP . Gain2_Gain_ntnvl1cqpn * rtX
. md4byhppt3 [ 2 ] ; igxneew1le = muDoubleScalarAtan ( 1.0 / rtB . mbeszndpzw
[ 0 ] * rtB . mbeszndpzw [ 2 ] ) ; ggbjmbjroo = muDoubleScalarCos (
igxneew1le ) ; kzghw22rl3_p = ( rtB . mbeszndpzw [ 0 ] * rtB . mbeszndpzw [ 0
] + rtB . mbeszndpzw [ 1 ] * rtB . mbeszndpzw [ 1 ] ) + rtB . mbeszndpzw [ 2
] * rtB . mbeszndpzw [ 2 ] ; if ( ssIsMajorTimeStep ( rtS ) ) { if ( rtDW .
i3ztellsjl != 0 ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW
. i3ztellsjl = 0 ; } ixdhbjnct0 = muDoubleScalarSqrt ( kzghw22rl3_p ) ; }
else if ( kzghw22rl3_p < 0.0 ) { ixdhbjnct0 = - muDoubleScalarSqrt (
muDoubleScalarAbs ( kzghw22rl3_p ) ) ; rtDW . i3ztellsjl = 1 ; } else {
ixdhbjnct0 = muDoubleScalarSqrt ( kzghw22rl3_p ) ; } kzghw22rl3_p = rtB .
mbeszndpzw [ 1 ] / ixdhbjnct0 ; if ( kzghw22rl3_p > 1.0 ) { kzghw22rl3_p =
1.0 ; } else { if ( kzghw22rl3_p < - 1.0 ) { kzghw22rl3_p = - 1.0 ; } }
kzghw22rl3_p = muDoubleScalarAsin ( kzghw22rl3_p ) ; bg2cz1r4a0 = rtP .
ChSign2_Gain * kzghw22rl3_p ; evub4310g5 = muDoubleScalarCos ( bg2cz1r4a0 ) ;
hlrngpk0qn [ 0 ] = ggbjmbjroo * evub4310g5 ; bg2cz1r4a0 = muDoubleScalarSin (
bg2cz1r4a0 ) ; hlrngpk0qn [ 1 ] = ggbjmbjroo * bg2cz1r4a0 * rtP . ChSign_Gain
; kdx1mgofh3 = muDoubleScalarSin ( igxneew1le ) ; hlrngpk0qn [ 2 ] = rtP .
ChSign1_Gain * kdx1mgofh3 ; hlrngpk0qn [ 3 ] = bg2cz1r4a0 ; hlrngpk0qn [ 4 ]
= evub4310g5 ; hlrngpk0qn [ 5 ] = rtP . Zero_Value ; hlrngpk0qn [ 6 ] =
kdx1mgofh3 * evub4310g5 ; hlrngpk0qn [ 7 ] = kdx1mgofh3 * bg2cz1r4a0 * rtP .
ChSign2_Gain_blrwynkzlu ; hlrngpk0qn [ 8 ] = ggbjmbjroo ; rtB . ddodrccvry =
( rtB . mbeszndpzw [ 0 ] * rtB . mbeszndpzw [ 0 ] + rtB . mbeszndpzw [ 1 ] *
rtB . mbeszndpzw [ 1 ] ) + rtB . mbeszndpzw [ 2 ] * rtB . mbeszndpzw [ 2 ] ;
if ( ssIsMajorTimeStep ( rtS ) ) { rtDW . hgmvbytvsp = ( rtB . ddodrccvry >=
0.0 ) ; } if ( rtDW . dgdkommmsd != 0 ) { rtX . jwktqmf5nt [ 0 ] = rtB .
mai2btwwwy [ 0 ] ; rtX . jwktqmf5nt [ 1 ] = rtB . mai2btwwwy [ 1 ] ; rtX .
jwktqmf5nt [ 2 ] = rtB . mai2btwwwy [ 2 ] ; } rtB . prll55li14 [ 0 ] = rtX .
jwktqmf5nt [ 0 ] ; rtB . prll55li14 [ 1 ] = rtX . jwktqmf5nt [ 1 ] ; rtB .
prll55li14 [ 2 ] = rtX . jwktqmf5nt [ 2 ] ; rtB . jxiqnugoaw = - rtB .
prll55li14 [ 2 ] - rtP . RefAlt_Value ; if ( ssIsMajorTimeStep ( rtS ) ) {
rtDW . fb0tpkibfq = rtB . jxiqnugoaw >= rtP .
Limitaltitudetotroposhere_UpperSat ? 1 : rtB . jxiqnugoaw > rtP .
Limitaltitudetotroposhere_LowerSat ? 0 : - 1 ; } brocf3ytq0 = rtP .
SeaLevelTemperature_Value - ( rtDW . fb0tpkibfq == 1 ? rtP .
Limitaltitudetotroposhere_UpperSat : rtDW . fb0tpkibfq == - 1 ? rtP .
Limitaltitudetotroposhere_LowerSat : rtB . jxiqnugoaw ) * rtP .
LapseRate_Gain ; ggbjmbjroo = rtP . uT0_Gain * brocf3ytq0 ; rtB . hjeoespy50
= rtP . AltitudeofTroposphere_Value - rtB . jxiqnugoaw ; if (
ssIsMajorTimeStep ( rtS ) ) { rtDW . nslzihk2f5 = rtB . hjeoespy50 >= rtP .
LimitaltitudetoStratosphere_UpperSat ? 1 : rtB . hjeoespy50 > rtP .
LimitaltitudetoStratosphere_LowerSat ? 0 : - 1 ; } if ( ( ggbjmbjroo < 0.0 )
&& ( rtP . gLR_Value > muDoubleScalarFloor ( rtP . gLR_Value ) ) ) {
evub4310g5 = - muDoubleScalarPower ( - ggbjmbjroo , rtP . gLR_Value ) ; }
else { evub4310g5 = muDoubleScalarPower ( ggbjmbjroo , rtP . gLR_Value ) ; }
ggbjmbjroo = muDoubleScalarExp ( ( rtDW . nslzihk2f5 == 1 ? rtP .
LimitaltitudetoStratosphere_UpperSat : rtDW . nslzihk2f5 == - 1 ? rtP .
LimitaltitudetoStratosphere_LowerSat : rtB . hjeoespy50 ) * rtP . gR_Gain * (
1.0 / brocf3ytq0 ) ) * ( evub4310g5 / ggbjmbjroo * rtP . rho0_Gain ) * rtP .
Gain_Gain_d31dqzkeif * ( rtDW . hgmvbytvsp > 0 ? rtB . ddodrccvry : - rtB .
ddodrccvry ) ; evub4310g5 = ggbjmbjroo * rtP . WingArea_Value ; bg2cz1r4a0 =
rtP . cLalpha_Gain * igxneew1le ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtDW
. hveldcssno = ( ssGetTaskTime ( rtS , 1 ) >= rtP . Doublet_T_start ) ; rtDW
. ef2fks3n4u = ( ssGetTaskTime ( rtS , 1 ) >= rtP . Doublet_span / 2.0 + rtP
. Doublet_T_start ) ; rtDW . o3c1xdpheq = ( ssGetTaskTime ( rtS , 1 ) >= rtP
. Doublet_span / 2.0 + rtP . Doublet_T_start ) ; rtDW . amfzu1el4q = (
ssGetTaskTime ( rtS , 1 ) >= rtP . Doublet_T_start + rtP . Doublet_span ) ;
if ( rtDW . hveldcssno == 1 ) { nfwdvadjxh = rtP . Doublet_amp ; } else {
nfwdvadjxh = rtP . Step_Y0 ; } if ( rtDW . ef2fks3n4u == 1 ) {
hcjz2yyqjx_idx_0 = rtP . Doublet_amp ; } else { hcjz2yyqjx_idx_0 = rtP .
Step1_Y0 ; } if ( rtDW . o3c1xdpheq == 1 ) { kdx1mgofh3 = - rtP . Doublet_amp
; } else { kdx1mgofh3 = rtP . Step2_Y0 ; } if ( rtDW . amfzu1el4q == 1 ) {
hcjz2yyqjx_idx_2 = - rtP . Doublet_amp ; } else { hcjz2yyqjx_idx_2 = rtP .
Step3_Y0 ; } rtB . lf41qcir2i = ( ( nfwdvadjxh - hcjz2yyqjx_idx_0 ) + (
kdx1mgofh3 - hcjz2yyqjx_idx_2 ) ) + rtP . Constant2_Value_bvlfok2r5u ; } {
real_T * pDataValues = ( real_T * ) rtDW . nyrbrzpro5 . DataPtr ; real_T *
pTimeValues = ( real_T * ) rtDW . nyrbrzpro5 . TimePtr ; int_T currTimeIndex
= rtDW . kue5d1kul0 . PrevIndex ; real_T t = ssGetTaskTime ( rtS , 0 ) ; int
numPoints , lastPoint ; FWksInfo * fromwksInfo = ( FWksInfo * ) rtDW .
nyrbrzpro5 . RSimInfoPtr ; numPoints = fromwksInfo -> nDataPoints ; lastPoint
= numPoints - 1 ; if ( t <= pTimeValues [ 0 ] ) { currTimeIndex = 0 ; } else
if ( t >= pTimeValues [ lastPoint ] ) { currTimeIndex = lastPoint - 1 ; }
else { if ( t < pTimeValues [ currTimeIndex ] ) { while ( t < pTimeValues [
currTimeIndex ] ) { currTimeIndex -- ; } } else { while ( t >= pTimeValues [
currTimeIndex + 1 ] ) { currTimeIndex ++ ; } } } rtDW . kue5d1kul0 .
PrevIndex = currTimeIndex ; { real_T t1 = pTimeValues [ currTimeIndex ] ;
real_T t2 = pTimeValues [ currTimeIndex + 1 ] ; if ( t1 == t2 ) { if ( t < t1
) { gdtjsop22x = pDataValues [ currTimeIndex ] ; } else { gdtjsop22x =
pDataValues [ currTimeIndex + 1 ] ; } } else { real_T f1 = ( t2 - t ) / ( t2
- t1 ) ; real_T f2 = 1.0 - f1 ; real_T d1 ; real_T d2 ; int_T TimeIndex =
currTimeIndex ; int_T * zcTimeIndices = & rtDW . bn4dbem3va [ 0 ] ; int_T *
zcTimeIndicesIdx = & rtDW . kwtny14ets ; int_T zcIdx = zcTimeIndices [ *
zcTimeIndicesIdx ] ; int_T numZcTimes = 4 ; if ( * zcTimeIndicesIdx <
numZcTimes ) { if ( ssIsMajorTimeStep ( rtS ) ) { if ( t > pTimeValues [
zcIdx ] ) { while ( * zcTimeIndicesIdx < ( numZcTimes - 1 ) && ( t >
pTimeValues [ zcIdx ] ) ) { ( * zcTimeIndicesIdx ) ++ ; zcIdx = zcTimeIndices
[ * zcTimeIndicesIdx ] ; } } } else { if ( t >= pTimeValues [ zcIdx ] && (
ssGetTimeOfLastOutput ( rtS ) < pTimeValues [ zcIdx ] ) ) { t2 = pTimeValues
[ zcIdx ] ; if ( zcIdx == 0 ) { TimeIndex = 0 ; t1 = t2 - 1 ; } else { t1 =
pTimeValues [ zcIdx - 1 ] ; TimeIndex = zcIdx - 1 ; } f1 = ( t2 - t ) / ( t2
- t1 ) ; f2 = 1.0 - f1 ; } } } d1 = pDataValues [ TimeIndex ] ; d2 =
pDataValues [ TimeIndex + 1 ] ; if ( zcIdx == 0 ) { d2 = d1 ; } gdtjsop22x =
( real_T ) rtInterpolate ( d1 , d2 , f1 , f2 ) ; pDataValues += numPoints ; }
} } { real_T * pDataValues = ( real_T * ) rtDW . knfsqkbog3 . DataPtr ;
real_T * pTimeValues = ( real_T * ) rtDW . knfsqkbog3 . TimePtr ; int_T
currTimeIndex = rtDW . exkkab2tvc . PrevIndex ; real_T t = ssGetTaskTime (
rtS , 0 ) ; int numPoints , lastPoint ; FWksInfo * fromwksInfo = ( FWksInfo *
) rtDW . knfsqkbog3 . RSimInfoPtr ; numPoints = fromwksInfo -> nDataPoints ;
lastPoint = numPoints - 1 ; if ( t <= pTimeValues [ 0 ] ) { currTimeIndex = 0
; } else if ( t >= pTimeValues [ lastPoint ] ) { currTimeIndex = lastPoint -
1 ; } else { if ( t < pTimeValues [ currTimeIndex ] ) { while ( t <
pTimeValues [ currTimeIndex ] ) { currTimeIndex -- ; } } else { while ( t >=
pTimeValues [ currTimeIndex + 1 ] ) { currTimeIndex ++ ; } } } rtDW .
exkkab2tvc . PrevIndex = currTimeIndex ; { real_T t1 = pTimeValues [
currTimeIndex ] ; real_T t2 = pTimeValues [ currTimeIndex + 1 ] ; if ( t1 ==
t2 ) { if ( t < t1 ) { cm14bug4k0 = pDataValues [ currTimeIndex ] ; } else {
cm14bug4k0 = pDataValues [ currTimeIndex + 1 ] ; } } else { real_T f1 = ( t2
- t ) / ( t2 - t1 ) ; real_T f2 = 1.0 - f1 ; real_T d1 ; real_T d2 ; int_T
TimeIndex = currTimeIndex ; d1 = pDataValues [ TimeIndex ] ; d2 = pDataValues
[ TimeIndex + 1 ] ; cm14bug4k0 = ( real_T ) rtInterpolate ( d1 , d2 , f1 , f2
) ; pDataValues += numPoints ; } } } { real_T * pDataValues = ( real_T * )
rtDW . k2h3rugqu1 . DataPtr ; real_T * pTimeValues = ( real_T * ) rtDW .
k2h3rugqu1 . TimePtr ; int_T currTimeIndex = rtDW . m2zkbzyhlz . PrevIndex ;
real_T t = ssGetTaskTime ( rtS , 0 ) ; int numPoints , lastPoint ; FWksInfo *
fromwksInfo = ( FWksInfo * ) rtDW . k2h3rugqu1 . RSimInfoPtr ; numPoints =
fromwksInfo -> nDataPoints ; lastPoint = numPoints - 1 ; if ( t <=
pTimeValues [ 0 ] ) { currTimeIndex = 0 ; } else if ( t >= pTimeValues [
lastPoint ] ) { currTimeIndex = lastPoint - 1 ; } else { if ( t < pTimeValues
[ currTimeIndex ] ) { while ( t < pTimeValues [ currTimeIndex ] ) {
currTimeIndex -- ; } } else { while ( t >= pTimeValues [ currTimeIndex + 1 ]
) { currTimeIndex ++ ; } } } rtDW . m2zkbzyhlz . PrevIndex = currTimeIndex ;
{ real_T t1 = pTimeValues [ currTimeIndex ] ; real_T t2 = pTimeValues [
currTimeIndex + 1 ] ; if ( t1 == t2 ) { if ( t < t1 ) { gzalpjf3ls =
pDataValues [ currTimeIndex ] ; } else { gzalpjf3ls = pDataValues [
currTimeIndex + 1 ] ; } } else { real_T f1 = ( t2 - t ) / ( t2 - t1 ) ;
real_T f2 = 1.0 - f1 ; real_T d1 ; real_T d2 ; int_T TimeIndex =
currTimeIndex ; int_T * zcTimeIndices = & rtDW . c2y55kstcc [ 0 ] ; int_T *
zcTimeIndicesIdx = & rtDW . bfzneoincq ; int_T zcIdx = zcTimeIndices [ *
zcTimeIndicesIdx ] ; int_T numZcTimes = 4 ; if ( * zcTimeIndicesIdx <
numZcTimes ) { if ( ssIsMajorTimeStep ( rtS ) ) { if ( t > pTimeValues [
zcIdx ] ) { while ( * zcTimeIndicesIdx < ( numZcTimes - 1 ) && ( t >
pTimeValues [ zcIdx ] ) ) { ( * zcTimeIndicesIdx ) ++ ; zcIdx = zcTimeIndices
[ * zcTimeIndicesIdx ] ; } } } else { if ( t >= pTimeValues [ zcIdx ] && (
ssGetTimeOfLastOutput ( rtS ) < pTimeValues [ zcIdx ] ) ) { t2 = pTimeValues
[ zcIdx ] ; if ( zcIdx == 0 ) { TimeIndex = 0 ; t1 = t2 - 1 ; } else { t1 =
pTimeValues [ zcIdx - 1 ] ; TimeIndex = zcIdx - 1 ; } f1 = ( t2 - t ) / ( t2
- t1 ) ; f2 = 1.0 - f1 ; } } } d1 = pDataValues [ TimeIndex ] ; d2 =
pDataValues [ TimeIndex + 1 ] ; if ( zcIdx == 0 ) { d2 = d1 ; } gzalpjf3ls =
( real_T ) rtInterpolate ( d1 , d2 , f1 , f2 ) ; pDataValues += numPoints ; }
} } { real_T * pDataValues = ( real_T * ) rtDW . hcmwiu4oc2 . DataPtr ;
real_T * pTimeValues = ( real_T * ) rtDW . hcmwiu4oc2 . TimePtr ; int_T
currTimeIndex = rtDW . jqiesixgdv . PrevIndex ; real_T t = ssGetTaskTime (
rtS , 0 ) ; int numPoints , lastPoint ; FWksInfo * fromwksInfo = ( FWksInfo *
) rtDW . hcmwiu4oc2 . RSimInfoPtr ; numPoints = fromwksInfo -> nDataPoints ;
lastPoint = numPoints - 1 ; if ( t <= pTimeValues [ 0 ] ) { currTimeIndex = 0
; } else if ( t >= pTimeValues [ lastPoint ] ) { currTimeIndex = lastPoint -
1 ; } else { if ( t < pTimeValues [ currTimeIndex ] ) { while ( t <
pTimeValues [ currTimeIndex ] ) { currTimeIndex -- ; } } else { while ( t >=
pTimeValues [ currTimeIndex + 1 ] ) { currTimeIndex ++ ; } } } rtDW .
jqiesixgdv . PrevIndex = currTimeIndex ; { real_T t1 = pTimeValues [
currTimeIndex ] ; real_T t2 = pTimeValues [ currTimeIndex + 1 ] ; if ( t1 ==
t2 ) { if ( t < t1 ) { d45dppdybq = pDataValues [ currTimeIndex ] ; } else {
d45dppdybq = pDataValues [ currTimeIndex + 1 ] ; } } else { real_T f1 = ( t2
- t ) / ( t2 - t1 ) ; real_T f2 = 1.0 - f1 ; real_T d1 ; real_T d2 ; int_T
TimeIndex = currTimeIndex ; int_T * zcTimeIndices = & rtDW . lgjhv10zvc [ 0 ]
; int_T * zcTimeIndicesIdx = & rtDW . aivemugqf1 ; int_T zcIdx =
zcTimeIndices [ * zcTimeIndicesIdx ] ; int_T numZcTimes = 4 ; if ( *
zcTimeIndicesIdx < numZcTimes ) { if ( ssIsMajorTimeStep ( rtS ) ) { if ( t >
pTimeValues [ zcIdx ] ) { while ( * zcTimeIndicesIdx < ( numZcTimes - 1 ) &&
( t > pTimeValues [ zcIdx ] ) ) { ( * zcTimeIndicesIdx ) ++ ; zcIdx =
zcTimeIndices [ * zcTimeIndicesIdx ] ; } } } else { if ( t >= pTimeValues [
zcIdx ] && ( ssGetTimeOfLastOutput ( rtS ) < pTimeValues [ zcIdx ] ) ) { t2 =
pTimeValues [ zcIdx ] ; if ( zcIdx == 0 ) { TimeIndex = 0 ; t1 = t2 - 1 ; }
else { t1 = pTimeValues [ zcIdx - 1 ] ; TimeIndex = zcIdx - 1 ; } f1 = ( t2 -
t ) / ( t2 - t1 ) ; f2 = 1.0 - f1 ; } } } d1 = pDataValues [ TimeIndex ] ; d2
= pDataValues [ TimeIndex + 1 ] ; if ( zcIdx == 0 ) { d2 = d1 ; } d45dppdybq
= ( real_T ) rtInterpolate ( d1 , d2 , f1 , f2 ) ; pDataValues += numPoints ;
} } } if ( rtP . ManualSwitch2_CurrentSetting == 1 ) { if ( rtP .
ManualSwitch_CurrentSetting == 1 ) { if ( rtP . ManualSwitch1_CurrentSetting
== 1 ) { hcjz2yyqjx_idx_0 = rtB . lf41qcir2i ; kdx1mgofh3 = rtP .
Constant_Value_iltbyzakku [ 0 ] ; hcjz2yyqjx_idx_2 = rtP .
Constant_Value_iltbyzakku [ 1 ] ; hcjz2yyqjx_idx_3 = rtP .
Constant_Value_iltbyzakku [ 2 ] ; } else { hcjz2yyqjx_idx_0 = ( rtP .
Gain_Gain_mxsmwhuwrc * gdtjsop22x + rtP . Constant2_Value_ol34lh25j4 ) * rtP
. Gain7_Gain ; kdx1mgofh3 = ( rtP . Gain1_Gain * cm14bug4k0 + rtP .
Constant1_Value_of0klte1gr ) * rtP . Gain6_Gain ; hcjz2yyqjx_idx_2 = ( rtP .
Gain2_Gain * gzalpjf3ls + rtP . Constant3_Value_ey1nyz4g22 ) * rtP .
Gain5_Gain ; hcjz2yyqjx_idx_3 = ( rtP . Gain3_Gain * d45dppdybq + rtP .
Constant4_Value_iwlbmt1pf3 ) * rtP . Gain4_Gain ; } } else { hcjz2yyqjx_idx_0
= rtP . FreePlant_Value [ 0 ] ; kdx1mgofh3 = rtP . FreePlant_Value [ 1 ] ;
hcjz2yyqjx_idx_2 = rtP . FreePlant_Value [ 2 ] ; hcjz2yyqjx_idx_3 = rtP .
FreePlant_Value [ 3 ] ; } } else { hcjz2yyqjx_idx_0 = rtP .
ControlledPlant_Value [ 0 ] ; kdx1mgofh3 = rtP . ControlledPlant_Value [ 1 ]
; hcjz2yyqjx_idx_2 = rtP . ControlledPlant_Value [ 2 ] ; hcjz2yyqjx_idx_3 =
rtP . ControlledPlant_Value [ 3 ] ; } if ( rtDW . j4k0h2foay != 0 ) { rtX .
a2thzvctjt [ 0 ] = rtB . lnbo3dn5b5 [ 0 ] ; rtX . a2thzvctjt [ 1 ] = rtB .
lnbo3dn5b5 [ 1 ] ; rtX . a2thzvctjt [ 2 ] = rtB . lnbo3dn5b5 [ 2 ] ; } rtB .
g2bzvajzvm [ 0 ] = rtX . a2thzvctjt [ 0 ] ; rtB . g2bzvajzvm [ 1 ] = rtX .
a2thzvctjt [ 1 ] ; rtB . g2bzvajzvm [ 2 ] = rtX . a2thzvctjt [ 2 ] ; rtB .
nxlyj2r2ke = rtB . dorju0mbfg - rtB . g2bzvajzvm [ 1 ] ; rtB . igulonupg4 = (
( ( ( rtP . Constant1_Value_aja1fvk5dn [ 0 ] - rtB . mbeszndpzw [ 0 ] ) * rtP
. LongLQR_Gain [ 0 ] + ( rtP . Constant1_Value_aja1fvk5dn [ 1 ] - rtB .
mbeszndpzw [ 2 ] ) * rtP . LongLQR_Gain [ 1 ] ) + rtP . LongLQR_Gain [ 2 ] *
ikf1a42anw_idx_1 ) + rtP . LongLQR_Gain [ 3 ] * rtB . nxlyj2r2ke ) * rtP .
Gain_Gain_is0it0xd34 ; if ( ssIsMajorTimeStep ( rtS ) ) { rtDW . gdmux55hjy =
rtB . igulonupg4 >= rtP . Saturation1_UpperSat ? 1 : rtB . igulonupg4 > rtP .
Saturation1_LowerSat ? 0 : - 1 ; } tmp [ 0 ] = rtP .
Constant2_Value_gm0og1aigu - rtB . mbeszndpzw [ 1 ] ; tmp [ 1 ] =
ikf1a42anw_idx_0 ; tmp [ 2 ] = ikf1a42anw_idx_2 ; tmp [ 3 ] = rtB .
g2bzvajzvm [ 0 ] ; tmp [ 4 ] = rtB . g2bzvajzvm [ 2 ] ; for ( i_p = 0 ; i_p <
2 ; i_p ++ ) { tmp_p [ i_p ] = 0.0 ; for ( i = 0 ; i < 5 ; i ++ ) { tmp_p [
i_p ] += rtP . LatLQR_Gain [ ( i << 1 ) + i_p ] * tmp [ i ] ; } rtB .
iluz41jmye [ i_p ] = rtP . Gain1_Gain_mfxdzqt1sa * tmp_p [ i_p ] ; } if (
ssIsMajorTimeStep ( rtS ) ) { rtDW . csi2mijlzp [ 0 ] = rtB . iluz41jmye [ 0
] >= rtP . Saturation2_UpperSat ? 1 : rtB . iluz41jmye [ 0 ] > rtP .
Saturation2_LowerSat ? 0 : - 1 ; rtDW . csi2mijlzp [ 1 ] = rtB . iluz41jmye [
1 ] >= rtP . Saturation2_UpperSat ? 1 : rtB . iluz41jmye [ 1 ] > rtP .
Saturation2_LowerSat ? 0 : - 1 ; } if ( rtP .
ManualSwitch1_CurrentSetting_g2n2m14h1o == 1 ) { nfwdvadjxh = rtDW .
gdmux55hjy == 1 ? rtP . Saturation1_UpperSat : rtDW . gdmux55hjy == - 1 ? rtP
. Saturation1_LowerSat : rtB . igulonupg4 ; } else { nfwdvadjxh = rtP .
Constant2_Value_eiuvnldjii [ 0 ] ; } rtB . lbzm4w3kvc [ 0 ] =
hcjz2yyqjx_idx_0 + nfwdvadjxh ; if ( rtP .
ManualSwitch1_CurrentSetting_g2n2m14h1o == 1 ) { nfwdvadjxh = rtP . dF_Value
; } else { nfwdvadjxh = rtP . Constant2_Value_eiuvnldjii [ 1 ] ; } rtB .
lbzm4w3kvc [ 1 ] = kdx1mgofh3 + nfwdvadjxh ; if ( rtP .
ManualSwitch1_CurrentSetting_g2n2m14h1o == 1 ) { nfwdvadjxh = rtDW .
csi2mijlzp [ 0 ] == 1 ? rtP . Saturation2_UpperSat : rtDW . csi2mijlzp [ 0 ]
== - 1 ? rtP . Saturation2_LowerSat : rtB . iluz41jmye [ 0 ] ; } else {
nfwdvadjxh = rtP . Constant2_Value_eiuvnldjii [ 2 ] ; } rtB . lbzm4w3kvc [ 2
] = hcjz2yyqjx_idx_2 + nfwdvadjxh ; if ( rtP .
ManualSwitch1_CurrentSetting_g2n2m14h1o == 1 ) { nfwdvadjxh = rtDW .
csi2mijlzp [ 1 ] == 1 ? rtP . Saturation2_UpperSat : rtDW . csi2mijlzp [ 1 ]
== - 1 ? rtP . Saturation2_LowerSat : rtB . iluz41jmye [ 1 ] ; } else {
nfwdvadjxh = rtP . Constant2_Value_eiuvnldjii [ 3 ] ; } rtB . lbzm4w3kvc [ 3
] = hcjz2yyqjx_idx_3 + nfwdvadjxh ; kdx1mgofh3 = rtP . cLdelta_e_Gain * rtB .
lbzm4w3kvc [ 0 ] ; nfwdvadjxh = rtP . cLdelta_f_Gain * rtB . lbzm4w3kvc [ 1 ]
; hcjz2yyqjx_idx_0 = rtP . TransferFcn_C * rtX . ag4giqb3jg ;
hcjz2yyqjx_idx_2 = rtP . cLalphadot_Gain * hcjz2yyqjx_idx_0 ;
hcjz2yyqjx_idx_3 = rtP . cLq_Gain * ikf1a42anw_idx_1 ; hp5pw2ydpn = ( rtB .
mbeszndpzw [ 0 ] * rtB . mbeszndpzw [ 0 ] + rtB . mbeszndpzw [ 1 ] * rtB .
mbeszndpzw [ 1 ] ) + rtB . mbeszndpzw [ 2 ] * rtB . mbeszndpzw [ 2 ] ; if (
ssIsMajorTimeStep ( rtS ) ) { if ( rtDW . kdajnepqa5 != 0 ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW . kdajnepqa5 = 0 ;
} hp5pw2ydpn = muDoubleScalarSqrt ( hp5pw2ydpn ) ; } else if ( hp5pw2ydpn <
0.0 ) { hp5pw2ydpn = - muDoubleScalarSqrt ( muDoubleScalarAbs ( hp5pw2ydpn )
) ; rtDW . kdajnepqa5 = 1 ; } else { hp5pw2ydpn = muDoubleScalarSqrt (
hp5pw2ydpn ) ; } hcjz2yyqjx_idx_2 = ( hcjz2yyqjx_idx_2 + hcjz2yyqjx_idx_3 ) *
rtP . LiftCoefficient_meanchord / ( rtP . u_Gain * hp5pw2ydpn ) ; brocf3ytq0
*= rtP . gammaR_Gain ; if ( ssIsMajorTimeStep ( rtS ) ) { if ( rtDW .
euxjrceybc != 0 ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW
. euxjrceybc = 0 ; } hcjz2yyqjx_idx_3 = muDoubleScalarSqrt ( brocf3ytq0 ) ; }
else if ( brocf3ytq0 < 0.0 ) { hcjz2yyqjx_idx_3 = - muDoubleScalarSqrt (
muDoubleScalarAbs ( brocf3ytq0 ) ) ; rtDW . euxjrceybc = 1 ; } else {
hcjz2yyqjx_idx_3 = muDoubleScalarSqrt ( brocf3ytq0 ) ; } ixdhbjnct0 /=
hcjz2yyqjx_idx_3 ; kdx1mgofh3 = ( ( ( ( rtP . LiftCoefficient_cL0 +
bg2cz1r4a0 ) + kdx1mgofh3 ) + nfwdvadjxh ) + hcjz2yyqjx_idx_2 ) + rtP .
CLM_Gain * ixdhbjnct0 ; rtB . odqjhpytke = rtP . cDalpha_Gain * igxneew1le ;
rtB . n51upk5du5 = rtP . cDdelta_f_Gain * rtB . lbzm4w3kvc [ 1 ] ; if (
ssIsMajorTimeStep ( rtS ) ) { rtDW . h43rirlooy = ( rtB . odqjhpytke >= 0.0 )
; } rtB . b4lvv4thsq = rtP . cDdelta_e_Gain * rtB . lbzm4w3kvc [ 0 ] ; if (
ssIsMajorTimeStep ( rtS ) ) { rtDW . jk5xksjzsk = ( rtB . n51upk5du5 >= 0.0 )
; } rtB . j4qce2ejgk = rtP . cDdelta_a_Gain * rtB . lbzm4w3kvc [ 2 ] ; if (
ssIsMajorTimeStep ( rtS ) ) { rtDW . eb0yxld54a = ( rtB . b4lvv4thsq >= 0.0 )
; } rtB . j2ppwxwj2v = rtP . cDdelta_r_Gain * rtB . lbzm4w3kvc [ 3 ] ; if (
ssIsMajorTimeStep ( rtS ) ) { rtDW . d4kppgermp = ( rtB . j4qce2ejgk >= 0.0 )
; rtDW . awptayczte = ( rtB . j2ppwxwj2v >= 0.0 ) ; } bg2cz1r4a0 = ( ( ( ( (
( ( kdx1mgofh3 * kdx1mgofh3 * rtP . InducedDrag_Gain + rtP .
DragCoefficient_cD0 ) + ( rtDW . h43rirlooy > 0 ? rtB . odqjhpytke : - rtB .
odqjhpytke ) ) + ( rtDW . jk5xksjzsk > 0 ? rtB . n51upk5du5 : - rtB .
n51upk5du5 ) ) + ( rtDW . eb0yxld54a > 0 ? rtB . b4lvv4thsq : - rtB .
b4lvv4thsq ) ) + ( rtDW . d4kppgermp > 0 ? rtB . j4qce2ejgk : - rtB .
j4qce2ejgk ) ) + ( rtDW . awptayczte > 0 ? rtB . j2ppwxwj2v : - rtB .
j2ppwxwj2v ) ) + rtP . cDM_Gain * ixdhbjnct0 ) * rtP . ChSign_Gain_pd02wcxouh
; nfwdvadjxh = rtP . cYbeta_Gain * kzghw22rl3_p ; brocf3ytq0 = rtP .
cYdelta_a_Gain * rtB . lbzm4w3kvc [ 2 ] ; hcjz2yyqjx_idx_2 = rtP .
cYdelta_r_Gain * rtB . lbzm4w3kvc [ 3 ] ; hcjz2yyqjx_idx_3 = rtP . cYp_Gain *
ikf1a42anw_idx_0 + rtP . cYr_Gain * ikf1a42anw_idx_2 ; hp5pw2ydpn = ( rtB .
mbeszndpzw [ 0 ] * rtB . mbeszndpzw [ 0 ] + rtB . mbeszndpzw [ 1 ] * rtB .
mbeszndpzw [ 1 ] ) + rtB . mbeszndpzw [ 2 ] * rtB . mbeszndpzw [ 2 ] ; if (
ssIsMajorTimeStep ( rtS ) ) { if ( rtDW . lq4r04u54d != 0 ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW . lq4r04u54d = 0 ;
} hp5pw2ydpn = muDoubleScalarSqrt ( hp5pw2ydpn ) ; } else if ( hp5pw2ydpn <
0.0 ) { hp5pw2ydpn = - muDoubleScalarSqrt ( muDoubleScalarAbs ( hp5pw2ydpn )
) ; rtDW . lq4r04u54d = 1 ; } else { hp5pw2ydpn = muDoubleScalarSqrt (
hp5pw2ydpn ) ; } nfwdvadjxh = ( ( nfwdvadjxh + brocf3ytq0 ) +
hcjz2yyqjx_idx_2 ) + hcjz2yyqjx_idx_3 * rtP . Wingspan_Value / ( rtP .
u_Gain_pb5qen5bq2 * hp5pw2ydpn ) ; kdx1mgofh3 *= rtP .
ChSign1_Gain_jgqy0alfoa ; { real_T * pDataValues = ( real_T * ) rtDW .
ezztmokhxt . DataPtr ; real_T * pTimeValues = ( real_T * ) rtDW . ezztmokhxt
. TimePtr ; int_T currTimeIndex = rtDW . dfcv1ogrid . PrevIndex ; real_T t =
ssGetTaskTime ( rtS , 0 ) ; int numPoints , lastPoint ; FWksInfo *
fromwksInfo = ( FWksInfo * ) rtDW . ezztmokhxt . RSimInfoPtr ; numPoints =
fromwksInfo -> nDataPoints ; lastPoint = numPoints - 1 ; if ( t <=
pTimeValues [ 0 ] ) { currTimeIndex = 0 ; } else if ( t >= pTimeValues [
lastPoint ] ) { currTimeIndex = lastPoint - 1 ; } else { if ( t < pTimeValues
[ currTimeIndex ] ) { while ( t < pTimeValues [ currTimeIndex ] ) {
currTimeIndex -- ; } } else { while ( t >= pTimeValues [ currTimeIndex + 1 ]
) { currTimeIndex ++ ; } } } rtDW . dfcv1ogrid . PrevIndex = currTimeIndex ;
{ real_T t1 = pTimeValues [ currTimeIndex ] ; real_T t2 = pTimeValues [
currTimeIndex + 1 ] ; if ( t1 == t2 ) { if ( t < t1 ) { h0f0nzijlv =
pDataValues [ currTimeIndex ] ; } else { h0f0nzijlv = pDataValues [
currTimeIndex + 1 ] ; } } else { real_T f1 = ( t2 - t ) / ( t2 - t1 ) ;
real_T f2 = 1.0 - f1 ; real_T d1 ; real_T d2 ; int_T TimeIndex =
currTimeIndex ; int_T * zcTimeIndices = & rtDW . auwndvyfpq [ 0 ] ; int_T *
zcTimeIndicesIdx = & rtDW . hqdpuh5bh4 ; int_T zcIdx = zcTimeIndices [ *
zcTimeIndicesIdx ] ; int_T numZcTimes = 2 ; if ( * zcTimeIndicesIdx <
numZcTimes ) { if ( ssIsMajorTimeStep ( rtS ) ) { if ( t > pTimeValues [
zcIdx ] ) { while ( * zcTimeIndicesIdx < ( numZcTimes - 1 ) && ( t >
pTimeValues [ zcIdx ] ) ) { ( * zcTimeIndicesIdx ) ++ ; zcIdx = zcTimeIndices
[ * zcTimeIndicesIdx ] ; } } } else { if ( t >= pTimeValues [ zcIdx ] && (
ssGetTimeOfLastOutput ( rtS ) < pTimeValues [ zcIdx ] ) ) { t2 = pTimeValues
[ zcIdx ] ; if ( zcIdx == 0 ) { TimeIndex = 0 ; t1 = t2 - 1 ; } else { t1 =
pTimeValues [ zcIdx - 1 ] ; TimeIndex = zcIdx - 1 ; } f1 = ( t2 - t ) / ( t2
- t1 ) ; f2 = 1.0 - f1 ; } } } d1 = pDataValues [ TimeIndex ] ; d2 =
pDataValues [ TimeIndex + 1 ] ; if ( zcIdx == 0 ) { d2 = d1 ; } h0f0nzijlv =
( real_T ) rtInterpolate ( d1 , d2 , f1 , f2 ) ; pDataValues += numPoints ; }
} } if ( rtP . ManualSwitch_CurrentSetting_mbegp1wenu == 1 ) { brocf3ytq0 =
h0f0nzijlv ; } else { brocf3ytq0 = rtP . TrimThrust4_Value ; } bg2cz1r4a0 *=
evub4310g5 ; nfwdvadjxh *= evub4310g5 ; kdx1mgofh3 *= evub4310g5 ; for ( i_p
= 0 ; i_p < 3 ; i_p ++ ) { nfadndiksa [ i_p ] = rtB . gor1ljyslz [ i_p ] *
brocf3ytq0 + ( hlrngpk0qn [ i_p + 6 ] * kdx1mgofh3 + ( hlrngpk0qn [ i_p + 3 ]
* nfwdvadjxh + hlrngpk0qn [ i_p ] * bg2cz1r4a0 ) ) ; } evub4310g5 = rtP .
Gain1_Gain_jlinvxtcyq * muDoubleScalarSin ( rtB . g2bzvajzvm [ 1 ] ) ;
kdx1mgofh3 = muDoubleScalarCos ( rtB . g2bzvajzvm [ 1 ] ) ; bg2cz1r4a0 =
muDoubleScalarSin ( rtB . g2bzvajzvm [ 0 ] ) * kdx1mgofh3 ; kdx1mgofh3 *=
muDoubleScalarCos ( rtB . g2bzvajzvm [ 0 ] ) ; rtB . puqzbadmna [ 0 ] = ( rtB
. prll55li14 [ 0 ] * rtB . fqj3t5j0hs - rtB . prll55li14 [ 1 ] * rtB .
ladmdwvset ) * rtB . hcthdqledv * 57.295779513082323 + rtB . l4k2a5bsh4 ; rtB
. puqzbadmna [ 1 ] = ( rtB . prll55li14 [ 0 ] * rtB . ladmdwvset + rtB .
prll55li14 [ 1 ] * rtB . fqj3t5j0hs ) * rtB . n5jin1c2zm * 57.295779513082323
+ rtB . kzv3jtixuu ; if ( ssIsMajorTimeStep ( rtS ) ) { rtDW . chwk0ea5er = (
rtB . puqzbadmna [ 0 ] >= 0.0 ) ; } rtB . p43ilaklx2 = rtDW . chwk0ea5er > 0
? rtB . puqzbadmna [ 0 ] : - rtB . puqzbadmna [ 0 ] ; if ( ssIsSampleHit (
rtS , 1 , 0 ) ) { if ( ssIsMajorTimeStep ( rtS ) ) { rtDW . ligunf0r1k = (
rtB . p43ilaklx2 > rtP . CompareToConstant_const_b0xas2jkq3 ) ; } rtB .
ar551zz3kn = rtDW . ligunf0r1k ; } if ( rtB . ar551zz3kn ) { rtB . ebdsowrcxw
= muDoubleScalarMod ( rtB . puqzbadmna [ 0 ] + rtP . Bias_Bias_egwxvvuqi5 ,
rtP . Constant2_Value ) + rtP . Bias1_Bias_hhxbgizgvm ; } else { rtB .
ebdsowrcxw = rtB . puqzbadmna [ 0 ] ; } if ( ssIsSampleHit ( rtS , 1 , 0 ) )
{ if ( rtB . ebdsowrcxw > 0.0 ) { rtDW . hmcvrdlbiw = 1 ; } else if ( rtB .
ebdsowrcxw < 0.0 ) { rtDW . hmcvrdlbiw = - 1 ; } else { rtDW . hmcvrdlbiw = 0
; } rtB . aa5dhjvrml = rtDW . hmcvrdlbiw ; } if ( ssIsMajorTimeStep ( rtS ) )
{ rtDW . mujtalxvpm = ( rtB . ebdsowrcxw >= 0.0 ) ; } rtB . fl2tbgohhi = rtDW
. mujtalxvpm > 0 ? rtB . ebdsowrcxw : - rtB . ebdsowrcxw ; if ( ssIsSampleHit
( rtS , 1 , 0 ) ) { if ( ssIsMajorTimeStep ( rtS ) ) { rtDW . mug4q33r34 = (
rtB . fl2tbgohhi > rtP . CompareToConstant_const ) ; } rtB . ku1qygrkrl =
rtDW . mug4q33r34 ; if ( rtB . ku1qygrkrl ) { rtB . kf1oc12ha5 = rtP .
Constant_Value_o10wbquf15 ; } else { rtB . kf1oc12ha5 = rtP . Constant1_Value
; } } rtB . ltejiu1rdi = rtB . kf1oc12ha5 + rtB . puqzbadmna [ 1 ] ; if (
ssIsMajorTimeStep ( rtS ) ) { rtDW . kxe4uaswic = ( rtB . ltejiu1rdi >= 0.0 )
; } rtB . nc2kd2edsn = rtDW . kxe4uaswic > 0 ? rtB . ltejiu1rdi : - rtB .
ltejiu1rdi ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { if ( ssIsMajorTimeStep (
rtS ) ) { rtDW . bzoc2ge3pm = ( rtB . nc2kd2edsn > rtP .
CompareToConstant_const_kmoxadnhb5 ) ; } rtB . ao5xxbupqa = rtDW . bzoc2ge3pm
; } if ( rtB . ku1qygrkrl ) { nfwdvadjxh = ( ( rtB . fl2tbgohhi + rtP .
Bias_Bias ) * rtP . Gain_Gain + rtP . Bias1_Bias ) * rtB . aa5dhjvrml ; }
else { nfwdvadjxh = rtB . ebdsowrcxw ; } hp5pw2ydpn = nfwdvadjxh *
0.017453292519943295 ; brocf3ytq0 = muDoubleScalarAbs ( hp5pw2ydpn ) ;
nfwdvadjxh = 1.0 ; if ( brocf3ytq0 > 3.1415926535897931 ) { if ( hp5pw2ydpn <
- 3.1415926535897931 ) { nfwdvadjxh = - 1.0 ; } if ( muDoubleScalarIsInf (
brocf3ytq0 + 3.1415926535897931 ) ) { hcjz2yyqjx_idx_3 = ( rtNaN ) ; } else {
hcjz2yyqjx_idx_3 = muDoubleScalarRem ( brocf3ytq0 + 3.1415926535897931 ,
6.2831853071795862 ) ; rEQ0 = ( hcjz2yyqjx_idx_3 == 0.0 ) ; if ( ! rEQ0 ) {
hp5pw2ydpn = ( brocf3ytq0 + 3.1415926535897931 ) / 6.2831853071795862 ; rEQ0
= ! ( muDoubleScalarAbs ( hp5pw2ydpn - muDoubleScalarFloor ( hp5pw2ydpn + 0.5
) ) > 2.2204460492503131E-16 * hp5pw2ydpn ) ; } if ( rEQ0 ) {
hcjz2yyqjx_idx_3 = 0.0 ; } } hp5pw2ydpn = ( hcjz2yyqjx_idx_3 -
3.1415926535897931 ) * nfwdvadjxh ; brocf3ytq0 = muDoubleScalarAbs (
hp5pw2ydpn ) ; } if ( brocf3ytq0 > 1.5707963267948966 ) { if ( hp5pw2ydpn >
1.5707963267948966 ) { hp5pw2ydpn = 1.5707963267948966 - ( brocf3ytq0 -
1.5707963267948966 ) ; } if ( hp5pw2ydpn < - 1.5707963267948966 ) {
hp5pw2ydpn = - ( 1.5707963267948966 - ( brocf3ytq0 - 1.5707963267948966 ) ) ;
} } brocf3ytq0 = muDoubleScalarSin ( hp5pw2ydpn ) ; nfwdvadjxh = brocf3ytq0 *
brocf3ytq0 ; gs11owd144 [ 2 ] = ( ( 1.0 - ( 1.006802597171564 - 2.0 *
nfwdvadjxh / 298.257223563 ) * 2.0 * rtB . jxiqnugoaw / 6.378137E+6 ) + 3.0 *
rtB . jxiqnugoaw * rtB . jxiqnugoaw / 4.0680631590769E+13 ) * ( (
0.00193185265241 * nfwdvadjxh + 1.0 ) * 9.7803253359 / muDoubleScalarSqrt (
1.0 - 0.00669437999014 * nfwdvadjxh ) ) ; brocf3ytq0 = gs11owd144 [ 2 ] *
gs11owd144 [ 2 ] ; if ( ssIsMajorTimeStep ( rtS ) ) { if ( rtDW . jro3w2jetk
!= 0 ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW .
jro3w2jetk = 0 ; } brocf3ytq0 = muDoubleScalarSqrt ( brocf3ytq0 ) ; } else if
( brocf3ytq0 < 0.0 ) { brocf3ytq0 = - muDoubleScalarSqrt ( muDoubleScalarAbs
( brocf3ytq0 ) ) ; rtDW . jro3w2jetk = 1 ; } else { brocf3ytq0 =
muDoubleScalarSqrt ( brocf3ytq0 ) ; } nfwdvadjxh = rtP . mass_Value *
brocf3ytq0 ; rtB . paumsm4ucv [ 0 ] = evub4310g5 * nfwdvadjxh + nfadndiksa [
0 ] ; rtB . paumsm4ucv [ 1 ] = bg2cz1r4a0 * nfwdvadjxh + nfadndiksa [ 1 ] ;
rtB . paumsm4ucv [ 2 ] = kdx1mgofh3 * nfwdvadjxh + nfadndiksa [ 2 ] ; if (
rtDW . kv4lnrjne2 != 0 ) { rtX . papl5plp0u = rtB . bh40mgxfug ; } evub4310g5
= rtP . Constant1_Value_old4tikkcg / rtX . papl5plp0u ; rtB . pd3h1ffkcz [ 0
] = ( rtB . paumsm4ucv [ 0 ] / rtX . papl5plp0u - evub4310g5 * rtB .
mbeszndpzw [ 0 ] ) - ( ikf1a42anw_idx_1 * rtB . mbeszndpzw [ 2 ] -
ikf1a42anw_idx_2 * rtB . mbeszndpzw [ 1 ] ) ; rtB . pd3h1ffkcz [ 1 ] = ( rtB
. paumsm4ucv [ 1 ] / rtX . papl5plp0u - evub4310g5 * rtB . mbeszndpzw [ 1 ] )
- ( ikf1a42anw_idx_2 * rtB . mbeszndpzw [ 0 ] - ikf1a42anw_idx_0 * rtB .
mbeszndpzw [ 2 ] ) ; rtB . pd3h1ffkcz [ 2 ] = ( rtB . paumsm4ucv [ 2 ] / rtX
. papl5plp0u - evub4310g5 * rtB . mbeszndpzw [ 2 ] ) - ( ikf1a42anw_idx_0 *
rtB . mbeszndpzw [ 1 ] - ikf1a42anw_idx_1 * rtB . mbeszndpzw [ 0 ] ) ;
evub4310g5 = muDoubleScalarCos ( igxneew1le ) ; kdx1mgofh3 = rtP .
Gain_Gain_fldlnfjp4b * kzghw22rl3_p ; bg2cz1r4a0 = muDoubleScalarCos (
kdx1mgofh3 ) ; hlrngpk0qn [ 0 ] = evub4310g5 * bg2cz1r4a0 ; kdx1mgofh3 =
muDoubleScalarSin ( kdx1mgofh3 ) ; hlrngpk0qn [ 1 ] = evub4310g5 * kdx1mgofh3
* rtP . ChSign_Gain_jrexwz533r ; nfwdvadjxh = muDoubleScalarSin ( igxneew1le
) ; hlrngpk0qn [ 2 ] = rtP . ChSign1_Gain_p1dv1gzhg0 * nfwdvadjxh ;
hlrngpk0qn [ 3 ] = kdx1mgofh3 ; hlrngpk0qn [ 4 ] = bg2cz1r4a0 ; hlrngpk0qn [
5 ] = rtP . Zero_Value_dhaiu1n4hb ; hlrngpk0qn [ 6 ] = nfwdvadjxh *
bg2cz1r4a0 ; hlrngpk0qn [ 7 ] = nfwdvadjxh * kdx1mgofh3 * rtP .
ChSign2_Gain_mg4y2ieuqq ; hlrngpk0qn [ 8 ] = evub4310g5 ; evub4310g5 = rtP .
clbeta_Gain * kzghw22rl3_p ; bg2cz1r4a0 = rtP . cldelta_a_Gain * rtB .
lbzm4w3kvc [ 2 ] ; kdx1mgofh3 = rtP . cldelta_r_Gain * rtB . lbzm4w3kvc [ 3 ]
; nfwdvadjxh = rtP . clp_Gain * ikf1a42anw_idx_0 ; brocf3ytq0 = rtP .
clr_Gain * ikf1a42anw_idx_2 ; hcjz2yyqjx_idx_2 = ( rtB . mbeszndpzw [ 0 ] *
rtB . mbeszndpzw [ 0 ] + rtB . mbeszndpzw [ 1 ] * rtB . mbeszndpzw [ 1 ] ) +
rtB . mbeszndpzw [ 2 ] * rtB . mbeszndpzw [ 2 ] ; if ( ssIsMajorTimeStep (
rtS ) ) { if ( rtDW . fciwvikpdr != 0 ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW . fciwvikpdr = 0 ;
} hcjz2yyqjx_idx_3 = muDoubleScalarSqrt ( hcjz2yyqjx_idx_2 ) ; } else if (
hcjz2yyqjx_idx_2 < 0.0 ) { hcjz2yyqjx_idx_3 = - muDoubleScalarSqrt (
muDoubleScalarAbs ( hcjz2yyqjx_idx_2 ) ) ; rtDW . fciwvikpdr = 1 ; } else {
hcjz2yyqjx_idx_3 = muDoubleScalarSqrt ( hcjz2yyqjx_idx_2 ) ; } evub4310g5 = (
( nfwdvadjxh + brocf3ytq0 ) * rtP . Wingspan_Value_drrojpryp4 / ( rtP .
u_Gain_dzcqhyfoug * hcjz2yyqjx_idx_3 ) + ( ( evub4310g5 + bg2cz1r4a0 ) +
kdx1mgofh3 ) ) * ( ggbjmbjroo * rtP . Wingarea_Value * rtP .
Wingspan_Value_cr0bafp5uf ) ; rtB . aiijml5ggp = rtP . cmalpha_Gain *
igxneew1le ; rtB . mlb2v0rqr4 = rtP . cmdelta_f_Gain * rtB . lbzm4w3kvc [ 1 ]
; rtB . mmcuu43erm = rtP . cmdelta_e_Gain * rtB . lbzm4w3kvc [ 0 ] ; rtB .
babk200cg1 = rtP . cmalphadot_Gain * hcjz2yyqjx_idx_0 ; rtB . eimam0aysg =
rtP . cmq_Gain * ikf1a42anw_idx_1 ; igxneew1le = rtB . babk200cg1 + rtB .
eimam0aysg ; hcjz2yyqjx_idx_0 = ( rtB . mbeszndpzw [ 0 ] * rtB . mbeszndpzw [
0 ] + rtB . mbeszndpzw [ 1 ] * rtB . mbeszndpzw [ 1 ] ) + rtB . mbeszndpzw [
2 ] * rtB . mbeszndpzw [ 2 ] ; if ( ssIsMajorTimeStep ( rtS ) ) { if ( rtDW .
n5ngktfrhq != 0 ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW
. n5ngktfrhq = 0 ; } bg2cz1r4a0 = muDoubleScalarSqrt ( hcjz2yyqjx_idx_0 ) ; }
else if ( hcjz2yyqjx_idx_0 < 0.0 ) { bg2cz1r4a0 = - muDoubleScalarSqrt (
muDoubleScalarAbs ( hcjz2yyqjx_idx_0 ) ) ; rtDW . n5ngktfrhq = 1 ; } else {
bg2cz1r4a0 = muDoubleScalarSqrt ( hcjz2yyqjx_idx_0 ) ; } rtB . n4ytkvk2rz =
rtP . cmM_Gain * ixdhbjnct0 ; igxneew1le = ( ( ( ( ( rtB . obrryzou3p + rtB .
aiijml5ggp ) + rtB . mlb2v0rqr4 ) + rtB . mmcuu43erm ) + igxneew1le * rtP .
Wingchord_Value_emuwkezyaz / ( rtP . u_Gain_kpl0cbpinj * bg2cz1r4a0 ) ) + rtB
. n4ytkvk2rz ) * ( ggbjmbjroo * rtP . Wingarea_Value * rtP . Wingchord_Value
) ; kzghw22rl3_p *= rtP . cnbeta_Gain ; hcjz2yyqjx_idx_0 = rtP .
cndelta_a_Gain * rtB . lbzm4w3kvc [ 2 ] ; ixdhbjnct0 = rtP . cndelta_r_Gain *
rtB . lbzm4w3kvc [ 3 ] ; bg2cz1r4a0 = rtP . cnp_Gain * ikf1a42anw_idx_0 ;
kdx1mgofh3 = rtP . cnr_Gain * ikf1a42anw_idx_2 ; nfwdvadjxh = ( rtB .
mbeszndpzw [ 0 ] * rtB . mbeszndpzw [ 0 ] + rtB . mbeszndpzw [ 1 ] * rtB .
mbeszndpzw [ 1 ] ) + rtB . mbeszndpzw [ 2 ] * rtB . mbeszndpzw [ 2 ] ; if (
ssIsMajorTimeStep ( rtS ) ) { if ( rtDW . dxc22zb0w3 != 0 ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW . dxc22zb0w3 = 0 ;
} brocf3ytq0 = muDoubleScalarSqrt ( nfwdvadjxh ) ; } else if ( nfwdvadjxh <
0.0 ) { brocf3ytq0 = - muDoubleScalarSqrt ( muDoubleScalarAbs ( nfwdvadjxh )
) ; rtDW . dxc22zb0w3 = 1 ; } else { brocf3ytq0 = muDoubleScalarSqrt (
nfwdvadjxh ) ; } kdx1mgofh3 = ( ( bg2cz1r4a0 + kdx1mgofh3 ) * rtP .
Wingspan_Value_erx3lkovhx / ( rtP . u_Gain_p0db5lqo0p * brocf3ytq0 ) + ( (
kzghw22rl3_p + hcjz2yyqjx_idx_0 ) + ixdhbjnct0 ) ) * ( ggbjmbjroo * rtP .
Wingarea_Value * rtP . Wingspan2_Value ) ; for ( i_p = 0 ; i_p < 3 ; i_p ++ )
{ rtB . hc3hgdwtyb [ i_p ] = ( ( hlrngpk0qn [ i_p + 6 ] * kdx1mgofh3 + (
hlrngpk0qn [ i_p + 3 ] * igxneew1le + hlrngpk0qn [ i_p ] * evub4310g5 ) ) +
rtP . TrimThrust5_Value [ i_p ] ) + rtP . TrimThrust5_Value_pghqg4ahuq [ i_p
] ; gs11owd144 [ i_p ] = rtP . Constant2_Value_lh0btpjb3l [ i_p + 6 ] *
ikf1a42anw_idx_2 + ( rtP . Constant2_Value_lh0btpjb3l [ i_p + 3 ] *
ikf1a42anw_idx_1 + rtP . Constant2_Value_lh0btpjb3l [ i_p ] *
ikf1a42anw_idx_0 ) ; } ikf1a42anw_p [ 0 ] = ikf1a42anw_idx_1 * gs11owd144 [ 2
] ; ikf1a42anw_p [ 1 ] = ikf1a42anw_idx_2 * gs11owd144 [ 0 ] ; ikf1a42anw_p [
2 ] = ikf1a42anw_idx_0 * gs11owd144 [ 1 ] ; ikf1a42anw_e [ 0 ] =
ikf1a42anw_idx_2 * gs11owd144 [ 1 ] ; ikf1a42anw_e [ 1 ] = ikf1a42anw_idx_0 *
gs11owd144 [ 2 ] ; ikf1a42anw_e [ 2 ] = ikf1a42anw_idx_1 * gs11owd144 [ 0 ] ;
for ( i_p = 0 ; i_p < 3 ; i_p ++ ) { tmp_e [ i_p ] = ( rtB . hc3hgdwtyb [ i_p
] - ( ( rtP . Constant3_Value_f1k1adieba [ i_p + 3 ] * ikf1a42anw_idx_1 + rtP
. Constant3_Value_f1k1adieba [ i_p ] * ikf1a42anw_idx_0 ) + rtP .
Constant3_Value_f1k1adieba [ i_p + 6 ] * ikf1a42anw_idx_2 ) ) - (
ikf1a42anw_p [ i_p ] - ikf1a42anw_e [ i_p ] ) ; }
rt_mldivide_U1d3x3_U2d3x1_Yd3x1_snf ( rtP . Constant2_Value_lh0btpjb3l ,
tmp_e , rtB . axza31sfxm ) ; rtB . ej5pw05q3j [ 0 ] = rtP .
Gain1_Gain_b1hf4hkty0 * rtB . axza31sfxm [ 0 ] ; rtB . ej5pw05q3j [ 1 ] = rtP
. Gain1_Gain_b1hf4hkty0 * rtB . axza31sfxm [ 1 ] ; rtB . ej5pw05q3j [ 2 ] =
rtP . Gain1_Gain_b1hf4hkty0 * rtB . axza31sfxm [ 2 ] ; rtB . hhdivriu54 [ 0 ]
= rtP . Gain_Gain_dqhhuexjt5 * rtB . g2bzvajzvm [ 0 ] ; rtB . hhdivriu54 [ 1
] = rtP . Gain_Gain_dqhhuexjt5 * rtB . g2bzvajzvm [ 1 ] ; rtB . hhdivriu54 [
2 ] = rtP . Gain_Gain_dqhhuexjt5 * rtB . g2bzvajzvm [ 2 ] ; rtB . nco05nrykr
[ 0 ] = rtP . Gain5_Gain_lm3oic4sdo * rtB . g2bzvajzvm [ 0 ] ; rtB .
nco05nrykr [ 1 ] = rtP . Gain5_Gain_lm3oic4sdo * rtB . g2bzvajzvm [ 1 ] ; rtB
. nco05nrykr [ 2 ] = rtP . Gain5_Gain_lm3oic4sdo * rtB . g2bzvajzvm [ 2 ] ;
if ( ssGetLogOutput ( rtS ) ) { { double locTime = ssGetTaskTime ( rtS , 0 )
; ; if ( rtwTimeInLoggingInterval ( rtliGetLoggingInterval ( ssGetRootSS (
rtS ) -> mdlInfo -> rtwLogInfo ) , locTime ) ) { rt_UpdateLogVar ( ( LogVar *
) ( LogVar * ) ( rtDW . ayqwng4oox . LoggedData ) , & rtB . nco05nrykr [ 0 ]
, 0 ) ; } } } rtB . l2let5yzu1 [ 0 ] = rtP . Gain3_Gain_hjbg4mtw5c [ 0 ] *
rtB . prll55li14 [ 0 ] ; rtB . l2let5yzu1 [ 1 ] = rtP . Gain3_Gain_hjbg4mtw5c
[ 1 ] * rtB . prll55li14 [ 1 ] ; rtB . l2let5yzu1 [ 2 ] = rtP .
Gain3_Gain_hjbg4mtw5c [ 2 ] * rtB . prll55li14 [ 2 ] ; rtB . bt44u1ruqs [ 0 ]
= rtP . Gain4_Gain_l0vaw0ty4p [ 0 ] * rtB . prll55li14 [ 0 ] ; rtB .
bt44u1ruqs [ 1 ] = rtP . Gain4_Gain_l0vaw0ty4p [ 1 ] * rtB . prll55li14 [ 1 ]
; rtB . bt44u1ruqs [ 2 ] = rtP . Gain4_Gain_l0vaw0ty4p [ 2 ] * rtB .
prll55li14 [ 2 ] ; if ( ssGetLogOutput ( rtS ) ) { { double locTime =
ssGetTaskTime ( rtS , 0 ) ; ; if ( rtwTimeInLoggingInterval (
rtliGetLoggingInterval ( ssGetRootSS ( rtS ) -> mdlInfo -> rtwLogInfo ) ,
locTime ) ) { rt_UpdateLogVar ( ( LogVar * ) ( LogVar * ) ( rtDW . l0rvcjwiw5
. LoggedData ) , & rtB . bt44u1ruqs [ 0 ] , 0 ) ; } } } muDoubleScalarSinCos
( rtB . g2bzvajzvm [ 2 ] , & gs11owd144 [ 0 ] , & nfadndiksa [ 0 ] ) ;
muDoubleScalarSinCos ( rtB . g2bzvajzvm [ 1 ] , & gs11owd144 [ 1 ] , &
nfadndiksa [ 1 ] ) ; muDoubleScalarSinCos ( rtB . g2bzvajzvm [ 0 ] , &
brocf3ytq0 , & nfadndiksa [ 2 ] ) ; hlrngpk0qn [ 0 ] = nfadndiksa [ 1 ] *
nfadndiksa [ 0 ] ; hlrngpk0qn [ 1 ] = brocf3ytq0 * gs11owd144 [ 1 ] *
nfadndiksa [ 0 ] - nfadndiksa [ 2 ] * gs11owd144 [ 0 ] ; hlrngpk0qn [ 2 ] =
nfadndiksa [ 2 ] * gs11owd144 [ 1 ] * nfadndiksa [ 0 ] + brocf3ytq0 *
gs11owd144 [ 0 ] ; hlrngpk0qn [ 3 ] = nfadndiksa [ 1 ] * gs11owd144 [ 0 ] ;
hlrngpk0qn [ 4 ] = brocf3ytq0 * gs11owd144 [ 1 ] * gs11owd144 [ 0 ] +
nfadndiksa [ 2 ] * nfadndiksa [ 0 ] ; hlrngpk0qn [ 5 ] = nfadndiksa [ 2 ] *
gs11owd144 [ 1 ] * gs11owd144 [ 0 ] - brocf3ytq0 * nfadndiksa [ 0 ] ;
hlrngpk0qn [ 6 ] = - gs11owd144 [ 1 ] ; hlrngpk0qn [ 7 ] = brocf3ytq0 *
nfadndiksa [ 1 ] ; hlrngpk0qn [ 8 ] = nfadndiksa [ 2 ] * nfadndiksa [ 1 ] ;
for ( i_p = 0 ; i_p < 3 ; i_p ++ ) { rtB . ewosjguuu0 [ i_p ] = hlrngpk0qn [
3 * i_p + 2 ] * rtB . mbeszndpzw [ 2 ] + ( hlrngpk0qn [ 3 * i_p + 1 ] * rtB .
mbeszndpzw [ 1 ] + hlrngpk0qn [ 3 * i_p ] * rtB . mbeszndpzw [ 0 ] ) ; }
rtPrevAction = rtDW . mqarvij1wr ; rtAction = - 1 ; if ( ssIsMajorTimeStep (
rtS ) ) { if ( rtB . prll55li14 [ 2 ] >= 0.0 ) { rtAction = 0 ; } rtDW .
mqarvij1wr = rtAction ; } else { rtAction = rtDW . mqarvij1wr ; } if ( (
rtPrevAction != rtAction ) && ( rtPrevAction == 0 ) ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } if ( rtAction == 0 ) {
if ( 0 != rtPrevAction ) { if ( ssGetTaskTime ( rtS , 0 ) != ssGetTStart (
rtS ) ) { ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; } } if (
ssIsSampleHit ( rtS , 1 , 0 ) && ( rtP . Constant_Value != 0.0 ) ) {
ssSetStopRequested ( rtS , 1 ) ; } if ( ssIsMajorTimeStep ( rtS ) ) {
srUpdateBC ( rtDW . f5ilhbx002 ) ; } } muDoubleScalarSinCos ( rtB .
g2bzvajzvm [ 0 ] , & gs11owd144 [ 0 ] , & nfadndiksa [ 0 ] ) ;
muDoubleScalarSinCos ( rtB . g2bzvajzvm [ 1 ] , & gs11owd144 [ 1 ] , &
nfadndiksa [ 1 ] ) ; muDoubleScalarSinCos ( rtB . g2bzvajzvm [ 2 ] , &
gs11owd144 [ 2 ] , & nfadndiksa [ 2 ] ) ; rtB . iexmvyr4r4 [ 0 ] = (
ikf1a42anw_idx_1 * gs11owd144 [ 0 ] + ikf1a42anw_idx_2 * nfadndiksa [ 0 ] ) *
( gs11owd144 [ 1 ] / nfadndiksa [ 1 ] ) + ikf1a42anw_idx_0 ; rtB . iexmvyr4r4
[ 1 ] = ikf1a42anw_idx_1 * nfadndiksa [ 0 ] - ikf1a42anw_idx_2 * gs11owd144 [
0 ] ; rtB . iexmvyr4r4 [ 2 ] = ( ikf1a42anw_idx_1 * gs11owd144 [ 0 ] +
ikf1a42anw_idx_2 * nfadndiksa [ 0 ] ) / nfadndiksa [ 1 ] ; rtB . gel1pzm210 =
( rtB . pd3h1ffkcz [ 2 ] * rtB . mbeszndpzw [ 0 ] - rtB . pd3h1ffkcz [ 0 ] *
rtB . mbeszndpzw [ 2 ] ) / ( muDoubleScalarPower ( rtB . mbeszndpzw [ 0 ] ,
2.0 ) + muDoubleScalarPower ( rtB . mbeszndpzw [ 2 ] , 2.0 ) ) ; igxneew1le =
muDoubleScalarPower ( rtB . mbeszndpzw [ 0 ] , 2.0 ) + muDoubleScalarPower (
rtB . mbeszndpzw [ 2 ] , 2.0 ) ; if ( igxneew1le < 0.0 ) { igxneew1le = -
muDoubleScalarSqrt ( - igxneew1le ) ; } else { igxneew1le =
muDoubleScalarSqrt ( igxneew1le ) ; } rtB . l3nhcgjbby = ( (
muDoubleScalarPower ( rtB . mbeszndpzw [ 0 ] , 2.0 ) + muDoubleScalarPower (
rtB . mbeszndpzw [ 2 ] , 2.0 ) ) * rtB . pd3h1ffkcz [ 1 ] - ( rtB .
mbeszndpzw [ 0 ] * rtB . pd3h1ffkcz [ 0 ] + rtB . mbeszndpzw [ 2 ] * rtB .
pd3h1ffkcz [ 2 ] ) * rtB . mbeszndpzw [ 1 ] ) / ( ( ( muDoubleScalarPower (
rtB . mbeszndpzw [ 0 ] , 2.0 ) + muDoubleScalarPower ( rtB . mbeszndpzw [ 1 ]
, 2.0 ) ) + muDoubleScalarPower ( rtB . mbeszndpzw [ 2 ] , 2.0 ) ) *
igxneew1le ) ; if ( ssGetLogOutput ( rtS ) ) { { double locTime =
ssGetTaskTime ( rtS , 0 ) ; ; if ( rtwTimeInLoggingInterval (
rtliGetLoggingInterval ( ssGetRootSS ( rtS ) -> mdlInfo -> rtwLogInfo ) ,
locTime ) ) { rt_UpdateLogVar ( ( LogVar * ) ( LogVar * ) ( rtDW . juhedu4p0x
. LoggedData ) , & rtB . lbzm4w3kvc [ 0 ] , 0 ) ; } } } UNUSED_PARAMETER (
tid ) ; } void MdlOutputsTID2 ( int_T tid ) { real_T lzdlzmm2cg ; real_T
dnxtsu05jy ; real_T l0fbdsw4v4 ; real_T cwuotyldgs ; rtB . obrryzou3p = rtP .
Cm0_Value ; if ( muDoubleScalarAbs ( rtP . FlatEarthtoLLA_LL0 [ 0 ] ) > rtP .
CompareToConstant_const_nifrvxypha ) { dnxtsu05jy = muDoubleScalarMod ( rtP .
FlatEarthtoLLA_LL0 [ 0 ] + rtP . Bias_Bias_lfg1tbgilu , rtP .
Constant2_Value_muoeisyhao ) + rtP . Bias1_Bias_dxmrixcsmx ; } else {
dnxtsu05jy = rtP . FlatEarthtoLLA_LL0 [ 0 ] ; } l0fbdsw4v4 =
muDoubleScalarAbs ( dnxtsu05jy ) ; if ( l0fbdsw4v4 > rtP .
CompareToConstant_const_lrvr5wm4my ) { rtB . l4k2a5bsh4 = ( ( l0fbdsw4v4 +
rtP . Bias_Bias_f2s41qt1rc ) * rtP . Gain_Gain_p3bohr0orw + rtP .
Bias1_Bias_h3sn5uls4z ) * muDoubleScalarSign ( dnxtsu05jy ) ; dnxtsu05jy =
rtP . Constant_Value_bx2r5flqh4 ; } else { rtB . l4k2a5bsh4 = dnxtsu05jy ;
dnxtsu05jy = rtP . Constant1_Value_folsuaqk2w ; } dnxtsu05jy += rtP .
FlatEarthtoLLA_LL0 [ 1 ] ; if ( muDoubleScalarAbs ( dnxtsu05jy ) > rtP .
CompareToConstant_const_obwydhle4i ) { rtB . kzv3jtixuu = muDoubleScalarMod (
dnxtsu05jy + rtP . Bias_Bias_d5zpfez5uz , rtP . Constant2_Value_ir4n4t0fex )
+ rtP . Bias1_Bias_ewxdzezg00 ; } else { rtB . kzv3jtixuu = dnxtsu05jy ; }
dnxtsu05jy = 0.017453292519943295 * rtB . l4k2a5bsh4 ; l0fbdsw4v4 = rtP .
f_Value - rtP . Constant_Value_mjz5zpttx1 ; cwuotyldgs = rtP .
Constant_Value_enfqz0alpl - l0fbdsw4v4 * l0fbdsw4v4 ; if ( ssIsMajorTimeStep
( rtS ) ) { if ( rtDW . dkeirtfvst != 0 ) {
ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW . dkeirtfvst = 0 ;
} l0fbdsw4v4 = muDoubleScalarSqrt ( cwuotyldgs ) ; } else if ( cwuotyldgs <
0.0 ) { l0fbdsw4v4 = - muDoubleScalarSqrt ( muDoubleScalarAbs ( cwuotyldgs )
) ; rtDW . dkeirtfvst = 1 ; } else { l0fbdsw4v4 = muDoubleScalarSqrt (
cwuotyldgs ) ; } cwuotyldgs = muDoubleScalarSin ( dnxtsu05jy ) ; cwuotyldgs =
rtP . Constant_Value_mibaoj2rgl - l0fbdsw4v4 * l0fbdsw4v4 * cwuotyldgs *
cwuotyldgs ; if ( ssIsMajorTimeStep ( rtS ) ) { if ( rtDW . arnvx1x5wb != 0 )
{ ssSetBlockStateForSolverChangedAtMajorStep ( rtS ) ; rtDW . arnvx1x5wb = 0
; } lzdlzmm2cg = muDoubleScalarSqrt ( cwuotyldgs ) ; } else if ( cwuotyldgs <
0.0 ) { lzdlzmm2cg = - muDoubleScalarSqrt ( muDoubleScalarAbs ( cwuotyldgs )
) ; rtDW . arnvx1x5wb = 1 ; } else { lzdlzmm2cg = muDoubleScalarSqrt (
cwuotyldgs ) ; } lzdlzmm2cg = rtP . Constant1_Value_d1hfa5vt1i / lzdlzmm2cg ;
rtB . hcthdqledv = muDoubleScalarAtan2 ( rtP . Constant2_Value_pkofftudxg , (
rtP . Constant_Value_lljga3nj5j - l0fbdsw4v4 * l0fbdsw4v4 ) * lzdlzmm2cg /
cwuotyldgs ) ; rtB . n5jin1c2zm = muDoubleScalarAtan2 ( rtP . Constant3_Value
, lzdlzmm2cg * muDoubleScalarCos ( dnxtsu05jy ) ) ; muDoubleScalarSinCos (
0.017453292519943295 * rtP . FlatEarthtoLLA_psi , & rtB . ladmdwvset , & rtB
. fqj3t5j0hs ) ; rtB . gor1ljyslz [ 0 ] = rtP . Throttle_Gain * rtP .
TrimThrust1_Value ; rtB . gor1ljyslz [ 1 ] = rtP . Throttle_Gain * rtP .
TrimThrust2_Value ; rtB . gor1ljyslz [ 2 ] = rtP . Throttle_Gain * rtP .
TrimThrust3_Value ; rtB . bh40mgxfug = rtP . Constant_Value_ki5yoscsu1 ; rtB
. ft1rv4ttnm [ 0 ] = rtP . Constant4_Value [ 0 ] ; rtB . hbmslxdafy [ 0 ] =
rtP . Constant6_Value [ 0 ] ; rtB . lnbo3dn5b5 [ 0 ] = rtP . Constant7_Value
[ 0 ] ; rtB . mai2btwwwy [ 0 ] = rtP . Constant8_Value [ 0 ] ; rtB .
ft1rv4ttnm [ 1 ] = rtP . Constant4_Value [ 1 ] ; rtB . hbmslxdafy [ 1 ] = rtP
. Constant6_Value [ 1 ] ; rtB . lnbo3dn5b5 [ 1 ] = rtP . Constant7_Value [ 1
] ; rtB . mai2btwwwy [ 1 ] = rtP . Constant8_Value [ 1 ] ; rtB . ft1rv4ttnm [
2 ] = rtP . Constant4_Value [ 2 ] ; rtB . hbmslxdafy [ 2 ] = rtP .
Constant6_Value [ 2 ] ; rtB . lnbo3dn5b5 [ 2 ] = rtP . Constant7_Value [ 2 ]
; rtB . mai2btwwwy [ 2 ] = rtP . Constant8_Value [ 2 ] ; rtB . dorju0mbfg =
rtP . Constant_Value_ldaynjj304 ; UNUSED_PARAMETER ( tid ) ; } void MdlUpdate
( int_T tid ) { rtDW . j5skdyoj5i = 0 ; rtDW . hwhk0plcbm = 0 ; rtDW .
dgdkommmsd = 0 ; rtDW . j4k0h2foay = 0 ; rtDW . kv4lnrjne2 = 0 ;
UNUSED_PARAMETER ( tid ) ; } void MdlUpdateTID2 ( int_T tid ) {
UNUSED_PARAMETER ( tid ) ; } void MdlDerivatives ( void ) { XDot * _rtXdot ;
_rtXdot = ( ( XDot * ) ssGetdX ( rtS ) ) ; _rtXdot -> hkxwzleotw [ 0 ] = rtB
. pd3h1ffkcz [ 0 ] ; _rtXdot -> md4byhppt3 [ 0 ] = rtB . axza31sfxm [ 0 ] ;
_rtXdot -> jwktqmf5nt [ 0 ] = rtB . ewosjguuu0 [ 0 ] ; _rtXdot -> a2thzvctjt
[ 0 ] = rtB . iexmvyr4r4 [ 0 ] ; _rtXdot -> hkxwzleotw [ 1 ] = rtB .
pd3h1ffkcz [ 1 ] ; _rtXdot -> md4byhppt3 [ 1 ] = rtB . axza31sfxm [ 1 ] ;
_rtXdot -> jwktqmf5nt [ 1 ] = rtB . ewosjguuu0 [ 1 ] ; _rtXdot -> a2thzvctjt
[ 1 ] = rtB . iexmvyr4r4 [ 1 ] ; _rtXdot -> hkxwzleotw [ 2 ] = rtB .
pd3h1ffkcz [ 2 ] ; _rtXdot -> md4byhppt3 [ 2 ] = rtB . axza31sfxm [ 2 ] ;
_rtXdot -> jwktqmf5nt [ 2 ] = rtB . ewosjguuu0 [ 2 ] ; _rtXdot -> a2thzvctjt
[ 2 ] = rtB . iexmvyr4r4 [ 2 ] ; _rtXdot -> ag4giqb3jg = 0.0 ; _rtXdot ->
ag4giqb3jg += rtP . TransferFcn_A * rtX . ag4giqb3jg ; _rtXdot -> ag4giqb3jg
+= rtB . gel1pzm210 ; _rtXdot -> papl5plp0u = rtP .
Constant1_Value_old4tikkcg ; _rtXdot -> kzigeirre3 = 0.0 ; _rtXdot ->
kzigeirre3 += rtP . TransferFcn1_A * rtX . kzigeirre3 ; _rtXdot -> kzigeirre3
+= rtB . l3nhcgjbby ; } void MdlProjection ( void ) { } void MdlZeroCrossings
( void ) { ZCV * _rtZCSV ; _rtZCSV = ( ( ZCV * ) ssGetSolverZcSignalVector (
rtS ) ) ; _rtZCSV -> esxwhjpixn = rtB . ddodrccvry ; _rtZCSV -> jl3mbtekoy =
rtB . jxiqnugoaw - rtP . Limitaltitudetotroposhere_UpperSat ; _rtZCSV ->
m1ecruo3jg = rtB . jxiqnugoaw - rtP . Limitaltitudetotroposhere_LowerSat ;
_rtZCSV -> cfdlx3be1l = rtB . hjeoespy50 - rtP .
LimitaltitudetoStratosphere_UpperSat ; _rtZCSV -> kiryj23le1 = rtB .
hjeoespy50 - rtP . LimitaltitudetoStratosphere_LowerSat ; _rtZCSV ->
cdzkij01l3 = ssGetT ( rtS ) - rtP . Doublet_T_start ; _rtZCSV -> lnafym5qo0 =
ssGetT ( rtS ) - ( rtP . Doublet_span / 2.0 + rtP . Doublet_T_start ) ;
_rtZCSV -> dvyvvk0pax = ssGetT ( rtS ) - ( rtP . Doublet_span / 2.0 + rtP .
Doublet_T_start ) ; _rtZCSV -> a0x5kr2xu1 = ssGetT ( rtS ) - ( rtP .
Doublet_T_start + rtP . Doublet_span ) ; { const double * timePtr = ( double
* ) rtDW . nyrbrzpro5 . TimePtr ; int_T * zcTimeIndices = & rtDW . bn4dbem3va
[ 0 ] ; int_T zcTimeIndicesIdx = rtDW . kwtny14ets ; ( ( ZCV * )
ssGetSolverZcSignalVector ( rtS ) ) -> fo2a53r5z4 = ssGetT ( rtS ) - timePtr
[ zcTimeIndices [ zcTimeIndicesIdx ] ] ; } { const double * timePtr = (
double * ) rtDW . k2h3rugqu1 . TimePtr ; int_T * zcTimeIndices = & rtDW .
c2y55kstcc [ 0 ] ; int_T zcTimeIndicesIdx = rtDW . bfzneoincq ; ( ( ZCV * )
ssGetSolverZcSignalVector ( rtS ) ) -> p0wuzgany1 = ssGetT ( rtS ) - timePtr
[ zcTimeIndices [ zcTimeIndicesIdx ] ] ; } { const double * timePtr = (
double * ) rtDW . hcmwiu4oc2 . TimePtr ; int_T * zcTimeIndices = & rtDW .
lgjhv10zvc [ 0 ] ; int_T zcTimeIndicesIdx = rtDW . aivemugqf1 ; ( ( ZCV * )
ssGetSolverZcSignalVector ( rtS ) ) -> jlivwyxcs1 = ssGetT ( rtS ) - timePtr
[ zcTimeIndices [ zcTimeIndicesIdx ] ] ; } _rtZCSV -> kxfxfrzymu = rtB .
igulonupg4 - rtP . Saturation1_UpperSat ; _rtZCSV -> cqtewcutcm = rtB .
igulonupg4 - rtP . Saturation1_LowerSat ; _rtZCSV -> jea0fndtzq [ 0 ] = rtB .
iluz41jmye [ 0 ] - rtP . Saturation2_UpperSat ; _rtZCSV -> fnqiehf0iq [ 0 ] =
rtB . iluz41jmye [ 0 ] - rtP . Saturation2_LowerSat ; _rtZCSV -> jea0fndtzq [
1 ] = rtB . iluz41jmye [ 1 ] - rtP . Saturation2_UpperSat ; _rtZCSV ->
fnqiehf0iq [ 1 ] = rtB . iluz41jmye [ 1 ] - rtP . Saturation2_LowerSat ;
_rtZCSV -> ksjmic4fui = rtB . odqjhpytke ; _rtZCSV -> ozr3k2rs0z = rtB .
n51upk5du5 ; _rtZCSV -> fzrm0x3g5u = rtB . b4lvv4thsq ; _rtZCSV -> hwhadsnigc
= rtB . j4qce2ejgk ; _rtZCSV -> miseu2fsh3 = rtB . j2ppwxwj2v ; { const
double * timePtr = ( double * ) rtDW . ezztmokhxt . TimePtr ; int_T *
zcTimeIndices = & rtDW . auwndvyfpq [ 0 ] ; int_T zcTimeIndicesIdx = rtDW .
hqdpuh5bh4 ; ( ( ZCV * ) ssGetSolverZcSignalVector ( rtS ) ) -> jsx5vij2em =
ssGetT ( rtS ) - timePtr [ zcTimeIndices [ zcTimeIndicesIdx ] ] ; } _rtZCSV
-> nkmzx4dpc2 = rtB . puqzbadmna [ 0 ] ; _rtZCSV -> d3j52t4cdu = rtB .
p43ilaklx2 - rtP . CompareToConstant_const_b0xas2jkq3 ; _rtZCSV -> jgjmx24uez
= rtB . ebdsowrcxw ; _rtZCSV -> ajsprelrkn = rtB . ebdsowrcxw ; _rtZCSV ->
icmmjkv3h0 = rtB . fl2tbgohhi - rtP . CompareToConstant_const ; _rtZCSV ->
pqje4iwe4y = rtB . ltejiu1rdi ; _rtZCSV -> nlsfj3nrys = rtB . nc2kd2edsn -
rtP . CompareToConstant_const_kmoxadnhb5 ; _rtZCSV -> agxt5l3hh0 = 0.0 ; if (
rtB . prll55li14 [ 2 ] >= 0.0 ) { _rtZCSV -> agxt5l3hh0 = 1.0 ; } } void
MdlTerminate ( void ) { rt_FREE ( rtDW . nyrbrzpro5 . RSimInfoPtr ) ; rt_FREE
( rtDW . knfsqkbog3 . RSimInfoPtr ) ; rt_FREE ( rtDW . k2h3rugqu1 .
RSimInfoPtr ) ; rt_FREE ( rtDW . hcmwiu4oc2 . RSimInfoPtr ) ; rt_FREE ( rtDW
. ezztmokhxt . RSimInfoPtr ) ; if ( rt_slioCatalogue ( ) != ( NULL ) ) { void
* * slioCatalogueAddr = rt_slioCatalogueAddr ( ) ; rtwSaveDatasetsToMatFile (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) ,
rt_GetMatSigstreamLoggingFileName ( ) ) ; rtwTerminateSlioCatalogue (
slioCatalogueAddr ) ; * slioCatalogueAddr = NULL ; } } void
MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS , 15 ) ;
ssSetNumPeriodicContStates ( rtS , 0 ) ; ssSetNumY ( rtS , 0 ) ; ssSetNumU (
rtS , 0 ) ; ssSetDirectFeedThrough ( rtS , 0 ) ; ssSetNumSampleTimes ( rtS ,
2 ) ; ssSetNumBlocks ( rtS , 449 ) ; ssSetNumBlockIO ( rtS , 61 ) ;
ssSetNumBlockParams ( rtS , 350 ) ; } void MdlInitializeSampleTimes ( void )
{ ssSetSampleTime ( rtS , 0 , 0.0 ) ; ssSetSampleTime ( rtS , 1 , 0.0 ) ;
ssSetOffsetTime ( rtS , 0 , 0.0 ) ; ssSetOffsetTime ( rtS , 1 , 1.0 ) ; }
void raccel_set_checksum ( ) { ssSetChecksumVal ( rtS , 0 , 4196730302U ) ;
ssSetChecksumVal ( rtS , 1 , 151385502U ) ; ssSetChecksumVal ( rtS , 2 ,
2760859041U ) ; ssSetChecksumVal ( rtS , 3 , 3234198081U ) ; }
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
( B ) ) ; } { real_T * x = ( real_T * ) & rtX ; ssSetContStates ( rtS , x ) ;
( void ) memset ( ( void * ) x , 0 , sizeof ( X ) ) ; } { void * dwork = (
void * ) & rtDW ; ssSetRootDWork ( rtS , dwork ) ; ( void ) memset ( dwork ,
0 , sizeof ( DW ) ) ; } { static DataTypeTransInfo dtInfo ; ( void ) memset (
( char_T * ) & dtInfo , 0 , sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS
, & dtInfo ) ; dtInfo . numDataTypes = 14 ; dtInfo . dataTypeSizes = &
rtDataTypeSizes [ 0 ] ; dtInfo . dataTypeNames = & rtDataTypeNames [ 0 ] ;
dtInfo . BTransTable = & rtBTransTable ; dtInfo . PTransTable = &
rtPTransTable ; dtInfo . dataTypeInfoTable = rtDataTypeInfoTable ; }
AFDNFSmodelSPA_InitializeDataMapInfo ( ) ; ssSetIsRapidAcceleratorActive (
rtS , true ) ; ssSetRootSS ( rtS , rtS ) ; ssSetVersion ( rtS ,
SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS , "AFDNFSmodelSPA" ) ;
ssSetPath ( rtS , "AFDNFSmodelSPA" ) ; ssSetTStart ( rtS , 0.0 ) ;
ssSetTFinal ( rtS , 100.0 ) ; { static RTWLogInfo rt_DataLoggingInfo ;
rt_DataLoggingInfo . loggingInterval = NULL ; ssSetRTWLogInfo ( rtS , &
rt_DataLoggingInfo ) ; } { { static int_T rt_LoggedStateWidths [ ] = { 3 , 3
, 3 , 3 , 1 , 1 , 1 } ; static int_T rt_LoggedStateNumDimensions [ ] = { 1 ,
1 , 1 , 1 , 1 , 1 , 1 } ; static int_T rt_LoggedStateDimensions [ ] = { 3 , 3
, 3 , 3 , 1 , 1 , 1 } ; static boolean_T rt_LoggedStateIsVarDims [ ] = { 0 ,
0 , 0 , 0 , 0 , 0 , 0 } ; static BuiltInDTypeId rt_LoggedStateDataTypeIds [ ]
= { SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE } ; static int_T rt_LoggedStateComplexSignals [ ] = { 0 , 0 , 0 , 0
, 0 , 0 , 0 } ; static RTWPreprocessingFcnPtr
rt_LoggingStatePreprocessingFcnPtrs [ ] = { ( NULL ) , ( NULL ) , ( NULL ) ,
( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) } ; static const char_T *
rt_LoggedStateLabels [ ] = { "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" ,
"CSTATE" , "CSTATE" , "CSTATE" } ; static const char_T *
rt_LoggedStateBlockNames [ ] = {
 "AFDNFSmodelSPA/Nonlinear Flight\nSimulator/6DoF Nonlinear Flight\nEquations of Motion\n(Rigid Body)/Linear Velocity\nIntegrator\n(Body)"
,
 "AFDNFSmodelSPA/Nonlinear Flight\nSimulator/6DoF Nonlinear Flight\nEquations of Motion\n(Rigid Body)/Angular Velocity\nIntegrator\n(Body)"
,
 "AFDNFSmodelSPA/Nonlinear Flight\nSimulator/6DoF Nonlinear Flight\nEquations of Motion\n(Rigid Body)/Euler angles &\nDirection Cosine/Position\nIntegrator"
,
 "AFDNFSmodelSPA/Nonlinear Flight\nSimulator/6DoF Nonlinear Flight\nEquations of Motion\n(Rigid Body)/Euler angles &\nDirection Cosine/Euler\nAngles Int"
,
 "AFDNFSmodelSPA/Nonlinear Flight\nSimulator/Forces and Moments/Aerodynamic Forces and Moments\nDerivatives/Aero Attributes/Transfer Fcn"
,
 "AFDNFSmodelSPA/Nonlinear Flight\nSimulator/6DoF Nonlinear Flight\nEquations of Motion\n(Rigid Body)/Mass Int"
,
 "AFDNFSmodelSPA/Nonlinear Flight\nSimulator/Forces and Moments/Aerodynamic Forces and Moments\nDerivatives/Aero Attributes/Transfer Fcn1"
} ; static const char_T * rt_LoggedStateNames [ ] = { "BodyLinearVelocity" ,
"BodyAngularVelocity" , "" , "" , "" , "BodyMass" , "" } ; static boolean_T
rt_LoggedStateCrossMdlRef [ ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 } ; static
RTWLogDataTypeConvert rt_RTWLogDataTypeConvert [ ] = { { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } } ; static RTWLogSignalInfo rt_LoggedStateSignalInfo =
{ 7 , rt_LoggedStateWidths , rt_LoggedStateNumDimensions ,
rt_LoggedStateDimensions , rt_LoggedStateIsVarDims , ( NULL ) , ( NULL ) ,
rt_LoggedStateDataTypeIds , rt_LoggedStateComplexSignals , ( NULL ) ,
rt_LoggingStatePreprocessingFcnPtrs , { rt_LoggedStateLabels } , ( NULL ) , (
NULL ) , ( NULL ) , { rt_LoggedStateBlockNames } , { rt_LoggedStateNames } ,
rt_LoggedStateCrossMdlRef , rt_RTWLogDataTypeConvert } ; static void *
rt_LoggedStateSignalPtrs [ 7 ] ; rtliSetLogXSignalPtrs ( ssGetRTWLogInfo (
rtS ) , ( LogSignalPtrsType ) rt_LoggedStateSignalPtrs ) ;
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , & rt_LoggedStateSignalInfo
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) & rtX . hkxwzleotw [ 0 ] ;
rt_LoggedStateSignalPtrs [ 1 ] = ( void * ) & rtX . md4byhppt3 [ 0 ] ;
rt_LoggedStateSignalPtrs [ 2 ] = ( void * ) & rtX . jwktqmf5nt [ 0 ] ;
rt_LoggedStateSignalPtrs [ 3 ] = ( void * ) & rtX . a2thzvctjt [ 0 ] ;
rt_LoggedStateSignalPtrs [ 4 ] = ( void * ) & rtX . ag4giqb3jg ;
rt_LoggedStateSignalPtrs [ 5 ] = ( void * ) & rtX . papl5plp0u ;
rt_LoggedStateSignalPtrs [ 6 ] = ( void * ) & rtX . kzigeirre3 ; }
rtliSetLogT ( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX (
ssGetRTWLogInfo ( rtS ) , "tmp_raccel_xout" ) ; rtliSetLogXFinal (
ssGetRTWLogInfo ( rtS ) , "xFinal" ) ; rtliSetLogVarNameModifier (
ssGetRTWLogInfo ( rtS ) , "none" ) ; rtliSetLogFormat ( ssGetRTWLogInfo ( rtS
) , 2 ) ; rtliSetLogMaxRows ( ssGetRTWLogInfo ( rtS ) , 0 ) ;
rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS ) , 1 ) ; rtliSetLogY (
ssGetRTWLogInfo ( rtS ) , "" ) ; rtliSetLogYSignalInfo ( ssGetRTWLogInfo (
rtS ) , ( NULL ) ) ; rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL
) ) ; } { static struct _ssStatesInfo2 statesInfo2 ; ssSetStatesInfo2 ( rtS ,
& statesInfo2 ) ; } { static ssPeriodicStatesInfo periodicStatesInfo ;
ssSetPeriodicStatesInfo ( rtS , & periodicStatesInfo ) ; } { static
ssJacobianPerturbationBounds jacobianPerturbationBounds ;
ssSetJacobianPerturbationBounds ( rtS , & jacobianPerturbationBounds ) ; } {
static ssSolverInfo slvrInfo ; static boolean_T contStatesDisabled [ 15 ] ;
static real_T absTol [ 15 ] = { 1.0E-8 , 1.0E-8 , 1.0E-8 , 1.0E-8 , 1.0E-8 ,
1.0E-8 , 1.0E-8 , 1.0E-8 , 1.0E-8 , 1.0E-8 , 1.0E-8 , 1.0E-8 , 1.0E-8 ,
1.0E-8 , 1.0E-8 } ; static uint8_T absTolControl [ 15 ] = { 2U , 2U , 2U , 2U
, 2U , 2U , 2U , 2U , 2U , 2U , 2U , 2U , 2U , 2U , 2U } ; static real_T
contStateJacPerturbBoundMinVec [ 15 ] ; static real_T
contStateJacPerturbBoundMaxVec [ 15 ] ; static uint8_T zcAttributes [ 32 ] =
{ ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) ,
( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL_UP ) , ( ZC_EVENT_ALL_UP ) , (
ZC_EVENT_ALL_UP ) , ( ZC_EVENT_ALL_UP ) , ( ZC_EVENT_ALL_UP ) , (
ZC_EVENT_ALL_UP ) , ( ZC_EVENT_ALL_UP ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL )
, ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) ,
( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL ) , ( ZC_EVENT_ALL_UP ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) ,
( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , (
ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) } ; static ssNonContDerivSigInfo
nonContDerivSigInfo [ 6 ] = { { 1 * sizeof ( boolean_T ) , ( char * ) ( & rtB
. ao5xxbupqa ) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
kf1oc12ha5 ) , ( NULL ) } , { 1 * sizeof ( boolean_T ) , ( char * ) ( & rtB .
ku1qygrkrl ) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
aa5dhjvrml ) , ( NULL ) } , { 1 * sizeof ( boolean_T ) , ( char * ) ( & rtB .
ar551zz3kn ) , ( NULL ) } , { 1 * sizeof ( real_T ) , ( char * ) ( & rtB .
lf41qcir2i ) , ( NULL ) } } ; { int i ; for ( i = 0 ; i < 15 ; ++ i ) {
contStateJacPerturbBoundMinVec [ i ] = 0 ; contStateJacPerturbBoundMaxVec [ i
] = rtGetInf ( ) ; } } ssSetSolverRelTol ( rtS , 1.0E-8 ) ; ssSetStepSize (
rtS , 0.0 ) ; ssSetMinStepSize ( rtS , 0.0 ) ; ssSetMaxNumMinSteps ( rtS , -
1 ) ; ssSetMinStepViolatedError ( rtS , 0 ) ; ssSetMaxStepSize ( rtS , 2.0 )
; ssSetSolverMaxOrder ( rtS , - 1 ) ; ssSetSolverRefineFactor ( rtS , 1 ) ;
ssSetOutputTimes ( rtS , ( NULL ) ) ; ssSetNumOutputTimes ( rtS , 0 ) ;
ssSetOutputTimesOnly ( rtS , 0 ) ; ssSetOutputTimesIndex ( rtS , 0 ) ;
ssSetZCCacheNeedsReset ( rtS , 1 ) ; ssSetDerivCacheNeedsReset ( rtS , 0 ) ;
ssSetNumNonContDerivSigInfos ( rtS , 6 ) ; ssSetNonContDerivSigInfos ( rtS ,
nonContDerivSigInfo ) ; ssSetSolverInfo ( rtS , & slvrInfo ) ;
ssSetSolverName ( rtS , "ode45" ) ; ssSetVariableStepSolver ( rtS , 1 ) ;
ssSetSolverConsistencyChecking ( rtS , 0 ) ; ssSetSolverAdaptiveZcDetection (
rtS , 1 ) ; ssSetSolverRobustResetMethod ( rtS , 0 ) ; ssSetAbsTolVector (
rtS , absTol ) ; ssSetAbsTolControlVector ( rtS , absTolControl ) ;
ssSetSolverAbsTol_Obsolete ( rtS , absTol ) ;
ssSetSolverAbsTolControl_Obsolete ( rtS , absTolControl ) ;
ssSetJacobianPerturbationBoundsMinVec ( rtS , contStateJacPerturbBoundMinVec
) ; ssSetJacobianPerturbationBoundsMaxVec ( rtS ,
contStateJacPerturbBoundMaxVec ) ; ssSetSolverStateProjection ( rtS , 0 ) ;
ssSetSolverMassMatrixType ( rtS , ( ssMatrixType ) 0 ) ;
ssSetSolverMassMatrixNzMax ( rtS , 0 ) ; ssSetModelOutputs ( rtS , MdlOutputs
) ; ssSetModelLogData ( rtS , rt_UpdateTXYLogVars ) ;
ssSetModelLogDataIfInInterval ( rtS , rt_UpdateTXXFYLogVars ) ;
ssSetModelUpdate ( rtS , MdlUpdate ) ; ssSetModelDerivatives ( rtS ,
MdlDerivatives ) ; ssSetSolverZcSignalAttrib ( rtS , zcAttributes ) ;
ssSetSolverNumZcSignals ( rtS , 32 ) ; ssSetModelZeroCrossings ( rtS ,
MdlZeroCrossings ) ; ssSetSolverConsecutiveZCsStepRelTol ( rtS ,
2.8421709430404007E-13 ) ; ssSetSolverMaxConsecutiveZCs ( rtS , 1000 ) ;
ssSetSolverConsecutiveZCsError ( rtS , 2 ) ; ssSetSolverMaskedZcDiagnostic (
rtS , 1 ) ; ssSetSolverIgnoredZcDiagnostic ( rtS , 1 ) ;
ssSetSolverZcThreshold ( rtS , 1.0E-8 ) ; ssSetSolverMaxConsecutiveMinStep (
rtS , 1 ) ; ssSetSolverShapePreserveControl ( rtS , 2 ) ; ssSetTNextTid ( rtS
, INT_MIN ) ; ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset ( rtS )
; ssSetNumNonsampledZCs ( rtS , 32 ) ; ssSetContStateDisabled ( rtS ,
contStatesDisabled ) ; ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ; }
ssSetChecksumVal ( rtS , 0 , 4196730302U ) ; ssSetChecksumVal ( rtS , 1 ,
151385502U ) ; ssSetChecksumVal ( rtS , 2 , 2760859041U ) ; ssSetChecksumVal
( rtS , 3 , 3234198081U ) ; { static const sysRanDType rtAlwaysEnabled =
SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo rt_ExtModeInfo ; static const
sysRanDType * systemRan [ 8 ] ; gblRTWExtModeInfo = & rt_ExtModeInfo ;
ssSetRTWExtModeInfo ( rtS , & rt_ExtModeInfo ) ;
rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo , systemRan ) ;
systemRan [ 0 ] = & rtAlwaysEnabled ; systemRan [ 1 ] = ( sysRanDType * ) &
rtDW . f5ilhbx002 ; systemRan [ 2 ] = & rtAlwaysEnabled ; systemRan [ 3 ] = &
rtAlwaysEnabled ; systemRan [ 4 ] = & rtAlwaysEnabled ; systemRan [ 5 ] = &
rtAlwaysEnabled ; systemRan [ 6 ] = & rtAlwaysEnabled ; systemRan [ 7 ] = &
rtAlwaysEnabled ; rteiSetModelMappingInfoPtr ( ssGetRTWExtModeInfo ( rtS ) ,
& ssGetModelMappingInfo ( rtS ) ) ; rteiSetChecksumsPtr ( ssGetRTWExtModeInfo
( rtS ) , ssGetChecksums ( rtS ) ) ; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS
) , ssGetTPtr ( rtS ) ) ; } return rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = 2 ; void MdlOutputsParameterSampleTime (
int_T tid ) { MdlOutputsTID2 ( tid ) ; }
