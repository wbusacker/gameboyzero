#ifndef IRQ_BANK_H
#define IRQ_BANK_H

#include <stdint.h>

namespace IRQ {

typedef uint8_t Interrupt_Request;

const Interrupt_Request INTERRUPT_BIT_V_BLANK = 0; /* Display has finished drawing the frame   */
const Interrupt_Request INTERRUPT_BIT_LCDC    = 1; /* LCDC Has Fired, check stat               */
const Interrupt_Request INTERRUPT_BIT_TIMER   = 2; /* Timer Overflow                           */
const Interrupt_Request INTERRUPT_BIT_SIO     = 3; /* Serial IO Transfer Complete              */
const Interrupt_Request INTERRUPT_BIT_HL_CHG  = 4; /* Input Pin transitioned from High to Low  */

/* Interrupt Address Jump Points    */
const uint16_t INTERRUPT_TABLE_V_BLANK = 0x0040;
const uint16_t INTERRUPT_TABLE_LCDC    = 0x0048;
const uint16_t INTERRUPT_TABLE_TIMER   = 0x0050;
const uint16_t INTERRUPT_TABLE_SIO     = 0x0058;
const uint16_t INTERRUPT_TABLE_HL_CHG  = 0x0060;

class Controller {

    public:
    Controller();

    virtual uint16_t get_interrupt(void);

    virtual void raise_interrupt(Interrupt_Request request);
    virtual void set_enable_mask(uint8_t mask);
    virtual uint8_t get_enable_mask(void);

    Interrupt_Request interrupt_enable_mask;
    Interrupt_Request interrupt_pending_mask;
};

}    // namespace IRQ

#endif