#include "fetcher.h"
#include "string.h"

uint8_t fetch_vertical_byte(graphic_t* image, pos2d_t* pos)
{
    uint8_t byte = 0;

    uint16_t bytes_per_row = image->width/8;
    uint8_t remainder_bits = image->width%8;
    if (0 != remainder_bits)
    {
        bytes_per_row++;
    }

    uint16_t byte_col_pos = pos->col/8;
    uint8_t col_bit_offset = pos->col % 8;
    uint16_t start_byte = (pos->row*bytes_per_row);

    uint16_t i,array_idx;
    array_idx = start_byte+byte_col_pos;
    for (i=0; i < 8 ; i++)
    {
        if (array_idx >= (image->height*bytes_per_row))
            break;
        uint8_t bit_mask = 0b10000000 >> col_bit_offset;
        if ((image->array[array_idx] & bit_mask) != 0)
        {
            byte |= (0b00000001) << i;
        }

        array_idx += bytes_per_row;
    }
    return byte;
}
