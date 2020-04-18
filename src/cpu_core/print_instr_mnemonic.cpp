#include <cpu_core.h>

namespace CPU {

static char mnemonics[256][128] = {
  "NOP                    \0", "LD BC,nn               \0", "LD (BC),A              \0", "INC BC                 \0",
  "INC B                  \0", "DEC B                  \0", "LD B,n                 \0", "RLCA                   \0",
  "LD (nn),SP             \0", "ADD HL,BC              \0", "LD A,(BC)              \0", "DEC BC                 \0",
  "INC C                  \0", "DEC C                  \0", "LD C,n                 \0", "RRCA                   \0",
  "STOP                   \0", "LD DE,nn               \0", "LD (DE),A              \0", "INC DE                 \0",
  "INC D                  \0", "DEC D                  \0", "LD D,n                 \0", "RLA                    \0",
  "JR e                   \0", "ADD HL,DE              \0", "LD A,(DE)              \0", "DEC DE                 \0",
  "INC E                  \0", "DEC E                  \0", "LD E,n                 \0", "RRA                    \0",
  "JR NZ,e                \0", "LD HL,nn               \0", "LD (HL+),A             \0", "INC HL                 \0",
  "INC H                  \0", "DEC H                  \0", "LD H,n                 \0", "DAA                    \0",
  "JR Z,e                 \0", "ADD HL,HL              \0", "LD A,(HL+)             \0", "DEC HL                 \0",
  "INC L                  \0", "DEC L                  \0", "LD L,n                 \0", "CPL                    \0",
  "JR NC,e                \0", "LD SP,nn               \0", "LD (HL-),A             \0", "INC SP                 \0",
  "INC (HL)               \0", "DEC (HL)               \0", "LD (HL),n              \0", "SCF                    \0",
  "JR C,e                 \0", "ADD HL,SP              \0", "LD A,(HL-)             \0", "DEC SP                 \0",
  "INC A                  \0", "DEC A                  \0", "LD A,n                 \0", "CCF                    \0",
  "LD B,B                 \0", "LD B,C                 \0", "LD B,D                 \0", "LD B,E                 \0",
  "LD B,H                 \0", "LD B,L                 \0", "LD B,(HL)              \0", "LD B,A                 \0",
  "LD C,B                 \0", "LD C,C                 \0", "LD C,D                 \0", "LD C,E                 \0",
  "LD C,H                 \0", "LD C,L                 \0", "LD C,(HL)              \0", "LD C,A                 \0",
  "LD D,B                 \0", "LD D,C                 \0", "LD D,D                 \0", "LD D,E                 \0",
  "LD D,H                 \0", "LD D,L                 \0", "LD D,(HL)              \0", "LD D,A                 \0",
  "LD E,B                 \0", "LD E,C                 \0", "LD E,D                 \0", "LD E,E                 \0",
  "LD E,H                 \0", "LD E,L                 \0", "LD E,(HL)              \0", "LD E,A                 \0",
  "LD H,B                 \0", "LD H,C                 \0", "LD H,D                 \0", "LD H,E                 \0",
  "LD H,H                 \0", "LD H,L                 \0", "LD H,(HL)              \0", "LD H,A                 \0",
  "LD L,B                 \0", "LD L,C                 \0", "LD L,D                 \0", "LD L,E                 \0",
  "LD L,H                 \0", "LD L,L                 \0", "LD L,(HL)              \0", "LD L,A                 \0",
  "LD (HL),B              \0", "LD (HL),C              \0", "LD (HL),D              \0", "LD (HL),E              \0",
  "LD (HL),H              \0", "LD (HL),L              \0", "HALT                   \0", "LD (HL),A              \0",
  "LD A,B                 \0", "LD A,C                 \0", "LD A,D                 \0", "LD A,E                 \0",
  "LD A,H                 \0", "LD A,L                 \0", "LD A,(HL)              \0", "LD A,A                 \0",
  "ADD B                  \0", "ADD C                  \0", "ADD D                  \0", "ADD E                  \0",
  "ADD H                  \0", "ADD L                  \0", "ADD (HL)               \0", "ADD A                  \0",
  "ADC B                  \0", "ADC C                  \0", "ADC D                  \0", "ADC E                  \0",
  "ADC H                  \0", "ADC L                  \0", "ADC (HL)               \0", "ADC A                  \0",
  "SUB B                  \0", "SUB C                  \0", "SUB D                  \0", "SUB E                  \0",
  "SUB H                  \0", "SUB L                  \0", "SUB (HL)               \0", "SUB A                  \0",
  "SBC B                  \0", "SBC C                  \0", "SBC D                  \0", "SBC E                  \0",
  "SBC H                  \0", "SBC L                  \0", "SBC (HL)               \0", "SBC A                  \0",
  "AND B                  \0", "AND C                  \0", "AND D                  \0", "AND E                  \0",
  "AND H                  \0", "AND L                  \0", "AND (HL)               \0", "AND A                  \0",
  "XOR B                  \0", "XOR C                  \0", "XOR D                  \0", "XOR E                  \0",
  "XOR H                  \0", "XOR L                  \0", "XOR (HL)               \0", "XOR A                  \0",
  "OR B                   \0", "OR C                   \0", "OR D                   \0", "OR E                   \0",
  "OR H                   \0", "OR L                   \0", "OR (HL)                \0", "OR A                   \0",
  "CP B                   \0", "CP C                   \0", "CP D                   \0", "CP E                   \0",
  "CP H                   \0", "CP L                   \0", "CP (HL)                \0", "CP A                   \0",
  "RET NZ                 \0", "POP BC                 \0", "JP NZ,nn               \0", "JP nn                  \0",
  "CALL NZ,nn             \0", "PUSH BC                \0", "ADD n                  \0", "RST 0x00               \0",
  "RET Z                  \0", "RET JP                 \0", "JP Z,nn                \0", "CB op                  \0",
  "CALL Z,nn              \0", "CALL nn                \0", "ADC n                  \0", "RST 0x08               \0",
  "RET NC                 \0", "POP DE                 \0", "JP NC,nn               \0", "UNIMPLEMENTED          \0",
  "CALL NC,nn             \0", "PUSH DE                \0", "SUB n                  \0", "RST 0x10               \0",
  "RET C                  \0", "RETI                   \0", "JP C,nn                \0", "UNIMPLEMENTED          \0",
  "CALL C,nn              \0", "UNIMPLEMENTED          \0", "SBC n                  \0", "RST 0x18               \0",
  "LDH (n),A              \0", "POP HL                 \0", "LDH (C),A              \0", "UNIMPLEMENTED          \0",
  "UNIMPLEMENTED          \0", "PUSH HL                \0", "AND n                  \0", "RST 0x20               \0",
  "ADD SP,e               \0", "JP HL                  \0", "LD (nn),A              \0", "UNIMPLEMENTED          \0",
  "UNIMPLEMENTED          \0", "UNIMPLEMENTED          \0", "XOR n                  \0", "RST 0x28               \0",
  "LDH A,(n)              \0", "POP AF                 \0", "LDH A,(C)              \0", "DI                     \0",
  "UNIMPLEMENTED          \0", "PUSH AF                \0", "OR n                   \0", "RST 0x30               \0",
  "LD HL,SP+e             \0", "LD SP,HL               \0", "LD A,(nn)              \0", "EI                     \0",
  "UNIMPLEMENTED          \0", "UNIMPLEMENTED          \0", "CP n                   \0", "RST 0x38               \0",
};

void
print_instr_mnemonic(uint8_t instr) {
    printf("[ISTR] %s\n", mnemonics[instr]);
    fflush(stdout);
}

char *
get_instr_mnemonic(uint8_t instr) {
    return mnemonics[instr];
}

}    // namespace CPU