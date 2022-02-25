 #include <stdint.h>
#include <pic32mx.h>
#include "graphics.h"


void init_io(void){
    TRISDSET = 0x70;
}

int getbtns(void){
    return (PORTD >> 4) & 0xE;
}
/*
char btn_left(){
    if (getbtns() & 0x1)
        return 1;
    else
        return 0;
  
}

char btn_right(){
    if((getbtns() >> 2) & 0x1)
        return 1;
    else
        return 0;
}

char btn_p(){
    if((getbtns() >> 1) & 0x1)
        return 1;
    else
        return 0;
}*/

char btn_left(){
    if (getbtns() & 0x1)
        return 1;
    else
        return 0;
  
}

char btn_right(){
    if((getbtns() >> 2) & 0x1)
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


