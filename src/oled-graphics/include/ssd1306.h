#ifndef SSD1306_H
#define SSD1306_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stdint.h>
#include "ssd1306_def.h"
#include "gdisplay_driver.h"

void ssd1306_setup(gdisplay_driver_t* driver, display_comm_t* comm, waiter_t* timer);
bool ssd1306_init();
bool ssd1306_send_cmd(uint8_t cmd, uint8_t* params);
bool ssd1306_send_data(uint8_t* data, uint16_t size);

#ifdef	__cplusplus
}
#endif

#endif // SSD1306_H
