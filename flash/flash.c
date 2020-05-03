/**************************************************** 
 	 Author: Mahmoud Gamal
 	 Version: 1.0
************************************************/
#include "std_types.h"
#include "bit_math.h"
#include "flash.h"


#define	FLASH_KEY1					0x45670123
#define	FLASH_KEY2					0xCDEF89AB
#define	FLASH_ERASE_VALUE			0xFF

#define FLASH_SR_BSY_FLAG			0x00000001

#define	FLASH_CR_LOCK				0x00000080
#define	FLASH_CR_ENABLE_PROGRAM		0x00000001
#define	FLASH_CR_ENABLE_ERASE_PAGE	0x00000002
#define	FLASH_CR_ENABLE_ERASE_FLASH	0x00000003
#define FLASH_CR_START_BIT			0x00000040



typedef struct 
{
	u32 ACR;
	u32 KEYR;
	u32 OPTKEYR;
	u32 SR;
	u32 CR;
	u32 AR;
	u32 reserved;
	u32 OBR;
	u32 WRPR;
}FLASH_t;


const FLASH_t * FLASH = (volatile const FLASH_t *)0x40022000;

void FLASH_unlockRegisters(void)
{
	if((FLASH->CR & FLASH_CR_LOCK) == 1)
	{
		FLASH->KEYR = FLASH_KEY1;
		FLASH->KEYR = FLASH_KEY2;
	}
}
void FLASH_lockRegisters(void)
{
	if((FLASH->CR & FLASH_CR_LOCK) == 0)
	{
		FLASH->CR |= FLASH_CR_LOCK;
	}
}

ErrorStatus FLASH_eraseSection(u32* startAddress)
{
	u8 state;
	FLASH->CR |= FLASH_CR_ENABLE_ERASE_PAGE;
	FLASH->AR = startAddress;
	FLASH->CR |= FLASH_CR_START_BIT;
	while(FLASH->SR & FLASH_SR_BSY_FLAG);
	if(*startAddress == FLASH_ERASE_VALUE)
	{
		state = OK;
	}
	else
	{
		state = NOK;
	}
	return state;

}
void FLASH_eraseFlash(void)
{
	FLASH->CR |= FLASH_CR_ENABLE_ERASE_FLASH;
	FLASH->AR = startAddress;
	FLASH->CR |= FLASH_CR_START_BIT;
}


void FLASH_writeHalfWord(u32* destinationAddress, u32* sourceAddress)
{
	u8 state = OK;
	if( ((destinationAddress >= 0x08000000) && (destinationAddress <= 0x08010000)) && (((sourceAddress >= 0x08000000) && (sourceAddress <= 0x08010000))|| ((sourceAddress >= 0x20000000) && (sourceAddress <= 0x20005000))) )
	{
		if(*destinationAddress == FLASH_ERASE_VALUE)
		{
			FLASH->CR |= FLASH_CR_ENABLE_PROGRAM;
			(u16)*destinationAddress = (u16)*sourceAddress;

			while(FLASH->SR & FLASH_SR_BSY_FLAG);
			if((u16)*destinationAddress == (u16)*sourceAddress)
			{
				state = OK;
			}
			else
			{
				state = NOK;
			}
		}

		else
		{
			state = NOK;
		}	
	}

	else
	{
		state = INVALIDINPUT
	}


	return state;
}

