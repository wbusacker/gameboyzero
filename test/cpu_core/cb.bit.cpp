#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <cpu_core.h>
#include <mbc1.h>
#include <memory_map_mock.h>
#include <irq_controller_mock.h>

using namespace testing;

TEST(CPU_CB_BIT, BIT_0_A_ZERO){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x47));

    core.A = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_0_B_ZERO){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x40));

    core.B = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_0_C_ZERO){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x41));

    core.C = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_0_D_ZERO){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x42));

    core.D = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_0_E_ZERO){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x43));

    core.E = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_0_H_ZERO){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x44));

    core.H = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_0_L_ZERO){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x45));

    core.L = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_0_HL_ZERO){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(3)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x46))
        .WillOnce(Return(0x00));

    EXPECT_CALL(bus, store_addr(_,_))
        .Times(1);

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_0_A_ONE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x47));

    core.A = 0x01;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_0_B_ONE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x40));

    core.B = 0x01;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_0_C_ONE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x41));

    core.C = 0x01;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_0_D_ONE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x42));

    core.D = 0x01;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_0_E_ONE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x43));

    core.E = 0x01;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_0_H_ONE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x44));

    core.H = 0x01;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_0_L_ONE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x45));

    core.L = 0x01;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_0_HL_ONE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(3)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x46))
        .WillOnce(Return(0x01));

    EXPECT_CALL(bus, store_addr(_,_))
        .Times(1);

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_1_A_ZERO){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x4F));

    core.A = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_1_B_ZERO){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x48));

    core.B = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_1_C_ZERO){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x49));

    core.C = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_1_D_ZERO){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x4A));

    core.D = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_1_E_ZERO){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x4B));

    core.E = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_1_H_ZERO){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x4C));

    core.H = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_1_L_ZERO){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x4D));

    core.L = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_1_HL_ZERO){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(3)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x4E))
        .WillOnce(Return(0x00));

    EXPECT_CALL(bus, store_addr(_,_))
        .Times(1);

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_1_A_ONE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x4F));

    core.A = 0x02;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_1_B_ONE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x48));

    core.B = 0x02;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_1_C_ONE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x49));

    core.C = 0x02;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_1_D_ONE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x4A));

    core.D = 0x02;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_1_E_ONE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x4B));

    core.E = 0x02;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_1_H_ONE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x4C));

    core.H = 0x02;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_1_L_ONE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x4D));

    core.L = 0x02;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_1_HL_ONE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(3)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x4E))
        .WillOnce(Return(0x02));

    EXPECT_CALL(bus, store_addr(_,_))
        .Times(1);

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_2_A_ZERO){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x57));

    core.A = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_2_B_ZERO){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x50));

    core.B = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_2_C_ZERO){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x51));

    core.C = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_2_D_ZERO){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x52));

    core.D = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_2_E_ZERO){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x53));

    core.E = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_2_H_ZERO){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x54));

    core.H = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_2_L_ZERO){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x55));

    core.L = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_2_HL_ZERO){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(3)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x56))
        .WillOnce(Return(0x00));

    EXPECT_CALL(bus, store_addr(_,_))
        .Times(1);

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_2_A_ONE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x57));

    core.A = 0x04;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_2_B_ONE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x50));

    core.B = 0x04;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_2_C_ONE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x51));

    core.C = 0x04;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_2_D_ONE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x52));

    core.D = 0x04;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_2_E_ONE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x53));

    core.E = 0x04;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_2_H_ONE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x54));

    core.H = 0x04;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_2_L_ONE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x55));

    core.L = 0x04;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_2_HL_ONE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(3)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x56))
        .WillOnce(Return(0x04));

    EXPECT_CALL(bus, store_addr(_,_))
        .Times(1);

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_3_A_ZERO){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x5F));

    core.A = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_3_B_ZERO){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x58));

    core.B = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_3_C_ZERO){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x59));

    core.C = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_3_D_ZERO){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x5A));

    core.D = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_3_E_ZERO){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x5B));

    core.E = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_3_H_ZERO){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x5C));

    core.H = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_3_L_ZERO){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x5D));

    core.L = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_3_HL_ZERO){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(3)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x5E))
        .WillOnce(Return(0x00));

    EXPECT_CALL(bus, store_addr(_,_))
        .Times(1);

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_3_A_ONE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x5F));

    core.A = 0x08;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_3_B_ONE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x58));

    core.B = 0x08;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_3_C_ONE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x59));

    core.C = 0x08;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_3_D_ONE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x5A));

    core.D = 0x08;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_3_E_ONE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x5B));

    core.E = 0x08;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_3_H_ONE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x5C));

    core.H = 0x08;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_3_L_ONE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x5D));

    core.L = 0x08;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_3_HL_ONE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(3)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x5E))
        .WillOnce(Return(0x08));

    EXPECT_CALL(bus, store_addr(_,_))
        .Times(1);

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_4_A_ZERO){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x67));

    core.A = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_4_B_ZERO){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x60));

    core.B = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_4_C_ZERO){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x61));

    core.C = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_4_D_ZERO){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x62));

    core.D = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_4_E_ZERO){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x63));

    core.E = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_4_H_ZERO){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x64));

    core.H = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_4_L_ZERO){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x65));

    core.L = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_4_HL_ZERO){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(3)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x66))
        .WillOnce(Return(0x00));

    EXPECT_CALL(bus, store_addr(_,_))
        .Times(1);

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_4_A_ONE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x67));

    core.A = 0x10;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_4_B_ONE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x60));

    core.B = 0x10;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_4_C_ONE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x61));

    core.C = 0x10;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_4_D_ONE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x62));

    core.D = 0x10;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_4_E_ONE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x63));

    core.E = 0x10;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_4_H_ONE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x64));

    core.H = 0x10;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_4_L_ONE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x65));

    core.L = 0x10;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_4_HL_ONE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(3)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x66))
        .WillOnce(Return(0x10));

    EXPECT_CALL(bus, store_addr(_,_))
        .Times(1);

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_5_A_ZERO){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x6F));

    core.A = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_5_B_ZERO){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x68));

    core.B = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_5_C_ZERO){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x69));

    core.C = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_5_D_ZERO){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x6A));

    core.D = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_5_E_ZERO){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x6B));

    core.E = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_5_H_ZERO){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x6C));

    core.H = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_5_L_ZERO){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x6D));

    core.L = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_5_HL_ZERO){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(3)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x6E))
        .WillOnce(Return(0x00));

    EXPECT_CALL(bus, store_addr(_,_))
        .Times(1);

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_5_A_ONE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x6F));

    core.A = 0x20;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_5_B_ONE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x68));

    core.B = 0x20;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_5_C_ONE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x69));

    core.C = 0x20;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_5_D_ONE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x6A));

    core.D = 0x20;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_5_E_ONE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x6B));

    core.E = 0x20;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_5_H_ONE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x6C));

    core.H = 0x20;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_5_L_ONE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x6D));

    core.L = 0x20;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_5_HL_ONE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(3)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x6E))
        .WillOnce(Return(0x20));

    EXPECT_CALL(bus, store_addr(_,_))
        .Times(1);

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_6_A_ZERO){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x77));

    core.A = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_6_B_ZERO){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x70));

    core.B = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_6_C_ZERO){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x71));

    core.C = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_6_D_ZERO){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x72));

    core.D = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_6_E_ZERO){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x73));

    core.E = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_6_H_ZERO){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x74));

    core.H = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_6_L_ZERO){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x75));

    core.L = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_6_HL_ZERO){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(3)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x76))
        .WillOnce(Return(0x00));

    EXPECT_CALL(bus, store_addr(_,_))
        .Times(1);

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_6_A_ONE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x77));

    core.A = 0x40;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_6_B_ONE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x70));

    core.B = 0x40;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_6_C_ONE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x71));

    core.C = 0x40;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_6_D_ONE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x72));

    core.D = 0x40;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_6_E_ONE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x73));

    core.E = 0x40;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_6_H_ONE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x74));

    core.H = 0x40;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_6_L_ONE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x75));

    core.L = 0x40;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_6_HL_ONE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(3)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x76))
        .WillOnce(Return(0x40));

    EXPECT_CALL(bus, store_addr(_,_))
        .Times(1);

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_7_A_ZERO){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x7F));

    core.A = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_7_B_ZERO){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x78));

    core.B = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_7_C_ZERO){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x79));

    core.C = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_7_D_ZERO){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x7A));

    core.D = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_7_E_ZERO){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x7B));

    core.E = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_7_H_ZERO){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x7C));

    core.H = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_7_L_ZERO){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x7D));

    core.L = 0x00;

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_7_HL_ZERO){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(3)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x7E))
        .WillOnce(Return(0x00));

    EXPECT_CALL(bus, store_addr(_,_))
        .Times(1);

    core.flags.zero = false;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, true);
}

TEST(CPU_CB_BIT, BIT_7_A_ONE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x7F));

    core.A = 0x80;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_7_B_ONE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x78));

    core.B = 0x80;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_7_C_ONE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x79));

    core.C = 0x80;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_7_D_ONE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x7A));

    core.D = 0x80;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_7_E_ONE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x7B));

    core.E = 0x80;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_7_H_ONE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x7C));

    core.H = 0x80;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_7_L_ONE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(2)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x7D));

    core.L = 0x80;

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}

TEST(CPU_CB_BIT, BIT_7_HL_ONE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(3)
        .WillOnce(Return(0xCB))
        .WillOnce(Return(0x7E))
        .WillOnce(Return(0x80));

    EXPECT_CALL(bus, store_addr(_,_))
        .Times(1);

    core.flags.zero = true;

    core.cycle_cpu();

    ASSERT_EQ(core.flags.zero, false);
}