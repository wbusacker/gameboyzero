#include <io_control.h>
#include <stdint.h>

namespace IO {

IO_Registers::IO_Registers() {

    buttons.up     = IO::RELEASED;
    buttons.down   = IO::RELEASED;
    buttons.left   = IO::RELEASED;
    buttons.right  = IO::RELEASED;
    buttons.a      = IO::RELEASED;
    buttons.b      = IO::RELEASED;
    buttons.select = IO::RELEASED;
    buttons.start  = IO::RELEASED;

    serial_buffer = 0x00;
    tx_start      = false;
    clock_source  = false;

    divider = 0x00;

    timer_accumulator          = 0x00;
    timer_reset_value          = 0x00;
    timer_active               = false;
    clock_timer_divider        = IO::FOUR_KH;
    clock_to_timer_accumulator = 0x00;
}

}    // namespace IO