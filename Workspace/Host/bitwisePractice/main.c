/*
 * main.c
 *
 *  Created on: Oct 15, 2023
 *      Author: mariestahaab
 */

#include <stdio.h>
#include <stdint.h>

int main(void){

	uint16_t data = 0x0;

	printf("Data        = %4x\n", data);
	printf("Shifted val = %4x\n", data |= (0x1 << 3 | 0x1 << 2));
	printf("Shifted val = %4x\n", data |= (0x3 << 2));
	printf("Shifted val = %4x\n", data |= (0x11 << 2));

	// Bit Extraction:
	printf("\nBIT EXTRACTION:\n");

	data = 0xac00;
	uint16_t temp = 0x0;

	printf("Data             = %4x\n", data);

	//To extract bits 15 to 10 (6-bits) from 16-bit data:
	//	data: 1010 1100 0000 0000
	//	value from 15 to 10 = 1010 11 or 0010 1011 = 2b

	//	-shift the required bits to the LSB (by 10 bits).
	//		0000 0000 0010 1011
	printf("Shifted data     = %4x\n", data >> 10);

	//	-mask the required value (6-bits) and save it in a new variable.
	temp = 0x3F & (data >> 10);
	printf("Extracted (temp) = %4x\n", temp);

	// or store in data, without using temp: data >>= 10;
	data = 0x3F & (data >> 10);
	printf("Extracted (data) = %4x\n", data);

	return 0;
}
