#include <diy-vt100/msp430g2553/port2.h>
#include <diy-vt100/msp430g2553/cqueue.h>
#include <diy-vt100/msp430g2553/ic_74xx595.h>

#include <diy-vt100/common.h>
#include <diy-vt100/uart.h>

cqueue_t ps2kbd;
void port2_interrupt(void)__attribute__((interrupt(PORT2_VECTOR)));

void port2_init(void)
{
	P2DIR &= ~(KEYBOARD_PS2_DATA | KEYBOARD_PS2_CLK);
	P2REN |= KEYBOARD_PS2_DATA | KEYBOARD_PS2_CLK;
	P2OUT |= KEYBOARD_PS2_DATA | KEYBOARD_PS2_CLK;
	
	P2IFG &= ~KEYBOARD_PS2_CLK;
	
	P2IES |= KEYBOARD_PS2_CLK;
	P2IE |= KEYBOARD_PS2_CLK;
	
	/* interrupt goes to pin2_interrupt() */

	/* output port */
	P2DIR |= NOKIA1100_SS;
	P2OUT |= NOKIA1100_SS;
	
	P2DIR |= IC_74XX595_STCP;
	P2OUT |= IC_74XX595_STCP;
}

void port2_interrupt(void)
{
	static uint8_t data;
	static uint8_t index;
	
	__low(P2IFG, KEYBOARD_PS2_CLK);
	
	switch(index)
	{
		case 0:
			/* start bit */
		break;
		
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
			/* data */
			data >>= 1;
			if(__read(P2IN,KEYBOARD_PS2_DATA))
			{
				__high(data, BIT7);
			}
		break;
		
		case 9:
			/* TODO: check parity for data */
		break;
		
		case 10:
			/* STOP bit */
			cqueue_push(&ps2kbd, data);
			__bic_status_register_on_exit(LPM1_bits);
		default:
			index = 0;
			return;
	}
	
	index++;
}
