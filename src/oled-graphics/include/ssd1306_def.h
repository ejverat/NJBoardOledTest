#ifndef SSD1306_DEF_H
#define SSD1306_DEF_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <inttypes.h>

const uint8_t SSD1306_SINGLE_MSK = 0x80;
const uint8_t SSD1306_STREAM_MSK = 0x00;

const uint8_t SSD1306_DATA_MSK = 0x40;
const uint8_t SSD1306_CMD_MSK = 0x00;

typedef enum
{
    SSD1306_CMD_SETLOWCOLUMN     = 0x00,
    SSD1306_CMD_SETHIGHCOLUMN    = 0x10,
    SSD1306_CMD_MEMORYMODE       = 0x20,
    SSD1306_CMD_COLUMNADDR       = 0x21,
    SSD1306_CMD_PAGEADDR         = 0x22,
    SSD1306_CMD_SET_FADE_AND_BLINK = 0x23,
    SSD1306_CMD_SCROLL_RHOR      = 0x26,
    SSD1306_CMD_SCROLL_LHOR      = 0x27,
    SSD1306_CMD_SCROLL_RVER      = 0x29,
    SSD1306_CMD_SCROLL_LVER      = 0x2A,
    SSD1306_CMD_DEACTIVATESCROLL = 0x2E,
    SSD1306_CMD_ACTIVATESCROLL 	 = 0x2F,
    SSD1306_CMD_SETSTARTLINE     = 0x40,
    SSD1306_CMD_DEFAULT_ADDRESS  = 0x78,
    SSD1306_CMD_SETCONTRAST      = 0x81,
    SSD1306_CMD_CHARGEPUMP       = 0x8D,
    SSD1306_CMD_SEGREMAP0        = 0xA0,
    SSD1306_CMD_SEGREMAP127      = 0xA1,
    SSD1306_CMD_SET_VER_SCROLL   = 0xA3,
    SSD1306_CMD_DISPLAYALLON_RESUME = 0xA4,
    SSD1306_CMD_DISPLAYALLON     = 0xA5,
    SSD1306_CMD_NORMALDISPLAY    = 0xA6,
    SSD1306_CMD_INVERTDISPLAY    = 0xA7,
    SSD1306_CMD_SETMULTIPLEX     = 0xA8,
    SSD1306_CMD_DISPLAYOFF       = 0xAE,
    SSD1306_CMD_DISPLAYON        = 0xAF,
    SSD1306_CMD_SETPAGE          = 0xB0,
    SSD1306_CMD_COMSCANINC       = 0xC0,
    SSD1306_CMD_COMSCANDEC       = 0xC8,
    SSD1306_CMD_SETDISPLAYOFFSET = 0xD3,
    SSD1306_CMD_SETDISPLAYCLOCKDIV = 0xD5,
    SSD1306_CMD_SET_ZOOM_IN		 = 0xD6,
    SSD1306_CMD_SETPRECHARGE     = 0xD9,
    SSD1306_CMD_SETCOMPINS       = 0xDA,
    SSD1306_CMD_SETVCOMDETECT    = 0xDB,
    SSD1306_CMD_NOP              = 0xE3,
} ssd1306_cmd_t;


#ifdef	__cplusplus
}
#endif

#endif // SSD1306_DEF_H