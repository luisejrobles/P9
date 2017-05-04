#include <avr/io.h>
#include "Timer0.h"
#include "UART.h"
#include "Clock.h"


int main()
{

	UART0_Init(0);	//iniciando 2560 9600 BR
	timer0_CTC();	//Iniciando timer0
	//Clock_Ini(11,59,54);	
	while(1){ 

	}
}