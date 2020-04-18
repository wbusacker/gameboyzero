#ifndef MEMORY_MAP_MOCK_H
#define MEMORY_MAP_MOCK_H

#include <gmock/gmock.h>
#include <memory_map.h>
#include <irq_controller.h>

class Mock_Memory_Map : public Memory::Memory_Map {
public:

    Mock_Memory_Map(Cart::Cartridge *c, IRQ::Controller *i);

    MOCK_METHOD(uint8_t,    fetch_addr, (uint16_t addr), (override));
    MOCK_METHOD(void,       store_addr, (uint16_t addr, uint8_t val), (override));

};

#endif