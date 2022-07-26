#ifndef TIMER_H
#define TIMER_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdint.h>

typedef struct
{
    void (*wait_ms)(uint16_t);
}waiter_t;

#ifdef	__cplusplus
}
#endif

#endif // TIMER_H
