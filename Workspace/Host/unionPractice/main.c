/*
 * main.c
 *
 *  Created on: Oct 18, 2023
 *      Author: mariestahaab
 */

#include <stdint.h>
#include <stdio.h>

union Addresses{
	uint16_t add_4Bytes;
	uint32_t add_8Bytes;
};

int main (void){

	union Addresses ADD4;
	union Addresses ADD8;

	ADD4.add_4Bytes = 0xABCD;
	ADD8.add_8Bytes = 0xFFFFCCCC;

	printf("ADD4 -> add_4Bytes = 0x%X\n", ADD4.add_4Bytes);
	printf("ADD8 -> add_8Bytes = 0x%X\n", ADD8.add_8Bytes);

	union Addresses addTest;

	addTest.add_4Bytes = 0xABCD;
	addTest.add_8Bytes = 0xFFFFCCCC;

	printf("\naddTest -> add_4Bytes = 0x%X\n", addTest.add_4Bytes);
	printf("addTest -> add_8Bytes = 0x%X\n", addTest.add_8Bytes);

	return 0;
}
