/*
 * keypadTest.c
 *
 *  Created on: Oct 24, 2023
 *      Author: mariestahaab
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

	*portB_ModeReg &= ~(0x3 << 12) & ~(0x3 << 10) & ~(0x3 << 8) & ~(0x3 << 6);		// CLEAR
	*portB_ModeReg |= (0x1 << 12) | (0x1 << 10) | (0x1 << 8) | (0x1 << 6);			// SET

	printf("Hello World\n");

	while(1){

		*portB_OutReg |= (0xF << 3);		// Make all ROWS HIGH.

		*portB_OutReg &= ~(0x1 << 3);		// Make R1 LOW.

		if( !(*portA_InReg & (0x1 << 5)) ){
			for(uint32_t i = 300000; i > 0; i--);
			printf("Key 1 pressed\n");
		}
		else if( !(*portA_InReg & (0x1 << 6)) ){
			for(uint32_t i = 300000; i > 0; i--);
			printf("Key 2 pressed\n");
		}
		else if( !(*portA_InReg & (0x1 << 7)) ){
			for(uint32_t i = 300000; i > 0; i--);
			printf("Key 3 pressed\n");
		}
		else if( !(*portA_InReg & (0x1 << 8)) ){
			for(uint32_t i = 300000; i > 0; i--);
			printf("Key A pressed\n");
		}
	}

}
