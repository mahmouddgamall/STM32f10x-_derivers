#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H
typedef struct
{
	u32 CRL;
	u32 CRH;
	u32 IDR;
	u32 ODR;
	u32 BSR;
	u32 BRR;
	u32 LCK;
}GPIOstruct;

typedef struct{
	u32 pin;
	u8 speed;
	u8 mode;
	volatile GPIOstruct* port;
}GPIO_t;


#define PORTA 				(volatile GPIOstruct*) 0x40010800
#define PORTB 			    (volatile GPIOstruct*) 0x40010C00
#define PORTC				 	 (volatile GPIOstruct*) 0x40011000

#define MODE_INPUT_ANALOG							(u8)0
#define MODE_INPUT_FLOATING							(u8)4
#define MODE_INPUT_PULL_UP							(u8)0x28
#define MODE_INPUT_PULL_DOWN						(u8)0x48

/*	a bit is set in the next 4 bits so as to distinguish between input and output configurations	*/
/*	This bit will be removed by "& 0x0F" in the function, so it wil not affect other configurations	*/
/*	Check the init function to understand more	*/
#define MODE_OUTPUT_PUSH_PULL						(u8)0x10
#define MODE_OUTPUT_OPEN_DRAIN						(u8)0x14
#define MODE_OUTPUT_AF_PUSH_PULL					(u8)0x18
#define MODE_OUTPUT_AF_OPEN_DRAIN					(u8)0x1C


#define	SPEED_10_MHZ								(u8)1
#define	SPEED_2_MHZ									(u8)2
#define	SPEED_50_MHZ								(u8)3

#define	GPIO_RESET									0u
#define	GPIO_SET									1u

#define	PIN_0										(u8)1
#define	PIN_1										(u8)2
#define	PIN_2										(u8)4
#define	PIN_3										(u8)8
#define	PIN_4										(u8)0x10
#define	PIN_5										(u8)0x20
#define	PIN_6										(u8)0x40
#define	PIN_7										(u8)0x80
#define	PIN_8										(u16)0x100
#define	PIN_9										(u16)0x200
#define	PIN_10										(u16)0x400
#define	PIN_11										(u16)0x800
#define	PIN_12										(u16)0x1000
#define	PIN_13										(u16)0x2000
#define	PIN_14										(u16)0x4000
#define	PIN_15										(u16)0x8000

#define	ALL_PINS										(u16)0xFFFF

void GPIO_voidinitPins(GPIO_t* hal);

void GPIO_voidSetPinValue(void* port,u16 pin, u8 state);


/*PIN_0
 *PIN_1
 *PIN_2
 *PIN_3
 *PIN_4
 *PIN_5
 *PIN_6
 *PIN_7
 *PIN_8
 *PIN_9
 *PIN_10
 *PIN_11
 *PIN_12
 *PIN_13
 *PIN_14
 *PIN_15
 * */

void GPIO_voidSetPin(void* port,u16 pin);


/*PIN_0
 *PIN_1
 *PIN_2
 *PIN_3
 *PIN_4
 *PIN_5
 *PIN_6
 *PIN_7
 *PIN_8
 *PIN_9
 *PIN_10
 *PIN_11
 *PIN_12
 *PIN_13
 *PIN_14
 *PIN_15
 * */

void GPIO_voidResetPin(void* port,u16 pin);

/*
 * PORTA
 * PORTB
 * PORTC
 * */

void GPIO_voidSetPortValue(GPIOstruct* port, u32 value);
/*
 * PORTA
 * PORTB
 * PORTC
 * */

u16 GPIO_u16GetOutputPort(GPIOstruct* port);

/*
 * PORTA
 * PORTB
 * PORTC
 * */
u16 GPIO_u16GetInputPort(GPIOstruct* port);
u16 GPIO_u16GetPin(GPIOstruct* port, u16 pin);

void GPIO_voidSetPeripheralPin(GPIO_t* hal,u16 pin);
void GPIO_voidPeripheralResetPin(GPIO_t* hal,u16 pin);

#endif
