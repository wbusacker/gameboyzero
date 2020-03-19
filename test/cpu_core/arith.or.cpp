#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <cpu_core.h>
#include <mbc1.h>
#include <memory_map_mock.h>

using namespace testing;

TEST(ARITH_OR, OR_A){
    Mock_Memory_Map bus(NULL);
    CPU::LR35902 core(bus);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(1)
        .WillOnce(Return(0xB7));

    core.A = 0xA5;
    core.A = 0xA5;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0xA5);

}

TEST(ARITH_OR, OR_B){
    Mock_Memory_Map bus(NULL);
    CPU::LR35902 core(bus);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(1)
        .WillOnce(Return(0xB0));

    core.A = 0xA5;
    core.B = 0x55;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0xF5);

}

TEST(ARITH_OR, OR_C){
    Mock_Memory_Map bus(NULL);
    CPU::LR35902 core(bus);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(1)
        .WillOnce(Return(0xB1));

    core.A = 0xA5;
    core.C = 0x55;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0xF5);

}

TEST(ARITH_OR, OR_D){
    Mock_Memory_Map bus(NULL);
    CPU::LR35902 core(bus);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(1)
        .WillOnce(Return(0xB2));

    core.A = 0xA5;
    core.D = 0x55;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0xF5);

}

TEST(ARITH_OR, OR_E){
    Mock_Memory_Map bus(NULL);
    CPU::LR35902 core(bus);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(1)
        .WillOnce(Return(0xB3));

    core.A = 0xA5;
    core.E = 0x55;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0xF5);

}

TEST(ARITH_OR, OR_H){
    Mock_Memory_Map bus(NULL);
    CPU::LR35902 core(bus);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(1)
        .WillOnce(Return(0xB4));

    core.A = 0xA5;
    core.H = 0x55;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0xF5);

}

TEST(ARITH_OR, OR_L){
    Mock_Memory_Map bus(NULL);
    CPU::LR35902 core(bus);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(1)
        .WillOnce(Return(0xB5));

    core.A = 0xA5;
    core.L = 0x55;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0xF5);

}

TEST(ARITH_OR, OR_HL){
    Mock_Memory_Map bus(NULL);
    CPU::LR35902 core(bus);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xB6))
        .WillOnce(Return(0xA5));

    core.A = 0x55;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0xF5);

}

TEST(ARITH_OR, OR_m){
    Mock_Memory_Map bus(NULL);
    CPU::LR35902 core(bus);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xF6))
        .WillOnce(Return(0xA5));

    core.A = 0x55;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0xF5);

}