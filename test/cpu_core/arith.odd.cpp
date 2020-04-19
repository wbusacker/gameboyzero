#include <cpu_core.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <irq_controller_mock.h>
#include <mbc1.h>
#include <memory_map_mock.h>

using namespace testing;

TEST(CPU_ODD, DAA) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x27));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.flags.carry      = false;
    core.flags.half_carry = false;
    core.A                = 0x2A;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0x2A + 6);
}

TEST(CPU_ODD, SCF) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x37));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.flags.carry = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.carry, true);
}

TEST(CPU_ODD, CCF) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x3F));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.flags.carry = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.carry, false);
}

TEST(CPU_ODD, CPL) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x2F));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.A = 0x55;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0xAA);
}
