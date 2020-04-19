#include <cpu_core.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <irq_controller_mock.h>
#include <mbc1.h>
#include <memory_map_mock.h>

using namespace testing;

TEST(ARITH_ADC, ADC_A) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x8F));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.A           = 0x11;
    core.flags.carry = true;
    core.A           = 0x11;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0x23);
}

TEST(ARITH_ADC, ADC_B) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x88));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.A           = 0x11;
    core.flags.carry = true;
    core.B           = 0x11;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0x23);
}

TEST(ARITH_ADC, ADC_C) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x89));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.A           = 0x11;
    core.flags.carry = true;
    core.C           = 0x11;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0x23);
}

TEST(ARITH_ADC, ADC_D) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x8A));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.A           = 0x11;
    core.flags.carry = true;
    core.D           = 0x11;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0x23);
}

TEST(ARITH_ADC, ADC_E) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x8B));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.A           = 0x11;
    core.flags.carry = true;
    core.E           = 0x11;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0x23);
}

TEST(ARITH_ADC, ADC_H) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x8C));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.A           = 0x11;
    core.flags.carry = true;
    core.H           = 0x11;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0x23);
}

TEST(ARITH_ADC, ADC_L) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x8D));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.A           = 0x11;
    core.flags.carry = true;
    core.L           = 0x11;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0x23);
}

TEST(ARITH_ADC, ADC_HL) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0x8E)).WillOnce(Return(0x11));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.flags.carry = true;
    core.A           = 0x11;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0x23);
}

TEST(ARITH_ADC, ADC_n) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCE)).WillOnce(Return(0x11));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.flags.carry = true;
    core.A           = 0x11;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0x23);
}
