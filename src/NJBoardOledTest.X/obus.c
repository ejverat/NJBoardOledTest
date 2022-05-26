#include "obus.h"
#include <stdbool.h>

bool obus_write_byte(obus_t* bus, uint8_t byte)
{
	switch(bus->bus_type)
	{
		case I2C_BUS:
			break;
		case SPI_BUS:
			break;
	}
	return true;
}

bool obus_write_block(obus_t* bus, uint8_t* block, size_t block_size)
{
	switch(bus->bus_type)
	{
		case I2C_BUS:
			break;
		case SPI_BUS:
			break;
	}
	return true;
}
