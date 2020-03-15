#include <gtest/gtest.h>
#include <cpu_core.h>

TEST(CPU_CORE, FLAG_STRUCT_SIZE){
    ASSERT_EQ(sizeof(CPU::CPU_flags), 1);
}

TEST(CPU_CORE, REGISTER_NUMBER_MAP){
    class Bus::Main_Bus bus;
    class CPU::LR35902 core(bus);

    /* Make sure we get back B */
    ASSERT_EQ(&core.A, core.get_reg_ptr_from_number(0x47));
    ASSERT_EQ(&core.B, core.get_reg_ptr_from_number(0x40));
    ASSERT_EQ(&core.C, core.get_reg_ptr_from_number(0x41));
    ASSERT_EQ(&core.D, core.get_reg_ptr_from_number(0x42));
    ASSERT_EQ(&core.E, core.get_reg_ptr_from_number(0x43));
    ASSERT_EQ(&core.H, core.get_reg_ptr_from_number(0x44));
    ASSERT_EQ(&core.L, core.get_reg_ptr_from_number(0x45));
    ASSERT_EQ(NULL,    core.get_reg_ptr_from_number(0x46));

}