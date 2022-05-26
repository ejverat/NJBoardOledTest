/* 
 * File:   SSD1322.h
 * Author: evera
 *
 * Created on December 15, 2021, 12:08 AM
 */

#ifndef SSD1322_H
#define	SSD1322_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "gdisplay.h"
#include <stdio.h>

void ssd1322_setup(size_t height, size_t width);
gdisplay_t* ssd1322_get_gd();


#ifdef	__cplusplus
}
#endif

#endif	/* SSD1322_H */

