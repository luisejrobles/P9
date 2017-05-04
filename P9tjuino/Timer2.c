#include <avr/interrupt.h>
#include <inttypes.h>
#include "Clock.h"
static volatile uint8_t SecFlag;

void Timer2_Init ( void ){
	TIMSK2 = 0;		//limpiando OCIE2A OCIE2B TOIE2
	ASSR = (1<<AS2);	//modo asincrono
	TCNT2 = 0		//iniciando timer en 0
	TCCR2A = 0;		
	
	/*esperando que a los registros*/
	while( ASSR&( (1<<<TCN2UB)|(1<<OCR2AUB)|(1<<OCR2BUB)|(1<<TCR2AUB)|(1<<TCR2BUB) ) );
	TIMSK2 = 0;	//limpiando las banderas de interrupcion
	TIMSK2 = (1<<TOIE2);	//habilitando interrupcion por overflow
	
	sei(); /* habilita interrupciones (global) */
}

uint8_t Timer2_SecFlag ( void )
{
	if( SecFlag ){
		SecFlag=0;
		return 1;
	}
	else{
		return 0;
	}
}

ISR (TIMER2_OVF_vect)
{ 
	if( SecFlag() ){
		Clock_Update();		//actualizando reloj
		UART0_puts("\n\r");
		Clock_Display();	//desplegando reloj	
	}
}