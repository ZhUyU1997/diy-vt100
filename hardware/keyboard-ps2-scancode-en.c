#include <hardware/keyboard-ps2.h>
#include <setup.h>

const struct __keyboard_ps2_scancode keyboard_ps2_scancode_en[KEYBOARD_PS2_SCANCODE_SIZE] =
{
	keyboard_ps2_scancode_ignore	(),
	keyboard_ps2_scancode_ignore	(), /* KEYBOARD_PS2_F9 */
	keyboard_ps2_scancode_ignore	(),
	keyboard_ps2_scancode_callback	(keyboard_ps2_scancode_callback_f5), /* KEYBOARD_PS2_F5 */
	keyboard_ps2_scancode_callback	(keyboard_ps2_scancode_callback_f3),
	keyboard_ps2_scancode_callback	(keyboard_ps2_scancode_callback_f1),
	keyboard_ps2_scancode_callback	(keyboard_ps2_scancode_callback_f2),
	keyboard_ps2_scancode_ignore	(), /* KEYBOARD_PS2_F12 */
	keyboard_ps2_scancode_ignore	(),
	keyboard_ps2_scancode_ignore	(), /* KEYBOARD_PS2_F10 */
	keyboard_ps2_scancode_ignore	(), /* KEYBOARD_PS2_F8 */
	keyboard_ps2_scancode_ignore	(), /* KEYBOARD_PS2_F6 */
	keyboard_ps2_scancode_callback	(keyboard_ps2_scancode_callback_f4),
	keyboard_ps2_scancode_special	(ASCII_TAB, ASCII_TAB),
	keyboard_ps2_scancode_special	('`', '~'),
	keyboard_ps2_scancode_ignore	(),
	keyboard_ps2_scancode_ignore	(),
	keyboard_ps2_scancode_ignore	(), /* left alt */
	keyboard_ps2_scancode_callback	(keyboard_ps2_scancode_callback_shift), /* left shift */
	keyboard_ps2_scancode_ignore	(),
	keyboard_ps2_scancode_callback	(keyboard_ps2_scancode_callback_ctrl), /* left ctrl */
	keyboard_ps2_scancode_alpha		('q', 'Q'),
	keyboard_ps2_scancode_num		('1', '!'),
	keyboard_ps2_scancode_ignore	(),
	keyboard_ps2_scancode_ignore	(),
	keyboard_ps2_scancode_ignore	(),
	keyboard_ps2_scancode_alpha		('z', 'Z'),
	keyboard_ps2_scancode_alpha		('s', 'S'),
	keyboard_ps2_scancode_alpha		('a', 'A'),
	keyboard_ps2_scancode_alpha		('w', 'W'),
	keyboard_ps2_scancode_num		('2', '@'),
	keyboard_ps2_scancode_ignore	(),
	keyboard_ps2_scancode_ignore	(),
	keyboard_ps2_scancode_alpha		('c', 'C'),
	keyboard_ps2_scancode_alpha		('x', 'X'),
	keyboard_ps2_scancode_alpha		('d', 'D'),
	keyboard_ps2_scancode_alpha		('e', 'E'),
	keyboard_ps2_scancode_num		('4', '$'),
	keyboard_ps2_scancode_num		('3', '#'),
	keyboard_ps2_scancode_ignore	(),
	keyboard_ps2_scancode_ignore	(),
	keyboard_ps2_scancode_alpha		(' ', ' '),
	keyboard_ps2_scancode_alpha		('v', 'V'),
	keyboard_ps2_scancode_alpha		('f', 'F'),
	keyboard_ps2_scancode_alpha		('t', 'T'),
	keyboard_ps2_scancode_alpha		('r', 'R'),
	keyboard_ps2_scancode_num		('5', '%'),
	keyboard_ps2_scancode_ignore	(),
	keyboard_ps2_scancode_ignore	(),
	keyboard_ps2_scancode_alpha		('n', 'N'),
	keyboard_ps2_scancode_alpha		('b', 'B'),
	keyboard_ps2_scancode_alpha		('h', 'H'),
	keyboard_ps2_scancode_alpha		('g', 'G'),
	keyboard_ps2_scancode_alpha		('y', 'Y'),
	keyboard_ps2_scancode_num		('6', '^'),
	keyboard_ps2_scancode_ignore	(),
	keyboard_ps2_scancode_ignore	(),
	keyboard_ps2_scancode_ignore	(),
	keyboard_ps2_scancode_alpha		('m', 'M'),
	keyboard_ps2_scancode_alpha		('j', 'J'),
	keyboard_ps2_scancode_alpha		('u', 'U'),
	keyboard_ps2_scancode_num		('7', '&'),
	keyboard_ps2_scancode_num		('8', '*'),
	keyboard_ps2_scancode_ignore	(),
	keyboard_ps2_scancode_ignore	(),
	keyboard_ps2_scancode_special	(',', '<'),
	keyboard_ps2_scancode_alpha		('k', 'K'),
	keyboard_ps2_scancode_alpha		('i', 'I'),
	keyboard_ps2_scancode_alpha		('o', 'O'),
	keyboard_ps2_scancode_num		('0', ')'),
	keyboard_ps2_scancode_num		('9', '('),
	keyboard_ps2_scancode_ignore	(),
	keyboard_ps2_scancode_ignore	(),
	keyboard_ps2_scancode_special	('.', '>'),
	keyboard_ps2_scancode_special	('/', '?'),
	keyboard_ps2_scancode_alpha		('l', 'L'),
	keyboard_ps2_scancode_special	(';', ':'),
	keyboard_ps2_scancode_alpha		('p', 'P'),
	keyboard_ps2_scancode_special	('-', '_'),
	keyboard_ps2_scancode_ignore	(),
	keyboard_ps2_scancode_ignore	(),
	keyboard_ps2_scancode_ignore	(),
	keyboard_ps2_scancode_special	('\'', '"'),
	keyboard_ps2_scancode_ignore	(),
	keyboard_ps2_scancode_special	('[', '{'),
	keyboard_ps2_scancode_special	('=', '+'),
	keyboard_ps2_scancode_ignore	(),
	keyboard_ps2_scancode_ignore	(),
	keyboard_ps2_scancode_callback	(keyboard_ps2_scancode_callback_caps),
	keyboard_ps2_scancode_callback	(keyboard_ps2_scancode_callback_shift), /* right shift */
	keyboard_ps2_scancode_callback	(keyboard_ps2_scancode_callback_enter),
	keyboard_ps2_scancode_special	(']', '}'),
	keyboard_ps2_scancode_ignore	(),
	keyboard_ps2_scancode_special	('\\', '|'),
	keyboard_ps2_scancode_ignore	(),
	keyboard_ps2_scancode_ignore	(),
	keyboard_ps2_scancode_ignore	(),
	keyboard_ps2_scancode_ignore	(),
	keyboard_ps2_scancode_ignore	(),
	keyboard_ps2_scancode_ignore	(),
	keyboard_ps2_scancode_ignore	(),
	keyboard_ps2_scancode_ignore	(),
	keyboard_ps2_scancode_special	(ASCII_BS, ASCII_BS),
	keyboard_ps2_scancode_ignore	(),
	keyboard_ps2_scancode_ignore	(),
	keyboard_ps2_scancode_callback	(keyboard_ps2_scancode_callback_keypad_1),
	keyboard_ps2_scancode_ignore	(),
	keyboard_ps2_scancode_callback	(keyboard_ps2_scancode_callback_keypad_4),
	keyboard_ps2_scancode_callback	(keyboard_ps2_scancode_callback_keypad_7),
	keyboard_ps2_scancode_ignore	(),
	keyboard_ps2_scancode_ignore	(),
	keyboard_ps2_scancode_ignore	(),
	keyboard_ps2_scancode_callback	(keyboard_ps2_scancode_callback_keypad_0),
	keyboard_ps2_scancode_callback	(keyboard_ps2_scancode_callback_keypad_dot),
	keyboard_ps2_scancode_callback	(keyboard_ps2_scancode_callback_keypad_2),
	keyboard_ps2_scancode_callback	(keyboard_ps2_scancode_callback_keypad_5),
	keyboard_ps2_scancode_callback	(keyboard_ps2_scancode_callback_keypad_6),
	keyboard_ps2_scancode_callback	(keyboard_ps2_scancode_callback_keypad_8),
	keyboard_ps2_scancode_special	(ASCII_ESCAPE, ASCII_ESCAPE),
	keyboard_ps2_scancode_ignore	(), /* num lock */
	keyboard_ps2_scancode_ignore	(), /* KEYBOARD_PS2_F11 */
	keyboard_ps2_scancode_special	('+', '+'),
	keyboard_ps2_scancode_callback	(keyboard_ps2_scancode_callback_keypad_3),
	keyboard_ps2_scancode_callback	(keyboard_ps2_scancode_callback_keypad_dash),
	keyboard_ps2_scancode_special	('*', '*'),
	keyboard_ps2_scancode_callback	(keyboard_ps2_scancode_callback_keypad_9),
//	keyboard_ps2_scancode_ignore	(), /* KEYBOARD_PS2_SCROLL */
//	keyboard_ps2_scancode_ignore	(),
//	keyboard_ps2_scancode_ignore	(),
//	keyboard_ps2_scancode_ignore	(),
//	keyboard_ps2_scancode_ignore	(),
//	keyboard_ps2_scancode_ignore	(), /* KEYBOARD_PS2_F7 */
};