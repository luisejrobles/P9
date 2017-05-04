#define BYTE unsigned char
#include "UART.h"

BYTE seg=50; /* para el manejo de los segundos */
BYTE min=59; /*minutos*/
BYTE horas=23; /*horas*/

void Clock_Ini(BYTE hora, BYTE minutos, BYTE segundos)
{
	seg=segundos;
	min=minutos;
	horas=hora;
}
void Clock_Update( void ){
	seg=(++seg%60);
	if(seg == 0)
	{
		min=(++min%60);
		if(min == 0)
		{
			horas=(++horas%24);
		}
	}
}
void Clock_Display( void ){
	/* imprimir reloj en formato "hh:mm:ss" */;
	UART0_putchar(10);
	UART0_putchar(13);
	PrintDec2d(horas);
	UART0_putchar(':');
	PrintDec2d(min);
	UART0_putchar(':');
	PrintDec2d(seg);
}
void PrintDec2d( BYTE dato){
	UART0_putchar( dato/10 +'0'); /* Imprime decenas */
	UART0_putchar( dato%10 +'0'); /* Imprime unidades */
}