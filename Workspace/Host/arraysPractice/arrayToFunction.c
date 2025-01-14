/*
 * arrayToFunction.c
 *
 *  Created on: Nov 2, 2023
 *      Author: mariestahaab
 */

#include <stdint.h>
#include <stdio.h>

void makeArray(uint32_t *data, uint32_t elements);
void printArray(uint32_t data[], uint32_t elements);

int main(void){

	uint32_t elements = 10;
	uint32_t data[elements];

	printf("Base address of Array = %p\n\n", data);

/*	for(uint32_t i = 0; i < elements; i++){
		*(data+i) = i;
	}*/

	makeArray(data, elements);

	*(data+3) = 12;

	/*for(uint32_t i = 0; i < elements; i++){
		printf("Address of Array[%d] = %p \t Contains: 0x%X\n", i, (data+i), *(data+i));
	}*/

	//printArray(data+2, elements-2); prints from second element; or
	//printArray(&data[2], elements-2);
	printArray(data, elements);

	printf("\nSize of Array = %lu\n", sizeof(data));

	return 0;
}

void makeArray(uint32_t *data, uint32_t elements){
	for(uint32_t i = 0; i < elements; i++){
		*(data+i) = i;
	}
}

void printArray(uint32_t data[], uint32_t elements){
	for(uint32_t i = 0; i < elements; i++){
		printf("Address of Array[%d] = %p \t Contains: 0x%X\n", i, (data+i), *(data+i));
	}
}
