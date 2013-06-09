#include <hardware/nokia1100.h>
#include <hardware/timer1_A3.h>

#include <vt100/buffer.h>
#include <vt100/cursor.h>
#include <vt100/buffer.h>

#include <setup.h>
#include <param.h>
#include <uart.h>
#include <setting.h>

uint8_t setup_type_current;
uint8_t setup_setting_number;

const struct __state
setup_state_type[] = 
{
	state_noparam	(0, setup_state_worker),
	
	state_select	(ASCII_ESCAPE, setup_state_arrow),
	state_noparam	(ASCII_DC3, setup_save), /* CTRL-S pressed */
	state_noparam	(ASCII_DC2, setup_reload), /* CTRL-R pressed */
	state_noparam	('0', setup_reset),
	state_noparam	('2', setup_TAB_flip),
	state_noparam	('3', setup_TABS_clear),
	state_noparam	('4', setup_LOCAL),
	state_noparam	('5', setup_switch),
	state_noparam	('6', setup_value_flip),
	state_noparam	('7', setup_speed), /* transmit speed */
	state_noparam	('8', setup_speed), /* receive speed */
	state_noparam	('9', setup_DECCOLM),
	state_noparam	(ASCII_LF, setup_next_setting),
	state_noparam	(ASCII_SPACE, setup_next_setting),
	state_noparam	(ASCII_TAB, setup_next_setting),
	state_end()
};

const struct __state
setup_state_arrow[] = 
{
	state_noparam	(0, setup_state_worker),
	
	state_select	('O', setup_state_arrow_select),
	state_select	('?', setup_state_arrow_select),
	
	state_noparam	('A', setup_brightness_increase),
	state_noparam	('B', setup_brightness_decrease),
	state_noparam	('C', setup_next_setting),
	state_noparam	('D', setup_previous_setting),
	state_end		()
};

const struct __state
setup_state_arrow_select[] =
{
	state_noparam	(0, setup_state_worker),
	
	state_noparam	('A', setup_brightness_increase),
	state_noparam	('B', setup_brightness_decrease),
	state_noparam	('C', setup_next_setting),
	state_noparam	('D', setup_previous_setting),
};

void setup_state_worker()
{	
	switch((int)state_iterate->cb)
	{
		case 0:
		case 1:
			/* ignore (missing or instructed to ignored) */
		return;
		
		case 2:
			state_current = (struct __state *)state_iterate->arg.state;
		break;
		
		default:
			/* restore state */
			state_current = (struct __state *)setup_state_type;
			
			state_iterate->cb();
			
			switch(setup_type_current)
			{
				case 'B':
					setup_B_refresh();
				break;
				
				case 'A':
					setup_A_refresh();
				break;
			}
		break;
	}
}

void setup_brightness_increase()
{
	/* increase brightness */
	if(setting.brightness < TIMER1_A3_PWM_MAX)
	{
		timer1_A3_pwm(++setting.brightness);
	}
}

void setup_brightness_decrease()
{
	/* decrease brightness */
	if(setting.brightness > TIMER1_A3_PWM_MIN)
	{
		timer1_A3_pwm(--setting.brightness);
	}
}

void setup_previous_setting()
{
	/* select left value */
	setup_setting_number--;
	
	/* limit to 16 only */
	setup_setting_number &= 0x0F;
}

void setup_next_setting()
{
	/* select right value */
	setup_setting_number++;
	
	/* limit to 16 only */
	setup_setting_number &= 0x0F;
}

void setup_value_flip()
{
	/* flip values in setup, 5 was pressed */
	
	if(setup_type_current == 'B')
	{
		switch(setup_setting_number)
		{
			/* box 1 */
			case 0:
				setting_flip(SETTING_CURSOR);
			break;
			
			case 1:
				setting_flip(SETTING_DECSCNM);
			break;
			
			case 2:
				setting_flip(SETTING_DECARM);
			break;
			
			case 3:
				setting_flip(SETTING_DECSCLM);
			break;
			
			/* box 2 */
			case 4:
				setting_flip(SETTING_MARGINBELL);
			break;
			
			case 5:
				setting_flip(SETTING_KEYCLICK);
			break;
			
			case 6:
				setting_flip(SETTING_DECANM);
			break;
			
			case 7:
				setting_flip(SETTING_AUTOX);
			break;
			
			/* box 3 */
			case 8:
				setting_flip(SETTING_SHIFTED);
			break;
			
			case 9:
				setting_flip(SETTING_DECAWM);
			break;
			
			case 10:
				setting_flip(SETTING_LNM);
			break;
			
			case 11:
				setting_flip(SETTING_DECINLM);
			break;
			
			/* box 4 */
			case 12:
				setting_flip(SETTING_PARITYSENSE);
			break;
			
			case 13:
				setting_flip(SETTING_PARITY);
			break;
			
			case 14:
				setting_flip(SETTING_BPC);
			break;
			
			case 15:
				/* setting_flip(SETTING_POWER); */
			break;
		}
	}
}

void setup_switch()
{
	setup_setting_number = 0;
	
	switch(setup_type_current)
	{
		case 'B':
			setup_type_current = 'A';
			vt100_buffer_copy(setup_buffer_A);
			setup_A_refresh();
		break;
		
		case 'A':
			setup_type_current = 'B';
			vt100_buffer_copy(setup_buffer_B);
			setup_B_refresh();
		break;
	}
}

void setup_B_refresh()
{
	row_t i;
	col_t j;
	uint8_t value_no = 0;
	
	
	bool_t readed_values[16] =
	{
		setting_read(SETTING_CURSOR), setting_read(SETTING_DECSCNM), setting_read(SETTING_DECARM), setting_read(SETTING_DECSCLM),
		setting_read(SETTING_MARGINBELL), setting_read(SETTING_KEYCLICK), setting_read(SETTING_DECANM), setting_read(SETTING_AUTOX),
		setting_read(SETTING_SHIFTED), setting_read(SETTING_DECAWM), setting_read(SETTING_LNM), setting_read(SETTING_DECINLM),
		setting_read(SETTING_PARITYSENSE), setting_read(SETTING_PARITY), setting_read(SETTING_BPC), /*setting_read(SETTING_POWER) */ 0
	};
	
	for(i = 6; i < 8; i++)
	{
		for(j=2; j < 13; j++)
		{
			if(j > 5 && j < 9)
			{
				continue;
			}
			
			vt100_buffer[i][j].data = readed_values[value_no] ? '1' : '0';
			
			if(value_no++ == setup_setting_number)
			{
				vt100_cursor.row = i;
				vt100_cursor.col = j;
			}
		}
		
		vt100_buffer[i][0].prop |= VT100_CHAR_PROP_ROW_TOUCH;
	}
	
	const struct __vt100_char *speed_str = uart_speed_get(setting.speed);
	
	vt100_buffer[4][0].prop |= VT100_CHAR_PROP_ROW_TOUCH;
	vt100_buffer[5][0].prop |= VT100_CHAR_PROP_ROW_TOUCH;
	
	for(j=0; j < UART_SPEED_STRING_LENGTH; j++)
	{
		vt100_buffer[4][j + 8] = vt100_buffer[5][j + 8] = speed_str[j];
	}
}

void setup_A_refresh()
{
	col_t j;
	vt100_cursor.row = 6;
	vt100_cursor.col = setup_setting_number;
	
	for(j=0; j < 16; j++)
	{
		vt100_buffer[6][j].data = setting_tab_read(j) ? 'T' : ' ';
	}		
}

void setup_save()
{
	col_t j = 0;
	const struct __vt100_char saving_message[VT100_WIDTH] = {{'S', VT100_CHAR_PROP_ROW_TOUCH}, {'a'}, {'v'}, {'e'}, {'d'}, {'.'}};

	/* start saving */
	setting_save();

	for(j = 0; j < VT100_WIDTH; j++)
	{
		vt100_buffer[3][j] = saving_message[j];
	}
}

void setup_reload()
{
	setting_load();
}

void setup_reset()
{
	/* restart */
	WDTCTL = 0;
}

void setup_DECCOLM()
{
	if(setup_type_current == 'A')
	{
		setting_flip(SETTING_DECCOLM);
	}
}

void setup_LOCAL()
{
	setting_flip(SETTING__LOCAL);
}

void setup_TABS_clear()
{
	if(setup_type_current == 'A')
	{
		setting_tab_clear();
	}
}

void setup_TAB_flip()
{
	if(setup_type_current == 'A')
	{
		setting_tab_flip(setup_setting_number);
	}
}

void setup_speed()
{
	/* handle speeds */
	if(!(++setting.speed < UART_SPEED_COUNT))
	{
		setting.speed = 0;
	}
}
