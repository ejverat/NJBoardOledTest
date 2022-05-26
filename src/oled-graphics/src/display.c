
#include "display.h"
#include <stddef.h>

bool set_display_size(display_t* disp, uint16_t width, uint16_t height)
{
    if (disp == NULL)
        return false;
    if (width == 0 || height == 0)
        return false;

    disp->height = height;
    disp->width = width;

    return true;
}

