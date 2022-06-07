#ifndef GRAPHIC2D_OBJECTS_H
#define GRAPHIC2D_OBJECTS_H
#ifdef	__cplusplus
extern "C" {
#endif

#include <stdint.h>

typedef struct
{
    uint16_t col;
    uint16_t row;
}pos2d_t;

typedef struct
{
    uint16_t start_col;
    uint16_t end_col;
    uint16_t start_row;
    uint16_t end_row;
}area2d_t;


typedef struct
{
    uint16_t width;
    uint16_t height;
    const uint8_t* array;
    uint8_t pixel_bit_size;
}graphic_t;

#ifdef	__cplusplus
}
#endif

#endif // GRAPHIC2D_OBJECTS_H
