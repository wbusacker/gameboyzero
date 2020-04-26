#include <cpu_core.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <irq_controller_mock.h>
#include <mbc1.h>
#include <memory_map_mock.h>

using namespace testing;

const uint8_t  TARGET_ADDR   = 0xA5;
const uint16_t TARGET_ADDR_H = 0x5A;
const uint8_t  TARGET_VAL    = 0x77;

TEST(LD_SPECIAL, LDH_n_A) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).WillOnce(Return(0xE0)).WillOnce(Return(TARGET_ADDR));

    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    EXPECT_CALL(bus, store_addr(0xFF00 + TARGET_ADDR, TARGET_VAL));

    core.A = TARGET_VAL;

    core.cycle_cpu();
}

TEST(LD_SPECIAL, LDH_A_n) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).WillOnce(Return(0xF0)).WillOnce(Return(TARGET_ADDR));

    EXPECT_CALL(bus, fetch_addr(0xFF00 + TARGET_ADDR)).WillOnce(Return(TARGET_VAL));

    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.A = 0x0;

    core.cycle_cpu();

    EXPECT_EQ(core.A, TARGET_VAL);
}

TEST(LD_SPECIAL, LDH_C_A) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).WillOnce(Return(0xE2));

    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    EXPECT_CALL(bus, store_addr(0xFF00 + TARGET_ADDR, TARGET_VAL));

    core.A = TARGET_VAL;
    core.C = TARGET_ADDR;

    core.cycle_cpu();
}

TEST(LD_SPECIAL, LDH_A_C) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).WillOnce(Return(0xF2));

    EXPECT_CALL(bus, fetch_addr(0xFF00 + TARGET_ADDR)).WillOnce(Return(TARGET_VAL));

    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.A = 0x0;
    core.C = TARGET_ADDR;

    core.cycle_cpu();

    EXPECT_EQ(core.A, TARGET_VAL);
}

TEST(LD_SPECIAL, LDH_nn_A) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
      .WillOnce(Return(0xEA))
      .WillOnce(Return(TARGET_ADDR))
      .WillOnce(Return(TARGET_ADDR_H));

    EXPECT_CALL(bus, store_addr((TARGET_ADDR_H << 8) + TARGET_ADDR, TARGET_VAL));

    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.A = TARGET_VAL;

    core.cycle_cpu();
}

TEST(LD_SPECIAL, LDH_A_nn) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
      .WillOnce(Return(0xFA))
      .WillOnce(Return(TARGET_ADDR))
      .WillOnce(Return(TARGET_ADDR_H));

    EXPECT_CALL(bus, fetch_addr((TARGET_ADDR_H << 8) + TARGET_ADDR)).WillOnce(Return(TARGET_VAL));

    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.A = 0x0;

    core.cycle_cpu();

    EXPECT_EQ(core.A, TARGET_VAL);
}