#include <cartridge.h>

namespace Cart {

enum Cartridge_Type determine_cart_type(FILE *fp) {

    /* Scan ahead to address 147 */
    fseek(fp, 0x147, SEEK_SET);

    uint8_t type = fgetc(fp);

    fseek(fp, 0, SEEK_SET);

    switch (type) {
        case 1:
        case 2:
        case 3:
            return CART_MBC1;
        default:
            return CART_UNKNOWN;
    }
    return CART_UNKNOWN;
}

}    // namespace Cart