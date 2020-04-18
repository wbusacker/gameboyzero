#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <cpu_core.h>
#include <mbc1.h>
#include <memory_map_mock.h>
#include <irq_controller_mock.h>

using namespace testing;

const uint8_t TARGET_VAL_1 = 0x01;
const uint8_t TARGET_VAL_2 = 0x23;

TEST(LD_16, LD_BC_nn){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);
    
    EXPECT_CALL(bus, fetch_addr(_))
        .Times(3)
        .WillOnce(Return(0x01))
        .WillOnce(Return(TARGET_VAL_1))
        .WillOnce(Return(TARGET_VAL_2));

    core.B = 0x00;
    core.C = 0x00;

    core.cycle_cpu();

    ASSERT_EQ(core.B, TARGET_VAL_2);
    ASSERT_EQ(core.C, TARGET_VAL_1);

}

TEST(LD_16, LD_DE_nn){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);
    
    EXPECT_CALL(bus, fetch_addr(_))
        .Times(3)
        .WillOnce(Return(0x11))
        .WillOnce(Return(TARGET_VAL_1))
        .WillOnce(Return(TARGET_VAL_2));

    core.D = 0x00;
    core.E = 0x00;

    core.cycle_cpu();

    ASSERT_EQ(core.D, TARGET_VAL_2);
    ASSERT_EQ(core.E, TARGET_VAL_1);

}

TEST(LD_16, LD_HL_nn){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);
    
    EXPECT_CALL(bus, fetch_addr(_))
        .Times(3)
        .WillOnce(Return(0x21))
        .WillOnce(Return(TARGET_VAL_1))
        .WillOnce(Return(TARGET_VAL_2));

    core.H = 0x00;
    core.L= 0x00;

    core.cycle_cpu();

    ASSERT_EQ(core.H, TARGET_VAL_2);
    ASSERT_EQ(core.L, TARGET_VAL_1);

}

TEST(LD_16, LD_SP_nn){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);
    EXPECT_CALL(bus, fetch_addr(_))
        .Times(3)
        .WillOnce(Return(0x31))
        .WillOnce(Return(TARGET_VAL_1))
        .WillOnce(Return(TARGET_VAL_2));

    core.stack_pointer = 0x0000;

    core.cycle_cpu();

    ASSERT_EQ(core.stack_pointer, (static_cast<uint16_t>(TARGET_VAL_2 << 8)) | TARGET_VAL_1);

}

TEST(LD_16, LD_nn_SP){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);
    
    EXPECT_CALL(bus, fetch_addr(_))
        .Times(3)
        .WillOnce(Return(0x08))
        .WillOnce(Return(TARGET_VAL_1))
        .WillOnce(Return(TARGET_VAL_2));

    uint16_t target_addr = (static_cast<uint16_t>(TARGET_VAL_2 << 8)) | TARGET_VAL_1;

    EXPECT_CALL(bus, store_addr(target_addr, TARGET_VAL_1));
    EXPECT_CALL(bus, store_addr(target_addr + 1, TARGET_VAL_2));

    core.stack_pointer = (static_cast<uint16_t>(TARGET_VAL_2 << 8)) | TARGET_VAL_1;

    core.cycle_cpu();

}

TEST(LD_16, POP_BC){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);
    core.stack_pointer = 0;
    core.B = 0;
    core.A = 0;

    
    EXPECT_CALL(bus, fetch_addr(_))
        .WillOnce(Return(0xC1));

    EXPECT_CALL(bus, fetch_addr(0x0))
        .WillOnce(Return(TARGET_VAL_1));

    EXPECT_CALL(bus, fetch_addr(0x1))
        .WillOnce(Return(TARGET_VAL_2));
        
    core.cycle_cpu();
        
    ASSERT_EQ(core.B, TARGET_VAL_2);
    ASSERT_EQ(core.C, TARGET_VAL_1);
    ASSERT_EQ(core.stack_pointer, 0x2);


}

TEST(LD_16, POP_DE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);
    core.stack_pointer = 0;
    core.D = 0;
    core.E = 0;

    
    EXPECT_CALL(bus, fetch_addr(_))
        .WillOnce(Return(0xD1));

    EXPECT_CALL(bus, fetch_addr(0x0))
        .WillOnce(Return(TARGET_VAL_1));

    EXPECT_CALL(bus, fetch_addr(0x1))
        .WillOnce(Return(TARGET_VAL_2));
        
    core.cycle_cpu();
        
    ASSERT_EQ(core.D, TARGET_VAL_2);
    ASSERT_EQ(core.E, TARGET_VAL_1);
    ASSERT_EQ(core.stack_pointer, 0x2);


}

TEST(LD_16, POP_HL){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);
    core.stack_pointer = 0;
    core.H = 0;
    core.L = 0;

    
    EXPECT_CALL(bus, fetch_addr(_))
        .WillOnce(Return(0xE1));

    EXPECT_CALL(bus, fetch_addr(0x0))
        .WillOnce(Return(TARGET_VAL_1));

    EXPECT_CALL(bus, fetch_addr(0x1))
        .WillOnce(Return(TARGET_VAL_2));
        
    core.cycle_cpu();
        
    ASSERT_EQ(core.H, TARGET_VAL_2);
    ASSERT_EQ(core.L, TARGET_VAL_1);
    ASSERT_EQ(core.stack_pointer, 0x2);


}

TEST(LD_16, POP_AF){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);
    core.stack_pointer      = 0;
    core.A                  = 0;
    core.flags.sub          = 0;
    core.flags.zero         = 0;
    core.flags.carry        = 0;
    core.flags.half_carry   = 0;

    
    EXPECT_CALL(bus, fetch_addr(_))
        .WillOnce(Return(0xF1));

    EXPECT_CALL(bus, fetch_addr(0x0))
        .WillOnce(Return(TARGET_VAL_1));

    EXPECT_CALL(bus, fetch_addr(0x1))
        .WillOnce(Return(TARGET_VAL_2));
        
    core.cycle_cpu();
        
    ASSERT_EQ(core.A, TARGET_VAL_2);

    ASSERT_EQ(core.flags.sub,           TARGET_VAL_1 & 0b1);
    ASSERT_EQ(core.flags.zero,          TARGET_VAL_1 & 0b10);
    ASSERT_EQ(core.flags.carry,         TARGET_VAL_1 & 0b100);
    ASSERT_EQ(core.flags.half_carry,    TARGET_VAL_1 & 0b1000);
    ASSERT_EQ(core.stack_pointer, 0x2);


}

TEST(LD_16, PUSH_BC){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);
    uint16_t target_addr = (static_cast<uint16_t>(TARGET_VAL_2 << 8)) | TARGET_VAL_1;

    core.stack_pointer = target_addr;
    core.B  = TARGET_VAL_2;
    core.C  = TARGET_VAL_1;

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(1)
        .WillOnce(Return(0xC5));

    EXPECT_CALL(bus, store_addr(target_addr - 1,    TARGET_VAL_2));
    EXPECT_CALL(bus, store_addr(target_addr - 2,    TARGET_VAL_1));

    core.cycle_cpu();

    ASSERT_EQ(core.stack_pointer, target_addr - 2);

}

TEST(LD_16, PUSH_DE){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);
    uint16_t target_addr = (static_cast<uint16_t>(TARGET_VAL_2 << 8)) | TARGET_VAL_1;

    core.stack_pointer = target_addr;
    core.D  = TARGET_VAL_2;
    core.E  = TARGET_VAL_1;

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(1)
        .WillOnce(Return(0xD5));

    EXPECT_CALL(bus, store_addr(target_addr - 1,    TARGET_VAL_2));
    EXPECT_CALL(bus, store_addr(target_addr - 2,    TARGET_VAL_1));

    core.cycle_cpu();

    ASSERT_EQ(core.stack_pointer, target_addr - 2);

}

TEST(LD_16, PUSH_HL){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);
    uint16_t target_addr = (static_cast<uint16_t>(TARGET_VAL_2 << 8)) | TARGET_VAL_1;

    core.stack_pointer = target_addr;
    core.H  = TARGET_VAL_2;
    core.L  = TARGET_VAL_1;

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(1)
        .WillOnce(Return(0xE5));

    EXPECT_CALL(bus, store_addr(target_addr - 1,    TARGET_VAL_2));
    EXPECT_CALL(bus, store_addr(target_addr - 2,    TARGET_VAL_1));

    core.cycle_cpu();

    ASSERT_EQ(core.stack_pointer, target_addr - 2);

}

TEST(LD_16, PUSH_AF){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);
    uint16_t target_addr = (static_cast<uint16_t>(TARGET_VAL_2 << 8)) | TARGET_VAL_1;

    core.stack_pointer      = target_addr;
    core.A                  = TARGET_VAL_2;
    core.flags.sub          = TARGET_VAL_1 & 0b1;
    core.flags.zero         = TARGET_VAL_1 & 0b10;
    core.flags.carry        = TARGET_VAL_1 & 0b100;
    core.flags.half_carry   = TARGET_VAL_1 & 0b1000;

    EXPECT_CALL(bus, fetch_addr(_))
        .Times(1)
        .WillOnce(Return(0xF5));

    EXPECT_CALL(bus, store_addr(target_addr - 1,    TARGET_VAL_2));
    EXPECT_CALL(bus, store_addr(target_addr - 2,    TARGET_VAL_1 & 0x0F));

    core.cycle_cpu();

    ASSERT_EQ(core.stack_pointer, target_addr - 2);

}

TEST(LD_16, LD_HL_SP_n){
    Mock_Memory_Map bus(NULL, NULL);
    Mock_Controller irq;
    CPU::LR35902 core(bus, irq);
    uint8_t offset = 0x5;
    uint16_t target_addr = (static_cast<uint16_t>(TARGET_VAL_2 << 8)) | TARGET_VAL_1;
    core.stack_pointer = target_addr;

    EXPECT_CALL(bus, fetch_addr(_))
        .WillOnce(Return(0xF8))
        .WillOnce(Return(offset));
    
    EXPECT_CALL(bus, fetch_addr(target_addr + offset))
        .WillOnce(Return(TARGET_VAL_1));

    EXPECT_CALL(bus, fetch_addr(target_addr + offset + 1))
        .WillOnce(Return(TARGET_VAL_2));

    core.cycle_cpu();

    ASSERT_EQ(core.H, TARGET_VAL_2);
    ASSERT_EQ(core.L, TARGET_VAL_1);



}