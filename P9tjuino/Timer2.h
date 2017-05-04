#include <avr/interrupt.h>
#include <inttypes.h>
#include "Clock.h"

ISR (TIMER2_OVF_vect);
uint8_t Timer2_SecFlag(void);
uint8_t Timer0_SecFlag (void);
void Timer2_Init (void);
