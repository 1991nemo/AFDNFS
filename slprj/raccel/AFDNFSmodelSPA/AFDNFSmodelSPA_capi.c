#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "AFDNFSmodelSPA_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)    
#else
#include "builtin_typeid_types.h"
#include "AFDNFSmodelSPA.h"
#include "AFDNFSmodelSPA_capi.h"
#include "AFDNFSmodelSPA_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST                  
#define TARGET_STRING(s)               (NULL)                    
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/6DoF Nonlinear Flight Equations of Motion (Rigid Body)/Linear Velocity Integrator (Body)"
) , TARGET_STRING ( "linearVelocity" ) , 0 , 0 , 0 , 0 , 0 } , { 1 , 0 ,
TARGET_STRING (
"AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Sum2" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 2 , 0 , TARGET_STRING (
"AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Sum3" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 3 , 0 , TARGET_STRING (
"AFDNFSmodelSPA/Nonlinear Flight Simulator/Initialization/Constant" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 1 } , { 4 , 0 , TARGET_STRING (
"AFDNFSmodelSPA/Nonlinear Flight Simulator/Initialization/Constant4" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 1 } , { 5 , 0 , TARGET_STRING (
"AFDNFSmodelSPA/Nonlinear Flight Simulator/Initialization/Constant6" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 1 } , { 6 , 0 , TARGET_STRING (
"AFDNFSmodelSPA/Nonlinear Flight Simulator/Initialization/Constant7" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 1 } , { 7 , 0 , TARGET_STRING (
"AFDNFSmodelSPA/Nonlinear Flight Simulator/Initialization/Constant8" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 1 } , { 8 , 0 , TARGET_STRING (
"AFDNFSmodelSPA/Nonlinear Flight Simulator/Plot/Gain" ) , TARGET_STRING ( ""
) , 0 , 0 , 2 , 0 , 0 } , { 9 , 0 , TARGET_STRING (
"AFDNFSmodelSPA/Nonlinear Flight Simulator/Plot/Gain1" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 0 } , { 10 , 0 , TARGET_STRING (
"AFDNFSmodelSPA/Nonlinear Flight Simulator/Plot/Gain2" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 0 } , { 11 , 0 , TARGET_STRING (
"AFDNFSmodelSPA/Nonlinear Flight Simulator/Plot/Gain3" ) , TARGET_STRING ( ""
) , 0 , 0 , 2 , 0 , 0 } , { 12 , 0 , TARGET_STRING (
"AFDNFSmodelSPA/Nonlinear Flight Simulator/Plot/Gain4" ) , TARGET_STRING ( ""
) , 0 , 0 , 2 , 0 , 0 } , { 13 , 0 , TARGET_STRING (
"AFDNFSmodelSPA/Nonlinear Flight Simulator/Plot/Gain5" ) , TARGET_STRING ( ""
) , 0 , 0 , 2 , 0 , 0 } , { 14 , 0 , TARGET_STRING (
"AFDNFSmodelSPA/OnBoardComputer/Control System/Sum" ) , TARGET_STRING ( "" )
, 0 , 0 , 3 , 0 , 0 } , { 15 , 0 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/6DoF Nonlinear Flight Equations of Motion (Rigid Body)/AngularAcceleration(Omegadot)/Product4"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 16 , 0 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/6DoF Nonlinear Flight Equations of Motion (Rigid Body)/Euler angles & Direction Cosine/Euler Angles Int"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 17 , 0 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/6DoF Nonlinear Flight Equations of Motion (Rigid Body)/Euler angles & Direction Cosine/Position Integrator"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 18 , 0 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/6DoF Nonlinear Flight Equations of Motion (Rigid Body)/Linear Acceleration(Vdot)/Sum3"
) , TARGET_STRING ( "linearAcceleration" ) , 0 , 0 , 0 , 0 , 0 } , { 19 , 0 ,
TARGET_STRING (
"AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Thrust/Throttle"
) , TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 1 } , { 20 , 0 , TARGET_STRING (
"AFDNFSmodelSPA/OnBoardComputer/Control System/LQR/Constant" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 1 } , { 21 , 0 , TARGET_STRING (
"AFDNFSmodelSPA/OnBoardComputer/Control System/LQR/Gain" ) , TARGET_STRING (
"" ) , 0 , 0 , 1 , 0 , 0 } , { 22 , 0 , TARGET_STRING (
"AFDNFSmodelSPA/OnBoardComputer/Control System/LQR/Gain1" ) , TARGET_STRING (
"" ) , 0 , 0 , 4 , 0 , 0 } , { 23 , 0 , TARGET_STRING (
"AFDNFSmodelSPA/OnBoardComputer/Control System/LQR/Sum" ) , TARGET_STRING (
"" ) , 0 , 0 , 1 , 0 , 0 } , { 24 , 0 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/6DoF Nonlinear Flight Equations of Motion (Rigid Body)/Euler angles & Direction Cosine/Transform from Body to Inertial axes/Reshape2"
) , TARGET_STRING ( "" ) , 0 , 0 , 2 , 0 , 0 } , { 25 , 0 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Aero Attributes/Fcn"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 26 , 0 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Aero Attributes/Fcn1"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 27 , 0 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Gravity Calculator/Flat Earth to LLA/Sum"
) , TARGET_STRING ( "" ) , 0 , 0 , 5 , 0 , 0 } , { 28 , 0 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Gravity Calculator/Flat Earth to LLA/Sum1"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 29 , 0 , TARGET_STRING (
 "AFDNFSmodelSPA/OnBoardComputer/Control System/Trim Offset +  Reference Excitation/Doublet Generated Signal/Sum"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 2 } , { 30 , 0 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Aero Attributes/Dynamic Pressure Calc/Dot Product"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 31 , 0 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Aero Attributes/Subsystem/Sum"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 32 , 0 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Moments/Pitch Moment Coefficient/Cm0"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 1 } , { 33 , 0 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Moments/Pitch Moment Coefficient/cmM"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 34 , 0 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Moments/Pitch Moment Coefficient/cmalpha"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 35 , 0 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Moments/Pitch Moment Coefficient/cmalphadot"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 36 , 0 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Moments/Pitch Moment Coefficient/cmdelta_e"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 37 , 0 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Moments/Pitch Moment Coefficient/cmdelta_f"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 38 , 0 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Moments/Pitch Moment Coefficient/cmq"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 39 , 0 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LatLong wrap/Sum"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 40 , 0 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LatLong wrap/Switch1"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 2 } , { 41 , 0 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LongLat_offset/SinCos"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 1 } , { 42 , 0 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LongLat_offset/SinCos"
) , TARGET_STRING ( "" ) , 1 , 0 , 1 , 0 , 1 } , { 43 , 0 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Forces/Force Coefficients Calculator/Drag Coefficient/cDalpha"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 44 , 0 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Forces/Force Coefficients Calculator/Drag Coefficient/cDdelta_a"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 45 , 0 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Forces/Force Coefficients Calculator/Drag Coefficient/cDdelta_e"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 46 , 0 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Forces/Force Coefficients Calculator/Drag Coefficient/cDdelta_f"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 47 , 0 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Forces/Force Coefficients Calculator/Drag Coefficient/cDdelta_r"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 48 , 0 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Abs1"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 49 , 0 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Sign1"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 2 } , { 50 , 0 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LatLong wrap/Wrap Longitude/Abs"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 51 , 0 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Switch"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 1 } , { 52 , 0 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LatLong wrap1/Wrap Longitude/Switch"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 1 } , { 53 , 0 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/Trigonometric Function1"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 1 } , { 54 , 0 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/Trigonometric Function2"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 1 } , { 55 , 0 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Compare To Constant/Compare"
) , TARGET_STRING ( "" ) , 0 , 1 , 1 , 0 , 2 } , { 56 , 0 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Abs"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 57 , 0 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Switch"
) , TARGET_STRING ( "" ) , 0 , 0 , 1 , 0 , 0 } , { 58 , 0 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LatLong wrap/Wrap Longitude/Compare To Constant/Compare"
) , TARGET_STRING ( "" ) , 0 , 1 , 1 , 0 , 2 } , { 59 , 0 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant/Compare"
) , TARGET_STRING ( "" ) , 0 , 1 , 1 , 0 , 2 } , { 0 , 0 , ( NULL ) , ( NULL
) , 0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_BlockParameters
rtBlockParameters [ ] = { { 60 , TARGET_STRING (
"AFDNFSmodelSPA/Nonlinear Flight Simulator/Initialization/Constant" ) ,
TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 61 , TARGET_STRING (
"AFDNFSmodelSPA/Nonlinear Flight Simulator/Initialization/Constant1" ) ,
TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 62 , TARGET_STRING (
"AFDNFSmodelSPA/Nonlinear Flight Simulator/Initialization/Constant2" ) ,
TARGET_STRING ( "Value" ) , 0 , 6 , 0 } , { 63 , TARGET_STRING (
"AFDNFSmodelSPA/Nonlinear Flight Simulator/Initialization/Constant3" ) ,
TARGET_STRING ( "Value" ) , 0 , 6 , 0 } , { 64 , TARGET_STRING (
"AFDNFSmodelSPA/Nonlinear Flight Simulator/Initialization/Constant4" ) ,
TARGET_STRING ( "Value" ) , 0 , 2 , 0 } , { 65 , TARGET_STRING (
"AFDNFSmodelSPA/Nonlinear Flight Simulator/Initialization/Constant6" ) ,
TARGET_STRING ( "Value" ) , 0 , 2 , 0 } , { 66 , TARGET_STRING (
"AFDNFSmodelSPA/Nonlinear Flight Simulator/Initialization/Constant7" ) ,
TARGET_STRING ( "Value" ) , 0 , 2 , 0 } , { 67 , TARGET_STRING (
"AFDNFSmodelSPA/Nonlinear Flight Simulator/Initialization/Constant8" ) ,
TARGET_STRING ( "Value" ) , 0 , 2 , 0 } , { 68 , TARGET_STRING (
"AFDNFSmodelSPA/Nonlinear Flight Simulator/Plot/Gain" ) , TARGET_STRING (
"Gain" ) , 0 , 1 , 0 } , { 69 , TARGET_STRING (
"AFDNFSmodelSPA/Nonlinear Flight Simulator/Plot/Gain1" ) , TARGET_STRING (
"Gain" ) , 0 , 1 , 0 } , { 70 , TARGET_STRING (
"AFDNFSmodelSPA/Nonlinear Flight Simulator/Plot/Gain2" ) , TARGET_STRING (
"Gain" ) , 0 , 1 , 0 } , { 71 , TARGET_STRING (
"AFDNFSmodelSPA/Nonlinear Flight Simulator/Plot/Gain3" ) , TARGET_STRING (
"Gain" ) , 0 , 2 , 0 } , { 72 , TARGET_STRING (
"AFDNFSmodelSPA/Nonlinear Flight Simulator/Plot/Gain4" ) , TARGET_STRING (
"Gain" ) , 0 , 2 , 0 } , { 73 , TARGET_STRING (
"AFDNFSmodelSPA/Nonlinear Flight Simulator/Plot/Gain5" ) , TARGET_STRING (
"Gain" ) , 0 , 1 , 0 } , { 74 , TARGET_STRING (
"AFDNFSmodelSPA/OnBoardComputer/Control System/Constant2" ) , TARGET_STRING (
"Value" ) , 0 , 3 , 0 } , { 75 , TARGET_STRING (
"AFDNFSmodelSPA/OnBoardComputer/Control System/Manual Switch1" ) ,
TARGET_STRING ( "CurrentSetting" ) , 2 , 1 , 0 } , { 76 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/6DoF Nonlinear Flight Equations of Motion (Rigid Body)/Euler angles & Direction Cosine/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 77 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Gravity Calculator/Flat Earth to LLA"
) , TARGET_STRING ( "LL0" ) , 0 , 7 , 0 } , { 78 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Gravity Calculator/Flat Earth to LLA"
) , TARGET_STRING ( "psi" ) , 0 , 1 , 0 } , { 79 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Gravity Calculator/Ref Alt"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 80 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Thrust/Trim Thrust1"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 81 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Thrust/Trim Thrust2"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 82 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Thrust/Trim Thrust3"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 83 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Thrust/Trim Thrust4"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 84 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Thrust/Trim Thrust5"
) , TARGET_STRING ( "Value" ) , 0 , 2 , 0 } , { 85 , TARGET_STRING (
"AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Thrust/Throttle"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 86 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Thrust/Manual Switch"
) , TARGET_STRING ( "CurrentSetting" ) , 2 , 1 , 0 } , { 87 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Weight/Trim Thrust5"
) , TARGET_STRING ( "Value" ) , 0 , 2 , 0 } , { 88 , TARGET_STRING (
"AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Weight/mass" )
, TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 89 , TARGET_STRING (
"AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Weight/Gain1" )
, TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 90 , TARGET_STRING (
"AFDNFSmodelSPA/OnBoardComputer/Control System/LQR/Constant" ) ,
TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 91 , TARGET_STRING (
"AFDNFSmodelSPA/OnBoardComputer/Control System/LQR/Constant1" ) ,
TARGET_STRING ( "Value" ) , 0 , 5 , 0 } , { 92 , TARGET_STRING (
"AFDNFSmodelSPA/OnBoardComputer/Control System/LQR/Constant2" ) ,
TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 93 , TARGET_STRING (
"AFDNFSmodelSPA/OnBoardComputer/Control System/LQR/dF" ) , TARGET_STRING (
"Value" ) , 0 , 1 , 0 } , { 94 , TARGET_STRING (
"AFDNFSmodelSPA/OnBoardComputer/Control System/LQR/Gain" ) , TARGET_STRING (
"Gain" ) , 0 , 1 , 0 } , { 95 , TARGET_STRING (
"AFDNFSmodelSPA/OnBoardComputer/Control System/LQR/Gain1" ) , TARGET_STRING (
"Gain" ) , 0 , 1 , 0 } , { 96 , TARGET_STRING (
"AFDNFSmodelSPA/OnBoardComputer/Control System/LQR/Lat LQR" ) , TARGET_STRING
( "Gain" ) , 0 , 8 , 0 } , { 97 , TARGET_STRING (
"AFDNFSmodelSPA/OnBoardComputer/Control System/LQR/Long LQR" ) ,
TARGET_STRING ( "Gain" ) , 0 , 9 , 0 } , { 98 , TARGET_STRING (
"AFDNFSmodelSPA/OnBoardComputer/Control System/LQR/Saturation1" ) ,
TARGET_STRING ( "UpperLimit" ) , 0 , 1 , 0 } , { 99 , TARGET_STRING (
"AFDNFSmodelSPA/OnBoardComputer/Control System/LQR/Saturation1" ) ,
TARGET_STRING ( "LowerLimit" ) , 0 , 1 , 0 } , { 100 , TARGET_STRING (
"AFDNFSmodelSPA/OnBoardComputer/Control System/LQR/Saturation2" ) ,
TARGET_STRING ( "UpperLimit" ) , 0 , 1 , 0 } , { 101 , TARGET_STRING (
"AFDNFSmodelSPA/OnBoardComputer/Control System/LQR/Saturation2" ) ,
TARGET_STRING ( "LowerLimit" ) , 0 , 1 , 0 } , { 102 , TARGET_STRING (
 "AFDNFSmodelSPA/OnBoardComputer/Control System/Trim Offset +  Reference Excitation/Controlled Plant"
) , TARGET_STRING ( "Value" ) , 0 , 3 , 0 } , { 103 , TARGET_STRING (
 "AFDNFSmodelSPA/OnBoardComputer/Control System/Trim Offset +  Reference Excitation/Free Plant"
) , TARGET_STRING ( "Value" ) , 0 , 3 , 0 } , { 104 , TARGET_STRING (
 "AFDNFSmodelSPA/OnBoardComputer/Control System/Trim Offset +  Reference Excitation/Manual Switch"
) , TARGET_STRING ( "CurrentSetting" ) , 2 , 1 , 0 } , { 105 , TARGET_STRING
(
 "AFDNFSmodelSPA/OnBoardComputer/Control System/Trim Offset +  Reference Excitation/Manual Switch1"
) , TARGET_STRING ( "CurrentSetting" ) , 2 , 1 , 0 } , { 106 , TARGET_STRING
(
 "AFDNFSmodelSPA/OnBoardComputer/Control System/Trim Offset +  Reference Excitation/Manual Switch2"
) , TARGET_STRING ( "CurrentSetting" ) , 2 , 1 , 0 } , { 107 , TARGET_STRING
(
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Aero Attributes/Transfer Fcn"
) , TARGET_STRING ( "A" ) , 0 , 1 , 0 } , { 108 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Aero Attributes/Transfer Fcn"
) , TARGET_STRING ( "C" ) , 0 , 1 , 0 } , { 109 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Aero Attributes/Transfer Fcn1"
) , TARGET_STRING ( "A" ) , 0 , 1 , 0 } , { 110 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Aero Attributes/Transfer Fcn1"
) , TARGET_STRING ( "C" ) , 0 , 1 , 0 } , { 111 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Thrust/Signal Builder/FromWs"
) , TARGET_STRING ( "Time0" ) , 0 , 10 , 0 } , { 112 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Thrust/Signal Builder/FromWs"
) , TARGET_STRING ( "Data0" ) , 0 , 10 , 0 } , { 113 , TARGET_STRING (
 "AFDNFSmodelSPA/OnBoardComputer/Control System/Trim Offset +  Reference Excitation/Doublet Generated Signal/Doublet"
) , TARGET_STRING ( "T_start" ) , 0 , 1 , 0 } , { 114 , TARGET_STRING (
 "AFDNFSmodelSPA/OnBoardComputer/Control System/Trim Offset +  Reference Excitation/Doublet Generated Signal/Doublet"
) , TARGET_STRING ( "amp" ) , 0 , 1 , 0 } , { 115 , TARGET_STRING (
 "AFDNFSmodelSPA/OnBoardComputer/Control System/Trim Offset +  Reference Excitation/Doublet Generated Signal/Doublet"
) , TARGET_STRING ( "span" ) , 0 , 1 , 0 } , { 116 , TARGET_STRING (
 "AFDNFSmodelSPA/OnBoardComputer/Control System/Trim Offset +  Reference Excitation/Doublet Generated Signal/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 2 , 0 } , { 117 , TARGET_STRING (
 "AFDNFSmodelSPA/OnBoardComputer/Control System/Trim Offset +  Reference Excitation/Doublet Generated Signal/Constant2"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 118 , TARGET_STRING (
 "AFDNFSmodelSPA/OnBoardComputer/Control System/Trim Offset +  Reference Excitation/Triangular signal span 10 sec/Constant1"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 119 , TARGET_STRING (
 "AFDNFSmodelSPA/OnBoardComputer/Control System/Trim Offset +  Reference Excitation/Triangular signal span 10 sec/Constant2"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 120 , TARGET_STRING (
 "AFDNFSmodelSPA/OnBoardComputer/Control System/Trim Offset +  Reference Excitation/Triangular signal span 10 sec/Constant3"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 121 , TARGET_STRING (
 "AFDNFSmodelSPA/OnBoardComputer/Control System/Trim Offset +  Reference Excitation/Triangular signal span 10 sec/Constant4"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 122 , TARGET_STRING (
 "AFDNFSmodelSPA/OnBoardComputer/Control System/Trim Offset +  Reference Excitation/Triangular signal span 10 sec/Gain"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 123 , TARGET_STRING (
 "AFDNFSmodelSPA/OnBoardComputer/Control System/Trim Offset +  Reference Excitation/Triangular signal span 10 sec/Gain1"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 124 , TARGET_STRING (
 "AFDNFSmodelSPA/OnBoardComputer/Control System/Trim Offset +  Reference Excitation/Triangular signal span 10 sec/Gain2"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 125 , TARGET_STRING (
 "AFDNFSmodelSPA/OnBoardComputer/Control System/Trim Offset +  Reference Excitation/Triangular signal span 10 sec/Gain3"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 126 , TARGET_STRING (
 "AFDNFSmodelSPA/OnBoardComputer/Control System/Trim Offset +  Reference Excitation/Triangular signal span 10 sec/Gain4"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 127 , TARGET_STRING (
 "AFDNFSmodelSPA/OnBoardComputer/Control System/Trim Offset +  Reference Excitation/Triangular signal span 10 sec/Gain5"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 128 , TARGET_STRING (
 "AFDNFSmodelSPA/OnBoardComputer/Control System/Trim Offset +  Reference Excitation/Triangular signal span 10 sec/Gain6"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 129 , TARGET_STRING (
 "AFDNFSmodelSPA/OnBoardComputer/Control System/Trim Offset +  Reference Excitation/Triangular signal span 10 sec/Gain7"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 130 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Aero Attributes/Dynamic Pressure Calc/Gain"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 131 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Aero Attributes/Subsystem/Altitude of Troposphere"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 132 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Aero Attributes/Subsystem/Sea Level  Temperature"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 133 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Aero Attributes/Subsystem/g//(L*R)"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 134 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Aero Attributes/Subsystem/1//T0"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 135 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Aero Attributes/Subsystem/Lapse Rate"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 136 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Aero Attributes/Subsystem/g//R"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 137 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Aero Attributes/Subsystem/gamma*R"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 138 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Aero Attributes/Subsystem/rho0"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 139 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Aero Attributes/Subsystem/Limit  altitude  to Stratosphere"
) , TARGET_STRING ( "UpperLimit" ) , 0 , 1 , 0 } , { 140 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Aero Attributes/Subsystem/Limit  altitude  to Stratosphere"
) , TARGET_STRING ( "LowerLimit" ) , 0 , 1 , 0 } , { 141 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Aero Attributes/Subsystem/Limit  altitude  to troposhere"
) , TARGET_STRING ( "UpperLimit" ) , 0 , 1 , 0 } , { 142 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Aero Attributes/Subsystem/Limit  altitude  to troposhere"
) , TARGET_STRING ( "LowerLimit" ) , 0 , 1 , 0 } , { 143 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Forces/Aerodynamic Forces/Wing Area"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 144 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Forces/Aerodynamic Forces/ChSign"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 145 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Forces/Aerodynamic Forces/ChSign1"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 146 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Forces/Aerodynamic Forces/ChSign2"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 147 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Forces/Force Coefficients Calculator/Drag Coefficient"
) , TARGET_STRING ( "cD0" ) , 0 , 1 , 0 } , { 148 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Forces/Force Coefficients Calculator/Lift Coefficient"
) , TARGET_STRING ( "cL0" ) , 0 , 1 , 0 } , { 149 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Forces/Force Coefficients Calculator/Lift Coefficient"
) , TARGET_STRING ( "meanchord" ) , 0 , 1 , 0 } , { 150 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Moments/Aerodynamic Moment /Wing area"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 151 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Moments/Aerodynamic Moment /Wing chord"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 152 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Moments/Aerodynamic Moment /Wing span"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 153 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Moments/Aerodynamic Moment /Wing span2"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 154 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Moments/Aerodynamic Moment /Gain"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 155 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Moments/Pitch Moment Coefficient/Cm0"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 156 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Moments/Pitch Moment Coefficient/Wing chord"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 157 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Moments/Pitch Moment Coefficient/2"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 158 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Moments/Pitch Moment Coefficient/cmM"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 159 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Moments/Pitch Moment Coefficient/cmalpha"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 160 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Moments/Pitch Moment Coefficient/cmalphadot"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 161 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Moments/Pitch Moment Coefficient/cmdelta_e"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 162 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Moments/Pitch Moment Coefficient/cmdelta_f"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 163 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Moments/Pitch Moment Coefficient/cmq"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 164 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Moments/Roll Moment Coefficient/Wing span"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 165 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Moments/Roll Moment Coefficient/2"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 166 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Moments/Roll Moment Coefficient/clbeta"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 167 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Moments/Roll Moment Coefficient/cldelta_a"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 168 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Moments/Roll Moment Coefficient/cldelta_r"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 169 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Moments/Roll Moment Coefficient/clp"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 170 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Moments/Roll Moment Coefficient/clr"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 171 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Moments/Yaw Moment Coefficient/Wing span"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 172 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Moments/Yaw Moment Coefficient/2"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 173 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Moments/Yaw Moment Coefficient/cnbeta"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 174 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Moments/Yaw Moment Coefficient/cndelta_a"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 175 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Moments/Yaw Moment Coefficient/cndelta_r"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 176 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Moments/Yaw Moment Coefficient/cnp"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 177 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Moments/Yaw Moment Coefficient/cnr"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 178 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LatLong wrap/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 179 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LatLong wrap/Constant1"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 180 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LatLong wrap1/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 181 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LatLong wrap1/Constant1"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 182 , TARGET_STRING (
 "AFDNFSmodelSPA/OnBoardComputer/Control System/Trim Offset +  Reference Excitation/Doublet Generated Signal/Doublet/Step"
) , TARGET_STRING ( "Before" ) , 0 , 1 , 0 } , { 183 , TARGET_STRING (
 "AFDNFSmodelSPA/OnBoardComputer/Control System/Trim Offset +  Reference Excitation/Doublet Generated Signal/Doublet/Step1"
) , TARGET_STRING ( "Before" ) , 0 , 1 , 0 } , { 184 , TARGET_STRING (
 "AFDNFSmodelSPA/OnBoardComputer/Control System/Trim Offset +  Reference Excitation/Doublet Generated Signal/Doublet/Step2"
) , TARGET_STRING ( "Before" ) , 0 , 1 , 0 } , { 185 , TARGET_STRING (
 "AFDNFSmodelSPA/OnBoardComputer/Control System/Trim Offset +  Reference Excitation/Doublet Generated Signal/Doublet/Step3"
) , TARGET_STRING ( "Before" ) , 0 , 1 , 0 } , { 186 , TARGET_STRING (
 "AFDNFSmodelSPA/OnBoardComputer/Control System/Trim Offset +  Reference Excitation/Triangular signal span 10 sec/Signal Builder1/FromWs"
) , TARGET_STRING ( "Time0" ) , 0 , 11 , 0 } , { 187 , TARGET_STRING (
 "AFDNFSmodelSPA/OnBoardComputer/Control System/Trim Offset +  Reference Excitation/Triangular signal span 10 sec/Signal Builder1/FromWs"
) , TARGET_STRING ( "Data0" ) , 0 , 11 , 0 } , { 188 , TARGET_STRING (
 "AFDNFSmodelSPA/OnBoardComputer/Control System/Trim Offset +  Reference Excitation/Triangular signal span 10 sec/Signal Builder2/FromWs"
) , TARGET_STRING ( "Time0" ) , 0 , 12 , 0 } , { 189 , TARGET_STRING (
 "AFDNFSmodelSPA/OnBoardComputer/Control System/Trim Offset +  Reference Excitation/Triangular signal span 10 sec/Signal Builder2/FromWs"
) , TARGET_STRING ( "Data0" ) , 0 , 12 , 0 } , { 190 , TARGET_STRING (
 "AFDNFSmodelSPA/OnBoardComputer/Control System/Trim Offset +  Reference Excitation/Triangular signal span 10 sec/Signal Builder3/FromWs"
) , TARGET_STRING ( "Time0" ) , 0 , 11 , 0 } , { 191 , TARGET_STRING (
 "AFDNFSmodelSPA/OnBoardComputer/Control System/Trim Offset +  Reference Excitation/Triangular signal span 10 sec/Signal Builder3/FromWs"
) , TARGET_STRING ( "Data0" ) , 0 , 11 , 0 } , { 192 , TARGET_STRING (
 "AFDNFSmodelSPA/OnBoardComputer/Control System/Trim Offset +  Reference Excitation/Triangular signal span 10 sec/Signal Builder4/FromWs"
) , TARGET_STRING ( "Time0" ) , 0 , 11 , 0 } , { 193 , TARGET_STRING (
 "AFDNFSmodelSPA/OnBoardComputer/Control System/Trim Offset +  Reference Excitation/Triangular signal span 10 sec/Signal Builder4/FromWs"
) , TARGET_STRING ( "Data0" ) , 0 , 11 , 0 } , { 194 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Forces/Aerodynamic Forces/Wind2Body TM/Zero"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 195 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Forces/Aerodynamic Forces/Wind2Body TM/ChSign"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 196 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Forces/Aerodynamic Forces/Wind2Body TM/ChSign1"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 197 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Forces/Aerodynamic Forces/Wind2Body TM/ChSign2"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 198 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Forces/Force Coefficients Calculator/Drag Coefficient/Induced Drag"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 199 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Forces/Force Coefficients Calculator/Drag Coefficient/cDM"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 200 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Forces/Force Coefficients Calculator/Drag Coefficient/cDalpha"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 201 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Forces/Force Coefficients Calculator/Drag Coefficient/cDdelta_a"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 202 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Forces/Force Coefficients Calculator/Drag Coefficient/cDdelta_e"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 203 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Forces/Force Coefficients Calculator/Drag Coefficient/cDdelta_f"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 204 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Forces/Force Coefficients Calculator/Drag Coefficient/cDdelta_r"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 205 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Forces/Force Coefficients Calculator/Lift Coefficient/1"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 206 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Forces/Force Coefficients Calculator/Lift Coefficient/CLM"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 207 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Forces/Force Coefficients Calculator/Lift Coefficient/cLalpha"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 208 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Forces/Force Coefficients Calculator/Lift Coefficient/cLalphadot"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 209 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Forces/Force Coefficients Calculator/Lift Coefficient/cLdelta_e"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 210 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Forces/Force Coefficients Calculator/Lift Coefficient/cLdelta_f"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 211 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Forces/Force Coefficients Calculator/Lift Coefficient/cLq"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 212 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Forces/Force Coefficients Calculator/SideForce Coefficient/Wing span"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 213 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Forces/Force Coefficients Calculator/SideForce Coefficient/2"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 214 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Forces/Force Coefficients Calculator/SideForce Coefficient/cYbeta"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 215 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Forces/Force Coefficients Calculator/SideForce Coefficient/cYdelta_a"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 216 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Forces/Force Coefficients Calculator/SideForce Coefficient/cYdelta_r"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 217 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Forces/Force Coefficients Calculator/SideForce Coefficient/cYp"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 218 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Forces/Force Coefficients Calculator/SideForce Coefficient/cYr"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 219 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Moments/Aerodynamic Moment /Wind2Body TM/Zero"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 220 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Moments/Aerodynamic Moment /Wind2Body TM/ChSign"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 221 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Moments/Aerodynamic Moment /Wind2Body TM/ChSign1"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 222 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Aerodynamic Forces and Moments Derivatives/Moments/Aerodynamic Moment /Wind2Body TM/ChSign2"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 223 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Compare To Constant"
) , TARGET_STRING ( "const" ) , 0 , 1 , 0 } , { 224 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Bias"
) , TARGET_STRING ( "Bias" ) , 0 , 1 , 0 } , { 225 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Bias1"
) , TARGET_STRING ( "Bias" ) , 0 , 1 , 0 } , { 226 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Gain"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 227 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LatLong wrap/Wrap Longitude/Compare To Constant"
) , TARGET_STRING ( "const" ) , 0 , 1 , 0 } , { 228 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LatLong wrap/Wrap Longitude/Bias"
) , TARGET_STRING ( "Bias" ) , 0 , 1 , 0 } , { 229 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LatLong wrap/Wrap Longitude/Bias1"
) , TARGET_STRING ( "Bias" ) , 0 , 1 , 0 } , { 230 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LatLong wrap/Wrap Longitude/Constant2"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 231 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Compare To Constant"
) , TARGET_STRING ( "const" ) , 0 , 1 , 0 } , { 232 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Bias"
) , TARGET_STRING ( "Bias" ) , 0 , 1 , 0 } , { 233 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Bias1"
) , TARGET_STRING ( "Bias" ) , 0 , 1 , 0 } , { 234 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Gain"
) , TARGET_STRING ( "Gain" ) , 0 , 1 , 0 } , { 235 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LatLong wrap1/Wrap Longitude/Compare To Constant"
) , TARGET_STRING ( "const" ) , 0 , 1 , 0 } , { 236 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LatLong wrap1/Wrap Longitude/Bias"
) , TARGET_STRING ( "Bias" ) , 0 , 1 , 0 } , { 237 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LatLong wrap1/Wrap Longitude/Bias1"
) , TARGET_STRING ( "Bias" ) , 0 , 1 , 0 } , { 238 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LatLong wrap1/Wrap Longitude/Constant2"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 239 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 240 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/Constant1"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 241 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/Constant2"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 242 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/Constant3"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 243 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Compare To Constant"
) , TARGET_STRING ( "const" ) , 0 , 1 , 0 } , { 244 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Bias"
) , TARGET_STRING ( "Bias" ) , 0 , 1 , 0 } , { 245 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Bias1"
) , TARGET_STRING ( "Bias" ) , 0 , 1 , 0 } , { 246 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LatLong wrap/Latitude Wrap 90/Wrap Angle 180/Constant2"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 247 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Wrap Angle 180/Compare To Constant"
) , TARGET_STRING ( "const" ) , 0 , 1 , 0 } , { 248 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Wrap Angle 180/Bias"
) , TARGET_STRING ( "Bias" ) , 0 , 1 , 0 } , { 249 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Wrap Angle 180/Bias1"
) , TARGET_STRING ( "Bias" ) , 0 , 1 , 0 } , { 250 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LatLong wrap1/Latitude Wrap 90/Wrap Angle 180/Constant2"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 251 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/denom/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 252 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/e/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 253 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/e/f"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 254 , TARGET_STRING (
 "AFDNFSmodelSPA/Nonlinear Flight Simulator/Forces and Moments/Gravity Calculator/Flat Earth to LLA/LongLat_offset/Find Radian//Distance/e^4/Constant"
) , TARGET_STRING ( "Value" ) , 0 , 1 , 0 } , { 0 , ( NULL ) , ( NULL ) , 0 ,
0 , 0 } } ; static const rtwCAPI_ModelParameters rtModelParameters [ ] = { {
0 , ( NULL ) , 0 , 0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . mbeszndpzw [ 0 ] , & rtB .
paumsm4ucv [ 0 ] , & rtB . hc3hgdwtyb [ 0 ] , & rtB . bh40mgxfug , & rtB .
ft1rv4ttnm [ 0 ] , & rtB . hbmslxdafy [ 0 ] , & rtB . lnbo3dn5b5 [ 0 ] , &
rtB . mai2btwwwy [ 0 ] , & rtB . hhdivriu54 [ 0 ] , & rtB . ej5pw05q3j [ 0 ]
, & rtB . pxlcyjc0py [ 0 ] , & rtB . l2let5yzu1 [ 0 ] , & rtB . bt44u1ruqs [
0 ] , & rtB . nco05nrykr [ 0 ] , & rtB . lbzm4w3kvc [ 0 ] , & rtB .
axza31sfxm [ 0 ] , & rtB . g2bzvajzvm [ 0 ] , & rtB . prll55li14 [ 0 ] , &
rtB . pd3h1ffkcz [ 0 ] , & rtB . gor1ljyslz [ 0 ] , & rtB . dorju0mbfg , &
rtB . igulonupg4 , & rtB . iluz41jmye [ 0 ] , & rtB . nxlyj2r2ke , & rtB .
ewosjguuu0 [ 0 ] , & rtB . gel1pzm210 , & rtB . l3nhcgjbby , & rtB .
puqzbadmna [ 0 ] , & rtB . jxiqnugoaw , & rtB . lf41qcir2i , & rtB .
ddodrccvry , & rtB . hjeoespy50 , & rtB . obrryzou3p , & rtB . n4ytkvk2rz , &
rtB . aiijml5ggp , & rtB . babk200cg1 , & rtB . mmcuu43erm , & rtB .
mlb2v0rqr4 , & rtB . eimam0aysg , & rtB . ltejiu1rdi , & rtB . kf1oc12ha5 , &
rtB . ladmdwvset , & rtB . fqj3t5j0hs , & rtB . odqjhpytke , & rtB .
j4qce2ejgk , & rtB . b4lvv4thsq , & rtB . n51upk5du5 , & rtB . j2ppwxwj2v , &
rtB . fl2tbgohhi , & rtB . aa5dhjvrml , & rtB . nc2kd2edsn , & rtB .
l4k2a5bsh4 , & rtB . kzv3jtixuu , & rtB . hcthdqledv , & rtB . n5jin1c2zm , &
rtB . ku1qygrkrl , & rtB . p43ilaklx2 , & rtB . ebdsowrcxw , & rtB .
ao5xxbupqa , & rtB . ar551zz3kn , & rtP . Constant_Value_ki5yoscsu1 , & rtP .
Constant1_Value_old4tikkcg , & rtP . Constant2_Value_lh0btpjb3l [ 0 ] , & rtP
. Constant3_Value_f1k1adieba [ 0 ] , & rtP . Constant4_Value [ 0 ] , & rtP .
Constant6_Value [ 0 ] , & rtP . Constant7_Value [ 0 ] , & rtP .
Constant8_Value [ 0 ] , & rtP . Gain_Gain_dqhhuexjt5 , & rtP .
Gain1_Gain_b1hf4hkty0 , & rtP . Gain2_Gain_ntnvl1cqpn , & rtP .
Gain3_Gain_hjbg4mtw5c [ 0 ] , & rtP . Gain4_Gain_l0vaw0ty4p [ 0 ] , & rtP .
Gain5_Gain_lm3oic4sdo , & rtP . Constant2_Value_eiuvnldjii [ 0 ] , & rtP .
ManualSwitch1_CurrentSetting_g2n2m14h1o , & rtP . Constant_Value , & rtP .
FlatEarthtoLLA_LL0 [ 0 ] , & rtP . FlatEarthtoLLA_psi , & rtP . RefAlt_Value
, & rtP . TrimThrust1_Value , & rtP . TrimThrust2_Value , & rtP .
TrimThrust3_Value , & rtP . TrimThrust4_Value , & rtP . TrimThrust5_Value [ 0
] , & rtP . Throttle_Gain , & rtP . ManualSwitch_CurrentSetting_mbegp1wenu ,
& rtP . TrimThrust5_Value_pghqg4ahuq [ 0 ] , & rtP . mass_Value , & rtP .
Gain1_Gain_jlinvxtcyq , & rtP . Constant_Value_ldaynjj304 , & rtP .
Constant1_Value_aja1fvk5dn [ 0 ] , & rtP . Constant2_Value_gm0og1aigu , & rtP
. dF_Value , & rtP . Gain_Gain_is0it0xd34 , & rtP . Gain1_Gain_mfxdzqt1sa , &
rtP . LatLQR_Gain [ 0 ] , & rtP . LongLQR_Gain [ 0 ] , & rtP .
Saturation1_UpperSat , & rtP . Saturation1_LowerSat , & rtP .
Saturation2_UpperSat , & rtP . Saturation2_LowerSat , & rtP .
ControlledPlant_Value [ 0 ] , & rtP . FreePlant_Value [ 0 ] , & rtP .
ManualSwitch_CurrentSetting , & rtP . ManualSwitch1_CurrentSetting , & rtP .
ManualSwitch2_CurrentSetting , & rtP . TransferFcn_A , & rtP . TransferFcn_C
, & rtP . TransferFcn1_A , & rtP . TransferFcn1_C , & rtP .
FromWs_Time0_i2ajdr5pty [ 0 ] , & rtP . FromWs_Data0_hempjedlcs [ 0 ] , & rtP
. Doublet_T_start , & rtP . Doublet_amp , & rtP . Doublet_span , & rtP .
Constant_Value_iltbyzakku [ 0 ] , & rtP . Constant2_Value_bvlfok2r5u , & rtP
. Constant1_Value_of0klte1gr , & rtP . Constant2_Value_ol34lh25j4 , & rtP .
Constant3_Value_ey1nyz4g22 , & rtP . Constant4_Value_iwlbmt1pf3 , & rtP .
Gain_Gain_mxsmwhuwrc , & rtP . Gain1_Gain , & rtP . Gain2_Gain , & rtP .
Gain3_Gain , & rtP . Gain4_Gain , & rtP . Gain5_Gain , & rtP . Gain6_Gain , &
rtP . Gain7_Gain , & rtP . Gain_Gain_d31dqzkeif , & rtP .
AltitudeofTroposphere_Value , & rtP . SeaLevelTemperature_Value , & rtP .
gLR_Value , & rtP . uT0_Gain , & rtP . LapseRate_Gain , & rtP . gR_Gain , &
rtP . gammaR_Gain , & rtP . rho0_Gain , & rtP .
LimitaltitudetoStratosphere_UpperSat , & rtP .
LimitaltitudetoStratosphere_LowerSat , & rtP .
Limitaltitudetotroposhere_UpperSat , & rtP .
Limitaltitudetotroposhere_LowerSat , & rtP . WingArea_Value , & rtP .
ChSign_Gain_pd02wcxouh , & rtP . ChSign1_Gain_jgqy0alfoa , & rtP .
ChSign2_Gain , & rtP . DragCoefficient_cD0 , & rtP . LiftCoefficient_cL0 , &
rtP . LiftCoefficient_meanchord , & rtP . Wingarea_Value , & rtP .
Wingchord_Value , & rtP . Wingspan_Value_cr0bafp5uf , & rtP . Wingspan2_Value
, & rtP . Gain_Gain_fldlnfjp4b , & rtP . Cm0_Value , & rtP .
Wingchord_Value_emuwkezyaz , & rtP . u_Gain_kpl0cbpinj , & rtP . cmM_Gain , &
rtP . cmalpha_Gain , & rtP . cmalphadot_Gain , & rtP . cmdelta_e_Gain , & rtP
. cmdelta_f_Gain , & rtP . cmq_Gain , & rtP . Wingspan_Value_drrojpryp4 , &
rtP . u_Gain_dzcqhyfoug , & rtP . clbeta_Gain , & rtP . cldelta_a_Gain , &
rtP . cldelta_r_Gain , & rtP . clp_Gain , & rtP . clr_Gain , & rtP .
Wingspan_Value_erx3lkovhx , & rtP . u_Gain_p0db5lqo0p , & rtP . cnbeta_Gain ,
& rtP . cndelta_a_Gain , & rtP . cndelta_r_Gain , & rtP . cnp_Gain , & rtP .
cnr_Gain , & rtP . Constant_Value_o10wbquf15 , & rtP . Constant1_Value , &
rtP . Constant_Value_bx2r5flqh4 , & rtP . Constant1_Value_folsuaqk2w , & rtP
. Step_Y0 , & rtP . Step1_Y0 , & rtP . Step2_Y0 , & rtP . Step3_Y0 , & rtP .
FromWs_Time0 [ 0 ] , & rtP . FromWs_Data0 [ 0 ] , & rtP .
FromWs_Time0_elms23aku5 [ 0 ] , & rtP . FromWs_Data0_epwwwxrf5p [ 0 ] , & rtP
. FromWs_Time0_dbgr3faoo4 [ 0 ] , & rtP . FromWs_Data0_gk1j2xmtdn [ 0 ] , &
rtP . FromWs_Time0_l0kcnhlhti [ 0 ] , & rtP . FromWs_Data0_pabez3hm0f [ 0 ] ,
& rtP . Zero_Value , & rtP . ChSign_Gain , & rtP . ChSign1_Gain , & rtP .
ChSign2_Gain_blrwynkzlu , & rtP . InducedDrag_Gain , & rtP . cDM_Gain , & rtP
. cDalpha_Gain , & rtP . cDdelta_a_Gain , & rtP . cDdelta_e_Gain , & rtP .
cDdelta_f_Gain , & rtP . cDdelta_r_Gain , & rtP . u_Gain , & rtP . CLM_Gain ,
& rtP . cLalpha_Gain , & rtP . cLalphadot_Gain , & rtP . cLdelta_e_Gain , &
rtP . cLdelta_f_Gain , & rtP . cLq_Gain , & rtP . Wingspan_Value , & rtP .
u_Gain_pb5qen5bq2 , & rtP . cYbeta_Gain , & rtP . cYdelta_a_Gain , & rtP .
cYdelta_r_Gain , & rtP . cYp_Gain , & rtP . cYr_Gain , & rtP .
Zero_Value_dhaiu1n4hb , & rtP . ChSign_Gain_jrexwz533r , & rtP .
ChSign1_Gain_p1dv1gzhg0 , & rtP . ChSign2_Gain_mg4y2ieuqq , & rtP .
CompareToConstant_const , & rtP . Bias_Bias , & rtP . Bias1_Bias , & rtP .
Gain_Gain , & rtP . CompareToConstant_const_kmoxadnhb5 , & rtP .
Bias_Bias_eiu2cdruu3 , & rtP . Bias1_Bias_hfpwrebp0l , & rtP .
Constant2_Value_aoptzpbs55 , & rtP . CompareToConstant_const_lrvr5wm4my , &
rtP . Bias_Bias_f2s41qt1rc , & rtP . Bias1_Bias_h3sn5uls4z , & rtP .
Gain_Gain_p3bohr0orw , & rtP . CompareToConstant_const_obwydhle4i , & rtP .
Bias_Bias_d5zpfez5uz , & rtP . Bias1_Bias_ewxdzezg00 , & rtP .
Constant2_Value_ir4n4t0fex , & rtP . Constant_Value_lljga3nj5j , & rtP .
Constant1_Value_d1hfa5vt1i , & rtP . Constant2_Value_pkofftudxg , & rtP .
Constant3_Value , & rtP . CompareToConstant_const_b0xas2jkq3 , & rtP .
Bias_Bias_egwxvvuqi5 , & rtP . Bias1_Bias_hhxbgizgvm , & rtP .
Constant2_Value , & rtP . CompareToConstant_const_nifrvxypha , & rtP .
Bias_Bias_lfg1tbgilu , & rtP . Bias1_Bias_dxmrixcsmx , & rtP .
Constant2_Value_muoeisyhao , & rtP . Constant_Value_mibaoj2rgl , & rtP .
Constant_Value_mjz5zpttx1 , & rtP . f_Value , & rtP .
Constant_Value_enfqz0alpl , } ; static int32_T * rtVarDimsAddrMap [ ] = { (
NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , SS_DOUBLE , 0 , 0 , 0 } , {
"unsigned char" , "boolean_T" , 0 , 0 , sizeof ( boolean_T ) , SS_BOOLEAN , 0
, 0 , 0 } , { "unsigned char" , "uint8_T" , 0 , 0 , sizeof ( uint8_T ) ,
SS_UINT8 , 0 , 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_MATRIX_COL_MAJOR , 0 , 2 , 0 } , { rtwCAPI_SCALAR , 2 , 2 , 0 } , {
rtwCAPI_VECTOR , 0 , 2 , 0 } , { rtwCAPI_VECTOR , 4 , 2 , 0 } , {
rtwCAPI_MATRIX_COL_MAJOR , 6 , 2 , 0 } , { rtwCAPI_VECTOR , 6 , 2 , 0 } , {
rtwCAPI_MATRIX_COL_MAJOR , 8 , 2 , 0 } , { rtwCAPI_VECTOR , 10 , 2 , 0 } , {
rtwCAPI_MATRIX_COL_MAJOR , 12 , 2 , 0 } , { rtwCAPI_VECTOR , 14 , 2 , 0 } , {
rtwCAPI_VECTOR , 16 , 2 , 0 } , { rtwCAPI_VECTOR , 18 , 2 , 0 } , {
rtwCAPI_VECTOR , 20 , 2 , 0 } } ; static const uint_T rtDimensionArray [ ] =
{ 3 , 1 , 1 , 1 , 4 , 1 , 2 , 1 , 3 , 3 , 1 , 2 , 2 , 5 , 1 , 4 , 6 , 1 , 13
, 1 , 9 , 1 } ; static const real_T rtcapiStoredFloats [ ] = { 0.0 , 1.0 } ;
static const rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) ,
rtwCAPI_FIX_RESERVED , 0 , 0 , 0 } , } ; static const rtwCAPI_SampleTimeMap
rtSampleTimeMap [ ] = { { ( const void * ) & rtcapiStoredFloats [ 0 ] , (
const void * ) & rtcapiStoredFloats [ 0 ] , 0 , 0 } , { ( NULL ) , ( NULL ) ,
2 , 0 } , { ( const void * ) & rtcapiStoredFloats [ 0 ] , ( const void * ) &
rtcapiStoredFloats [ 1 ] , 1 , 0 } } ; static rtwCAPI_ModelMappingStaticInfo
mmiStatic = { { rtBlockSignals , 60 , ( NULL ) , 0 , ( NULL ) , 0 } , {
rtBlockParameters , 195 , rtModelParameters , 0 } , { ( NULL ) , 0 } , {
rtDataTypeMap , rtDimensionMap , rtFixPtMap , rtElementMap , rtSampleTimeMap
, rtDimensionArray } , "float" , { 4196730302U , 151385502U , 2760859041U ,
3234198081U } , ( NULL ) , 0 , 0 } ; const rtwCAPI_ModelMappingStaticInfo *
AFDNFSmodelSPA_GetCAPIStaticMap ( void ) { return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void AFDNFSmodelSPA_InitializeDataMapInfo ( void ) { rtwCAPI_SetVersion ( ( *
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
void AFDNFSmodelSPA_host_InitializeDataMapInfo (
AFDNFSmodelSPA_host_DataMapInfo_T * dataMap , const char * path ) {
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
