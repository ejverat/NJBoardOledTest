#include "board_test.h"

#include "mcc_generated_files/system/system.h"
#include "mcc_generated_files/timer/delay.h"
#include "mcc_generated_files/timer/tmr0.h"
#include "mcc_generated_files/system/pins.h"
#include "mcc_generated_files/spi/mssp1.h"

#include "gdisplay.h"
#include "SSD1322.h"
#include "SSD1306.h"
#include "images.h"

#include <stdarg.h>


void hw_test_display_ssd1306(uint8_t address, size_t width, size_t height)
{
	ssd1306_setup(address, height,width);
	gdisplay_t* gd = ssd1306_get_gd();
	init_gdisplay(gd);

	DELAY_milliseconds(2000);
	clear_gdisplay(gd);
	DELAY_milliseconds(2000);

	image_t logo;
	logo.data = ev_img;
	logo.size = sizeof(ev_img);
	draw_gdisplay(gd, 0, 1, &logo);
	DELAY_milliseconds(5000);
}

void hw_test_display_ssd1322(size_t height, size_t width)
{
	//reset status
	ssd1322_setup(height, width);
	gdisplay_t* gd = ssd1322_get_gd();
	init_gdisplay(gd);

	DELAY_milliseconds(2000);
	clear_gdisplay(gd);
	DELAY_milliseconds(2000);

	image_t logo;
	logo.data = NHD_Logo;
	logo.size = sizeof(NHD_Logo);
	uint16_t col;
	for (col = 0; col < width-232; col++)
	{
		clear_gdisplay(gd);
		draw_gdisplay(gd, col, 0, &logo);
		DELAY_milliseconds(1000);
	}
	uint16_t row;
	for (row = 0; row < height-25; row++)
	{
		clear_gdisplay(gd);
		draw_gdisplay(gd, 0, row, &logo);
		DELAY_milliseconds(1000);
	}
	DELAY_milliseconds(5000);
}


static void tmr0_callback()
{
	OUT1_Toggle();
}

void hw_test_osc()
{
	Timer0_Initialize();
	Timer0_OverflowCallbackRegister(tmr0_callback);
}
