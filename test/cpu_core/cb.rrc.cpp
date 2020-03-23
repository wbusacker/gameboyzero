#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <cpu_core.h>
#include <mbc1.h>
#include <memory_map_mock.h>

using namespace testing;

TEST(CPU_CB_ROTATE, RRCA){
    Mock_Memory_Map bus(NULL);
    CPU::LR35902 core(bus);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(1)
        .WillOnce(Return(0x0F));

    core.A = 0x01;

    core.flags.carry = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.carry, true);
    ASSERT_EQ(core.A, 0x80);
}

TEST(CPU_CB_ROTATE, RRC_A){
    Mock_Memory_Map bus(NULL);
    CPU::LR35902 core(bus);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x0F));

    core.A = 0x01;

    core.flags.carry = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.carry, true);
    ASSERT_EQ(core.A, 0x80);
}

TEST(CPU_CB_ROTATE, RRC_B){
    Mock_Memory_Map bus(NULL);
    CPU::LR35902 core(bus);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x08));

    core.B = 0x01;

    core.flags.carry = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.carry, true);
    ASSERT_EQ(core.B, 0x80);
}

TEST(CPU_CB_ROTATE, RRC_C){
    Mock_Memory_Map bus(NULL);
    CPU::LR35902 core(bus);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x09));

    core.C = 0x01;

    core.flags.carry = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.carry, true);
    ASSERT_EQ(core.C, 0x80);
}

TEST(CPU_CB_ROTATE, RRC_D){
    Mock_Memory_Map bus(NULL);
    CPU::LR35902 core(bus);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x0A));

    core.D = 0x01;

    core.flags.carry = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.carry, true);
    ASSERT_EQ(core.D, 0x80);
}

TEST(CPU_CB_ROTATE, RRC_E){
    Mock_Memory_Map bus(NULL);
    CPU::LR35902 core(bus);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x0B));

    core.E = 0x01;

    core.flags.carry = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.carry, true);
    ASSERT_EQ(core.E, 0x80);
}

TEST(CPU_CB_ROTATE, RRC_H){
    Mock_Memory_Map bus(NULL);
    CPU::LR35902 core(bus);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x0C));

    core.H = 0x01;

    core.flags.carry = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.carry, true);
    ASSERT_EQ(core.H, 0x80);
}

TEST(CPU_CB_ROTATE, RRC_L){
    Mock_Memory_Map bus(NULL);
    CPU::LR35902 core(bus);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x0D));

    core.L = 0x01;

    core.flags.carry = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.carry, true);
    ASSERT_EQ(core.L, 0x80);
}

TEST(CPU_CB_ROTATE, RRC_HL){
    Mock_Memory_Map bus(NULL);
    CPU::LR35902 core(bus);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(3)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x0E))
        .WillOnce(Return(0x01));

    EXPECT_CALL(bus, store_addr(_,0x80))
        .Times(1);

    core.flags.carry = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.carry, true);
}