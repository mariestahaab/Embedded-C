/*
 * main.c
 *
 *  Created on: Oct 10, 2023
 *      Author: mariestahaab
 */

#include <stdio.h>

int main(){

/*	char temp = 17;

	long long int address = 0x00007FFF8E3C3824; // invalid pointer definition.

	char* address1 = (char*)0x00007FFF8E3C3824;

	printf ("%p\n", address1);

	printf ("%lu\n", sizeof(char*));
	printf ("%lu\n", sizeof(int*));
	printf ("%lu\n", sizeof(long*));
*/

	// Pointer exercise lec 80:
	char value = 100;
	printf ("Value = %d\n", value);

	char* address = &value;
	printf ("Address of %d in memory (ptr) = %p\n", value, address);

	char dataFromPtr = *address;
	printf ("Read Operation: %d\n", dataFromPtr);

	*address = 65;
	printf ("Value after write operation = %d\n", value);



	return 0;
}

