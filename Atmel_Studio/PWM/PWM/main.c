/*
 * PWM.c
 *
 * Created: 1/28/2018 2:30:31 PM
 * Author : Lenovo
 */ 

#include <avr/io.h>
#include <util/delay.h>

// initialize PWM
void pwm_init()
{
	// initialize timer0 in PWM mode
	TCCR0 |= (1<<WGM00)|(1<<COM01)|(1<<WGM01)|(1<<CS00);
	
	// make sure to make OC0 pin (pin PB3 for atmega32) as output pin
	DDRB |= (1<<PB3);
}

void main()
{
	uint8_t brightness;
	
	// initialize timer0 in PWM mode
	pwm_init();
	
	// run forever
	while(1)
	{
		// increasing brightness
		//for (brightness = 0; brightness < 255; ++brightness)
		//{
			// set the brightness as duty cycle
			OCR0 = 255;
			
			// delay so as to make the user "see" the change in brightness
			_delay_ms(3000);
		//}
		
		// decreasing brightness
		//for (brightness = 255; brightness > 0; --brightness)
		//{
			// set the brightness as duty cycle
			OCR0 = 200;
			
			// delay so as to make the user "see" the change in brightness
			_delay_ms(2000);
			
			OCR0 = 0;

			// delay so as to make the user "see" the change in brightness
			_delay_ms(1000);
		
		// repeat this forever
	}
}
