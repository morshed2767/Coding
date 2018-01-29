/*
 * GccApplication1.c
 *
 * Created: 10/23/2017 8:14:46 AM
 * Author : user-16
 */ 

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRD = 0xff;
    while (1) 
    {
		int i=0;
		for(i;i<8;i++){
			PORTD |= (1<<(PD0+i));
			_delay_ms(100);
			PORTD &= ~(1<<(PD0+i));
			_delay_ms(100);
		}
		int j=7;
		for(j;j>=0;j--){
			PORTD |= (1<<(PD0+j));
			_delay_ms(100);
			PORTD &= ~(1<<(PD0+j));
			_delay_ms(100);
		}
		
    }
}

