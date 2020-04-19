#include <cpu_core.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <irq_controller_mock.h>
#include <mbc1.h>
#include <memory_map_mock.h>

using namespace testing;

TEST(CPU_CB_ROTATE, RLCA) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x07));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.A = 0x80;

    core.flags.carry = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.carry, true);
    ASSERT_EQ(core.A, 0x01);
}

TEST(CPU_CB_ROTATE, RLC_A) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x07));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.A = 0x80;

    core.flags.carry = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.carry, true);
    ASSERT_EQ(core.A, 0x01);
}

TEST(CPU_CB_ROTATE, RLC_B) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x00));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.B = 0x80;

    core.flags.carry = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.carry, true);
    ASSERT_EQ(core.B, 0x01);
}

TEST(CPU_CB_ROTATE, RLC_C) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x01));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.C = 0x80;

    core.flags.carry = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.carry, true);
    ASSERT_EQ(core.C, 0x01);
}

TEST(CPU_CB_ROTATE, RLC_D) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x02));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.D = 0x80;

    core.flags.carry = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.carry, true);
    ASSERT_EQ(core.D, 0x01);
}

TEST(CPU_CB_ROTATE, RLC_E) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x03));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.E = 0x80;

    core.flags.carry = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.carry, true);
    ASSERT_EQ(core.E, 0x01);
}

TEST(CPU_CB_ROTATE, RLC_H) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x04));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.H = 0x80;

    core.flags.carry = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.carry, true);
    ASSERT_EQ(core.H, 0x01);
}

TEST(CPU_CB_ROTATE, RLC_L) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x05));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.L = 0x80;

    core.flags.carry = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.carry, true);
    ASSERT_EQ(core.L, 0x01);
}

TEST(CPU_CB_ROTATE, RLC_HL) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(3).WillOnce(Return(0xCB)).WillOnce(Return(0x06)).WillOnce(Return(0x80));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    EXPECT_CALL(bus, store_addr(_, 0x01)).Times(1);

    core.flags.carry = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.carry, true);
}