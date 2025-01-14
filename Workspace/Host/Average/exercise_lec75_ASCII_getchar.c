/*
 * exercise_lec75_ASCII_getchar.c
 *
 *  Created on: Oct 8, 2023
 *      Author: mariestahaab
 */

#include <stdio.h>

int main(void){
	int numberOfInputs = 6;
	char input;

	while(numberOfInputs > 0){

		printf("%d. Enter a character: ", 6 - numberOfInputs + 1);
		input = getchar();

		while(getchar() != '\n');

		printf("ASCII Value: %u\n\n", input);

		numberOfInputs--;
	}

	return 0;
}
