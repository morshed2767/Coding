/*
 * HBridgeMotor.c
 *
 * Created: 11/16/2017 3:32:10 PM
 * Author : Lenovo
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    DDRC = 0xff;
    while (1) 
    {
		PORTC = 0b00001100;
		//PORTB &= ~((1<<PB0) | (1<<PB3))
		_delay_ms(2000);
		PORTC = 0b00000011;
		_delay_ms(2000);
		//PORTB = (1<<PB1) | (1<<PB2);
    }
}

