  
/*	Author: anguy589
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #7  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 *
 *	Demo Link:
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

void ADC_init() {
	ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);

}

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRB = 0x00; PORTB = 0xFF;
	

	//max: 511, min = 23	

   unsigned short MAX = 511;
 
    ADC_init();
    while (1) {
	    unsigned short x = ADC;
	
		if(x >= (MAX/2)) {
			PORTB = 0x01;	
		}
		else if(x < (MAX/2)) {
			PORTB = 0x00;		
		}
	    
    }
    return 1;
}
