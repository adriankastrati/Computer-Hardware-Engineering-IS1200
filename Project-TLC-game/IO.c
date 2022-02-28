 #include <stdint.h>
#include <pic32mx.h>
#include "graphics.h"


void init_io(void){
    TRISD |= 0xfe0;
}

int getbtns(void){
    return (PORTD >> 5) & 0x7;
}

char btn_right(){
    if (getbtns() & 0x1)
        return 1;
    else
        return 0;
}

char btn_p(){
    if((getbtns() >> 1) & 0x1)
        return 1;
    else
        return 0;
}

char btn_left(){
    if((getbtns() >> 2) & 0x1)
        return 1;
    else
        return 0;
}

char btns_released(){
    return (btn_left() == 0 && btn_right() == 0 && btn_right() == 0);
}