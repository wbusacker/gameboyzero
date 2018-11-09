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

void initializeCPUCore(void);

void executeNextInstruction(void);

void executePrefixCB(void);

#endif