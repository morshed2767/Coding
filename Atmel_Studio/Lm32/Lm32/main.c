/*
 * Lm32.c
 *
 * Created: 11/20/2017 12:15:53 PM
 * Author : Lenovo
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
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

void adc_init(){
	ADMUX = (1<<REFS0);
	//Prescaler of 128
	ADCSRA  = (1<<ADEN) | (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0);
}

//Read ADC value
uint16_t adc_read(uint8_t ch){
	// select the corresponding channel 0~7
	// ANDing with ’7? will always keep the value
	// of ‘ch’ between 0 and 7
	ch &= 0b00000111;  // AND operation with 7
	ADMUX = (ADMUX & 0xF8)|ch; // clears the bottom 3 bits before ORing
	
	// start single convertion
	// write ’1? to ADSC
	ADCSRA |= (1<<ADSC);
	
	// wait for conversion to complete
	// ADSC becomes ’0? again
	// till then, run loop continuously
	while(ADCSRA & (1<<ADSC));
	
	return (ADC);
}

int main(void)
{
	DDRC = 0x00;
    uint16_t res;
    init_uart(MYUBRR);
    adc_init();
    while (1) 
    {
		res = adc_read(0);
		uint16_t mv = (res/1024)*5000;
		uint16_t cel = 10;
		char buffer [20];
		itoa (res,buffer,10);
		for (int j=0; j<20;j++)
		{
			//printf(buffer);
			UDR0 = buffer[j];
			_delay_ms(5);
		}
		
		_delay_ms(1000);
    }
}

