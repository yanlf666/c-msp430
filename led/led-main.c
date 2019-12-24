

#include <msp430.h>

int main(void)
{

     WDTCTL =  WDTPW | WDTHOLD;

     PM5CTL0 &= ~LOCKLPM5;

     unsigned int i = 0;
     
     P1DIR |= BIT0;
     P1OUT |= BIT0;
    
     
     
     while(1)
     {
	  P1OUT ^= BIT0;
	   __delay_cycles(100000);
	  
     }
}
