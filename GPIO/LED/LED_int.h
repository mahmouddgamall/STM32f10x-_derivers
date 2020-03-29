/*	Please choose the number of leds that you need in your system	*/

#ifndef	LED_H
#define	LED_H

#define LED_ON		(u8)1
#define LED_OFF		(u8)2



extern void HLED_voidinit(void);


/*
 * LED_ALARM
 * LED_DOOR
 *
 *
 * LED_ON
 * LED_OFF
 * */
extern ErrorStatus HLED_errsetLedState(u8 LED, u8 state);

#endif
