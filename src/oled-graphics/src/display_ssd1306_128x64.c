#include "display_ssd1306_128x64.h"
#include "ssd1306.h"
#include "ssd1306_utils.h"

static gdisplay_driver_t driver;
static uint8_t buffer[15];

static const uint16_t width = 128;
static const uint16_t height = 64;

void display_ssd1306_128x64_setup(gdisplay_t* display, display_comm_t* comm, waiter_t* timer)
{
    ssd1306_setup(&driver,comm,timer);
    display->driver = &driver;
    display->height = height;
    display->width = width;
    display->clear_fn = display_ssd1306_128x64_clear;
    display->draw_fn = display_ssd1306_128x64_draw;
}
bool display_ssd1306_128x64_init()
{
    return driver.init_fn();
}
bool display_ssd1306_128x64_clear(area2d_t* area)
{
    size_t i;

    driver.comm->enable_fn();

    buffer[0] = area->start_col;
    buffer[1] = area->end_col-1;
    driver.send_cmd_fn(SSD1306_CMD_COLUMNADDR, buffer);

    buffer[0] = ssd1306_row2page(area->start_row);
    buffer[1] = ssd1306_row2page(area->end_row);
    driver.send_cmd_fn(SSD1306_CMD_PAGEADDR, buffer);

    driver.comm->disable_fn();

    uint16_t bytes_to_send = (area->end_col - area->start_col) * (area->end_row - area->start_row);

    buffer[0] = 0;
    driver.comm->enable_fn();
    for(i = 0; i < bytes_to_send; i++)
    {
        if (!driver.send_data_fn(buffer,1))
            return false;
    }
    driver.comm->disable_fn();
    return true;
}
bool display_ssd1306_128x64_draw(pos2d_t* pos, graphic_t* graphic)
{
    size_t i;

    driver.comm->enable_fn();

    buffer[0] = pos->col;
    buffer[1] = pos->col+graphic->width-1;
    driver.send_cmd_fn(SSD1306_CMD_COLUMNADDR, buffer);

    buffer[0] = ssd1306_row2page(pos->row);
    buffer[1] = ssd1306_row2page(pos->row+graphic->height-1);
    driver.send_cmd_fn(SSD1306_CMD_PAGEADDR, buffer);

    driver.comm->disable_fn();

    uint16_t bytes_to_send = graphic->height*graphic->width;

    driver.comm->enable_fn();
    if (!driver.send_data_fn((uint8_t *)graphic->array,bytes_to_send))
        return false;
    driver.comm->disable_fn();
    return true;
}
