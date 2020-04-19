/**************************************************** 
 	 Author: Mahmoud Gamal
************************************************/
#include "std_types.h"
#include "bit_math.h"

#include "AFIO_register.h"
#include "AFIO_interface.h"


#define		AFIO_EXTI_PORT_MASK				0b1111

void AFIO_voidRemapEnable(u32 AFIO_REMAP_PERIPHERAL)
{

	AFIO->MAPR |= AFIO_REMAP_PERIPHERAL;
}
void AFIO_voidRemapDisable(u32 AFIO_REMAP_PERIPHERAL)
{
	AFIO->MAPR &=~ AFIO_REMAP_PERIPHERAL;
}

void AFIO_voidSetEXTIport(u8 AFIO_EXTI_PORT, u32 AFIO_EXTI_PIN)
{
	EXTICR[(AFIO_EXTI_PIN>>4)] &=~ (AFIO_PORT_MASK << (AFIO_EXTI_PIN & 0xFF));
	EXTICR[(AFIO_EXTI_PIN>>4)] |= (AFIO_EXTI_PORT << (AFIO_EXTI_PIN & 0xFF));
	
}