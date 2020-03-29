#include "std_types.h"
#include "rcc_interface.h"
#include "rcc_cnfg.h"

#include "HRCC.h"
extern void HRCC_voidSetSystemClockSpeed(u8 HRCC_SYS_CLK)
{
	rcc_voidEnableClock(RCC_HSE_ENABLE);
	rcc_voidSelectSysClock(RCC_HSE_SW);
	rcc_voidDisableClock(RCC_HSI_DISABLE);
	rcc_voidDisableClock(RCC_PLL_DISABLE);

	if(HRCC_SYS_CLK !=0)
	{
		if((HRCC_SYS_CLK & 0xF0) == 0)
		{
			rcc_voidPllSource(RCC_PLLSRC_HSE);
		}
		else if((HRCC_SYS_CLK & 0xF0) == 1)
		{
			rcc_voidPllSource(RCC_PLLSRC_HSEDIV2);
		}
		
		if((HRCC_SYS_CLK & 0x0F) == 1)
		{
			rcc_voidPllMultiplier(RCC_PLLMUL2);
		}
		else if((HRCC_SYS_CLK & 0x0F) == 2)
		{
			rcc_voidPllMultiplier(RCC_PLLMUL3);
		}
		else if((HRCC_SYS_CLK & 0x0F) == 3)
		{
			rcc_voidPllMultiplier(RCC_PLLMUL4);
		}
		else if((HRCC_SYS_CLK & 0x0F) == 4)
		{
			rcc_voidPllMultiplier(RCC_PLLMUL5);
		}
		else if((HRCC_SYS_CLK & 0x0F) == 5)
		{
			rcc_voidPllMultiplier(RCC_PLLMUL6);
		}
		else if((HRCC_SYS_CLK & 0x0F) == 6)
		{
			rcc_voidPllMultiplier(RCC_PLLMUL7);
		}
		else if((HRCC_SYS_CLK & 0x0F) == 7)
		{
			rcc_voidPllMultiplier(RCC_PLLMUL8);
		}
		else if((HRCC_SYS_CLK & 0x0F) == 8)
		{
			rcc_voidPllMultiplier(RCC_PLLMUL9);
		}
		else if((HRCC_SYS_CLK & 0x0F) == 0xA)
		{
			rcc_voidPllMultiplier(RCC_PLLMUL11);
		}
		else if((HRCC_SYS_CLK & 0x0F) == 0xB)
		{
			rcc_voidPllMultiplier(RCC_PLLMUL13);
		}
		else if((HRCC_SYS_CLK & 0x0F) == 0xC)
		{
			rcc_voidPllMultiplier(RCC_PLLMUL15);
		}
		rcc_voidEnableClock(RCC_PLL_ENABLE);
		rcc_voidSelectSysClock(RCC_PLL_SW);
	}
}

extern u8 HRCC_errEnablePeripheral(u64 HRCC_Peripheral)
{
	u8 status = OK;
	if((HRCC_Peripheral & 0xF00000000)==0xA00000000)
	{
		rcc_voidEnablePeripheralAHB((u32) HRCC_Peripheral);
	}
	else if((HRCC_Peripheral & 0xF00000000)==0xC00000000)
	{
		rcc_voidEnablePeripheralAPB2((u32) HRCC_Peripheral);
	}
	else if((HRCC_Peripheral & 0xF00000000)==0xE00000000)
	{
		rcc_voidEnablePeripheralAPB1((u32) HRCC_Peripheral);
	}
	else
	{
		status = NOK;
	}
	return status;
}

extern u8 HRCC_errDisablePeripheral(u64 HRCC_Peripheral)
{
	u8 status = OK;
	if((HRCC_Peripheral & 0xF00000000)==0xB00000000)
	{
		rcc_voidDisablePeripheralAHB((u32) HRCC_Peripheral);
	}
	else if((HRCC_Peripheral & 0xF00000000)==0xD00000000)
	{
		rcc_voidDisablePeripheralAPB2((u32) HRCC_Peripheral);
	}
	else if((HRCC_Peripheral & 0xF00000000)==0xF00000000)
	{
		rcc_voidDisablePeripheralAPB1((u32) HRCC_Peripheral);
	}
	else
	{
		status = NOK;
	}
	return status;
}



u32 HRCC_u32GetCurrentClockSpeed(void)
{
	u32 currentClockSpeed=0;
	u32 currentClock=0;
	currentClock = rcc_u8GetCurrentClock() ;
	if(currentClock == RCC_SWS_HSI)
	{
		currentClockSpeed = 8000000;
	}
	else if(currentClock == RCC_SWS_HSE)
	{
		currentClockSpeed = RCC_EXTERNAL_CLOCK_SPEED;
	}
	else if(currentClock == RCC_SWS_PLL)
	{
		u16 pllmul = (rcc_u32GetPLLMultiplier()>>18);
		if(pllmul == 0b1111)	pllmul = pllmul - 1;
		pllmul = pllmul +2;
		u8 pllsrc = rcc_u32GetPLLSource();
		if(pllsrc == RCC_PLLSRC_HSI)
		{
			currentClockSpeed = (4000000*pllmul);
		}
		else if(pllsrc == RCC_PLLSRC_HSE)
		{
			currentClockSpeed = (RCC_EXTERNAL_CLOCK_SPEED*pllmul);
		}
		else
		{
			currentClockSpeed = ((RCC_EXTERNAL_CLOCK_SPEED*pllmul)/2);
		}
	}
	return currentClockSpeed;
}


u32 HRCC_u32GetAHBClockSpeed(void)
{
	u8 currentPreschaler = rcc_u16GetAHBPreschaler();
	u32 currentClockSpeed = HRCC_u32GetCurrentClockSpeed();
	if(currentPreschaler>8)
	{
		if(currentPreschaler == RCC_AHB_2_DIVISOR)
			currentClockSpeed=currentClockSpeed/2;
		if(currentPreschaler == RCC_AHB_4_DIVISOR)
			currentClockSpeed=currentClockSpeed/4;
		if(currentPreschaler == RCC_AHB_8_DIVISOR)
			currentClockSpeed=currentClockSpeed/8;
		if(currentPreschaler == RCC_AHB_16_DIVISOR)
			currentClockSpeed=currentClockSpeed/16;
		if(currentPreschaler == RCC_AHB_64_DIVISOR)
			currentClockSpeed=currentClockSpeed/64;
		if(currentPreschaler == RCC_AHB_128_DIVISOR)
			currentClockSpeed=currentClockSpeed/128;
		if(currentPreschaler == RCC_AHB_256_DIVISOR)
			currentClockSpeed=currentClockSpeed/256;
		if(currentPreschaler == RCC_AHB_512_DIVISOR)
			currentClockSpeed=currentClockSpeed/512;
	}
	return currentClockSpeed;
}
