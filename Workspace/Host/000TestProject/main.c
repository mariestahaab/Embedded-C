/*
 * main.c
 *
 *  Created on: Aug 30, 2023
 *      Author: mariestahaab
 */

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

bool checkEven(void){
	int32_t input;

	printf("Enter a number: ");
	scanf("%d", &input);

	if(input % 2 == 0)
		printf("%d is an EVEN number.\n\n", input);
	else
		printf("%d is an ODD number.\n\n", input);

	return true;
}

void ifCheck(void){
	int32_t inputA, inputB;

	printf("Enter two numbers: ");
	scanf("%d %d", &inputA, &inputB);

	if(inputA < inputB){
		printf("%d is LESS than %d.\n", inputA, inputB);

	}else if(inputA == inputB){
		printf("%d is EQUAL to %d.\n", inputA, inputB);

	}else if(inputA > inputB){
		printf("%d is GREATER than %d.\n", inputA, inputB);
	}
}

int main(void){

	while(checkEven())
		;

	//ifCheck();

	getchar();

	return 0;
}
