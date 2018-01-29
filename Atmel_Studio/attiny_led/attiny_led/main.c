/*
 * attiny_led.c
 *
 * Created: 12/6/2017 12:45:09 PM
 * Author : Lenovo
 */ 
#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>



void InitADC ()
{
	// Set the ADC input to PB2/ADC1, left adjust result
	ADMUX |= (1 << MUX0);
	ADMUX |= (1 << ADLAR);
	
	// Set the prescaler to clock/128 & enable ADC
	ADCSRA |= (1 << ADPS1) | (1 << ADPS0) | (1 << ADEN);
}



int adc_read (void)
{
	// Start the conversion
	ADCSRA |= (1 << ADSC);

	// Wait for it to finish
	while (ADCSRA & (1 << ADSC));

	return ADCH;
}

int main(void)
{
	
	
	int adc_in;
	DDRB |= (1<<PB0);
	PORTB = 0;
	
	InitADC();
	while (1)
	{
		
		adc_in = adc_read();
		
		if (adc_in > 128)
		{
			PORTB |= 1<<PB0;
		}
		else
		{
			PORTB &= ~(1<<PB0);
		}
		
	}
}
