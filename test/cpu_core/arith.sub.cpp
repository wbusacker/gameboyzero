#include <cpu_core.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <irq_controller_mock.h>
#include <mbc1.h>
#include <memory_map_mock.h>

using namespace testing;

TEST(ARITH_SUB, SUB_A) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x97));

    core.A = 0x11;
    core.A = 0x11;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0x00);
}

TEST(ARITH_SUB, SUB_B) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x90));

    core.A = 0x11;
    core.B = 0x11;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0x00);
}

TEST(ARITH_SUB, SUB_C) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x91));

    core.A = 0x11;
    core.C = 0x11;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0x00);
}

TEST(ARITH_SUB, SUB_D) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x92));

    core.A = 0x11;
    core.D = 0x11;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0x00);
}

TEST(ARITH_SUB, SUB_E) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x93));

    core.A = 0x11;
    core.E = 0x11;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0x00);
}

TEST(ARITH_SUB, SUB_H) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x94));

    core.A = 0x11;
    core.H = 0x11;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0x00);
}

TEST(ARITH_SUB, SUB_L) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x95));

    core.A = 0x11;
    core.L = 0x11;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0x00);
}

TEST(ARITH_SUB, SUB_HL) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0x96)).WillOnce(Return(0x11));

    core.A = 0x11;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0x00);
}

TEST(ARITH_SUB, SUB_n) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xD6)).WillOnce(Return(0x11));

    core.A = 0x11;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0x00);
}