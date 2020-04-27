#include <cpu_core.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <irq_controller_mock.h>
#include <mbc1.h>
#include <memory_map_mock.h>

using namespace testing;

TEST(MISC, RES_00) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0xC7));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.program_counter = 0x0123 - 1;
    core.stack_pointer   = 0xFFFF;

    EXPECT_CALL(bus, store_addr(0xFFFF - 1, 0x01));
    EXPECT_CALL(bus, store_addr(0xFFFF - 2, 0x23));

    core.cycle_cpu();

    /* Assert that none of the CPU state got changed aside from the PC  */

    ASSERT_EQ(core.program_counter, 0x00);
}

TEST(MISC, RES_08) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0xCF));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.program_counter = 0x0123 - 1;
    core.stack_pointer   = 0xFFFF;

    EXPECT_CALL(bus, store_addr(0xFFFF - 1, 0x01));
    EXPECT_CALL(bus, store_addr(0xFFFF - 2, 0x23));

    core.cycle_cpu();

    /* Assert that none of the CPU state got changed aside from the PC  */

    ASSERT_EQ(core.program_counter, 0x08);
}

TEST(MISC, RES_10) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0xD7));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.program_counter = 0x0123 - 1;
    core.stack_pointer   = 0xFFFF;

    EXPECT_CALL(bus, store_addr(0xFFFF - 1, 0x01));
    EXPECT_CALL(bus, store_addr(0xFFFF - 2, 0x23));

    core.cycle_cpu();

    /* Assert that none of the CPU state got changed aside from the PC  */

    ASSERT_EQ(core.program_counter, 0x10);
}

TEST(MISC, RES_18) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0xDF));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.program_counter = 0x0123 - 1;
    core.stack_pointer   = 0xFFFF;

    EXPECT_CALL(bus, store_addr(0xFFFF - 1, 0x01));
    EXPECT_CALL(bus, store_addr(0xFFFF - 2, 0x23));

    core.cycle_cpu();

    /* Assert that none of the CPU state got changed aside from the PC  */

    ASSERT_EQ(core.program_counter, 0x18);
}

TEST(MISC, RES_20) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0xE7));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.program_counter = 0x0123 - 1;
    core.stack_pointer   = 0xFFFF;

    EXPECT_CALL(bus, store_addr(0xFFFF - 1, 0x01));
    EXPECT_CALL(bus, store_addr(0xFFFF - 2, 0x23));

    core.cycle_cpu();

    /* Assert that none of the CPU state got changed aside from the PC  */

    ASSERT_EQ(core.program_counter, 0x20);
}

TEST(MISC, RES_28) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0xEF));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.program_counter = 0x0123 - 1;
    core.stack_pointer   = 0xFFFF;

    EXPECT_CALL(bus, store_addr(0xFFFF - 1, 0x01));
    EXPECT_CALL(bus, store_addr(0xFFFF - 2, 0x23));

    core.cycle_cpu();

    /* Assert that none of the CPU state got changed aside from the PC  */

    ASSERT_EQ(core.program_counter, 0x28);
}

TEST(MISC, RES_30) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0xF7));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.program_counter = 0x0123 - 1;
    core.stack_pointer   = 0xFFFF;

    EXPECT_CALL(bus, store_addr(0xFFFF - 1, 0x01));
    EXPECT_CALL(bus, store_addr(0xFFFF - 2, 0x23));

    core.cycle_cpu();

    /* Assert that none of the CPU state got changed aside from the PC  */

    ASSERT_EQ(core.program_counter, 0x30);
}

TEST(MISC, RES_38) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0xFF));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.program_counter = 0x0123 - 1;
    core.stack_pointer   = 0xFFFF;

    EXPECT_CALL(bus, store_addr(0xFFFF - 1, 0x01));
    EXPECT_CALL(bus, store_addr(0xFFFF - 2, 0x23));

    core.cycle_cpu();

    /* Assert that none of the CPU state got changed aside from the PC  */

    ASSERT_EQ(core.program_counter, 0x38);
}