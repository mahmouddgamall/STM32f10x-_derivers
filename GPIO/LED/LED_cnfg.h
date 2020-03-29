/*	Please choose the number of leds that you need in your system	*/

#ifndef	LED_CNFG_H
#define	LED_CNFG_H

typedef struct
{
	u16 pin;
	void* port;
	u8 number;
	u8 OnMode;
	u8 OffMode;
	
} LED_t;

#define HLED_NUM_OF_LEDS						2


#define		LED_DOOR						0
#define		LED_ALARM						1

#endif
