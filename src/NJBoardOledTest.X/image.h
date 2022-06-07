/* 
 * File:   image.h
 * Author: evera
 *
 * Created on June 2, 2022, 12:29 AM
 */

#ifndef IMAGE_H
#define	IMAGE_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdint.h>

	typedef struct
	{
		uint16_t width;
		uint16_t height;
		const uint8_t* array;
		uint8_t pixels_per_byte;
	}image_t;


#ifdef	__cplusplus
}
#endif

#endif	/* IMAGE_H */

