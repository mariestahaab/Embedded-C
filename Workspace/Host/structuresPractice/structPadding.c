/*
 * structPadding.c
 *
 *  Created on: Oct 17, 2023
 *      Author: mariestahaab
 */

#include <stdint.h>
#include <stdio.h>

struct dataSet{			// total size should be 8 bytes, but sizeof() shows 12 byted because of padding.

	char	data1;		// 1 byte
	int		data2;		// 4 bytes
	char	data3;		// 1 byte
	short	data4;		// 2 bytes
};

struct dataPacked{		// total size should be 8 bytes, and sizeof() shows 8 bytes because of no padding.

	char	data1;		// 1 byte
	int		data2;		// 4 bytes
	char	data3;		// 1 byte
	short	data4;		// 2 bytes
}__attribute__((packed));

int main (void){

	struct dataSet data;

	data.data1 = 0x13;
	data.data2 = 0xFFFFEEEE;
	data.data3 = 0x27;
	data.data4 = 0xABCD;

	struct dataPacked dataP;

	dataP.data1 = 0x13;
	dataP.data2 = 0xFFFFEEEE;
	dataP.data3 = 0x27;
	dataP.data4 = 0xABCD;

	uint32_t sizePadded = sizeof(struct dataSet);
	uint32_t sizePacked = sizeof(struct dataPacked);

	uint8_t *ptr = (uint8_t*)&data;
	printf("PADDED STRUCT:\n");
	printf("BYTE    MEMORY ADDRESS                CONTENT\n");
	printf("=============================================\n");

	for(uint32_t i = 0; i < sizePadded; i++){

		printf("%d.      %p                   %X\n", i, ptr, *ptr);
		ptr++;
	}
	printf("\nSize  of PADDED STRUCT = %d\n", sizePadded);

	uint8_t *ptrP = (uint8_t*)&dataP;
	printf("\n\nPACKED STRUCT:\n");
	printf("BYTE    MEMORY ADDRESS                CONTENT\n");
	printf("=============================================\n");

	for(uint32_t i = 0; i < sizePacked; i++){

		printf("%d.      %p                   %X\n", i, ptrP, *ptrP);
		ptrP++;
	}
	printf("\nSize  of PACKED STRUCT = %d\n", sizePacked);

	return 0;
}

