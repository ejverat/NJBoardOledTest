#ifndef SSD1306_UTILS_H
#define SSD1306_UTILS_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdint.h>

inline uint8_t ssd1306_row2page(uint8_t row)
{
    return row/8;
}

#ifdef	__cplusplus
}
#endif
#endif // SSD1306_UTILS_H
