#ifndef MAIN_BUS_H
#define MAIN_BUS_H

#include <stdint.h>
#include <bus_interface.h>
#include <vector>

namespace Bus{

const uint8_t MAX_BUS_DEVICES = 100;

class Main_Bus{

public:

    Main_Bus();

    void attach_device(Bus::Bus_Interface *dev);

    uint8_t fetch_addr(uint16_t addr);
    void    store_addr(uint16_t addr, uint8_t val);



private:

    Bus::Bus_Interface* device_list[Bus::MAX_BUS_DEVICES];

    uint8_t num_loaded_devices;

};


}


#endif