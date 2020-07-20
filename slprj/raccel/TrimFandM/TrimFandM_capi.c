#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "TrimFandM_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)    
#else
#include "builtin_typeid_types.h"
#include "TrimFandM.h"
#include "TrimFandM_capi.h"
#include "TrimFandM_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST                  
#define TARGET_STRING(s)               (NULL)                    
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , TARGET_STRING (
"TrimFandM/Forces and Moments/Sum2" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0
, 0 } , { 1 , 0 , TARGET_STRING ( "TrimFandM/Forces and Moments/Sum3" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 2 , 0 , TARGET_STRING (
"TrimFandM/Forces and Moments/Thrust/Throttle" ) , TARGET_STRING ( "" ) , 0 ,
0 , 1 , 0 , 1 } , { 3 , 0 , TARGET_STRING (
"TrimFandM/Forces and Moments/Weight/Product2" ) , TARGET_STRING ( "" ) , 0 ,
0 , 1 , 0 , 1 } , { 4 , 0 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Aero Attributes/Trigonometric Function2"
) , TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 1 } , { 5 , 0 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Forces/Aerodynamic Forces/Product1"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 1 } , { 6 , 0 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Moments/Pitch Moment Coefficient/Cm0"
) , TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 1 } , { 7 , 0 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Moments/Pitch Moment Coefficient/cmM"
) , TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 1 } , { 8 , 0 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Moments/Pitch Moment Coefficient/cmalpha"
) , TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 1 } , { 9 , 0 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Moments/Pitch Moment Coefficient/cmalphadot"
) , TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 1 } , { 10 , 0 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Moments/Pitch Moment Coefficient/cmdelta_e"
) , TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 1 } , { 11 , 0 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Moments/Pitch Moment Coefficient/cmdelta_f"
) , TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 1 } , { 12 , 0 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Moments/Pitch Moment Coefficient/cmq"
) , TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 1 } , { 0 , 0 , ( NULL ) , ( NULL
) , 0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_BlockParameters
rtBlockParameters [ ] = { { 13 , TARGET_STRING ( "TrimFandM/Constant1" ) ,
TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 14 , TARGET_STRING (
"TrimFandM/Constant3" ) , TARGET_STRING ( "Value" ) , 0 , 3 , 0 } , { 15 ,
TARGET_STRING ( "TrimFandM/Constant4" ) , TARGET_STRING ( "Value" ) , 0 , 1 ,
0 } , { 16 , TARGET_STRING ( "TrimFandM/Constant5" ) , TARGET_STRING (
"Value" ) , 0 , 1 , 0 } , { 17 , TARGET_STRING ( "TrimFandM/Constant6" ) ,
TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 18 , TARGET_STRING (
"TrimFandM/Constant7" ) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 19 ,
TARGET_STRING (
"TrimFandM/Forces and Moments/Gravity Calculator/Flat Earth to LLA" ) ,
TARGET_STRING ( "LL0" ) , 0 , 4 , 0 } , { 20 , TARGET_STRING (
"TrimFandM/Forces and Moments/Gravity Calculator/Flat Earth to LLA" ) ,
TARGET_STRING ( "psi" ) , 0 , 2 , 0 } , { 21 , TARGET_STRING (
"TrimFandM/Forces and Moments/Gravity Calculator/Ref Alt" ) , TARGET_STRING (
"Value" ) , 0 , 2 , 0 } , { 22 , TARGET_STRING (
"TrimFandM/Forces and Moments/Thrust/Trim Thrust1" ) , TARGET_STRING (
"Value" ) , 0 , 2 , 0 } , { 23 , TARGET_STRING (
"TrimFandM/Forces and Moments/Thrust/Trim Thrust2" ) , TARGET_STRING (
"Value" ) , 0 , 2 , 0 } , { 24 , TARGET_STRING (
"TrimFandM/Forces and Moments/Thrust/Trim Thrust3" ) , TARGET_STRING (
"Value" ) , 0 , 2 , 0 } , { 25 , TARGET_STRING (
"TrimFandM/Forces and Moments/Thrust/Trim Thrust4" ) , TARGET_STRING (
"Value" ) , 0 , 2 , 0 } , { 26 , TARGET_STRING (
"TrimFandM/Forces and Moments/Thrust/Trim Thrust5" ) , TARGET_STRING (
"Value" ) , 0 , 1 , 0 } , { 27 , TARGET_STRING (
"TrimFandM/Forces and Moments/Thrust/Throttle" ) , TARGET_STRING ( "Gain" ) ,
0 , 2 , 0 } , { 28 , TARGET_STRING (
"TrimFandM/Forces and Moments/Thrust/Manual Switch" ) , TARGET_STRING (
"CurrentSetting" ) , 1 , 2 , 0 } , { 29 , TARGET_STRING (
"TrimFandM/Forces and Moments/Weight/Trim Thrust5" ) , TARGET_STRING (
"Value" ) , 0 , 1 , 0 } , { 30 , TARGET_STRING (
"TrimFandM/Forces and Moments/Weight/mass" ) , TARGET_STRING ( "Value" ) , 0
, 2 , 0 } , { 31 , TARGET_STRING (
"TrimFandM/Forces and Moments/Weight/Gain1" ) , TARGET_STRING ( "Gain" ) , 0
, 2 , 0 } , { 32 , TARGET_STRING (
"TrimFandM/Forces and Moments/Thrust/Signal Builder/FromWs" ) , TARGET_STRING
( "Time0" ) , 0 , 5 , 0 } , { 33 , TARGET_STRING (
"TrimFandM/Forces and Moments/Thrust/Signal Builder/FromWs" ) , TARGET_STRING
( "Data0" ) , 0 , 5 , 0 } , { 34 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Aero Attributes/Dynamic Pressure Calc/Gain"
) , TARGET_STRING ( "Gain" ) , 0 , 2 , 0 } , { 35 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Aero Attributes/Subsystem/Altitude of Troposphere"
) , TARGET_STRING ( "Value" ) , 0 , 2 , 0 } , { 36 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Aero Attributes/Subsystem/Sea Level  Temperature"
) , TARGET_STRING ( "Value" ) , 0 , 2 , 0 } , { 37 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Aero Attributes/Subsystem/g//(L*R)"
) , TARGET_STRING ( "Value" ) , 0 , 2 , 0 } , { 38 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Aero Attributes/Subsystem/1//T0"
) , TARGET_STRING ( "Gain" ) , 0 , 2 , 0 } , { 39 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Aero Attributes/Subsystem/Lapse Rate"
) , TARGET_STRING ( "Gain" ) , 0 , 2 , 0 } , { 40 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Aero Attributes/Subsystem/g//R"
) , TARGET_STRING ( "Gain" ) , 0 , 2 , 0 } , { 41 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Aero Attributes/Subsystem/gamma*R"
) , TARGET_STRING ( "Gain" ) , 0 , 2 , 0 } , { 42 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Aero Attributes/Subsystem/rho0"
) , TARGET_STRING ( "Gain" ) , 0 , 2 , 0 } , { 43 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Aero Attributes/Subsystem/Limit  altitude  to Stratosphere"
) , TARGET_STRING ( "UpperLimit" ) , 0 , 2 , 0 } , { 44 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Aero Attributes/Subsystem/Limit  altitude  to Stratosphere"
) , TARGET_STRING ( "LowerLimit" ) , 0 , 2 , 0 } , { 45 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Aero Attributes/Subsystem/Limit  altitude  to troposhere"
) , TARGET_STRING ( "UpperLimit" ) , 0 , 2 , 0 } , { 46 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Aero Attributes/Subsystem/Limit  altitude  to troposhere"
) , TARGET_STRING ( "LowerLimit" ) , 0 , 2 , 0 } , { 47 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Forces/Aerodynamic Forces/Wing Area"
) , TARGET_STRING ( "Value" ) , 0 , 2 , 0 } , { 48 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Forces/Aerodynamic Forces/ChSign"
) , TARGET_STRING ( "Gain" ) , 0 , 2 , 0 } , { 49 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Forces/Aerodynamic Forces/ChSign1"
) , TARGET_STRING ( "Gain" ) , 0 , 2 , 0 } , { 50 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Forces/Aerodynamic Forces/ChSign2"
) , TARGET_STRING ( "Gain" ) , 0 , 2 , 0 } , { 51 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Forces/Force Coefficients Calculator/Drag Coefficient"
) , TARGET_STRING ( "cD0" ) , 0 , 2 , 0 } , { 52 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Forces/Force Coefficients Calculator/Lift Coefficient"
) , TARGET_STRING ( "cL0" ) , 0 , 2 , 0 } , { 53 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Forces/Force Coefficients Calculator/Lift Coefficient"
) , TARGET_STRING ( "meanchord" ) , 0 , 2 , 0 } , { 54 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Moments/Aerodynamic Moment /Wing area"
) , TARGET_STRING ( "Value" ) , 0 , 2 , 0 } , { 55 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Moments/Aerodynamic Moment /Wing chord"
) , TARGET_STRING ( "Value" ) , 0 , 2 , 0 } , { 56 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Moments/Aerodynamic Moment /Wing span"
) , TARGET_STRING ( "Value" ) , 0 , 2 , 0 } , { 57 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Moments/Aerodynamic Moment /Wing span2"
) , TARGET_STRING ( "Value" ) , 0 , 2 , 0 } , { 58 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Moments/Aerodynamic Moment /Gain"
) , TARGET_STRING ( "Gain" ) , 0 , 2 , 0 } , { 59 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Moments/Pitch Moment Coefficient/Cm0"
) , TARGET_STRING ( "Value" ) , 0 , 2 , 0 } , { 60 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Moments/Pitch Moment Coefficient/Wing chord"
) , TARGET_STRING ( "Value" ) , 0 , 2 , 0 } , { 61 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Moments/Pitch Moment Coefficient/2"
) , TARGET_STRING ( "Gain" ) , 0 , 2 , 0 } , { 62 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Moments/Pitch Moment Coefficient/cmM"
) , TARGET_STRING ( "Gain" ) , 0 , 2 , 0 } , { 63 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Moments/Pitch Moment Coefficient/cmalpha"
) , TARGET_STRING ( "Gain" ) , 0 , 2 , 0 } , { 64 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Moments/Pitch Moment Coefficient/cmalphadot"
) , TARGET_STRING ( "Gain" ) , 0 , 2 , 0 } , { 65 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Moments/Pitch Moment Coefficient/cmdelta_e"
) , TARGET_STRING ( "Gain" ) , 0 , 2 , 0 } , { 66 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Moments/Pitch Moment Coefficient/cmdelta_f"
) , TARGET_STRING ( "Gain" ) , 0 , 2 , 0 } , { 67 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Moments/Pitch Moment Coefficient/cmq"
) , TARGET_STRING ( "Gain" ) , 0 , 2 , 0 } , { 68 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Moments/Roll Moment Coefficient/Wing span"
) , TARGET_STRING ( "Value" ) , 0 , 2 , 0 } , { 69 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Moments/Roll Moment Coefficient/2"
) , TARGET_STRING ( "Gain" ) , 0 , 2 , 0 } , { 70 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Moments/Roll Moment Coefficient/clbeta"
) , TARGET_STRING ( "Gain" ) , 0 , 2 , 0 } , { 71 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Moments/Roll Moment Coefficient/cldelta_a"
) , TARGET_STRING ( "Gain" ) , 0 , 2 , 0 } , { 72 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Moments/Roll Moment Coefficient/cldelta_r"
) , TARGET_STRING ( "Gain" ) , 0 , 2 , 0 } , { 73 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Moments/Roll Moment Coefficient/clp"
) , TARGET_STRING ( "Gain" ) , 0 , 2 , 0 } , { 74 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Moments/Roll Moment Coefficient/clr"
) , TARGET_STRING ( "Gain" ) , 0 , 2 , 0 } , { 75 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Moments/Yaw Moment Coefficient/Wing span"
) , TARGET_STRING ( "Value" ) , 0 , 2 , 0 } , { 76 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Moments/Yaw Moment Coefficient/2"
) , TARGET_STRING ( "Gain" ) , 0 , 2 , 0 } , { 77 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Moments/Yaw Moment Coefficient/cnbeta"
) , TARGET_STRING ( "Gain" ) , 0 , 2 , 0 } , { 78 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Moments/Yaw Moment Coefficient/cndelta_a"
) , TARGET_STRING ( "Gain" ) , 0 , 2 , 0 } , { 79 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Moments/Yaw Moment Coefficient/cndelta_r"
) , TARGET_STRING ( "Gain" ) , 0 , 2 , 0 } , { 80 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Moments/Yaw Moment Coefficient/cnp"
) , TARGET_STRING ( "Gain" ) , 0 , 2 , 0 } , { 81 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Moments/Yaw Moment Coefficient/cnr"
) , TARGET_STRING ( "Gain" ) , 0 , 2 , 0 } , { 82 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LatLong wrap/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 2 , 0 } , { 83 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LatLong wrap/Constant1"
) , TARGET_STRING ( "Value" ) , 0 , 2 , 0 } , { 84 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LatLong wrap1/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 2 , 0 } , { 85 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LatLong wrap1/Constant1"
) , TARGET_STRING ( "Value" ) , 0 , 2 , 0 } , { 86 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Forces/Aerodynamic Forces/Wind2Body TM/Zero"
) , TARGET_STRING ( "Value" ) , 0 , 2 , 0 } , { 87 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Forces/Aerodynamic Forces/Wind2Body TM/ChSign"
) , TARGET_STRING ( "Gain" ) , 0 , 2 , 0 } , { 88 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Forces/Aerodynamic Forces/Wind2Body TM/ChSign1"
) , TARGET_STRING ( "Gain" ) , 0 , 2 , 0 } , { 89 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Forces/Aerodynamic Forces/Wind2Body TM/ChSign2"
) , TARGET_STRING ( "Gain" ) , 0 , 2 , 0 } , { 90 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Forces/Force Coefficients Calculator/Drag Coefficient/Induced Drag"
) , TARGET_STRING ( "Gain" ) , 0 , 2 , 0 } , { 91 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Forces/Force Coefficients Calculator/Drag Coefficient/cDM"
) , TARGET_STRING ( "Gain" ) , 0 , 2 , 0 } , { 92 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Forces/Force Coefficients Calculator/Drag Coefficient/cDalpha"
) , TARGET_STRING ( "Gain" ) , 0 , 2 , 0 } , { 93 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Forces/Force Coefficients Calculator/Drag Coefficient/cDdelta_a"
) , TARGET_STRING ( "Gain" ) , 0 , 2 , 0 } , { 94 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Forces/Force Coefficients Calculator/Drag Coefficient/cDdelta_e"
) , TARGET_STRING ( "Gain" ) , 0 , 2 , 0 } , { 95 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Forces/Force Coefficients Calculator/Drag Coefficient/cDdelta_f"
) , TARGET_STRING ( "Gain" ) , 0 , 2 , 0 } , { 96 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Forces/Force Coefficients Calculator/Drag Coefficient/cDdelta_r"
) , TARGET_STRING ( "Gain" ) , 0 , 2 , 0 } , { 97 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Forces/Force Coefficients Calculator/Lift Coefficient/1"
) , TARGET_STRING ( "Gain" ) , 0 , 2 , 0 } , { 98 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Forces/Force Coefficients Calculator/Lift Coefficient/CLM"
) , TARGET_STRING ( "Gain" ) , 0 , 2 , 0 } , { 99 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Forces/Force Coefficients Calculator/Lift Coefficient/cLalpha"
) , TARGET_STRING ( "Gain" ) , 0 , 2 , 0 } , { 100 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Forces/Force Coefficients Calculator/Lift Coefficient/cLalphadot"
) , TARGET_STRING ( "Gain" ) , 0 , 2 , 0 } , { 101 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Forces/Force Coefficients Calculator/Lift Coefficient/cLdelta_e"
) , TARGET_STRING ( "Gain" ) , 0 , 2 , 0 } , { 102 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Forces/Force Coefficients Calculator/Lift Coefficient/cLdelta_f"
) , TARGET_STRING ( "Gain" ) , 0 , 2 , 0 } , { 103 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Forces/Force Coefficients Calculator/Lift Coefficient/cLq"
) , TARGET_STRING ( "Gain" ) , 0 , 2 , 0 } , { 104 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Forces/Force Coefficients Calculator/SideForce Coefficient/Wing span"
) , TARGET_STRING ( "Value" ) , 0 , 2 , 0 } , { 105 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Forces/Force Coefficients Calculator/SideForce Coefficient/2"
) , TARGET_STRING ( "Gain" ) , 0 , 2 , 0 } , { 106 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Forces/Force Coefficients Calculator/SideForce Coefficient/cYbeta"
) , TARGET_STRING ( "Gain" ) , 0 , 2 , 0 } , { 107 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Forces/Force Coefficients Calculator/SideForce Coefficient/cYdelta_a"
) , TARGET_STRING ( "Gain" ) , 0 , 2 , 0 } , { 108 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Forces/Force Coefficients Calculator/SideForce Coefficient/cYdelta_r"
) , TARGET_STRING ( "Gain" ) , 0 , 2 , 0 } , { 109 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Forces/Force Coefficients Calculator/SideForce Coefficient/cYp"
) , TARGET_STRING ( "Gain" ) , 0 , 2 , 0 } , { 110 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Forces/Force Coefficients Calculator/SideForce Coefficient/cYr"
) , TARGET_STRING ( "Gain" ) , 0 , 2 , 0 } , { 111 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Moments/Aerodynamic Moment /Wind2Body TM/Zero"
) , TARGET_STRING ( "Value" ) , 0 , 2 , 0 } , { 112 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Moments/Aerodynamic Moment /Wind2Body TM/ChSign"
) , TARGET_STRING ( "Gain" ) , 0 , 2 , 0 } , { 113 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Moments/Aerodynamic Moment /Wind2Body TM/ChSign1"
) , TARGET_STRING ( "Gain" ) , 0 , 2 , 0 } , { 114 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Aerodynamic Forces and /Moments/Aerodynamic Moment /Wind2Body TM/ChSign2"
) , TARGET_STRING ( "Gain" ) , 0 , 2 , 0 } , { 115 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Compare To Constant"
) , TARGET_STRING ( "const" ) , 0 , 2 , 0 } , { 116 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Bias"
) , TARGET_STRING ( "Bias" ) , 0 , 2 , 0 } , { 117 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Bias1"
) , TARGET_STRING ( "Bias" ) , 0 , 2 , 0 } , { 118 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Gain"
) , TARGET_STRING ( "Gain" ) , 0 , 2 , 0 } , { 119 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LatLong wrap/Wrap Longitude/Compare To Constant"
) , TARGET_STRING ( "const" ) , 0 , 2 , 0 } , { 120 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LatLong wrap/Wrap Longitude/Bias"
) , TARGET_STRING ( "Bias" ) , 0 , 2 , 0 } , { 121 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LatLong wrap/Wrap Longitude/Bias1"
) , TARGET_STRING ( "Bias" ) , 0 , 2 , 0 } , { 122 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LatLong wrap/Wrap Longitude/Constant2"
) , TARGET_STRING ( "Value" ) , 0 , 2 , 0 } , { 123 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Compare To Constant"
) , TARGET_STRING ( "const" ) , 0 , 2 , 0 } , { 124 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Bias"
) , TARGET_STRING ( "Bias" ) , 0 , 2 , 0 } , { 125 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Bias1"
) , TARGET_STRING ( "Bias" ) , 0 , 2 , 0 } , { 126 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Gain"
) , TARGET_STRING ( "Gain" ) , 0 , 2 , 0 } , { 127 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LatLong wrap1/Wrap Longitude/Compare To Constant"
) , TARGET_STRING ( "const" ) , 0 , 2 , 0 } , { 128 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LatLong wrap1/Wrap Longitude/Bias"
) , TARGET_STRING ( "Bias" ) , 0 , 2 , 0 } , { 129 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LatLong wrap1/Wrap Longitude/Bias1"
) , TARGET_STRING ( "Bias" ) , 0 , 2 , 0 } , { 130 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LatLong wrap1/Wrap Longitude/Constant2"
) , TARGET_STRING ( "Value" ) , 0 , 2 , 0 } , { 131 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 2 , 0 } , { 132 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/Constant1"
) , TARGET_STRING ( "Value" ) , 0 , 2 , 0 } , { 133 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/Constant2"
) , TARGET_STRING ( "Value" ) , 0 , 2 , 0 } , { 134 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/Constant3"
) , TARGET_STRING ( "Value" ) , 0 , 2 , 0 } , { 135 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant"
) , TARGET_STRING ( "const" ) , 0 , 2 , 0 } , { 136 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Bias"
) , TARGET_STRING ( "Bias" ) , 0 , 2 , 0 } , { 137 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Bias1"
) , TARGET_STRING ( "Bias" ) , 0 , 2 , 0 } , { 138 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Constant2"
) , TARGET_STRING ( "Value" ) , 0 , 2 , 0 } , { 139 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Wrap Angle 180/Compare To Constant"
) , TARGET_STRING ( "const" ) , 0 , 2 , 0 } , { 140 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Wrap Angle 180/Bias"
) , TARGET_STRING ( "Bias" ) , 0 , 2 , 0 } , { 141 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Wrap Angle 180/Bias1"
) , TARGET_STRING ( "Bias" ) , 0 , 2 , 0 } , { 142 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Wrap Angle 180/Constant2"
) , TARGET_STRING ( "Value" ) , 0 , 2 , 0 } , { 143 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/denom/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 2 , 0 } , { 144 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/e/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 2 , 0 } , { 145 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/e/f"
) , TARGET_STRING ( "Value" ) , 0 , 2 , 0 } , { 146 , TARGET_STRING (
 "TrimFandM/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/e^4/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 2 , 0 } , { 0 , ( NULL ) , ( NULL ) , 0 ,
0 , 0 } } ; static const rtwCAPI_ModelParameters rtModelParameters [ ] = { {
0 , ( NULL ) , 0 , 0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . cewmuklpud [ 0 ] , & rtB .
eitentvc2c [ 0 ] , & rtB . dkxpu1nqs1 [ 0 ] , & rtB . h5b40zrgbx [ 0 ] , &
rtB . c155b3ttul , & rtB . n20ebdvrmd [ 0 ] , & rtB . a3vyc4l10x , & rtB .
k1zmldxyil , & rtB . oouqhb3v3v , & rtB . lqji0le141 , & rtB . lbnjpcgymq , &
rtB . gqpi3oabc5 , & rtB . iwltmc0fj1 , & rtP . Constant1_Value [ 0 ] , & rtP
. Constant3_Value [ 0 ] , & rtP . Constant4_Value [ 0 ] , & rtP .
Constant5_Value [ 0 ] , & rtP . Constant6_Value [ 0 ] , & rtP .
Constant7_Value [ 0 ] , & rtP . FlatEarthtoLLA_LL0 [ 0 ] , & rtP .
FlatEarthtoLLA_psi , & rtP . RefAlt_Value , & rtP . TrimThrust1_Value , & rtP
. TrimThrust2_Value , & rtP . TrimThrust3_Value , & rtP . TrimThrust4_Value ,
& rtP . TrimThrust5_Value [ 0 ] , & rtP . Throttle_Gain , & rtP .
ManualSwitch_CurrentSetting , & rtP . TrimThrust5_Value_aggklib54h [ 0 ] , &
rtP . mass_Value , & rtP . Gain1_Gain , & rtP . FromWs_Time0 [ 0 ] , & rtP .
FromWs_Data0 [ 0 ] , & rtP . Gain_Gain_i2ygq2tusg , & rtP .
AltitudeofTroposphere_Value , & rtP . SeaLevelTemperature_Value , & rtP .
gLR_Value , & rtP . uT0_Gain , & rtP . LapseRate_Gain , & rtP . gR_Gain , &
rtP . gammaR_Gain , & rtP . rho0_Gain , & rtP .
LimitaltitudetoStratosphere_UpperSat , & rtP .
LimitaltitudetoStratosphere_LowerSat , & rtP .
Limitaltitudetotroposhere_UpperSat , & rtP .
Limitaltitudetotroposhere_LowerSat , & rtP . WingArea_Value , & rtP .
ChSign_Gain_k0w4nqg0k2 , & rtP . ChSign1_Gain_n4wwtfjx2h , & rtP .
ChSign2_Gain_effoydn3u1 , & rtP . DragCoefficient_cD0 , & rtP .
LiftCoefficient_cL0 , & rtP . LiftCoefficient_meanchord , & rtP .
Wingarea_Value , & rtP . Wingchord_Value , & rtP . Wingspan_Value , & rtP .
Wingspan2_Value , & rtP . Gain_Gain , & rtP . Cm0_Value , & rtP .
Wingchord_Value_pdh1mmrkaf , & rtP . u_Gain_c3gtfmblii , & rtP . cmM_Gain , &
rtP . cmalpha_Gain , & rtP . cmalphadot_Gain , & rtP . cmdelta_e_Gain , & rtP
. cmdelta_f_Gain , & rtP . cmq_Gain , & rtP . Wingspan_Value_abjhsc0f24 , &
rtP . u_Gain , & rtP . clbeta_Gain , & rtP . cldelta_a_Gain , & rtP .
cldelta_r_Gain , & rtP . clp_Gain , & rtP . clr_Gain , & rtP .
Wingspan_Value_e2odjstrw4 , & rtP . u_Gain_allopj2sjw , & rtP . cnbeta_Gain ,
& rtP . cndelta_a_Gain , & rtP . cndelta_r_Gain , & rtP . cnp_Gain , & rtP .
cnr_Gain , & rtP . Constant_Value , & rtP . Constant1_Value_gzve1ir0t2 , &
rtP . Constant_Value_mxa0cv5de4 , & rtP . Constant1_Value_pwlq2ttr5w , & rtP
. Zero_Value_mumexc0o4r , & rtP . ChSign_Gain_gtanyi5b3f , & rtP .
ChSign1_Gain_nkytdev4sk , & rtP . ChSign2_Gain_knade2nq5x , & rtP .
InducedDrag_Gain , & rtP . cDM_Gain , & rtP . cDalpha_Gain , & rtP .
cDdelta_a_Gain , & rtP . cDdelta_e_Gain , & rtP . cDdelta_f_Gain , & rtP .
cDdelta_r_Gain , & rtP . u_Gain_nvhs5kychw , & rtP . CLM_Gain , & rtP .
cLalpha_Gain , & rtP . cLalphadot_Gain , & rtP . cLdelta_e_Gain , & rtP .
cLdelta_f_Gain , & rtP . cLq_Gain , & rtP . Wingspan_Value_n3iuon0ekq , & rtP
. u_Gain_fra5iqtqqa , & rtP . cYbeta_Gain , & rtP . cYdelta_a_Gain , & rtP .
cYdelta_r_Gain , & rtP . cYp_Gain , & rtP . cYr_Gain , & rtP . Zero_Value , &
rtP . ChSign_Gain , & rtP . ChSign1_Gain , & rtP . ChSign2_Gain , & rtP .
CompareToConstant_const_m35urglgce , & rtP . Bias_Bias_mvispiykz2 , & rtP .
Bias1_Bias_bohiusfzhl , & rtP . Gain_Gain_lt1rzsj1bc , & rtP .
CompareToConstant_const_nfpclnqcaz , & rtP . Bias_Bias_hfb13vpfjg , & rtP .
Bias1_Bias_hdwwrgv0bw , & rtP . Constant2_Value_a3oznwkh02 , & rtP .
CompareToConstant_const_lqd2aov4ko , & rtP . Bias_Bias_d2nkgtoec1 , & rtP .
Bias1_Bias_gu4d3m1zk1 , & rtP . Gain_Gain_hksk452z1z , & rtP .
CompareToConstant_const_gbmczedm2k , & rtP . Bias_Bias_b2ra0lewbe , & rtP .
Bias1_Bias_eoswi2rhti , & rtP . Constant2_Value_mqqkn141fi , & rtP .
Constant_Value_ch1bn1coed , & rtP . Constant1_Value_axlwkx0upk , & rtP .
Constant2_Value , & rtP . Constant3_Value_g2ewzhwyko , & rtP .
CompareToConstant_const_ohveajuklj , & rtP . Bias_Bias_kpaulxvgkm , & rtP .
Bias1_Bias_cgno1ebhcg , & rtP . Constant2_Value_h4ldodunib , & rtP .
CompareToConstant_const , & rtP . Bias_Bias , & rtP . Bias1_Bias , & rtP .
Constant2_Value_mq0ugbio0d , & rtP . Constant_Value_nc3vt5cgfc , & rtP .
Constant_Value_m5g2px2tx2 , & rtP . f_Value , & rtP .
Constant_Value_cvu4p50c1r , } ; static int32_T * rtVarDimsAddrMap [ ] = { (
NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , SS_DOUBLE , 0 , 0 , 0 } , {
"unsigned char" , "uint8_T" , 0 , 0 , sizeof ( uint8_T ) , SS_UINT8 , 0 , 0 ,
0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_MATRIX_COL_MAJOR , 0 , 2 , 0 } , { rtwCAPI_VECTOR , 0 , 2 , 0 } , {
rtwCAPI_SCALAR , 2 , 2 , 0 } , { rtwCAPI_VECTOR , 4 , 2 , 0 } , {
rtwCAPI_VECTOR , 6 , 2 , 0 } , { rtwCAPI_VECTOR , 8 , 2 , 0 } } ; static
const uint_T rtDimensionArray [ ] = { 3 , 1 , 1 , 1 , 4 , 1 , 1 , 2 , 6 , 1 }
; static const real_T rtcapiStoredFloats [ ] = { 0.0 } ; static const
rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) ,
rtwCAPI_FIX_RESERVED , 0 , 0 , 0 } , } ; static const rtwCAPI_SampleTimeMap
rtSampleTimeMap [ ] = { { ( const void * ) & rtcapiStoredFloats [ 0 ] , (
const void * ) & rtcapiStoredFloats [ 0 ] , 0 , 0 } , { ( NULL ) , ( NULL ) ,
1 , 0 } } ; static rtwCAPI_ModelMappingStaticInfo mmiStatic = { {
rtBlockSignals , 13 , ( NULL ) , 0 , ( NULL ) , 0 } , { rtBlockParameters ,
134 , rtModelParameters , 0 } , { ( NULL ) , 0 } , { rtDataTypeMap ,
rtDimensionMap , rtFixPtMap , rtElementMap , rtSampleTimeMap ,
rtDimensionArray } , "float" , { 252174475U , 3684857294U , 833005927U ,
3066074947U } , ( NULL ) , 0 , 0 } ; const rtwCAPI_ModelMappingStaticInfo *
TrimFandM_GetCAPIStaticMap ( void ) { return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void TrimFandM_InitializeDataMapInfo ( void ) { rtwCAPI_SetVersion ( ( *
rt_dataMapInfoPtr ) . mmi , 1 ) ; rtwCAPI_SetStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ; rtwCAPI_SetLoggingStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ; rtwCAPI_SetDataAddressMap ( ( *
rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ; rtwCAPI_SetVarDimsAddressMap (
( * rt_dataMapInfoPtr ) . mmi , rtVarDimsAddrMap ) ;
rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi , 0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void TrimFandM_host_InitializeDataMapInfo ( TrimFandM_host_DataMapInfo_T *
dataMap , const char * path ) { rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ;
rtwCAPI_SetStaticMap ( dataMap -> mmi , & mmiStatic ) ;
rtwCAPI_SetDataAddressMap ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , NULL ) ; rtwCAPI_SetPath (
dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
