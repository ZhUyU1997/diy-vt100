#include <diy-vt100/screen.h>
#include <diy-vt100/msp430g2553/screen/nokia1100.h>
#include <diy-vt100/msp430g2553/port2.h>
#include <diy-vt100/msp430g2553/spi.h>

#define nokia1100_cs_low()  port2_low(NOKIA1100_SS)
#define nokia1100_cs_high()  port2_high(NOKIA1100_SS)

void nokia1100_full_clear(void)
{
	uint16_t i = 864;
	
	nokia1100_cs_low();
	
	/* send 0x00 in brust mode */
	while(i--)
	{
		spi_send9(BIT8);
	}
	
	/* Disable display LCD */
	nokia1100_cs_high();
}

/* only used to send data in one go */
void nokia1100_send_data(const uint8_t *data_array, const uint8_t size)
{
	nokia1100_cs_low();
	
	for(uint8_t i=0; i < size; i++)
	{
		spi_send9(BIT8 | data_array[i]);
	}
	
	nokia1100_cs_high();
}

void nokia1100_send_cmd(const uint8_t data)
{
	nokia1100_cs_low();
	spi_send9(data);
	nokia1100_cs_high();
}
