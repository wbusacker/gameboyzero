#include <main_bus.h>
#include <stdio.h>

namespace Bus{

void Main_Bus::attach_device(Bus::Bus_Interface *dev){
    device_list.push_back(dev);
}

uint8_t Main_Bus::fetch_addr(uint16_t addr){
    uint16_t dev_i;
    Bus::Bus_Interface *dev;
    for(dev_i = 0; dev_i < device_list.size(); dev_i++){
        dev = device_list[dev_i];
        /* Check if this is the right range */
        if((dev->get_start_addr() <= addr) && (dev->get_stop_addr() >= addr)){
            return dev->fetch_memory(addr);
        }
    }

    /* If we didn't find the requested address, display an error and return 0 */
    printf("Could not find device with address %d\n", addr);
    return 0;
}

void    Main_Bus::store_addr(uint16_t addr, uint8_t val){
    uint16_t dev_i;
    Bus::Bus_Interface *dev;
    for(dev_i = 0; dev_i < device_list.size(); dev_i++){
        dev = device_list[dev_i];
        /* Check if this is the right range */
        if((dev->get_start_addr() <= addr) && (dev->get_stop_addr() >= addr)){
            dev->store_memory(addr, val);
        }
    }

    /* If we didn't find the requested address, display an error*/
    printf("Could not find device with address %d\n", addr);
    return;

}


}