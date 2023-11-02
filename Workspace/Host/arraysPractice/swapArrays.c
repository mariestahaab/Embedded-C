/*
 * swapArrays.c
 *
 *  Created on: Nov 2, 2023
 *      Author: mariestahaab
 */

#include <stdint.h>
#include <stdio.h>

void makeArray(uint32_t *data, uint32_t elements, uint32_t start);
void getArray(uint32_t *data, uint32_t elements);
void printArray(uint32_t data[], uint32_t elements);
void swapArrays(uint32_t *data1, uint32_t *data2, uint32_t elements);

int main(void){

	uint32_t elements = 10;

	uint32_t arr1[elements];
	printf("Enter %d elements of Array 1:\n", elements);
	getArray(arr1, elements);

	uint32_t arr2[elements];
	printf("Enter %d elements of Array 2:\n", elements);
	getArray(arr2, elements);

	printf("Base address of Array 1 = %p\n", arr1);
	//makeArray(arr1, elements, 0);
	printArray(arr1, elements);


	printf("\nBase address of Array 2 = %p\n", arr2);
	//makeArray(arr2, elements, 18);
	printArray(arr2, elements);

	swapArrays(arr1, arr2, elements);

	printf("\nArray 1:\n");
	printArray(arr1, elements);

	printf("\nArray 2:\n");
	printArray(arr2, elements);

	return 0;
}

void makeArray(uint32_t *data, uint32_t elements, uint32_t start){
	for(uint32_t i = 0; i < elements; i++){
		*(data+i) = start;
		start++;
	}
}

void getArray(uint32_t *data, uint32_t elements){
	for(uint32_t i = 0; i < elements; i++){
		scanf("%d", (data+i));
	}
}

void printArray(uint32_t data[], uint32_t elements){
	printf("\n");

	for(uint32_t i = 0; i < elements; i++){
		printf("Address of Array[%d] = %p \t Contains: %d\n", i, (data+i), *(data+i));
	}
}

void swapArrays(uint32_t *data1, uint32_t *data2, uint32_t elements){
	for(uint32_t i = 0; i < elements; i++){
		uint32_t temp;

		temp = data1[i];
		data1[i] = data2[i];
		data2[i] = temp;
	}
}
