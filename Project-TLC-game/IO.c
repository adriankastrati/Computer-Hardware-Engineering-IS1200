 #include <stdint.h>
#include <pic32mx.h>
#include "graphics.h"
#include <stdbool.h>


void init_io(void){
    //initiate buttons to input
    TRISDSET = 0x7 << 5;
}

int getbtns(void){
    return (PORTD >> 5) & 0xE;
}

bool btn_right(){
    if((PORTD >> 5) & 0x1) return true;

    else return false;
}

bool btn_up(){
    if((PORTD >> 6) & 0x1) return true;

    else return false;
}

bool btn_left(){
    if((PORTD >> 7) & 0x1) return true;

    else return false;
}