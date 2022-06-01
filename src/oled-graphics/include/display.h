#ifndef DISPLAY_H
#define DISPLAY_H
#ifdef	__cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>

typedef struct
{
    uint16_t width;
    uint16_t height;
    bool (*clear_fn)();
}display_t;

bool set_display_size(display_t* disp, uint16_t width, uint16_t height);
bool display_clear(display_t* disp);

#ifdef	__cplusplus
}
#endif

#endif // DISPLAY_H
