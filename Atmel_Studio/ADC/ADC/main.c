/*
 * ADC.c
 *
 * Created: 11/13/2017 8:09:13 PM
 * Author : Lenovo
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define BAUD 19200
#define MYUBRR    F_CPU/16/BAUD-1

void init_uart(unsigned short uValue){
	// setting the baud rate
	UBRR0H =(unsigned char)  ( uValue>> 8);  // 0x00
	UBRR0L =(unsigned char) uValue;  // 0x0C
	// enabling TX & RX
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	//UCSR0B = (1<<RXEN0)|(1<<TXEN0)|(1<<RXCIE0);
	UCSR0A = (1<<UDRE0);
	UCSR0C =  (1 << UCSZ01) | (1 << UCSZ00);    // Set frame: 8data, 1 stop

}

void uart_transmit(unsigned char data){
	while(!(UCSR0A & (1<<UDRE0))){};
	UDR0 = data;
}

unsigned uart_receive(void){
	while(!(UCSR0A) & (1<<RXEN0)){};
	PORTC = UDR0;
}

//Initialize ADC
void adc_init(){
	ADMUX = (1<<REFS0);
	//Prescaler of 128
	ADCSRA  = (1<<ADEN) | (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0);
	
}

//Read ADC value
uint16_t adc_read(uint8_t ch){
	ch &=0xf0;
	ADMUX |= ch;
	ADCSRA |=(1<<ADSC);
	while(ADCSRA & (1<<ADSC));
	return ADC;
}

void led_init(){
	DDRB |= (1<<PB5);
}

int main ()
{
	uint16_t res;
	init_uart(MYUBRR);
	adc_init();
	led_init();
	while(1){
		res = adc_read(0);
		char buffer [20];
		itoa (res,buffer,10);

		for (int j=0; j<20;j++)
		{
			//printf(buffer);
			PORTD ^= (1<< PD7);
			UDR0 = buffer[j];
			_delay_ms(5);
		}
		//uart_transmit(res);
		if(res>=512){
			PORTB |= (1<<PB5);
			//_delay_ms(100);
		}else{
			PORTB &= ~(1<<PB5); 
			//_delay_ms(100);
		}
	}
	return 0;
}
