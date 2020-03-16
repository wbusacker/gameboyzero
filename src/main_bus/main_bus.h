#ifndef MAIN_BUS_H
#define MAIN_BUS_H

#include <stdint.h>
#include <bus_interface.h>
#include <vector>

namespace Bus{

class Main_Bus{

public:

    Main_Bus();

    void attach_device(Bus::Bus_Interface *dev);

    uint8_t fetch_addr(uint16_t addr);
    void    store_addr(uint16_t addr, uint8_t val);

private:

    std::vector<Bus::Bus_Interface*> device_list;

};


}


#endif