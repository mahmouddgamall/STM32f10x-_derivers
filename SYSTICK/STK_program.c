#include "bit_math.h"
#include "std_types.h"
#include "STK_interfac.h"
#include "STK_config.h"
#include "RCC_interface.h"

typedef struct
{
	u32 CTRL;
	u32 LOAD;
	u32 VAL;
	u32 CALIB;
}STK_t;

#define		SYSTICK_ENABLE	(u8)0x1
#define		SYSTICK_DISABLE	(u8)0xFFFFFFFE

#define		SYSTICK_INTERRUPT_ENABLE	(u8)0x2
#define		SYSTICK_INTERRUPT_DISABLE	(u8)0xFFFFFFFD

#define STK_BASE_ADDRESS      ((volatile u32*)0xE000E010)
STK_t* STK=(STK_t*)STK_BASE_ADDRESS;

/*Call Back Function For Systick timer*/

static volatile STK_t* SYSTICK = ((volatile STK_t*)0xE000E010) ;
void (* Systick_CallBack)(void) = NULL;

void SYSTICK_voidInit(void)
{
	/*Configure Prescaler  AHP or AHP/8    */
#if SYSTICK_CLK_SOURCE == SYSTICK_PRESCHALER_AHB
	STK->CTRL|=SYSTICK_PRESCHALER_AHB;
#elif SYSTICK_CLK_SOURCE == SYSTICK_PRESCHALER_AHBD8
	STK->CTRL&=SYSTICK_PRESCHALER_AHBD8;
#endif
	/*Enable Interrupt                     */
	STK->CTRL|=SYSTICK_INTERRUPT_ENABLE;

}


void SYSTICK_voidStart(void)
{
	SYSTICK->CTRL |= SYSTICK_ENABLE;
}

void SYSTICK_voidStop(void)
{
	SYSTICK->CTRL &= SYSTICK_DISABLE;
}

void SYSTICK_voidEnableInterrupt(void)
{
	SYSTICK->CTRL |= SYSTICK_INTERRUPT_ENABLE;
}

void SYSTICK_voidDisableInterrupt(void)
{
	SYSTICK->CTRL &= SYSTICK_INTERRUPT_DISABLE;
}

u8 SYSTICK_errSetTicks(u32 ticks)
{
	u8 error_status;
	if(ticks <= 0x00FFFFFF)
	{
		SYSTICK->LOAD = ticks;
		error_status = OK;
	}
	else
		error_status = NOK;
	return error_status;
}

u8 SYSTICK_errSetCallBack(SYSTICK_callBackFunction_t callBackFunction)
{
	if(callBackFunction)
	{
		Systick_CallBack = callBackFunction;
		return OK;
	}
	else
	{
		return NULLPOINTER;
	}
}

void SysTick_Handler(void)
{
	if(Systick_CallBack)
	{
		Systick_CallBack();
	}
}


u8 SYSTICK_errSetTimerusec(u32 Time_us,u32 speed)
{
	u8 status=OK;
	speed/=1000;
#if SYSTICK_CLK_SOURCE == SYSTICK_PRESCHALER_AHB
	;
#elif SYSTICK_CLK_SOURCE == SYSTICK_PRESCHALER_AHBD8
	speed/=8;
#endif

	u32 Load=(Time_us*speed)/1000;
	if(Load <= 0x00FFFFFF)
	{
		STK->LOAD=Load;
		STK->VAL=0;
	}
	else
		status = NOK;
	return status;
}
