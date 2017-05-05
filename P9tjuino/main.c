/*
 * P9tjuino.c
 *
 * Created: 03/05/2017 10:03:15 p. m.
 * Author : LuisEduardo
 */ 

#include <avr/io.h>
#include "Timer2.h"
#include "UART.h"
#include "Clock.h"


int main(void)
{
	UART0_Init(0);
	Timer2_Init(4);
	Clock_Ini(23,59,55);
    /* Replace with your application code */
    while (1) 
    {
		
    }
}

