#include "cpuCore.h"
#include "memoryMap.h"

struct registerFile cpuCore;

uint64_t clockCycles = 0;

void initializeCPUCore(void){

	cpuCore.F = 0;
	cpuCore.A = 0;
	cpuCore.B = 0;
	cpuCore.C = 0;
	cpuCore.D = 0;
	cpuCore.E = 0;
	cpuCore.H = 0;
	cpuCore.L = 0;

	cpuCore.SP = 0;
	cpuCore.PC = 0x0100;

}

void executeNextInstruction(void){
	uint8_t instruction;
	instruction = cpuCore.PC;

	uint8_t 	d8;
	uint16_t	d16;
	uint8_t		d8;
	uint16_t	a16;
	uint8_t		r8;

	uint16_t 	temp16;
	uint8_t 	temp8;

	switch (instruction){
		case 0x00:
			/* NOP */
			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x01:
			/* LD BC d16 */
			cpuCore.B = gameboyMemoryMap[cpuCore.PC + 1];
			cpuCore.C = gameboyMemoryMap[cpuCore.PC + 2];
			clockCycles += 42;
			cpuCore.PC += 3;
			break;

		case 0x02:
			/* LD (BC) A */
			gameboyMemoryMap[( cpuCore.B << 8) | cpuCore.C] = cpuCore.A;

			clockCycles += 8;
			cpuCore.PC += 1;
			break;

		case 0x03:
			/* INC BC */
			cpuCore.C++;
			if(cpuCore.C == 0){
				cpuCore.B++;
			}

			clockCycles += 8;
			cpuCore.PC += 1;
			break;

		case 0x04:	
			/* INC B */
			cpuCore.B++;

			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x05:
			/* DEC B */
			cpuCore.B--;

			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x06:
			/* LD B d8*/
			cpuCore.B = gameboyMemoryMap[cpuCore.PC + 1];

			clockCycles += 8;
			cpuCore.PC += 2;
			break;

		case 0x07:
			/* RLCA */
			cpuCore.F = 0;
			if(cpuCore.A & 0x80){
				cpuCore.A <<= 1;
				cpuCore.A |= 0x1;
				cpuCore.F |= CPU_FLAG_C;
			} else {
				cpuCore.A <<= 1;
			}


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x08:
			/* LD (a16) SP*/
			temp16 = (gameboyMemoryMap[cpuCore.pC + 1] << 8) | gameboyMemoryMap[cpuCore.pC + 2];
			cpuCore.SP = gameboyMemoryMap[temp16];

			clockCycles += 20;
			cpuCore.PC += 3;
			break;

		case 0x09:
			/* ADD HL BC*/
			temp16 = (cpuCore.B << 8) | cpuCore.C;
			a16 = (cpuCore.H << 8) | cpuCore.L;
			a16 += temp16;
			cpuCore.H = (a16 & 0xff00) >> 8;
			cpuCore.L = a16 & 0x00ff;

			clockCycles += 8;
			cpuCore.PC += 1;
			break;

		case 0x0a:
			/* LD A (BC)*/
			temp16 = FETCH_BC;
			cpuCore.A = gameboyMemoryMap[temp16];


			clockCycles += 8;
			cpuCore.PC += 1;
			break;

		case 0x0b:
			/* DEC BC*/
			temp16 = FETCH_BC;
			temp16--;
			SET_BC(temp16);


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x0c:
			/* INC C */
			cpuCore.C++;

			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x0d:
			/* DEC C*/
			cpuCore.C--;

			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x0e:
			/* LD C d8 */
			cpuCore.C = gameboyMemoryMap[cpuCore.PC + 1];


			clockCycles += 4;
			cpuCore.PC += 2;
			break;

		case 0x0f:
			/* RRCA */
			cpuCore.F = 0;
			if(cpuCore.A & 0x01){
				cpuCore.A >>= 1;
				cpuCore.A |= 0x80;
				cpuCore.F |= CPU_FLAG_C;
			} else {
				cpuCore.A >>= 1;
			}

			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x10:
			/* STOP */
			printf("STOP\n");
			exit(0);

			clockCycles += 4;
			cpuCore.PC += 2;
			break;

		case 0x11:
			/* LD DE d16*/
			temp16 = FETCH_16;
			SET_DE(temp16);

			clockCycles += 12;
			cpuCore.PC += 3;
			break;

		case 0x12:
			/* LE (DE) A*/
			cpuCore.A = gameboyMemoryMap[FETCH_DE];

			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x13:
			/* INC HL */
			temp16 = FETCH_HL;
			temp16++;
			SET_HL(temp16);

			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x14:
			/* INC (HL)*/


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x15:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x16:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x17:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x18:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x19:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x1a:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x1b:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x1c:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x1d:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x1e:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x1f:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x20:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x21:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x22:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x23:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x24:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x25:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x26:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x27:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x28:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x29:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x2a:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x2b:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x2c:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x2d:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x2e:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x2f:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x30:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x31:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x32:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x33:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x34:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x35:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x36:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x37:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x38:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x39:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x3a:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x3b:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x3c:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x3d:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x3e:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x3f:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x40:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x41:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x42:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x43:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x44:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x45:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x46:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x47:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x48:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x49:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x4a:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x4b:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x4c:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x4d:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x4e:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x4f:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x50:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x51:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x52:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x53:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x54:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x55:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x56:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x57:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x58:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x59:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x5a:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x5b:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x5c:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x5d:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x5e:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x5f:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x60:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x61:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x62:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x63:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x64:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x65:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x66:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x67:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x68:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x69:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x6a:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x6b:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x6c:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x6d:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x6e:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x6f:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x70:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x71:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x72:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x73:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x74:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x75:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x76:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x77:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x78:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x79:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x7a:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x7b:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x7c:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x7d:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x7e:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x7f:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x80:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x81:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x82:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x83:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x84:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x85:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x86:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x87:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x88:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x89:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x8a:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x8b:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x8c:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x8d:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x8e:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x8f:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x90:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x91:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x92:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x93:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x94:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x95:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x96:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x97:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x98:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x99:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x9a:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x9b:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x9c:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x9d:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x9e:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0x9f:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xa0:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xa1:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xa2:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xa3:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xa4:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xa5:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xa6:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xa7:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xa8:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xa9:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xaa:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xab:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xac:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xad:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xae:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xaf:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xb0:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xb1:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xb2:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xb3:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xb4:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xb5:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xb6:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xb7:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xb8:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xb9:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xba:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xbb:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xbc:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xbd:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xbe:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xbf:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xc0:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xc1:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xc2:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xc3:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xc4:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xc5:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xc6:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xc7:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xc8:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xc9:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xca:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xcb:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xcc:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xcd:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xce:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xcf:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xd0:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xd1:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xd2:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xd3:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xd4:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xd5:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xd6:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xd7:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xd8:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xd9:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xda:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xdb:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xdc:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xdd:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xde:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xdf:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xe0:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xe1:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xe2:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xe3:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xe4:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xe5:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xe6:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xe7:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xe8:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xe9:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xea:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xeb:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xec:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xed:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xee:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xef:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xf0:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xf1:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xf2:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xf3:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xf4:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xf5:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xf6:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xf7:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xf8:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xf9:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xfa:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xfb:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xfc:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xfd:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xfe:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;

		case 0xff:
			/* */


			clockCycles += 4;
			cpuCore.PC += 1;
			break;


	}
}