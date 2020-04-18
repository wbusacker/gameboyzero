#include <cpu_core.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <irq_controller_mock.h>
#include <mbc1.h>
#include <memory_map_mock.h>

using namespace testing;

TEST(CPU_CORE_ARITH, ADD_HALF_CARRY) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    core.A = 0b01101011;
    core.B = 0b00111101;

    core.process_arith(0x80);

    ASSERT_EQ(0b10101000, core.A);
    ASSERT_TRUE(core.flags.half_carry);
    ASSERT_FALSE(core.flags.carry);
}

TEST(CPU_CORE_ARITH, ADD_CARRY) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    core.A = 0b01101011;
    core.B = 0b10111101;

    core.process_arith(0x80);

    ASSERT_EQ(0b00101000, core.A);
    ASSERT_TRUE(core.flags.half_carry);
    ASSERT_TRUE(core.flags.carry);
}

TEST(CPU_CORE_ARITH, ADD_WITH_CARRY) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    core.A = 0x11;
    core.B = 0x11;

    core.flags.carry = true;

    core.process_arith(0x88);

    ASSERT_EQ(0x23, core.A);
}

TEST(CPU_CORE_ARITH, SUB) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    core.A = 0x11;
    core.B = 0x11;

    core.process_arith(0x90);

    ASSERT_EQ(0x0, core.A);
}

TEST(CPU_CORE_ARITH, SUB_WITH_CARRY) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    core.A = 0x11;
    core.B = 0x11;

    core.flags.carry = true;

    core.process_arith(0x98);

    ASSERT_EQ(0xff, core.A);
}
