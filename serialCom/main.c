/*
 * Project3.c
 *
 * Created: 2/1/2018 2:58:58 PM
 * Author : john
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "EmSys.h"


void delay_usec(unsigned int);
void sw_serial_putc(char c);

int main(void) {
	// init PORTB so that bit 6 (digital pin 12) is set for OUTPUT
	DDRB |= (1 << PB6);  // Remember that this is the DATA DIRECTION register--use PORTB to set/clear bit 6 output
	init_sw_serial_putc_test(9600,SERIAL_8N1);
	
	while(1) {
		sw_serial_putc('U');
		test_sw_serial_putc();
		_delay_ms(1000);
	}
	
	void sw_serial_putc(char c) {
		//char d = c;
		PORTB = 0x40;
		delay_usec(104);
	}
	
	//PORTB &= ~(1 << 6);
	//PORTB |= 1 << 6;
}

