#ifndef GDISPLAY_H
#define GDISPLAY_H
#ifdef	__cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stdint.h>
#include "graphic2d_objects.h"
#include "gdisplay_driver.h"

typedef struct
{
    uint16_t width;
    uint16_t height;
    gdisplay_driver_t* driver;
    bool (*clear_fn)(area2d_t*);
    bool (*draw_fn)(pos2d_t*,graphic_t*);
}gdisplay_t;


#ifdef	__cplusplus
}
#endif
#endif // GDISPLAY_H
