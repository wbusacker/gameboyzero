#ifndef BUS_INTERFACE
#define BUS_INTERFACE

#include <stdint.h>
#include <string.h>
#include <stdlib.h>

namespace Bus{

class Bus_Interface{

public:

    Bus_Interface(  uint16_t start_addr,
                    uint16_t stop_addr)
    {
        start_address = start_addr;
        stop_address = stop_addr;
        memory_buffer = new uint8_t[(stop_addr - start_addr)];
    }

    virtual void load_memory(void* buf, uint16_t len){
        memcpy(memory_buffer, buf, len);
    }

    virtual uint8_t fetch_memory(uint16_t addr){
        return memory_buffer[addr - start_address];
    }

    virtual void store_memory(uint16_t addr, uint8_t val){
        if((start_address <= val) && (stop_address >= val)){
            memory_buffer[addr - start_address] = val;
        }
    }

    uint16_t get_start_addr(){
        return start_address;
    }

    uint16_t get_stop_addr(){
        return stop_address;
    }

protected:

    uint16_t start_address;
    uint16_t stop_address;
    uint8_t *memory_buffer;

};

}

#endif