#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <cpu_core.h>
#include <mbc1.h>
#include <memory_map_mock.h>
#include <irq_controller_mock.h>

using namespace testing;


TEST(ARITH_SBC, SBC_A){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(1)
        .WillOnce(Return(0x9F));

    core.A = 0x11;
    core.flags.carry = true;
    core.A = 0x11;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0xff);

}

TEST(ARITH_SBC, SBC_B){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(1)
        .WillOnce(Return(0x98));

    core.A = 0x11;
    core.flags.carry = true;
    core.B = 0x11;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0xff);

}

TEST(ARITH_SBC, SBC_C){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(1)
        .WillOnce(Return(0x99));

    core.A = 0x11;
    core.flags.carry = true;
    core.C = 0x11;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0xff);

}

TEST(ARITH_SBC, SBC_D){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(1)
        .WillOnce(Return(0x9A));

    core.A = 0x11;
    core.flags.carry = true;
    core.D = 0x11;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0xff);

}

TEST(ARITH_SBC, SBC_E){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(1)
        .WillOnce(Return(0x9B));

    core.A = 0x11;
    core.flags.carry = true;
    core.E = 0x11;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0xff);

}

TEST(ARITH_SBC, SBC_H){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(1)
        .WillOnce(Return(0x9C));

    core.A = 0x11;
    core.flags.carry = true;
    core.H = 0x11;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0xff);

}

TEST(ARITH_SBC, SBC_L){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(1)
        .WillOnce(Return(0x9D));

    core.A = 0x11;
    core.flags.carry = true;
    core.L = 0x11;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0xff);

}

TEST(ARITH_SBC, SBC_HL){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0x9E))
        .WillOnce(Return(0x11));

    core.flags.carry = true;
    core.A = 0x11;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0xff);

}

TEST(ARITH_SBC, SBC_n){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xDE))
        .WillOnce(Return(0x11));

    core.flags.carry = true;
    core.A = 0x11;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0xff);

}