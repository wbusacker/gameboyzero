#include <cpu_core.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <irq_controller_mock.h>
#include <mbc1.h>
#include <memory_map_mock.h>

using namespace testing;

const uint8_t  TARGET_ADDR_H       = 0x12;
const uint8_t  TARGET_ADDR_L       = 0x34;
const uint8_t  START_ADDR_H        = 0x56;
const uint8_t  START_ADDR_L        = 0x78;
const uint16_t TARGET_ADDR         = (static_cast<uint16_t>(TARGET_ADDR_H) << 8) | TARGET_ADDR_L;
const uint16_t START_ADDR          = (static_cast<uint16_t>(START_ADDR_H) << 8) | START_ADDR_L;
const uint16_t STACK_POINTER_START = 0xFFFF;

TEST(FLOW_CONTROL, CALL_nn) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
      .WillOnce(Return(0xCD))
      .WillOnce(Return(TARGET_ADDR_L))
      .WillOnce(Return(TARGET_ADDR_H));

    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    EXPECT_CALL(bus, store_addr(STACK_POINTER_START - 1, START_ADDR_H));
    EXPECT_CALL(bus, store_addr(STACK_POINTER_START - 2, START_ADDR_L));

    core.program_counter = START_ADDR - 3;
    core.stack_pointer   = STACK_POINTER_START;
    core.cycle_cpu();

    ASSERT_EQ(core.program_counter, TARGET_ADDR);
    ASSERT_EQ(core.stack_pointer, STACK_POINTER_START - 2);
}

TEST(FLOW_CONTROL, CALL_NZ_nn_taken) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
      .WillOnce(Return(0xC4))
      .WillOnce(Return(TARGET_ADDR_L))
      .WillOnce(Return(TARGET_ADDR_H));

    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    EXPECT_CALL(bus, store_addr(STACK_POINTER_START - 1, START_ADDR_H));
    EXPECT_CALL(bus, store_addr(STACK_POINTER_START - 2, START_ADDR_L));

    core.program_counter = START_ADDR - 3;
    core.stack_pointer   = STACK_POINTER_START;
    core.flags.zero      = false;
    core.cycle_cpu();

    ASSERT_EQ(core.program_counter, TARGET_ADDR);
    ASSERT_EQ(core.stack_pointer, STACK_POINTER_START - 2);
}

TEST(FLOW_CONTROL, CALL_NC_nn_taken) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
      .WillOnce(Return(0xD4))
      .WillOnce(Return(TARGET_ADDR_L))
      .WillOnce(Return(TARGET_ADDR_H));

    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    EXPECT_CALL(bus, store_addr(STACK_POINTER_START - 1, START_ADDR_H));
    EXPECT_CALL(bus, store_addr(STACK_POINTER_START - 2, START_ADDR_L));

    core.program_counter = START_ADDR - 3;
    core.stack_pointer   = STACK_POINTER_START;
    core.flags.carry     = false;
    core.cycle_cpu();

    ASSERT_EQ(core.program_counter, TARGET_ADDR);
    ASSERT_EQ(core.stack_pointer, STACK_POINTER_START - 2);
}

TEST(FLOW_CONTROL, CALL_Z_nn_taken) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
      .WillOnce(Return(0xCC))
      .WillOnce(Return(TARGET_ADDR_L))
      .WillOnce(Return(TARGET_ADDR_H));

    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    EXPECT_CALL(bus, store_addr(STACK_POINTER_START - 1, START_ADDR_H));
    EXPECT_CALL(bus, store_addr(STACK_POINTER_START - 2, START_ADDR_L));

    core.program_counter = START_ADDR - 3;
    core.stack_pointer   = STACK_POINTER_START;
    core.flags.zero      = true;
    core.cycle_cpu();

    ASSERT_EQ(core.program_counter, TARGET_ADDR);
    ASSERT_EQ(core.stack_pointer, STACK_POINTER_START - 2);
}

TEST(FLOW_CONTROL, CALL_C_nn_taken) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
      .WillOnce(Return(0xDC))
      .WillOnce(Return(TARGET_ADDR_L))
      .WillOnce(Return(TARGET_ADDR_H));

    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    EXPECT_CALL(bus, store_addr(STACK_POINTER_START - 1, START_ADDR_H));
    EXPECT_CALL(bus, store_addr(STACK_POINTER_START - 2, START_ADDR_L));

    core.program_counter = START_ADDR - 3;
    core.stack_pointer   = STACK_POINTER_START;
    core.flags.carry     = true;
    core.cycle_cpu();

    ASSERT_EQ(core.program_counter, TARGET_ADDR);
    ASSERT_EQ(core.stack_pointer, STACK_POINTER_START - 2);
}

TEST(FLOW_CONTROL, CALL_NZ_nn_not_taken) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
      .WillOnce(Return(0xC4))
      .WillOnce(Return(TARGET_ADDR_L))
      .WillOnce(Return(TARGET_ADDR_H));

    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.program_counter = START_ADDR - 3;
    core.stack_pointer   = STACK_POINTER_START;
    core.flags.zero      = true;
    core.cycle_cpu();

    ASSERT_EQ(core.program_counter, START_ADDR);
    ASSERT_EQ(core.stack_pointer, STACK_POINTER_START);
}

TEST(FLOW_CONTROL, CALL_NC_nn_not_taken) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
      .WillOnce(Return(0xD4))
      .WillOnce(Return(TARGET_ADDR_L))
      .WillOnce(Return(TARGET_ADDR_H));

    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.program_counter = START_ADDR - 3;
    core.stack_pointer   = STACK_POINTER_START;
    core.flags.carry     = true;
    core.cycle_cpu();

    ASSERT_EQ(core.program_counter, START_ADDR);
    ASSERT_EQ(core.stack_pointer, STACK_POINTER_START);
}

TEST(FLOW_CONTROL, CALL_Z_nn_not_taken) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
      .WillOnce(Return(0xCC))
      .WillOnce(Return(TARGET_ADDR_L))
      .WillOnce(Return(TARGET_ADDR_H));

    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.program_counter = START_ADDR - 3;
    core.stack_pointer   = STACK_POINTER_START;
    core.flags.zero      = false;
    core.cycle_cpu();

    ASSERT_EQ(core.program_counter, START_ADDR);
    ASSERT_EQ(core.stack_pointer, STACK_POINTER_START);
}

TEST(FLOW_CONTROL, CALL_C_nn_not_taken) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
      .WillOnce(Return(0xDC))
      .WillOnce(Return(TARGET_ADDR_L))
      .WillOnce(Return(TARGET_ADDR_H));

    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.program_counter = START_ADDR - 3;
    core.stack_pointer   = STACK_POINTER_START;
    core.flags.carry     = false;
    core.cycle_cpu();

    ASSERT_EQ(core.program_counter, START_ADDR);
    ASSERT_EQ(core.stack_pointer, STACK_POINTER_START);
}

TEST(FLOW_CONTROL, RET) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
      .WillOnce(Return(0xC9))
      .WillOnce(Return(TARGET_ADDR_L))
      .WillOnce(Return(TARGET_ADDR_H));

    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.program_counter = START_ADDR;
    core.stack_pointer   = STACK_POINTER_START - 2;
    core.cycle_cpu();

    ASSERT_EQ(core.program_counter, TARGET_ADDR);
    ASSERT_EQ(core.stack_pointer, STACK_POINTER_START);
}

TEST(FLOW_CONTROL, RETI) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
      .WillOnce(Return(0xD9))
      .WillOnce(Return(TARGET_ADDR_L))
      .WillOnce(Return(TARGET_ADDR_H));

    core.enable_interrupt = false;
    core.program_counter  = START_ADDR;
    core.stack_pointer    = STACK_POINTER_START - 2;
    core.cycle_cpu();

    ASSERT_EQ(core.program_counter, TARGET_ADDR);
    ASSERT_EQ(core.stack_pointer, STACK_POINTER_START);
    ASSERT_EQ(core.enable_interrupt, true);
}

TEST(FLOW_CONTROL, RET_NZ_taken) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
      .WillOnce(Return(0xC0))
      .WillOnce(Return(TARGET_ADDR_L))
      .WillOnce(Return(TARGET_ADDR_H));

    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.program_counter = START_ADDR;
    core.stack_pointer   = STACK_POINTER_START - 2;
    core.flags.zero      = false;
    core.cycle_cpu();

    ASSERT_EQ(core.program_counter, TARGET_ADDR);
    ASSERT_EQ(core.stack_pointer, STACK_POINTER_START);
}

TEST(FLOW_CONTROL, RET_NC_taken) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
      .WillOnce(Return(0xD0))
      .WillOnce(Return(TARGET_ADDR_L))
      .WillOnce(Return(TARGET_ADDR_H));

    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.program_counter = START_ADDR;
    core.stack_pointer   = STACK_POINTER_START - 2;
    core.flags.carry     = false;
    core.cycle_cpu();

    ASSERT_EQ(core.program_counter, TARGET_ADDR);
    ASSERT_EQ(core.stack_pointer, STACK_POINTER_START);
}

TEST(FLOW_CONTROL, RET_Z_taken) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
      .WillOnce(Return(0xC8))
      .WillOnce(Return(TARGET_ADDR_L))
      .WillOnce(Return(TARGET_ADDR_H));

    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.program_counter = START_ADDR;
    core.stack_pointer   = STACK_POINTER_START - 2;
    core.flags.zero      = true;
    core.cycle_cpu();

    ASSERT_EQ(core.program_counter, TARGET_ADDR);
    ASSERT_EQ(core.stack_pointer, STACK_POINTER_START);
}

TEST(FLOW_CONTROL, RET_C_taken) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_))
      .WillOnce(Return(0xD8))
      .WillOnce(Return(TARGET_ADDR_L))
      .WillOnce(Return(TARGET_ADDR_H));

    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.program_counter = START_ADDR;
    core.stack_pointer   = STACK_POINTER_START - 2;
    core.flags.carry     = true;
    core.cycle_cpu();

    ASSERT_EQ(core.program_counter, TARGET_ADDR);
    ASSERT_EQ(core.stack_pointer, STACK_POINTER_START);
}

TEST(FLOW_CONTROL, RET_NZ_not_taken) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).WillOnce(Return(0xC0));

    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.program_counter = START_ADDR;
    core.stack_pointer   = STACK_POINTER_START - 2;
    core.flags.zero      = true;
    core.cycle_cpu();

    ASSERT_EQ(core.program_counter, START_ADDR + 1);
    ASSERT_EQ(core.stack_pointer, STACK_POINTER_START - 2);
}

TEST(FLOW_CONTROL, RET_NC_not_taken) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).WillOnce(Return(0xD0));

    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.program_counter = START_ADDR;
    core.stack_pointer   = STACK_POINTER_START - 2;
    core.flags.carry     = true;
    core.cycle_cpu();

    ASSERT_EQ(core.program_counter, START_ADDR + 1);
    ASSERT_EQ(core.stack_pointer, STACK_POINTER_START - 2);
}

TEST(FLOW_CONTROL, RET_Z_not_taken) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).WillOnce(Return(0xC8));

    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.program_counter = START_ADDR;
    core.stack_pointer   = STACK_POINTER_START - 2;
    core.flags.zero      = false;
    core.cycle_cpu();

    ASSERT_EQ(core.program_counter, START_ADDR + 1);
    ASSERT_EQ(core.stack_pointer, STACK_POINTER_START - 2);
}

TEST(FLOW_CONTROL, RET_C_not_taken) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).WillOnce(Return(0xD8));

    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.program_counter = START_ADDR;
    core.stack_pointer   = STACK_POINTER_START - 2;
    core.flags.carry     = false;
    core.cycle_cpu();

    ASSERT_EQ(core.program_counter, START_ADDR + 1);
    ASSERT_EQ(core.stack_pointer, STACK_POINTER_START - 2);
}