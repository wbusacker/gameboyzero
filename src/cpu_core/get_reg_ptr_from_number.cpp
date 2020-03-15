#include <cpu_core.h>
#include <unistd.h>

namespace CPU{

uint8_t* LR35902::get_reg_ptr_from_number(uint8_t num){

    num &= 0b111;

    switch(num){
        case 0b000:
            return &B;

        case 0b001:
            return &C;

        case 0b010:
            return &D;

        case 0b011:
            return &E;

        case 0b100:
            return &H;

        case 0b101:
            return &L;

        case 0b110:
            return NULL;

        case 0b111:
            return &A;
    }

    return NULL;
    
}

}