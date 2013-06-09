#include <hardware/flash.h>
#include <hardware/timer1_A3.h>
#include <setting.h>

const struct __setting flash_setting = 
{
	.vr_bits = 0xFF,
	.brightness = TIMER1_A3_PWM_INIT,
	.speed = 0, /* 9600 */
	.nvr_bits = 0xFFFF,
	.tabs = 0b1000100010001000,
	.answerback = {'d', 'i', 'y', '-', 'v', 't', '1', '0', '0'}
};

void flash_store()
{
	struct __setting *dest = (struct __setting *)(&flash_setting);
	
	__disable_interrupt();
	
	FCTL1 = FWKEY + ERASE;
	FCTL3 = FWKEY;

	dest->vr_bits = 0;
	
	FCTL1 = FWKEY + WRT;
	
	*dest = setting;
	
	FCTL1 = FWKEY;
	FCTL3 = FWKEY + LOCK;
	
	__enable_interrupt();
}

void flash_load()
{
	setting = (struct __setting)flash_setting;
	setting.vr_bits = 0;

}