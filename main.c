#include <xc.h>
#include "confrig.h"
#define _XTAL_FREQ 4000000
void Timer1();
void Intialization();

int a=0,b=0,c=0,d=0,e=0;
int a1=0,b1=0,c1=0,d1=0,e1=0;


void main(void) {
  TRISB = 0xff;//input
  TRISD = 0x00;//output
  PORTD = 0x00;
  Timer1();
  
  while(1)
  {
      
      if(RB0){
          a = 0;
          a1=1;
          PORTDbits.RD0=1;
      }
      if(RB1){
          b = 0;
          b1=1;
          PORTDbits.RD1=1;
      }
      if(RB2){
          c = 0;
          c1=1;
          PORTDbits.RD2=1;
      }
      if(RB3){
          d = 0;
          d1=1;
          PORTDbits.RD3=1;
      }
      if(RB4){
          e = 0;
          e1=1;
          PORTDbits.RD4=1;
      }
      
      
     
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

/*void Intialization()
{
time_out=0;
time_out1=0;
time_out2=0;
c=0;
}*/
// Write The ISR Handler
void interrupt ISR(void)
{
if(TMR1IF)
{
TMR1=15536;
a++;
b++;
c++;
d++;
e++;
if(a==10&&a1==1){//30
PORTDbits.RD0=0;
a1=0;}

if(b==10&&b1==1){//30
PORTDbits.RD1=0;
b1=0;}

if(c==10&&c1==1){//30
PORTDbits.RD2=0;
c1=0;}

if(d==10&&d1==1){//30
PORTDbits.RD3=0;
d1=0;}

if(e==10&&e1==1){//30
PORTDbits.RD4=0;
e1=0;}

}
TMR1IF=0;
}



