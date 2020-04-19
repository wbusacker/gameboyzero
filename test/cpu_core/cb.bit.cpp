#include <cpu_core.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <irq_controller_mock.h>
#include <mbc1.h>
#include <memory_map_mock.h>

using namespace testing;

TEST(CPU_CB_BIT, BIT_0_A_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x47));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.A = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_0_B_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x40));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.B = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_0_C_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x41));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.C = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_0_D_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x42));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.D = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_0_E_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x43));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.E = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_0_H_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x44));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.H = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_0_L_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x45));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.L = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_0_HL_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(3).WillOnce(Return(0xCB)).WillOnce(Return(0x46)).WillOnce(Return(0x00));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    EXPECT_CALL(bus, store_addr(_, _)).Times(1);

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_0_A_ONE) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x47));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.A = 0x01;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_0_B_ONE) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x40));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.B = 0x01;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_0_C_ONE) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x41));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.C = 0x01;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_0_D_ONE) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x42));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.D = 0x01;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_0_E_ONE) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x43));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.E = 0x01;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_0_H_ONE) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x44));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.H = 0x01;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_0_L_ONE) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x45));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.L = 0x01;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_0_HL_ONE) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(3).WillOnce(Return(0xCB)).WillOnce(Return(0x46)).WillOnce(Return(0x01));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    EXPECT_CALL(bus, store_addr(_, _)).Times(1);

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_1_A_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x4F));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.A = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_1_B_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x48));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.B = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_1_C_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x49));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.C = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_1_D_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x4A));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.D = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_1_E_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x4B));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.E = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_1_H_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x4C));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.H = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_1_L_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x4D));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.L = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_1_HL_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(3).WillOnce(Return(0xCB)).WillOnce(Return(0x4E)).WillOnce(Return(0x00));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    EXPECT_CALL(bus, store_addr(_, _)).Times(1);

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_1_A_ONE) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x4F));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.A = 0x02;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_1_B_ONE) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x48));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.B = 0x02;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_1_C_ONE) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x49));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.C = 0x02;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_1_D_ONE) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x4A));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.D = 0x02;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_1_E_ONE) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x4B));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.E = 0x02;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_1_H_ONE) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x4C));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.H = 0x02;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_1_L_ONE) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x4D));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.L = 0x02;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_1_HL_ONE) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(3).WillOnce(Return(0xCB)).WillOnce(Return(0x4E)).WillOnce(Return(0x02));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    EXPECT_CALL(bus, store_addr(_, _)).Times(1);

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_2_A_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x57));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.A = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_2_B_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x50));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.B = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_2_C_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x51));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.C = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_2_D_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x52));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.D = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_2_E_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x53));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.E = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_2_H_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x54));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.H = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_2_L_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x55));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.L = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_2_HL_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(3).WillOnce(Return(0xCB)).WillOnce(Return(0x56)).WillOnce(Return(0x00));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    EXPECT_CALL(bus, store_addr(_, _)).Times(1);

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_2_A_ONE) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x57));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.A = 0x04;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_2_B_ONE) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x50));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.B = 0x04;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_2_C_ONE) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x51));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.C = 0x04;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_2_D_ONE) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x52));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.D = 0x04;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_2_E_ONE) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x53));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.E = 0x04;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_2_H_ONE) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x54));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.H = 0x04;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_2_L_ONE) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x55));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.L = 0x04;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_2_HL_ONE) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(3).WillOnce(Return(0xCB)).WillOnce(Return(0x56)).WillOnce(Return(0x04));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    EXPECT_CALL(bus, store_addr(_, _)).Times(1);

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_3_A_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x5F));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.A = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_3_B_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x58));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.B = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_3_C_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x59));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.C = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_3_D_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x5A));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.D = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_3_E_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x5B));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.E = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_3_H_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x5C));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.H = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_3_L_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x5D));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.L = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_3_HL_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(3).WillOnce(Return(0xCB)).WillOnce(Return(0x5E)).WillOnce(Return(0x00));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    EXPECT_CALL(bus, store_addr(_, _)).Times(1);

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_3_A_ONE) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x5F));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.A = 0x08;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_3_B_ONE) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x58));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.B = 0x08;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_3_C_ONE) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x59));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.C = 0x08;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_3_D_ONE) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x5A));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.D = 0x08;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_3_E_ONE) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x5B));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.E = 0x08;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_3_H_ONE) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x5C));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.H = 0x08;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_3_L_ONE) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x5D));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.L = 0x08;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_3_HL_ONE) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(3).WillOnce(Return(0xCB)).WillOnce(Return(0x5E)).WillOnce(Return(0x08));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    EXPECT_CALL(bus, store_addr(_, _)).Times(1);

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_4_A_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x67));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.A = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_4_B_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x60));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.B = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_4_C_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x61));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.C = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_4_D_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x62));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.D = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_4_E_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x63));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.E = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_4_H_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x64));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.H = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_4_L_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x65));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.L = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_4_HL_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(3).WillOnce(Return(0xCB)).WillOnce(Return(0x66)).WillOnce(Return(0x00));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    EXPECT_CALL(bus, store_addr(_, _)).Times(1);

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_4_A_ONE) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x67));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.A = 0x10;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_4_B_ONE) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x60));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.B = 0x10;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_4_C_ONE) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x61));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.C = 0x10;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_4_D_ONE) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x62));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.D = 0x10;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_4_E_ONE) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x63));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.E = 0x10;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_4_H_ONE) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x64));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.H = 0x10;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_4_L_ONE) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x65));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.L = 0x10;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_4_HL_ONE) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(3).WillOnce(Return(0xCB)).WillOnce(Return(0x66)).WillOnce(Return(0x10));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    EXPECT_CALL(bus, store_addr(_, _)).Times(1);

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_5_A_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x6F));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.A = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_5_B_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x68));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.B = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_5_C_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x69));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.C = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_5_D_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x6A));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.D = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_5_E_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x6B));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.E = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_5_H_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x6C));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.H = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_5_L_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x6D));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.L = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_5_HL_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(3).WillOnce(Return(0xCB)).WillOnce(Return(0x6E)).WillOnce(Return(0x00));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    EXPECT_CALL(bus, store_addr(_, _)).Times(1);

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_5_A_ONE) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x6F));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.A = 0x20;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_5_B_ONE) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x68));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.B = 0x20;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_5_C_ONE) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x69));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.C = 0x20;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_5_D_ONE) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x6A));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.D = 0x20;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_5_E_ONE) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x6B));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.E = 0x20;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_5_H_ONE) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x6C));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.H = 0x20;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_5_L_ONE) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x6D));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.L = 0x20;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_5_HL_ONE) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(3).WillOnce(Return(0xCB)).WillOnce(Return(0x6E)).WillOnce(Return(0x20));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    EXPECT_CALL(bus, store_addr(_, _)).Times(1);

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_6_A_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x77));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.A = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_6_B_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x70));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.B = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_6_C_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x71));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.C = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_6_D_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x72));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.D = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_6_E_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x73));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.E = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_6_H_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x74));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.H = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_6_L_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x75));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.L = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_6_HL_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(3).WillOnce(Return(0xCB)).WillOnce(Return(0x76)).WillOnce(Return(0x00));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    EXPECT_CALL(bus, store_addr(_, _)).Times(1);

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_6_A_ONE) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x77));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.A = 0x40;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_6_B_ONE) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x70));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.B = 0x40;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_6_C_ONE) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x71));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.C = 0x40;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_6_D_ONE) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x72));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.D = 0x40;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_6_E_ONE) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x73));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.E = 0x40;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_6_H_ONE) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x74));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.H = 0x40;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_6_L_ONE) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x75));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.L = 0x40;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_6_HL_ONE) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(3).WillOnce(Return(0xCB)).WillOnce(Return(0x76)).WillOnce(Return(0x40));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    EXPECT_CALL(bus, store_addr(_, _)).Times(1);

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_7_A_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x7F));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.A = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_7_B_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x78));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.B = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_7_C_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x79));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.C = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_7_D_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x7A));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.D = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_7_E_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x7B));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.E = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_7_H_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x7C));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.H = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_7_L_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x7D));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.L = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_7_HL_ZERO) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(3).WillOnce(Return(0xCB)).WillOnce(Return(0x7E)).WillOnce(Return(0x00));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    EXPECT_CALL(bus, store_addr(_, _)).Times(1);

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_7_A_ONE) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x7F));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.A = 0x80;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_7_B_ONE) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x78));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.B = 0x80;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_7_C_ONE) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x79));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.C = 0x80;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_7_D_ONE) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x7A));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.D = 0x80;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_7_E_ONE) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x7B));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.E = 0x80;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_7_H_ONE) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x7C));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.H = 0x80;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_7_L_ONE) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x7D));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.L = 0x80;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_7_HL_ONE) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(3).WillOnce(Return(0xCB)).WillOnce(Return(0x7E)).WillOnce(Return(0x80));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    EXPECT_CALL(bus, store_addr(_, _)).Times(1);

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}