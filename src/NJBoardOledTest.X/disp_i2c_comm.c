#include "disp_i2c_comm.h"
#include "queue.h"
#include "ssd1306_def.h"
#include "mcc_generated_files/i2c_host/mssp2.h"
#include "mcc_generated_files/timer/delay.h"

static queue_t q;
static uint8_t q_buffer[128*8+1];
static display_comm_t comm;
static uint8_t i2c_add;

void i2c_comm_set_address(uint8_t add)
{
	i2c_add = add;
}

display_comm_t* i2c_comm_instance()
{
	comm.init_fn = i2c_comm_init;
	comm.enable_fn = i2c_comm_enable;
	comm.disable_fn = i2c_comm_disable;
	comm.start_reset_fn = i2c_comm_start_reset;
	comm.end_reset_fn = i2c_comm_end_reset;
	comm.enable_cmd_fn = i2c_comm_enable_cmd;
	comm.disable_cmd_fn = i2c_comm_disable_cmd;
	comm.enable_data_fn = i2c_comm_enable_data;
	comm.disable_data_fn = i2c_comm_disable_data;
	comm.send_byte_fn = i2c_comm_send_byte;
	return &comm;
}

bool i2c_comm_init()
{
	return queue_init(&q,sizeof(uint8_t),q_buffer,sizeof(q_buffer));
}

void i2c_comm_enable()
{
	uint8_t dummy;
	while(!queue_is_empty(&q))
	{
		queue_dequeue(&q,&dummy);
	}
}

void i2c_comm_disable()
{
	uint8_t element;

	while(!queue_is_empty(&q))
	{
		queue_dequeue(&q,&element);
	}
}
void i2c_comm_start_reset()
{}
void i2c_comm_end_reset()
{}
void i2c_comm_enable_cmd()
{
	if (queue_is_empty(&q))
	{
		uint8_t cmd_byte = SSD1306_STREAM_MSK | SSD1306_CMD_MSK;
		queue_enqueue(&q,&cmd_byte);
	}
}
void i2c_comm_disable_cmd()
{
	if(i2c2_host_interface.Write(i2c_add,q_buffer,(size_t)(q.index*q.element_size)))
	{
		DELAY_milliseconds(10);
		if(i2c2_host_interface.IsBusy())
		{
			return;
		}
		if(i2c2_host_interface.ErrorGet() == I2C_ERROR_NONE)
		{
			return;
		}
	}
}
void i2c_comm_enable_data()
{
	if (queue_is_empty(&q))
	{
		uint8_t cmd_byte = SSD1306_STREAM_MSK | SSD1306_DATA_MSK;
		queue_enqueue(&q,&cmd_byte);
	}
}
void i2c_comm_disable_data()
{
	if(i2c2_host_interface.Write(i2c_add,q_buffer,(size_t)(q.index*q.element_size)))
	{
		DELAY_milliseconds(10);
		if(i2c2_host_interface.IsBusy())
		{
			return;
		}
		if(i2c2_host_interface.ErrorGet() == I2C_ERROR_NONE)
		{
			return;
		}
	}
}
bool i2c_comm_send_byte(uint8_t byte)
{
		return queue_enqueue(&q,&byte);
}
