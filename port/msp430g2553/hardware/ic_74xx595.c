#include <diy-vt100/msp430g2553/ic_74xx595.h>
#include <diy-vt100/msp430g2553/port2.h>
#include <diy-vt100/msp430g2553/spi.h>

uint8_t ic_74xx595;

void ic_74xx595_refresh(void)
{
	port2_low(IC_74XX595_STCP);
	spi_send(ic_74xx595);
	port2_high(IC_74XX595_STCP);
}
