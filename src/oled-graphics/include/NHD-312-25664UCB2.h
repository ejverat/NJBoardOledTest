#ifndef NHD31225664UCB2_H
#define NHD31225664UCB2_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "gdisplay.h"
#include "display_comm.h"
#include "timer.h"
#include "graphic2d_objects.h"
#include <stdint.h>

void nhd31225664ucb2_setup(gdisplay_t* display, display_comm_t* comm, waiter_t* timer);
bool nhd31225664ucb2_init();
bool nhd31225664ucb2_clear(area2d_t* area);
bool nhd31225664ucb2_draw(pos2d_t* pos, graphic_t* graphic);

#ifdef	__cplusplus
}
#endif

#endif // NHD31225664UCB2_H
