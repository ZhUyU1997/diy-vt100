#ifndef SETTING_H
#define SETTING_H

#include <diy-vt100/common.h>

#define answerback_size 20

/* ONLINE: 	(online mode|offline mode)
 * MODE: 	(vt52|ansi)
 * AUTOX: 	auto XON & XOFF (OFF|ON)
 * BPS:		bits per character(7|8)
 * DECCOLM:	character per line(80|130)
 * CURSOR: 	cursor (block|underline)
 * SHIFTED:	#, EURO selection (#|EURO)
 * POWER: 	(60Hz|50Hz)
 * SCREEN: 	(DARK|LIGHT)
 */

typedef struct
{
	struct
	{
		/* DEC PRIV - VR */
		uint8_t DECKPAM:1;
		uint8_t DECCKM:1;
		uint8_t DECGON:1;
		uint8_t DECCOM:1;

		/* VT100 PRIVATE - VR */
		uint8_t UNSOLIC:1;
		uint8_t LOCAL:1;
		uint8_t SETUP_TYPE:1;
		uint8_t SETUP_SHOW:1;
		
		/* KEYBOARD - VR */
		uint8_t KBD_SHIFT:1;
		uint8_t KBD_CTRL:1;
		uint8_t KBD_CAPS:1;
		
		/* HW - PRIVATE - NA */
		uint8_t HW_PRIV0:1;
		uint8_t HW_PRIV1:1;
		uint8_t HW_PRIV2:1;
		uint8_t HW_PRIV3:1;

		/* DEC PRIV - NVR */
		uint8_t DECANM:1;
		uint8_t DECARM:1;
		uint8_t AUTOX:1;
		uint8_t BPC:1;
		uint8_t DECCOLM:1;
		uint8_t CURSOR:1;
		uint8_t DECINLM:1;
		uint8_t LNM:1;
		uint8_t KEYCLICK:1;
		uint8_t MARGINBELL:1;
		uint8_t PARITY:1;
		uint8_t PARITYSENSE:1;
		uint8_t DECSCNM:1;
		uint8_t DECSCLM:1;
		uint8_t DECAWM:1;
		uint8_t SHIFTED:1;
		uint8_t POWER:1;
	}
	__attribute((packed)) bits;

	uint8_t brightness;
	uint8_t uart_rx;
	uint8_t uart_tx;
	uint16_t tabs;
	uint8_t answerback[answerback_size];
}
__attribute((packed)) setting_t;

extern volatile setting_t setting;

#define setting_tab_high(pos) 	__high(setting.tabs, __bitmask(pos))
#define setting_tab_low(pos) 	__low(setting.tabs, __bitmask(pos))
#define setting_tab_flip(pos) 	__flip(setting.tabs, __bitmask(pos))
#define setting_tabs_clear() 	(setting.tabs = 0)

#define setting_tab_islow(pos) 	__islow(setting.tabs, __bitmask(pos))
#define setting_tab_ishigh(pos) __ishigh(setting.tabs, __bitmask(pos))

void setting_load(void);
void setting_store(void);
void setting_init(void);

/* defined by hardware */
//setting_t parm_setting
//#define parm_setting_tab_islow(pos)
//#define parm_setting_tab_ishigh(pos)

#include <diy-vt100/hardware/setting.h>

#endif
