/*
 * main.c
 *
 *  Created on: Oct 11, 2023
 *      Author: mariestahaab
 */

#include <stdio.h>
#include <stdint.h>

int main(void){

	int32_t inputA, inputB;

	printf("Enter A and B:\n");
	scanf("%d %d", &inputA, &inputB);

	printf("\nBitwise AND	(&) : %d", inputA & inputB);
	printf("\nBitwise OR	(|) : %d", inputA | inputB);
	printf("\nBitwise EXOR	(^) : %d", inputA ^ inputB);
	printf("\nBitwise NOT	(~) : %d", ~inputA		  );

	return 0;
}
