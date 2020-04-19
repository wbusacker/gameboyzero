#include <cpu_core.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <irq_controller_mock.h>
#include <mbc1.h>
#include <memory_map_mock.h>

using namespace testing;

TEST(CPU_CB_SHIFT, SRA_A) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x2F));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.A = 0x81;

    core.flags.carry = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.carry, true);
    ASSERT_EQ(core.A, 0xC0);
}

TEST(CPU_CB_SHIFT, SRA_B) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x28));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.B = 0x81;

    core.flags.carry = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.carry, true);
    ASSERT_EQ(core.B, 0xC0);
}

TEST(CPU_CB_SHIFT, SRA_C) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x29));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.C = 0x81;

    core.flags.carry = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.carry, true);
    ASSERT_EQ(core.C, 0xC0);
}

TEST(CPU_CB_SHIFT, SRA_D) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x2A));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.D = 0x81;

    core.flags.carry = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.carry, true);
    ASSERT_EQ(core.D, 0xC0);
}

TEST(CPU_CB_SHIFT, SRA_E) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x2B));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.E = 0x81;

    core.flags.carry = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.carry, true);
    ASSERT_EQ(core.E, 0xC0);
}

TEST(CPU_CB_SHIFT, SRA_H) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x2C));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.H = 0x81;

    core.flags.carry = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.carry, true);
    ASSERT_EQ(core.H, 0xC0);
}

TEST(CPU_CB_SHIFT, SRA_L) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x2D));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.L = 0x81;

    core.flags.carry = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.carry, true);
    ASSERT_EQ(core.L, 0xC0);
}

TEST(CPU_CB_SHIFT, SRA_HL) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(3).WillOnce(Return(0xCB)).WillOnce(Return(0x2E)).WillOnce(Return(0x81));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    EXPECT_CALL(bus, store_addr(_, 0xC0)).Times(1);

    core.flags.carry = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.carry, true);
}