#include "std_types.h"
#include "GPIO_int.h"



void GPIO_voidinitPins(GPIO_t* hal)
{
	GPIOstruct* GPIOport= (GPIOstruct*) hal->port;
	u32 tempRegLow = GPIOport->CRL, tempRegHigh = GPIOport->CRH;
	/*these variables are to house the value of CRL and CRH before change, and then set them back to the state after change directly*/

	u8 bit=0;

	/*	CRL configuration	*/
	for (bit = 0 ; bit<8 ; bit++)
	{
		/*	If the pin is used	*/
		if( hal->pin & ( 1 << bit ))
		{
			/*	Clear the 4 bits required  to configure the pin	*/
			tempRegLow &=~ ((0xF)<<bit*4);
			/*	Output configuration	*/
			if( hal->mode & 0x10)
			{
				tempRegLow |= (((hal->mode+hal->speed)&0x0F)<<bit*4);
			}
			/*	Input pull up configuration	*/
			else if(hal->mode & 0x20)
			{
				tempRegLow |= (((hal->mode)&0x0F)<<bit*4);
				GPIOport->BSR = (hal->pin);
			}

			/*	Input pull down configuration	*/
			else if(hal->mode & 0x40)
			{
				tempRegLow |= (((hal->mode)&0x0F)<<bit*4);
				GPIOport->BRR = (hal->pin);
			}
			/*other Input configuration	*/
			else if(!(hal->mode & 0xF0))
			{
				tempRegLow |= (((hal->mode)&0x0F)<<bit*4);
			}
		}
	}

	/*	CRH configuration	*/
	for (bit = 0 ; bit<8 ; bit++)
	{

		/*	If the pin is  to be used	in the second 8 bits of the pin configuration*/
		if( hal->pin & ( 1 << (bit+8) ))
		{
			tempRegHigh &=~ ((0xF)<<bit*4);

			/*	Output configuration	*/
			if( hal->mode & 0x10)
			{
				tempRegHigh |= (((hal->mode+hal->speed)&0x0F)<<bit*4);
			}

			/*	Input pull up configuration	*/
			else if(hal->mode & 0x20)
			{
				tempRegHigh |= (((hal->mode)&0x0F)<<bit*4);
				GPIOport->BSR = (hal->pin);
			}

			/*	Input pull down configuration	*/
			else if(hal->mode & 0x40)
			{
				tempRegHigh |= (((hal->mode)&0x0F)<<bit*4);
				GPIOport->BRR = (hal->pin);
			}
			/*	Other Input configuration	*/
			else if(!(hal->mode & 0xF0))
			{
				tempRegHigh |= (((hal->mode)&0x0F)<<bit*4);
			}
		}
	}
	/*	set the value of the registers again	*/
	GPIOport->CRL = tempRegLow;
	GPIOport->CRH = tempRegHigh;

}

void GPIO_voidSetPinValue(void* port,u16 pin, u8 state)
{
	GPIOstruct* GPIOport = (GPIOstruct*)port;
	if(state == GPIO_SET)
		GPIOport->BSR=pin;
	else if (state == GPIO_RESET)
		GPIOport->BRR=pin;

}

u8 GPIO_u8GetPin(void* port, u16 pin)
{
	GPIOstruct* GPIOport = (GPIOstruct*)port;
	u8 status=0;
	if(GPIOport->IDR & pin)
	{
		status=1;
	}

	return status;
}


void GPIO_voidSetPin(void* port,u16 pin)
{
	GPIOstruct* GPIOport = (GPIOstruct*)port;
	GPIOport->BSR=pin;
}
void GPIO_voidResetPin(void* port,u16 pin)
{

	GPIOstruct* GPIOport = (GPIOstruct*)port;
	GPIOport->BRR=pin;
}


void GPIO_voidSetPortValue(GPIOstruct* port, u32 value)
{
	GPIOstruct* GPIOport = (GPIOstruct*)port;
	GPIOport->ODR=value;
}

u16 GPIO_u16GetOutputPort(GPIOstruct* port)
{
	GPIOstruct* GPIOport = (GPIOstruct*)port;
	u16 value = GPIOport->ODR;
	return value;
}


u16 GPIO_u16GetInputPort(GPIOstruct* port)
{
	GPIOstruct* GPIOport = (GPIOstruct*)port;
	u16 value = GPIOport->IDR;
	return value;
}
u16 GPIO_u16GetPin(GPIOstruct* port, u16 pin)
{
	GPIOstruct* GPIOport = (GPIOstruct*)port;
		u16 value = (GPIOport->IDR & pin);
		if (value)		value = 1;
		return value;
}
