#include "ssd1306.h"
#include "gdisplay_driver.h"
#include "ssd1306_def.h"
#include "ssd1306_cmd.h"

static display_comm_t* ssd1306_comm;
static waiter_t* ssd1306_timer;
static uint8_t params[6];

void ssd1306_setup(gdisplay_driver_t* driver, display_comm_t* comm, waiter_t* timer)
{
    driver->init_fn = ssd1306_init;
    driver->send_cmd_fn = ssd1306_send_cmd;
    driver->send_data_fn = ssd1306_send_data;
    driver->comm = comm;
    driver->timer = timer;
    ssd1306_comm = comm;
    ssd1306_timer = timer;
}

bool ssd1306_init()
{
    ssd1306_timer->wait_ms(100);
    if (!ssd1306_comm->init_fn())
        return false;

    ssd1306_comm->enable_fn();

    ssd1306_send_cmd(SSD1306_CMD_DISPLAYOFF, params);				//
    params[0] = 0x81;
    ssd1306_send_cmd(SSD1306_CMD_SETDISPLAYCLOCKDIV, params);	//
    params[0] = 0x7f;
    ssd1306_send_cmd(SSD1306_CMD_SETCONTRAST, params);		//
    params[0] = 0x00;
    ssd1306_send_cmd(SSD1306_CMD_MEMORYMODE, params);		//
    ssd1306_send_cmd(SSD1306_CMD_SETSTARTLINE | 0, params);	//
    params[0] = 63;
    ssd1306_send_cmd(SSD1306_CMD_SETMULTIPLEX, params);		//
    params[0] = 0x02;
    ssd1306_send_cmd(SSD1306_CMD_SETCOMPINS, params);		//
    ssd1306_send_cmd(SSD1306_CMD_SEGREMAP0, params);	//
                            //
                            //
    ssd1306_send_cmd(SSD1306_CMD_COMSCANINC, params);		//
    ssd1306_send_cmd(SSD1306_CMD_NORMALDISPLAY, params);	//
    ssd1306_send_cmd(SSD1306_CMD_DEACTIVATESCROLL, params);	//
    params[0] = 0x2;
    ssd1306_send_cmd(SSD1306_CMD_SETPRECHARGE, params);		//
                            //
                            //
    params[0] = 0x14;
    ssd1306_send_cmd(SSD1306_CMD_CHARGEPUMP, params);		//
    ssd1306_send_cmd(SSD1306_CMD_DISPLAYON, params);	//
    ssd1306_comm->disable_fn();

    return true;
}

bool ssd1306_send_cmd(uint8_t cmd, uint8_t* params)
{
    ssd1306_comm->enable_cmd_fn();
    if (!ssd1306_comm->send_byte_fn(cmd))
        return false;
    uint8_t num_params = ssd1306_cmd_num_params((ssd1306_cmd_t)cmd);
    uint8_t p_idx;
    for (p_idx = 0; p_idx < num_params; p_idx++)
    {
        uint8_t param = params[p_idx];
        ssd1306_param_mask((ssd1306_cmd_t)cmd,p_idx,&param);
        if (!ssd1306_comm->send_byte_fn(param))
            return false;
    }
    return true;
}

bool ssd1306_send_data(uint8_t* data, uint16_t size)
{
    ssd1306_comm->enable_data_fn();

    uint8_t p_idx;
    for (p_idx = 0; p_idx < size; p_idx++)
    {
        if (!ssd1306_comm->send_byte_fn(data[p_idx]))
            return false;
    }

    return true;
}
