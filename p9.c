#include <avr/io.h>
#include “Timer0.h”
/* incluir lo necesario para usar UART0 */

int main()
{
	/* llamar a función para inicializar puertos E/S */
	/* llamar a función para inicializar UART0 */
	Timer0_Ini(); /* Inicializar Timer0 para 1 sec.*/
	while(1){ 
		/* == main loop == */
		if( Timer0_SecFlag() )
		{ 
			/* ¿ha pasado 1 Segundo? */
			/* instrucciones para encender LED */
			UART0_puts(“1 segundo\n\r”);
			/* instrucciones para apagar LED */
		}
	}
}