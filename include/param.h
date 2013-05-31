#ifndef _PARAM_H_
#define _PARAM_H_

#include <common.h>

#define PARAM_QUEUE_SIZE 8
#define PARAM_DELIMITER ';'

struct __param
{
	uint8_t count;
	uint8_t data[PARAM_QUEUE_SIZE];
	uint8_t pass;
};

extern struct __param param;

void param_add();
void param_default(uint8_t pcount, uint8_t pdefault);
#endif