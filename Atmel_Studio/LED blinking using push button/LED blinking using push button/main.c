/*
 * LED blinking using push button.c
 *
 * Created: 10/19/2017 8:48:01 AM
 * Author : user-16
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>


int main (void)
{
	DDRC &=(0<<PC0);
	DDRD |= (1<<PD0);
	uint8_t inputTemp=0;
	
    /* Replace with your application code */
    while (1) 
    {
		inputTemp=PINC & 0x01;
		if (inputTemp ==(0x00))
		{PORTD |=(1<<PD0);}
			else
			{PORTD &=~ (1<<PD0);}
			}
		return 0;
		}
    


