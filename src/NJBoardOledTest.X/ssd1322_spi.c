#include "SSD1322.h"
#include "mcc_generated_files/spi/mssp1.h"
#include "mcc_generated_files/system/pins.h"
#include "mcc_generated_files/timer/delay.h"


bool ssd1322_spi_init()
{
	SPI1.Open(0);
	return true;
}

void ssd1322_enabled(bool enabled)
{
	if (enabled)
	{
		IO_CS_SetLow();
	}
	else
	{
		IO_CS_SetHigh();
	}
}

void ssd1322_set_cmd(bool cmd)
{
	if (cmd)
	{
		IO_DC_SetLow();
	}
	else
	{
		IO_CS_SetHigh();
	}
}

void ssd1322_reset(bool cmd)
{
	if (true)
	{
		IO_RES_SetLow();
	}
	else
	{
		IO_RES_SetHigh();
	}
}

bool ssd1322_write_byte(uint8_t byte)
{
	SPI1.ByteExchange(byte);
	return true;
}
