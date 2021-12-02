/**
 * Generated Pins header File
 * 
 * @file pins.h
 * 
 * @defgroup  pinsdriver Pins Driver
 * 
 * @brief This is generated driver header for pins. 
 *        This header file provides APIs for all pins selected in the GUI.
 *
 * @version Driver Version  3.0.0
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

#ifndef PINS_H
#define PINS_H

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set IO_RA4 aliases
#define OUT1_TRIS                 TRISAbits.TRISA4
#define OUT1_LAT                  LATAbits.LATA4
#define OUT1_PORT                 PORTAbits.RA4
#define OUT1_WPU                  WPUAbits.WPUA4
#define OUT1_OD                   ODCONAbits.ODCA4
#define OUT1_ANS                  ANSELAbits.ANSA4
#define OUT1_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define OUT1_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define OUT1_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define OUT1_GetValue()           PORTAbits.RA4
#define OUT1_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define OUT1_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define OUT1_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define OUT1_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define OUT1_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define OUT1_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define OUT1_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define OUT1_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set IO_RB1 aliases
#define IO_RB1_TRIS                 TRISBbits.TRISB1
#define IO_RB1_LAT                  LATBbits.LATB1
#define IO_RB1_PORT                 PORTBbits.RB1
#define IO_RB1_WPU                  WPUBbits.WPUB1
#define IO_RB1_OD                   ODCONBbits.ODCB1
#define IO_RB1_ANS                  ANSELBbits.ANSB1
#define IO_RB1_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define IO_RB1_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define IO_RB1_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define IO_RB1_GetValue()           PORTBbits.RB1
#define IO_RB1_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define IO_RB1_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define IO_RB1_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define IO_RB1_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define IO_RB1_SetPushPull()        do { ODCONBbits.ODCB1 = 0; } while(0)
#define IO_RB1_SetOpenDrain()       do { ODCONBbits.ODCB1 = 1; } while(0)
#define IO_RB1_SetAnalogMode()      do { ANSELBbits.ANSB1 = 1; } while(0)
#define IO_RB1_SetDigitalMode()     do { ANSELBbits.ANSB1 = 0; } while(0)

// get/set IO_RB2 aliases
#define IO_RB2_TRIS                 TRISBbits.TRISB2
#define IO_RB2_LAT                  LATBbits.LATB2
#define IO_RB2_PORT                 PORTBbits.RB2
#define IO_RB2_WPU                  WPUBbits.WPUB2
#define IO_RB2_OD                   ODCONBbits.ODCB2
#define IO_RB2_ANS                  ANSELBbits.ANSB2
#define IO_RB2_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define IO_RB2_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define IO_RB2_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define IO_RB2_GetValue()           PORTBbits.RB2
#define IO_RB2_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define IO_RB2_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define IO_RB2_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define IO_RB2_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define IO_RB2_SetPushPull()        do { ODCONBbits.ODCB2 = 0; } while(0)
#define IO_RB2_SetOpenDrain()       do { ODCONBbits.ODCB2 = 1; } while(0)
#define IO_RB2_SetAnalogMode()      do { ANSELBbits.ANSB2 = 1; } while(0)
#define IO_RB2_SetDigitalMode()     do { ANSELBbits.ANSB2 = 0; } while(0)

// get/set IO_RC1 aliases
#define IO_RC1_TRIS                 TRISCbits.TRISC1
#define IO_RC1_LAT                  LATCbits.LATC1
#define IO_RC1_PORT                 PORTCbits.RC1
#define IO_RC1_WPU                  WPUCbits.WPUC1
#define IO_RC1_OD                   ODCONCbits.ODCC1
#define IO_RC1_ANS                  ANSELCbits.ANSC1
#define IO_RC1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define IO_RC1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define IO_RC1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define IO_RC1_GetValue()           PORTCbits.RC1
#define IO_RC1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define IO_RC1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define IO_RC1_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define IO_RC1_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define IO_RC1_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define IO_RC1_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define IO_RC1_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define IO_RC1_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set IO_RC2 aliases
#define IO_RC2_TRIS                 TRISCbits.TRISC2
#define IO_RC2_LAT                  LATCbits.LATC2
#define IO_RC2_PORT                 PORTCbits.RC2
#define IO_RC2_WPU                  WPUCbits.WPUC2
#define IO_RC2_OD                   ODCONCbits.ODCC2
#define IO_RC2_ANS                  ANSELCbits.ANSC2
#define IO_RC2_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define IO_RC2_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define IO_RC2_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define IO_RC2_GetValue()           PORTCbits.RC2
#define IO_RC2_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define IO_RC2_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define IO_RC2_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define IO_RC2_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define IO_RC2_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define IO_RC2_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define IO_RC2_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define IO_RC2_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set IO_RC4 aliases
#define IO_RC4_TRIS                 TRISCbits.TRISC4
#define IO_RC4_LAT                  LATCbits.LATC4
#define IO_RC4_PORT                 PORTCbits.RC4
#define IO_RC4_WPU                  WPUCbits.WPUC4
#define IO_RC4_OD                   ODCONCbits.ODCC4
#define IO_RC4_ANS                  ANSELCbits.ANSC4
#define IO_RC4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define IO_RC4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define IO_RC4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define IO_RC4_GetValue()           PORTCbits.RC4
#define IO_RC4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define IO_RC4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define IO_RC4_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define IO_RC4_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define IO_RC4_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define IO_RC4_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define IO_RC4_SetAnalogMode()      do { ANSELCbits.ANSC4 = 1; } while(0)
#define IO_RC4_SetDigitalMode()     do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set IO_RD0 aliases
#define IO_CS_TRIS                 TRISDbits.TRISD0
#define IO_CS_LAT                  LATDbits.LATD0
#define IO_CS_PORT                 PORTDbits.RD0
#define IO_CS_WPU                  WPUDbits.WPUD0
#define IO_CS_OD                   ODCONDbits.ODCD0
#define IO_CS_ANS                  ANSELDbits.ANSD0
#define IO_CS_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define IO_CS_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define IO_CS_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define IO_CS_GetValue()           PORTDbits.RD0
#define IO_CS_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define IO_CS_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)
#define IO_CS_SetPullup()          do { WPUDbits.WPUD0 = 1; } while(0)
#define IO_CS_ResetPullup()        do { WPUDbits.WPUD0 = 0; } while(0)
#define IO_CS_SetPushPull()        do { ODCONDbits.ODCD0 = 0; } while(0)
#define IO_CS_SetOpenDrain()       do { ODCONDbits.ODCD0 = 1; } while(0)
#define IO_CS_SetAnalogMode()      do { ANSELDbits.ANSD0 = 1; } while(0)
#define IO_CS_SetDigitalMode()     do { ANSELDbits.ANSD0 = 0; } while(0)

// get/set IO_RD1 aliases
#define IO_RES_TRIS                 TRISDbits.TRISD1
#define IO_RES_LAT                  LATDbits.LATD1
#define IO_RES_PORT                 PORTDbits.RD1
#define IO_RES_WPU                  WPUDbits.WPUD1
#define IO_RES_OD                   ODCONDbits.ODCD1
#define IO_RES_ANS                  ANSELDbits.ANSD1
#define IO_RES_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define IO_RES_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define IO_RES_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define IO_RES_GetValue()           PORTDbits.RD1
#define IO_RES_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define IO_RES_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)
#define IO_RES_SetPullup()          do { WPUDbits.WPUD1 = 1; } while(0)
#define IO_RES_ResetPullup()        do { WPUDbits.WPUD1 = 0; } while(0)
#define IO_RES_SetPushPull()        do { ODCONDbits.ODCD1 = 0; } while(0)
#define IO_RES_SetOpenDrain()       do { ODCONDbits.ODCD1 = 1; } while(0)
#define IO_RES_SetAnalogMode()      do { ANSELDbits.ANSD1 = 1; } while(0)
#define IO_RES_SetDigitalMode()     do { ANSELDbits.ANSD1 = 0; } while(0)

// get/set IO_RD2 aliases
#define IO_DC_TRIS                 TRISDbits.TRISD2
#define IO_DC_LAT                  LATDbits.LATD2
#define IO_DC_PORT                 PORTDbits.RD2
#define IO_DC_WPU                  WPUDbits.WPUD2
#define IO_DC_OD                   ODCONDbits.ODCD2
#define IO_DC_ANS                  ANSELDbits.ANSD2
#define IO_DC_SetHigh()            do { LATDbits.LATD2 = 1; } while(0)
#define IO_DC_SetLow()             do { LATDbits.LATD2 = 0; } while(0)
#define IO_DC_Toggle()             do { LATDbits.LATD2 = ~LATDbits.LATD2; } while(0)
#define IO_DC_GetValue()           PORTDbits.RD2
#define IO_DC_SetDigitalInput()    do { TRISDbits.TRISD2 = 1; } while(0)
#define IO_DC_SetDigitalOutput()   do { TRISDbits.TRISD2 = 0; } while(0)
#define IO_DC_SetPullup()          do { WPUDbits.WPUD2 = 1; } while(0)
#define IO_DC_ResetPullup()        do { WPUDbits.WPUD2 = 0; } while(0)
#define IO_DC_SetPushPull()        do { ODCONDbits.ODCD2 = 0; } while(0)
#define IO_DC_SetOpenDrain()       do { ODCONDbits.ODCD2 = 1; } while(0)
#define IO_DC_SetAnalogMode()      do { ANSELDbits.ANSD2 = 1; } while(0)
#define IO_DC_SetDigitalMode()     do { ANSELDbits.ANSD2 = 0; } while(0)

/**
 * @ingroup  pinsdriver
 * @brief GPIO and peripheral I/O initialization
 * @param none
 * @return none
 */
void PIN_MANAGER_Initialize (void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt on Change Handling routine
 * @param none
 * @return none
 */
void PIN_MANAGER_IOC(void);


#endif // PINS_H
/**
 End of File
*/