#ifndef DISPLAY_SSD1306_128X64_H
#define DISPLAY_SSD1306_128X64_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "gdisplay.h"
#include "display_comm.h"
#include "timer.h"
#include "graphic2d_objects.h"
#include <stdint.h>

void display_ssd1306_128x64_setup(gdisplay_t* display, display_comm_t* comm, waiter_t* timer);
bool display_ssd1306_128x64_init();
bool display_ssd1306_128x64_clear(area2d_t* area);
bool display_ssd1306_128x64_draw(pos2d_t* pos, graphic_t* graphic);

#ifdef	__cplusplus
}
#endif

#endif // DISPLAY_SSD1306_128X64_H
