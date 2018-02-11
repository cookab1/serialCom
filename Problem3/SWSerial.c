/*
 * SWSerial.c
 *
 * Created: 2/10/2018 7:54:40 PM
 *  Author: Andy
 */ 

#include "SWSerial.h"
#include <string.h>

void delay_usec(unsigned int);

void init_sw_serial(int rx_pin, int tx_pin, long baudrate, int framing) {
	rxPin = rx_pin;
	txPin = tx_pin;
	switchBaud(baudrate);
	frameParam = framing;
}



void sw_serial_putc(char c){
	BITBANG(0);
	for(int i = 0; i < 8; i++) {
		BITBANG(c & 1);
		c >>= 1;
	}
	BITBANG(1);
	
}

char sw_serial_getc(void) {
	char c;
	int i;
	//start;//wait for the start bit before we start reading
	for(i = 0; i < 8; i++) {
		c |= rxPin;
		c << 1;
		delay_usec(bitTime);
	}
	
	return c;
}

void sw_serial_puts(char *str) {
	int i;
	int length = strlen(str);
	for(i = 0; i < length; i++) {
		
	}
}

void switchBaud(long baudrate) {
	baud = baudrate;
	bitTime = (1 / baud) * 1000000;
}