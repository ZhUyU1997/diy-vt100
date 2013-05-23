#ifndef _VT100_REPORT_H_
#define _VT100_REPORT_H_

#include <uart.h>
#include <vt100/param.h>
#include <vt100/misc.h>
#include <vt100/cursor.h>

/* send device attribute */
/* send ^[[?1;0c  | vt100 or ANSI/VT100 Clone  */
void vt100_report_identity();

void vt100_report_DSR();

void vt100_report_parameters();

#endif
