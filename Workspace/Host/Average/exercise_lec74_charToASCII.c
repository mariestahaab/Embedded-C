/*
 * exercise_lec74_charToASCII.c
 *
 *  Created on: Oct 8, 2023
 *      Author: mariestahaab
 */

#include <stdio.h>

int main(void){
	char a, b, c, d, e, f;

	printf("Enter six characters: \n");
	fflush(stdout);
	scanf("%c %c %c %c %c %c", &a, &b, &c, &d, &e, &f);

	printf("\nASCII Values are: \n%u, %u, %u, %u, %u, %u", a, b, c, d, e, f);	// or use %d but %u is preferred.
	fflush(stdout);

	getchar();

	return 0;
}