/**************************************************** 
 	 Author: Mahmoud Gamal
 	 Version: 1.0
************************************************/
#ifndef FLASH_H
#define FLASH_H


void FLASH_unlockRegisters(void);
void FLASH_lockRegisters(void);

ErrorStatus FLASH_eraseSection(u32* startAddress);
void FLASH_eraseFlash(void);

void FLASH_writeHalfWord(u32* destinationAddress, u32* sourceAddress);


#endif