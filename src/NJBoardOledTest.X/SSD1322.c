#include "SSD1322.h"
#include "ssd1322_spi.h"
#include "ssd1322_cmd.h"
#include "mcc_generated_files/timer/delay.h"

static gdisplay_t ssd1322_gd;

static bool ssd1322_cmd(ssd1322_cmd_t byte)
{
	ssd1322_set_cmd(true);
	return ssd1322_write_byte((uint8_t)byte);
}

static bool ssd1322_data(uint8_t byte)
{
	ssd1322_set_cmd(false);
	return ssd1322_write_byte(byte);
}

static bool ssd1322_cmd_set_column_address(uint8_t start, uint8_t end)
{
	ssd1322_cmd(SSD1322_CMD_SET_COLUMN_ADDRESS);
	ssd1322_data(start);
	ssd1322_data(end);
	return true;
}

static bool ssd1322_cmd_set_row_address(uint8_t start, uint8_t end)
{
	ssd1322_cmd(SSD1322_CMD_SET_ROW_ADDRESS);
	ssd1322_data(start);
	ssd1322_data(end);
	return true;
}

static bool ssd1322_cmd_lock(uint8_t lock)
{
	ssd1322_cmd(SSD1322_CMD_LOCK);
	ssd1322_data(lock);
	return true;
}

static bool ssd1322_cmd_set_display_clock_oscfreq(uint8_t a)
{
	ssd1322_cmd(SSD1322_CMD_SET_FCD_OSCFREQ);
	ssd1322_data(a);
	return true;
}
	
static bool ssd1322_cmd_multiplex_ratio(uint8_t a)
{
	ssd1322_cmd(SSD1322_CMD_SET_MULT_RATIO);
	ssd1322_data(a);
	return true;
}

static bool ssd1322_cmd_set_display_offset(uint8_t a)
{
	ssd1322_cmd(SSD1322_CMD_SET_DISPLAY_OFFSET);
	ssd1322_data(a);
	return true;
}

static bool ssd1322_cmd_set_display_start_line(uint8_t a)
{
	ssd1322_cmd(SSD1322_CMD_SET_DISPLAY_START_L);
	ssd1322_data(a);
	return true;
}

static bool ssd1322_cmd_set_remap(uint8_t a,uint8_t b)
{
	ssd1322_cmd(SSD1322_CMD_SET_REMAP_DUAL_COM);
	ssd1322_data(a);
	ssd1322_data(b);
	return true;
}

static bool ssd1322_cmd_function_selection(uint8_t a)
{
	ssd1322_cmd(SSD1322_CMD_SET_FUNCTION_SEL);
	ssd1322_data(a);
	return true;
}

static bool ssd1322_cmd_display_enh_a(uint8_t a,uint8_t b)
{
	ssd1322_cmd(SSD1322_CMD_DISPLAY_ENH_A);
	ssd1322_data(a);
	ssd1322_data(b);
	return true;
}

static bool ssd1322_cmd_set_contrast_current(uint8_t a)
{
	ssd1322_cmd(SSD1322_CMD_SET_CONTRAST_CURR);
	ssd1322_data(a);
	return true;
}

static bool ssd1322_cmd_master_current_control(uint8_t a)
{
	ssd1322_cmd(SSD1322_CMD_MASTER_CURR_CONTROL);
	ssd1322_data(a);
	return true;
}

static bool ssd1322_cmd_set_phase_length(uint8_t a)
{
	ssd1322_cmd(SSD1322_CMD_SET_PHASE_L);
	ssd1322_data(a);
	return true;
}

static bool ssd1322_cmd_display_enh_b(uint8_t a)
{
	ssd1322_cmd(SSD1322_CMD_DISPLAY_ENH_B);
	ssd1322_data(a);
	return true;
}

static bool ssd1322_cmd_set_precharge_voltage(uint8_t a)
{
	ssd1322_cmd(SSD1322_CMD_SET_PRE_CHARGE_V);
	ssd1322_data(a);
	return true;
}

static bool ssd1322_cmd_set_second_precharge_period(uint8_t a)
{
	ssd1322_cmd(SSD1322_CMD_SET_2ND_PRE_PERIOD);
	ssd1322_data(a);
	return true;
}

static bool ssd1322_cmd_set_vcomh_voltage(uint8_t a)
{
	ssd1322_cmd(SSD1322_CMD_SET_VCOMH);
	ssd1322_data(a);
	return true;
}

static bool ssd1322_clear()
{
	size_t i,j;

	DELAY_milliseconds(2);
	ssd1322_enabled(true);
	DELAY_milliseconds(2);
	ssd1322_cmd_set_column_address(0x1C,0x5B);
	ssd1322_cmd_set_row_address(0x00,ssd1322_gd.height-1);
	ssd1322_cmd(SSD1322_CMD_WRITE_RAM);

	for(i=0;i<ssd1322_gd.width/4;i++) //Columns
	{
		for(j=0;j<ssd1322_gd.height*2;j++) //Rows
		{
			ssd1322_data(0x00);
			DELAY_microseconds(100);
		}
	}
	DELAY_milliseconds(2);
	ssd1322_enabled(false);

	return true;
}

static bool ssd1322_init()
{
	DELAY_milliseconds(1000);
	ssd1322_spi_init();

	ssd1322_enabled(false);

	ssd1322_reset(true);
	DELAY_milliseconds(150);
	ssd1322_reset(false);
	DELAY_milliseconds(300);

	//init commands
	DELAY_milliseconds(2);
	ssd1322_enabled(true);
	DELAY_milliseconds(2);

	ssd1322_cmd_lock(0x12);
	ssd1322_cmd(SSD1322_CMD_DISPLAY_OFF);
	ssd1322_cmd_set_display_clock_oscfreq(0x91);
	ssd1322_cmd_multiplex_ratio(0x3F);
	ssd1322_cmd_set_display_offset(0x00);
	ssd1322_cmd_set_display_start_line(0x00);
	ssd1322_cmd_set_remap(0x06,0x11);
	ssd1322_cmd_function_selection(0x01);
	ssd1322_cmd_display_enh_a(0xA0,0x05|0xfd);
	ssd1322_cmd_set_contrast_current(0x9F);
	ssd1322_cmd_master_current_control(0x0F);
	ssd1322_cmd(SSD1322_CMD_SEL_DEF_LIN_GS_TABLE);                        // Default Linear Grayscale Table    
	ssd1322_cmd_set_phase_length(0xe2);                             // Set Phase Length       
	ssd1322_cmd_display_enh_b(0x082|0x020);                          // Display Enhancement      
	ssd1322_cmd_set_precharge_voltage(0x1f);                        // Set Precharge Voltage    
	ssd1322_cmd_set_second_precharge_period(0x08);                  // Set Second Precharge Period    
	ssd1322_cmd_set_vcomh_voltage(0x07);                            // Set VCOMH Voltage     
	ssd1322_cmd(SSD1322_CMD_SET_DISPLAY_MODE_EOFF);                                 // Set Normal Display    
	ssd1322_cmd(SSD1322_CMD_EXIT_PARTIAL_DISPLAY);                             // Exit Partial Display Mode    

	DELAY_milliseconds(2);
	ssd1322_cmd(SSD1322_CMD_DISPLAY_ON);                               // Sleep Mode OFF
	DELAY_milliseconds(2);
	ssd1322_enabled(false);


	return true;
}

static bool ssd1322_draw(uint16_t col, uint16_t row, uint8_t* data, size_t size)
{
	size_t i, j, buff;
	DELAY_milliseconds(2);
	ssd1322_enabled(true);
	DELAY_milliseconds(2);

	//TODO: Calculate row and col by size
	ssd1322_cmd_set_remap(0x14, 0x11);
	ssd1322_cmd_set_column_address(0x1C,0x5B);
	ssd1322_cmd_set_row_address(0x00,ssd1322_gd.height-1);
	ssd1322_cmd(SSD1322_CMD_WRITE_RAM);

	for(i=0;i<64;i++) //Columns
	{
		for(j=0;j<32;j++) //Rows
		{
			buff = *data;
			buff = ((buff >> 6) & 0x03);
			if(buff == 0x03){ssd1322_data(0xFF);}
			else if(buff == 0x02){ssd1322_data(0xF0);}
			else if(buff == 0x01){ssd1322_data(0x0F);}
			else ssd1322_data(0x00);

			buff = *data;
			buff = ((buff >> 4) & 0x03);
			if(buff == 0x03){ssd1322_data(0xFF);}
			else if(buff == 0x02){ssd1322_data(0xF0);}
			else if(buff == 0x01){ssd1322_data(0x0F);}
			else ssd1322_data(0x00);

			buff = *data;
			buff = ((buff >> 2) & 0x03);
			if(buff == 0x03){ssd1322_data(0xFF);}
			else if(buff == 0x02){ssd1322_data(0xF0);}
			else if(buff == 0x01){ssd1322_data(0x0F);}
			else ssd1322_data(0x00);

			buff = *data;
			buff = (buff & 0x03);
			if(buff == 0x03){ssd1322_data(0xFF);}
			else if(buff == 0x02){ssd1322_data(0xF0);}
			else if(buff == 0x01){ssd1322_data(0x0F);}
			else ssd1322_data(0x00);

			data++;
		}
	}
	DELAY_milliseconds(2);
	ssd1322_enabled(false);
	DELAY_milliseconds(2);

	return true;
}

void ssd1322_setup(size_t height, size_t width)
{
	ssd1322_gd.init_fn = ssd1322_init;
	ssd1322_gd.clear_fn = ssd1322_clear;
	ssd1322_gd.draw_fn = ssd1322_draw;
	ssd1322_gd.height = height;
	ssd1322_gd.width = width;
}

gdisplay_t* ssd1322_get_gd()
{
	return &ssd1322_gd;
}
