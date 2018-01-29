/*
 * BCDto7seg.c
 *
 * Created: 10/24/2017 8:46:40 AM
 * Author : user-16
 */ 

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    DDRC = 0xff;
    while (1) 
    {
		int i,j;
		for(i=0; i<=9; i++){
			
			for(j=0; j<=9; j++){
				PORTC = i|j<<4;
			_delay_ms(500); 
			}
		}
	}
}
