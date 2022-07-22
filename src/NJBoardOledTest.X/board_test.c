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

#include "disp_i2c_comm.h"
#include "display_ssd1306_128x64.h"

static gdisplay_t nhaven_disp;
static gdisplay_t ssd1306_12864_disp;
extern graphic_t test_image_64x55;
extern graphic_t test_image_37x32;

void hw_test_display_ssd1306(uint8_t address, size_t width, size_t height)
{

  i2c_comm_set_address(address);
  display_ssd1306_128x64_setup (&ssd1306_12864_disp,i2c_comm_instance (),timer_delay_instance ());
  display_ssd1306_128x64_init ();

  waiter_t* w = timer_delay_instance();
  area2d_t area;
  area.start_col = 0;
  area.start_row = 0;
  area.end_col = width;
  area.end_row = height;
  ssd1306_12864_disp.clear_fn(&area);
  
  pos2d_t pos;
  pos.col = 0;
  pos.row = 0;

  const graphic_t gtemp = 
  {
	  128,
	  32,
	  (const uint8_t*) &ev_img2[0],
	  1
  };
  
  ssd1306_12864_disp.draw_fn(&pos,&test_image_37x32);
  
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
  
  pos2d_t pos;
  pos.col = 0;
  pos.row = 0;
  
  nhaven_disp.draw_fn(&pos,&test_image_64x55);

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
