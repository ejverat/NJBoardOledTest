#include "SSD1306.h"
#include "ssd1306_i2c.h"
#include "ssd1306_cmd.h"
#include "mcc_generated_files/timer/delay.h"

static gdisplay_t ssd1306_gd;

static bool ssd1306_init()
{
	DELAY_milliseconds(100);
	ssd1306_i2c_reset_buffer();
	ssd1306_i2c_add_byte(SSD1306_STREAM_MSK | SSD1306_CMD_MSK);

	ssd1306_i2c_add_byte(SSD1306_CMD_DISPLAYOFF);

	ssd1306_i2c_add_byte(SSD1306_CMD_SETDISPLAYCLOCKDIV);
	ssd1306_i2c_add_byte(0x81);


	ssd1306_i2c_add_byte(SSD1306_CMD_SETCONTRAST);
	ssd1306_i2c_add_byte(0x7F);

	ssd1306_i2c_add_byte(SSD1306_CMD_MEMORYMODE);
	ssd1306_i2c_add_byte(0x00);

	ssd1306_i2c_add_byte(SSD1306_CMD_SETSTARTLINE | 0);

	ssd1306_i2c_add_byte(SSD1306_CMD_SETMULTIPLEX);
	ssd1306_i2c_add_byte(63);

	ssd1306_i2c_add_byte(SSD1306_CMD_SETCOMPINS);
	ssd1306_i2c_add_byte(0x02);

	ssd1306_i2c_add_byte(SSD1306_CMD_SEGREMAP);

	ssd1306_i2c_add_byte(SSD1306_CMD_COMSCANINC);

	ssd1306_i2c_add_byte(SSD1306_CMD_NORMALDISPLAY);

	ssd1306_i2c_add_byte(SSD1306_CMD_DEACTIVATESCROLL);

	ssd1306_i2c_add_byte(SSD1306_CMD_SETPRECHARGE);
	ssd1306_i2c_add_byte(0x2);

	ssd1306_i2c_add_byte(SSD1306_CMD_CHARGEPUMP);
	ssd1306_i2c_add_byte(0x14);

	ssd1306_i2c_add_byte(SSD1306_CMD_DISPLAYON);

	return ssd1306_i2c_send();
}

static bool ssd1306_clear()
{
	ssd1306_i2c_reset_buffer();
	ssd1306_i2c_add_byte(SSD1306_STREAM_MSK | SSD1306_CMD_MSK);
	/* Set column (segment) */
	ssd1306_i2c_add_byte(SSD1306_CMD_COLUMNADDR);
	ssd1306_i2c_add_byte(0);
	ssd1306_i2c_add_byte(ssd1306_gd.width-1);
	/* Set row (page) */
	ssd1306_i2c_add_byte(SSD1306_CMD_PAGEADDR);
	ssd1306_i2c_add_byte(0);
	ssd1306_i2c_add_byte(ssd1306_gd.height/8 - 1);

	if (!ssd1306_i2c_send())
		return false;

	ssd1306_i2c_reset_buffer();
	ssd1306_i2c_add_byte(SSD1306_STREAM_MSK | SSD1306_DATA_MSK);

	size_t i,j;
	ssd1306_i2c_add_byte(0x00);
	for (i=0; i<ssd1306_gd.width*(ssd1306_gd.height/8) - 1; i++)
	{
		ssd1306_i2c_add_byte(0x00);
	}
	return ssd1306_i2c_send();
}

/*row should be from 0 to 7 maximum */
static bool ssd1306_draw(uint16_t col, uint16_t row, uint8_t* data, size_t size)
{
	ssd1306_i2c_reset_buffer();
	ssd1306_i2c_add_byte(SSD1306_STREAM_MSK | SSD1306_CMD_MSK);
	/* Set column (segment) */
	ssd1306_i2c_add_byte(SSD1306_CMD_COLUMNADDR);
	ssd1306_i2c_add_byte(col);
	ssd1306_i2c_add_byte(ssd1306_gd.width-1);
	/* Set row (page) */
	ssd1306_i2c_add_byte(SSD1306_CMD_PAGEADDR);
	ssd1306_i2c_add_byte(row);
	ssd1306_i2c_add_byte(ssd1306_gd.height/8 - 1);

	if (!ssd1306_i2c_send())
		return false;

	ssd1306_i2c_reset_buffer();
	ssd1306_i2c_add_byte(SSD1306_STREAM_MSK | SSD1306_DATA_MSK);

	size_t i;
	for (i=0; i<size; i++)
	{
		ssd1306_i2c_add_byte(data[i]);
	}
	return ssd1306_i2c_send();
}

void ssd1306_setup(uint8_t address, size_t height, size_t width)
{
	ssd1306_gd.init_fn = ssd1306_init;
	ssd1306_gd.clear_fn = ssd1306_clear;
	ssd1306_gd.draw_fn = ssd1306_draw;
	ssd1306_gd.height = height;
	ssd1306_gd.width = width;

	ssd1306_i2c_set_address(address);
}

gdisplay_t* ssd1306_get_gd()
{
	return &ssd1306_gd;
}
