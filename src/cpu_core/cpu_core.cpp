#include <cpu_core.h>

namespace CPU {

bool print_diagnostics = true;

LR35902::LR35902(Memory::Memory_Map &bus, IRQ::Controller &irq) :
    memory_bus(bus), irq_controller(irq), func_decomp(bus) {
    flags.sub        = false;
    flags.zero       = true;
    flags.carry      = true;
    flags.half_carry = true;
    flags.padding    = 0x0;

    A = 0x01;
    B = 0x00;
    C = 0x13;
    D = 0x00;
    E = 0xD8;
    H = 0x01;
    L = 0x4D;

    stack_pointer   = 0xFFFE;
    program_counter = 0x0100;

    stall_processor  = false;
    instr_cycles     = 0;
    enable_interrupt = false;

    trace_buffer_overflow = false;
    trace_buffer_bottom   = 0;

    static char default_instr[CPU::MNEMONIC_LENGTH] = "Default INSTR";

    uint16_t i;
    for (i = 0; i < CPU::TRACE_BUFFER_LEN; i++) {

        trace_buffer[i].addr     = 0xFFFF;
        trace_buffer[i].count    = 0x0;
        trace_buffer[i].mnemonic = default_instr;
    }

    num_clock_cycles = 0xFFFFFFFFFFFFFFFF;

    timespec timer_get;
    clock_gettime(CLOCK_MONOTONIC, &timer_get);

    cpu_start_time_ns = timer_get.tv_nsec;
    cpu_start_time_ns += static_cast<uint64_t>(timer_get.tv_sec) * 1E9;

    pthread_mutex_init(&cpu_control_lock, NULL);

    enable_instruction_trace = false;
    enable_function_trace    = false;

    trace_log_handle = fopen(CPU::TRACE_LOG_NAME, "w");
    // fclose(fp);

    // func_decomp.register_call(0x0150, 0x0700);

    last_cycle_time = 0;
    cpu_frequency   = 0;

    /* Define all of the destination functions  */
    fp[0]   = &LR35902::process_misc;
    fp[1]   = &LR35902::process_ld;
    fp[2]   = &LR35902::process_ld;
    fp[3]   = &LR35902::process_arith;
    fp[4]   = &LR35902::process_arith;
    fp[5]   = &LR35902::process_arith;
    fp[6]   = &LR35902::process_ld;
    fp[7]   = &LR35902::process_logical;
    fp[8]   = &LR35902::process_ld;
    fp[9]   = &LR35902::process_arith;
    fp[10]  = &LR35902::process_ld;
    fp[11]  = &LR35902::process_arith;
    fp[12]  = &LR35902::process_arith;
    fp[13]  = &LR35902::process_arith;
    fp[14]  = &LR35902::process_ld;
    fp[15]  = &LR35902::process_logical;
    fp[16]  = &LR35902::process_misc;
    fp[17]  = &LR35902::process_ld;
    fp[18]  = &LR35902::process_ld;
    fp[19]  = &LR35902::process_arith;
    fp[20]  = &LR35902::process_arith;
    fp[21]  = &LR35902::process_arith;
    fp[22]  = &LR35902::process_ld;
    fp[23]  = &LR35902::process_logical;
    fp[24]  = &LR35902::process_flow;
    fp[25]  = &LR35902::process_arith;
    fp[26]  = &LR35902::process_ld;
    fp[27]  = &LR35902::process_arith;
    fp[28]  = &LR35902::process_arith;
    fp[29]  = &LR35902::process_arith;
    fp[30]  = &LR35902::process_ld;
    fp[31]  = &LR35902::process_logical;
    fp[32]  = &LR35902::process_flow;
    fp[33]  = &LR35902::process_ld;
    fp[34]  = &LR35902::process_ld;
    fp[35]  = &LR35902::process_arith;
    fp[36]  = &LR35902::process_arith;
    fp[37]  = &LR35902::process_arith;
    fp[38]  = &LR35902::process_ld;
    fp[39]  = &LR35902::process_arith;
    fp[40]  = &LR35902::process_flow;
    fp[41]  = &LR35902::process_arith;
    fp[42]  = &LR35902::process_ld;
    fp[43]  = &LR35902::process_arith;
    fp[44]  = &LR35902::process_arith;
    fp[45]  = &LR35902::process_arith;
    fp[46]  = &LR35902::process_ld;
    fp[47]  = &LR35902::process_arith;
    fp[48]  = &LR35902::process_flow;
    fp[49]  = &LR35902::process_ld;
    fp[50]  = &LR35902::process_ld;
    fp[51]  = &LR35902::process_arith;
    fp[52]  = &LR35902::process_arith;
    fp[53]  = &LR35902::process_arith;
    fp[54]  = &LR35902::process_ld;
    fp[55]  = &LR35902::process_arith;
    fp[56]  = &LR35902::process_flow;
    fp[57]  = &LR35902::process_arith;
    fp[58]  = &LR35902::process_ld;
    fp[59]  = &LR35902::process_arith;
    fp[60]  = &LR35902::process_arith;
    fp[61]  = &LR35902::process_arith;
    fp[62]  = &LR35902::process_ld;
    fp[63]  = &LR35902::process_arith;
    fp[64]  = &LR35902::process_ld;
    fp[65]  = &LR35902::process_ld;
    fp[66]  = &LR35902::process_ld;
    fp[67]  = &LR35902::process_ld;
    fp[68]  = &LR35902::process_ld;
    fp[69]  = &LR35902::process_ld;
    fp[70]  = &LR35902::process_ld;
    fp[71]  = &LR35902::process_ld;
    fp[72]  = &LR35902::process_ld;
    fp[73]  = &LR35902::process_ld;
    fp[74]  = &LR35902::process_ld;
    fp[75]  = &LR35902::process_ld;
    fp[76]  = &LR35902::process_ld;
    fp[77]  = &LR35902::process_ld;
    fp[78]  = &LR35902::process_ld;
    fp[79]  = &LR35902::process_ld;
    fp[80]  = &LR35902::process_ld;
    fp[81]  = &LR35902::process_ld;
    fp[82]  = &LR35902::process_ld;
    fp[83]  = &LR35902::process_ld;
    fp[84]  = &LR35902::process_ld;
    fp[85]  = &LR35902::process_ld;
    fp[86]  = &LR35902::process_ld;
    fp[87]  = &LR35902::process_ld;
    fp[88]  = &LR35902::process_ld;
    fp[89]  = &LR35902::process_ld;
    fp[90]  = &LR35902::process_ld;
    fp[91]  = &LR35902::process_ld;
    fp[92]  = &LR35902::process_ld;
    fp[93]  = &LR35902::process_ld;
    fp[94]  = &LR35902::process_ld;
    fp[95]  = &LR35902::process_ld;
    fp[96]  = &LR35902::process_ld;
    fp[97]  = &LR35902::process_ld;
    fp[98]  = &LR35902::process_ld;
    fp[99]  = &LR35902::process_ld;
    fp[100] = &LR35902::process_ld;
    fp[101] = &LR35902::process_ld;
    fp[102] = &LR35902::process_ld;
    fp[103] = &LR35902::process_ld;
    fp[104] = &LR35902::process_ld;
    fp[105] = &LR35902::process_ld;
    fp[106] = &LR35902::process_ld;
    fp[107] = &LR35902::process_ld;
    fp[108] = &LR35902::process_ld;
    fp[109] = &LR35902::process_ld;
    fp[110] = &LR35902::process_ld;
    fp[111] = &LR35902::process_ld;
    fp[112] = &LR35902::process_ld;
    fp[113] = &LR35902::process_ld;
    fp[114] = &LR35902::process_ld;
    fp[115] = &LR35902::process_ld;
    fp[116] = &LR35902::process_ld;
    fp[117] = &LR35902::process_ld;
    fp[118] = &LR35902::process_misc;
    fp[119] = &LR35902::process_ld;
    fp[120] = &LR35902::process_ld;
    fp[121] = &LR35902::process_ld;
    fp[122] = &LR35902::process_ld;
    fp[123] = &LR35902::process_ld;
    fp[124] = &LR35902::process_ld;
    fp[125] = &LR35902::process_ld;
    fp[126] = &LR35902::process_ld;
    fp[127] = &LR35902::process_ld;
    fp[128] = &LR35902::process_arith;
    fp[129] = &LR35902::process_arith;
    fp[130] = &LR35902::process_arith;
    fp[131] = &LR35902::process_arith;
    fp[132] = &LR35902::process_arith;
    fp[133] = &LR35902::process_arith;
    fp[134] = &LR35902::process_arith;
    fp[135] = &LR35902::process_arith;
    fp[136] = &LR35902::process_arith;
    fp[137] = &LR35902::process_arith;
    fp[138] = &LR35902::process_arith;
    fp[139] = &LR35902::process_arith;
    fp[140] = &LR35902::process_arith;
    fp[141] = &LR35902::process_arith;
    fp[142] = &LR35902::process_arith;
    fp[143] = &LR35902::process_arith;
    fp[144] = &LR35902::process_arith;
    fp[145] = &LR35902::process_arith;
    fp[146] = &LR35902::process_arith;
    fp[147] = &LR35902::process_arith;
    fp[148] = &LR35902::process_arith;
    fp[149] = &LR35902::process_arith;
    fp[150] = &LR35902::process_arith;
    fp[151] = &LR35902::process_arith;
    fp[152] = &LR35902::process_arith;
    fp[153] = &LR35902::process_arith;
    fp[154] = &LR35902::process_arith;
    fp[155] = &LR35902::process_arith;
    fp[156] = &LR35902::process_arith;
    fp[157] = &LR35902::process_arith;
    fp[158] = &LR35902::process_arith;
    fp[159] = &LR35902::process_arith;
    fp[160] = &LR35902::process_arith;
    fp[161] = &LR35902::process_arith;
    fp[162] = &LR35902::process_arith;
    fp[163] = &LR35902::process_arith;
    fp[164] = &LR35902::process_arith;
    fp[165] = &LR35902::process_arith;
    fp[166] = &LR35902::process_arith;
    fp[167] = &LR35902::process_arith;
    fp[168] = &LR35902::process_arith;
    fp[169] = &LR35902::process_arith;
    fp[170] = &LR35902::process_arith;
    fp[171] = &LR35902::process_arith;
    fp[172] = &LR35902::process_arith;
    fp[173] = &LR35902::process_arith;
    fp[174] = &LR35902::process_arith;
    fp[175] = &LR35902::process_arith;
    fp[176] = &LR35902::process_arith;
    fp[177] = &LR35902::process_arith;
    fp[178] = &LR35902::process_arith;
    fp[179] = &LR35902::process_arith;
    fp[180] = &LR35902::process_arith;
    fp[181] = &LR35902::process_arith;
    fp[182] = &LR35902::process_arith;
    fp[183] = &LR35902::process_arith;
    fp[184] = &LR35902::process_arith;
    fp[185] = &LR35902::process_arith;
    fp[186] = &LR35902::process_arith;
    fp[187] = &LR35902::process_arith;
    fp[188] = &LR35902::process_arith;
    fp[189] = &LR35902::process_arith;
    fp[190] = &LR35902::process_arith;
    fp[191] = &LR35902::process_arith;
    fp[192] = &LR35902::process_flow;
    fp[193] = &LR35902::process_ld;
    fp[194] = &LR35902::process_flow;
    fp[195] = &LR35902::process_flow;
    fp[196] = &LR35902::process_flow;
    fp[197] = &LR35902::process_ld;
    fp[198] = &LR35902::process_arith;
    fp[199] = &LR35902::process_flow;
    fp[200] = &LR35902::process_flow;
    fp[201] = &LR35902::process_flow;
    fp[202] = &LR35902::process_flow;
    fp[203] = &LR35902::process_logical;
    fp[204] = &LR35902::process_flow;
    fp[205] = &LR35902::process_flow;
    fp[206] = &LR35902::process_arith;
    fp[207] = &LR35902::process_flow;
    fp[208] = &LR35902::process_flow;
    fp[209] = &LR35902::process_ld;
    fp[210] = &LR35902::process_flow;
    fp[211] = NULL;
    fp[212] = &LR35902::process_flow;
    fp[213] = &LR35902::process_ld;
    fp[214] = &LR35902::process_arith;
    fp[215] = &LR35902::process_flow;
    fp[216] = &LR35902::process_flow;
    fp[217] = &LR35902::process_flow;
    fp[218] = &LR35902::process_flow;
    fp[219] = NULL;
    fp[220] = &LR35902::process_flow;
    fp[221] = NULL;
    fp[222] = &LR35902::process_arith;
    fp[223] = &LR35902::process_flow;
    fp[224] = &LR35902::process_ld;
    fp[225] = &LR35902::process_ld;
    fp[226] = &LR35902::process_ld;
    fp[227] = NULL;
    fp[228] = NULL;
    fp[229] = &LR35902::process_ld;
    fp[230] = &LR35902::process_arith;
    fp[231] = &LR35902::process_flow;
    fp[232] = &LR35902::process_arith;
    fp[233] = &LR35902::process_flow;
    fp[234] = &LR35902::process_ld;
    fp[235] = NULL;
    fp[236] = NULL;
    fp[237] = NULL;
    fp[238] = &LR35902::process_arith;
    fp[239] = &LR35902::process_flow;
    fp[240] = &LR35902::process_ld;
    fp[241] = &LR35902::process_ld;
    fp[242] = &LR35902::process_ld;
    fp[243] = &LR35902::process_misc;
    fp[244] = NULL;
    fp[245] = &LR35902::process_ld;
    fp[246] = &LR35902::process_arith;
    fp[247] = &LR35902::process_flow;
    fp[248] = &LR35902::process_ld;
    fp[249] = &LR35902::process_ld;
    fp[250] = &LR35902::process_ld;
    fp[251] = &LR35902::process_misc;
    fp[252] = NULL;
    fp[253] = NULL;
    fp[254] = &LR35902::process_arith;
    fp[255] = &LR35902::process_flow;
}

LR35902::~LR35902(void) {
    fclose(trace_log_handle);
}

}    // namespace CPU