#ifndef _TIMER0_H
#define _TIMER0_H
#include <inttypes.h>

void Timer0_Ini ( void );
uint8_t Timer0_SecFlag ( void );
ISR (TIMER0_OVF_vect);