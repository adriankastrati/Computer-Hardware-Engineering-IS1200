#include <stdint.h>   
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#include "graphics.h"
#include <pic32mx.h> 



void init_io(void){
    //initiate buttons to input
    //TRISDSET = 0x7 << 5;
    TRISDSET = 0xfe << 5;
}


bool get_switch1(){
    if((PORTD >> 8) & 0x1) return true;
    else return false;
}

bool get_switch2(){
    if((PORTD >> 9) & 0x1) return true;
    else return false;
}

bool get_switch3(){
 if((PORTD >> 10) & 0x1) return true;

    else return false;    
}

bool get_switch4(){
 if((PORTD >> 11) & 0x1) return true;

    else return false;    
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
char btns_released(){
    return (btn_left() == 0 && btn_right() == 0 && btn_right() == 0);
}
