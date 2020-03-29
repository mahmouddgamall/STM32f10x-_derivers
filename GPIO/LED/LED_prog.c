#include "std_types.h"
#include	"GPIO_int.h"
#include	"LED_int.h"
#include "LED_cnfg.h"

static GPIO_t LED;

extern LED_t myLEDs[HLED_NUM_OF_LEDS];

extern void HLED_voidinit(void)
{
	for(u8 i = 0 ; i < HLED_NUM_OF_LEDS ; i++ )
	{
		LED.pin = myLEDs[i].pin;
		LED.speed = SPEED_2_MHZ;
		LED.mode = MODE_OUTPUT_PUSH_PULL;
		LED.port = myLEDs[i].port;
		GPIO_voidinitPins(&LED);
	}
}


extern ErrorStatus HLED_errsetLedState(u8 LED, u8 state)
{

	u8 status = NOK;

	if(LED < HLED_NUM_OF_LEDS)
	{

		if	(state == LED_ON)		
		{
			status = OK;
			GPIO_voidSetPinValue(myLEDs[LED].port,myLEDs[LED].pin,myLEDs[LED].OnMode);
		}
		else if	(state == LED_OFF)
		{
			status = OK;
			GPIO_voidSetPinValue(myLEDs[LED].port,myLEDs[LED].pin,myLEDs[LED].OffMode);
		}
	}
	return status;

}
