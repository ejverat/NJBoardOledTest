/* 
 * File:   obus.h
 * Author: evera
 *
 * Created on December 13, 2021, 1:15 AM
 */

#ifndef OBUS_H
#define	OBUS_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <inttypes.h>
#include <stdio.h>
#include "bus.h"

typedef struct 
{
	bus_t bus_type;
	void* bhandler;
} obus_t;

bool obus_write_byte(obus_t* bus, uint8_t byte);
bool obus_write_block(obus_t* bus, uint8_t* block, size_t block_size);


#ifdef	__cplusplus
}
#endif

#endif	/* OBUS_H */

