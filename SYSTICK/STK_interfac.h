/************************************************************
Author :Mohamed Ibrahem
Version:v01
Date:13 March 2020
*************************************************************/
#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H


/************************************************************
Author :Mohamed Ibrahem
Version:v01
Date:13 March 2020
*************************************************************/








#define STK_FLAG_MASK   0x00000010


#define	SYSTICK_PRESCHALER_AHB			4
#define	SYSTICK_PRESCHALER_AHBD8		0xfffffffb



typedef void(*SYSTICK_callBackFunction_t)(void);

/*Configure Prescaler for the Timer and Enable interrupt */

void SYSTICK_voidInit(void);


void SYSTICK_voidSetPreschaler(void);

void SYSTICK_voidStart(void);

void SYSTICK_voidStop(void);

void SYSTICK_voidEnableInterrupt(void);

void SYSTICK_voidDisableInterrupt(void);

u8 SYSTICK_errSetTicks(u32 ticks);

u8 SYSTICK_errSetCallBack(SYSTICK_callBackFunction_t callBackFunction);

u8 SYSTICK_errSetTimerusec(u32 Time_us,u32 speed);


#endif
