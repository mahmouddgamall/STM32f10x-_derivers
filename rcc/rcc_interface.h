/******************************************
Author: Mahmoud Gamal
02/2/2020
RCC deriver for stm32f10x

******************************************/
#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H


#define	RCC_HSI_SW										(u8)0
#define	RCC_HSE_SW										(u8)1
#define	RCC_PLL_SW										(u8)2
#define	RCC_SW_PIN										(u8)0
#define	RCC_SWS_PIN										(u8)2
#define RCC_HSEDIV2_VAL								(u8)2
#define RCC_PLLHSE										(u8)0
#define RCC_PLLHS1										(u8)1
#define	RCC_HSI_DISABLE								(u32)0xFFFFFFFE
#define	RCC_HSE_DISABLE       	  		(u32)0XFFFEFFFF
#define	RCC_PLL_DISABLE       	  		(u32)0XFEFFFFFF
#define	RCC_HSI_ENABLE								(u8)0X00000001
#define	RCC_HSE_ENABLE								(u32)0X00010000
#define	RCC_PLL_ENABLE								(u32)0X01000000
#define RCC_HSIRDY										(u8)2
#define RCC_HSERDY										(u32)0x00020000
#define RCC_PLLRDY										(u32)0x02000000
#define	RCC_CSSON											(u8)19
#define	RCC_HSEBYP										(u8)18
#define RCC_PLLSRC_HSI								(u32)0
#define RCC_PLLSRC_HSE								(u32)0x00010000
#define RCC_PLLSRC_HSEDIV2						(u32)0x00030000
#define RCC_PLLMUL2										(u32)0
#define RCC_PLLMUL3										(u32)0X40000
#define RCC_PLLMUL4										(u32)0X80000
#define RCC_PLLMUL5										(u32)0XC0000
#define RCC_PLLMUL6										(u32)0X100000
#define RCC_PLLMUL7										(u32)0X140000
#define RCC_PLLMUL8										(u32)0X180000
#define RCC_PLLMUL9										(u32)0X1C0000
#define RCC_PLLMUL10									(u32)0X200000
#define RCC_PLLMUL11									(u32)0X240000
#define RCC_PLLMUL12									(u32)0X280000
#define RCC_PLLMUL13									(u32)0X2C0000
#define RCC_PLLMUL14									(u32)0X200000
#define RCC_PLLMUL15									(u32)0X240000
#define RCC_PLLMUL16									(u32)0X280000
#define	RCC_DMA1EN_AHBENR							(u8)1
#define	RCC_DMA2EN_AHBENR							(u8)2
#define	RCC_SRAMEN_AHBENR							(u8)4
#define	RCC_FLITFEN_AHBENR						(u8)16
#define	RCC_CRCEEN_AHBENR							(u8)64
#define	RCC_FSMCEN_AHBENR							(u8)256
#define	RCC_SDIOEN_AHBENR							(u16)1024
#define	RCC_DMA1EN_AHBENR_DISABLE			(u32)0xFFFFFFFE
#define	RCC_DMA2EN_AHBENR_DISABLE			(u32)0xFFFFFFFD
#define	RCC_SRAMEN_AHBENR_DISABLE			(u32)0xFFFFFFFB
#define	RCC_FLITFEN_AHBENR_DISABLE		(u32)0xFFFFFFEF
#define	RCC_CRCEEN_AHBENR_DISABLE			(u32)0xFFFFFFBF
#define	RCC_FSMCEN_AHBENR_DISABLE			(u32)0xFFFFFEFF
#define	RCC_SDIOEN_AHBENR_DISABLE			(u32)0xFFFFFBFE
#define	RCC_AFIOEN_APB2ENR						(u8)1
#define	RCC_IOPAEN_APB2ENR						(u8)4
#define	RCC_IOPBEN_APB2ENR						(u8)8
#define	RCC_IOPCEN_APB2ENR						(u8)16
#define	RCC_IOPDEN_APB2ENR						(u8)32
#define	RCC_IOPEEN_APB2ENR						(u8)64
#define	RCC_IOPFEN_APB2ENR						(u8)128
#define	RCC_IOPGEN_APB2ENR						(u32)256
#define	RCC_ADC1EN_APB2ENR						(u32)512
#define	RCC_ADC2EN_APB2ENR						(u32)1024
#define	RCC_TIM1EN_APB2ENR						(u32)2048
#define	RCC_SPI1EN_APB2ENR						(u32)4096
#define	RCC_TIM8EN_APB2ENR						(u32)8192
#define	RCC_USART1EN_APB2ENR					(u32)0x4000
#define	RCC_ADC3EN_APB2ENR						(u32)0x8000
#define	RCC_TIM9EN_APB2ENR						(u32)0x80000
#define	RCC_TIM10EN_APB2ENR						(u32)0x100000
#define	RCC_TIM11EN_APB2ENR						(u32)0x200000
#define	RCC_AFIOEN_APB2RST						(u8)1
#define	RCC_IOPAEN_APB2RST						(u8)4
#define	RCC_IOPBEN_APB2RST						(u8)8
#define	RCC_IOPCEN_APB2RST						(u8)16
#define	RCC_IOPDEN_APB2RST						(u8)32
#define	RCC_IOPEEN_APB2RST						(u8)64
#define	RCC_IOPFEN_APB2RST						(u8)128
#define	RCC_IOPGEN_APB2RST						(u32)256
#define	RCC_ADC1EN_APB2RST						(u32)512
#define	RCC_ADC2EN_APB2RST						(u32)1024
#define	RCC_TIM1EN_APB2RST						(u32)2048
#define	RCC_SPI1EN_APB2RST						(u32)4096
#define	RCC_TIM8EN_APB2RST						(u32)8192
#define	RCC_USART1EN_APB2RST					(u32)0x4000
#define	RCC_ADC3EN_APB2RST						(u32)0x8000
#define	RCC_TIM9EN_APB2RST						(u32)0x80000
#define	RCC_TIM10EN_APB2RST						(u32)0x100000
#define	RCC_TIM11EN_APB2RST						(u32)0x200000
#define	RCC_AFIOEN_APB2ENR_DISABLE		(u32)0xFFFFFFFE
#define	RCC_IOPAEN_APB2ENR_DISABLE		(u32)0xFFFFFFFB
#define	RCC_IOPBEN_APB2ENR_DISABLE		(u32)0xFFFFFFF7
#define	RCC_IOPCEN_APB2ENR_DISABLE		(u32)0xFFFFFFEF
#define	RCC_IOPDEN_APB2ENR_DISABLE		(u32)0xFFFFFFDF
#define	RCC_IOPEEN_APB2ENR_DISABLE		(u32)0xFFFFFFBF
#define	RCC_IOPFEN_APB2ENR_DISABLE		(u32)0xFFFFFF7F
#define	RCC_IOPGEN_APB2ENR_DISABLE		(u32)0xFFFFFEFF
#define	RCC_ADC1EN_APB2ENR_DISABLE		(u32)0xFFFFFDFF
#define	RCC_ADC2EN_APB2ENR_DISABLE		(u32)0xFFFFFBFF
#define	RCC_TIM1EN_APB2ENR_DISABLE		(u32)0xFFFFF7FF
#define	RCC_SPI1EN_APB2ENR_DISABLE		(u32)0xFFFFEFFF
#define	RCC_TIM8EN_APB2ENR_DISABLE		(u32)0xFFFFDFFF
#define	RCC_USART1EN_APB2ENR_DISABLE	(u32)0xFFFFBFFF
#define	RCC_ADC3EN_APB2ENR_DISABLE		(u32)0xFFFF7FFF
#define	RCC_TIM9EN_APB2ENR_DISABLE		(u32)0xFFF7FFFF
#define	RCC_TIM10EN_APB2ENR_DISABLE		(u32)0xFFEFFFFF
#define	RCC_TIM11EN_APB2ENR_DISABLE		(u32)0xFFDFFFFF
#define	RCC_TIM2EN_APB1ENR						(u8)1
#define	RCC_TIM3EN_APB1ENR						(u8)2
#define	RCC_TIM4EN_APB1ENR						(u8)4
#define	RCC_TIM5EN_APB1ENR						(u8)8
#define	RCC_TIM6EN_APB1ENR						(u8)16
#define	RCC_TIM7EN_APB1ENR						(u8)32
#define	RCC_TIM12EN_APB1ENR						(u8)64
#define	RCC_TIM13EN_APB1ENR						(u8)128
#define	RCC_TIM14EN_APB1ENR						(u32)256
#define	RCC_WWDEN_APB1ENR							(u32)0x800
#define	RCC_SPI2EN_APB1ENR						(u32)0x4000
#define	RCC_USART2EN_APB1ENR					(u32)0x20000
#define	RCC_USART3EN_APB1ENR					(u32)0x40000
#define	RCC_I2C1EN_APB1ENR						(u32)0x200000
#define	RCC_I2C2EN_APB1ENR						(u32)0x400000
#define	RCC_USBEN_APB1ENR							(u32)0x800000
#define	RCC_CANEN_APB1ENR							(u32)0x2000000
#define	RCC_BKPEN_APB1ENR							(u32)0x8000000
#define	RCC_PWREN_APB1ENR							(u32)0x10000000
#define	RCC_DACEN_APB1ENR							(u32)0x20000000
#define	RCC_TIM2EN_APB1RST						(u8)1
#define	RCC_TIM3EN_APB1RST						(u8)2
#define	RCC_TIM4EN_APB1RST						(u8)4
#define	RCC_TIM5EN_APB1RST						(u8)8
#define	RCC_TIM6EN_APB1RST						(u8)16
#define	RCC_TIM7EN_APB1RST						(u8)32
#define	RCC_TIM12EN_APB1RST						(u8)64
#define	RCC_TIM13EN_APB1RST						(u8)128
#define	RCC_TIM14EN_APB1RST						(u32)256
#define	RCC_WWDEN_APB1RST							(u32)0x800
#define	RCC_SPI2EN_APB1RST						(u32)0x4000
#define	RCC_USART2EN_APB1RST					(u32)0x20000
#define	RCC_USART3EN_APB1RST					(u32)0x40000
#define	RCC_I2C1EN_APB1RST						(u32)0x200000
#define	RCC_I2C2EN_APB1RST						(u32)0x400000
#define	RCC_USBEN_APB1RST							(u32)0x800000
#define	RCC_CANEN_APB1RST							(u32)0x2000000
#define	RCC_BKPEN_APB1RST							(u32)0x8000000
#define	RCC_PWREN_APB1RST							(u32)0x10000000
#define	RCC_DACEN_APB1RST							(u32)0x20000000
#define	RCC_TIM2EN_APB1ENR_DISABLE		(u32)0xFFFFFFFE
#define	RCC_TIM3EN_APB1ENR_DISABLE		(u32)0xFFFFFFFD
#define	RCC_TIM4EN_APB1ENR_DISABLE		(u32)0xFFFFFFFB
#define	RCC_TIM5EN_APB1ENR_DISABLE		(u32)0xFFFFFFF7
#define	RCC_TIM6EN_APB1ENR_DISABLE		(u32)0xFFFFFFEF
#define	RCC_TIM7EN_APB1ENR_DISABLE		(u32)0xFFFFFFDF
#define	RCC_TIM12EN_APB1ENR_DISABLE		(u32)0xFFFFFFBF
#define	RCC_TIM13EN_APB1ENR_DISABLE		(u32)0xFFFFFF7F
#define	RCC_TIM14EN_APB1ENR_DISABLE		(u32)0xFFFFFEFF
#define	RCC_WWDEN_APB1ENR_DISABLE			(u32)0xFFFFF7FF
#define	RCC_SPI2EN_APB1ENR_DISABLE		(u32)0xFFFFBFFF
#define	RCC_USART2EN_APB1ENR_DISABLE	(u32)0xFFFDFFFF
#define	RCC_USART3EN_APB1ENR_DISABLE	(u32)0xFFFBFFFF
#define	RCC_I2C1EN_APB1ENR_DISABLE		(u32)0xFFDFFFFF
#define	RCC_I2C2EN_APB1ENR_DISABLE		(u32)0xFFBFFFFF
#define	RCC_USBEN_APB1ENR_DISABLE			(u32)0xFF7FFFFF
#define	RCC_CANEN_APB1ENR_DISABLE			(u32)0xFDFFFFFF
#define	RCC_BKPEN_APB1ENR_DISABLE			(u32)0xF7FFFFFF
#define	RCC_PWREN_APB1ENR_DISABLE			(u32)0xEFFFFFFF
#define	RCC_DACEN_APB1ENR_DISABLE			(u32)0xDFFFFFFF
#define	RCC_APB1_NO_DIVISOR						(u8)0
#define	RCC_APB1_2_DIVISOR						(u32)0X2000
#define	RCC_APB1_4_DIVISOR						(u32)0X2800
#define	RCC_APB1_8_DIVISOR						(u32)0X3000
#define	RCC_APB1_16_DIVISOR						(u32)0X3800
#define	RCC_AHB_NO_DIVISOR						(u8)0
#define	RCC_AHB_2_DIVISOR							(u8)0x80
#define	RCC_AHB_4_DIVISOR							(u8)0x90
#define	RCC_AHB_8_DIVISOR							(u8)0xA0
#define	RCC_AHB_16_DIVISOR						(u8)0xB0
#define	RCC_AHB_64_DIVISOR						(u8)0xC0
#define	RCC_AHB_128_DIVISOR						(u8)0xD0
#define	RCC_AHB_256_DIVISOR						(u8)0xE0
#define	RCC_AHB_512_DIVISOR						(u8)0xF0
#define	RCC_APB2_NO_DIVISOR						(u8)0
#define	RCC_APB2_2_DIVISOR						(u32)0X400
#define	RCC_APB2_4_DIVISOR						(u32)0X500
#define	RCC_APB2_8_DIVISOR						(u32)0X600
#define	RCC_APB2_16_DIVISOR						(u32)0X700

#define	RCC_SWS_HSI						(u8)0b0000
#define	RCC_SWS_HSE						(u8)0b0100
#define	RCC_SWS_PLL						(u8)0b1000

/*
RCC_HSI_ENABLE
RCC_HSE_ENABLE
RCC_PLL_ENABLE
*/
void rcc_voidEnableClock(u32 clockSource);

/*
RCC_HSI_DISABLE
RCC_HSE_DISABLE
RCC_PLL_DISABLE

*/

void rcc_voidDisableClock(u32 clockSource);

/*
RCC_HSI_SW
RCC_HSE_SW
RCC_PLL_SW
*/

void rcc_voidSelectSysClock(u32 clockSource);

/*
 * RCC_HSIRDY
	 RCC_HSERDY
	 RCC_PLLRDY
*/

ErrorStatus rcc_errClockReady(u32 clock);

/*
RCC_PLLSRC_HSI
RCC_PLLSRC_HSE
RCC_PLLSRC_HSEDIV2
*/

void rcc_voidPllSource (u32 pllsrc);

/*
RCC_PLLMUL2	
RCC_PLLMUL3	
RCC_PLLMUL4	
RCC_PLLMUL5	
RCC_PLLMUL6	
RCC_PLLMUL7	
RCC_PLLMUL8	
RCC_PLLMUL9	
RCC_PLLMUL10
RCC_PLLMUL11
RCC_PLLMUL12
RCC_PLLMUL13
RCC_PLLMUL14
RCC_PLLMUL15
RCC_PLLMUL16
*/

void rcc_voidPllMultiplier(u32 pllmul);

/*
RCC_DMA1EN_AHBENR	
RCC_DMA2EN_AHBENR	
RCC_SRAMEN_AHBENR	
RCC_FLITFEN_AHBENR
RCC_CRCEEN_AHBENR	
RCC_FSMCEN_AHBENR	
RCC_SDIOEN_AHBENR	
*/



void rcc_voidEnablePeripheralAHB (u32 peripheral);

/*

RCC_DMA1EN_AHBENR_DISABLE	
RCC_DMA2EN_AHBENR_DISABLE	
RCC_SRAMEN_AHBENR_DISABLE	
RCC_FLITFEN_AHBENR_DISABLE
RCC_CRCEEN_AHBENR_DISABLE	
RCC_FSMCEN_AHBENR_DISABLE	
RCC_SDIOEN_AHBENR_DISABLE	

*/


void rcc_voidDisablePeripheralAHB (u32 peripheral);

/*
RCC_AFIOEN_APB2ENR	
RCC_IOPAEN_APB2ENR	
RCC_IOPBEN_APB2ENR	
RCC_IOPCEN_APB2ENR	
RCC_IOPDEN_APB2ENR	
RCC_IOPEEN_APB2ENR	
RCC_IOPFEN_APB2ENR	
RCC_IOPGEN_APB2ENR	
RCC_ADC1EN_APB2ENR	
RCC_ADC2EN_APB2ENR	
RCC_TIM1EN_APB2ENR	
RCC_SPI1EN_APB2ENR	
RCC_TIM8EN_APB2ENR	
RCC_USART1EN_APB2ENR
RCC_ADC3EN_APB2ENR	
RCC_TIM9EN_APB2ENR	
RCC_TIM10EN_APB2ENR	
RCC_TIM11EN_APB2ENR	
*/

void rcc_voidEnablePeripheralAPB2 (u32 peripheral);

void rcc_voidResetPeripheralAPB2 (u32 peripheral);


/*
RCC_AFIOEN_APB2ENR_DISABLE	
RCC_IOPAEN_APB2ENR_DISABLE	
RCC_IOPBEN_APB2ENR_DISABLE	
RCC_IOPCEN_APB2ENR_DISABLE	
RCC_IOPDEN_APB2ENR_DISABLE	
RCC_IOPEEN_APB2ENR_DISABLE	
RCC_IOPFEN_APB2ENR_DISABLE	
RCC_IOPGEN_APB2ENR_DISABLE	
RCC_ADC1EN_APB2ENR_DISABLE	
RCC_ADC2EN_APB2ENR_DISABLE	
RCC_TIM1EN_APB2ENR_DISABLE	
RCC_SPI1EN_APB2ENR_DISABLE	
RCC_TIM8EN_APB2ENR_DISABLE	
RCC_USART1EN_APB2ENR_DISABLE
RCC_ADC3EN_APB2ENR_DISABLE	
RCC_TIM9EN_APB2ENR_DISABLE	
RCC_TIM10EN_APB2ENR_DISABLE	
RCC_TIM11EN_APB2ENR_DISABLE	

*/

void rcc_voidDisablePeripheralAPB2 (u32 peripheral);

/*
RCC_TIM2EN_APB1ENR	
RCC_TIM3EN_APB1ENR	
RCC_TIM4EN_APB1ENR	
RCC_TIM5EN_APB1ENR	
RCC_TIM6EN_APB1ENR	
RCC_TIM7EN_APB1ENR	
RCC_TIM12EN_APB1ENR	
RCC_TIM13EN_APB1ENR	
RCC_TIM14EN_APB1ENR	
RCC_WWDEN_APB1ENR		
RCC_SPI2EN_APB1ENR	
RCC_USART2EN_APB1ENR
RCC_USART3EN_APB1ENR
RCC_I2C1EN_APB1ENR	
RCC_I2C2EN_APB1ENR	
RCC_USBEN_APB1ENR		
RCC_CANEN_APB1ENR		
RCC_BKPEN_APB1ENR		
RCC_PWREN_APB1ENR		
RCC_DACEN_APB1ENR		
*/




void rcc_voidEnablePeripheralAPB1 (u32 peripheral);

void rcc_voidResetPeripheralAPB1 (u32 peripheral);




/*

RCC_TIM2EN_APB1ENR_DISABLE	
RCC_TIM3EN_APB1ENR_DISABLE	
RCC_TIM4EN_APB1ENR_DISABLE	
RCC_TIM5EN_APB1ENR_DISABLE	
RCC_TIM6EN_APB1ENR_DISABLE	
RCC_TIM7EN_APB1ENR_DISABLE	
RCC_TIM12EN_APB1ENR_DISABLE	
RCC_TIM13EN_APB1ENR_DISABLE	
RCC_TIM14EN_APB1ENR_DISABLE	
RCC_WWDEN_APB1ENR_DISABLE		
RCC_SPI2EN_APB1ENR_DISABLE	
RCC_USART2EN_APB1ENR_DISABLE
RCC_USART3EN_APB1ENR_DISABLE
RCC_I2C1EN_APB1ENR_DISABLE	
RCC_I2C2EN_APB1ENR_DISABLE	
RCC_USBEN_APB1ENR_DISABLE		
RCC_CANEN_APB1ENR_DISABLE		
RCC_BKPEN_APB1ENR_DISABLE		
RCC_PWREN_APB1ENR_DISABLE		
RCC_DACEN_APB1ENR_DISABLE		

*/



void rcc_voidDisablePeripheralAPB1 (u32 peripheral);

/*
RCC_MCO_NO_CLOCK	
RCC_MCO_SYS_CLOCK	
RCC_MCO_HSI_CLOCK	
RCC_MCO_HSE_CLOCK	
RCC_MCO_PLL_CLOCK	
*/

void rcc_voidsetMCO(u32 mcosrc);

/*
RCC_AHB_NO_DIVISOR	
RCC_AHB_2_DIVISOR		
RCC_AHB_4_DIVISOR		
RCC_AHB_8_DIVISOR		
RCC_AHB_16_DIVISOR	
RCC_AHB_64_DIVISOR	
RCC_AHB_128_DIVISOR
RCC_AHB_256_DIVISOR
RCC_AHB_512_DIVISOR
*/

void rcc_voidAHBprescaler(u32 prescaler);


/*

RCC_APB2_NO_DIVISOR	
RCC_APB2_2_DIVISOR	
RCC_APB2_4_DIVISOR	
RCC_APB2_8_DIVISOR	
RCC_APB2_16_DIVISOR	

*/

void rcc_voidAPB2prescaler(u32 prescaler);


/*

RCC_APB1_NO_DIVISOR	
RCC_APB1_2_DIVISOR	
RCC_APB1_4_DIVISOR	
RCC_APB1_8_DIVISOR	
RCC_APB1_16_DIVISOR	

*/

void rcc_voidAPB1prescaler(u32 prescaler);

u8 rcc_u8GetCurrentClock(void);

u32 rcc_u32GetPLLMultiplier(void);

u32 rcc_u32GetPLLSource(void);

u16 rcc_u16GetAHBPreschaler(void);



#endif
