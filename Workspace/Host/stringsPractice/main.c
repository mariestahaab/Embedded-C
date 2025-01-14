/*
 * main.c
 *
 *  Created on: Nov 2, 2023
 *      Author: mariestahaab
 */

#include <string.h>
#include <stdint.h>
#include <stdio.h>

int main(void){

	uint8_t msg1[10] = "Hello!";
	uint8_t msg2[] = {'H', 'e', 'l', 'l', 'o', '!', '\0'};

	printf("%s \n", msg1);

	for(uint32_t i = 0; i < 7; i++){
		printf("%c \t", 		  msg1[i]);
	}

	printf("\n");
	for(uint32_t i = 0; i < 7; i++){
		printf("%d \t", (uint32_t)msg1[i]);
	}
	printf("\nSize: %lu \n", sizeof(msg1));

	printf("\n%s \n", msg2);
	printf("Size: %lu \n", sizeof(msg2));

	printf("strlen: %lu \n", strlen(msg2));

	return 0;
}
