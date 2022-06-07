#ifndef SSD1322_UTILS_H
#define SSD1322_UTILS_H
#ifdef	__cplusplus
extern "C" {
#endif

#include <stdint.h>

inline uint8_t ssd1322_col_pixel_to_address(uint16_t pixel, uint16_t col_address_offset)
{
  return (uint8_t)(col_address_offset+(pixel/4));
}

inline uint8_t ssd1322_row_pixel_to_address(uint16_t pixel, uint16_t row_address_offset)
{
  return (uint8_t)(row_address_offset+pixel);
}

inline uint16_t ssd1322_words_to_send(uint16_t start_col, uint16_t end_col, uint16_t start_row, uint16_t end_row)
{
    uint16_t col_size = end_col - start_col;
    uint16_t row_size = end_row - start_row;
    if (col_size == 0 || row_size == 0)
        return 0;
    return (col_size/4)*row_size;
    /*if (col_size >= 4 && col_size < 8 && row_size >= 4 && row_size < 8)
        return 1;
    if (col_size >= 8 && row_size == 8)
        return 2;
    return 0;*/
}

#ifdef	__cplusplus
}
#endif

#endif // SSD1322_UTILS_H
