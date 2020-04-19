/**************************************************** 
 	 Author: Mahmoud Gamal
************************************************/
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

#define	EXTI_PIN0 				0x00000001 			
#define	EXTI_PIN1 				0x00000002
#define	EXTI_PIN2 				0x00000004
#define	EXTI_PIN3 				0x00000008
#define	EXTI_PIN4 				0x00000010
#define	EXTI_PIN5 				0x00000020
#define	EXTI_PIN6 				0x00000040
#define	EXTI_PIN7 				0x00000080
#define	EXTI_PIN8 				0x00000100
#define	EXTI_PIN9 				0x00000200
#define	EXTI_PIN10				0x00000400
#define	EXTI_PIN11				0x00000800
#define	EXTI_PIN12				0x00001000
#define	EXTI_PIN13				0x00002000
#define	EXTI_PIN14				0x00004000
#define	EXTI_PIN15				0x00008000
#define	EXTI_PIN16				0x00010000
#define	EXTI_PIN17				0x00020000
#define	EXTI_PIN18				0x00040000
#define	EXTI_PIN19				0x00080000

#define	EXTI_SOURCE_RISING_EDGE			0
#define	EXTI_SOURCE_FALLING_EDGE		1
#define	EXTI_SOURCE_ON_CHANGE			2

#define EXTI_FLAG_IS_PENDING			1
#define EXTI_FLAG_IS_NOT_PENDING		0

#define	EXTI_IRQ0						0
#define	EXTI_IRQ1						1
#define	EXTI_IRQ2						2
#define	EXTI_IRQ3						3
#define	EXTI_IRQ4						4
#define	EXTI_IRQ9_5						5
#define	EXTI_IRQ15_10					6

#define IS_EXTI_PIN(PIN) 			(((PIN) == EXTI_PIN0) || \
                                    ((PIN) == EXTI_PIN1) || \
                                    ((PIN) == EXTI_PIN2) || \
                                    ((PIN) == EXTI_PIN3) || \
                                    ((PIN) == EXTI_PIN4) || \
                                    ((PIN) == EXTI_PIN5) || \
                                    ((PIN) == EXTI_PIN6) || \
                                    ((PIN) == EXTI_PIN7) || \
                                    ((PIN) == EXTI_PIN8) || \
                                    ((PIN) == EXTI_PIN9) || \
                                    ((PIN) == EXTI_PIN10) || \
                                    ((PIN) == EXTI_PIN11) || \
                                    ((PIN) == EXTI_PIN12) || \
                                    ((PIN) == EXTI_PIN13) || \
                                    ((PIN) == EXTI_PIN14) || \
                                    ((PIN) == EXTI_PIN15) || \
                                    ((PIN) == EXTI_PIN16) || \
                                    ((PIN) == EXTI_PIN17) || \
                                    ((PIN) == EXTI_PIN18) || \
                                    ((PIN) == EXTI_PIN19))

u8 EXTI_errInterruptMaskEnable(u32 EXTI_PIN);
u8 EXTI_errInterruptMaskDisable(u32 EXTI_PIN);

u8 EXTI_errEventMaskEnable(u32 EXTI_PIN);
u8 EXTI_errEventMaskDisable(u32 EXTI_PIN);

u8 EXTI_errSetTriggerSource(u32 EXTI_PIN, u8 EXTI_SOURCE);

u8 EXTI_errSoftwareInterruptEnable(u32 EXTI_PIN);

u8 EXTI_errClearPendingFlag(u32 EXTI_PIN);

u8 EXTI_errSetCallBackFunction(void (*callBackFunction)(void), u8 EXTI_IRQ);


u8 EXTI_errClearAndGetPendingFlag(u32 EXTI_PIN, u8* value);
u8 EXTI_errClearAndGetPendingFlag(u32 EXTI_PIN, u8* value);


#endif
