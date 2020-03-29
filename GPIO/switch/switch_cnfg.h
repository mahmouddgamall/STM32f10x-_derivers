/*	Please choose the number of leds that you need in your system	*/

#ifndef	SWITCH_CNFG_H
#define	SWITCH_CNFG_H

typedef struct
{
	u16 pin;
	void* port;
	u8 number;
	u8 pessedMode;
	u8 releasedMode;
	
} SWITCH_t;

#define HSWITCH_NUM_OF_SWITCHS						2


#define		SWITCH_DOOR						0
#define		SWITCH_ALARM					1

#endif
