/**************************************************** 
 	 Author: Mahmoud Gamal
************************************************/
#ifndef EXTI_REGISTER_H
#define EXTI_REGISTER_H

typedef struct 
{
	u32 IMR;
	u32 EMR;
	u32 RTSR;
	u32 FTSR;
	u32 SWIER;
	u32 PR;
}EXTI_t;

#define		EXTI_BASEADDRESS			0X40010400

volatile EXTI_t *EXTI = (volatile EXTI_t *) EXTI_BASEADDRESS;

#endif