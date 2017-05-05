#include <avr/interrupt.h>
#include <inttypes.h>
#include "Clock.h"

ISR (TIMER2_COMPA_vect);
uint8_t Timer2_Flag(void);
uint8_t Timer0_SecFlag (void);
void Timer2_Init (void);
