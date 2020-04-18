#ifndef IO_CONTROL_H
#define IO_CONTROL_H

#include <stdint.h>

namespace IO {

enum Button_State_Enm { PRESSED, RELEASED };

struct Buttons_State {
    enum Button_State_Enm up;
    enum Button_State_Enm down;
    enum Button_State_Enm left;
    enum Button_State_Enm right;
    enum Button_State_Enm a;
    enum Button_State_Enm b;
    enum Button_State_Enm select;
    enum Button_State_Enm start;
};

enum Clock_Freq_Div_Enm { FOUR_KH = 256, TWO_SIXTY_TWO_KH = 4, SIXTY_FIVE_KH = 16, SIXTEEN_KH = 64 };

class IO_Registers {

    public:
    IO_Registers();

    uint8_t read_io(uint16_t addr);
    void    write_io(uint16_t addr, uint8_t val);

    /* Button State                     */
    struct Buttons_State buttons;

    /* Serial IO                        */
    uint8_t serial_buffer;
    bool    tx_start;
    bool    clock_source;

    /* Clock & Timers                   */
    uint8_t                 divider;
    uint8_t                 timer_accumulator;
    uint8_t                 timer_reset_value;
    bool                    timer_active;
    enum Clock_Freq_Div_Enm clock_timer_divider;
    uint8_t                 clock_to_timer_accumulator;
};

}    // namespace IO

#endif