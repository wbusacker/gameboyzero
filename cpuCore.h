#ifndef CPU_CORE_H
#define CPU_CORE_H

struct registerFile{
	uint8_t F;
	uint8_t A;
	uint8_t B;
	uint8_t C;
	uint8_t D;
	uint8_t E;
	uint8_t H;
	uint8_t L;

	uint16_t SP;
	uint16_t PC;
}

extern uint64_t clockCycles;

extern struct registerFile cpuCore;

#define CPU_FLAG_Z 	(1 << 7)
#define CPU_FLAG_N 	(1 << 6)
#define CPU_FLAG_H	(1 << 5)
#define CPU_FLAG_C	(1 << 4)

#define FETCH_BC ((uint16_t)cpuCore.B << 8) | (uint16_t)cpuCore.C
#define FETCH_DE ((uint16_t)cpuCore.D << 8) | (uint16_t)cpuCore.E
#define FETCH_HL ((uint16_t)cpuCore.H << 8) | (uint16_t)cpuCore.L

#define SET_BC(x) cpuCore.B = (uint8_t)((x & 0xff00) >> 8); cpuCore.C = (uint8_t)(x & 0xff) 
#define SET_DE(x) cpuCore.D = (uint8_t)((x & 0xff00) >> 8); cpuCore.E = (uint8_t)(x & 0xff) 
#define SET_HL(x) cpuCore.H = (uint8_t)((x & 0xff00) >> 8); cpuCore.L = (uint8_t)(x & 0xff) 

#define FETCH_16 	(gameboyMemoryMap[cpuCore.pC + 1] << 8) | gameboyMemoryMap[cpuCore.pC + 2]
#define FETCH_8		gameboyMemoryMap[cpuCore.pC + 1]

void initializeCPUCore(void);

void executeNextInstruction(void);

void executePrefixCB(void);

#endif