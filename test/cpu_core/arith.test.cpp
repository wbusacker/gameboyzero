#include <gtest/gtest.h>
#include <cpu_core.h>

TEST(CPU_CORE_ARITH, ADD_HALF_CARRY){
    class Bus::Main_Bus bus;
    class CPU::LR35902 core(bus);

    core.A = 0b01101011;
    core.B = 0b00111101;

    core.process_arith(0x80);

    ASSERT_EQ(0b10101000, core.A);
    ASSERT_TRUE(core.flags.half_carry);
    ASSERT_FALSE(core.flags.carry);
}

TEST(CPU_CORE_ARITH, ADD_CARRY){
    class Bus::Main_Bus bus;
    class CPU::LR35902 core(bus);

    core.A = 0b01101011;
    core.B = 0b10111101;

    core.process_arith(0x80);

    ASSERT_EQ(0b00101000, core.A);
    ASSERT_TRUE(core.flags.half_carry);
    ASSERT_TRUE(core.flags.carry);

}

TEST(CPU_CORE_ARITH, ADD_WITH_CARRY){
    class Bus::Main_Bus bus;
    class CPU::LR35902 core(bus);

    core.A = 0x11;
    core.B = 0x11;

    core.flags.carry = true;

    core.process_arith(0x88);

    ASSERT_EQ(0x23, core.A);

}

TEST(CPU_CORE_ARITH, SUB){

    class Bus::Main_Bus bus;
    class CPU::LR35902 core(bus);

    core.A = 0x11;
    core.B = 0x11;

    core.process_arith(0x90);

    ASSERT_EQ(0x0, core.A);
    
}

TEST(CPU_CORE_ARITH, SUB_WITH_CARRY){

    class Bus::Main_Bus bus;
    class CPU::LR35902 core(bus);

    core.A = 0x11;
    core.B = 0x11;

    core.flags.carry = true;

    core.process_arith(0x98);

    ASSERT_EQ(0xff, core.A);
    
}