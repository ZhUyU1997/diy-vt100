#ifndef _KEYBOARD_PS2_H_
#define _KEYBOARD_PS2_H_

#include <common.h>
#include <cqueue.h>

struct __kbd
{
	int8_t index;
	uint8_t latch;
	uint8_t data;
	
	uint8_t param;
	struct __cqueue queue;
};

extern struct __kbd kbd;

#define KBD_CTRL 	BIT0
#define KBD_NUM 	BIT1
#define KBD_CAPS 	BIT2
#define KBD_SHIFT 	BIT3
#define KBD_MODIFIER BIT4
#define KBD_BREAK 	BIT5
#define KBD_PARITY 	BIT6

#define kbd_latch_read(bit) __read(kbd.latch, bit)
#define kbd_latch_high(bit) __high(kbd.latch, bit)
#define kbd_latch_low(bit) __low(kbd.latch, bit)
#define kbd_latch_flip(bit) __flip(kbd.latch, bit)

void kbd_ctrl();
void kbd_shift();
void kbd_caps();
void kbd_f5();
void kbd_f4();
void kbd_f3();
void kbd_f2();
void kbd_f1();
void kbd_enter();

void kbd_keypad_0();
void kbd_keypad_1();
void kbd_keypad_2();
void kbd_keypad_3();
void kbd_keypad_4();
void kbd_keypad_5();
void kbd_keypad_6();
void kbd_keypad_7();
void kbd_keypad_8();
void kbd_keypad_9();
void kbd_keypad_dot();
void kbd_keypad_dash();

void kbd_decode();

#endif
