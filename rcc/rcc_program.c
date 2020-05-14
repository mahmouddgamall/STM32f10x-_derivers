#include "std_types.h"
#include "rcc_interface.h"
#include "rcc_cnfg.h"

#define SW_CLEAR						(u32)0xFFFFFFFC

#define HSEDIV2_VAL					(u8)2

#define	PLLXTPRE_CLEAR			(u32)0xFF7FFFFF

#define PLLMULL_CFGR_CLEAR		(u32)0xFFC3FFFF

#define	RCC_SWS_CLOCK_MASK		(u8)0b1100

#define MCO_OFFSET_CLEAR		(u32)0xF8FFFFFF
#define	MCO_NO_CLOCK				(u32)0
#define	MCO_SYS_CLOCK				(u32)0x4000000
#define	MCO_HSI_CLOCK				(u32)0x5000000
#define	MCO_HSE_CLOCK				(u32)0x6000000
#define	MCO_PLL_CLOCK				(u32)0x7000000

#define	APB2_PRESCHALER_PIN		(u8)11

#define APB2_CFGR_CLEAR			(u32)0xFFFFF8FF

#define	APB1_PRESCHALER_PIN		(u8)8

#define APB1_CFGR_CLEAR			(u32)0xFFFFC7FF

#define	AHB_PRESCHALER_PIN		(u8)4

#define AHB_CFGR_CLEAR			(u32)0xFFFFFF0F

#define PLLSRC_CLEAR	(u32)0xFFF4FFFF
#define	RCC_CLK_RDY_TIMEOUT			10000u

#define BASE_ADDRESS	0x40021000

typedef struct
{
	u32 CR;
	u32 CFGR;
	u32 CIR;
	u32 APB2RSTR;
	u32 APB1RSTR;
	u32 AHBENR;
	u32 APB2ENR;
	u32 APB1ENR;
	u32 BDCR;
	u32 CSR;
}RCCstruct;

static volatile RCCstruct* RCC = (volatile RCCstruct*) BASE_ADDRESS;



void rcc_voidEnableClock(u32 clockSource)
{
	RCC->CR |= clockSource;
}


void rcc_voidDisableClock(u32 clockSourceMask)
{
	RCC->CR &= clockSourceMask;
}



void rcc_voidSelectSysClock(u32 clockSource)
{
	u8 temp = RCC->CFGR;
	temp &= SW_CLEAR;
	temp |= clockSource;
	RCC->CFGR = temp;
}



ErrorStatus rcc_errClockReady(u32 clock)
{
	u16 counter=0;
	u8 status = OK;
	while((!(RCC->CR&clock))&&(counter < RCC_CLK_RDY_TIMEOUT))
		counter++;
	if(counter >= RCC_CLK_RDY_TIMEOUT)status = NOK;
	return status;
}



void rcc_voidPllSource (u32 pllsrc)
{
	u32 temp = RCC->CFGR;
	temp &= PLLSRC_CLEAR;
	temp |= pllsrc;
	RCC->CFGR = temp;
}




void rcc_voidPllMultiplier(u32 pllmul)
{
	RCC->CFGR &= (PLLMULL_CFGR_CLEAR);
	RCC->CFGR |= (pllmul);
}



void rcc_voidResetPeripheralAPB2 (u32 peripheral)
{
	RCC->APB2RSTR|=peripheral;
}


void rcc_voidResetPeripheralAPB1 (u32 peripheral)
{
	RCC->APB1RSTR|=peripheral;
}


void rcc_voidEnablePeripheralAHB (u32 peripheral)
{
	RCC->AHBENR|=peripheral;
}



void rcc_voidDisablePeripheralAHB (u32 peripheral)
{
	RCC->AHBENR &= peripheral;
}


void rcc_voidEnablePeripheralAPB2 (u32 peripheral)
{
	RCC->APB2ENR|=peripheral;
}



void rcc_voidDisablePeripheralAPB2 (u32 peripheral)
{
	RCC->APB2ENR&=peripheral;
}


void rcc_voidEnablePeripheralAPB1 (u32 peripheral)
{
	RCC->APB1ENR|=peripheral;
}




void rcc_voidDisablePeripheralAPB1 (u32 peripheral)
{
	RCC->APB2ENR&=peripheral;
}




void rcc_voidsetMCO(u32 mcosrc)
{
	RCC->CFGR &= MCO_OFFSET_CLEAR;
	RCC->CFGR |= mcosrc;
}

void rcc_voidAHBprescaler(u32 prescaler)
{
		RCC->CFGR &= AHB_CFGR_CLEAR;
		RCC->CFGR |= prescaler;
}



void rcc_voidAPB2prescaler(u32 prescaler)
{
	RCC->CFGR &=(APB2_CFGR_CLEAR);
	RCC->CFGR |= prescaler;
}




void rcc_voidAPB1prescaler(u32 prescaler)
{
	RCC->CFGR &=(APB1_CFGR_CLEAR);
	RCC->CFGR |= prescaler;
}




u8 rcc_u8GetCurrentClock(void)
{
	u32 currentClock = RCC->CFGR & RCC_SWS_CLOCK_MASK ;
	return ((u8)currentClock);
}

u32 rcc_u32GetPLLMultiplier(void)
{
	u32 pllmul = (RCC->CFGR & 0x3C0000);
	return pllmul;
}

u32 rcc_u32GetPLLSource(void)
{
	u32 pllsource = (RCC->CFGR & 0x30000);
	return pllsource;
}

u16 rcc_u16GetAHBPreschaler(void)
{
	u16 currentPreschaler = ((RCC->CFGR)&(0xFF<<4));
	return currentPreschaler;
}

