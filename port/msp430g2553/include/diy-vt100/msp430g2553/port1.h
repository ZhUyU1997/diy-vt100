#ifndef HW_PORT1_H
#define HW_PORT1_H

#include <diy-vt100/common.h>

#define SETUP_BUTTON BIT3

#define UCB0CLK BIT5
//#define UCB0SOMI BIT6
#define UCB0SIMO BIT7

#define port1_low(bits) 	__low(P1OUT, bits)
#define port1_high(bits)	__high(P1OUT, bits)
#define port1_flip(bits)	__flip(P1OUT, bits)

#endif
