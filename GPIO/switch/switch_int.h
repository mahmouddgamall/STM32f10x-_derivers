/*	Please choose the number of leds that you need in your system	*/

#ifndef	SWITCH_INT_H
#define	SWITCH_INT_H

#define SWITCH_PRESSED		(u8)1
#define SWITCH_RELEASED		(u8)0


extern void HSWITCH_voidinit(void);


/*
 * LED_ALARM
 * LED_DOOR
 *
 *
 * LED_ON
 * LED_OFF
 * */
extern ErrorStatus HSWITCH_errGetSwitchValue(u8 Switch, u8 *state);

#endif
