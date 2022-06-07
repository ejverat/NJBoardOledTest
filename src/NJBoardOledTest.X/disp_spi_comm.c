#include "disp_spi_comm.h"
#include "mcc_generated_files/spi/mssp1.h"
#include "mcc_generated_files/system/pins.h"

static display_comm_t comm;

display_comm_t* spi_comm_instance()
{
  comm.init_fn = spi_comm_init;
  comm.enable_fn = spi_comm_enable;
  comm.disable_fn = spi_comm_disable;
  comm.start_reset_fn = spi_comm_start_reset;
  comm.end_reset_fn = spi_comm_end_reset;
  comm.enable_cmd_fn = spi_comm_enable_cmd;
  comm.disable_cmd_fn = spi_comm_disable_cmd;
  comm.enable_data_fn = spi_comm_enable_data;
  comm.disable_data_fn = spi_comm_disable_data;
  comm.send_byte_fn = spi_comm_send_byte;
  
  return &comm;
}

bool spi_comm_init()
{
	SPI1.Open(0);
	return true;
}
void spi_comm_enable()
{
  IO_CS_SetLow();
}
void spi_comm_disable()
{
  IO_CS_SetHigh();
}
void spi_comm_start_reset()
{
  IO_RES_SetLow();
}
void spi_comm_end_reset()
{
  IO_RES_SetHigh();
}
void spi_comm_enable_cmd()
{
  IO_DC_SetLow();
}
void spi_comm_disable_cmd()
{
}
void spi_comm_enable_data()
{
  IO_DC_SetHigh();
}
void spi_comm_disable_data()
{
}
bool spi_comm_send_byte(uint8_t byte)
{
  	SPI1.ByteExchange(byte);
	return true;
}
