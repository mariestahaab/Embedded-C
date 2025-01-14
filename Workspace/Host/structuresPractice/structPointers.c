/*
 * structPointers.c
 *
 *  Created on: Oct 18, 2023
 *      Author: mariestahaab
 */

#include <stdint.h>
#include <stdio.h>

typedef struct{			// total size should be 8 bytes, but sizeof() shows 12 byted because of padding.

	char	data1;		// 1 byte
	int		data2;		// 4 bytes
	char	data3;		// 1 byte
	short	data4;		// 2 bytes
} dataSet_t;

void dispMemberFunctions(dataSet_t *ptrData);

int main(void){

	dataSet_t data;

	dataSet_t *pData;
	pData = &data;

	pData -> data1 = 0x13;
	pData -> data2 = 0xFFFFEEEE;
	pData -> data3 = 0x27;
	pData -> data4 = 0xABCD;

	dispMemberFunctions(&data);

	return 0;
}

void dispMemberFunctions(dataSet_t *ptrData){
	printf("data1: %X\n", ptrData -> data1);
}
