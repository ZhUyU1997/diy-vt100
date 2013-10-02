#include <diy-vt100/setting.h>
#include <diy-vt100/uart.h>
#include <diy-vt100/vt100/attribute.h>
#include <diy-vt100/screen.h>

//value = bps/(10 * (2 ^ clkmul_conv ))
//where clkmul_conv = 16 for clkmul == 1
//where clkmul_conv = 64 for clkmul == 2
const uartspeed_t uart_speed[UART_SPEED_COUNT] = 
{
	{"9600", 	"112", 	'1'},
	{"19200", 	"120", 	'1'},
	{"38400", 	"60", 	'2'},
	{"56000", 	"87", 	'2'},
	{"115200", 	"180", 	'2'},
	{"128000", 	"200", 	'2'},
	{"256000", 	"400", 	'2'}
};

void uart_send_uint8(uint8_t val)
{
	uint8_t tmp = val / 100;
	
	if(tmp)
	{
		uart_send('0' + tmp);
		val -= tmp * 100;
	}

	tmp = val / 10;
	if(tmp)
	{
		uart_send('0' + tmp);
		val -= tmp * 10;
	}
	
	uart_send('0' + val);
}
/*
void uart_send_array(const uint8_t *arr, const uint8_t size)
{
	for(uint8_t i=0; i < size; i++)
	{
		uart_send(arr[i]);
	}
}
*/
void uart_send_string(const char *string)
{
	for(uint8_t i=0; string[i]; i++)
	{
		uart_send(string[i]);
	}
}
