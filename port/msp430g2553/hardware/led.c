#include <diy-vt100/led.h>
#include <diy-vt100/msp430g2553/ic_74xx595.h>

void led_on(led_t leds)
{
	ic_74xx595 |= leds << 1;
}

void led_off(led_t leds)
{
	ic_74xx595 &= ~(leds << 1);
}
