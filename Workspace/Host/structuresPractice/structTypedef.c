/*
 * structTypedef.c
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

int main(void){

	dataSet_t data;

	data.data1 = 0x13;
	data.data2 = 0xFFFFEEEE;
	data.data3 = 0x27;
	data.data4 = 0xABCD;

	uint32_t sizePadded = sizeof(dataSet_t);

	uint8_t *ptr = (uint8_t*)&data;
	printf("PADDED STRUCT:\n");
	printf("BYTE    MEMORY ADDRESS           CONTENT\n");
	printf("========================================\n");

	for(uint32_t i = 0; i < sizePadded; i++){

		printf("%d.    \t%p    \t\t %X\n", i, ptr, *ptr);
		ptr++;
	}
	printf("\nSize  of PADDED STRUCT = %d\n", sizePadded);

	return 0;
}
