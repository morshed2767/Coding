/*
 * batman3.c
 *
 * Created: 10/23/2017 9:15:07 AM
 * Author : user-16
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRD = 0xff;
	DDRB = 0xff;
	DDRC = 0xff;
	while (1)
	{
		
		int m=0;
		for(m;m<8;m+=2){
			PORTC |=(1<<(PC0+m));
			_delay_ms(50);
		}
		
		int n=7;
		for(n;n>=0;n-=2){
			PORTC &=~(1<<(PC0+n));
			_delay_ms(50);
		}
		
		int a=7;
		for(a;a>=0;a--){
			PORTB |=(1<<(PB0+a));
			_delay_ms(50);
		}
		
		int b=0;
		for(b;b<8;b++){
			PORTB &=~(1<<(PB0+b));
			_delay_ms(50);
		}
		
		
		int j=3;
		for(j;j>=0;j--){
			PORTD |=(1<<(PD0+j));
			_delay_ms(50);
		}
		
		int l=0;
		for(l;l<4;l++){
			PORTD &= ~(1<<(PD0+l));
			_delay_ms(50);
		}
		
		int i=4;
		for(i;i<8;i++){
			PORTD |= (1<<(PD0+i));
			_delay_ms(50);
		}

		
		int k=7;
		for(k;k>=4;k--){
			PORTD &= ~(1<<(PD0+k));
			_delay_ms(50);
		}
		
	}
}


