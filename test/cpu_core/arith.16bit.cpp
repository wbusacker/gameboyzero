#include <cpu_core.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <irq_controller_mock.h>
#include <mbc1.h>
#include <memory_map_mock.h>

using namespace testing;

TEST(CPU_16_BIT, INC_BC) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x03));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.B = 0x1;
    core.C = 0xff;
    core.cycle_cpu();

    ASSERT_EQ(core.B, 0x2);
    ASSERT_EQ(core.C, 0x0);
}

TEST(CPU_16_BIT, INC_DE) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x13));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.D = 0x1;
    core.E = 0xff;
    core.cycle_cpu();

    ASSERT_EQ(core.D, 0x2);
    ASSERT_EQ(core.E, 0x0);
}

TEST(CPU_16_BIT, INC_HL) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x23));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.H = 0x1;
    core.L = 0xff;
    core.cycle_cpu();

    ASSERT_EQ(core.H, 0x2);
    ASSERT_EQ(core.L, 0x0);
}

TEST(CPU_16_BIT, INC_SP) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x33));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.stack_pointer = 0x1;
    core.cycle_cpu();

    ASSERT_EQ(core.stack_pointer, 0x2);
}

TEST(CPU_16_BIT, DEC_BC) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x0B));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.B = 0x01;
    core.C = 0x00;
    core.cycle_cpu();

    ASSERT_EQ(core.B, 0x0);
    ASSERT_EQ(core.C, 0xff);
}

TEST(CPU_16_BIT, DEC_DE) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x1B));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.D = 0x01;
    core.E = 0x00;
    core.cycle_cpu();

    ASSERT_EQ(core.D, 0x0);
    ASSERT_EQ(core.E, 0xff);
}

TEST(CPU_16_BIT, DEC_HL) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x2B));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.H = 0x1;
    core.L = 0x00;
    core.cycle_cpu();

    ASSERT_EQ(core.H, 0x0);
    ASSERT_EQ(core.L, 0xff);
}

TEST(CPU_16_BIT, DEC_SP) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x3B));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.stack_pointer = 0x01;
    core.cycle_cpu();

    ASSERT_EQ(core.stack_pointer, 0x00);
}

TEST(CPU_16_BIT, ADD_HL_BC) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x09));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.H = 0x01;
    core.L = 0x23;
    core.B = 0x01;
    core.C = 0x23;
    core.cycle_cpu();

    ASSERT_EQ(core.H, 0x02);
    ASSERT_EQ(core.L, 0x46);
}

TEST(CPU_16_BIT, ADD_HL_DE) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x19));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.H = 0x01;
    core.L = 0x23;
    core.D = 0x01;
    core.E = 0x23;
    core.cycle_cpu();
    ASSERT_EQ(core.H, 0x02);
    ASSERT_EQ(core.L, 0x46);
}

TEST(CPU_16_BIT, ADD_HL_HL) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x29));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.H = 0x01;
    core.L = 0x23;
    core.H = 0x01;
    core.L = 0x23;
    core.cycle_cpu();

    ASSERT_EQ(core.H, 0x02);
    ASSERT_EQ(core.L, 0x46);
}

TEST(CPU_16_BIT, ADD_HL_SP) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x39));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.H             = 0x01;
    core.L             = 0x23;
    core.stack_pointer = 0x0123;
    core.cycle_cpu();

    ASSERT_EQ(core.H, 0x02);
    ASSERT_EQ(core.L, 0x46);
}

TEST(CPU_16_BIT, ADD_SP_n) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0xE8)).WillOnce(Return(0x01));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.stack_pointer = 0x0123;
    core.cycle_cpu();

    ASSERT_EQ(core.stack_pointer, 0x0124);
}