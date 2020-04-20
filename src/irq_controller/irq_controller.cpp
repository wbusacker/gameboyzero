#include <irq_controller.h>

namespace IRQ {

Controller::Controller() {
    interrupt_enable_mask  = 0x0;
    interrupt_pending_mask = 0x0;
}

void
Controller::raise_interrupt(Interrupt_Request request) {
    interrupt_pending_mask |= 1 << request;
}

uint16_t
Controller::get_interrupt(void) {

    Interrupt_Request interrupt_flags;

    interrupt_flags = interrupt_enable_mask & interrupt_pending_mask;

    if ((interrupt_flags & (1 << INTERRUPT_BIT_V_BLANK)) != 0) {
        interrupt_pending_mask &= ~(1 << INTERRUPT_BIT_V_BLANK);
        return INTERRUPT_TABLE_V_BLANK;

    } else if ((interrupt_flags & (1 << INTERRUPT_BIT_LCDC)) != 0) {
        interrupt_pending_mask &= ~(1 << INTERRUPT_BIT_LCDC);
        return INTERRUPT_TABLE_LCDC;

    } else if ((interrupt_flags & (1 << INTERRUPT_BIT_TIMER)) != 0) {
        interrupt_pending_mask &= ~(1 << INTERRUPT_BIT_TIMER);
        return INTERRUPT_TABLE_TIMER;

    } else if ((interrupt_flags & (1 << INTERRUPT_BIT_SIO)) != 0) {
        interrupt_pending_mask &= ~(1 << INTERRUPT_BIT_SIO);
        return INTERRUPT_TABLE_SIO;

    } else if ((interrupt_flags & (1 << INTERRUPT_BIT_HL_CHG)) != 0) {
        interrupt_pending_mask &= ~(1 << INTERRUPT_BIT_HL_CHG);
        return INTERRUPT_TABLE_HL_CHG;
    }

    return 0;
}

void
Controller::set_enable_mask(uint8_t mask) {
    interrupt_enable_mask = static_cast<Interrupt_Request>(mask);
    return;
}

uint8_t Controller::get_enable_mask(void){
    return interrupt_enable_mask;
}

}    // namespace IRQ