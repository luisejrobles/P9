#include <avr/interrupt.h>
#include <inttypes.h>
#include "Clock.h"
static volatile uint8_t SecFlag;

void Timer0_Ini ( void ){
	TCNT0=0x06; /* Inicializar valor para el timer0 */
	TCCR0A=0x00; /* inicializa timer0 en modo 0 (normal) */
	/* Inicializar con fuente de osc. Int. */
	TCCR0B=0x03; /* con Prescalador 64 */
	TIMSK0=0x01; /* habilita interrupcion del Timer0 */
	sei(); /* habilita interrupciones (global) */
}

void timer0_CTC(void)
{
	TCNT0  = 0;	//incializando timer en 0
	TCCR0A = (2<<WGM00);	//CTC enable
	TCCR0B = (3<<CS00);		//64 PS
	TIMSK0 = (1<<OCIE2A);	//Output cmp match A interrupt enable
	OCR0A  = 250 -1;		//TOP 	
	
	sei();	//interrupciones globales

}

void timer0_8PS(void)
{
		TCNT0  = 0;	//incializando timer en 0
		TCCR0A = (2<<WGM00);	//CTC enable
		TCCR0B = (2<<CS00);		//8 PS
		TIMSK0 = (1<<OCIE2A);	//Output cmp match A interrupt enable
		OCR0A  = 250 -1;		//TOP

		sei();	//interrupciones globales

}

ISR (TIMER0_COMPA_vect)
{ 
	static uint16_t mSecCnt;
	mSecCnt++; /* Incrementa contador de milisegundos */
	if( mSecCnt == 1000 ){
		Clock_Update();		//actualizando reloj
		UART0_puts("\n\r");
		Clock_Display();	//desplegando reloj	
		mSecCnt = 0;		//reiniciando cuenta de ms
	}
}