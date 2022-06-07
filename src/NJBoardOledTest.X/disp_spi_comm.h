/* 
 * File:   disp_spi_comm.h
 * Author: evera
 *
 * Created on June 3, 2022, 5:35 AM
 */

#ifndef DISP_SPI_COMM_H
#define	DISP_SPI_COMM_H

#ifdef	__cplusplus
extern "C" {
#endif
#include <stdint.h>
#include <stdbool.h>
#include "display_comm.h"

display_comm_t* spi_comm_instance();
bool spi_comm_init();
void spi_comm_enable();
void spi_comm_disable();
void spi_comm_start_reset();
void spi_comm_end_reset();
void spi_comm_enable_cmd();
void spi_comm_disable_cmd();
void spi_comm_enable_data();
void spi_comm_disable_data();
bool spi_comm_send_byte(uint8_t byte);




#ifdef	__cplusplus
}
#endif

#endif	/* DISP_SPI_COMM_H */

