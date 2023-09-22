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

#include "16x2led.h"
#include "buzzer.h"
#include "switchHandler.h"
#include "sensor.h"

/*
                         Main application
 */

uint16_t data = 0b1;

//void segmentGo(void) {
//    LED_G_PORT = 0;
//    LED_R_PORT = 1;
//    tone(1000);
//    bool head = data & 0x8000;
//    data <<= 1;
//    data |= head;
//    noTone();
//    return;
//}
//
//void segmentCFlip(void) {
//    LED_R_PORT = 0;
//    LED_G_PORT = 1;
//    tone(2000);
//    ledSwapColor();
//    noTone();
//    return;
//}
//
//// for Menu variables
//bool isTrace = false;
//uint16_t ledAsobi;
//bool isSelected1 = false;
//bool isSelected2 = false;
//// for Menu variables
//
//void obalTrace(void){
//    SW1SetFunction(startTrace);
//    SW2SetFunction(startTrace);
//    ledAsobi = 0b1;
//    ledChooseR();
//    TMR1_SetInterruptHandler(startAsobu);
//    while(!isTrace){ledBright(ledAsobi);
//    }
//    //    SW1SetFunction(selectThr);
//    //    SW2SetFunction(selectThr);
//    tone(2000);
//    __delay_ms(200);
//    tone(1500);
//    __delay_ms(200);
//    tone(1000);
//    __delay_ms(500);
//    noTone();
//    onG();
//    sensorSelector(1);
//    while(isSelected1) {
//        uint16_t sens = analogScan();
//        ledBright(sens << 6);
//    }
//    while(1){
//        
//    }
//}
//
//void startAsobu(){
//    bool head=(ledAsobi&0xFFFF)>>15;
//    ledAsobi<<=1;
//    ledAsobi|=head;
//    return;
//}
//
//void startTrace(void){
//    isTrace = true;
//    return;
//}

void main(void) {
    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

    //    SWSetupISR(); // DO NOT DELETE IT
    //
    //    LED_G_PORT = 0;
    //    LED_R_PORT = 1;
        tone(2000);
        __delay_ms(200);
        tone(1000);
        __delay_ms(200);
        noTone();
    //
    //    LED_R_PORT = 0;
    //    LED_G_PORT = 1;
    //    SW1SetFunction(segmentCFlip);
    //    SW2SetFunction(segmentGo);
    //
    //    LED_G_PORT = 0;
    //    LED_R_PORT = 1;
    //
    //    ledChooseG();

    PWM5_Start();
    PWM6_Start();
    PWM5_DutyCycleSet(0);
    PWM6_DutyCycleSet(0);
    while (1) {
        //        obalTrace();
        L_SEL1_PORT = 0;
        L_SEL2_PORT = 1;
        R_SEL1_PORT = 0;
        R_SEL2_PORT = 1;
    }
}
/**
 End of File
 */