/* 
 * File:   ssd1306_i2c.h
 * Author: evera
 *
 * Created on December 17, 2021, 4:39 AM
 */

#ifndef SSD1306_I2C_H
#define	SSD1306_I2C_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <inttypes.h>
#include <stdbool.h>

void ssd1306_i2c_set_address(uint8_t address);
void ssd1306_i2c_reset_buffer();
void ssd1306_i2c_add_byte(uint8_t byte);
bool ssd1306_i2c_send();

#ifdef	__cplusplus
}
#endif

#endif	/* SSD1306_I2C_H */

