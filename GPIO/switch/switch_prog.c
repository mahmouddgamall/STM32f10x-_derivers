#include "std_types.h"
#include "GPIO_int.h"
#include "switch_int.h"
#include "switch_cnfg.h"

static GPIO_t SWITCH;

extern SWITCH_t mySwitchs[HSWITCH_NUM_OF_SWITCHS];

extern void HSWITCH_voidinit(void)
{
	for(u8 i = 0 ; i < HSWITCH_NUM_OF_SWITCHS ; i++ )
	{
		SWITCH.pin = mySwitchs[i].pin;
		SWITCH.speed = SPEED_2_MHZ;
		SWITCH.mode = MODE_INPUT_PULL_UP;
		SWITCH.port = mySwitchs[i].port;
		GPIO_voidinitPins(&SWITCH);
	}
}


extern ErrorStatus HSWITCH_errGetSwitchValue(u8 Switch, u8 *state)
{

	u8 status = NOK;
	u8 temp_state;

	if(Switch < HSWITCH_NUM_OF_SWITCHS)
	{
		temp_state = GPIO_u16GetPin(mySwitchs[Switch].port,mySwitchs[Switch].pin);
		status = OK;

		if	(temp_state == mySwitchs[Switch].pessedMode)
		{
			*state = SWITCH_PRESSED;
		}
		else if	(temp_state == mySwitchs[Switch].releasedMode)
		{
			*state = SWITCH_RELEASED;
		}
	}
	return status;

}
