#include "__cf_DatcomForceMoment.h"
#include "ext_types.h"
static uint_T rtDataTypeSizes [ ] = { sizeof ( real_T ) , sizeof ( real32_T )
, sizeof ( int8_T ) , sizeof ( uint8_T ) , sizeof ( int16_T ) , sizeof (
uint16_T ) , sizeof ( int32_T ) , sizeof ( uint32_T ) , sizeof ( boolean_T )
, sizeof ( fcn_call_T ) , sizeof ( int_T ) , sizeof ( pointer_T ) , sizeof (
action_T ) , 2 * sizeof ( uint32_T ) } ; static const char_T *
rtDataTypeNames [ ] = { "real_T" , "real32_T" , "int8_T" , "uint8_T" ,
"int16_T" , "uint16_T" , "int32_T" , "uint32_T" , "boolean_T" , "fcn_call_T"
, "int_T" , "pointer_T" , "action_T" , "timer_uint32_pair_T" } ; static
DataTypeTransition rtBTransitions [ ] = { { ( char_T * ) ( & rtB . nhxk0ib0lj
) , 0 , 0 , 81 } , { ( char_T * ) ( & rtDW . lshsqezqdg ) , 0 , 0 , 8 } , { (
char_T * ) ( & rtDW . l43hqho0yh . TimePtr ) , 11 , 0 , 6 } , { ( char_T * )
( & rtDW . eavb5jrhyr ) , 6 , 0 , 6 } , { ( char_T * ) ( & rtDW . cffy3oatmx
. PrevIndex ) , 10 , 0 , 1 } } ; static DataTypeTransitionTable rtBTransTable
= { 5U , rtBTransitions } ; static DataTypeTransition rtPTransitions [ ] = {
{ ( char_T * ) ( & rtP . u [ 0 ] ) , 0 , 0 , 4938 } , { ( char_T * ) ( & rtP
. CD_dimSize [ 0 ] ) , 7 , 0 , 80 } , { ( char_T * ) ( & rtP .
ManualSwitch_CurrentSetting ) , 3 , 0 , 1 } } ; static
DataTypeTransitionTable rtPTransTable = { 3U , rtPTransitions } ;
