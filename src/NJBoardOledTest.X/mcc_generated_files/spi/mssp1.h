/**
  SPI1 Generated Driver API Header File

  @Company
    Microchip Technology Inc.

  @File Name
    spi1.h

  @Summary
    This is the generated header file for the SPI1 driver.

  @Description
    This header file provides APIs for driver for SPI1.
    Generation Information :
        Driver Version    :  2.0.0
    The generated drivers are tested against the following:
        Compiler          :  XC8 v2.30 and above
        MPLAB             :  MPLABX v5.45 and above
*/

/*
© [2021] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

#ifndef SPI1_H
#define SPI1_H

/**
  Section: Included Files
*/

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "spi_interface.h"

/**
  SPI_INTERFACE object 

  @Summary
    SPI driver interface object.
 */                
extern const struct SPI_INTERFACE SPI1;

/* SPI interfaces */
typedef enum { 
    MSSP1_DEFAULT
} spi1_modes_t;

void SPI1_Initialize(void);
bool SPI1_Open(uint8_t spiConfigIndex);
void SPI1_Close(void);
uint8_t SPI1_ByteExchange(uint8_t byteData);
void SPI1_BufferExchange(void * bufferData, size_t bufferSize);
void SPI1_BufferWrite(void * bufferData, size_t bufferSize);
void SPI1_BufferRead(void * bufferData, size_t bufferSize);
void SPI1_ByteWrite(uint8_t byteData);
uint8_t SPI1_ByteRead(void);

uint8_t __attribute__((deprecated)) SPI1_ExchangeByte(uint8_t data);
void __attribute__((deprecated)) SPI1_ExchangeBlock(void *block, size_t blockSize);
void __attribute__((deprecated)) SPI1_WriteBlock(void *block, size_t blockSize);
void __attribute__((deprecated)) SPI1_ReadBlock(void *block, size_t blockSize);
void __attribute__((deprecated)) SPI1_WriteByte(uint8_t byte);
uint8_t __attribute__((deprecated)) SPI1_ReadByte(void);

#endif //SPI1_H