/*
 * oneScanfInsteadOfThree.c
 *
 *  Created on: Oct 8, 2023
 *      Author: mariestahaab
 */

#include <stdio.h>

int main(void){
	float a, b, c, sum, average;

	printf("Enter three numbers: \n");
	fflush(stdout);
	scanf("%f %f %f", &a, &b, &c);

	sum = a+b+c;
	printf("\nSum = %f", sum);
	fflush(stdout);

	average = sum / 3;
	printf("\nAverage = %.5f", average);
	fflush(stdout);

	getchar();

	return 0;
}
