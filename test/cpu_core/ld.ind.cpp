#include <cpu_core.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <irq_controller_mock.h>
#include <mbc1.h>
#include <memory_map_mock.h>

using namespace testing;

const uint8_t TARGET_VAL = 0x80;

TEST(LD_IND, LD_BC_A) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x02));

    EXPECT_CALL(bus, store_addr(0x1234, TARGET_VAL)).Times(1);

    core.A = TARGET_VAL;
    core.B = 0x12;
    core.C = 0x34;

    core.cycle_cpu();
}

TEST(LD_IND, LD_DE_A) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x12));

    EXPECT_CALL(bus, store_addr(0x1234, TARGET_VAL)).Times(1);

    core.A = TARGET_VAL;
    core.D = 0x12;
    core.E = 0x34;

    core.cycle_cpu();
}

TEST(LD_IND, LD_HL_P_A) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x22));

    EXPECT_CALL(bus, store_addr(0x1234, TARGET_VAL)).Times(1);

    core.A = TARGET_VAL;
    core.H = 0x12;
    core.L = 0x34;

    core.cycle_cpu();

    ASSERT_EQ(core.L, 0x35);
}

TEST(LD_IND, LD_HL_M_A) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(1).WillOnce(Return(0x32));

    EXPECT_CALL(bus, store_addr(0x1234, TARGET_VAL)).Times(1);

    core.A = TARGET_VAL;
    core.H = 0x12;
    core.L = 0x34;

    core.cycle_cpu();

    ASSERT_EQ(core.L, 0x33);
}

TEST(LD_IND, LD_A_BC) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0x0A)).WillOnce(Return(TARGET_VAL));

    core.A = 0x00;
    core.B = 0x12;
    core.C = 0x34;

    core.cycle_cpu();

    ASSERT_EQ(core.A, TARGET_VAL);
}

TEST(LD_IND, LD_A_DE) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0x1A)).WillOnce(Return(TARGET_VAL));

    core.A = TARGET_VAL;
    core.D = 0x12;
    core.E = 0x34;

    core.cycle_cpu();
}

TEST(LD_IND, LD_A_HL_P) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0x2A)).WillOnce(Return(TARGET_VAL));

    core.A = 0x00;
    core.H = 0x12;
    core.L = 0x34;

    core.cycle_cpu();

    ASSERT_EQ(core.A, TARGET_VAL);
    ASSERT_EQ(core.L, 0x35);
}

TEST(LD_IND, LD_A_HL_M) {
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902    core(bus, irq);

    EXPECT_CALL(bus, fetch_addr(_)).Times(2).WillOnce(Return(0x3A)).WillOnce(Return(TARGET_VAL));

    core.A = TARGET_VAL;
    core.H = 0x12;
    core.L = 0x34;

    core.cycle_cpu();

    ASSERT_EQ(core.A, TARGET_VAL);
    ASSERT_EQ(core.L, 0x33);
}