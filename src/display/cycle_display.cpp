#include <display.h>
#include <stdio.h>

namespace Graphics {

void Display::cycle_display() {

    update_control_registers();

    /* If the display is off, don't do anything */
    // if(lcdc.operation == false){
    //     return;
    // }

    display_counter++;
    mode_counter++;

    bool updated_hline = false;
    bool updated_mode  = false;

    // printf("Mode %d Counter %d ", stat.mode, mode_counter);

    switch (stat.mode) {
        case MODE_0:
            if (mode_counter == MODE_0_CYCLE_COUNT) {
                stat.mode = MODE_2;
                // printf("\n-> Mode 2");
                // fflush(stdout);
                updated_mode = true;
            }
            break;

        case MODE_1:

            /* During Mode 1 keep upping the h_line when appropriate    */

            if ((mode_counter % H_LINE_CYCLE_COUNT) == 0) {
                h_line++;
                updated_hline = true;
            }

            if (mode_counter == MODE_1_CYCLE_COUNT) {
                stat.mode = MODE_0;
                // printf("\n-> Mode 0");
                // fflush(stdout);
                h_line        = 0;
                updated_hline = true;
                updated_mode  = true;
            }
            break;

        case MODE_2:
            if (mode_counter == MODE_2_CYCLE_COUNT) {
                stat.mode = MODE_3;
                // printf("\n-> Mode 3");
                // fflush(stdout);
                updated_mode = true;
            }
            break;

        case MODE_3:
            if (mode_counter == MODE_3_CYCLE_COUNT) {
                stat.mode = MODE_0;
                // printf("\n-> Mode 0");
                // fflush(stdout);
                h_line++;
                updated_hline = true;
                updated_mode  = true;
            }
            break;
    }

    if (updated_hline) {

        // printf("Now on line %d ", h_line);

        if (h_line == DISPLAY_ROW_COUNT) {
            stat.mode    = MODE_1;
            updated_mode = true;
            // printf("\n-> Mode 1");
            // fflush(stdout);
            irq_controller.raise_interrupt(IRQ::INTERRUPT_BIT_V_BLANK);
        }

        if (h_line == main_memory.fetch_addr(Graphics::LYC_ADDR)) {
            stat.lyc_coincidence = true;
            irq_controller.raise_interrupt(IRQ::INTERRUPT_BIT_LCDC);
        } else {
            stat.lyc_coincidence = false;
        }

        main_memory.store_addr(Graphics::LY_ADDR, h_line);
    }

    if (updated_mode) {

        mode_counter = 0;

        switch (stat.mode) {
            case MODE_0: /* Do nothing, HBLANK                   */
                perform_mode_0(h_line);
                break;

            case MODE_1: /* Render Image                         */
                perform_mode_1(h_line);
                break;

            case MODE_2: /* Write line grayscale buffer to image */
                perform_mode_2(h_line);
                break;

            case MODE_3: /* Write line to grayscale buffer       */
                perform_mode_3(h_line);
                break;
        }
    }
}

}    // namespace Graphics