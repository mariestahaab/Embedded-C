/*
 * toggle_led.c
 *
 *  Created on: Oct 15, 2023
 *      Author: mariestahaab
 */

#include <stdint.h>
#include "regAddr.h"


uint32_t pressedButton(void);

volatile uint32_t *pClkCtrlReg		= (uint32_t*) 0x40023830;

volatile uint32_t *pPortCModeReg	= (uint32_t*) 0x40020800;
volatile uint32_t *pPortCInReg		= (uint32_t*) 0x40020810;

volatile uint32_t *pPortAModeReg	= (uint32_t*) 0x40020000;
volatile uint32_t *pPortAOutReg		= (uint32_t*) 0x40020014;

int main(void){

	// To enable Clock for GPIO A and GPIO C in the AHB1ENR, set bits 2, 0 to 1, 1.
    *pClkCtrlReg	|= (0x1 << 2 | 0x1 << 0);

    // Set bits 27, 26 (MODER13) to 0, 0 respectively for Input Mode.
    *pPortCModeReg	&= ~(0x1 << 27 | 0x1 << 26);

    // Set bits 11 and 10 (for pin 5) to 0 and 1 respectively for General Purpose Output Mode.

    // 1. CLEAR bits 11 and 10 in the register:
    *pPortAModeReg	&= ~(0x1 << 11 | 0x1 << 10);

    // 2. Set bits 11, 10 to 0, 1:
    *pPortAModeReg	|= (0x01 << 10);

    while(1){

    	if(pressedButton() & 0x1){
    		*pPortAOutReg ^= (0x1 << 5);
    	}
    }
}

uint32_t pressedButton(void){

	static uint32_t buttonLastState;	//Default value of static variable is 0.
	uint32_t buttonCurrentState = ~(*pPortCInReg >> 13);
	uint32_t buttonPressed = (~buttonCurrentState) & (buttonLastState);

	buttonLastState = buttonCurrentState;

	return buttonPressed;
}

