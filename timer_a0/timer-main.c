

#include <msp430.h>

int main(void)
{
     
     WDTCTL = WDTPW | WDTHOLD;
     PM5CTL0 &= ~LOCKLPM5;

     unsigned int cnt = 0;

     
     P1DIR |= BIT0;
     P1OUT |= BIT0;

     TA0CCTL0 = CCIE;
     TA0CCR0 = 20000;
     TA0CTL = TASSEL__SMCLK | MC__CONTINOUS;

     __bis_SR_register(LPM0_bits + GIE);
     __no_operation();
     while(1)
     {
	  
     }
}

// Timer0_A0 interrupt service routine

void __attribute__ ((interrupt(TIMER0_A0_VECTOR)))  Timer0_A0_ISR (void)
{
     
     
     if(cnt >= 100)
     {
	  cnt = 0 ;
	  P1OUT ^= BIT0;
	  TA0CCR0 += 20000;
	  
     }
     else
     {
	  cnt++;
     }
    
}
