#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <cpu_core.h>
#include <mbc1.h>
#include <memory_map_mock.h>
#include <irq_controller_mock.h>

using namespace testing;


TEST(ARITH_CP, CP_A_TRUE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(1)
        .WillOnce(Return(0xBF));

    core.A = 0x11;
    core.A = 0x11;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);

}

TEST(ARITH_CP, CP_B_TRUE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(1)
        .WillOnce(Return(0xB8));

    core.A = 0x11;
    core.B = 0x11;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);

}

TEST(ARITH_CP, CP_C_TRUE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(1)
        .WillOnce(Return(0xB9));

    core.A = 0x11;
    core.C = 0x11;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);

}

TEST(ARITH_CP, CP_D_TRUE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(1)
        .WillOnce(Return(0xBA));

    core.A = 0x11;
    core.D = 0x11;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);

}

TEST(ARITH_CP, CP_E_TRUE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(1)
        .WillOnce(Return(0xBB));

    core.A = 0x11;
    core.E = 0x11;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);

}

TEST(ARITH_CP, CP_H_TRUE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(1)
        .WillOnce(Return(0xBC));

    core.A = 0x11;
    core.H = 0x11;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);

}

TEST(ARITH_CP, CP_L_TRUE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(1)
        .WillOnce(Return(0xBD));

    core.A = 0x11;
    core.L = 0x11;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);

}

TEST(ARITH_CP, CP_HL_TRUE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xBE))
        .WillOnce(Return(0x11));

    core.A = 0x11;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);

}

TEST(ARITH_CP, CP_n_TRUE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xFE))
        .WillOnce(Return(0x11));

    core.A = 0x11;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);

}

TEST(ARITH_CP, CP_A_FALSE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(1)
        .WillOnce(Return(0xBF));

    core.A = 0x11;
    core.A = 0x15;

    core.cycle_cpu();

    ASSERT_NE(core.flags.zero, false);

}

TEST(ARITH_CP, CP_B_FALSE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(1)
        .WillOnce(Return(0xB8));

    core.A = 0x11;
    core.B = 0x15;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);

}

TEST(ARITH_CP, CP_C_FALSE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(1)
        .WillOnce(Return(0xB9));

    core.A = 0x11;
    core.C = 0x15;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);

}

TEST(ARITH_CP, CP_D_FALSE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(1)
        .WillOnce(Return(0xBA));

    core.A = 0x11;
    core.D = 0x15;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);

}

TEST(ARITH_CP, CP_E_FALSE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(1)
        .WillOnce(Return(0xBB));

    core.A = 0x11;
    core.E = 0x15;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);

}

TEST(ARITH_CP, CP_H_FALSE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(1)
        .WillOnce(Return(0xBC));

    core.A = 0x11;
    core.H = 0x15;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);

}

TEST(ARITH_CP, CP_L_FALSE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(1)
        .WillOnce(Return(0xBD));

    core.A = 0x11;
    core.L = 0x15;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);

}

TEST(ARITH_CP, CP_HL_FALSE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xBE))
        .WillOnce(Return(0x11));

    core.A = 0x15;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);

}

TEST(ARITH_CP, CP_n_FALSE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xFE))
        .WillOnce(Return(0x11));

    core.A = 0x15;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);

}