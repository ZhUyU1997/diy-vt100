#ifndef HW_SCREEN_H
#define HW_SCREEN_H

#define __NOKIA1100LCD__

#ifdef __NOKIA1100LCD__
#include <diy-vt100/msp430g2553/screen/nokia1100.h>
#else
#error "unkown LCD"
#endif

#endif
