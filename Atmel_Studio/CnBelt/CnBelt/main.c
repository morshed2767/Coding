/*
 * CnBelt.c
 *
 * Created: 11/19/2017 12:23:21 PM
 * Author : Lenovo
 */ 

#define F_CPU 80000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRB = 0xff;
	DDRC = 0x00;
	DDRD = 0xff;
	PORTC = 0x00;
	
	PORTB &= ~(1<<PB2);
    while (1) 
    {
		int x=0;
		x = (PINC &(1<<PC0));
		if(x==1){
			PORTD |= (1<<PD0);
		}
		if(x==0)
		{
			PORTD &= ~(1<<PD0);
		}
		
    }
}

