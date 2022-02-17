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
int prime = 1234567;
int mytime = 0x5957;

char textstring[] = "text, more text, and even more text!";
int timeoutcount = 0;

/* Interrupt Service Routine */
void user_isr( void ){
  timeoutcount++;

  if(timeoutcount == 10){
    time2string( textstring, mytime );
    display_string( 3, textstring );
    display_update();
    tick( &mytime );

    timeoutcount = 0;
  }
    IFSCLR(0) = 1 << 8;

}

/* Lab-specific initialization goes here */
void labinit( void ){
  volatile int *p_TRISE =  0xbf886100;
  *p_TRISE &= ~0xff; 
  volatile int *p_PORTE = 0xbf886110;
  *p_PORTE &= ~0xff;
  TRISD &= 0xfe0;
   
  //stop timer 2
  T2CONCLR = 1 << 15;

  //clear timer
  TMR2 = 0x0;
  
  //period register
  PR2 = 0x7a12;
  
  //prescale
  T2CONSET = 7 << 4;
  
  IPCSET(2) = 0x3f;

  //clear flag
  IFSCLR(0) = 1 << 8;

  // enable timer interrupts  
  IECSET(0) = 1 << 8;

  enable_interrupt();

  //start timer
  T2CONSET = 1 << 15;
  
  //configure and set the subpriority levels in IPC2 register
  //Set the T2IE interrupt enable bit in the IEC2

}

/* This function is called repetitively from the main program */
void labwork( void ){  
  prime = nextprime( prime );
  display_string( 0, itoaconv( prime ) );
  display_update();
}