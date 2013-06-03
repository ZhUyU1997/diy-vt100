#ifndef _HARDWARE_TIMER0_A3_H_
#define _HARDWARE_TIMER0_A3_H_

#include <common.h> 

#define TIMER0_A3_TACTL TA0CTL
#define TIMER0_A3_TACCR0 TA0CCR0
#define TIMER0_A3_TACCR1 TA0CCR1
#define TIMER0_A3_TACCTL0 TA0CCTL0

void timer0_A3_init();
void timer0_A0_interrupt (void) __attribute__((interrupt(TIMER0_A0_VECTOR)));

#endif