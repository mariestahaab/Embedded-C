/*
 * PB13_ON.c
 *
 *  Created on: Oct 15, 2023
 *      Author: mariestahaab
 */

//
//	NOTE: This does not turn on the LED.
//

// TASK: To turn on the on board LED (LD2) on the NUCLEO Board.
// PROCEDURE:
// Step-1: Identify the GPIO Port and Pin associated with the LED.
// 	-Green LED LD2 connected to PA5 or PB13.
// 	-Base address of GPIO B is 0x4002 0400.
//	-Both ports share the AHB1 Bus.
//
// Step-2: Activate the GPIO B Port by enabling the clock.
//	-AHB1ENR Register.
//	-RCC Base Address: 0x4002 3800.
//	-Address Offset for AHB1: 0x30.
//	-Set bit-1 to enable GPIO B.
//
// Step-3: Configure GPIO Pin Mode as OUTPUT.
//	-Base address of GPIO B is 0x4002 0400.
//	-Address Offset for GPIO Port Mode Register: 0x00.
//	-Set bits 27 and 26 (for pin 13) to 0 and 1 respectively for General Purpose Output Mode.
//
// Step-4: Write to the GPIO Pin.
//	-Base address of GPIO B is 0x4002 0400.
//	-Address Offset for GPIO Output Data Register: 0x14.
//	-Set bit-13 to 1 to turn ON LED.

#include <stdint.h>

int main(void)
{
	uint32_t *pClkCtrlReg 	= (uint32_t*) 0x40023830;
	uint32_t *pPortBModeReg = (uint32_t*) 0x40020400;
	uint32_t *pPortBOutReg 	= (uint32_t*) 0x40020414;

	//Step-2:
	// To enable Clock for GPIO B in the AHB1ENR, set bit-1 to 1.

	//uint32_t temp = *pClkCtrlReg;		// READ:	the value of data in the register.
	//temp = temp | 0x10;				// MODIFY:	apply the required mask.
	//*pClkCtrlReg = temp;				// WRITE:	the value back to the register.

    *pClkCtrlReg |= (0x1 << 1);			// or:		*pClkCtrlReg = *pClkCtrlReg | 0x10;

    // Step-3:
    // Set bits 27 and 26 (for pin 13) to 0 and 1 respectively for General Purpose Output Mode.

    // 1. CLEAR bits 27 and 26 in the register:
    *pPortBModeReg &= ~(0x11 << 26);

    // 2. Set bits 27, 26 to 0, 1:
    *pPortBModeReg |= (0x01 << 26);

    // Step-4:
    // Set bit-13 to 1 to turn ON LED.
    *pPortBOutReg |= (0x1 << 13);

	for(;;);
}
