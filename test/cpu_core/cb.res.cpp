#include <cpu_core.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <irq_controller_mock.h>
#include <mbc1.h>
#include <memory_map_mock.h>

using namespace testing;

TEST(CPU_CB_BIT, RES_0_A_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x87));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.A = 0x01;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0x00);
}

TEST(CPU_CB_BIT, RES_0_B_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x80));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.B = 0x01;

    core.cycle_cpu();

    ASSERT_EQ(core.B, 0x00);
}

TEST(CPU_CB_BIT, RES_0_C_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x81));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.C = 0x01;

    core.cycle_cpu();

    ASSERT_EQ(core.C, 0x00);
}

TEST(CPU_CB_BIT, RES_0_D_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x82));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.D = 0x01;

    core.cycle_cpu();

    ASSERT_EQ(core.D, 0x00);
}

TEST(CPU_CB_BIT, RES_0_E_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x83));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.E = 0x01;

    core.cycle_cpu();

    ASSERT_EQ(core.E, 0x00);
}

TEST(CPU_CB_BIT, RES_0_H_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x84));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.H = 0x01;

    core.cycle_cpu();

    ASSERT_EQ(core.H, 0x00);
}

TEST(CPU_CB_BIT, RES_0_L_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x85));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.L = 0x01;

    core.cycle_cpu();

    ASSERT_EQ(core.L, 0x00);
}

TEST(CPU_CB_BIT, RES_0_HL_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(3).WillOnce(Return(0xCB)).WillOnce(Return(0x86)).WillOnce(Return(0x01));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    EXPECT_CALL(bus, store_addr(_, 0x00)).Times(1);

    core.cycle_cpu();
}

TEST(CPU_CB_BIT, RES_1_A_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x8F));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.A = 0x02;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0x00);
}

TEST(CPU_CB_BIT, RES_1_B_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x88));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.B = 0x02;

    core.cycle_cpu();

    ASSERT_EQ(core.B, 0x00);
}

TEST(CPU_CB_BIT, RES_1_C_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x89));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.C = 0x02;

    core.cycle_cpu();

    ASSERT_EQ(core.C, 0x00);
}

TEST(CPU_CB_BIT, RES_1_D_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x8A));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.D = 0x02;

    core.cycle_cpu();

    ASSERT_EQ(core.D, 0x00);
}

TEST(CPU_CB_BIT, RES_1_E_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x8B));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.E = 0x02;

    core.cycle_cpu();

    ASSERT_EQ(core.E, 0x00);
}

TEST(CPU_CB_BIT, RES_1_H_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x8C));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.H = 0x02;

    core.cycle_cpu();

    ASSERT_EQ(core.H, 0x00);
}

TEST(CPU_CB_BIT, RES_1_L_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x8D));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.L = 0x02;

    core.cycle_cpu();

    ASSERT_EQ(core.L, 0x00);
}

TEST(CPU_CB_BIT, RES_1_HL_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(3).WillOnce(Return(0xCB)).WillOnce(Return(0x8E)).WillOnce(Return(0x02));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    EXPECT_CALL(bus, store_addr(_, 0x00)).Times(1);

    core.cycle_cpu();
}

TEST(CPU_CB_BIT, RES_2_A_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x97));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.A = 0x04;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0x00);
}

TEST(CPU_CB_BIT, RES_2_B_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x90));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.B = 0x04;

    core.cycle_cpu();

    ASSERT_EQ(core.B, 0x00);
}

TEST(CPU_CB_BIT, RES_2_C_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x91));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.C = 0x04;

    core.cycle_cpu();

    ASSERT_EQ(core.C, 0x00);
}

TEST(CPU_CB_BIT, RES_2_D_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x92));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.D = 0x04;

    core.cycle_cpu();

    ASSERT_EQ(core.D, 0x00);
}

TEST(CPU_CB_BIT, RES_2_E_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x93));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.E = 0x04;

    core.cycle_cpu();

    ASSERT_EQ(core.E, 0x00);
}

TEST(CPU_CB_BIT, RES_2_H_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x94));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.H = 0x04;

    core.cycle_cpu();

    ASSERT_EQ(core.H, 0x00);
}

TEST(CPU_CB_BIT, RES_2_L_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x95));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.L = 0x04;

    core.cycle_cpu();

    ASSERT_EQ(core.L, 0x00);
}

TEST(CPU_CB_BIT, RES_2_HL_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(3).WillOnce(Return(0xCB)).WillOnce(Return(0x96)).WillOnce(Return(0x04));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    EXPECT_CALL(bus, store_addr(_, 0x00)).Times(1);

    core.cycle_cpu();
}

TEST(CPU_CB_BIT, RES_3_A_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x9F));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.A = 0x08;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0x00);
}

TEST(CPU_CB_BIT, RES_3_B_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x98));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.B = 0x08;

    core.cycle_cpu();

    ASSERT_EQ(core.B, 0x00);
}

TEST(CPU_CB_BIT, RES_3_C_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x99));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.C = 0x08;

    core.cycle_cpu();

    ASSERT_EQ(core.C, 0x00);
}

TEST(CPU_CB_BIT, RES_3_D_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x9A));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.D = 0x08;

    core.cycle_cpu();

    ASSERT_EQ(core.D, 0x00);
}

TEST(CPU_CB_BIT, RES_3_E_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x9B));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.E = 0x08;

    core.cycle_cpu();

    ASSERT_EQ(core.E, 0x00);
}

TEST(CPU_CB_BIT, RES_3_H_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x9C));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.H = 0x08;

    core.cycle_cpu();

    ASSERT_EQ(core.H, 0x00);
}

TEST(CPU_CB_BIT, RES_3_L_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x9D));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.L = 0x08;

    core.cycle_cpu();

    ASSERT_EQ(core.L, 0x00);
}

TEST(CPU_CB_BIT, RES_3_HL_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(3).WillOnce(Return(0xCB)).WillOnce(Return(0x9E)).WillOnce(Return(0x08));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    EXPECT_CALL(bus, store_addr(_, 0x00)).Times(1);

    core.cycle_cpu();
}

TEST(CPU_CB_BIT, RES_4_A_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xA7));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.A = 0x10;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0x00);
}

TEST(CPU_CB_BIT, RES_4_B_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xA0));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.B = 0x10;

    core.cycle_cpu();

    ASSERT_EQ(core.B, 0x00);
}

TEST(CPU_CB_BIT, RES_4_C_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xA1));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.C = 0x10;

    core.cycle_cpu();

    ASSERT_EQ(core.C, 0x00);
}

TEST(CPU_CB_BIT, RES_4_D_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xA2));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.D = 0x10;

    core.cycle_cpu();

    ASSERT_EQ(core.D, 0x00);
}

TEST(CPU_CB_BIT, RES_4_E_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xA3));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.E = 0x10;

    core.cycle_cpu();

    ASSERT_EQ(core.E, 0x00);
}

TEST(CPU_CB_BIT, RES_4_H_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xA4));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.H = 0x10;

    core.cycle_cpu();

    ASSERT_EQ(core.H, 0x00);
}

TEST(CPU_CB_BIT, RES_4_L_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xA5));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.L = 0x10;

    core.cycle_cpu();

    ASSERT_EQ(core.L, 0x00);
}

TEST(CPU_CB_BIT, RES_4_HL_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(3).WillOnce(Return(0xCB)).WillOnce(Return(0xA6)).WillOnce(Return(0x10));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    EXPECT_CALL(bus, store_addr(_, 0x00)).Times(1);

    core.cycle_cpu();
}

TEST(CPU_CB_BIT, RES_5_A_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xAF));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.A = 0x20;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0x00);
}

TEST(CPU_CB_BIT, RES_5_B_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xA8));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.B = 0x20;

    core.cycle_cpu();

    ASSERT_EQ(core.B, 0x00);
}

TEST(CPU_CB_BIT, RES_5_C_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xA9));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.C = 0x20;

    core.cycle_cpu();

    ASSERT_EQ(core.C, 0x00);
}

TEST(CPU_CB_BIT, RES_5_D_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xAA));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.D = 0x20;

    core.cycle_cpu();

    ASSERT_EQ(core.D, 0x00);
}

TEST(CPU_CB_BIT, RES_5_E_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xAB));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.E = 0x20;

    core.cycle_cpu();

    ASSERT_EQ(core.E, 0x00);
}

TEST(CPU_CB_BIT, RES_5_H_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xAC));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.H = 0x20;

    core.cycle_cpu();

    ASSERT_EQ(core.H, 0x00);
}

TEST(CPU_CB_BIT, RES_5_L_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xAD));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.L = 0x20;

    core.cycle_cpu();

    ASSERT_EQ(core.L, 0x00);
}

TEST(CPU_CB_BIT, RES_5_HL_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(3).WillOnce(Return(0xCB)).WillOnce(Return(0xAE)).WillOnce(Return(0x20));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    EXPECT_CALL(bus, store_addr(_, 0x00)).Times(1);

    core.cycle_cpu();
}

TEST(CPU_CB_BIT, RES_6_A_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xB7));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.A = 0x40;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0x00);
}

TEST(CPU_CB_BIT, RES_6_B_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xB0));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.B = 0x40;

    core.cycle_cpu();

    ASSERT_EQ(core.B, 0x00);
}

TEST(CPU_CB_BIT, RES_6_C_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xB1));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.C = 0x40;

    core.cycle_cpu();

    ASSERT_EQ(core.C, 0x00);
}

TEST(CPU_CB_BIT, RES_6_D_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xB2));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.D = 0x40;

    core.cycle_cpu();

    ASSERT_EQ(core.D, 0x00);
}

TEST(CPU_CB_BIT, RES_6_E_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xB3));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.E = 0x40;

    core.cycle_cpu();

    ASSERT_EQ(core.E, 0x00);
}

TEST(CPU_CB_BIT, RES_6_H_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xB4));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.H = 0x40;

    core.cycle_cpu();

    ASSERT_EQ(core.H, 0x00);
}

TEST(CPU_CB_BIT, RES_6_L_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xB5));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.L = 0x40;

    core.cycle_cpu();

    ASSERT_EQ(core.L, 0x00);
}

TEST(CPU_CB_BIT, RES_6_HL_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(3).WillOnce(Return(0xCB)).WillOnce(Return(0xB6)).WillOnce(Return(0x40));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    EXPECT_CALL(bus, store_addr(_, 0x00)).Times(1);

    core.cycle_cpu();
}

TEST(CPU_CB_BIT, RES_7_A_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xBF));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.A = 0x80;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0x00);
}

TEST(CPU_CB_BIT, RES_7_B_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xB8));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.B = 0x80;

    core.cycle_cpu();

    ASSERT_EQ(core.B, 0x00);
}

TEST(CPU_CB_BIT, RES_7_C_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xB9));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.C = 0x80;

    core.cycle_cpu();

    ASSERT_EQ(core.C, 0x00);
}

TEST(CPU_CB_BIT, RES_7_D_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xBA));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.D = 0x80;

    core.cycle_cpu();

    ASSERT_EQ(core.D, 0x00);
}

TEST(CPU_CB_BIT, RES_7_E_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xBB));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.E = 0x80;

    core.cycle_cpu();

    ASSERT_EQ(core.E, 0x00);
}

TEST(CPU_CB_BIT, RES_7_H_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xBC));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.H = 0x80;

    core.cycle_cpu();

    ASSERT_EQ(core.H, 0x00);
}

TEST(CPU_CB_BIT, RES_7_L_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xBD));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.L = 0x80;

    core.cycle_cpu();

    ASSERT_EQ(core.L, 0x00);
}

TEST(CPU_CB_BIT, RES_7_HL_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(3).WillOnce(Return(0xCB)).WillOnce(Return(0xBE)).WillOnce(Return(0x80));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    EXPECT_CALL(bus, store_addr(_, 0x00)).Times(1);

    core.cycle_cpu();
}