#include "SSD1322.h"
#include "ssd1322_spi.h"
#include "ssd1322_cmd.h"
#include "image.h"
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

	for(i=0;i<ssd1322_gd.height;i++) //rows
	{
		for(j=0;j<ssd1322_gd.width;j+=4) //Rows: we send 4 pixels every 2 bytes (16 bits of data)
		{
			ssd1322_data(0x00);
			ssd1322_data(0x00);
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

	ssd1322_cmd_lock(0x12);				// FDh (0001 0[A2=0]10) Unlock OLED driver IC MCU interface from entering command [reset] p.36
	ssd1322_cmd(SSD1322_CMD_DISPLAY_OFF);		// AEh Sleep mode ON (Display OFF) p.33
	ssd1322_cmd_set_display_clock_oscfreq(0x91);	// B3h (1001) freq=(while more higher value more freq)  (0001) divided by 2 p.34
	ssd1322_cmd_multiplex_ratio(0x3F);		// CAh (0011 1111) <= 63 when dual COM mode is enabled p.41 p.36
	ssd1322_cmd_set_display_offset(0x00);		// A2h (0000 0000) (no offset/vertical scroll) Set vertical scroll by COM from 0-127 p.33 p.43
	ssd1322_cmd_set_display_start_line(0x00);	// A1h (0000 0000) Set display RAM display start line register from 0-127 p.32 p.42
	ssd1322_cmd_set_remap(0x14, 0x11);		// A0h A(0001 0100) B(0001 0001) p.32 p.39 p.40 p.41
							// 	A[5]=0b, Disable COM Split Odd Even [reset] pin assignment of common is in sequential as COM127 COM126...COM 65 COM64...SEG479...SEG0...COM0 COM1...COM62 COM63
							// 	A[4]=1b, Scan from COM[N-1] to COM0, where N is the Multiplex ratio
							// 	A[2]=1b, Enable Nibble Re-map
							// 	A[1]=0b, Disable Column Address Re-map [reset]
							// 	A[0]=0b, Horizontal address increment [reset]
							// 	B[4]=1b, Enable Dual COM mode (MUX <= 63)
	ssd1322_cmd_function_selection(0x01);		// ABh (0000 0001) A[0]=1b, Enable internal VDD regulator [reset]
	ssd1322_cmd_display_enh_a(0xA0,0x05|0xfd);	// B4h (1010 0000) (1111 1101) p.34
							// 	A[1:0] = 00b: Enable external VSL
							// 	B[7:3] = 11111b: Enhanced low GS display quality
	ssd1322_cmd_set_contrast_current(0x9F);		// C1h (1001 1111) p.35 A[7:0]: Contrast current value, range:00h~FFh, i.e. 256 steps for I SEG current [reset = 7Fh]
	ssd1322_cmd_master_current_control(0x0F);	// C7h (0000 1111) A[3:0] = 1111b, no change [reset] p.36
	ssd1322_cmd(SSD1322_CMD_SEL_DEF_LIN_GS_TABLE);	// B9h Default Linear Grayscale Table    
	ssd1322_cmd_set_phase_length(0xe2);		// B1h (1110 0010) Set Phase Length 
							// 	0010 = 5 DCLKs A[3:0] Phase 1 period (reset phase length) of 5~31 DCLK(s)
							// 	1110 = 15 DCLKs A[7:4] Phase 2 period (first pre-charge phase length)
	ssd1322_cmd_display_enh_b(0x082|0x020);		// D1h (1010 0010) A[5:4] = 10b: Normal [reset] (Display Enhancement) p.36
	ssd1322_cmd_set_precharge_voltage(0x1f);	// BBh (0001 1111) Set Precharge Voltage  0.60 x VCC p.35
	ssd1322_cmd_set_second_precharge_period(0x08);	// B6h (0000 1000) Set Second Precharge Period   8 dclks [reset] p.34
	ssd1322_cmd_set_vcomh_voltage(0x07);		// BEh (0000 0111) Set VCOMH Voltage     0.86 x VCC  p.35
	ssd1322_cmd(SSD1322_CMD_SET_DISPLAY_MODE_EOFF);	// A6h Set Normal Display    p.33
	ssd1322_cmd(SSD1322_CMD_EXIT_PARTIAL_DISPLAY);	// A9h Exit Partial Display Mode p.33   

	DELAY_milliseconds(2);
	ssd1322_cmd(SSD1322_CMD_DISPLAY_ON);		// AF Sleep Mode OFF
	DELAY_milliseconds(2);
	ssd1322_enabled(false);


	return true;
}

static const uint8_t gray_scale_to_mono_table[] = {0x00,0x0F,0xF0,0xFF};

static const uint8_t byte_mask_lower[] = {
	0b00000001,
	0b00000011,
	0b00000111,
	0b00001111,
	0b00011111,
	0b00111111,
	0b01111111,
	0b11111111
};

static const uint8_t byte_mask_upper[] = {
	0b10000000,
	0b11000000,
	0b11100000,
	0b11110000,
	0b11111000,
	0b11111100,
	0b11111110,
	0b11111111,
};

static bool ssd1322_draw(uint16_t col, uint16_t row, uint8_t* data, size_t size)
{
	size_t i, j, buff = 0;
	DELAY_milliseconds(2);
	ssd1322_enabled(true);
	DELAY_milliseconds(2);
	
	//TODO: as parameter
	//create image
	mimage_t img;
	img.array = data;
	img.height = 25; //NHLogo
	img.width = 232;
	img.pixels_per_byte = 8;
	//calculate column frontiers (col should be divisible by 4)
	uint8_t start_col = 0x1C + col/4;
	uint8_t end_col = start_col + (img.width/4) - 1;
	//calculate rows frontiers
	uint8_t start_row = 0x00 + row;
	uint8_t end_row = start_row + img.height-1;

	//TODO: Calculate row and col by size
	ssd1322_cmd_set_column_address(start_col,end_col);	// 15h Start col address = 28 ((112/4) seg112-115), end = 91 ((364/4) seg364-367)
	ssd1322_cmd_set_row_address(start_row,end_row); //75h start = 0, end = height-1
	ssd1322_cmd(SSD1322_CMD_WRITE_RAM);

	uint8_t col_residual = col%4;

	for(i=0;i<img.height;i++) //Rows
	{
		for(j=0;j<img.width;j+=img.pixels_per_byte) //Cols
		{
			/*buff |= (*data) >> col_residual;
			buff &= byte_mask_lower[8-col_residual];
			*/
			buff = *data;
			/*uint8_t div_step = img.pixels_per_byte/4;
			uint8_t div;
			for (div = img.pixels_per_byte - div_step; div >= 0; div -= div_step)
			{
				ssd1322_data(gray_scale_to_mono_table[(buff >> div) & 0x03]);
			}*/
			
			ssd1322_data(gray_scale_to_mono_table[(buff >> 6) & 0x03]);
			ssd1322_data(gray_scale_to_mono_table[(buff >> 4) & 0x03]);
			ssd1322_data(gray_scale_to_mono_table[(buff >> 2) & 0x03]);
			ssd1322_data(gray_scale_to_mono_table[buff & 0x03]);
			
			/*buff = (*data) << (8-col_residual);
			buff &= byte_mask_upper[col_residual];
			*/
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
