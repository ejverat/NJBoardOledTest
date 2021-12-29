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
#include <stdio.h>


#ifdef	__cplusplus
extern "C" {
#endif

void hw_test_display_ssd1306(uint8_t address, size_t width, size_t height);
void hw_test_display_ssd1322(size_t height, size_t width);
void hw_test_osc();

#ifdef	__cplusplus
}
#endif

#endif	/* BOARD_TEST_H */

