#include <cpu_core.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <irq_controller_mock.h>
#include <mbc1.h>
#include <memory_map_mock.h>

using namespace testing;

TEST(MISC, NOP) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x00));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.A = 0x12;
    core.B = 0x12;
    core.C = 0x12;
    core.D = 0x12;
    core.E = 0x12;
    core.H = 0x12;
    core.L = 0x12;

    core.flags.sub        = false;
    core.flags.zero       = false;
    core.flags.carry      = false;
    core.flags.half_carry = false;
    core.stack_pointer    = 0xFFFD;
    core.program_counter  = 0;

    core.cycle_cpu();

    /* Assert that none of the CPU state got changed aside from the PC  */

    ASSERT_EQ(core.A, 0x12);
    ASSERT_EQ(core.B, 0x12);
    ASSERT_EQ(core.C, 0x12);
    ASSERT_EQ(core.D, 0x12);
    ASSERT_EQ(core.E, 0x12);
    ASSERT_EQ(core.H, 0x12);
    ASSERT_EQ(core.L, 0x12);

    ASSERT_EQ(core.flags.sub, false);
    ASSERT_EQ(core.flags.zero, false);
    ASSERT_EQ(core.flags.carry, false);
    ASSERT_EQ(core.flags.half_carry, false);
    ASSERT_EQ(core.stack_pointer, 0xFFFD);
    ASSERT_EQ(core.program_counter, 1);
}

TEST(MISC, STOP) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x10));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    /* Two calls to cycle the CPU should fail   */
    core.cycle_cpu();
    core.cycle_cpu();
}

TEST(MISC, HALT) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x76));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    /* Two calls to cycle the CPU should fail   */
    core.cycle_cpu();
    core.cycle_cpu();
}

TEST(MISC, DI) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0xF3));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.enable_interrupt = true;

    /* Two calls to cycle the CPU should fail   */
    core.cycle_cpu();

    EXPECT_EQ(core.enable_interrupt, false);
}

TEST(MISC, EI) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0xFB));
    // EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.enable_interrupt = false;

    /* Two calls to cycle the CPU should fail   */
    core.cycle_cpu();

    EXPECT_EQ(core.enable_interrupt, true);
}