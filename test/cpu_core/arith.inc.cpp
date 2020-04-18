#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <cpu_core.h>
#include <mbc1.h>
#include <memory_map_mock.h>
#include <irq_controller_mock.h>

using namespace testing;

TEST(ARITH_INC, INC_A){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(1)
        .WillOnce(Return(0x3C));

    core.A = 0x11;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0x12);

}

TEST(ARITH_INC, INC_B){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(1)
        .WillOnce(Return(0x04));

    core.B = 0x11;

    core.cycle_cpu();

    ASSERT_EQ(core.B, 0x12);

}

TEST(ARITH_INC, INC_C){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(1)
        .WillOnce(Return(0x0C));

    core.C = 0x11;

    core.cycle_cpu();

    ASSERT_EQ(core.C, 0x12);

}

TEST(ARITH_INC, INC_D){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(1)
        .WillOnce(Return(0x14));

    core.D = 0x11;

    core.cycle_cpu();

    ASSERT_EQ(core.D, 0x12);

}

TEST(ARITH_INC, INC_E){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(1)
        .WillOnce(Return(0x1C));

    core.E = 0x11;

    core.cycle_cpu();

    ASSERT_EQ(core.E, 0x12);

}

TEST(ARITH_INC, INC_H){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(1)
        .WillOnce(Return(0x24));

    core.H = 0x11;

    core.cycle_cpu();

    ASSERT_EQ(core.H, 0x12);

}

TEST(ARITH_INC, INC_L){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(1)
        .WillOnce(Return(0x2C));

    core.L = 0x11;

    core.cycle_cpu();

    ASSERT_EQ(core.L, 0x12);

}

TEST(ARITH_INC, INC_HL){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0x34))
        .WillOnce(Return(0x11));

    EXPECT_CALL(bus, store_addr(_,0x12))
        .Times(1);

    core.cycle_cpu();

}