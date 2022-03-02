#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "graphics.h"  /* Declatations for these labs */ 
 #include <stdbool.h>

void init_timer(){
    //stops timer 
    T2CONCLR = 1 << 15;
    
    //clears timer 2 to 0
    TMR2 = 0x0;

    //Period register
    PR2 = 0x30d4;

    //internal clock
    //T2CONCLR = 1 << 1;
    
  
    //sets prescale
    T2CONSET = 7 << 4;
  /*
    IPCSET(2) = 0xC;

    IPCSET(2) = 0x1;

    IFSCLR(2) = 0x4;
    */
}


