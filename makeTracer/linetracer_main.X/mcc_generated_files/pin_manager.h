/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC16F1778
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.36 and above
        MPLAB 	          :  MPLAB X 6.00	
 */

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
 */

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
 */

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set channel_AN0 aliases
#define channel_AN0_TRIS                 TRISAbits.TRISA0
#define channel_AN0_LAT                  LATAbits.LATA0
#define channel_AN0_PORT                 PORTAbits.RA0
#define channel_AN0_WPU                  WPUAbits.WPUA0
#define channel_AN0_OD                   ODCONAbits.ODA0
#define channel_AN0_ANS                  ANSELAbits.ANSA0
#define channel_AN0_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define channel_AN0_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define channel_AN0_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define channel_AN0_GetValue()           PORTAbits.RA0
#define channel_AN0_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define channel_AN0_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define channel_AN0_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define channel_AN0_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define channel_AN0_SetPushPull()        do { ODCONAbits.ODA0 = 0; } while(0)
#define channel_AN0_SetOpenDrain()       do { ODCONAbits.ODA0 = 1; } while(0)
#define channel_AN0_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define channel_AN0_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set channel_AN1 aliases
#define channel_AN1_TRIS                 TRISAbits.TRISA1
#define channel_AN1_LAT                  LATAbits.LATA1
#define channel_AN1_PORT                 PORTAbits.RA1
#define channel_AN1_WPU                  WPUAbits.WPUA1
#define channel_AN1_OD                   ODCONAbits.ODA1
#define channel_AN1_ANS                  ANSELAbits.ANSA1
#define channel_AN1_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define channel_AN1_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define channel_AN1_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define channel_AN1_GetValue()           PORTAbits.RA1
#define channel_AN1_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define channel_AN1_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define channel_AN1_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define channel_AN1_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define channel_AN1_SetPushPull()        do { ODCONAbits.ODA1 = 0; } while(0)
#define channel_AN1_SetOpenDrain()       do { ODCONAbits.ODA1 = 1; } while(0)
#define channel_AN1_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define channel_AN1_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set SENS_SEL1 aliases
#define SENS_SEL1_TRIS                 TRISAbits.TRISA2
#define SENS_SEL1_LAT                  LATAbits.LATA2
#define SENS_SEL1_PORT                 PORTAbits.RA2
#define SENS_SEL1_WPU                  WPUAbits.WPUA2
#define SENS_SEL1_OD                   ODCONAbits.ODA2
#define SENS_SEL1_ANS                  ANSELAbits.ANSA2
#define SENS_SEL1_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define SENS_SEL1_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define SENS_SEL1_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define SENS_SEL1_GetValue()           PORTAbits.RA2
#define SENS_SEL1_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define SENS_SEL1_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define SENS_SEL1_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define SENS_SEL1_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define SENS_SEL1_SetPushPull()        do { ODCONAbits.ODA2 = 0; } while(0)
#define SENS_SEL1_SetOpenDrain()       do { ODCONAbits.ODA2 = 1; } while(0)
#define SENS_SEL1_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define SENS_SEL1_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set SENS_SEL2 aliases
#define SENS_SEL2_TRIS                 TRISAbits.TRISA3
#define SENS_SEL2_LAT                  LATAbits.LATA3
#define SENS_SEL2_PORT                 PORTAbits.RA3
#define SENS_SEL2_WPU                  WPUAbits.WPUA3
#define SENS_SEL2_OD                   ODCONAbits.ODA3
#define SENS_SEL2_ANS                  ANSELAbits.ANSA3
#define SENS_SEL2_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define SENS_SEL2_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define SENS_SEL2_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define SENS_SEL2_GetValue()           PORTAbits.RA3
#define SENS_SEL2_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define SENS_SEL2_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define SENS_SEL2_SetPullup()          do { WPUAbits.WPUA3 = 1; } while(0)
#define SENS_SEL2_ResetPullup()        do { WPUAbits.WPUA3 = 0; } while(0)
#define SENS_SEL2_SetPushPull()        do { ODCONAbits.ODA3 = 0; } while(0)
#define SENS_SEL2_SetOpenDrain()       do { ODCONAbits.ODA3 = 1; } while(0)
#define SENS_SEL2_SetAnalogMode()      do { ANSELAbits.ANSA3 = 1; } while(0)
#define SENS_SEL2_SetDigitalMode()     do { ANSELAbits.ANSA3 = 0; } while(0)

// get/set SW1 aliases
#define SW1_TRIS                 TRISAbits.TRISA4
#define SW1_LAT                  LATAbits.LATA4
#define SW1_PORT                 PORTAbits.RA4
#define SW1_WPU                  WPUAbits.WPUA4
#define SW1_OD                   ODCONAbits.ODA4
#define SW1_ANS                  ANSELAbits.ANSA4
#define SW1_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define SW1_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define SW1_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define SW1_GetValue()           PORTAbits.RA4
#define SW1_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define SW1_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define SW1_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define SW1_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define SW1_SetPushPull()        do { ODCONAbits.ODA4 = 0; } while(0)
#define SW1_SetOpenDrain()       do { ODCONAbits.ODA4 = 1; } while(0)
#define SW1_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define SW1_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set SW2 aliases
#define SW2_TRIS                 TRISAbits.TRISA5
#define SW2_LAT                  LATAbits.LATA5
#define SW2_PORT                 PORTAbits.RA5
#define SW2_WPU                  WPUAbits.WPUA5
#define SW2_OD                   ODCONAbits.ODA5
#define SW2_ANS                  ANSELAbits.ANSA5
#define SW2_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define SW2_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define SW2_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define SW2_GetValue()           PORTAbits.RA5
#define SW2_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define SW2_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define SW2_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define SW2_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define SW2_SetPushPull()        do { ODCONAbits.ODA5 = 0; } while(0)
#define SW2_SetOpenDrain()       do { ODCONAbits.ODA5 = 1; } while(0)
#define SW2_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define SW2_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set LED_G aliases
#define LED_G_TRIS                 TRISAbits.TRISA6
#define LED_G_LAT                  LATAbits.LATA6
#define LED_G_PORT                 PORTAbits.RA6
#define LED_G_WPU                  WPUAbits.WPUA6
#define LED_G_OD                   ODCONAbits.ODA6
#define LED_G_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define LED_G_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define LED_G_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define LED_G_GetValue()           PORTAbits.RA6
#define LED_G_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define LED_G_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)
#define LED_G_SetPullup()          do { WPUAbits.WPUA6 = 1; } while(0)
#define LED_G_ResetPullup()        do { WPUAbits.WPUA6 = 0; } while(0)
#define LED_G_SetPushPull()        do { ODCONAbits.ODA6 = 0; } while(0)
#define LED_G_SetOpenDrain()       do { ODCONAbits.ODA6 = 1; } while(0)

// get/set BUZZ aliases
#define BUZZ_TRIS                 TRISAbits.TRISA7
#define BUZZ_LAT                  LATAbits.LATA7
#define BUZZ_PORT                 PORTAbits.RA7
#define BUZZ_WPU                  WPUAbits.WPUA7
#define BUZZ_OD                   ODCONAbits.ODA7
#define BUZZ_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define BUZZ_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define BUZZ_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define BUZZ_GetValue()           PORTAbits.RA7
#define BUZZ_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define BUZZ_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)
#define BUZZ_SetPullup()          do { WPUAbits.WPUA7 = 1; } while(0)
#define BUZZ_ResetPullup()        do { WPUAbits.WPUA7 = 0; } while(0)
#define BUZZ_SetPushPull()        do { ODCONAbits.ODA7 = 0; } while(0)
#define BUZZ_SetOpenDrain()       do { ODCONAbits.ODA7 = 1; } while(0)

// get/set RB0 procedures
#define RB0_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define RB0_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define RB0_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define RB0_GetValue()              PORTBbits.RB0
#define RB0_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define RB0_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define RB0_SetPullup()             do { WPUBbits.WPUB0 = 1; } while(0)
#define RB0_ResetPullup()           do { WPUBbits.WPUB0 = 0; } while(0)
#define RB0_SetAnalogMode()         do { ANSELBbits.ANSB0 = 1; } while(0)
#define RB0_SetDigitalMode()        do { ANSELBbits.ANSB0 = 0; } while(0)

// get/set LED_SREG_DAT aliases
#define LED_SREG_DAT_TRIS                 TRISBbits.TRISB1
#define LED_SREG_DAT_LAT                  LATBbits.LATB1
#define LED_SREG_DAT_PORT                 PORTBbits.RB1
#define LED_SREG_DAT_WPU                  WPUBbits.WPUB1
#define LED_SREG_DAT_ANS                  ANSELBbits.ANSB1
#define LED_SREG_DAT_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define LED_SREG_DAT_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define LED_SREG_DAT_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define LED_SREG_DAT_GetValue()           PORTBbits.RB1
#define LED_SREG_DAT_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define LED_SREG_DAT_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define LED_SREG_DAT_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define LED_SREG_DAT_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define LED_SREG_DAT_SetAnalogMode()      do { ANSELBbits.ANSB1 = 1; } while(0)
#define LED_SREG_DAT_SetDigitalMode()     do { ANSELBbits.ANSB1 = 0; } while(0)

// get/set LED_SREG_CLK aliases
#define LED_SREG_CLK_TRIS                 TRISBbits.TRISB2
#define LED_SREG_CLK_LAT                  LATBbits.LATB2
#define LED_SREG_CLK_PORT                 PORTBbits.RB2
#define LED_SREG_CLK_WPU                  WPUBbits.WPUB2
#define LED_SREG_CLK_ANS                  ANSELBbits.ANSB2
#define LED_SREG_CLK_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define LED_SREG_CLK_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define LED_SREG_CLK_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define LED_SREG_CLK_GetValue()           PORTBbits.RB2
#define LED_SREG_CLK_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define LED_SREG_CLK_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define LED_SREG_CLK_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define LED_SREG_CLK_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define LED_SREG_CLK_SetAnalogMode()      do { ANSELBbits.ANSB2 = 1; } while(0)
#define LED_SREG_CLK_SetDigitalMode()     do { ANSELBbits.ANSB2 = 0; } while(0)

// get/set LED_SREG_SEND aliases
#define LED_SREG_SEND_TRIS                 TRISBbits.TRISB3
#define LED_SREG_SEND_LAT                  LATBbits.LATB3
#define LED_SREG_SEND_PORT                 PORTBbits.RB3
#define LED_SREG_SEND_WPU                  WPUBbits.WPUB3
#define LED_SREG_SEND_ANS                  ANSELBbits.ANSB3
#define LED_SREG_SEND_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define LED_SREG_SEND_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define LED_SREG_SEND_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define LED_SREG_SEND_GetValue()           PORTBbits.RB3
#define LED_SREG_SEND_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define LED_SREG_SEND_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define LED_SREG_SEND_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define LED_SREG_SEND_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define LED_SREG_SEND_SetAnalogMode()      do { ANSELBbits.ANSB3 = 1; } while(0)
#define LED_SREG_SEND_SetDigitalMode()     do { ANSELBbits.ANSB3 = 0; } while(0)

// get/set LED_COLSEL1 aliases
#define LED_COLSEL1_TRIS                 TRISBbits.TRISB4
#define LED_COLSEL1_LAT                  LATBbits.LATB4
#define LED_COLSEL1_PORT                 PORTBbits.RB4
#define LED_COLSEL1_WPU                  WPUBbits.WPUB4
#define LED_COLSEL1_OD                   ODCONBbits.ODB4
#define LED_COLSEL1_ANS                  ANSELBbits.ANSB4
#define LED_COLSEL1_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define LED_COLSEL1_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define LED_COLSEL1_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define LED_COLSEL1_GetValue()           PORTBbits.RB4
#define LED_COLSEL1_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define LED_COLSEL1_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define LED_COLSEL1_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define LED_COLSEL1_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define LED_COLSEL1_SetPushPull()        do { ODCONBbits.ODB4 = 0; } while(0)
#define LED_COLSEL1_SetOpenDrain()       do { ODCONBbits.ODB4 = 1; } while(0)
#define LED_COLSEL1_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define LED_COLSEL1_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set LED_COLSEL2 aliases
#define LED_COLSEL2_TRIS                 TRISBbits.TRISB5
#define LED_COLSEL2_LAT                  LATBbits.LATB5
#define LED_COLSEL2_PORT                 PORTBbits.RB5
#define LED_COLSEL2_WPU                  WPUBbits.WPUB5
#define LED_COLSEL2_OD                   ODCONBbits.ODB5
#define LED_COLSEL2_ANS                  ANSELBbits.ANSB5
#define LED_COLSEL2_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define LED_COLSEL2_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define LED_COLSEL2_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define LED_COLSEL2_GetValue()           PORTBbits.RB5
#define LED_COLSEL2_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define LED_COLSEL2_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define LED_COLSEL2_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define LED_COLSEL2_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define LED_COLSEL2_SetPushPull()        do { ODCONBbits.ODB5 = 0; } while(0)
#define LED_COLSEL2_SetOpenDrain()       do { ODCONBbits.ODB5 = 1; } while(0)
#define LED_COLSEL2_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define LED_COLSEL2_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set RB7 procedures
#define RB7_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define RB7_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define RB7_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define RB7_GetValue()              PORTBbits.RB7
#define RB7_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define RB7_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define RB7_SetPullup()             do { WPUBbits.WPUB7 = 1; } while(0)
#define RB7_ResetPullup()           do { WPUBbits.WPUB7 = 0; } while(0)

// get/set LED_R aliases
#define LED_R_TRIS                 TRISCbits.TRISC0
#define LED_R_LAT                  LATCbits.LATC0
#define LED_R_PORT                 PORTCbits.RC0
#define LED_R_WPU                  WPUCbits.WPUC0
#define LED_R_OD                   ODCONCbits.ODC0
#define LED_R_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define LED_R_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define LED_R_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define LED_R_GetValue()           PORTCbits.RC0
#define LED_R_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define LED_R_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define LED_R_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define LED_R_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define LED_R_SetPushPull()        do { ODCONCbits.ODC0 = 0; } while(0)
#define LED_R_SetOpenDrain()       do { ODCONCbits.ODC0 = 1; } while(0)

// get/set RC1 procedures
#define RC1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define RC1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define RC1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define RC1_GetValue()              PORTCbits.RC1
#define RC1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define RC1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define RC1_SetPullup()             do { WPUCbits.WPUC1 = 1; } while(0)
#define RC1_ResetPullup()           do { WPUCbits.WPUC1 = 0; } while(0)

// get/set L_SEL1 aliases
#define L_SEL1_TRIS                 TRISCbits.TRISC2
#define L_SEL1_LAT                  LATCbits.LATC2
#define L_SEL1_PORT                 PORTCbits.RC2
#define L_SEL1_WPU                  WPUCbits.WPUC2
#define L_SEL1_OD                   ODCONCbits.ODC2
#define L_SEL1_ANS                  ANSELCbits.ANSC2
#define L_SEL1_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define L_SEL1_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define L_SEL1_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define L_SEL1_GetValue()           PORTCbits.RC2
#define L_SEL1_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define L_SEL1_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define L_SEL1_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define L_SEL1_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define L_SEL1_SetPushPull()        do { ODCONCbits.ODC2 = 0; } while(0)
#define L_SEL1_SetOpenDrain()       do { ODCONCbits.ODC2 = 1; } while(0)
#define L_SEL1_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define L_SEL1_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set L_SEL2 aliases
#define L_SEL2_TRIS                 TRISCbits.TRISC3
#define L_SEL2_LAT                  LATCbits.LATC3
#define L_SEL2_PORT                 PORTCbits.RC3
#define L_SEL2_WPU                  WPUCbits.WPUC3
#define L_SEL2_OD                   ODCONCbits.ODC3
#define L_SEL2_ANS                  ANSELCbits.ANSC3
#define L_SEL2_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define L_SEL2_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define L_SEL2_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define L_SEL2_GetValue()           PORTCbits.RC3
#define L_SEL2_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define L_SEL2_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define L_SEL2_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define L_SEL2_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define L_SEL2_SetPushPull()        do { ODCONCbits.ODC3 = 0; } while(0)
#define L_SEL2_SetOpenDrain()       do { ODCONCbits.ODC3 = 1; } while(0)
#define L_SEL2_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define L_SEL2_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set R_SEL2 aliases
#define R_SEL2_TRIS                 TRISCbits.TRISC4
#define R_SEL2_LAT                  LATCbits.LATC4
#define R_SEL2_PORT                 PORTCbits.RC4
#define R_SEL2_WPU                  WPUCbits.WPUC4
#define R_SEL2_OD                   ODCONCbits.ODC4
#define R_SEL2_ANS                  ANSELCbits.ANSC4
#define R_SEL2_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define R_SEL2_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define R_SEL2_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define R_SEL2_GetValue()           PORTCbits.RC4
#define R_SEL2_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define R_SEL2_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define R_SEL2_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define R_SEL2_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define R_SEL2_SetPushPull()        do { ODCONCbits.ODC4 = 0; } while(0)
#define R_SEL2_SetOpenDrain()       do { ODCONCbits.ODC4 = 1; } while(0)
#define R_SEL2_SetAnalogMode()      do { ANSELCbits.ANSC4 = 1; } while(0)
#define R_SEL2_SetDigitalMode()     do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set R_SEL1 aliases
#define R_SEL1_TRIS                 TRISCbits.TRISC5
#define R_SEL1_LAT                  LATCbits.LATC5
#define R_SEL1_PORT                 PORTCbits.RC5
#define R_SEL1_WPU                  WPUCbits.WPUC5
#define R_SEL1_OD                   ODCONCbits.ODC5
#define R_SEL1_ANS                  ANSELCbits.ANSC5
#define R_SEL1_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define R_SEL1_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define R_SEL1_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define R_SEL1_GetValue()           PORTCbits.RC5
#define R_SEL1_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define R_SEL1_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define R_SEL1_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define R_SEL1_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define R_SEL1_SetPushPull()        do { ODCONCbits.ODC5 = 0; } while(0)
#define R_SEL1_SetOpenDrain()       do { ODCONCbits.ODC5 = 1; } while(0)
#define R_SEL1_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define R_SEL1_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)

// get/set RC6 procedures
#define RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RC6_GetValue()              PORTCbits.RC6
#define RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define RC6_SetPullup()             do { WPUCbits.WPUC6 = 1; } while(0)
#define RC6_ResetPullup()           do { WPUCbits.WPUC6 = 0; } while(0)
#define RC6_SetAnalogMode()         do { ANSELCbits.ANSC6 = 1; } while(0)
#define RC6_SetDigitalMode()        do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set RC7 procedures
#define RC7_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define RC7_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define RC7_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define RC7_GetValue()              PORTCbits.RC7
#define RC7_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define RC7_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define RC7_SetPullup()             do { WPUCbits.WPUC7 = 1; } while(0)
#define RC7_ResetPullup()           do { WPUCbits.WPUC7 = 0; } while(0)
#define RC7_SetAnalogMode()         do { ANSELCbits.ANSC7 = 1; } while(0)
#define RC7_SetDigitalMode()        do { ANSELCbits.ANSC7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize(void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCAF4 pin functionality
 * @Example
    IOCAF4_ISR();
 */
void IOCAF4_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCAF4 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCAF4 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF4_SetInterruptHandler(MyInterruptHandler);

 */
void IOCAF4_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCAF4 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCAF4_SetInterruptHandler() method.
    This handler is called every time the IOCAF4 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF4_SetInterruptHandler(IOCAF4_InterruptHandler);

 */
extern void (*IOCAF4_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCAF4 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCAF4_SetInterruptHandler() method.
    This handler is called every time the IOCAF4 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF4_SetInterruptHandler(IOCAF4_DefaultInterruptHandler);

 */
void IOCAF4_DefaultInterruptHandler(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCAF5 pin functionality
 * @Example
    IOCAF5_ISR();
 */
void IOCAF5_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCAF5 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCAF5 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF5_SetInterruptHandler(MyInterruptHandler);

 */
void IOCAF5_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCAF5 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCAF5_SetInterruptHandler() method.
    This handler is called every time the IOCAF5 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF5_SetInterruptHandler(IOCAF5_InterruptHandler);

 */
extern void (*IOCAF5_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCAF5 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCAF5_SetInterruptHandler() method.
    This handler is called every time the IOCAF5 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF5_SetInterruptHandler(IOCAF5_DefaultInterruptHandler);

 */
void IOCAF5_DefaultInterruptHandler(void);



#endif // PIN_MANAGER_H
/**
 End of File
 */