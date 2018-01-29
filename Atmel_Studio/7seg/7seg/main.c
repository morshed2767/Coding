/*
 * 7seg.c
 *
 * Created: 10/23/2017 2:05:48 PM
 * Author : user-16
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>



int main(void)
{
    DDRC = 0xff;
	DDRB = 0xff;
	char val[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0xff, 0x6f}; 
	while (1)
    {
		int i=0;
		for(i; i<=9; i++ ){
			PORTB = val[i];
			
			int j=0;
			for(j;j<=9;j++){
				PORTC = val[j];
				_delay_ms(1000);
			}
			
		}
		
		
    }
}

