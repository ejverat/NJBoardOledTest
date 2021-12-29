/* 
 * File:   SSD1306.h
 * Author: evera
 *
 * Created on December 17, 2021, 4:39 AM
 */

#ifndef SSD1306_H
#define	SSD1306_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "gdisplay.h"
#include <stdio.h>

void ssd1306_setup(uint8_t address, size_t height, size_t width);
gdisplay_t* ssd1306_get_gd();


#ifdef	__cplusplus
}
#endif

#endif	/* SSD1306_H */

