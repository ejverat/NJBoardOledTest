#include "ssd1306_cmd.h"

uint8_t ssd1306_cmd_num_params(ssd1306_cmd_t cmd)
{
    uint8_t num_params = 0;
    switch(cmd)
    {
    case SSD1306_CMD_MEMORYMODE:
    case SSD1306_CMD_SET_FADE_AND_BLINK:
    case SSD1306_CMD_SETCONTRAST:
    case SSD1306_CMD_SETMULTIPLEX:
    case SSD1306_CMD_SETDISPLAYOFFSET:
    case SSD1306_CMD_SET_ZOOM_IN:
    case SSD1306_CMD_SETCOMPINS:
    case SSD1306_CMD_SETDISPLAYCLOCKDIV:
    case SSD1306_CMD_SETPRECHARGE:
    case SSD1306_CMD_SETVCOMDETECT:
    case SSD1306_CMD_CHARGEPUMP:
        num_params = 1;
        break;
    case SSD1306_CMD_COLUMNADDR:
    case SSD1306_CMD_PAGEADDR:
    case SSD1306_CMD_SET_VER_SCROLL:
        num_params = 2;
        break;
    case SSD1306_CMD_SCROLL_RHOR:
    case SSD1306_CMD_SCROLL_LHOR:
        num_params = 6;
        break;
    case SSD1306_CMD_SCROLL_RVER:
    case SSD1306_CMD_SCROLL_LVER:
        num_params = 5;
        break;
    default:
        num_params = 0;
        break;
    }
    return num_params;
}
void ssd1306_param_mask(ssd1306_cmd_t cmd, uint8_t param_index, uint8_t* param)
{
    uint8_t and_mask = 0xff;
    uint8_t or_mask = 0x00;
    switch(cmd)
    {
    case SSD1306_CMD_SET_ZOOM_IN:
        and_mask = 0b00000001;
        break;
    case SSD1306_CMD_SETCOMPINS:
        and_mask = 0b00110000;
        or_mask =  0b00000010;
        break;
    case SSD1306_CMD_SETVCOMDETECT:
        and_mask = 0b01110000;
        break;
    case SSD1306_CMD_CHARGEPUMP:
        and_mask = 0b00000100;
        or_mask =  0b00010000;
        break;
    case SSD1306_CMD_SCROLL_RHOR:
    case SSD1306_CMD_SCROLL_LHOR:
        if (param_index == 0 || param_index == 4)
            and_mask = 0b00000000;
        else if(param_index == 5)
        {
            or_mask =  0b11111111;
        }
        break;
    case SSD1306_CMD_SCROLL_RVER:
    case SSD1306_CMD_SCROLL_LVER:
        if (param_index == 0)
            and_mask = 0b00000000;
        break;
    default:
        and_mask = 0xff;
        or_mask = 0x00;
        break;
    }
    *param &= and_mask;
    *param |= or_mask;
}
