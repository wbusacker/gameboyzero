#ifndef MEMORY_MAP_H
#define MEMORY_MAP_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/*
	0000 - 00FF Restart and Interrupt Vectors
	0100 - 014F Cartridge Header Area
	0150 - 3FFF Cartridge ROM Bank 0
	4000 - 7FFF Cartridge ROM Switchable Bank
	8000 - 97FF Character RAM
	9800 - 9BFF BG Map Data 1
	9C00 - 9FFF BG Map Data 2
	A000 - BFFF Cartidge RAM
	C000 - CFFF Internal RAM Bank 0
	D000 - DFFF Internal RAM Bank 1 - 7
	E000 - FDFF Echo RAM
	FE00 - FE9F Object Attribute Memory
	FEA0 - FE9F Unusable
	FF00 - FF7F Hardware IO Registers
	FF80 - FFFE Zero Page
	FFFF		IE Flag
*/

#define GAMEBOY_MEMORY_MAP_SIZE 0xFFFF

uint8_t gameboyMemoryMap[GAMEBOY_MEMORY_MAP_SIZE];

uint8_t *cartridgeMap;

void initializeMemoryMap(void);

void loadCartridge(FILE *fp);

void swapMemoryBank(uint8_t bankNum);



#endif