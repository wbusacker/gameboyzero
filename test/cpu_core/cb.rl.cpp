#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <cpu_core.h>
#include <mbc1.h>
#include <memory_map_mock.h>

using namespace testing;

TEST(CPU_CB_ROTATE, RLA){
    Mock_Memory_Map bus(NULL);
    CPU::LR35902 core(bus);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(1)
        .WillOnce(Return(0x17));

    core.A = 0x20;

    core.flags.carry = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.carry, false);
    ASSERT_EQ(core.A, 0x41);
}

TEST(CPU_CB_ROTATE, RL_A){
    Mock_Memory_Map bus(NULL);
    CPU::LR35902 core(bus);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x17));

    core.A = 0x20;

    core.flags.carry = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.carry, false);
    ASSERT_EQ(core.A, 0x41);
}

TEST(CPU_CB_ROTATE, RL_B){
    Mock_Memory_Map bus(NULL);
    CPU::LR35902 core(bus);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x10));

    core.B = 0x20;

    core.flags.carry = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.carry, false);
    ASSERT_EQ(core.B, 0x41);
}

TEST(CPU_CB_ROTATE, RL_C){
    Mock_Memory_Map bus(NULL);
    CPU::LR35902 core(bus);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x11));

    core.C = 0x20;

    core.flags.carry = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.carry, false);
    ASSERT_EQ(core.C, 0x41);
}

TEST(CPU_CB_ROTATE, RL_D){
    Mock_Memory_Map bus(NULL);
    CPU::LR35902 core(bus);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x12));

    core.D = 0x20;

    core.flags.carry = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.carry, false);
    ASSERT_EQ(core.D, 0x41);
}

TEST(CPU_CB_ROTATE, RL_E){
    Mock_Memory_Map bus(NULL);
    CPU::LR35902 core(bus);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x13));

    core.E = 0x20;

    core.flags.carry = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.carry, false);
    ASSERT_EQ(core.E, 0x41);
}

TEST(CPU_CB_ROTATE, RL_H){
    Mock_Memory_Map bus(NULL);
    CPU::LR35902 core(bus);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x14));

    core.H = 0x20;

    core.flags.carry = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.carry, false);
    ASSERT_EQ(core.H, 0x41);
}

TEST(CPU_CB_ROTATE, RL_L){
    Mock_Memory_Map bus(NULL);
    CPU::LR35902 core(bus);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x15));

    core.L = 0x20;

    core.flags.carry = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.carry, false);
    ASSERT_EQ(core.L, 0x41);
}

TEST(CPU_CB_ROTATE, RL_HL){
    Mock_Memory_Map bus(NULL);
    CPU::LR35902 core(bus);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(3)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x16))
        .WillOnce(Return(0x20));

    EXPECT_CALL(bus, store_addr(_,0x41))
        .Times(1);

    core.flags.carry = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.carry, false);
}