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

// TASK: To turn on the on board LED (LD2) on the NUCLEO Board.
// PROCEDURE:
// Step-1: Identify the GPIO Port and Pin associated with the LED.
// 	-Green LED LD2 connected to PA5.
// 	-Base address of GPIO A is 0x4002 0000.
//	-Port A is on the AHB1 Bus.
//
// Step-2: Activate the GPIO A Port by enabling the clock.
//	-AHB1ENR Register.
//	-RCC Base Address: 0x4002 3800.
//	-Address Offset for AHB1: 0x30.
//	-Set bit-0 to enable GPIO A.
//
// Step-3: Configure GPIO Pin Mode as OUTPUT.
//	-Base address of GPIO A is 0x4002 0000.
//	-Address Offset for GPIO Port Mode Register: 0x00.
//	-Set bits 11 and 10 (for pin 5) to 0 and 1 respectively for General Purpose Output Mode.
//
// Step-4: Write to the GPIO Pin.
//	-Base address of GPIO A is 0x4002 0000.
//	-Address Offset for GPIO Output Data Register: 0x14.
//	-Set bit-5 to 1 to turn ON LED.

#include <stdint.h>

int main(void)
{
	uint32_t *pClkCtrlReg 	= (uint32_t*) 0x40023830;
	uint32_t *pPortAModeReg = (uint32_t*) 0x40020000;
	uint32_t *pPortAOutReg 	= (uint32_t*) 0x40020014;

	//Step-2:
	// To enable Clock for GPIO A in the AHB1ENR, set bit-0 to 1.

	//uint32_t temp = *pClkCtrlReg;		// READ:	the value of data in the register.
	//temp = temp | 0x1;				// MODIFY:	apply the required mask.
	//*pClkCtrlReg = temp;				// WRITE:	the value back to the register.

    *pClkCtrlReg |= (0x1 << 0);				// or:		*pClkCtrlReg = *pClkCtrlReg | 0x1;

    // Step-3:
    // Set bits 11 and 10 (for pin 5) to 0 and 1 respectively for General Purpose Output Mode.

    // 1. CLEAR bits 11 and 10 in the register:
    *pPortAModeReg &= ~(0x11 << 10);

    // 2. Set bits 11, 10 to 0, 1:
    *pPortAModeReg |= (0x01 << 10);

    // Step-4:
    // Set bit-5 to 1 to turn ON LED.
    *pPortAOutReg |= (0x1 << 5);

	for(;;);
}
