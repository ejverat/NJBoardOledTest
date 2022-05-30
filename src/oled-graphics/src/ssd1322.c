#include "ssd1322.h"

static ssd1322_t driver;

ssd1322_t* ssd1322_instance()
{
    return &driver;
}

bool ssd1322_send_command(uint8_t* commands, uint16_t size)
{
    driver.set_command_bit_fn(true);
    return true;
}

bool ssd1322_send_data(uint8_t* data, uint16_t size)
{
    driver.set_command_bit_fn(false);
    return true;
}
