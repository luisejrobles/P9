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
	char str[20];
	
	//DDRB = (1<<PB7);			//Puerto b salida
	//UART0_Init(0);			//Inicializando UART0
	
	UART0_AutoBaudRate();
	UART0_puts("\n\rAutobauding done. UBRR0=");
	itoa(str,UBRR0,10);
	UART0_puts(str);
	UART0_puts("\n\r");
	
	Timer2_Init(2);
	Clock_Ini(23,59,55);
    /* Replace with your application code */
    while (1) 
    {
		
    }
}

