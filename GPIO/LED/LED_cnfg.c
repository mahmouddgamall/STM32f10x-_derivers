#include "std_types.h"
#include	"GPIO_int.h"
#include	"LED_cnfg.h"

LED_t myLEDs[HLED_NUM_OF_LEDS]=
{
	{PIN_13|PIN_14,PORTC,LED_DOOR,GPIO_RESET,GPIO_SET},
	{PIN_13,PORTA,LED_ALARM,GPIO_SET,GPIO_RESET}
};



