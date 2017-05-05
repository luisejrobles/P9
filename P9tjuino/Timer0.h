#include <avr/interrupt.h>
#include <inttypes.h>
#include "Clock.h"

void timer0_CTC(void);
void Timer0_Ini ( void );
uint8_t Timer0_SecFlag ( void );
ISR (TIMER0_COMPA_vect);