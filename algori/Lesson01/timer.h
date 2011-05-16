#ifndef _TIMER_H
#define _TIMER_H

#include <bios.h>

#define get_tick()           (long)biostime (0, 0L)
#define diff_tick(t1, t2)    (long) ((t2) - (t1))
#define diff_second(t1, t2)  ((float) ((t2) - (t1)) / CLK_TCK)

#endif
