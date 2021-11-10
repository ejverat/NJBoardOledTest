#include "board_test.h"

#include "mcc_generated_files/system/system.h"
#include "mcc_generated_files/timer/delay.h"

#include <stdarg.h>


/* const uint8_t SSD1306_I2C_ADDR = 0x3C; */ /* 7-bit address */

const uint8_t SSD1306_SINGLE_MSK = 0x80;
const uint8_t SSD1306_STREAM_MSK = 0x00;

const uint8_t SSD1306_DATA_MSK = 0x40;
const uint8_t SSD1306_CMD_MSK = 0x00;

inline bool send_i2c_buffer(uint8_t address, uint8_t *buffer, size_t size)
{
	if(i2c_host_interface.Write
			(address,buffer,size))
	{
		DELAY_milliseconds(10);
		if(i2c_host_interface.IsBusy())
		{
			return false;
		}
		if(i2c_host_interface.ErrorGet() == I2C_ERROR_NONE)
		{
			return true;
		}
	}
	return false;
}

bool hw_test_i2c(uint8_t address)
{
	return true;
	const uint8_t control_byte = 
		SSD1306_SINGLE_MSK | SSD1306_CMD_MSK;
	const uint8_t cmd = 0xE3;
#define TEST_DATA_LENGHT 2

	uint8_t pData[TEST_DATA_LENGHT];
	pData[0] = control_byte;
	pData[1] = cmd;
	return send_i2c_buffer(address,pData,TEST_DATA_LENGHT);
}

static bool send_i2c_bytes(uint8_t address, uint8_t *buffer, size_t bytes, ...)
{
	va_list argp;
	va_start(argp,bytes);
	size_t i;
	for(i = 0 ; i < bytes ; i++)
	{
		buffer[i] = va_arg(argp,uint8_t);
	}
	va_end(argp);

	return send_i2c_buffer(address,buffer,bytes);
}

bool hw_test_display(uint8_t address)
{
	uint8_t tmp_buff[16];
	bool result[16];
	size_t i;

	for (i=0; i<16; i++)
	{
		result[i] = true;
	}
	/* Initialize Display */
	DELAY_milliseconds(10);
	/* Display off */
	uint8_t control_byte = 
		SSD1306_SINGLE_MSK | SSD1306_CMD_MSK;
	result[0] = send_i2c_bytes(address,tmp_buff,2,control_byte,0xAE);
	/* Set OSC Default 0x81 */
	control_byte = 
		SSD1306_STREAM_MSK | SSD1306_CMD_MSK;
	result[1] = send_i2c_bytes(address,tmp_buff,3,control_byte,0xD5,0x81);
	/* Brightness in range 0~255, default=0x7F */
	control_byte = 
		SSD1306_STREAM_MSK | SSD1306_CMD_MSK;
	result[2] = send_i2c_bytes(address,tmp_buff,3,control_byte,0x81,0x7F);
	/* Memory Address Mode: Horizontal=0, Vertical=1, Page=default=2 */
	control_byte = 
		SSD1306_STREAM_MSK | SSD1306_CMD_MSK;
	result[3] = send_i2c_bytes(address,tmp_buff,3,control_byte,0x20,0x00);
	/* Set Display start line in range 0x40~0x7F */
	control_byte = 
		SSD1306_SINGLE_MSK | SSD1306_CMD_MSK;
	result[4] = send_i2c_bytes(address,tmp_buff,2,control_byte,0x40);
	/* Set multiplex number (activated rows): rows=height-1, default=63 */
	control_byte = 
		SSD1306_STREAM_MSK | SSD1306_CMD_MSK;
	result[5] = send_i2c_bytes(address,tmp_buff,3,control_byte,0xA8,63);
	/* Reduce a half of height */
	control_byte = 
		SSD1306_STREAM_MSK | SSD1306_CMD_MSK;
	result[6] = send_i2c_bytes(address,tmp_buff,3,control_byte,0xDA,0x02);
	/* Segment (Column) normal mode, Inverse=0xA1 */
	control_byte = 
		SSD1306_SINGLE_MSK | SSD1306_CMD_MSK;
	result[7] = send_i2c_bytes(address,tmp_buff,2,control_byte,0xA0);
	/* Common (Row) normal mode, inverse=0xC8 */
	control_byte = 
		SSD1306_SINGLE_MSK | SSD1306_CMD_MSK;
	result[8] = send_i2c_bytes(address,tmp_buff,2,control_byte,0xC0);
	/* Display normal mode, inverse=0xA7 */
	control_byte = 
		SSD1306_SINGLE_MSK | SSD1306_CMD_MSK;
	result[9] = send_i2c_bytes(address,tmp_buff,2,control_byte,0xA6);
	/* Disable Scroll */
	control_byte = 
		SSD1306_SINGLE_MSK | SSD1306_CMD_MSK;
	result[10] = send_i2c_bytes(address,tmp_buff,2,control_byte,0x2E);
	/* Pre-charge period, default=2 */
	control_byte = 
		SSD1306_STREAM_MSK | SSD1306_CMD_MSK;
	result[11] = send_i2c_bytes(address,tmp_buff,3,control_byte,0xD9,2);
	/* Charge Pump: On=0x14, Off=0x10 */
	control_byte = 
		SSD1306_STREAM_MSK | SSD1306_CMD_MSK;
	result[12] = send_i2c_bytes(address,tmp_buff,3,control_byte,0x8D,0x14);
	/* Display on */
	control_byte = 
		SSD1306_SINGLE_MSK | SSD1306_CMD_MSK;
	result[13] = send_i2c_bytes(address,tmp_buff,2,control_byte,0xAF);



	return false;
}

void hw_test_display_pixel(uint8_t pixel)
{
}
