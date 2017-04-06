#include "__cf_DatcomForceMoment.h"
#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "DatcomForceMoment_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)    
#else
#include "builtin_typeid_types.h"
#include "DatcomForceMoment.h"
#include "DatcomForceMoment_capi.h"
#include "DatcomForceMoment_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST                  
#define TARGET_STRING(s)               (NULL)                    
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , TARGET_STRING (
"DatcomForceMoment/Sum" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 1
, 0 , TARGET_STRING ( "DatcomForceMoment/Sum1" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 0 } , { 2 , 0 , TARGET_STRING (
"DatcomForceMoment/Aero Attributes/Derivative2" ) , TARGET_STRING ( "Betadot"
) , 0 , 0 , 1 , 0 , 0 } , { 3 , 0 , TARGET_STRING (
"DatcomForceMoment/Aero Attributes/Beta Saturation" ) , TARGET_STRING ( "" )
, 0 , 0 , 1 , 0 , 1 } , { 4 , 0 , TARGET_STRING (
"DatcomForceMoment/Aero Attributes/Beta Saturation1" ) , TARGET_STRING ( "" )
, 0 , 0 , 1 , 0 , 0 } , { 5 , 0 , TARGET_STRING (
"DatcomForceMoment/Aero Attributes/Trigonometric Function2" ) , TARGET_STRING
( "" ) , 0 , 0 , 1 , 0 , 1 } , { 6 , 0 , TARGET_STRING (
"DatcomForceMoment/Aero Attributes/Trigonometric Function3" ) , TARGET_STRING
( "" ) , 0 , 0 , 1 , 0 , 1 } , { 7 , 0 , TARGET_STRING (
"DatcomForceMoment/Thrust /Throttle" ) , TARGET_STRING ( "" ) , 0 , 0 , 2 , 0
, 1 } , { 8 , 0 , TARGET_STRING ( "DatcomForceMoment/Weight/Product2" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 1 } , { 9 , 0 , TARGET_STRING (
"DatcomForceMoment/Weight/Product3" ) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0
, 1 } , { 10 , 0 , TARGET_STRING ( "DatcomForceMoment/Weight/Product6" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 1 } , { 11 , 0 , TARGET_STRING (
"DatcomForceMoment/Digital DATCOM v1.0.2/Dynamic Contribution/CLad1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 1 } , { 12 , 0 , TARGET_STRING (
"DatcomForceMoment/Digital DATCOM v1.0.2/Dynamic Contribution/CYp1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 1 } , { 13 , 0 , TARGET_STRING (
"DatcomForceMoment/Digital DATCOM v1.0.2/Dynamic Contribution/Clp1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 1 } , { 14 , 0 , TARGET_STRING (
"DatcomForceMoment/Digital DATCOM v1.0.2/Dynamic Contribution/Clq1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 1 } , { 15 , 0 , TARGET_STRING (
"DatcomForceMoment/Digital DATCOM v1.0.2/Dynamic Contribution/Clr1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 1 } , { 16 , 0 , TARGET_STRING (
"DatcomForceMoment/Digital DATCOM v1.0.2/Dynamic Contribution/Cmad1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 1 } , { 17 , 0 , TARGET_STRING (
"DatcomForceMoment/Digital DATCOM v1.0.2/Dynamic Contribution/Cmq1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 1 } , { 18 , 0 , TARGET_STRING (
"DatcomForceMoment/Digital DATCOM v1.0.2/Dynamic Contribution/Cnp1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 1 } , { 19 , 0 , TARGET_STRING (
"DatcomForceMoment/Digital DATCOM v1.0.2/Dynamic Contribution/Cnr1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 1 } , { 20 , 0 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Dynamic Contribution/Aerodynamic Forces and Moments Stability Axis/Product1"
) , TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 1 } , { 21 , 0 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Dynamic Contribution/Aerodynamic Forces and Moments Stability Axis/Product2"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 1 } , { 22 , 0 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Dynamic Contribution/Incidence, Sideslip, & Airspeed1/Airspeed"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 1 } , { 23 , 0 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Dynamic Contribution/Stability Angular Rates/Product2"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 1 } , { 24 , 0 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Dynamic Contribution/Stability Angular Rates/Unary Minus1"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 1 } , { 25 , 0 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Deflection/Aerodynamic Forces and Moments/Force Transformation/Product"
) , TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 1 } , { 26 , 0 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Deflection/Aerodynamic Forces and Moments/Moment Transformation/Product"
) , TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 1 } , { 27 , 0 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Dynamic Contribution/Aerodynamic Forces and Moments Stability Axis/CG-CP Transformation/Product"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 28 , 0 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Dynamic Contribution/Aerodynamic Forces and Moments Stability Axis/Force Transformation/Transpose"
) , TARGET_STRING ( "Stability2Body" ) , 0 , 0 , 3 , 0 , 1 } , { 29 , 0 ,
TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Dynamic Contribution/Aerodynamic Forces and Moments Stability Axis/Moment Transformation/Transpose"
) , TARGET_STRING ( "Stability2Body" ) , 0 , 0 , 3 , 0 , 1 } , { 30 , 0 ,
TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Static Contribution/Aerodynamic Forces and Moments/Force Transformation/Product"
) , TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 1 } , { 31 , 0 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Static Contribution/Aerodynamic Forces and Moments/Moment Transformation/Product"
) , TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 1 } , { 32 , 0 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Dynamic Contribution/Stability Angular Rates/Direction Cosine Matrix Body to Wind/Create Transformation Matrix/Vector Concatenate"
) , TARGET_STRING ( "" ) , 0 , 0 , 4 , 0 , 1 } , { 0 , 0 , ( NULL ) , ( NULL
) , 0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_BlockParameters
rtBlockParameters [ ] = { { 33 , TARGET_STRING (
"DatcomForceMoment/Aero Attributes/Beta Saturation" ) , TARGET_STRING (
"UpperLimit" ) , 0 , 1 , 0 } , { 34 , TARGET_STRING (
"DatcomForceMoment/Aero Attributes/Beta Saturation" ) , TARGET_STRING (
"LowerLimit" ) , 0 , 1 , 0 } , { 35 , TARGET_STRING (
"DatcomForceMoment/Aero Attributes/Beta Saturation1" ) , TARGET_STRING (
"UpperLimit" ) , 0 , 1 , 0 } , { 36 , TARGET_STRING (
"DatcomForceMoment/Aero Attributes/Beta Saturation1" ) , TARGET_STRING (
"LowerLimit" ) , 0 , 1 , 0 } , { 37 , TARGET_STRING (
"DatcomForceMoment/Digital DATCOM v1.0.2/Constant" ) , TARGET_STRING (
"Value" ) , 0 , 1 , 0 } , { 38 , TARGET_STRING (
"DatcomForceMoment/Digital DATCOM v1.0.2/Constant1" ) , TARGET_STRING (
"Value" ) , 0 , 1 , 0 } , { 39 , TARGET_STRING (
"DatcomForceMoment/Digital DATCOM v1.0.2/Constant2" ) , TARGET_STRING (
"Value" ) , 0 , 1 , 0 } , { 40 , TARGET_STRING (
"DatcomForceMoment/Digital DATCOM v1.0.2/Constant3" ) , TARGET_STRING (
"Value" ) , 0 , 1 , 0 } , { 41 , TARGET_STRING (
"DatcomForceMoment/Digital DATCOM v1.0.2/Constant4" ) , TARGET_STRING (
"Value" ) , 0 , 1 , 0 } , { 42 , TARGET_STRING (
"DatcomForceMoment/Digital DATCOM v1.0.2/Constant5" ) , TARGET_STRING (
"Value" ) , 0 , 1 , 0 } , { 43 , TARGET_STRING (
"DatcomForceMoment/Digital DATCOM v1.0.2/Constant6" ) , TARGET_STRING (
"Value" ) , 0 , 1 , 0 } , { 44 , TARGET_STRING (
"DatcomForceMoment/Digital DATCOM v1.0.2/Constant7" ) , TARGET_STRING (
"Value" ) , 0 , 1 , 0 } , { 45 , TARGET_STRING (
"DatcomForceMoment/Digital DATCOM v1.0.2/Constant8" ) , TARGET_STRING (
"Value" ) , 0 , 1 , 0 } , { 46 , TARGET_STRING (
"DatcomForceMoment/Digital DATCOM v1.0.2/(Mach)" ) , TARGET_STRING (
"BreakpointsData" ) , 0 , 5 , 0 } , { 47 , TARGET_STRING (
"DatcomForceMoment/Digital DATCOM v1.0.2/(alpha)" ) , TARGET_STRING (
"BreakpointsData" ) , 0 , 6 , 0 } , { 48 , TARGET_STRING (
"DatcomForceMoment/Digital DATCOM v1.0.2/(altitude)" ) , TARGET_STRING (
"BreakpointsData" ) , 0 , 7 , 0 } , { 49 , TARGET_STRING (
"DatcomForceMoment/Digital DATCOM v1.0.2/(delta_a)" ) , TARGET_STRING (
"BreakpointsData" ) , 0 , 6 , 0 } , { 50 , TARGET_STRING (
"DatcomForceMoment/Digital DATCOM v1.0.2/(delta_e)" ) , TARGET_STRING (
"BreakpointsData" ) , 0 , 6 , 0 } , { 51 , TARGET_STRING (
"DatcomForceMoment/Digital DATCOM v1.0.2/(delta_f)" ) , TARGET_STRING (
"BreakpointsData" ) , 0 , 6 , 0 } , { 52 , TARGET_STRING (
"DatcomForceMoment/Thrust /Trim Thrust1" ) , TARGET_STRING ( "Value" ) , 0 ,
1 , 0 } , { 53 , TARGET_STRING ( "DatcomForceMoment/Thrust /Trim Thrust2" ) ,
TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 54 , TARGET_STRING (
"DatcomForceMoment/Thrust /Trim Thrust3" ) , TARGET_STRING ( "Value" ) , 0 ,
1 , 0 } , { 55 , TARGET_STRING ( "DatcomForceMoment/Thrust /Trim Thrust4" ) ,
TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 56 , TARGET_STRING (
"DatcomForceMoment/Thrust /Trim Thrust5" ) , TARGET_STRING ( "Value" ) , 0 ,
2 , 0 } , { 57 , TARGET_STRING ( "DatcomForceMoment/Thrust /Throttle" ) ,
TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 58 , TARGET_STRING (
"DatcomForceMoment/Thrust /Manual Switch" ) , TARGET_STRING (
"CurrentSetting" ) , 1 , 1 , 0 } , { 59 , TARGET_STRING (
"DatcomForceMoment/Weight/Weight Force" ) , TARGET_STRING ( "Value" ) , 0 , 1
, 0 } , { 60 , TARGET_STRING ( "DatcomForceMoment/Weight/Weight Moment" ) ,
TARGET_STRING ( "Value" ) , 0 , 2 , 0 } , { 61 , TARGET_STRING (
"DatcomForceMoment/Weight/Gain1" ) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } ,
{ 62 , TARGET_STRING (
"DatcomForceMoment/Aero Attributes/Dynamic Pressure Calc/Gain" ) ,
TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 63 , TARGET_STRING (
"DatcomForceMoment/Aero Attributes/Subsystem/Altitude of Troposphere" ) ,
TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 64 , TARGET_STRING (
"DatcomForceMoment/Aero Attributes/Subsystem/Sea Level  Temperature" ) ,
TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 65 , TARGET_STRING (
"DatcomForceMoment/Aero Attributes/Subsystem/g//(L*R)" ) , TARGET_STRING (
"Value" ) , 0 , 1 , 0 } , { 66 , TARGET_STRING (
"DatcomForceMoment/Aero Attributes/Subsystem/1//T0" ) , TARGET_STRING (
"Gain" ) , 0 , 1 , 0 } , { 67 , TARGET_STRING (
"DatcomForceMoment/Aero Attributes/Subsystem/Lapse Rate" ) , TARGET_STRING (
"Gain" ) , 0 , 1 , 0 } , { 68 , TARGET_STRING (
"DatcomForceMoment/Aero Attributes/Subsystem/g//R" ) , TARGET_STRING ( "Gain"
) , 0 , 1 , 0 } , { 69 , TARGET_STRING (
"DatcomForceMoment/Aero Attributes/Subsystem/gamma*R" ) , TARGET_STRING (
"Gain" ) , 0 , 1 , 0 } , { 70 , TARGET_STRING (
"DatcomForceMoment/Aero Attributes/Subsystem/rho0" ) , TARGET_STRING ( "Gain"
) , 0 , 1 , 0 } , { 71 , TARGET_STRING (
"DatcomForceMoment/Aero Attributes/Subsystem/Limit  altitude  to Stratosphere"
) , TARGET_STRING ( "UpperLimit" ) , 0 , 1 , 0 } , { 72 , TARGET_STRING (
"DatcomForceMoment/Aero Attributes/Subsystem/Limit  altitude  to Stratosphere"
) , TARGET_STRING ( "LowerLimit" ) , 0 , 1 , 0 } , { 73 , TARGET_STRING (
"DatcomForceMoment/Aero Attributes/Subsystem/Limit  altitude  to troposhere"
) , TARGET_STRING ( "UpperLimit" ) , 0 , 1 , 0 } , { 74 , TARGET_STRING (
"DatcomForceMoment/Aero Attributes/Subsystem/Limit  altitude  to troposhere"
) , TARGET_STRING ( "LowerLimit" ) , 0 , 1 , 0 } , { 75 , TARGET_STRING (
"DatcomForceMoment/Digital DATCOM v1.0.2/Dynamic Contribution/1" ) ,
TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 76 , TARGET_STRING (
"DatcomForceMoment/Digital DATCOM v1.0.2/Dynamic Contribution/2" ) ,
TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 77 , TARGET_STRING (
"DatcomForceMoment/Digital DATCOM v1.0.2/Dynamic Contribution/3" ) ,
TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 78 , TARGET_STRING (
"DatcomForceMoment/Digital DATCOM v1.0.2/Dynamic Contribution/zero" ) ,
TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 79 , TARGET_STRING (
"DatcomForceMoment/Digital DATCOM v1.0.2/Dynamic Contribution/Gain1" ) ,
TARGET_STRING ( "Gain" ) , 0 , 8 , 0 } , { 80 , TARGET_STRING (
"DatcomForceMoment/Digital DATCOM v1.0.2/Dynamic Contribution/CLad1" ) ,
TARGET_STRING ( "Table" ) , 0 , 9 , 0 } , { 81 , TARGET_STRING (
"DatcomForceMoment/Digital DATCOM v1.0.2/Dynamic Contribution/CLad1" ) ,
TARGET_STRING ( "dimSizes" ) , 2 , 2 , 0 } , { 82 , TARGET_STRING (
"DatcomForceMoment/Digital DATCOM v1.0.2/Dynamic Contribution/CYp1" ) ,
TARGET_STRING ( "Table" ) , 0 , 9 , 0 } , { 83 , TARGET_STRING (
"DatcomForceMoment/Digital DATCOM v1.0.2/Dynamic Contribution/CYp1" ) ,
TARGET_STRING ( "dimSizes" ) , 2 , 2 , 0 } , { 84 , TARGET_STRING (
"DatcomForceMoment/Digital DATCOM v1.0.2/Dynamic Contribution/Clp1" ) ,
TARGET_STRING ( "Table" ) , 0 , 9 , 0 } , { 85 , TARGET_STRING (
"DatcomForceMoment/Digital DATCOM v1.0.2/Dynamic Contribution/Clp1" ) ,
TARGET_STRING ( "dimSizes" ) , 2 , 2 , 0 } , { 86 , TARGET_STRING (
"DatcomForceMoment/Digital DATCOM v1.0.2/Dynamic Contribution/Clq1" ) ,
TARGET_STRING ( "Table" ) , 0 , 9 , 0 } , { 87 , TARGET_STRING (
"DatcomForceMoment/Digital DATCOM v1.0.2/Dynamic Contribution/Clq1" ) ,
TARGET_STRING ( "dimSizes" ) , 2 , 2 , 0 } , { 88 , TARGET_STRING (
"DatcomForceMoment/Digital DATCOM v1.0.2/Dynamic Contribution/Clr1" ) ,
TARGET_STRING ( "Table" ) , 0 , 9 , 0 } , { 89 , TARGET_STRING (
"DatcomForceMoment/Digital DATCOM v1.0.2/Dynamic Contribution/Clr1" ) ,
TARGET_STRING ( "dimSizes" ) , 2 , 2 , 0 } , { 90 , TARGET_STRING (
"DatcomForceMoment/Digital DATCOM v1.0.2/Dynamic Contribution/Cmad1" ) ,
TARGET_STRING ( "Table" ) , 0 , 9 , 0 } , { 91 , TARGET_STRING (
"DatcomForceMoment/Digital DATCOM v1.0.2/Dynamic Contribution/Cmad1" ) ,
TARGET_STRING ( "dimSizes" ) , 2 , 2 , 0 } , { 92 , TARGET_STRING (
"DatcomForceMoment/Digital DATCOM v1.0.2/Dynamic Contribution/Cmq1" ) ,
TARGET_STRING ( "Table" ) , 0 , 9 , 0 } , { 93 , TARGET_STRING (
"DatcomForceMoment/Digital DATCOM v1.0.2/Dynamic Contribution/Cmq1" ) ,
TARGET_STRING ( "dimSizes" ) , 2 , 2 , 0 } , { 94 , TARGET_STRING (
"DatcomForceMoment/Digital DATCOM v1.0.2/Dynamic Contribution/Cnp1" ) ,
TARGET_STRING ( "Table" ) , 0 , 9 , 0 } , { 95 , TARGET_STRING (
"DatcomForceMoment/Digital DATCOM v1.0.2/Dynamic Contribution/Cnp1" ) ,
TARGET_STRING ( "dimSizes" ) , 2 , 2 , 0 } , { 96 , TARGET_STRING (
"DatcomForceMoment/Digital DATCOM v1.0.2/Dynamic Contribution/Cnr1" ) ,
TARGET_STRING ( "Table" ) , 0 , 9 , 0 } , { 97 , TARGET_STRING (
"DatcomForceMoment/Digital DATCOM v1.0.2/Dynamic Contribution/Cnr1" ) ,
TARGET_STRING ( "dimSizes" ) , 2 , 2 , 0 } , { 98 , TARGET_STRING (
"DatcomForceMoment/Digital DATCOM v1.0.2/Static Contribution/zero1" ) ,
TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 99 , TARGET_STRING (
"DatcomForceMoment/Digital DATCOM v1.0.2/Static Contribution/CD" ) ,
TARGET_STRING ( "Table" ) , 0 , 9 , 0 } , { 100 , TARGET_STRING (
"DatcomForceMoment/Digital DATCOM v1.0.2/Static Contribution/CD" ) ,
TARGET_STRING ( "dimSizes" ) , 2 , 2 , 0 } , { 101 , TARGET_STRING (
"DatcomForceMoment/Digital DATCOM v1.0.2/Static Contribution/CL" ) ,
TARGET_STRING ( "Table" ) , 0 , 9 , 0 } , { 102 , TARGET_STRING (
"DatcomForceMoment/Digital DATCOM v1.0.2/Static Contribution/CL" ) ,
TARGET_STRING ( "dimSizes" ) , 2 , 2 , 0 } , { 103 , TARGET_STRING (
"DatcomForceMoment/Digital DATCOM v1.0.2/Static Contribution/CYb" ) ,
TARGET_STRING ( "Table" ) , 0 , 9 , 0 } , { 104 , TARGET_STRING (
"DatcomForceMoment/Digital DATCOM v1.0.2/Static Contribution/CYb" ) ,
TARGET_STRING ( "dimSizes" ) , 2 , 2 , 0 } , { 105 , TARGET_STRING (
"DatcomForceMoment/Digital DATCOM v1.0.2/Static Contribution/Clb" ) ,
TARGET_STRING ( "Table" ) , 0 , 9 , 0 } , { 106 , TARGET_STRING (
"DatcomForceMoment/Digital DATCOM v1.0.2/Static Contribution/Clb" ) ,
TARGET_STRING ( "dimSizes" ) , 2 , 2 , 0 } , { 107 , TARGET_STRING (
"DatcomForceMoment/Digital DATCOM v1.0.2/Static Contribution/Cm" ) ,
TARGET_STRING ( "Table" ) , 0 , 9 , 0 } , { 108 , TARGET_STRING (
"DatcomForceMoment/Digital DATCOM v1.0.2/Static Contribution/Cm" ) ,
TARGET_STRING ( "dimSizes" ) , 2 , 2 , 0 } , { 109 , TARGET_STRING (
"DatcomForceMoment/Digital DATCOM v1.0.2/Static Contribution/Cnb" ) ,
TARGET_STRING ( "Table" ) , 0 , 9 , 0 } , { 110 , TARGET_STRING (
"DatcomForceMoment/Digital DATCOM v1.0.2/Static Contribution/Cnb" ) ,
TARGET_STRING ( "dimSizes" ) , 2 , 2 , 0 } , { 111 , TARGET_STRING (
"DatcomForceMoment/Digital DATCOM v1.0.2/Static Contribution/Xcp" ) ,
TARGET_STRING ( "Table" ) , 0 , 9 , 0 } , { 112 , TARGET_STRING (
"DatcomForceMoment/Digital DATCOM v1.0.2/Static Contribution/Xcp" ) ,
TARGET_STRING ( "dimSizes" ) , 2 , 2 , 0 } , { 113 , TARGET_STRING (
"DatcomForceMoment/Thrust /Signal Builder/FromWs" ) , TARGET_STRING ( "Time0"
) , 0 , 10 , 0 } , { 114 , TARGET_STRING (
"DatcomForceMoment/Thrust /Signal Builder/FromWs" ) , TARGET_STRING ( "Data0"
) , 0 , 10 , 0 } , { 115 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Deflection/Aerodynamic Forces and Moments/coefAdjust"
) , TARGET_STRING ( "Gain" ) , 0 , 7 , 0 } , { 116 , TARGET_STRING (
"DatcomForceMoment/Digital DATCOM v1.0.2/Deflection/Delta Coefficients/Gain"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 117 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Dynamic Contribution/Aerodynamic Forces and Moments Stability Axis/coefAdjust"
) , TARGET_STRING ( "Gain" ) , 0 , 7 , 0 } , { 118 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Static Contribution/Aerodynamic Forces and Moments/coefAdjust"
) , TARGET_STRING ( "Gain" ) , 0 , 7 , 0 } , { 119 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Deflection/Delta Coefficients/Aileron Deflaction/Constant1"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 120 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Deflection/Delta Coefficients/Aileron Deflaction/Constant4"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 121 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Deflection/Delta Coefficients/Aileron Deflaction/Constant5"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 122 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Deflection/Delta Coefficients/Aileron Deflaction/Constant6"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 123 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Deflection/Delta Coefficients/Aileron Deflaction/DCl"
) , TARGET_STRING ( "Table" ) , 0 , 11 , 0 } , { 124 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Deflection/Delta Coefficients/Aileron Deflaction/DCl"
) , TARGET_STRING ( "dimSizes" ) , 2 , 12 , 0 } , { 125 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Deflection/Delta Coefficients/Aileron Deflaction/DCn"
) , TARGET_STRING ( "Table" ) , 0 , 11 , 0 } , { 126 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Deflection/Delta Coefficients/Aileron Deflaction/DCn"
) , TARGET_STRING ( "dimSizes" ) , 2 , 12 , 0 } , { 127 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Deflection/Delta Coefficients/Elevator Deflaction/Constant1"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 128 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Deflection/Delta Coefficients/Elevator Deflaction/Constant2"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 129 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Deflection/Delta Coefficients/Elevator Deflaction/Constant3"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 130 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Deflection/Delta Coefficients/Elevator Deflaction/DCDI"
) , TARGET_STRING ( "Table" ) , 0 , 11 , 0 } , { 131 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Deflection/Delta Coefficients/Elevator Deflaction/DCDI"
) , TARGET_STRING ( "dimSizes" ) , 2 , 12 , 0 } , { 132 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Deflection/Delta Coefficients/Elevator Deflaction/DCL"
) , TARGET_STRING ( "Table" ) , 0 , 11 , 0 } , { 133 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Deflection/Delta Coefficients/Elevator Deflaction/DCL"
) , TARGET_STRING ( "dimSizes" ) , 2 , 12 , 0 } , { 134 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Deflection/Delta Coefficients/Elevator Deflaction/DCm"
) , TARGET_STRING ( "Table" ) , 0 , 11 , 0 } , { 135 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Deflection/Delta Coefficients/Elevator Deflaction/DCm"
) , TARGET_STRING ( "dimSizes" ) , 2 , 12 , 0 } , { 136 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Deflection/Delta Coefficients/Flap Deflaction/Constant1"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 137 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Deflection/Delta Coefficients/Flap Deflaction/Constant2"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 138 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Deflection/Delta Coefficients/Flap Deflaction/Constant3"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 139 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Deflection/Delta Coefficients/Flap Deflaction/DCDI"
) , TARGET_STRING ( "Table" ) , 0 , 11 , 0 } , { 140 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Deflection/Delta Coefficients/Flap Deflaction/DCDI"
) , TARGET_STRING ( "dimSizes" ) , 2 , 12 , 0 } , { 141 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Deflection/Delta Coefficients/Flap Deflaction/DCL"
) , TARGET_STRING ( "Table" ) , 0 , 11 , 0 } , { 142 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Deflection/Delta Coefficients/Flap Deflaction/DCL"
) , TARGET_STRING ( "dimSizes" ) , 2 , 12 , 0 } , { 143 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Deflection/Delta Coefficients/Flap Deflaction/DCm"
) , TARGET_STRING ( "Table" ) , 0 , 11 , 0 } , { 144 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Deflection/Delta Coefficients/Flap Deflaction/DCm"
) , TARGET_STRING ( "dimSizes" ) , 2 , 12 , 0 } , { 145 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Deflection/Aerodynamic Forces and Moments/CG-CP Transformation/Body2Stability/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 146 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Deflection/Aerodynamic Forces and Moments/CG-CP Transformation/Body2Stability/Constant1"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 147 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Deflection/Aerodynamic Forces and Moments/CG-CP Transformation/Body2Stability/Constant2"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 148 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Deflection/Aerodynamic Forces and Moments/CG-CP Transformation/Body2Stability/Constant3"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 149 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Deflection/Aerodynamic Forces and Moments/CG-CP Transformation/Body2Stability/Constant4"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 150 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Deflection/Aerodynamic Forces and Moments/Force Transformation/Body2Stability/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 151 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Deflection/Aerodynamic Forces and Moments/Force Transformation/Body2Stability/Constant1"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 152 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Deflection/Aerodynamic Forces and Moments/Force Transformation/Body2Stability/Constant2"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 153 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Deflection/Aerodynamic Forces and Moments/Force Transformation/Body2Stability/Constant3"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 154 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Deflection/Aerodynamic Forces and Moments/Force Transformation/Body2Stability/Constant4"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 155 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Deflection/Aerodynamic Forces and Moments/Moment Transformation/Body2Stability/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 156 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Deflection/Aerodynamic Forces and Moments/Moment Transformation/Body2Stability/Constant1"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 157 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Deflection/Aerodynamic Forces and Moments/Moment Transformation/Body2Stability/Constant2"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 158 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Deflection/Aerodynamic Forces and Moments/Moment Transformation/Body2Stability/Constant3"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 159 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Deflection/Aerodynamic Forces and Moments/Moment Transformation/Body2Stability/Constant4"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 160 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Dynamic Contribution/Aerodynamic Forces and Moments Stability Axis/CG-CP Transformation/Body2Stability/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 161 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Dynamic Contribution/Aerodynamic Forces and Moments Stability Axis/CG-CP Transformation/Body2Stability/Constant1"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 162 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Dynamic Contribution/Aerodynamic Forces and Moments Stability Axis/CG-CP Transformation/Body2Stability/Constant2"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 163 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Dynamic Contribution/Aerodynamic Forces and Moments Stability Axis/CG-CP Transformation/Body2Stability/Constant3"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 164 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Dynamic Contribution/Aerodynamic Forces and Moments Stability Axis/CG-CP Transformation/Body2Stability/Constant4"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 165 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Dynamic Contribution/Aerodynamic Forces and Moments Stability Axis/Force Transformation/Body2Stability/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 166 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Dynamic Contribution/Aerodynamic Forces and Moments Stability Axis/Force Transformation/Body2Stability/Constant1"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 167 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Dynamic Contribution/Aerodynamic Forces and Moments Stability Axis/Force Transformation/Body2Stability/Constant2"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 168 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Dynamic Contribution/Aerodynamic Forces and Moments Stability Axis/Force Transformation/Body2Stability/Constant3"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 169 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Dynamic Contribution/Aerodynamic Forces and Moments Stability Axis/Force Transformation/Body2Stability/Constant4"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 170 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Dynamic Contribution/Aerodynamic Forces and Moments Stability Axis/Moment Transformation/Body2Stability/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 171 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Dynamic Contribution/Aerodynamic Forces and Moments Stability Axis/Moment Transformation/Body2Stability/Constant1"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 172 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Dynamic Contribution/Aerodynamic Forces and Moments Stability Axis/Moment Transformation/Body2Stability/Constant2"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 173 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Dynamic Contribution/Aerodynamic Forces and Moments Stability Axis/Moment Transformation/Body2Stability/Constant3"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 174 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Dynamic Contribution/Aerodynamic Forces and Moments Stability Axis/Moment Transformation/Body2Stability/Constant4"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 175 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Dynamic Contribution/Stability Angular Rates/Direction Cosine Matrix Body to Wind/A32/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 176 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Static Contribution/Aerodynamic Forces and Moments/CG-CP Transformation/Body2Stability/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 177 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Static Contribution/Aerodynamic Forces and Moments/CG-CP Transformation/Body2Stability/Constant1"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 178 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Static Contribution/Aerodynamic Forces and Moments/CG-CP Transformation/Body2Stability/Constant2"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 179 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Static Contribution/Aerodynamic Forces and Moments/CG-CP Transformation/Body2Stability/Constant3"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 180 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Static Contribution/Aerodynamic Forces and Moments/CG-CP Transformation/Body2Stability/Constant4"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 181 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Static Contribution/Aerodynamic Forces and Moments/Force Transformation/Body2Stability/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 182 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Static Contribution/Aerodynamic Forces and Moments/Force Transformation/Body2Stability/Constant1"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 183 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Static Contribution/Aerodynamic Forces and Moments/Force Transformation/Body2Stability/Constant2"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 184 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Static Contribution/Aerodynamic Forces and Moments/Force Transformation/Body2Stability/Constant3"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 185 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Static Contribution/Aerodynamic Forces and Moments/Force Transformation/Body2Stability/Constant4"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 186 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Static Contribution/Aerodynamic Forces and Moments/Moment Transformation/Body2Stability/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 187 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Static Contribution/Aerodynamic Forces and Moments/Moment Transformation/Body2Stability/Constant1"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 188 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Static Contribution/Aerodynamic Forces and Moments/Moment Transformation/Body2Stability/Constant2"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 189 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Static Contribution/Aerodynamic Forces and Moments/Moment Transformation/Body2Stability/Constant3"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 190 , TARGET_STRING (
 "DatcomForceMoment/Digital DATCOM v1.0.2/Static Contribution/Aerodynamic Forces and Moments/Moment Transformation/Body2Stability/Constant4"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 0 , ( NULL ) , ( NULL ) , 0 ,
0 , 0 } } ; static const rtwCAPI_ModelParameters rtModelParameters [ ] = { {
191 , TARGET_STRING ( "u" ) , 0 , 13 , 0 } , { 0 , ( NULL ) , 0 , 0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . jwtgtch3mu [ 0 ] , & rtB .
pg2hzggfwd [ 0 ] , & rtB . jvmj3dgdoq , & rtB . hzbuxpmezj , & rtB .
ookv2bvvls , & rtB . nhxk0ib0lj , & rtB . jf5nt45ccr , & rtB . igwvaibikt [ 0
] , & rtB . n2spnyfef4 , & rtB . ab5d34lf4o , & rtB . jjpibu4asu , & rtB .
bbuiyhe1o5 , & rtB . mml2ndjd5d , & rtB . mxt20vlpck , & rtB . ianx2c50xl , &
rtB . n3teuvsdd5 , & rtB . oxq5mf1mg3 , & rtB . kacxif5qn0 , & rtB .
iayveggtaq , & rtB . il1zzs3oim , & rtB . ilvgb1vukq [ 0 ] , & rtB .
idhxicsqcr , & rtB . lanxaiurnw , & rtB . phcwtlgyip , & rtB . f2a4bnffor , &
rtB . hxsqezn2an [ 0 ] , & rtB . kies3oo3id [ 0 ] , & rtB . dp5pi2avlk [ 0 ]
, & rtB . fsutp3ayo3 [ 0 ] , & rtB . bdzrxsq0jb [ 0 ] , & rtB . pw5gjuojru [
0 ] , & rtB . m1nsvprq1z [ 0 ] , & rtB . hbts5j1pqq [ 0 ] , & rtP .
BetaSaturation_UpperSat , & rtP . BetaSaturation_LowerSat , & rtP .
BetaSaturation1_UpperSat , & rtP . BetaSaturation1_LowerSat , & rtP .
Constant_Value_cddtuuqxak , & rtP . Constant1_Value_f1v4g1iait , & rtP .
Constant2_Value_mwviqzbxqh , & rtP . Constant3_Value_c0ie4jx1vv , & rtP .
Constant4_Value_lvvzxuwh5z , & rtP . Constant5_Value_hu2bresth1 , & rtP .
Constant6_Value , & rtP . Constant7_Value , & rtP . Constant8_Value , & rtP .
Mach_BreakpointsData [ 0 ] , & rtP . alpha_BreakpointsData [ 0 ] , & rtP .
altitude_BreakpointsData [ 0 ] , & rtP . delta_a_BreakpointsData [ 0 ] , &
rtP . delta_e_BreakpointsData [ 0 ] , & rtP . delta_f_BreakpointsData [ 0 ] ,
& rtP . TrimThrust1_Value , & rtP . TrimThrust2_Value , & rtP .
TrimThrust3_Value , & rtP . TrimThrust4_Value , & rtP . TrimThrust5_Value [ 0
] , & rtP . Throttle_Gain , & rtP . ManualSwitch_CurrentSetting , & rtP .
WeightForce_Value , & rtP . WeightMoment_Value [ 0 ] , & rtP .
Gain1_Gain_gk1wozgh1p , & rtP . Gain_Gain , & rtP .
AltitudeofTroposphere_Value , & rtP . SeaLevelTemperature_Value , & rtP .
gLR_Value , & rtP . uT0_Gain , & rtP . LapseRate_Gain , & rtP . gR_Gain , &
rtP . gammaR_Gain , & rtP . rho0_Gain , & rtP .
LimitaltitudetoStratosphere_UpperSat , & rtP .
LimitaltitudetoStratosphere_LowerSat , & rtP .
Limitaltitudetotroposhere_UpperSat , & rtP .
Limitaltitudetotroposhere_LowerSat , & rtP . u_Value_jauwwxrr5h , & rtP .
u_Value_agropua0cl , & rtP . u_Value , & rtP . zero_Value , & rtP .
Gain1_Gain [ 0 ] , & rtP . CLad1_Table [ 0 ] , & rtP . CLad1_dimSize [ 0 ] ,
& rtP . CYp1_Table [ 0 ] , & rtP . CYp1_dimSize [ 0 ] , & rtP . Clp1_Table [
0 ] , & rtP . Clp1_dimSize [ 0 ] , & rtP . Clq1_Table [ 0 ] , & rtP .
Clq1_dimSize [ 0 ] , & rtP . Clr1_Table [ 0 ] , & rtP . Clr1_dimSize [ 0 ] ,
& rtP . Cmad1_Table [ 0 ] , & rtP . Cmad1_dimSize [ 0 ] , & rtP . Cmq1_Table
[ 0 ] , & rtP . Cmq1_dimSize [ 0 ] , & rtP . Cnp1_Table [ 0 ] , & rtP .
Cnp1_dimSize [ 0 ] , & rtP . Cnr1_Table [ 0 ] , & rtP . Cnr1_dimSize [ 0 ] ,
& rtP . zero1_Value , & rtP . CD_Table [ 0 ] , & rtP . CD_dimSize [ 0 ] , &
rtP . CL_Table [ 0 ] , & rtP . CL_dimSize [ 0 ] , & rtP . CYb_Table [ 0 ] , &
rtP . CYb_dimSize [ 0 ] , & rtP . Clb_Table [ 0 ] , & rtP . Clb_dimSize [ 0 ]
, & rtP . Cm_Table [ 0 ] , & rtP . Cm_dimSize [ 0 ] , & rtP . Cnb_Table [ 0 ]
, & rtP . Cnb_dimSize [ 0 ] , & rtP . Xcp_Table [ 0 ] , & rtP . Xcp_dimSize [
0 ] , & rtP . FromWs_Time0 [ 0 ] , & rtP . FromWs_Data0 [ 0 ] , & rtP .
coefAdjust_Gain_jhgwt4xcre [ 0 ] , & rtP . Gain_Gain_gtonf3ckiq , & rtP .
coefAdjust_Gain_blqcdygkok [ 0 ] , & rtP . coefAdjust_Gain [ 0 ] , & rtP .
Constant1_Value_jj4sc0nzo2 , & rtP . Constant4_Value_bxodvzr3wv , & rtP .
Constant5_Value , & rtP . Constant6_Value_o2itzcqfbo , & rtP . DCl_Table [ 0
] , & rtP . DCl_dimSize [ 0 ] , & rtP . DCn_Table [ 0 ] , & rtP . DCn_dimSize
[ 0 ] , & rtP . Constant1_Value_dvrrjd2vth , & rtP .
Constant2_Value_n1gt4skuej , & rtP . Constant3_Value_ammrq4bbzx , & rtP .
DCDI_Table_ectqqf4lpu [ 0 ] , & rtP . DCDI_dimSize_hvypykhf0h [ 0 ] , & rtP .
DCL_Table_b2ogh4jov4 [ 0 ] , & rtP . DCL_dimSize_i0jbywo0xh [ 0 ] , & rtP .
DCm_Table_jpppnjjyiv [ 0 ] , & rtP . DCm_dimSize_oju4dybify [ 0 ] , & rtP .
Constant1_Value_bhkzpq4cm3 , & rtP . Constant2_Value_old3zd5smi , & rtP .
Constant3_Value_nvs1o44prj , & rtP . DCDI_Table [ 0 ] , & rtP . DCDI_dimSize
[ 0 ] , & rtP . DCL_Table [ 0 ] , & rtP . DCL_dimSize [ 0 ] , & rtP .
DCm_Table [ 0 ] , & rtP . DCm_dimSize [ 0 ] , & rtP .
Constant_Value_huxzftueqj , & rtP . Constant1_Value_knfpzjs1ar , & rtP .
Constant2_Value_oqyl4nphju , & rtP . Constant3_Value_idex1eazwv , & rtP .
Constant4_Value_ijxamwyxru , & rtP . Constant_Value_epkxnw5b5k , & rtP .
Constant1_Value_e4b4arvsx4 , & rtP . Constant2_Value_i0tusarllo , & rtP .
Constant3_Value_n2bp44blge , & rtP . Constant4_Value_ebczl1p2kp , & rtP .
Constant_Value_kouoqvqr2q , & rtP . Constant1_Value_ol4tirigyp , & rtP .
Constant2_Value_gjwptupmqz , & rtP . Constant3_Value_pwsvvqm1ni , & rtP .
Constant4_Value_cbj5azvbu2 , & rtP . Constant_Value_fbwwe2lmsk , & rtP .
Constant1_Value_hei4fwlj0u , & rtP . Constant2_Value_d4ghahoovd , & rtP .
Constant3_Value_pp0fbeghm2 , & rtP . Constant4_Value_iw11bz0kqi , & rtP .
Constant_Value_gzdzpzihxe , & rtP . Constant1_Value_n0vvf1ru2i , & rtP .
Constant2_Value_eqjwl24tzr , & rtP . Constant3_Value_emiujykzul , & rtP .
Constant4_Value_bijw4dwdaf , & rtP . Constant_Value_ejuc1rn4ry , & rtP .
Constant1_Value_g0n03q330k , & rtP . Constant2_Value_oqrmwaotar , & rtP .
Constant3_Value_gaexcfymgv , & rtP . Constant4_Value_jl0l41uur4 , & rtP .
Constant_Value_fhedlbhuxr , & rtP . Constant_Value_hfw2vld21b , & rtP .
Constant1_Value_ic5cse51j2 , & rtP . Constant2_Value_iq4hlvezb4 , & rtP .
Constant3_Value_bfs2kyqhyj , & rtP . Constant4_Value_p1gsoflfkl , & rtP .
Constant_Value , & rtP . Constant1_Value , & rtP . Constant2_Value , & rtP .
Constant3_Value , & rtP . Constant4_Value , & rtP . Constant_Value_gi4rxypddg
, & rtP . Constant1_Value_bylbexapfl , & rtP . Constant2_Value_ntj1nxsmyj , &
rtP . Constant3_Value_irkjubdpiu , & rtP . Constant4_Value_g531dn02hg , & rtP
. u [ 0 ] , } ; static int32_T * rtVarDimsAddrMap [ ] = { ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , SS_DOUBLE , 0 , 0 } , {
"unsigned char" , "uint8_T" , 0 , 0 , sizeof ( uint8_T ) , SS_UINT8 , 0 , 0 }
, { "unsigned int" , "uint32_T" , 0 , 0 , sizeof ( uint32_T ) , SS_UINT32 , 0
, 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_MATRIX_COL_MAJOR , 0 , 2 , 0 } , { rtwCAPI_SCALAR , 2 , 2 , 0 } , {
rtwCAPI_VECTOR , 0 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 4 , 2 , 0 } , {
rtwCAPI_VECTOR , 6 , 2 , 0 } , { rtwCAPI_VECTOR , 8 , 2 , 0 } , {
rtwCAPI_VECTOR , 10 , 2 , 0 } , { rtwCAPI_VECTOR , 12 , 2 , 0 } , {
rtwCAPI_VECTOR , 14 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR_ND , 16 , 3 , 0 }
, { rtwCAPI_VECTOR , 19 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR_ND , 21 , 4 ,
0 } , { rtwCAPI_VECTOR , 25 , 2 , 0 } , { rtwCAPI_VECTOR , 27 , 2 , 0 } } ;
static const uint_T rtDimensionArray [ ] = { 3 , 1 , 1 , 1 , 3 , 3 , 9 , 1 ,
1 , 2 , 1 , 9 , 1 , 3 , 1 , 6 , 9 , 2 , 3 , 6 , 1 , 9 , 2 , 3 , 9 , 4 , 1 ,
17 , 1 } ; static const real_T rtcapiStoredFloats [ ] = { 0.0 } ; static
const rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) ,
rtwCAPI_FIX_RESERVED , 0 , 0 , 0 } , } ; static const rtwCAPI_SampleTimeMap
rtSampleTimeMap [ ] = { { ( const void * ) & rtcapiStoredFloats [ 0 ] , (
const void * ) & rtcapiStoredFloats [ 0 ] , 0 , 0 } , { ( NULL ) , ( NULL ) ,
2 , 0 } } ; static rtwCAPI_ModelMappingStaticInfo mmiStatic = { {
rtBlockSignals , 33 , ( NULL ) , 0 , ( NULL ) , 0 } , { rtBlockParameters ,
158 , rtModelParameters , 1 } , { ( NULL ) , 0 } , { rtDataTypeMap ,
rtDimensionMap , rtFixPtMap , rtElementMap , rtSampleTimeMap ,
rtDimensionArray } , "float" , { 309997958U , 4152278500U , 3176591357U ,
2740593875U } , ( NULL ) , 0 , 0 } ; const rtwCAPI_ModelMappingStaticInfo *
DatcomForceMoment_GetCAPIStaticMap ( ) { return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void DatcomForceMoment_InitializeDataMapInfo ( SimStruct * const rtS ) {
rtwCAPI_SetVersion ( ( * rt_dataMapInfoPtr ) . mmi , 1 ) ;
rtwCAPI_SetStaticMap ( ( * rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ;
rtwCAPI_SetLoggingStaticMap ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetDataAddressMap ( ( * rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ;
rtwCAPI_SetVarDimsAddressMap ( ( * rt_dataMapInfoPtr ) . mmi ,
rtVarDimsAddrMap ) ; rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr )
. mmi , ( NULL ) ) ; rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi
, ( NULL ) ) ; rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi ,
0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void DatcomForceMoment_host_InitializeDataMapInfo (
DatcomForceMoment_host_DataMapInfo_T * dataMap , const char * path ) {
rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ; rtwCAPI_SetStaticMap ( dataMap ->
mmi , & mmiStatic ) ; rtwCAPI_SetDataAddressMap ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , NULL ) ; rtwCAPI_SetPath (
dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
