/*
 * main.c
 *
 *  Created on: Oct 8, 2023
 *      Author: mariestahaab
 */
#include <stdio.h>

int main(void){
	int a, b, c, sum;
	float average;

	printf("Enter A: ");
	fflush(stdout);						// To flush the contents of the output buffer to the display. Not always required. Use if printf does not print anything on the console.
	scanf("%d", &a);

	printf("Enter B: ");
	fflush(stdout);
	scanf("%d", &b);

	printf("Enter C: ");
	fflush(stdout);
	scanf("%d", &c);

	sum = a+b+c;
	printf("\nSum = %d", sum);
	fflush(stdout);

	average = (float)sum / 3;
	printf("\nAverage = %.5f", average);
	fflush(stdout);

	getchar();

	return 0;
}
