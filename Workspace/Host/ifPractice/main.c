/*
 * main.c
 *
 *  Created on: Oct 11, 2023
 *      Author: mariestahaab
 */

#include <stdio.h>
#include <stdint.h>

void ifCheck(void){
	float	floatA, floatB;
	int32_t inputA, inputB;

	printf("Enter two numbers (INT):\n");

	if(scanf("%f %f", &floatA, &floatB)){

		inputA = floatA;
		inputB = floatB;

		if(inputA < inputB){
			printf("%d is LESS than %d.\n", inputA, inputB);

		}else if(inputA == inputB){
			printf("%d is EQUAL to %d.\n", inputA, inputB);

		}else if(inputA > inputB){
			printf("%d is GREATER than %d.\n", inputA, inputB);
		}

	}else{
		printf("Invalid Input \n");
	}


}

int main(void){

	ifCheck();

	return 0;
}
