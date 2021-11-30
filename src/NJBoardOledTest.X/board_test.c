#include "board_test.h"

#include "mcc_generated_files/system/system.h"
#include "mcc_generated_files/timer/delay.h"
#include "mcc_generated_files/timer/tmr0.h"
#include "mcc_generated_files/system/pins.h"

#include <stdarg.h>


/* const uint8_t SSD1306_I2C_ADDR = 0x3C; */ /* 7-bit address */

const uint8_t SSD1306_SINGLE_MSK = 0x80;
const uint8_t SSD1306_STREAM_MSK = 0x00;

const uint8_t SSD1306_DATA_MSK = 0x40;
const uint8_t SSD1306_CMD_MSK = 0x00;
#define I2C_BUFFER_SIZE 128*8+1
static uint8_t i2c_buffer[I2C_BUFFER_SIZE];
static uint8_t* i2c_buffer_p;

inline void reset_i2c_buffer()
{
	i2c_buffer_p = &i2c_buffer[0];
}

inline void add_i2c_byte(uint8_t byte)
{
	*i2c_buffer_p = byte;
	i2c_buffer_p++;
}


inline bool send_i2c_buffer(uint8_t address)
{
	if(i2c_host_interface.Write
			(address,i2c_buffer,(size_t)(i2c_buffer_p - i2c_buffer)))
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
	/*const uint8_t control_byte = 
		SSD1306_SINGLE_MSK | SSD1306_CMD_MSK;
	const uint8_t cmd = 0xE3;
#define TEST_DATA_LENGHT 2

	uint8_t pData[TEST_DATA_LENGHT];
	pData[0] = control_byte;
	pData[1] = cmd;
	return send_i2c_buffer(address,pData,TEST_DATA_LENGHT);*/
	return true;
}

/*static bool send_i2c_bytes(uint8_t address, uint8_t *buffer, size_t bytes, ...)
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
}*/

bool hw_test_display(uint8_t address)
{
	DELAY_milliseconds(100);
	reset_i2c_buffer();
	add_i2c_byte(SSD1306_STREAM_MSK | SSD1306_CMD_MSK);

	add_i2c_byte(0xAE);

	add_i2c_byte(0xD5);
	add_i2c_byte(0x81);


	add_i2c_byte(0x81);
	add_i2c_byte(0x7F);

	add_i2c_byte(0x20);
	add_i2c_byte(0x00);

	add_i2c_byte(0x40);

	add_i2c_byte(0xA8);
	add_i2c_byte(63);

	add_i2c_byte(0xDA);
	add_i2c_byte(0x02);

	add_i2c_byte(0xA0);

	add_i2c_byte(0xC0);

	add_i2c_byte(0xA6);

	add_i2c_byte(0x2E);

	add_i2c_byte(0xD9);
	add_i2c_byte(0x2);

	add_i2c_byte(0x8D);
	add_i2c_byte(0x14);

	add_i2c_byte(0xAF);

	return send_i2c_buffer(address);

}

void hw_test_display_pixel(uint8_t pixel)
{

}

void hw_test_display_fill(uint8_t address)
{


	DELAY_milliseconds(5000);
	reset_i2c_buffer();
	add_i2c_byte(SSD1306_STREAM_MSK | SSD1306_CMD_MSK);
	/* Set column (segment) from 0 to 127*/
	add_i2c_byte(0x21);
	add_i2c_byte(0);
	add_i2c_byte(127);
	/* Set row (page) from 0 to 3*/
	add_i2c_byte(0x22);
	add_i2c_byte(0);
	add_i2c_byte(7);

	send_i2c_buffer(address);

	reset_i2c_buffer();
	add_i2c_byte(SSD1306_STREAM_MSK | SSD1306_DATA_MSK);

	size_t i,j;
	add_i2c_byte(0b11111111);
	for (i=0; i<128-2; i++)
	{
		add_i2c_byte(0b00000001);
	}
	add_i2c_byte(0b11111111);
	for (i=0; i<6; i++)
	{
		add_i2c_byte(0b11111111);
		for (j=0; j<128-2; j++)
		{
			add_i2c_byte(0b00000000);
		}
		add_i2c_byte(0b11111111);
	}
	add_i2c_byte(0b11111111);
	for (i=0; i<128-2; i++)
	{
		add_i2c_byte(0b10000000);
	}
	add_i2c_byte(0b11111111);

	send_i2c_buffer(address);
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
