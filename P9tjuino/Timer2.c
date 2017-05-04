#include <avr/interrupt.h>
#include <inttypes.h>
#include "Clock.h"

static uint8_t Flag;

void Timer2_Init ( uint8_t baseT ){
	TIMSK2 = 0;					//limpiando OCIE2A OCIE2B TOIE2
	ASSR = (1<<AS2);			//modo asincrono
	TCNT2 = 2;					//iniciando timer en 0
	TCCR2A = 0;		
	
	/*esperando que a los registros*/
	while( ASSR&( (1<<TCN2UB)|(1<<OCR2AUB)|(1<<OCR2BUB)|(1<<TCR2AUB)|(1<<TCR2BUB) ) );
	TIMSK2 = 0;					//limpiando las banderas de interrupcion
	TIMSK2 = (1<<TOIE2);		//habilitando interrupcion por overflow
	OCR2A = 256 -1;				//128 PS
	sei();						//habilita interrupciones (global) */
	 Flag = baseT;				//segundos a los cuales llegar
}

uint8_t Timer2_Flag ( void )
{
	if( Flag ){
		Flag = 0;
		return 1;
	}
	else{
		Flag++;
		return 0;
	}
}

ISR (SIG_OUTPUT_COMPARE2A)
{ 
	if(Flag)
	{
		UpdateClock();
		Clock_Display();
	}
}