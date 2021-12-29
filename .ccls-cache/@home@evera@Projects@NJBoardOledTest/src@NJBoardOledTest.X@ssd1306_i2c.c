#include "ssd1306_i2c.h"
#include <stdbool.h>
#include <inttypes.h>
#include"mcc_generated_files/i2c_host/mssp2.h"
#include "mcc_generated_files/timer/delay.h"

#define I2C_BUFFER_SIZE 128*8+1
static uint8_t i2c_buffer[I2C_BUFFER_SIZE];
static uint8_t* i2c_buff_p = NULL;
static uint8_t i2c_add;

void ssd1306_i2c_set_address(uint8_t address)
{
	i2c_add = address;
}

void ssd1306_i2c_reset_buffer()
{
	i2c_buff_p = &i2c_buffer[0];
}

void ssd1306_i2c_add_byte(uint8_t byte)
{
	*i2c_buff_p = byte;
	i2c_buff_p++;
}

bool ssd1306_i2c_send()
{
	if(i2c2_host_interface.Write
			(i2c_add,i2c_buffer,(size_t)(i2c_buff_p - i2c_buffer)))
	{
		DELAY_milliseconds(10);
		if(i2c2_host_interface.IsBusy())
		{
			return false;
		}
		if(i2c2_host_interface.ErrorGet() == I2C_ERROR_NONE)
		{
			return true;
		}
	}
	return false;
}
