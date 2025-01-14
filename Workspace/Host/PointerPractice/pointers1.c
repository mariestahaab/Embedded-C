/*
 * pointers1.c
 *
 *  Created on: Oct 10, 2023
 *      Author: mariestahaab
 */

long long int gData = 0x00007FFF8E3C3824;

#include <stdio.h>

int main(void){

	printf ("DATA = %llx\n\n", gData);

	char *pAddress1 = (char*) &gData;
	printf ("Value at address (%p) using charPtr  = %x\n", pAddress1, *pAddress1);

	short *pAddress2 = (short*) &gData;
	printf ("Value at address (%p) using shortPtr = %x\n", pAddress2, *pAddress2);

	int *pAddress3 = (int*) &gData;
	printf ("Value at address (%p) using intPtr   = %x\n", pAddress3, *pAddress3);

	long long int *pAddress4 = (long long int*) &gData;
	printf ("Value at address (%p) using llIntPtr = %llx\n", pAddress4, *pAddress4);

	return 0;
}
