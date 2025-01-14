/*
 * testingOfBits.c
 *
 *  Created on: Oct 12, 2023
 *      Author: mariestahaab
 */

#include <stdio.h>
#include <stdint.h>

void checkEven(void){

	int32_t number = 0;
	printf("Enter a Number: ");
	scanf("%d", &number);

	if(number == 0){
		printf("Number is 0.\n");
	}
	else{
		if(number & 0x01){
			printf("Number is ODD.\n");
		}
		else{
			printf("Number is EVEN.\n");
		}
	}
}

void setBits47(void){

	int32_t number = 0;
	printf("Enter an Number: ");
	scanf("%d", &number);

	printf("\nEntered Number: 0x%x", number);
	printf("\nAfter setting bits 4 and 7: 0x%x", number | 0x90);
}

void clearBits456(void){

	int32_t number = 0;
	printf("Enter an Number: ");
	scanf("%d", &number);

	printf("\nEntered Number: 0x%x", number);
	printf("\nAfter clearing bits 4, 5 and 6: 0x%x", number & 0xFFFFFF8F); //or (number & ~(011100000)) => (number & (~0x70))
}

int main(void){

	//checkEven();
	//setBits47();
	clearBits456();
	return 0;
}
