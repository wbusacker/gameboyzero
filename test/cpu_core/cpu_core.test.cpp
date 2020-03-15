#include <gtest/gtest.h>
#include <cpu_core.h>

TEST(CPU_CORE, FLAG_STRUCT_SIZE){
    ASSERT_EQ(sizeof(CPU::CPU_flags), 1);
}