/*
 * multiplexer.c
 *
 * Created: 10/24/2017 1:43:59 PM
 * Author : user-16
 */ 

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    DDRC = 0xff;
	DDRD = 0xff;
	char degits[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0xff, 0x6f};
    while (1) 
    {
		
		int i,j;
		for(i=0;i<=9; i++)
		{
			for(j=0; j<=9; j++)
			{
				PORTD = 1;
				PORTC = degits[i];
				_delay_ms(500);
				PORTD = 2;
				PORTC = degits[j];
				_delay_ms(500);
			}
			
		}
    }
}

