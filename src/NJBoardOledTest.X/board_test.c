#include "board_test.h"

#include "mcc_generated_files/system/system.h"
#include "mcc_generated_files/timer/delay.h"
#include "mcc_generated_files/timer/tmr0.h"
#include "mcc_generated_files/system/pins.h"
#include "mcc_generated_files/spi/mssp1.h"

#include "NHD-312-25664UCB2.h"
#include "timer_delay.h"
#include "disp_spi_comm.h"
#include "graphic2d_objects.h"
#include "images.h"

static gdisplay_t nhaven_disp;

/*#include "gdisplay.h"
#include "SSD1322.h"
#include "SSD1306.h"
#include "images.h"

#include <stdarg.h>
 */


void hw_test_display_ssd1306(uint8_t address, size_t width, size_t height)
{
  /*
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
	DELAY_milliseconds(5000);*/
}

void hw_test_display_ssd1322(size_t height, size_t width)
{
  nhd31225664ucb2_setup(&nhaven_disp,spi_comm_instance(),timer_delay_instance());
  nhd31225664ucb2_init ();
  
  area2d_t area;
  area.start_col = 0;
  area.start_row = 0;
  area.end_col = width;
  area.end_row = height;
  nhaven_disp.clear_fn(&area);
  
  graphic_t logo;
  logo.array = NHD_Logo;
  logo.pixel_bit_size = 1;
  logo.height = 25;
  logo.width = 232;
  
  pos2d_t pos;
  pos.col = 0;
  pos.row = 0;
  
  nhaven_disp.draw_fn(&pos,&logo);

  /*
   DELAY_milliseconds(2000);

  area.end_col = 232;
  area.end_row = 25;
  nhaven_disp.clear_fn(&area);
  */
  
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
