/* 
 * File:   timer_delay.h
 * Author: evera
 *
 * Created on June 3, 2022, 6:03 AM
 */

#ifndef TIMER_DELAY_H
#define	TIMER_DELAY_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "timer.h"
    waiter_t* timer_delay_instance();
    void timer_delay_ms(uint16_t ms);



#ifdef	__cplusplus
}
#endif

#endif	/* TIMER_DELAY_H */

