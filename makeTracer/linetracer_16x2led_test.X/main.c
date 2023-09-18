/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC16F1778
        Driver Version    :  2.00
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

#include "mcc_generated_files/mcc.h"

/*
                         Main application
 */

bool SWflag = false;
uint16_t pwmr = 1023, pwml = 1023;

void front(void){
    SELR2_SetLow();
    SELR1_SetHigh();
    SELL2_SetLow();
    SELL1_SetHigh();
    
    return;
}

void frontR(void){
    front();
    PWM3_LoadDutyValue(1023);
    PWM4_LoadDutyValue(1023);
    
    SELR2_SetLow();
    SELR1_SetLow();
    SELL2_SetLow();
    SELL1_SetHigh();
    
    return;
}

void frontL(void){
    front();
    PWM3_LoadDutyValue(1023);
    PWM4_LoadDutyValue(1023);
    
    SELR2_SetLow();
    SELR1_SetHigh();
    SELL2_SetLow();
    SELL1_SetLow();
    
    return;
}

void stop(void){
    SELR2_SetLow();
    SELR1_SetLow();
    SELL2_SetLow();
    SELL1_SetLow();
    
    return;
}

void breaks(void){
    SELR2_SetHigh();
    SELR1_SetHigh();
    SELL2_SetHigh();
    SELL1_SetHigh();
    
    return;
}

void buzz(){
    for (uint8_t tone_n = 0; tone_n < 50; tone_n++){
        BUZZ_SetHigh();
        __delay_us(500);
        BUZZ_SetLow();
        __delay_us(500);
    }
}

void readSW(void (*function)()){
    if (SW_GetValue == 0 && !SWflag){
        function;
        SWflag = true;
        __delay_ms(50);
        break;
    }else if (SW_GetValue() == 1){
        SWflag = false;
    }
}

void waitStart(void){
    while(1){
        if (SW_GetValue() == 0 && !SWflag){
            buzz();
            SWflag = true;
            __delay_ms(100);
            break;
        }else if(SW_GetValue() == 1){
            SWflag = false;
        }
    }
}

void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

    while (1)
    {
        waitStart();
    }
}
/**
 End of File
*/