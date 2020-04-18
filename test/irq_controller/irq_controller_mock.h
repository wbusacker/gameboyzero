#ifndef IRQ_CONTROLLER_MOCK_H
#define IRQ_CONTROLLER_MOCK_H

#include <gmock/gmock.h>
#include <irq_controller.h>

class Mock_Controller : public IRQ::Controller {
    public:
    Mock_Controller();

    MOCK_METHOD(uint16_t, get_interrupt, (), (override));
    MOCK_METHOD(void, raise_interrupt, (IRQ::Interrupt_Request request), (override));
    MOCK_METHOD(void, set_enable_mask, (uint8_t mask), (override));
};

#endif