/*
 * structExercise_162.c
 *
 *  Created on: Oct 18, 2023
 *      Author: mariestahaab
 */

#include <stdint.h>
#include <stdio.h>

union Packet{

	uint32_t testPacketValue;

	struct{
		uint32_t	crc		 :2	;		// use 2-bits	for CRC
		uint32_t	status	 :1	;		// use 1-bit	for STATUS
		uint32_t	payload	 :12;		// use 12-bits	for PAYLOAD
		uint32_t	bat		 :3	;		// use 3-bits	for BAT
		uint32_t	sensor	 :3	;		// use 3-bits	for SENSOR
		uint32_t	longAddr :8	;		// use 8-bits	for LONG_ADDR
		uint32_t	shortAddr:2	;		// use 2-bits	for SHORT_ADDR
		uint32_t	addrMode :1	;		// use 1-bit	for ADDR_MODE
	}packetFields;
};

void dispPacketValues(union Packet *pPkt);

int main(void){

	union Packet Packet0;

	Packet0. testPacketValue = 0x03FF1234;

	printf("Values are:\n");
	printf("CRC\t\t: 0x%X\n"		,Packet0. packetFields. crc		 );
	printf("STATUS\t\t: 0x%X\n"		,Packet0. packetFields. status	 );
	printf("PAYLOAD\t\t: 0x%X\n" 	,Packet0. packetFields. payload	 );
	printf("BAT\t\t: 0x%X\n" 		,Packet0. packetFields. bat		 );
	printf("SENSOR\t\t: 0x%X\n" 	,Packet0. packetFields. sensor	 );
	printf("LONG_ADDR\t: 0x%X\n"	,Packet0. packetFields. longAddr );
	printf("SHORT_ADDR\t: 0x%X\n" 	,Packet0. packetFields. shortAddr);
	printf("ADDR_MODE\t: 0x%X\n" 	,Packet0. packetFields. addrMode );

//	dispPacketValues(&Packet0);

	return 0;
}

void dispPacketValues(union Packet *pPkt){
	printf("\nValues are:\n");
	printf("CRC\t\t: 0x%X\n"		,pPkt -> packetFields. crc		);
	printf("STATUS\t\t: 0x%X\n"		,pPkt -> packetFields. status	);
	printf("PAYLOAD\t\t: 0x%X\n" 	,pPkt -> packetFields. payload	);
	printf("BAT\t\t: 0x%X\n" 		,pPkt -> packetFields. bat		);
	printf("SENSOR\t\t: 0x%X\n" 	,pPkt -> packetFields. sensor	);
	printf("LONG_ADDR\t: 0x%X\n"	,pPkt -> packetFields. longAddr	);
	printf("SHORT_ADDR\t: 0x%X\n" 	,pPkt -> packetFields. shortAddr);
	printf("ADDR_MODE\t: 0x%X\n" 	,pPkt -> packetFields. addrMode	);
}
