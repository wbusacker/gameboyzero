#ifndef ROM_BANK_H
#define ROM_BANK_H

#include <bus_interface.h>

namespace ROM{

class ROM_Bank: public Bus::Bus_Interface{

public:

    ROM_Bank( uint16_t start_addr, uint16_t stop_addr) : 
        Bus::Bus_Interface(start_addr, stop_addr){
        start_address = start_addr;
        stop_address = stop_addr;
        memory_buffer = new uint8_t[(stop_addr - start_addr)];
    }


    void load_memory(uint8_t* buf, uint16_t len){return;}

    uint8_t fetch_memory(uint16_t addr){
        return irq_mask;
    }

    virtual void store_memory(uint16_t addr, uint8_t val){
        irq_mask = val;
    }

private:

    uint8_t irq_mask;

};

}

#endif