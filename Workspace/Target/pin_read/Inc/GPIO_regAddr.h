/*
 * regAddr.h
 *
 *  Created on: Oct 22, 2023
 *      Author: mariestahaab
 *
 *-----------------------------------------------------------------------------
 *  GPIO Register Boundary Addresses (For STM32F446RE):
 *
 *  GPIOA: 0x4002 0000 - 0x4002 03FF
 *  GPIOB: 0x4002 0400 - 0x4002 07FF
 *  GPIOC: 0x4002 0800 - 0x4002 0BFF
 *  GPIOD: 0x4002 0C00 - 0x4002 0FFF
 *  GPIOE: 0x4002 1000 - 0x4002 13FF
 *  GPIOF: 0x4002 1400 - 0x4002 17FF
 *  GPIOG: 0x4002 1800 - 0x4002 1BFF
 *  GPIOH: 0x4002 1C00 - 0x4002 1FFF
 *
 *  RCC Register Base Address:
 *
 *  RCC: 0x4002 3800 - 0x4002 3BFF
 *
 *-----------------------------------------------------------------------------
 *  HOW TO USE:
 *
 *  RCC_AHB1ENR_t volatile *pRCC_AHB1ENR = (RCC_AHB1ENR_t*) 0x40023830;
 *  	pRCC_AHB1ENR -> GPIO_A_EN = 1;
 *  	pRCC_AHB1ENR -> GPIO_C_EN = 1;
 *
 *  GPIOx_MODER_t volatile *pGPIOA_MODER = (GPIOx_MODER_t*) 0x40020000;
 *  	pGPIOA_MODER -> MODER_5 = 1;
 *
 *  GPIOx_MODER_t volatile *pGPIOC_MODER = (GPIOx_MODER_t*) 0x40020800;
 *  	pGPIOC_MODER -> MODER_13 = 0;
 *
 *  GPIOx_IDR_t volatile *pGPIOC_IDR = (GPIOx_IDR_t*) 0x40020810;
 *  	x = pGPIOC_IDR -> IDR_13;
 *
 *  GPIOx_ODR_t volatile *pGPIOA_ODR = (GPIOx_ODR_t*) 0x40020014;
 *  	pGPIOA_ODR -> ODR_5 = 1;
 */

#include <stdint.h>

#ifndef REGADDR_H_
#define REGADDR_H_


/*
 * RCC AHB1 peripheral clock enable register (RCC_AHB1ENR)
 * Address offset: 0x30
 * Reset value: 0x0010 0000
 * Access: no wait state, word, half-word and byte access.
 */
typedef struct{

	uint32_t GPIO_A_EN		:1	;
	uint32_t GPIO_B_EN		:1	;
	uint32_t GPIO_C_EN		:1	;
	uint32_t GPIO_D_EN		:1	;
	uint32_t GPIO_E_EN		:1	;
	uint32_t GPIO_F_EN		:1	;
	uint32_t GPIO_G_EN		:1	;
	uint32_t GPIO_H_EN		:1	;

	uint32_t reserved_0		:4	;

	uint32_t CRC_EN			:1	;

	uint32_t reserved_1		:5	;

	uint32_t BKP_SRAM_EN	:1	;

	uint32_t reserved_2		:2	;

	uint32_t DMA_1_EN		:1	;
	uint32_t DMA_2_EN		:1	;

	uint32_t reserved_3		:6	;

	uint32_t OTGHS_EN		:1	;
	uint32_t OTGHSULPI_EN	:1	;

	uint32_t reserved_4		:1	;

} RCC_AHB1ENR_t;
/*
typedef union{

	uint32_t RCC_AHB1ENR_reg;

	struct{

		uint32_t GPIO_A_EN		:1	;
		uint32_t GPIO_B_EN		:1	;
		uint32_t GPIO_C_EN		:1	;
		uint32_t GPIO_D_EN		:1	;
		uint32_t GPIO_E_EN		:1	;
		uint32_t GPIO_F_EN		:1	;
		uint32_t GPIO_G_EN		:1	;
		uint32_t GPIO_H_EN		:1	;

		uint32_t reserved_0		:4	;

		uint32_t CRC_EN			:1	;

		uint32_t reserved_1		:5	;

		uint32_t BKP_SRAM_EN	:1	;

		uint32_t reserved_2		:2	;

		uint32_t DMA_1_EN		:1	;
		uint32_t DMA_2_EN		:1	;

		uint32_t reserved_3		:6	;

		uint32_t OTGHS_EN		:1	;
		uint32_t OTGHSULPI_EN	:1	;

		uint32_t reserved_4		:1	;

	} RCC_AHB1ENR;

} RCC_AHB1ENR_u;
*/

/*
 * GPIO port mode register (GPIOx_MODER) (x = A..H)
 * Address offset: 0x00
 * Reset values:
 * • 0xA800 0000 for port A
 * • 0x0000 0280 for port B
 * • 0x0000 0000 for other ports
 *
 * These bits are written by software to configure the I/O direction mode.
 * • 00: Input (reset state)
 * • 01: General purpose output mode
 * • 10: Alternate function mode
 * • 11: Analog mode
 */

typedef struct{

	uint32_t MODER_0 		:2	;
	uint32_t MODER_1 		:2	;
	uint32_t MODER_2 		:2	;
	uint32_t MODER_3 		:2	;
	uint32_t MODER_4 		:2	;
	uint32_t MODER_5 		:2	;
	uint32_t MODER_6 		:2	;
	uint32_t MODER_7 		:2	;
	uint32_t MODER_8 		:2	;
	uint32_t MODER_9 		:2	;
	uint32_t MODER_10 		:2	;
	uint32_t MODER_11 		:2	;
	uint32_t MODER_12 		:2	;
	uint32_t MODER_13 		:2	;
	uint32_t MODER_14 		:2	;
	uint32_t MODER_15 		:2	;

} GPIOx_MODER_t;


/*
 * GPIO port input data register (GPIOx_IDR) (x = A..H)
 * Address offset: 0x10
 * Reset value: 0x0000 XXXX (where X means undefined)
 */
typedef struct{

	uint32_t IDR_0 			:1	;
	uint32_t IDR_1 			:1	;
	uint32_t IDR_2 			:1	;
	uint32_t IDR_3 			:1	;
	uint32_t IDR_4 			:1	;
	uint32_t IDR_5 			:1	;
	uint32_t IDR_6 			:1	;
	uint32_t IDR_7 			:1	;
	uint32_t IDR_8 			:1	;
	uint32_t IDR_9 			:1	;
	uint32_t IDR_10 		:1	;
	uint32_t IDR_11 		:1	;
	uint32_t IDR_12 		:1	;
	uint32_t IDR_13 		:1	;
	uint32_t IDR_14 		:1	;
	uint32_t IDR_15 		:1	;

	uint32_t reserved 		:16	;

} GPIOx_IDR_t;


/*
 * GPIO port output data register (GPIOx_ODR) (x = A..H)
 * Address offset: 0x14
 * Reset value: 0x0000 0000
 */
typedef struct{

	uint32_t ODR_0 			:1	;
	uint32_t ODR_1 			:1	;
	uint32_t ODR_2 			:1	;
	uint32_t ODR_3 			:1	;
	uint32_t ODR_4 			:1	;
	uint32_t ODR_5 			:1	;
	uint32_t ODR_6 			:1	;
	uint32_t ODR_7 			:1	;
	uint32_t ODR_8 			:1	;
	uint32_t ODR_9 			:1	;
	uint32_t ODR_10 		:1	;
	uint32_t ODR_11 		:1	;
	uint32_t ODR_12 		:1	;
	uint32_t ODR_13 		:1	;
	uint32_t ODR_14 		:1	;
	uint32_t ODR_15 		:1	;

	uint32_t reserved 		:16	;

} GPIOx_ODR_t;


/*
 * GPIO port pull-up/pull-down register (GPIOx_PUPDR) (x = A..H)
 * Address offset: 0x0C
 * Reset values:
 * • 0x6400 0000 for port A
 * • 0x0000 0100 for port B
 * • 0x0000 0000 for other ports
 *
 * These bits are written by software to configure the I/O pull-up or pull-down.
 * • 00: No pull-up, pull-down
 * • 01: Pull-up
 * • 10: Pull-down
 * • 11: Reserved
 */

typedef union{

	uint32_t GPIOx_PUPDR_reg;

	struct{

		uint32_t PUPDR_0 		:2	;
		uint32_t PUPDR_1 		:2	;
		uint32_t PUPDR_2 		:2	;
		uint32_t PUPDR_3 		:2	;
		uint32_t PUPDR_4 		:2	;
		uint32_t PUPDR_5 		:2	;
		uint32_t PUPDR_6 		:2	;
		uint32_t PUPDR_7 		:2	;
		uint32_t PUPDR_8 		:2	;
		uint32_t PUPDR_9 		:2	;
		uint32_t PUPDR_10 		:2	;
		uint32_t PUPDR_11 		:2	;
		uint32_t PUPDR_12 		:2	;
		uint32_t PUPDR_13 		:2	;
		uint32_t PUPDR_14 		:2	;
		uint32_t PUPDR_15 		:2	;

	} GPIOx_PUPDR;

} GPIOx_PUPDR_u;

#endif /* REGADDR_H_ */
