/* 
 * File:   ssd1322_spi.h
 * Author: evera
 *
 * Created on December 15, 2021, 12:15 AM
 */

#ifndef SSD1322_SPI_H
#define	SSD1322_SPI_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <inttypes.h>

bool ssd1322_spi_init();
void ssd1322_enabled(bool enabled);
void ssd1322_set_cmd(bool cmd);
void ssd1322_reset(bool rst);
bool ssd1322_write_byte(uint8_t byte);



#ifdef	__cplusplus
}
#endif

#endif	/* SSD1322_SPI_H */

