/*
 * dotmatrix.c
 *
 * Created: 10/25/2017 2:09:33 PM
 * Author : user-16
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    DDRC = 0xff;
	DDRD = 0xff;
    while (1) 
    {
		PORTD = ~1;
		//PORTC =2;
		int i;
		for(i=0; i<5; i++){
			PORTC |= (1<<i); 
			_delay_ms(200);
			PORTC &= ~(1<<i);
		}
    }
}

