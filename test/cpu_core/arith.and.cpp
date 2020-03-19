#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <cpu_core.h>
#include <mbc1.h>
#include <memory_map_mock.h>

using namespace testing;


TEST(ARITH_AND, AND_A){
    Mock_Memory_Map bus(NULL);
    CPU::LR35902 core(bus);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(1)
        .WillOnce(Return(0xA7));

    core.A = 0x55;
    core.A = 0x55;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0x55);

}

TEST(ARITH_AND, AND_B){
    Mock_Memory_Map bus(NULL);
    CPU::LR35902 core(bus);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(1)
        .WillOnce(Return(0xA0));

    core.A = 0xA5;
    core.B = 0x55;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0x05);

}

TEST(ARITH_AND, AND_C){
    Mock_Memory_Map bus(NULL);
    CPU::LR35902 core(bus);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(1)
        .WillOnce(Return(0xA1));

    core.A = 0xA5;
    core.C = 0x55;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0x05);

}

TEST(ARITH_AND, AND_D){
    Mock_Memory_Map bus(NULL);
    CPU::LR35902 core(bus);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(1)
        .WillOnce(Return(0xA2));

    core.A = 0xA5;
    core.D = 0x55;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0x05);

}

TEST(ARITH_AND, AND_E){
    Mock_Memory_Map bus(NULL);
    CPU::LR35902 core(bus);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(1)
        .WillOnce(Return(0xA3));

    core.A = 0xA5;
    core.E = 0x55;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0x05);

}

TEST(ARITH_AND, AND_H){
    Mock_Memory_Map bus(NULL);
    CPU::LR35902 core(bus);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(1)
        .WillOnce(Return(0xA4));

    core.A = 0xA5;
    core.H = 0x55;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0x05);

}

TEST(ARITH_AND, AND_L){
    Mock_Memory_Map bus(NULL);
    CPU::LR35902 core(bus);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(1)
        .WillOnce(Return(0xA5));

    core.A = 0xA5;
    core.L = 0x55;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0x05);

}

TEST(ARITH_AND, AND_HL){
    Mock_Memory_Map bus(NULL);
    CPU::LR35902 core(bus);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xA6))
        .WillOnce(Return(0xA5));

    core.A = 0x55;
    
    core.cycle_cpu();

    ASSERT_EQ(core.A, 0x05);

}

TEST(ARITH_AND, AND_n){
    Mock_Memory_Map bus(NULL);
    CPU::LR35902 core(bus);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xE6))
        .WillOnce(Return(0xA5));

    core.A = 0x55;
    
    core.cycle_cpu();

    ASSERT_EQ(core.A, 0x05);

}