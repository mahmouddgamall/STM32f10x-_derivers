/**************************************************** 
 	 Author: Mahmoud Gamal
************************************************/
#include "std_types.h"
#include "bit_math.h"
#include "EXTI_register.h"
#include "EXTI_interface.h"

typedef void(*cbf_t)(void);

cbf_t EXTI_IRQHandler[7];


u8 EXTI_errInterruptMaskDisable(u32 EXTI_PIN)
{
	u8 status = OK;
	if(IS_EXTI_PIN(EXTI_PIN))
	{
		EXTI->IMR |= EXTI_PIN;	
	}
	else
	{
		status = NOK;
	}
	return status;
}

u8 EXTI_errInterruptMaskEnable(u32 EXTI_PIN)
{
	u8 status = OK;
	if(IS_EXTI_PIN(EXTI_PIN))
	{
		EXTI->IMR &=~EXTI_PIN;
	}
	else
	{
		status = NOK;
	}
	return status;
}

u8 EXTI_errEventMaskDisable(u32 EXTI_PIN)
{
	u8 status = OK;
	if(IS_EXTI_PIN(EXTI_PIN))
	{
		EXTI->EMR |= EXTI_PIN;
	}
	else
	{
		status = NOK;
	}
	return status;
}
u8 EXTI_errEventMaskEnable(u32 EXTI_PIN)
{
	u8 status = OK;
	if(IS_EXTI_PIN(EXTI_PIN))
	{
		EXTI->EMR &=~EXTI_PIN;
	}
	else
	{
		status = NOK;
	}
	return status;

}

u8 EXTI_errSetTriggerSource(u32 EXTI_PIN, u8 EXTI_SOURCE)
{
	u8 status = OK;
	if((IS_EXTI_PIN(EXTI_PIN)) && (EXTI_SOURCE < 3))
	{
		EXTI->RTSR &=~ EXTI_PIN;
		EXTI->FTSR &=~ EXTI_PIN;
		if(EXTI_SOURCE == EXTI_SOURCE_RISING_EDGE)
		{
			EXTI->RTSR |= EXTI_PIN;
		}
		else if(EXTI_SOURCE == EXTI_SOURCE_FALLING_EDGE)
		{
			EXTI->FTSR |= EXTI_PIN;
		}
		else if(EXTI_SOURCE == EXTI_SOURCE_ON_CHANGE)
		{
			EXTI->RTSR |= EXTI_PIN;
			EXTI->FTSR |= EXTI_PIN;
		}
	}
	else
	{
		status = NOK;
	}
	return status;

}

u8 EXTI_errSoftwareInt_erruptEnable(u32 EXTI_PIN)
{
	u8 status = OK;
	if(IS_EXTI_PIN(EXTI_PIN))
	{
		EXTI->SWIER|= EXTI_PIN;
	}
	else
	{
		status = NOK;
	}
	return status;
}

u8 EXTI_errClearPendingFlag(u32 EXTI_PIN)
{
	u8 status = OK;
	if(IS_EXTI_PIN(EXTI_PIN))
	{
		EXTI->PR|= EXTI_PIN;
	}
	else
	{
		status = NOK;
	}
	return status;
}

u8 EXTI_errGetPendingFlag(u32 EXTI_PIN, u8* value)
{
	u8 status = OK;
	if(IS_EXTI_PIN(EXTI_PIN))
	{
		if (EXTI->PR & EXTI_PIN)
			*value = EXTI_FLAG_IS_PENDING;
		else
			*value = EXTI_FLAG_IS_NOT_PENDING;
	}
	else
	{
		status = NOK;
	}
	return status;
}

u8 EXTI_errClearAndGetPendingFlag(u32 EXTI_PIN, u8* value)
{
	u8 status = OK;
	if(IS_EXTI_PIN(EXTI_PIN))
	{
		if (EXTI->PR & EXTI_PIN)
		*value = EXTI_FLAG_IS_PENDING;
	else
		*value = EXTI_FLAG_IS_NOT_PENDING;
		EXTI->PR|= EXTI_PIN;

	}
	else
	{
		status = NOK;
	}
	return status;
}

u8 EXTI_errSetCallBackFunction(void (*callBackFunction)(void), u8 EXTI_IRQ)
{
	u8 status = OK;
	if(callBackFunction != NULL)
	{
		EXTI_IRQHandler[EXTI_IRQ] = callBackFunction;
	}
	else
		status = NOK;
	return status;
}

void EXTI0_IRQHandler(void)
{
	EXTI_errClearPendingFlag(EXTI_PIN0);
	if(EXTI_IRQHandler[0])
	{
		EXTI_IRQHandler[0]();
	}
}
void EXTI1_IRQHandler(void)
{
	EXTI_errClearPendingFlag(EXTI_PIN1);
	if(EXTI_IRQHandler[1])
		EXTI_IRQHandler[1]();
}
void EXTI2_IRQHandler(void)
{
	EXTI_errClearPendingFlag(EXTI_PIN2);
	if(EXTI_IRQHandler[2])
		EXTI_IRQHandler[2]();
}
void EXTI3_IRQHandler(void)
{
	EXTI_errClearPendingFlag(EXTI_PIN3);
	if(EXTI_IRQHandler[3])
		EXTI_IRQHandler[3]();
}

void EXTI4_IRQHandler(void)
{
	EXTI_errClearPendingFlag(EXTI_PIN4);
	if(EXTI_IRQHandler[4])
		EXTI_IRQHandler[4]();
}
void EXTI9_5_IRQHandler(void)
{
	if(EXTI_IRQHandler[5])
		EXTI_IRQHandler[5]();
}
void EXTI15_10_IRQHandler(void)
{
	if(EXTI_IRQHandler[6])
		EXTI_IRQHandler[6]();
}
