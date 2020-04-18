#include <cpu_core.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <irq_controller_mock.h>
#include <mbc1.h>
#include <memory_map_mock.h>

using namespace testing;

TEST(CPU_CB_ROTATE, RRA) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x1F));

    core.A = 0x00;

    core.flags.carry = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.carry, false);
    ASSERT_EQ(core.A, 0x80);
}

TEST(CPU_CB_ROTATE, RR_A) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x1F));

    core.A = 0x00;

    core.flags.carry = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.carry, false);
    ASSERT_EQ(core.A, 0x80);
}

TEST(CPU_CB_ROTATE, RR_B) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x18));

    core.B = 0x00;

    core.flags.carry = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.carry, false);
    ASSERT_EQ(core.B, 0x80);
}

TEST(CPU_CB_ROTATE, RR_C) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x19));

    core.C = 0x00;

    core.flags.carry = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.carry, false);
    ASSERT_EQ(core.C, 0x80);
}

TEST(CPU_CB_ROTATE, RR_D) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x1A));

    core.D = 0x00;

    core.flags.carry = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.carry, false);
    ASSERT_EQ(core.D, 0x80);
}

TEST(CPU_CB_ROTATE, RR_E) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x1B));

    core.E = 0x00;

    core.flags.carry = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.carry, false);
    ASSERT_EQ(core.E, 0x80);
}

TEST(CPU_CB_ROTATE, RR_H) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x1C));

    core.H = 0x00;

    core.flags.carry = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.carry, false);
    ASSERT_EQ(core.H, 0x80);
}

TEST(CPU_CB_ROTATE, RR_L) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x1D));

    core.L = 0x00;

    core.flags.carry = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.carry, false);
    ASSERT_EQ(core.L, 0x80);
}

TEST(CPU_CB_ROTATE, RR_HL) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(3).WillOnce(Return(0xCB)).WillOnce(Return(0x1E)).WillOnce(Return(0x00));

    EXPECT_CALL(bus, store_addr(_, 0x80)).Times(1);

    core.flags.carry = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.carry, false);
}