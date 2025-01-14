/*
 * structBitFields_Exercise165.c
 *
 *  Created on: Oct 18, 2023
 *      Author: mariestahaab
 */

/*
 * Question: Create a structure named "CarDetails" which comprises of the following information:
 * 1)	Car max speed	= 400 kmph 					(7-bits )
 * 2)	Car weight		= 5000 kg 					(13-bits)
 * 3)	Car colour		= an ASCII code of colour	(7-bits )
 * 4)	Car price		= 100,000,000 USD 			(28-bits)
 *
 * Total size of data = 55-bits.
 * Size of struct with bit fields = 64 bits  -> 8-Bytes
 * Size of struct without bit fields = 12-Bytes
 */

#include <stdint.h>
#include <stdio.h>

typedef struct{
	uint16_t speed	;
	uint16_t weight	;
	uint8_t  colour	;
	uint32_t price	;
} CarDetails_0_t;

typedef struct{
	uint32_t speed	:7 ;	// bits 0 to 6		of 32-bit word.
	uint32_t weight	:13;	// bits 7 to 19		of 32-bit word.
	uint32_t colour	:7 ;	// bits 20 to 26	of 32-bit word.
							// bits 27 to 31 (5-bits) free in 32-bit word.
							// not enough space for price (28-bits).
	// One Way (1):
	uint32_t priceL	:5 ;	// lower 5-bits of price stored in the same 32-bit word.
	uint32_t priceH	:23;	// remaining bits of price stored in new 32-bit word.

	// Another way (2):
	//uint32_t price;			// price stored in new 32-bit word.
} CarDetails_1_t;

typedef struct{
	uint32_t speed	:7 ;	// bits 0 to 6		of 32-bit word.
	uint32_t weight	:13;	// bits 7 to 19		of 32-bit word.
	uint32_t colour	:7 ;	// bits 20 to 26	of 32-bit word.
							// bits 27 to 31 (5-bits) free in 32-bit word.
							// not enough space for price (28-bits).
	// One Way (1):
	//uint32_t priceL	:5 ;	// lower 5-bits of price stored in the same 32-bit word.
	//uint32_t priceH	:23;	// remaining bits of price stored in new 32-bit word.

	// Another way (2):
	uint32_t price;			// price stored in new 32-bit word.
} CarDetails_2_t;

int main(void){

	CarDetails_0_t CarDetails_0;
	CarDetails_0_t *pCarDetails_0 = &CarDetails_0;

	pCarDetails_0 -> speed	= 0x64;
	pCarDetails_0 -> weight	= 5000;
	pCarDetails_0 -> colour	= 0x7F;
	pCarDetails_0 -> price	= 100000000;

	CarDetails_1_t CarDetails_1;
	CarDetails_1_t *pCarDetails_1 = &CarDetails_1;

	pCarDetails_1 -> speed	= 0x64;
	pCarDetails_1 -> weight	= 5000;
	pCarDetails_1 -> colour	= 0x7F;
	pCarDetails_1 -> priceL	= 0x00;
	pCarDetails_1 -> priceH	= 0x2FAF08;

	CarDetails_2_t CarDetails_2;
	CarDetails_2_t *pCarDetails_2 = &CarDetails_2;

	pCarDetails_2 -> speed	= 0x64;
	pCarDetails_2 -> weight	= 5000;
	pCarDetails_2 -> colour	= 0x7F;
	pCarDetails_2 -> price	= 100000000;

	printf("\nSize of STRUCTURE 0: %lu-Byte(s).\n", sizeof(CarDetails_0));
	printf("\nSize of STRUCTURE 1: %lu-Byte(s).\n", sizeof(CarDetails_1));
	printf("\nSize of STRUCTURE 2: %lu-Byte(s).\n", sizeof(CarDetails_2));



	return 0;
}

