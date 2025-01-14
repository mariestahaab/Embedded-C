/*
 * structBitFields.c
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

#include <stdint.h>
#include <stdio.h>

// All bit fields will be referring to different bit fields of the same (single) uint32_t memory.
// size of struct is only 4-Bytes.
// no need to parse data manually if order of the elements is kept the same as the order of the data being received, in next example.

typedef struct{
	uint32_t	crc		 :2	;		// use 2-bits	for CRC
	uint32_t	status	 :1	;		// use 1-bit	for STATUS
	uint32_t	payload	 :12;		// use 12-bits	for PAYLOAD
	uint32_t	bat		 :3	;		// use 3-bits	for BAT
	uint32_t	sensor	 :3	;		// use 3-bits	for SENSOR
	uint32_t	longAddr :8	;		// use 8-bits	for LONG_ADDR
	uint32_t	shortAddr:2	;		// use 2-bits	for SHORT_ADDR
	uint32_t	addrMode :1	;		// use 1-bit	for ADDR_MODE
} Packet_t;

void dispPacketValues(Packet_t *pPkt);

int main(void){

	uint32_t testPacketValue = 0x03FF1234;

	Packet_t Packet;
	Packet_t *pPacket = &Packet;

	pPacket -> crc 			= (uint32_t) ((testPacketValue >> 0 ) & (0x3	));
	pPacket -> status 		= (uint32_t) ((testPacketValue >> 2 ) & (0x1	));
	pPacket -> payload 		= (uint32_t) ((testPacketValue >> 3 ) & (0xFFF	));
	pPacket -> bat 			= (uint32_t) ((testPacketValue >> 15) & (0x7	));
	pPacket -> sensor 		= (uint32_t) ((testPacketValue >> 18) & (0x7	));
	pPacket -> longAddr 	= (uint32_t) ((testPacketValue >> 21) & (0xFF	));
	pPacket -> shortAddr 	= (uint32_t) ((testPacketValue >> 29) & (0x3	));
	pPacket -> addrMode 	= (uint32_t) ((testPacketValue >> 31) & (0x1	));

	dispPacketValues(pPacket);

	printf("\nSize of STRUCTURE: %lu-Byte(s).\n", sizeof(Packet));

	return 0;
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
