#ifndef CARTRIDGE_H
#define CARTRIDGE_H

#include <stdint.h>
#include <stdio.h>

namespace Cart {

const uint8_t  MAX_ROM_BANKS = 128;
const uint8_t  MAX_RAM_BANKS = 16;
const uint16_t ROM_BANK_SIZE = 0x4000;
const uint16_t RAM_BANK_SIZE = 0x2000;

enum Cartridge_Type {
    CART_NO_CONTROLLER,
    CART_MBC1,
    CART_MBC2,
    CART_MBC3,
    CART_MBC5,
    CART_MMMO1,
    CART_CAMERA,
    CART_TAMA5,
    CART_HUC3,
    CART_UNKNOWN
};

enum Cartridge_Attributes { BATTERY = 0x01, SRAM = 0x02, RUMBLE = 0x04, TIMER = 0x08 };

enum Cartridge_Type determine_cart_type(FILE *fp);
uint8_t             get_num_ram_banks(FILE *fp);
uint8_t             get_num_rom_banks(FILE *fp);

class Cartridge {

    public:
    Cartridge();

    virtual void init_cart(FILE *fp){};

    virtual void write_memory(uint16_t addr, uint8_t val){};

    virtual uint8_t
      read_memory(uint16_t addr) {
        return 0;
    };
};

}    // namespace Cart

#endif