/*void init_timer(){
    //stops timer 
    T2CONCLR = 1 << 15;

    //internal clock
    T2CONCLR = 1 << 1;
    
    //sets timer 2 to 0
    TMR2 = 0x0;

    //sets prescale
    T2SET = 7 << 4;
    
    //Period register
    PR2 = 0x7a12;

    IPC2SET = 0xC;

    IPC2SET = 0x1;

    IFSCLR(2) = 0x4;
}
*/