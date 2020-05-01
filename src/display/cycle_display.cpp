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
    bool updated_mode = false;

    switch(stat.mode){
        case MODE_0:
            if(mode_counter == MODE_0_CYCLE_COUNT){
                mode_counter = 0;
                stat.mode = MODE_2;
                // printf("\n-> Mode 2");
                // fflush(stdout);
                updated_mode = true;
            }
            break;

        case MODE_1:
            if(mode_counter == MODE_1_CYCLE_COUNT){
                mode_counter = 0;
                stat.mode = MODE_0;
                // printf("\n-> Mode 0");
                // fflush(stdout);
                h_line = 0;
                updated_hline = true;
                updated_mode = true;
            }
            break;

        case MODE_2:
            if(mode_counter == MODE_2_CYCLE_COUNT){
                mode_counter = 0;
                stat.mode = MODE_3;
                // printf("\n-> Mode 3");
                // fflush(stdout);
                updated_mode = true;
            }
            break;

        case MODE_3:
            if(mode_counter == MODE_3_CYCLE_COUNT){
                mode_counter = 0;
                stat.mode = MODE_0;
                // printf("\n-> Mode 0");
                // fflush(stdout);
                h_line++;
                updated_hline = true;
                updated_mode = true;
            }
            break;
    }

    if(h_line >= DISPLAY_ROW_COUNT){
        if((mode_counter % H_LINE_CYCLE_COUNT) == 0){
            h_line++;
            updated_hline = true;
        }
    }

    if(updated_hline){

        if( h_line == DISPLAY_ROW_COUNT){
            stat.mode = MODE_1;
                // printf("\n-> Mode 1");
                // fflush(stdout);
            irq_controller.raise_interrupt(IRQ::INTERRUPT_BIT_V_BLANK);
        }

        if( h_line == main_memory.fetch_addr(Graphics::LYC_ADDR)){
            stat.lyc_coincidence = true;
            irq_controller.raise_interrupt(IRQ::INTERRUPT_BIT_LCDC);
        } else {
            stat.lyc_coincidence = false;
        }

        main_memory.store_addr(Graphics::LY_ADDR, h_line);

    }

    if(updated_mode){

        pthread_mutex_lock(&list_lock);

        struct Mode_List* entry = new struct Mode_List;

        entry->mode = stat.mode;
        entry->next = NULL;

        /* If the list is empty, set the new head at entry  */
        if(mode_list == NULL){
            mode_list = entry;
        } else {

            /* Find the end of the list */
            struct Mode_List* next = mode_list;
            next = mode_list;
            while(next->next != NULL){
                next = next->next;
            }

            next->next = entry;

        }

        pthread_mutex_unlock(&list_lock);
       
        sem_post(&frame_sync);

    }

}

}    // namespace Graphics