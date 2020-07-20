#include "ext_types.h"
static DataTypeInfo rtDataTypeInfoTable [ ] = { { "real_T" , 0 , 8 } , {
"real32_T" , 1 , 4 } , { "int8_T" , 2 , 1 } , { "uint8_T" , 3 , 1 } , {
"int16_T" , 4 , 2 } , { "uint16_T" , 5 , 2 } , { "int32_T" , 6 , 4 } , {
"uint32_T" , 7 , 4 } , { "boolean_T" , 8 , 1 } , { "fcn_call_T" , 9 , 0 } , {
"int_T" , 10 , 4 } , { "pointer_T" , 11 , 8 } , { "action_T" , 12 , 8 } , {
"timer_uint32_pair_T" , 13 , 8 } } ; static uint_T rtDataTypeSizes [ ] = {
sizeof ( real_T ) , sizeof ( real32_T ) , sizeof ( int8_T ) , sizeof (
uint8_T ) , sizeof ( int16_T ) , sizeof ( uint16_T ) , sizeof ( int32_T ) ,
sizeof ( uint32_T ) , sizeof ( boolean_T ) , sizeof ( fcn_call_T ) , sizeof (
int_T ) , sizeof ( pointer_T ) , sizeof ( action_T ) , 2 * sizeof ( uint32_T
) } ; static const char_T * rtDataTypeNames [ ] = { "real_T" , "real32_T" ,
"int8_T" , "uint8_T" , "int16_T" , "uint16_T" , "int32_T" , "uint32_T" ,
"boolean_T" , "fcn_call_T" , "int_T" , "pointer_T" , "action_T" ,
"timer_uint32_pair_T" } ; static DataTypeTransition rtBTransitions [ ] = { {
( char_T * ) ( & rtB . mbeszndpzw [ 0 ] ) , 0 , 0 , 103 } , { ( char_T * ) (
& rtB . ar551zz3kn ) , 8 , 0 , 3 } , { ( char_T * ) ( & rtDW . ncc32vf3v1 .
LoggedData ) , 11 , 0 , 29 } , { ( char_T * ) ( & rtDW . j5skdyoj5i ) , 10 ,
0 , 47 } , { ( char_T * ) ( & rtDW . i3ztellsjl ) , 2 , 0 , 12 } , { ( char_T
* ) ( & rtDW . ligunf0r1k ) , 8 , 0 , 3 } } ; static DataTypeTransitionTable
rtBTransTable = { 6U , rtBTransitions } ; static DataTypeTransition
rtPTransitions [ ] = { { ( char_T * ) ( & rtP . FlatEarthtoLLA_LL0 [ 0 ] ) ,
0 , 0 , 345 } , { ( char_T * ) ( & rtP . ManualSwitch1_CurrentSetting ) , 3 ,
0 , 5 } } ; static DataTypeTransitionTable rtPTransTable = { 2U ,
rtPTransitions } ;
