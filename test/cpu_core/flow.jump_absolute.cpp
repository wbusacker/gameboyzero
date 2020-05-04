#include <cpu_core.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <irq_controller_mock.h>
#include <mbc1.h>
#include <memory_map_mock.h>

using namespace testing;

const uint8_t  START_ADDR_H = 0x56;
const uint8_t  START_ADDR_L = 0x78;
const uint16_t START_ADDR   = (static_cast<uint16_t>(START_ADDR_H) << 8) | START_ADDR_L;

const uint8_t  TARGET_ADDR_H = 0x12;
const uint8_t  TARGET_ADDR_L = 0x34;
const uint16_t TARGET_ADDR   = (static_cast<uint16_t>(TARGET_ADDR_H) << 8) | TARGET_ADDR_L;

const uint8_t JUMP_OFFSET = 0x77;

TEST(FLOW_CONTROL, JP_nn) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
      .WillOnce(Return(0xC3))
      .WillOnce(Return(TARGET_ADDR_L))
      .WillOnce(Return(TARGET_ADDR_H));

    core.program_counter = START_ADDR;
    core.cycle_cpu();

    ASSERT_EQ(core.program_counter, TARGET_ADDR);
}

TEST(FLOW_CONTROL, JP_NZ_nn_taken) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
      .WillOnce(Return(0xC2))
      .WillOnce(Return(TARGET_ADDR_L))
      .WillOnce(Return(TARGET_ADDR_H));

    core.program_counter = START_ADDR;
    core.flags.zero      = false;
    core.cycle_cpu();

    ASSERT_EQ(core.program_counter, TARGET_ADDR);
}

TEST(FLOW_CONTROL, JP_NC_nn_taken) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
      .WillOnce(Return(0xD2))
      .WillOnce(Return(TARGET_ADDR_L))
      .WillOnce(Return(TARGET_ADDR_H));

    core.program_counter = START_ADDR;
    core.flags.carry     = false;
    core.cycle_cpu();

    ASSERT_EQ(core.program_counter, TARGET_ADDR);
}

TEST(FLOW_CONTROL, JP_Z_nn_taken) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
      .WillOnce(Return(0xCA))
      .WillOnce(Return(TARGET_ADDR_L))
      .WillOnce(Return(TARGET_ADDR_H));

    core.program_counter = START_ADDR;
    core.flags.zero      = true;
    core.cycle_cpu();

    ASSERT_EQ(core.program_counter, TARGET_ADDR);
}

TEST(FLOW_CONTROL, JP_C_nn_taken) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
      .WillOnce(Return(0xDA))
      .WillOnce(Return(TARGET_ADDR_L))
      .WillOnce(Return(TARGET_ADDR_H));

    core.program_counter = START_ADDR;
    core.flags.carry     = true;
    core.cycle_cpu();

    ASSERT_EQ(core.program_counter, TARGET_ADDR);
}

TEST(FLOW_CONTROL, JP_NZ_nn_not_taken) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
      .WillOnce(Return(0xC2))
      .WillOnce(Return(TARGET_ADDR_L))
      .WillOnce(Return(TARGET_ADDR_H));

    core.program_counter = START_ADDR;
    core.flags.zero      = true;
    core.cycle_cpu();

    ASSERT_EQ(core.program_counter, START_ADDR + 3);
}

TEST(FLOW_CONTROL, JP_NC_nn_not_taken) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
      .WillOnce(Return(0xD2))
      .WillOnce(Return(TARGET_ADDR_L))
      .WillOnce(Return(TARGET_ADDR_H));

    core.program_counter = START_ADDR;
    core.flags.carry     = true;
    core.cycle_cpu();

    ASSERT_EQ(core.program_counter, START_ADDR + 3);
}

TEST(FLOW_CONTROL, JP_Z_nn_not_taken) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
      .WillOnce(Return(0xCA))
      .WillOnce(Return(TARGET_ADDR_L))
      .WillOnce(Return(TARGET_ADDR_H));

    core.program_counter = START_ADDR;
    core.flags.zero      = false;
    core.cycle_cpu();

    ASSERT_EQ(core.program_counter, START_ADDR + 3);
}

TEST(FLOW_CONTROL, JP_C_nn_not_taken) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
      .WillOnce(Return(0xDA))
      .WillOnce(Return(TARGET_ADDR_L))
      .WillOnce(Return(TARGET_ADDR_H));

    core.program_counter = START_ADDR;
    core.flags.carry     = false;
    core.cycle_cpu();

    ASSERT_EQ(core.program_counter, START_ADDR + 3);
}

TEST(FLOW_CONTROL, JP_HL) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).WillOnce(Return(0xE9));

    core.program_counter = START_ADDR;
    core.H               = TARGET_ADDR_H;
    core.L               = TARGET_ADDR_L;
    core.cycle_cpu();

    ASSERT_EQ(core.program_counter, TARGET_ADDR);
}