/*
 * Project1.c
 *
 * Created: 10/18/2017 1:49:30 PM
 * Author : user-16
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRD |=(1<<PD0);//data direction register
	

		
    /* Replace with your application code */
    while (1) 
    {
		PORTD |=(1<<PD0);// port output
		_delay_ms(1000);
		PORTD &=(0<PD0);//port output
		_delay_ms(100);
		
		
    }
	return 0;
}

