/*
 * TimerCounter.c
 *
 * Created: 10/29/2017 2:43:44 PM
 * Author : user-16
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <avr/interrupt.h>

volatile uint8_t timerVariable  = 0;
ISR(TIMER0_OVF_vect){
	timerVariable++;
	if(timerVariable >= 0){
		timerVariable = 0;
		PORTB ^= (1<<PORTB5);
	}
}

int main(void){
	DDRB = 0x20;
	TCCR0B =0x5; // timer clock =I/O clock/256
	TIFR0 = 1<<TOV0; //clear overflow flag
	TIMSK0 = 1<<TOIE0; //enable overflow interrupt
	sei(); //set external interrupt **cli() disable external interrupt
	while(1){
		
	}

}

