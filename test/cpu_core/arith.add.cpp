#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <cpu_core.h>
#include <mbc1.h>
#include <memory_map_mock.h>
#include <irq_controller_mock.h>

using namespace testing;


TEST(ARITH_ADD, ADD_A){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(1)
        .WillOnce(Return(0x87));

    core.A = 0x11;
    core.A = 0x11;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0x22);

}

TEST(ARITH_ADD, ADD_B){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(1)
        .WillOnce(Return(0x80));

    core.A = 0x11;
    core.B = 0x11;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0x22);

}

TEST(ARITH_ADD, ADD_C){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(1)
        .WillOnce(Return(0x81));

    core.A = 0x11;
    core.C = 0x11;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0x22);

}

TEST(ARITH_ADD, ADD_D){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(1)
        .WillOnce(Return(0x82));

    core.A = 0x11;
    core.D = 0x11;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0x22);

}

TEST(ARITH_ADD, ADD_E){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(1)
        .WillOnce(Return(0x83));

    core.A = 0x11;
    core.E = 0x11;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0x22);

}

TEST(ARITH_ADD, ADD_H){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(1)
        .WillOnce(Return(0x84));

    core.A = 0x11;
    core.H = 0x11;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0x22);

}

TEST(ARITH_ADD, ADD_L){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(1)
        .WillOnce(Return(0x85));

    core.A = 0x11;
    core.L = 0x11;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0x22);

}

TEST(ARITH_ADD, ADD_HL){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0x86))
        .WillOnce(Return(0x11));

    core.A = 0x11;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0x22);

}

TEST(ARITH_ADD, ADD_n){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xC6))
        .WillOnce(Return(0x11));

    core.A = 0x11;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0x22);

}