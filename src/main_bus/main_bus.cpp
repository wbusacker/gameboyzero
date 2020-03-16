#include <main_bus.h>
#include <stdio.h>

namespace Bus{


Main_Bus::Main_Bus(){
    num_loaded_devices = 0;    
}

void Main_Bus::attach_device(Bus::Bus_Interface *dev){
    printf("Adding device located at %016lX\n", reinterpret_cast<uint64_t>(dev));
    fflush(stdout);
    device_list[num_loaded_devices++] = dev;
}

uint8_t Main_Bus::fetch_addr(uint16_t addr){

    printf("[READ] ADDR = %04X\n",addr);
    fflush(stdout);

    uint16_t dev_i;
    Bus::Bus_Interface *dev;
    for(dev_i = 0; dev_i < num_loaded_devices; dev_i++){
        dev = device_list[dev_i];
        // printf("Device %d @ %016lX\n", dev_i, reinterpret_cast<uint64_t>(dev));
        fflush(stdout);
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

    printf("[STOR] ADDR = %04X DATA = %02X\n",addr, val);
    fflush(stdout);

    uint16_t dev_i;
    Bus::Bus_Interface *dev;
    for(dev_i = 0; dev_i < num_loaded_devices; dev_i++){
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