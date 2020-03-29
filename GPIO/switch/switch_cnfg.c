#include "std_types.h"
#include	"GPIO_int.h"
#include	"switch_cnfg.h"

SWITCH_t mySwitchs[HSWITCH_NUM_OF_SWITCHS]=
{
	{PIN_15,PORTC,SWITCH_DOOR,GPIO_RESET,GPIO_SET},
	{PIN_1,PORTA,SWITCH_ALARM,GPIO_RESET,GPIO_SET}
};



