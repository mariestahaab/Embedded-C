/*
 * main.c
 *
 *  Created on: Nov 1, 2023
 *      Author: mariestahaab
 */

#include <stdint.h>
#include <stdio.h>

int main(void){

	uint32_t elements = 7;
	uint32_t items[elements];

	printf("Base address of Array = %p\n\n", items);

	for(uint32_t i = 0; i < elements; i++){
		*(items+i) = i;
		//items[i] = i;
	}

	*(items+2) = 12;

	for(uint32_t i = 0; i < elements; i++){
		printf("Address of Array[%d] = %p \t Contains: 0x%X\n", i, (items+i), *(items+i));
	}

	printf("\nSize of Array = %lu\n", sizeof(items));

	return 0;
}
