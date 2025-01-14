/*
 * structExercise_162.c
 *
 *  Created on: Oct 18, 2023
 *      Author: mariestahaab
 */

/* Question: Decode the given packet and print the values of different fields.
 *
 * 32-bit Packet Contents:
 *
 * 			|  ADDR_MODE  |  SHORT_ADDR  |  LONG_ADDR  |  SENSOR  |  BAT  |  PAYLOAD  |  STATUS  |  CRC  |
 * bits:   		   1			  2			    8			 3		  3		   12		   1		 2
 *
 */

// size of data = 32-bits (4-Bytes) and size of struct = 10-Bytes.
// 6-Bytes of extra memory consumed.
// use bit fields to save memory.

#include <stdint.h>
#include <stdio.h>

typedef struct{
	uint8_t		crc			;
	uint8_t		status		;
	uint16_t	payload		;
	uint8_t		bat			;
	uint8_t		sensor		;
	uint8_t		longAddr	;
	uint8_t		shortAddr	;
	uint8_t		addrMode	;
} Packet_t;

void dispPacketValues(Packet_t *pPkt);
void getPacketValues(uint32_t *pVal);

int main(void){

	uint32_t testPacketValue;// = 0x03FF1234;
	getPacketValues(&testPacketValue);

	Packet_t Packet;
	Packet_t *pPacket = &Packet;

	pPacket -> crc 			= (uint8_t ) ((testPacketValue >> 0 ) & (0x3	));
	pPacket -> status 		= (uint8_t ) ((testPacketValue >> 2 ) & (0x1	));
	pPacket -> payload 		= (uint16_t) ((testPacketValue >> 3 ) & (0xFFF	));
	pPacket -> bat 			= (uint8_t ) ((testPacketValue >> 15) & (0x7	));
	pPacket -> sensor 		= (uint8_t ) ((testPacketValue >> 18) & (0x7	));
	pPacket -> longAddr 	= (uint8_t ) ((testPacketValue >> 21) & (0xFF	));
	pPacket -> shortAddr 	= (uint8_t ) ((testPacketValue >> 29) & (0x3	));
	pPacket -> addrMode 	= (uint8_t ) ((testPacketValue >> 31) & (0x1	));

	dispPacketValues(pPacket);

	printf("\nSize of STRUCTURE: %lu-Byte(s).\n", sizeof(Packet));

	return 0;
}

void getPacketValues(uint32_t *pVal){
	printf("Enter a 32-bit HEX Value: ");
	scanf("%x", pVal);
}

void dispPacketValues(Packet_t *pPkt){
	printf("\nValues are:\n");
	printf("CRC\t\t: 0x%X\n"		,pPkt -> crc		);
	printf("STATUS\t\t: 0x%X\n"		,pPkt -> status		);
	printf("PAYLOAD\t\t: 0x%X\n" 	,pPkt -> payload	);
	printf("BAT\t\t: 0x%X\n" 		,pPkt -> bat		);
	printf("SENSOR\t\t: 0x%X\n" 	,pPkt -> sensor		);
	printf("LONG_ADDR\t: 0x%X\n"	,pPkt -> longAddr	);
	printf("SHORT_ADDR\t: 0x%X\n" 	,pPkt -> shortAddr	);
	printf("ADDR_MODE\t: 0x%X\n" 	,pPkt -> addrMode	);
}
