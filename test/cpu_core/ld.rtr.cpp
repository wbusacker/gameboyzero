#include <cpu_core.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <irq_controller_mock.h>
#include <mbc1.h>
#include <memory_map_mock.h>

using namespace testing;

const uint8_t TARGET_VAL = 0x80;

TEST(LD_RTR, LD_A_A) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x7F));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.A = 0x00;
    core.A = TARGET_VAL;

    core.cycle_cpu();

    ASSERT_EQ(TARGET_VAL, core.A);
}

TEST(LD_RTR, LD_A_B) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x78));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.A = 0x00;
    core.B = TARGET_VAL;

    core.cycle_cpu();

    ASSERT_EQ(TARGET_VAL, core.A);
}

TEST(LD_RTR, LD_A_C) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x79));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.A = 0x00;
    core.C = TARGET_VAL;

    core.cycle_cpu();

    ASSERT_EQ(TARGET_VAL, core.A);
}

TEST(LD_RTR, LD_A_D) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x7A));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.A = 0x00;
    core.D = TARGET_VAL;

    core.cycle_cpu();

    ASSERT_EQ(TARGET_VAL, core.A);
}

TEST(LD_RTR, LD_A_E) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x7B));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.A = 0x00;
    core.E = TARGET_VAL;

    core.cycle_cpu();

    ASSERT_EQ(TARGET_VAL, core.A);
}

TEST(LD_RTR, LD_A_H) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x7C));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.A = 0x00;
    core.H = TARGET_VAL;

    core.cycle_cpu();

    ASSERT_EQ(TARGET_VAL, core.A);
}

TEST(LD_RTR, LD_A_L) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x7D));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.A = 0x00;
    core.L = TARGET_VAL;

    core.cycle_cpu();

    ASSERT_EQ(TARGET_VAL, core.A);
}

TEST(LD_RTR, LD_A_HL) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0x7E)).WillOnce(Return(TARGET_VAL));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.A = 0x00;

    core.cycle_cpu();

    ASSERT_EQ(TARGET_VAL, core.A);
}

TEST(LD_RTR, LD_B_A) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x47));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.B = 0x00;
    core.A = TARGET_VAL;

    core.cycle_cpu();

    ASSERT_EQ(TARGET_VAL, core.B);
}

TEST(LD_RTR, LD_B_B) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x40));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.B = 0x00;
    core.B = TARGET_VAL;

    core.cycle_cpu();

    ASSERT_EQ(TARGET_VAL, core.B);
}

TEST(LD_RTR, LD_B_C) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x41));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.B = 0x00;
    core.C = TARGET_VAL;

    core.cycle_cpu();

    ASSERT_EQ(TARGET_VAL, core.B);
}

TEST(LD_RTR, LD_B_D) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x42));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.B = 0x00;
    core.D = TARGET_VAL;

    core.cycle_cpu();

    ASSERT_EQ(TARGET_VAL, core.B);
}

TEST(LD_RTR, LD_B_E) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x43));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.B = 0x00;
    core.E = TARGET_VAL;

    core.cycle_cpu();

    ASSERT_EQ(TARGET_VAL, core.B);
}

TEST(LD_RTR, LD_B_H) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x44));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.B = 0x00;
    core.H = TARGET_VAL;

    core.cycle_cpu();

    ASSERT_EQ(TARGET_VAL, core.B);
}

TEST(LD_RTR, LD_B_L) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x45));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.B = 0x00;
    core.L = TARGET_VAL;

    core.cycle_cpu();

    ASSERT_EQ(TARGET_VAL, core.B);
}

TEST(LD_RTR, LD_B_HL) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0x46)).WillOnce(Return(TARGET_VAL));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.B = 0x00;

    core.cycle_cpu();

    ASSERT_EQ(TARGET_VAL, core.B);
}

TEST(LD_RTR, LD_C_A) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x4F));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.C = 0x00;
    core.A = TARGET_VAL;

    core.cycle_cpu();

    ASSERT_EQ(TARGET_VAL, core.C);
}

TEST(LD_RTR, LD_C_B) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x48));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.C = 0x00;
    core.B = TARGET_VAL;

    core.cycle_cpu();

    ASSERT_EQ(TARGET_VAL, core.C);
}

TEST(LD_RTR, LD_C_C) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x49));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.C = 0x00;
    core.C = TARGET_VAL;

    core.cycle_cpu();

    ASSERT_EQ(TARGET_VAL, core.C);
}

TEST(LD_RTR, LD_C_D) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x4A));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.C = 0x00;
    core.D = TARGET_VAL;

    core.cycle_cpu();

    ASSERT_EQ(TARGET_VAL, core.C);
}

TEST(LD_RTR, LD_C_E) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x4B));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.C = 0x00;
    core.E = TARGET_VAL;

    core.cycle_cpu();

    ASSERT_EQ(TARGET_VAL, core.C);
}

TEST(LD_RTR, LD_C_H) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x4C));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.C = 0x00;
    core.H = TARGET_VAL;

    core.cycle_cpu();

    ASSERT_EQ(TARGET_VAL, core.C);
}

TEST(LD_RTR, LD_C_L) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x4D));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.C = 0x00;
    core.L = TARGET_VAL;

    core.cycle_cpu();

    ASSERT_EQ(TARGET_VAL, core.C);
}

TEST(LD_RTR, LD_C_HL) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0x4E)).WillOnce(Return(TARGET_VAL));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.C = 0x00;

    core.cycle_cpu();

    ASSERT_EQ(TARGET_VAL, core.C);
}

TEST(LD_RTR, LD_D_A) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x57));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.D = 0x00;
    core.A = TARGET_VAL;

    core.cycle_cpu();

    ASSERT_EQ(TARGET_VAL, core.D);
}

TEST(LD_RTR, LD_D_B) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x50));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.D = 0x00;
    core.B = TARGET_VAL;

    core.cycle_cpu();

    ASSERT_EQ(TARGET_VAL, core.D);
}

TEST(LD_RTR, LD_D_C) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x51));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.D = 0x00;
    core.C = TARGET_VAL;

    core.cycle_cpu();

    ASSERT_EQ(TARGET_VAL, core.D);
}

TEST(LD_RTR, LD_D_D) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x52));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.D = 0x00;
    core.D = TARGET_VAL;

    core.cycle_cpu();

    ASSERT_EQ(TARGET_VAL, core.D);
}

TEST(LD_RTR, LD_D_E) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x53));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.D = 0x00;
    core.E = TARGET_VAL;

    core.cycle_cpu();

    ASSERT_EQ(TARGET_VAL, core.D);
}

TEST(LD_RTR, LD_D_H) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x54));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.D = 0x00;
    core.H = TARGET_VAL;

    core.cycle_cpu();

    ASSERT_EQ(TARGET_VAL, core.D);
}

TEST(LD_RTR, LD_D_L) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x55));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.D = 0x00;
    core.L = TARGET_VAL;

    core.cycle_cpu();

    ASSERT_EQ(TARGET_VAL, core.D);
}

TEST(LD_RTR, LD_D_HL) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0x56)).WillOnce(Return(TARGET_VAL));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.D = 0x00;

    core.cycle_cpu();

    ASSERT_EQ(TARGET_VAL, core.D);
}

TEST(LD_RTR, LD_E_A) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x5F));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.E = 0x00;
    core.A = TARGET_VAL;

    core.cycle_cpu();

    ASSERT_EQ(TARGET_VAL, core.E);
}

TEST(LD_RTR, LD_E_B) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x58));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.E = 0x00;
    core.B = TARGET_VAL;

    core.cycle_cpu();

    ASSERT_EQ(TARGET_VAL, core.E);
}

TEST(LD_RTR, LD_E_C) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x59));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.E = 0x00;
    core.C = TARGET_VAL;

    core.cycle_cpu();

    ASSERT_EQ(TARGET_VAL, core.E);
}

TEST(LD_RTR, LD_E_D) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x5A));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.E = 0x00;
    core.D = TARGET_VAL;

    core.cycle_cpu();

    ASSERT_EQ(TARGET_VAL, core.E);
}

TEST(LD_RTR, LD_E_E) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x5B));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.E = 0x00;
    core.E = TARGET_VAL;

    core.cycle_cpu();

    ASSERT_EQ(TARGET_VAL, core.E);
}

TEST(LD_RTR, LD_E_H) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x5C));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.E = 0x00;
    core.H = TARGET_VAL;

    core.cycle_cpu();

    ASSERT_EQ(TARGET_VAL, core.E);
}

TEST(LD_RTR, LD_E_L) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x5D));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.E = 0x00;
    core.L = TARGET_VAL;

    core.cycle_cpu();

    ASSERT_EQ(TARGET_VAL, core.E);
}

TEST(LD_RTR, LD_E_HL) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0x5E)).WillOnce(Return(TARGET_VAL));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.E = 0x00;

    core.cycle_cpu();

    ASSERT_EQ(TARGET_VAL, core.E);
}

TEST(LD_RTR, LD_H_A) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x67));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.H = 0x00;
    core.A = TARGET_VAL;

    core.cycle_cpu();

    ASSERT_EQ(TARGET_VAL, core.H);
}

TEST(LD_RTR, LD_H_B) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x60));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.H = 0x00;
    core.B = TARGET_VAL;

    core.cycle_cpu();

    ASSERT_EQ(TARGET_VAL, core.H);
}

TEST(LD_RTR, LD_H_C) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x61));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.H = 0x00;
    core.C = TARGET_VAL;

    core.cycle_cpu();

    ASSERT_EQ(TARGET_VAL, core.H);
}

TEST(LD_RTR, LD_H_D) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x62));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.H = 0x00;
    core.D = TARGET_VAL;

    core.cycle_cpu();

    ASSERT_EQ(TARGET_VAL, core.H);
}

TEST(LD_RTR, LD_H_E) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x63));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.H = 0x00;
    core.E = TARGET_VAL;

    core.cycle_cpu();

    ASSERT_EQ(TARGET_VAL, core.H);
}

TEST(LD_RTR, LD_H_H) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x64));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.H = 0x00;
    core.H = TARGET_VAL;

    core.cycle_cpu();

    ASSERT_EQ(TARGET_VAL, core.H);
}

TEST(LD_RTR, LD_H_L) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x65));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.H = 0x00;
    core.L = TARGET_VAL;

    core.cycle_cpu();

    ASSERT_EQ(TARGET_VAL, core.H);
}

TEST(LD_RTR, LD_H_HL) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0x66)).WillOnce(Return(TARGET_VAL));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.H = 0x00;

    core.cycle_cpu();

    ASSERT_EQ(TARGET_VAL, core.H);
}

TEST(LD_RTR, LD_L_A) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x6F));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.L = 0x00;
    core.A = TARGET_VAL;

    core.cycle_cpu();

    ASSERT_EQ(TARGET_VAL, core.L);
}

TEST(LD_RTR, LD_L_B) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x68));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.L = 0x00;
    core.B = TARGET_VAL;

    core.cycle_cpu();

    ASSERT_EQ(TARGET_VAL, core.L);
}

TEST(LD_RTR, LD_L_C) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x69));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.L = 0x00;
    core.C = TARGET_VAL;

    core.cycle_cpu();

    ASSERT_EQ(TARGET_VAL, core.L);
}

TEST(LD_RTR, LD_L_D) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x6A));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.L = 0x00;
    core.D = TARGET_VAL;

    core.cycle_cpu();

    ASSERT_EQ(TARGET_VAL, core.L);
}

TEST(LD_RTR, LD_L_E) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x6B));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.L = 0x00;
    core.E = TARGET_VAL;

    core.cycle_cpu();

    ASSERT_EQ(TARGET_VAL, core.L);
}

TEST(LD_RTR, LD_L_H) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x6C));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.L = 0x00;
    core.H = TARGET_VAL;

    core.cycle_cpu();

    ASSERT_EQ(TARGET_VAL, core.L);
}

TEST(LD_RTR, LD_L_L) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x6D));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.L = 0x00;
    core.L = TARGET_VAL;

    core.cycle_cpu();

    ASSERT_EQ(TARGET_VAL, core.L);
}

TEST(LD_RTR, LD_L_HL) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0x6E)).WillOnce(Return(TARGET_VAL));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.L = 0x00;

    core.cycle_cpu();

    ASSERT_EQ(TARGET_VAL, core.L);
}

TEST(LD_RTR, LD_HL_A) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x77));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    EXPECT_CALL(bus, store_addr(_, TARGET_VAL)).Times(1);

    core.A = TARGET_VAL;

    core.cycle_cpu();
}

TEST(LD_RTR, LD_HL_B) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x70));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    EXPECT_CALL(bus, store_addr(_, TARGET_VAL)).Times(1);

    core.B = TARGET_VAL;

    core.cycle_cpu();
}

TEST(LD_RTR, LD_HL_C) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x71));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    EXPECT_CALL(bus, store_addr(_, TARGET_VAL)).Times(1);

    core.C = TARGET_VAL;

    core.cycle_cpu();
}

TEST(LD_RTR, LD_HL_D) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x72));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    EXPECT_CALL(bus, store_addr(_, TARGET_VAL)).Times(1);

    core.D = TARGET_VAL;

    core.cycle_cpu();
}

TEST(LD_RTR, LD_HL_E) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x73));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    EXPECT_CALL(bus, store_addr(_, TARGET_VAL)).Times(1);

    core.E = TARGET_VAL;

    core.cycle_cpu();
}

TEST(LD_RTR, LD_HL_H) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x74));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    EXPECT_CALL(bus, store_addr(_, TARGET_VAL)).Times(1);

    core.H = TARGET_VAL;

    core.cycle_cpu();
}

TEST(LD_RTR, LD_HL_L) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x75));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    EXPECT_CALL(bus, store_addr(_, TARGET_VAL)).Times(1);

    core.L = TARGET_VAL;

    core.cycle_cpu();
}