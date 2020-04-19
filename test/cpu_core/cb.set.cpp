#include <cpu_core.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <irq_controller_mock.h>
#include <mbc1.h>
#include <memory_map_mock.h>

using namespace testing;

TEST(CPU_CB_BIT, SET_0_A_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xC7));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.A = 0x00;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0x01);
}

TEST(CPU_CB_BIT, SET_0_B_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xC0));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.B = 0x00;

    core.cycle_cpu();

    ASSERT_EQ(core.B, 0x01);
}

TEST(CPU_CB_BIT, SET_0_C_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xC1));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.C = 0x00;

    core.cycle_cpu();

    ASSERT_EQ(core.C, 0x01);
}

TEST(CPU_CB_BIT, SET_0_D_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xC2));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.D = 0x00;

    core.cycle_cpu();

    ASSERT_EQ(core.D, 0x01);
}

TEST(CPU_CB_BIT, SET_0_E_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xC3));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.E = 0x00;

    core.cycle_cpu();

    ASSERT_EQ(core.E, 0x01);
}

TEST(CPU_CB_BIT, SET_0_H_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xC4));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.H = 0x00;

    core.cycle_cpu();

    ASSERT_EQ(core.H, 0x01);
}

TEST(CPU_CB_BIT, SET_0_L_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xC5));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.L = 0x00;

    core.cycle_cpu();

    ASSERT_EQ(core.L, 0x01);
}

TEST(CPU_CB_BIT, SET_0_HL_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(3).WillOnce(Return(0xCB)).WillOnce(Return(0xC6)).WillOnce(Return(0x00));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    EXPECT_CALL(bus, store_addr(_, 0x01)).Times(1);

    core.cycle_cpu();
}

TEST(CPU_CB_BIT, SET_1_A_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xCF));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.A = 0x00;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0x02);
}

TEST(CPU_CB_BIT, SET_1_B_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xC8));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.B = 0x00;

    core.cycle_cpu();

    ASSERT_EQ(core.B, 0x02);
}

TEST(CPU_CB_BIT, SET_1_C_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xC9));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.C = 0x00;

    core.cycle_cpu();

    ASSERT_EQ(core.C, 0x02);
}

TEST(CPU_CB_BIT, SET_1_D_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xCA));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.D = 0x00;

    core.cycle_cpu();

    ASSERT_EQ(core.D, 0x02);
}

TEST(CPU_CB_BIT, SET_1_E_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xCB));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.E = 0x00;

    core.cycle_cpu();

    ASSERT_EQ(core.E, 0x02);
}

TEST(CPU_CB_BIT, SET_1_H_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xCC));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.H = 0x00;

    core.cycle_cpu();

    ASSERT_EQ(core.H, 0x02);
}

TEST(CPU_CB_BIT, SET_1_L_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xCD));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.L = 0x00;

    core.cycle_cpu();

    ASSERT_EQ(core.L, 0x02);
}

TEST(CPU_CB_BIT, SET_1_HL_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(3).WillOnce(Return(0xCB)).WillOnce(Return(0xCE)).WillOnce(Return(0x00));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    EXPECT_CALL(bus, store_addr(_, 0x02)).Times(1);

    core.cycle_cpu();
}

TEST(CPU_CB_BIT, SET_2_A_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xD7));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.A = 0x00;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0x04);
}

TEST(CPU_CB_BIT, SET_2_B_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xD0));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.B = 0x00;

    core.cycle_cpu();

    ASSERT_EQ(core.B, 0x04);
}

TEST(CPU_CB_BIT, SET_2_C_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xD1));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.C = 0x00;

    core.cycle_cpu();

    ASSERT_EQ(core.C, 0x04);
}

TEST(CPU_CB_BIT, SET_2_D_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xD2));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.D = 0x00;

    core.cycle_cpu();

    ASSERT_EQ(core.D, 0x04);
}

TEST(CPU_CB_BIT, SET_2_E_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xD3));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.E = 0x00;

    core.cycle_cpu();

    ASSERT_EQ(core.E, 0x04);
}

TEST(CPU_CB_BIT, SET_2_H_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xD4));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.H = 0x00;

    core.cycle_cpu();

    ASSERT_EQ(core.H, 0x04);
}

TEST(CPU_CB_BIT, SET_2_L_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xD5));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.L = 0x00;

    core.cycle_cpu();

    ASSERT_EQ(core.L, 0x04);
}

TEST(CPU_CB_BIT, SET_2_HL_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(3).WillOnce(Return(0xCB)).WillOnce(Return(0xD6)).WillOnce(Return(0x00));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    EXPECT_CALL(bus, store_addr(_, 0x04)).Times(1);

    core.cycle_cpu();
}

TEST(CPU_CB_BIT, SET_3_A_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xDF));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.A = 0x00;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0x08);
}

TEST(CPU_CB_BIT, SET_3_B_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xD8));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.B = 0x00;

    core.cycle_cpu();

    ASSERT_EQ(core.B, 0x08);
}

TEST(CPU_CB_BIT, SET_3_C_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xD9));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.C = 0x00;

    core.cycle_cpu();

    ASSERT_EQ(core.C, 0x08);
}

TEST(CPU_CB_BIT, SET_3_D_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xDA));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.D = 0x00;

    core.cycle_cpu();

    ASSERT_EQ(core.D, 0x08);
}

TEST(CPU_CB_BIT, SET_3_E_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xDB));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.E = 0x00;

    core.cycle_cpu();

    ASSERT_EQ(core.E, 0x08);
}

TEST(CPU_CB_BIT, SET_3_H_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xDC));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.H = 0x00;

    core.cycle_cpu();

    ASSERT_EQ(core.H, 0x08);
}

TEST(CPU_CB_BIT, SET_3_L_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xDD));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.L = 0x00;

    core.cycle_cpu();

    ASSERT_EQ(core.L, 0x08);
}

TEST(CPU_CB_BIT, SET_3_HL_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(3).WillOnce(Return(0xCB)).WillOnce(Return(0xDE)).WillOnce(Return(0x00));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    EXPECT_CALL(bus, store_addr(_, 0x08)).Times(1);

    core.cycle_cpu();
}

TEST(CPU_CB_BIT, SET_4_A_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xE7));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.A = 0x00;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0x10);
}

TEST(CPU_CB_BIT, SET_4_B_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xE0));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.B = 0x00;

    core.cycle_cpu();

    ASSERT_EQ(core.B, 0x10);
}

TEST(CPU_CB_BIT, SET_4_C_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xE1));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.C = 0x00;

    core.cycle_cpu();

    ASSERT_EQ(core.C, 0x10);
}

TEST(CPU_CB_BIT, SET_4_D_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xE2));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.D = 0x00;

    core.cycle_cpu();

    ASSERT_EQ(core.D, 0x10);
}

TEST(CPU_CB_BIT, SET_4_E_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xE3));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.E = 0x00;

    core.cycle_cpu();

    ASSERT_EQ(core.E, 0x10);
}

TEST(CPU_CB_BIT, SET_4_H_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xE4));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.H = 0x00;

    core.cycle_cpu();

    ASSERT_EQ(core.H, 0x10);
}

TEST(CPU_CB_BIT, SET_4_L_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xE5));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.L = 0x00;

    core.cycle_cpu();

    ASSERT_EQ(core.L, 0x10);
}

TEST(CPU_CB_BIT, SET_4_HL_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(3).WillOnce(Return(0xCB)).WillOnce(Return(0xE6)).WillOnce(Return(0x00));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    EXPECT_CALL(bus, store_addr(_, 0x10)).Times(1);

    core.cycle_cpu();
}

TEST(CPU_CB_BIT, SET_5_A_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xEF));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.A = 0x00;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0x20);
}

TEST(CPU_CB_BIT, SET_5_B_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xE8));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.B = 0x00;

    core.cycle_cpu();

    ASSERT_EQ(core.B, 0x20);
}

TEST(CPU_CB_BIT, SET_5_C_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xE9));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.C = 0x00;

    core.cycle_cpu();

    ASSERT_EQ(core.C, 0x20);
}

TEST(CPU_CB_BIT, SET_5_D_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xEA));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.D = 0x00;

    core.cycle_cpu();

    ASSERT_EQ(core.D, 0x20);
}

TEST(CPU_CB_BIT, SET_5_E_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xEB));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.E = 0x00;

    core.cycle_cpu();

    ASSERT_EQ(core.E, 0x20);
}

TEST(CPU_CB_BIT, SET_5_H_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xEC));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.H = 0x00;

    core.cycle_cpu();

    ASSERT_EQ(core.H, 0x20);
}

TEST(CPU_CB_BIT, SET_5_L_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xED));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.L = 0x00;

    core.cycle_cpu();

    ASSERT_EQ(core.L, 0x20);
}

TEST(CPU_CB_BIT, SET_5_HL_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(3).WillOnce(Return(0xCB)).WillOnce(Return(0xEE)).WillOnce(Return(0x00));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    EXPECT_CALL(bus, store_addr(_, 0x20)).Times(1);

    core.cycle_cpu();
}

TEST(CPU_CB_BIT, SET_6_A_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xF7));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.A = 0x00;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0x40);
}

TEST(CPU_CB_BIT, SET_6_B_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xF0));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.B = 0x00;

    core.cycle_cpu();

    ASSERT_EQ(core.B, 0x40);
}

TEST(CPU_CB_BIT, SET_6_C_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xF1));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.C = 0x00;

    core.cycle_cpu();

    ASSERT_EQ(core.C, 0x40);
}

TEST(CPU_CB_BIT, SET_6_D_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xF2));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.D = 0x00;

    core.cycle_cpu();

    ASSERT_EQ(core.D, 0x40);
}

TEST(CPU_CB_BIT, SET_6_E_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xF3));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.E = 0x00;

    core.cycle_cpu();

    ASSERT_EQ(core.E, 0x40);
}

TEST(CPU_CB_BIT, SET_6_H_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xF4));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.H = 0x00;

    core.cycle_cpu();

    ASSERT_EQ(core.H, 0x40);
}

TEST(CPU_CB_BIT, SET_6_L_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xF5));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.L = 0x00;

    core.cycle_cpu();

    ASSERT_EQ(core.L, 0x40);
}

TEST(CPU_CB_BIT, SET_6_HL_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(3).WillOnce(Return(0xCB)).WillOnce(Return(0xF6)).WillOnce(Return(0x00));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    EXPECT_CALL(bus, store_addr(_, 0x40)).Times(1);

    core.cycle_cpu();
}

TEST(CPU_CB_BIT, SET_7_A_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xFF));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.A = 0x00;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0x80);
}

TEST(CPU_CB_BIT, SET_7_B_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xF8));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.B = 0x00;

    core.cycle_cpu();

    ASSERT_EQ(core.B, 0x80);
}

TEST(CPU_CB_BIT, SET_7_C_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xF9));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.C = 0x00;

    core.cycle_cpu();

    ASSERT_EQ(core.C, 0x80);
}

TEST(CPU_CB_BIT, SET_7_D_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xFA));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.D = 0x00;

    core.cycle_cpu();

    ASSERT_EQ(core.D, 0x80);
}

TEST(CPU_CB_BIT, SET_7_E_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xFB));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.E = 0x00;

    core.cycle_cpu();

    ASSERT_EQ(core.E, 0x80);
}

TEST(CPU_CB_BIT, SET_7_H_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xFC));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.H = 0x00;

    core.cycle_cpu();

    ASSERT_EQ(core.H, 0x80);
}

TEST(CPU_CB_BIT, SET_7_L_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0xFD));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.L = 0x00;

    core.cycle_cpu();

    ASSERT_EQ(core.L, 0x80);
}

TEST(CPU_CB_BIT, SET_7_HL_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(3).WillOnce(Return(0xCB)).WillOnce(Return(0xFE)).WillOnce(Return(0x00));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    EXPECT_CALL(bus, store_addr(_, 0x80)).Times(1);

    core.cycle_cpu();
}