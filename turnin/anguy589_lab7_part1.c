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
	DDRB = 0xFF; PORTB = 0x00;
	DDRD = 0xFF; PORTD = 0x00;	

    //lower 8 bits on portB PB[7:0]
    //upper 2 bits on portD PD[1:0]

    ADC_init();
    while (1) {
	    unsigned short x = ADC;
	
	    unsigned char byte = (char)x;
	    unsigned char halfNibble = (char)(x >> 8);
	    
	    PORTB = byte;
	    PORTD = halfNibble;
    }
    return 1;
}
