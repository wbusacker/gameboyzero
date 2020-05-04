#include <cpu_core.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <irq_controller_mock.h>
#include <mbc1.h>
#include <memory_map_mock.h>

using namespace testing;

const uint8_t TARGET_VAL = 0xA5;

TEST(LD_IND, LD_A_n) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0x3E)).WillOnce(Return(TARGET_VAL));

    core.A = 0x00;

    core.cycle_cpu();

    EXPECT_EQ(core.A, TARGET_VAL);
}

TEST(LD_IND, LD_B_n) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0x06)).WillOnce(Return(TARGET_VAL));

    core.B = 0x00;

    core.cycle_cpu();

    EXPECT_EQ(core.B, TARGET_VAL);
}

TEST(LD_IND, LD_C_n) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0x0E)).WillOnce(Return(TARGET_VAL));

    core.C = 0x00;

    core.cycle_cpu();

    EXPECT_EQ(core.C, TARGET_VAL);
}

TEST(LD_IND, LD_D_n) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0x16)).WillOnce(Return(TARGET_VAL));

    core.D = 0x00;

    core.cycle_cpu();

    EXPECT_EQ(core.D, TARGET_VAL);
}

TEST(LD_IND, LD_E_n) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0x1E)).WillOnce(Return(TARGET_VAL));

    core.E = 0x00;

    core.cycle_cpu();

    EXPECT_EQ(core.E, TARGET_VAL);
}

TEST(LD_IND, LD_H_n) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0x26)).WillOnce(Return(TARGET_VAL));

    core.H = 0x00;

    core.cycle_cpu();

    EXPECT_EQ(core.H, TARGET_VAL);
}

TEST(LD_IND, LD_L_n) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0x2E)).WillOnce(Return(TARGET_VAL));

    core.L = 0x00;

    core.cycle_cpu();

    EXPECT_EQ(core.L, TARGET_VAL);
}

TEST(LD_IND, LD_HL_n) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0x36)).WillOnce(Return(TARGET_VAL));

    EXPECT_CALL(bus, store_addr(_, TARGET_VAL)).Times(1);

    core.cycle_cpu();
}
