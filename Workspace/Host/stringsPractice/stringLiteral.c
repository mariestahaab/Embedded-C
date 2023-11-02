/*
 * stringLiteral.c
 *
 *  Created on: Nov 2, 2023
 *      Author: mariestahaab
 */

#include <stdint.h>
#include <stdio.h>

int main(void){

	char *msg1 = "Hello!";

	uint8_t name[30];

	printf("%s \n", msg1);		//stored in ROM.

	printf("Enter your name: ");
	scanf("%[^\n]s", name);

	printf("Hi, %s!", name);

	return 0;
}
