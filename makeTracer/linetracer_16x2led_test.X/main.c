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

/*
                         Main application
 */

volatile uint16_t headMaskR = 0b1;
volatile uint16_t headMaskG = 0b1000000000000000;
volatile bool revLoop = false;
volatile uint8_t shiftR = 15;
volatile uint8_t shiftG = 1;

void l1(void){
    revLoop = true;
    headMaskR = 0b1000000000000000;
    headMaskG = 0b1;
    tone(880);
    return;
}

void l2(void){
    revLoop = false;
    headMaskR = 0b1;
    headMaskG = 0b1000000000000000;
    tone(440);
    return;
}

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

    uint16_t test, gtest;

    SWSetupISR(); // >>> IMPORTANT: DO NOT DELETE IT <<<
    
    //    PC98
    tone(2000);
    __delay_ms(200);
    tone(1000);
    __delay_ms(200);
    noTone();
    //    PC98

    test = 0b0110000000000000;
    gtest = 0b0110000000000000;
    ledBright(test);

    SW1SetFunction(l1);
    SW2SetFunction(l2);
    
//    tone(523);
//    __delay_ms(500);
//    tone(587);
//    __delay_ms(500);
//    tone(659);
//    __delay_ms(500);
//    tone(698);
//    __delay_ms(500);
//    tone(784);
//    __delay_ms(500);
//    tone(880);
//    __delay_ms(500);
//    tone(988);
//    __delay_ms(500);
//    tone(1046);
//    __delay_ms(500);
//    noTone();
    
    while (1) {
        LED_G_PORT = !revLoop;
        LED_R_PORT = revLoop;
        //        test=0b1010101010101010;

        bool head = test & headMaskR;
        if(revLoop){
            test <<= 1;
        }else{
            test >>= 1;
        }
        test = test | (head << ((uint8_t)(!revLoop) * 15));
        
        head = gtest & headMaskG;
        if(revLoop){
            gtest >>= 1;
        }else{
            gtest <<= 1;
        }
        gtest = gtest | (head << ((uint8_t)(revLoop) * 15));
        
        for (int o = 0; o < 100; o++) {
            ledChooseR();
            ledBright(test);
            ledChooseG();
            ledBright(gtest);
        }
        //        test=0b0101010101010101;
        //        test=0;
    }
}
/**
 End of File
 */