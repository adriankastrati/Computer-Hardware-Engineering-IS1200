/* mipslabwork.c

   This file written 2015 by F Lundevall
   Updated 2017-04-21 by F Lundevall

   This file should be changed by YOU! So you must
   add comment(s) here with your name(s) and date(s):

   This file modified 2017-04-31 by Ture Teknolog 

   For copyright and licensing, see file COPYING */

#include <stdint.h>   /* Declarations of uint_32 and the like */
#include <pic32mx.h>  /* Declarations of system-specific addresses etc */
#include "mipslab.h"  /* Declatations for these labs */

int mytime = 0x5957;

char textstring[] = "text, more text, and even more text!";

/* Interrupt Service Routine */
void user_isr( void ){
  
  return;
}

/* Lab-specific initialization goes here */
void labinit( void ){
  //sets bits as output
  volatile int *p_TRISE =  0xbf886100;
  *p_TRISE &= ~0xff; 

  
  volatile int *p_PORTE = 0xbf886110;
  *p_PORTE &= ~0xff;

  // set bits of 1111 1110 000 to input (buttons)
  TRISD |= 0xfe0;

  //add code to initialize Timer 2 for timeouts every 100 ms (that is 10 timeouts per second). 
  //Be prepared to justify your choices of clock-rate divider and time-out period.

  //Timer 2 operates at 80 MHz
/*
  //clears timer 2 bit 15 and 1
  T2CONCLEAR = 1 << 15;
  T2CONCLEAR = 1 << 1;
  
  //resets the timervalue
  TMR2 = 0x0;
  
  //prescale
  T2CONSET = 101 << 4; 

  //turn on timer
  T2CONSET = 1 << 15;
  */
  }

/* This function is called repetitively from the main program */
void labwork( void ){
  int btn_2 = getbtns() & 0x1;
  int btn_3 = (getbtns() >> 1) & 0x1;
  int btn_4 = (getbtns() >> 2) & 0x1;

  int switch_value = getsw() & 0xf;

  if(btn_4){
    int new_time = (mytime & 0x0fff) | (switch_value << 12);
    mytime = new_time; 
  }
  
  if(btn_3){
    int new_time = (mytime & 0xf0ff) | (switch_value << 8);
    mytime = new_time;  
  }

  if(btn_2){
    int new_time = (mytime & 0xff0f) | (switch_value << 4);
    mytime = new_time;  
  }

  volatile int *p_PORTE = 0xbf886110;
  
  //increments value by 1
  *p_PORTE =  ((*p_PORTE & 0xff) + 1);

  delay( 1000 );
  time2string( textstring, mytime );
  display_string( 3, textstring );
  display_update();
  tick( &mytime );

  display_image(96, icon);
}