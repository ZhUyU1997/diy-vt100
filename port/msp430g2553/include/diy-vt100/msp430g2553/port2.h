#ifndef HW_PORT2_H
#define HW_PORT2_H

#include <diy-vt100/common.h>

/* === for keyboard === */
#define KEYBOARD_PS2_DATA BIT0
#define KEYBOARD_PS2_CLK BIT1

/* NOTE: using P2.2 for timer1_A3 PWM for LCD */

#define NOKIA1100_SS 	BIT3

//#define IC_74XX595_DATA BIT0   -> moved to spi
#define IC_74XX595_STCP BIT4
//#define IC_74XX595_SHCP BIT5   - > moved to spi

#define port2_low(bits) 	__low(P2OUT, bits)
#define port2_high(bits)	__high(P2OUT, bits)
#define port2_flip(bits)	__flip(P2OUT, bits)

#endif
