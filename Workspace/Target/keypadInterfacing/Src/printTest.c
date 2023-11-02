/*
 * printTest.c
 *
 *  Created on: Oct 24, 2023
 *      Author: mariestahaab
 */

#include <stdio.h>
#include <stdint.h>

int main(void)
{
    /* Loop forever */
	printf("Hello World!\n\n");

	printf("Size of CHAR = %u\n", 			sizeof(char)		);
	printf("Size of SHORT = %u\n", 			sizeof(short)		);
	printf("Size of INT = %u\n", 			sizeof(int)			);
	printf("Size of LONG_INT = %u\n", 		sizeof(long)		);
	printf("Size of LONG_LONG_INT = %u\n", 	sizeof(long long)	);
	printf("Size of DOUBLE = %u\n", 		sizeof(double)		);

	for(;;);

	return 0;
}
