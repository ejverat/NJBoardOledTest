/**
  SPI1 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    spi1.c

  @Summary
    This is the generated driver implementation file for the SPI1 driver.

  @Description
    This source file provides APIs for driver for SPI1.
    Generation Information :
        Driver Version    :  2.0.0
    The generated drivers are tested against the following:
        Compiler          :  XC8 v2.30 and above
        MPLAB             :  MPLABX v5.45 and above
*/

/*
� [2021] Microchip Technology Inc. and its subsidiaries.

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

#include <xc.h>
#include "../mssp1.h"

/**
  SPI1_DRIVER_FUNCTION object 

  @Summary
    Defines an object for SPI_DRIVER_FUNCTIONS.
 */
const struct SPI_INTERFACE SPI1 = {
    .Initialize = SPI1_Initialize,
    .Close = SPI1_Close,
    .Open = SPI1_Open,
    .BufferExchange = SPI1_BufferExchange,
    .BufferRead = SPI1_BufferRead,
    .BufferWrite = SPI1_BufferWrite,	
    .ByteExchange = SPI1_ByteExchange,
    .ByteRead = SPI1_ByteRead,	
    .ByteWrite = SPI1_ByteWrite,
};

typedef struct { 
    uint8_t con1; 
    uint8_t stat;
    uint8_t add;
    uint8_t operation;
} spi1_configuration_t;

//con1 == SSPxCON1, stat == SSPxSTAT, add == SSPxADD, operation == Host/Client
static const spi1_configuration_t spi1_configuration[] = {   
    { 0x10, 0x64, 0x1, 0 }
};

void SPI1_Initialize(void)
{
    //SPI setup
    SSP1STAT = 0x64;
    SSP1CON1 = 0x10;
    SSP1ADD = 0x1;
    TRISCbits.TRISC6 = 0;
    SSP1CON1bits.SSPEN = 0;
}

bool SPI1_Open(uint8_t spiConfigIndex)
{
    if(!SSP1CON1bits.SSPEN)
    {
        SSP1STAT = spi1_configuration[spiConfigIndex].stat;
        SSP1CON1 = spi1_configuration[spiConfigIndex].con1;
        SSP1CON2 = 0x00;
        SSP1ADD  = spi1_configuration[spiConfigIndex].add;
        TRISCbits.TRISC6 = spi1_configuration[spiConfigIndex].operation;
        SSP1CON1bits.SSPEN = 1;
        return true;
    }
    return false;
}

void SPI1_Close(void)
{
    SSP1CON1bits.SSPEN = 0;
}

uint8_t SPI1_ByteExchange(uint8_t data)
{
    SSP1BUF = data;
    while(!PIR3bits.SSP1IF);
    PIR3bits.SSP1IF = 0;
    return SSP1BUF;
}

void SPI1_BufferExchange(void *block, size_t blockSize)
{
    uint8_t *data = block;
    while(blockSize--)
    {
        SSP1BUF = *data;
        while(!PIR3bits.SSP1IF);
        PIR3bits.SSP1IF = 0;
        *data++ = SSP1BUF;
    }
}

// Half Duplex SPI Functions
void SPI1_BufferWrite(void *block, size_t blockSize)
{
    uint8_t *data = block;
    while(blockSize--)
    {
        SPI1_ByteExchange(*data++);
    }
}

void SPI1_BufferRead(void *block, size_t blockSize)
{
    uint8_t *data = block;
    while(blockSize--)
    {
        *data++ = SPI1_ByteExchange(0);
    }
}

void SPI1_ByteWrite(uint8_t byte)
{
    SSP1BUF = byte;
}

uint8_t SPI1_ByteRead(void)
{
    return SSP1BUF;
}

uint8_t SPI1_ExchangeByte(uint8_t data)
{
    return SPI1_ByteExchange(data);
}

void SPI1_ExchangeBlock(void *block, size_t blockSize)
{
    SPI1_BufferExchange(block, blockSize);
}

void SPI1_WriteBlock(void *block, size_t blockSize)
{
    SPI1_BufferWrite(block, blockSize);
}

void SPI1_ReadBlock(void *block, size_t blockSize)
{
    SPI1_BufferRead(block, blockSize);
}

void SPI1_WriteByte(uint8_t byte)
{
    SPI1_ByteWrite(byte);
}

uint8_t SPI1_ReadByte(void)
{
    return SPI1_ByteRead();
}
