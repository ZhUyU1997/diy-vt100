#ifndef LED_H
#define LED_H

#include <diy-vt100/common.h>

typedef enum
{
	LINE = BIT0,
	LOCAL = BIT1,
	KBDLOCK = BIT2,
	PROG1 = BIT3,
	PROG2 = BIT4,
	PROG3 = BIT5,
	PROG4 = BIT6,	
}
led_t;

void led_on(led_t);
void led_off(led_t);

#endif
