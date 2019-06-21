//***************************************************************************************
//  MSP430 Blink the LED Demo - Software Toggle P1.0 and P1.6
//
//  Description; Toggle P1.0 and P1.6 by xor'ing the status inside of a software loop.
//  ACLK = n/a, MCLK = SMCLK = default DCO
//
//                MSP430x5xx
//             -----------------
//         /|\|              XIN|-
//          | |                 |
//          --|RST          XOUT|-
//            |                 |
//            |             P1.0|-->LED1
//            |             P1.6|-->LED2
//
//  author: Thiago Marques Siqueira
//***************************************************************************************

#include <msp430.h>

int main(void) {
	WDTCTL = WDTPW | WDTHOLD;		// Stop watchdog timer
	P1DIR |= 0x41;					// Set P1.0 and P1.6 to output direction

	for(;;) {
		volatile unsigned int i;	// volatile to prevent optimization

		P1OUT ^= 0x41;				// Toggle P1.0 and P1.6 using exclusive-OR

		i = 30000;					// SW Delay
		do i--;
		while(i != 0);
	}
	
	return 0;
}
