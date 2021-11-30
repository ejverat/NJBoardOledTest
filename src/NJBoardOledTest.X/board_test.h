/* 
 * File:   board_test,h.h
 * Author: evera
 *
 * Created on October 28, 2021, 10:23 PM
 */

#ifndef BOARD_TEST_H
#define	BOARD_TEST_H

#include <stdbool.h>
#include <stdint.h>


#ifdef	__cplusplus
extern "C" {
#endif

bool hw_test_i2c(uint8_t address);
bool hw_test_display(uint8_t address);
void hw_test_display_pixel(uint8_t pixel);
void hw_test_display_fill(uint8_t address);
void hw_test_osc();

#ifdef	__cplusplus
}
#endif

#endif	/* BOARD_TEST_H */

