#include <cpu_core.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <irq_controller_mock.h>
#include <mbc1.h>
#include <memory_map_mock.h>

using namespace testing;

TEST(ARITH_AND, AND_A) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0xA7));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.A = 0x55;
    core.A = 0x55;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0x55);
}

TEST(ARITH_AND, AND_B) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0xA0));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.A = 0xA5;
    core.B = 0x55;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0x05);
}

TEST(ARITH_AND, AND_C) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0xA1));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.A = 0xA5;
    core.C = 0x55;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0x05);
}

TEST(ARITH_AND, AND_D) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0xA2));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.A = 0xA5;
    core.D = 0x55;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0x05);
}

TEST(ARITH_AND, AND_E) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0xA3));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.A = 0xA5;
    core.E = 0x55;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0x05);
}

TEST(ARITH_AND, AND_H) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0xA4));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.A = 0xA5;
    core.H = 0x55;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0x05);
}

TEST(ARITH_AND, AND_L) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0xA5));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.A = 0xA5;
    core.L = 0x55;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0x05);
}

TEST(ARITH_AND, AND_HL) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xA6)).WillOnce(Return(0xA5));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.A = 0x55;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0x05);
}

TEST(ARITH_AND, AND_n) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xE6)).WillOnce(Return(0xA5));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.A = 0x55;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0x05);
}