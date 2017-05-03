/*
 * P9.c
 *
 * Created: 28/04/2017 05:10:11 p. m.
 * Author : LuisEduardo
 */ 

#ticks = 1m/(16Mhz/64) = 250 -1
F_TIMER = F_CPU/PS

#include <avr/io.h>

void Timer0_1m(void)
{
	TCNT0 = 0 //Clear timer
	TCCR0A = 2<<WGM00;
	TCCR0B =  3<<CS00;
	OCR0A = 250-1;
	
	while( !(TIFR0 & (1<<OCF0A)) );
	
	TIFR0|= (1<<OCF0A);
}

OV 0-255
	
//==================CRISTAL TJUINO===========================	
	
#ticks = 1s/(1/(32768Hz)/PS-1) = 32768/-1

void Timer0_1m(void)
{
	TIMSK2 = 0;
	ASSR = (1<<AS2);
	
	
	TCNT2 = 0 //Clear timer
	TCCR2A = 2<<WGM00;
	TCCR2B =  5<<CS00;
	OCR2A = 256-1;
	
	while( ASSR&((1<<TCN2UB)|(1<<OCR2AUB)|(1<<OCR2BUB)|(1<<TCR2AUB)|(1<<TCR2BUB) ));
	
	TIFR2= (7<<TOV2);
	TIMSK2 |= 1<< OCIE2A;
}

//=======================================================================================
int main(void)
{
    /* Replace with your application code */
    while (1) 
    {
    }
}

