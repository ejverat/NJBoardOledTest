#include "NHD-312-25664UCB2.h"
#include "ssd1322.h"
#include "timer.h"
#include "ssd1322_utils.h"
#include <stddef.h>

#define GET_COL_ADDRESS(pix) (uint8_t)(start_col_address+(pix/4))
#define GET_ROW_ADDRESS(pix) (uint8_t)(start_row_com+pix)

static gdisplay_driver_t driver;
static uint8_t buffer[15];

// NHD-3.12-25664UCB2
static const uint16_t width = 256;
static const uint16_t height = 64;
static const uint8_t start_col_address = 0x1C;
static const uint8_t end_col_address = 0x5B;
static const uint8_t start_row_com = 0;
static const uint8_t end_row_com = 63;

void nhd31225664ucb2_setup(gdisplay_t* display, display_comm_t* comm, waiter_t* timer)
{
    ssd1322_setup(&driver,comm,timer);
    display->driver = &driver;
    display->height = height;
    display->width = width;
    display->clear_fn = nhd31225664ucb2_clear;
    display->draw_fn = nhd31225664ucb2_draw;
}

bool nhd31225664ucb2_init()
{
    return driver.init_fn();
}

bool nhd31225664ucb2_clear(area2d_t* area)
{
    size_t i,j;

    driver.timer->wait_ms(2);
    driver.comm->enable_fn();
    driver.timer->wait_ms(2);

    buffer[0] = ssd1322_col_pixel_to_address(area->start_col, start_col_address);
    buffer[1] = ssd1322_col_pixel_to_address(area->end_col-1, start_col_address);
    driver.send_cmd_fn(SSD1322_CMD_SET_COLUMN_ADDRESS, buffer);

    buffer[0] = ssd1322_row_pixel_to_address(area->start_row, start_row_com);
    buffer[1] = ssd1322_row_pixel_to_address(area->end_row-1, start_row_com);
    driver.send_cmd_fn(SSD1322_CMD_SET_ROW_ADDRESS, buffer);

    driver.send_cmd_fn(SSD1322_CMD_WRITE_RAM, buffer);

    uint16_t words_to_send = ssd1322_words_to_send(area->start_col, area->end_col, area->start_row, area->end_row);

    buffer[0] = 0;
    buffer[1] = 0;
    for(i = 0; i < words_to_send; i++)
    {
        if (!driver.send_data_fn(buffer,2))
            return false;
    }
    driver.timer->wait_ms(2);
    driver.comm->disable_fn();
    return true;
}

static const uint8_t gray_scale_to_mono_table[] = {0x00,0x0F,0xF0,0xFF};

bool nhd31225664ucb2_draw(pos2d_t* pos, graphic_t* graphic)
{
    size_t i, j;
    driver.timer->wait_ms(2);
    driver.comm->enable_fn();
    driver.timer->wait_ms(2);

    //TODO: as parameter
    //create image
    /*
    img.height = 25; //NHLogo
    img.width = 232;
    */

    buffer[0] = GET_COL_ADDRESS(pos->col);
    buffer[1] = GET_COL_ADDRESS((uint16_t)(pos->col + graphic->width - 1));
    driver.send_cmd_fn(SSD1322_CMD_SET_COLUMN_ADDRESS, buffer);

    buffer[0] = GET_ROW_ADDRESS(pos->row);
    buffer[1] = GET_ROW_ADDRESS((uint16_t)(pos->row + graphic->height - 1));
    driver.send_cmd_fn(SSD1322_CMD_SET_ROW_ADDRESS, buffer);

    driver.send_cmd_fn(SSD1322_CMD_WRITE_RAM, buffer);

    //TODO: handle more pixel bits resolution, just 1 bit of resolution is supported now

    uint8_t* byte = (uint8_t*)graphic->array;

    for ( i = 0; i < graphic->height; i++) //Rows
    {
        for ( j = 0; j < graphic->width; j += 8/graphic->pixel_bit_size) //Cols
        {
            buffer[0] = gray_scale_to_mono_table[(*byte >> 6) & 0x03];
            buffer[1] = gray_scale_to_mono_table[(*byte >> 4) & 0x03];
            buffer[2] = gray_scale_to_mono_table[(*byte >> 2) & 0x03];
            buffer[3] = gray_scale_to_mono_table[*byte & 0x03];
            if (!driver.send_data_fn(buffer,4))
                return false;

            byte++;
        }
    }

    driver.timer->wait_ms(2);
    driver.comm->disable_fn();
    driver.timer->wait_ms(2);
    return true;
}
