#include <cpu_core.h>
#include <gtest/gtest.h>

int
main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    // InitGoogleTest();

    CPU::print_diagnostics = false;

    return RUN_ALL_TESTS();
}