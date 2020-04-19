#include <cpu_core.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <irq_controller_mock.h>
#include <mbc1.h>
#include <memory_map_mock.h>

using namespace testing;

TEST(CPU_CB_SWAP, SWAP_A) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x37));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.A = 0xA5;

    core.cycle_cpu();

    ASSERT_EQ(core.A, 0x5A);
}

TEST(CPU_CB_SWAP, SWAP_B) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x30));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.B = 0xA5;

    core.cycle_cpu();

    ASSERT_EQ(core.B, 0x5A);
}

TEST(CPU_CB_SWAP, SWAP_C) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x31));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.C = 0xA5;

    core.cycle_cpu();

    ASSERT_EQ(core.C, 0x5A);
}

TEST(CPU_CB_SWAP, SWAP_D) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x32));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.D = 0xA5;

    core.cycle_cpu();

    ASSERT_EQ(core.D, 0x5A);
}

TEST(CPU_CB_SWAP, SWAP_E) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x33));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.E = 0xA5;

    core.cycle_cpu();

    ASSERT_EQ(core.E, 0x5A);
}

TEST(CPU_CB_SWAP, SWAP_H) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x34));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.H = 0xA5;

    core.cycle_cpu();

    ASSERT_EQ(core.H, 0x5A);
}

TEST(CPU_CB_SWAP, SWAP_L) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0xCB)).WillOnce(Return(0x35));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    core.L = 0xA5;

    core.cycle_cpu();

    ASSERT_EQ(core.L, 0x5A);
}

TEST(CPU_CB_SWAP, SWAP_HL) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(3).WillOnce(Return(0xCB)).WillOnce(Return(0x36)).WillOnce(Return(0xA5));
    EXPECT_CALL(irq, get_interrupt()).Times(1).WillOnce(Return(0));

    EXPECT_CALL(bus, store_addr(_, 0x5A)).Times(1);

    core.cycle_cpu();
}