/* 
 * File:   disp_i2c_comm.h
 * Author: evera
 *
 * Created on July 2, 2022, 1:10 AM
 */

#ifndef DISP_I2C_COMM_H
#define	DISP_I2C_COMM_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include "display_comm.h"

void i2c_comm_set_address(uint8_t add);
display_comm_t* i2c_comm_instance();
bool i2c_comm_init();
void i2c_comm_enable();
void i2c_comm_disable();
void i2c_comm_start_reset();
void i2c_comm_end_reset();
void i2c_comm_enable_cmd();
void i2c_comm_disable_cmd();
void i2c_comm_enable_data();
void i2c_comm_disable_data();
bool i2c_comm_send_byte(uint8_t byte);


#ifdef	__cplusplus
}
#endif

#endif	/* DISP_I2C_COMM_H */

