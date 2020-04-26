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

const uint8_t JUMP_OFFSET = 0x77;

TEST(FLOW_CONTROL, JR_e) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).WillOnce(Return(0x18)).WillOnce(Return(JUMP_OFFSET));

    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.program_counter = START_ADDR;
    core.cycle_cpu();

    ASSERT_EQ(core.program_counter, START_ADDR + JUMP_OFFSET + 2);
}

TEST(FLOW_CONTROL, JR_NZ_e_taken) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).WillOnce(Return(0x20)).WillOnce(Return(JUMP_OFFSET));

    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.program_counter = START_ADDR;
    core.flags.zero      = false;
    core.cycle_cpu();

    ASSERT_EQ(core.program_counter, START_ADDR + JUMP_OFFSET + 2);
}

TEST(FLOW_CONTROL, JR_NC_e_taken) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).WillOnce(Return(0x30)).WillOnce(Return(JUMP_OFFSET));

    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.program_counter = START_ADDR;
    core.flags.carry     = false;
    core.cycle_cpu();

    ASSERT_EQ(core.program_counter, START_ADDR + JUMP_OFFSET + 2);
}

TEST(FLOW_CONTROL, JR_Z_e_taken) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).WillOnce(Return(0x28)).WillOnce(Return(JUMP_OFFSET));

    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.program_counter = START_ADDR;
    core.flags.zero      = true;
    core.cycle_cpu();

    ASSERT_EQ(core.program_counter, START_ADDR + JUMP_OFFSET + 2);
}

TEST(FLOW_CONTROL, JR_C_e_taken) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).WillOnce(Return(0x38)).WillOnce(Return(JUMP_OFFSET));

    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.program_counter = START_ADDR;
    core.flags.carry     = true;
    core.cycle_cpu();

    ASSERT_EQ(core.program_counter, START_ADDR + JUMP_OFFSET + 2);
}

TEST(FLOW_CONTROL, JR_NZ_e_not_taken) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).WillOnce(Return(0x20)).WillOnce(Return(JUMP_OFFSET));

    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.program_counter = START_ADDR;
    core.flags.zero      = true;
    core.cycle_cpu();

    ASSERT_EQ(core.program_counter, START_ADDR + 2);
}

TEST(FLOW_CONTROL, JR_NC_e_not_taken) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).WillOnce(Return(0x30)).WillOnce(Return(JUMP_OFFSET));

    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.program_counter = START_ADDR;
    core.flags.carry     = true;
    core.cycle_cpu();

    ASSERT_EQ(core.program_counter, START_ADDR + 2);
}

TEST(FLOW_CONTROL, JR_Z_e_not_taken) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).WillOnce(Return(0x28)).WillOnce(Return(JUMP_OFFSET));

    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.program_counter = START_ADDR;
    core.flags.zero      = false;
    core.cycle_cpu();

    ASSERT_EQ(core.program_counter, START_ADDR + 2);
}

TEST(FLOW_CONTROL, JR_C_e_not_taken) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).WillOnce(Return(0x38)).WillOnce(Return(JUMP_OFFSET));

    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.program_counter = START_ADDR;
    core.flags.carry     = false;
    core.cycle_cpu();

    ASSERT_EQ(core.program_counter, START_ADDR + 2);
}