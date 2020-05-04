#include <cpu_core.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <irq_controller_mock.h>
#include <mbc1.h>
#include <memory_map_mock.h>

using namespace testing;

TEST(ARITH_XOR, XOR_A) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0xAF));

    core.A = 0xA5;
    core.A = 0x55;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0x00);
}

TEST(ARITH_XOR, XOR_B) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0xA8));

    core.A = 0xA5;
    core.B = 0x55;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0xF0);
}

TEST(ARITH_XOR, XOR_C) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0xA9));

    core.A = 0xA5;
    core.C = 0x55;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0xF0);
}

TEST(ARITH_XOR, XOR_D) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0xAA));

    core.A = 0xA5;
    core.D = 0x55;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0xF0);
}

TEST(ARITH_XOR, XOR_E) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0xAB));

    core.A = 0xA5;
    core.E = 0x55;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0xF0);
}

TEST(ARITH_XOR, XOR_H) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0xAC));

    core.A = 0xA5;
    core.H = 0x55;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0xF0);
}

TEST(ARITH_XOR, XOR_L) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0xAD));

    core.A = 0xA5;
    core.L = 0x55;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0xF0);
}

TEST(ARITH_XOR, XOR_HL) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xAE)).WillOnce(Return(0xA5));

    core.A = 0x55;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0xF0);
}

TEST(ARITH_XOR, XOR_n) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xEE)).WillOnce(Return(0xA5));

    core.A = 0x55;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0xF0);
}