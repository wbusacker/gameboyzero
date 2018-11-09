#include "memoryMap.h"

void initializeMemoryMap(void){

	/* Create memory map buffer */
	uint32_t i;
	for(i = 0; i < GAMEBOY_MEMORY_MAP_SIZE; i++){
		gameboyMemoryMap[i] = 0;
	}

	return;
}

void loadCartridge(FILE *fp){
	/* Determine Cartidge Size */

	uint32_t byteCount;
	fseek(fp, 0L, SEEK_END);
	byteCount = (uint32_t) ftell(fp);
	fseek(fp, 0L, SEEK_SET);

	/* Create Cartridge buffer */

	cartridgeMap = (uint8_t *) malloc(byteCount);

	/* Load Cartridge into map */

	fread(cartridgeMap, 1, byteCount, fp);

	/* Move Bank 0 into GBMM */

	uint32_t i;
	for(i = 0; i < 0x4000; i++){
		gameboyMemoryMap[i] = *(cartridgeMap + i);
	}

	/* Move Bank 1 into its hard sport */

	for(i = 0x4000; i < 0x8000; i++){
		gameboyMemoryMap[i] = *(cartridgeMap + i);
	}
}

void swapMemoryBank(uint8_t bankNum){
	uint32_t i;
	for(i = 0x4000; i < 0x8000; i++){
		gameboyMemoryMap[i] = *(cartridgeMap + i + (0x4000 * (bankNum -1)));
	}

	return;
}
