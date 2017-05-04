#include <avr/io.h>
#include "Timer0.h"
#include "UART.h"
#include "Clock.h"


int main()
{

	UART0_Init(0);
	timer0_CTC();
	Clock_Ini(0,10,15);
	while(1){ 

	}
}