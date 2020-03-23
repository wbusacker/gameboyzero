#include <gtest/gtest.h>
#include <cpu_core.h>

int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    // InitGoogleTest();

    CPU::print_diagnostics = false;

    return RUN_ALL_TESTS();
}