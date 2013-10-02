#ifndef HW_IC_74XX595_H
#define HW_IC_74XX595_H

#include <diy-vt100/common.h>

#define BUZZER BIT0
//#define LED_ONLINE BIT1
//#define LED_OFFLINE BIT2
//#define LED_KBDLOCK BIT3
//#define LED_PROG1 BIT4
//#define LED_PROG2 BIT5
//#define LED_PROG3 BIT6
//#define LED_PROG4 BIT7

extern uint8_t ic_74xx595;

void ic_74xx595_refresh(void);

#endif
