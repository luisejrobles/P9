#include <avr/interrupt.h>
#include <inttypes.h>
#include "Clock.h"

ISR (SIG_OUTPUT_COMPARE2A);
uint8_t Timer2_Flag(void);
uint8_t Timer0_SecFlag (void);
void Timer2_Init (void);
