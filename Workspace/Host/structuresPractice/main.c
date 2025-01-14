/*
 * main.c
 *
 *  Created on: Oct 17, 2023
 *      Author: mariestahaab
 */

#include <stdint.h>
#include <stdio.h>

struct carModel{					// total size should be 14 bytes

	unsigned int carNumber;			// 4 bytes
	uint32_t	 carPrice;			// 4 bytes
	uint16_t	 carMaxSpeed;		// 2 bytes
	float		 carWeight;			// 4 bytes
};

int main (void){

	// One Method (C89):
	struct carModel carBMW = {2021, 15000, 220, 1330};			// 1 to 1 mapping, ORDER IS IMPORTANT.
	//struct carModel carFord = {4031, 35000, 160, 1900.96};

	// Another Method (C99):
	struct carModel carHonda = {.carNumber = 2021, .carWeight = 90.90, .carMaxSpeed = 220, .carPrice = 15000};

	struct carModel carFord = {.carNumber = 4031,/* .carWeight = 1900.96, .carMaxSpeed = 160, .carPrice = 35000*/};

	//To access element:
	printf("Details of BMW:\n");
	printf("carNumber:   %d\n", carBMW.carNumber);
	printf("carPrice:    %d\n", carBMW.carPrice);
	printf("carMaxSpeed: %d\n", carBMW.carMaxSpeed);
	printf("carWeight:   %.2f\n", carBMW.carWeight);

	printf("\nDetails of Honda:\n");
	printf("carNumber:   %d\n", carHonda.carNumber);
	printf("carPrice:    %d\n", carHonda.carPrice);
	printf("carMaxSpeed: %d\n", carHonda.carMaxSpeed);
	printf("carWeight:   %.2f\n", carHonda.carWeight);

	// To change the values:
	carHonda.carNumber		= 4957;
	carHonda.carPrice		= 33000;
	carHonda.carMaxSpeed	= 310;
	carHonda.carWeight 		= 765.567;

	printf("\nUPDATED Details of Honda:\n");
	printf("carNumber:   %d\n", carHonda.carNumber);
	printf("carPrice:    %d\n", carHonda.carPrice);
	printf("carMaxSpeed: %d\n", carHonda.carMaxSpeed);
	printf("carWeight:   %.2f\n", carHonda.carWeight);

	// Size Of Struct:
	printf("\nSize of struct carModel: %lu\n", sizeof(struct carModel)); 	// Prints 16 instead of 14, 2 byte structure padding.
	printf("\nSize of struct carBMW: %lu\n", sizeof(carBMW));

	printf("\nSize of struct carFord: %lu\n", sizeof(carFord));

	return 0;
}
