#include <xc.h>
#include <stdint.h>
#include "config.h"
#define _XTAL_FREQ 4000000

 uint16_t c=0;
 int time_out=0;
 int time_out1=0;
 int time_out2=0;
 int next=1;
 void Timer1();
 void Intialization();
 
void main(void) {
    // Set port d and bit(0,1)of port b To Be Output Pin (LED) and port a input sensor
   // TRISA=0b111111;
    TRISD=0x00;
    TRISB=0b11110000;
    // Set The Initial State Of RB0 To Be OFF
    PORTD=0x00;
    PORTB=0x00;
    Timer1();
    // Write The System's Main Routine
    while(1)
    {
        //street 0
        if(RB4==1 && next==1)
        {
           Intialization();
         
          PORTD=0b00100010;
          PORTB=0b00001001;
        
        if(time_out1==1) //for traffic green
        { PORTD=0b00100001;
            PORTB=0b00001001;}
          
         if(time_out2==1)    //for traffic yellow 
         { PORTD=0b00100010;  
             PORTB=0b00001001;}
          
          if(time_out==1){
              next=2;
          }} else{next=2;}
        
        //street 1
        if(RB5==1 && next==2)
        {
            Intialization();
          
            PORTD=0b00010100;
           PORTB=0b00001001;
         
         if(time_out1==1) //for traffic green of S1
        { PORTD=0b00001100;
             PORTB=0b00001001;}
           
         if(time_out2==1)      //for traffic yellow 
         {PORTD=0b00010100;  
             PORTB=0b00001001;}
           
           if(time_out==1){
               next = 3;
           }
        }else{next=3;}
        
    // street 2
        if(RB6==1 && next==3)
        {
            Intialization();
        
          PORTD=0b10100100;
          PORTB=0b00001000;
           
        if(time_out1==1)   //for traffic green of S2
        { PORTD=0b01100100;
            PORTB=0b00001000;}
          
         if(time_out2==1)    //for traffic yellow of S2
         {  PORTD=0b10100100;  
            PORTB=0b00001000;}
          
          if(time_out==1){
              next = 4;
          }}else{next=4;}
        
      //street 3 
        if(RB7==1 && next==4)
        {
            
          Intialization();
          //for traffic yellow of S3
          PORTD=0b00100100;
          PORTB=0b00000101;
          
        if(time_out1==1)      //for traffic green of S3  
         {  PORTD=0b00100100;  
            PORTB=0b00000011;}
          
         if(time_out2==1)     //for traffic yellow of S3
         {  PORTD=0b00100100;  
            PORTB=0b00000101;}
          
          if(time_out==1){
              next = 1;
          }
        }else{next=1;}
       }
    return;
}

void Timer1(){
    //---[Enable TMR1 Interrupt]---
    TMR1IE=1;
    PEIE=1;
    GIE=1;
    //---[Configure Timer Module To Operate in Timer Mode]---

    // Clear The TMR1 Register, to start counting from 0
    TMR1=15536;
    // Select The Local Clock as TMR1 Clock Source
    TMR1CS=0;
    // Set The Pre-scaler To 1:1
    T1CKPS0=0;
    T1CKPS1=0;
    // Turn ON TMR1 Module !
    TMR1ON=1;
}

// intialize flags
void Intialization()
{ 
         time_out=0;
         time_out1=0;
         time_out2=0;  
         c=0;
}


// Write The ISR Handler
void __interrupt() ISR(void)
{
    if(TMR1IF)
    {
        TMR1=15536;
        c++;
        if(c==60)
        time_out1=1;
        
        if(c==160)
           time_out2=1;
       
        if(c==220){
            time_out=1;
            c=0; 
        }
               
        TMR1IF=0;
    }
}