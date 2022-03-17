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
int timeoutcount = 0;

/* Interrupt Service Routine */
void user_isr( void ){
  
  return;
}

/* Lab-specific initialization goes here */
void labinit( void ){
  volatile int *p_TRISE =  0xbf886100;
  *p_TRISE &= ~0xff; 

  volatile int *p_PORTE = 0xbf886110;
  *p_PORTE &= ~0xff;

  TRISD &= 0xfe0;

  //Timer 2 operates at 80 MHz


  //clears timer 2 bit 15, stops timer
  T2CONCLR = 1 << 15;
 
  //prescale 256
  T2CONSET = 0x7 << 4;

  //seperate timer
  T2CONCLR = 1 << 3;

  //internal timer
  T2CONCLR = 1 << 1;

  //period register to 31250
  PR2 = 0x7a12;
  
 //resets the timervalue
  TMR2 = 0x0;

  //clear IF2
  IFSCLR(0) = 1 << 8;

  //start timer
  T2CONSET = 1 << 15;

  /*
  //sets period register
  PR2 = 0x7a12;

  //resets the timervalue
  TMR2 = 0x0;

  //clear IF2
  IFSCLR(0) = 1 << 8;

  //T2CON = 0000000001110000;

  T2CONSET = 1 << 15;
  */
}

/* This function is called repetitively from the main program */
void labwork( void ){  
  int button_value = getbtns() & 0x3;
  int switch_value = getsw() & 0xf;
  
  int btn_2 = getbtns() & 0x1;
  int btn_3 = (getbtns() >> 1) & 0x1;
  int btn_4 = (getbtns() >> 2) & 0x1;
  int count = 0;


  //int switch_value = getsw() & 0xf;

  if(btn_4){
    int new_time = (mytime & 0x0fff) | (getsw() << 12);
    mytime = new_time; 
  }
  
  if(btn_3){
    int new_time = (mytime & 0xf0ff) | (getsw() << 8);
    mytime = new_time;  
  }

  if(btn_2){
    int new_time = (mytime & 0xff0f) | (getsw() << 4);
    mytime = new_time;  
  }


  //period register when timer hiys


  //resets time-out event-flag
  
  if( (IFS(0) >> 8) & 1){ 
    timeoutcount++;
    
    //clear flag
    IFSCLR(0) = 1 << 8;
  }

  if(timeoutcount == 10){
    time2string( textstring, mytime );
    display_string( 3, textstring );
    display_update();


    tick( &mytime );
    
    // update lighs
    volatile int *p_PORTE = 0xbf886110;
    *p_PORTE = (*p_PORTE & ~0xff) + (((char) *p_PORTE & 0xff) + 1);
    
    display_image(96, icon);
    timeoutcount = 0;
  }
  

}