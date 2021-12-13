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
#include "obus.h"

typedef struct
{
	uint16_t width;
	uint16_t height;
	obus_t* bus;
} gdisplay_t;

bool init_gdisplay(gdisplay_t* gd);


#ifdef	__cplusplus
}
#endif

#endif	/* GDISPLAY_H */

