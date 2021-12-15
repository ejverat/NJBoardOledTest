/* 
 * File:   gdisplay.h
 * Author: evera
 *
 * Created on December 13, 2021, 1:09 AM
 */

#ifndef GDISPLAY_H
#define	GDISPLAY_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct
{
	uint16_t width;
	uint16_t height;
	bool (*init_fn)(void);
	bool (*draw_fn)(uint16_t,uint16_t,uint8_t*,size_t);
	bool (*clear_fn)(void);
} gdisplay_t;

typedef struct 
{
	uint8_t* data;
	size_t size;
} image_t;

bool init_gdisplay(gdisplay_t* gd);
bool draw_gdisplay(gdisplay_t* gd, uint16_t col, uint16_t row, image_t* img);
bool clear_gdisplay(gdisplay_t* gd);


#ifdef	__cplusplus
}
#endif

#endif	/* GDISPLAY_H */

