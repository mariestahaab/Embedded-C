/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
#include <stdint.h>
#include <stdio.h>

volatile uint32_t *ClkCtrlReg = (uint32_t*) 0x40023830;

volatile uint32_t *portA_ModeReg = (uint32_t*) 0x40020000;
volatile uint32_t *portB_ModeReg = (uint32_t*) 0x40020400;

volatile uint32_t *portA_PuPdReg = (uint32_t*) 0x4002000C;

volatile uint32_t *portA_InReg = (uint32_t*) 0x40020010;
volatile uint32_t *portB_OutReg = (uint32_t*) 0x40020414;

int main(void)
{
	//CONFIGURE REGISTERS:

	*ClkCtrlReg		|= (0x1 << 1) | (0x1 << 0);

	*portA_ModeReg &= ~(0x3 << 16) & ~(0x3 << 14) & ~(0x3 << 12) & ~(0x3 << 10);	// CLEAR

	*portA_PuPdReg &= ~(0x3 << 16) & ~(0x3 << 14) & ~(0x3 << 12) & ~(0x3 << 10);	// CLEAR
	*portA_PuPdReg |= (0x1 << 16) | (0x1 << 14) | (0x1 << 12) | (0x1 << 10);		// SET

	*portB_ModeReg &= ~(0x3 << 18) & ~(0x3 << 16) & ~(0x3 << 12) & ~(0x3 << 10);		// CLEAR
	*portB_ModeReg |= (0x1 << 18) | (0x1 << 16) | (0x1 << 12) | (0x1 << 10);			// SET

	printf("Hello World\n");

	while(1){

		*portB_OutReg |= (0x3 << 8 | 0x3 << 5);		// Make all ROWS HIGH.
		*portB_OutReg &= ~(0x1 << 8);		// Make R1 LOW.

		if( !((*portA_InReg >> 5) & 0x1) ){
			for(uint32_t i = 300000; i > 0; i--);
			printf("1\n");
		}
		if( !((*portA_InReg >> 6) & 0x1) ){
			for(uint32_t i = 300000; i > 0; i--);
			printf("2\n");
		}
		if( !((*portA_InReg >> 7) & 0x1) ){
			for(uint32_t i = 300000; i > 0; i--);
			printf("3\n");
		}
		if( !((*portA_InReg >> 8) & 0x1) ){
			for(uint32_t i = 300000; i > 0; i--);
			printf("A\n");
		}

		*portB_OutReg |= (0x3 << 8 | 0x3 << 5);		// Make all ROWS HIGH.
		*portB_OutReg &= ~(0x1 << 9);		// Make R2 LOW.

		if( !(*portA_InReg & (0x1 << 5)) ){
			for(uint32_t i = 300000; i > 0; i--);
			printf("4\n");
		}
		if( !(*portA_InReg & (0x1 << 6)) ){
			for(uint32_t i = 300000; i > 0; i--);
			printf("5\n");
		}
		if( !(*portA_InReg & (0x1 << 7)) ){
			for(uint32_t i = 300000; i > 0; i--);
			printf("6\n");
		}
		if( !(*portA_InReg & (0x1 << 8)) ){
			for(uint32_t i = 300000; i > 0; i--);
			printf("B\n");
		}

		*portB_OutReg |= (0x3 << 8 | 0x3 << 5);		// Make all ROWS HIGH.
		*portB_OutReg &= ~(0x1 << 5);		// Make R3 LOW.

		if( !(*portA_InReg & (0x1 << 5)) ){
			for(uint32_t i = 300000; i > 0; i--);
			printf("7\n");
		}
		if( !(*portA_InReg & (0x1 << 6)) ){
			for(uint32_t i = 300000; i > 0; i--);
			printf("8\n");
		}
		if( !(*portA_InReg & (0x1 << 7)) ){
			for(uint32_t i = 300000; i > 0; i--);
			printf("9\n");
		}
		if( !(*portA_InReg & (0x1 << 8)) ){
			for(uint32_t i = 300000; i > 0; i--);
			printf("C\n");
		}

		*portB_OutReg |= (0x3 << 8 | 0x3 << 5); 	// Make all ROWS HIGH.
		*portB_OutReg &= ~(0x1 << 6);		// Make R4 LOW.

		if( !(*portA_InReg & (0x1 << 5)) ){
			for(uint32_t i = 300000; i > 0; i--);
			printf("*\n");
		}
		if( !(*portA_InReg & (0x1 << 6)) ){
			for(uint32_t i = 300000; i > 0; i--);
			printf("0\n");
		}
		if( !(*portA_InReg & (0x1 << 7)) ){
			for(uint32_t i = 300000; i > 0; i--);
			printf("#\n");
		}
		if( !(*portA_InReg & (0x1 << 8)) ){
			for(uint32_t i = 300000; i > 0; i--);
			printf("D\n");
		}
	}
}