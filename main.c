#include <diy-vt100/hardware.h>
#include <diy-vt100/common.h>
#include <diy-vt100/keyboard/keyboard.h>
#include <diy-vt100/splash.h>
#include <diy-vt100/param.h>
#include <diy-vt100/uart.h>
#include <diy-vt100/state-machine.h>
#include <diy-vt100/vt100/misc.h>
#include <diy-vt100/vt100/screen.h>
#include <diy-vt100/setting.h>

void msp430_init();

void
main()
{
	hardware_init();
	
	uart_init();
	setting_init();
	vt100_init();
	
	/* show splash screen */
	splash();
	
	__loop:
		while(kbd.queue.count)
		{
			kbd.param = cqueue_pop(&kbd.queue);
			kbd_decode();
		}
		
		while(uart_rx.count)
		{
			param.pass = cqueue_pop(&uart_rx);
			state_do();
		}
		
		vt100_screen_refresh();
		
		refresh_finished();
	goto __loop;
}


