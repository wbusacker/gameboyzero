#ifndef MBC_1_H
#define MBC_1_H

#include <cartridge.h>

namespace Cart{

class MBC1 : public Cartridge{

public:

    void    init_cart(FILE *fp);

    void    write_memory(uint16_t addr, uint8_t val);

    uint8_t read_memory(uint16_t addr);

private:

    bool    extended_memory_mode;
    bool    enable_ram;
    uint8_t bank1;
    uint8_t bank2;

    uint8_t num_ram_banks;
    uint8_t num_rom_banks;

    uint8_t **ram_banks;
    uint8_t **rom_banks;

};

}

#endif