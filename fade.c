/*** blink.c – Blink a LED at PB5, repeatedly  -*- C -*- */
#include <avr/io.h>             /* for DDRB, PORTB, etc. */
#include <util/delay.h>         /* for _delay_ms () */
#include <stdio.h>


//hello


void main()
{
	uint8_t brightness = 230;
	uint8_t pin = DDD6;
	uint8_t fadeAmount = 1;


    DDRD |= (1 << pin);
    // PD6 is now an output

    OCR0A = brightness;
    // set PWM for duty cycle


    TCCR0A |= (1 << COM0A1);
    // set none-inverting mode

    TCCR0A |= (1 << WGM01) | (1 << WGM00);
    // set fast PWM Mode

    TCCR0B |= (1 << CS02);
    // set prescaler to 256 and starts PWM


   while (1)
   {
    	OCR0A = brightness;
    	brightness = brightness + fadeAmount;
    	if (brightness <= 10 || brightness >= 245) {
    	fadeAmount = -fadeAmount;
  		}
  		if (brightness <= 100){
  		_delay_ms (15);
  		}
  		if (brightness <= 50){
  		_delay_ms (50);
  		}
  		_delay_ms (20);
    }
}

