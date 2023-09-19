/* 
 * File:   16x2led.c
 * Author: seikin
 *
 * Created on September 18, 2023, 4:38 PM
 */

#include "16x2led.h"

/*
 * 
 */

bool LEDcolorR = false, LEDcolorG = false;

void ledChooseR(void){
    if(LEDcolorR) return;
    LEDcolorR=true;
    LEDcolorG=false;
    LED_COLSEL2_PORT = 0;
    __delay_us(1);
    LED_COLSEL1_PORT = 1;
    __delay_us(1);
    return;
}

void ledChooseG(void){
    if(LEDcolorG) return;
    LEDcolorR=false;
    LEDcolorG=true;
    LED_COLSEL1_PORT = 0;
    __delay_us(1);
    LED_COLSEL2_PORT = 1;
    __delay_us(1);
    return;
}

bool ledSwapColor(void){
    if(!(LEDcolorR || LEDcolorG)) return 1;
    LEDcolorR = !LEDcolorR;
    LEDcolorG = !LEDcolorG;
    if(LEDcolorR == false){  // R=>G change
        LED_COLSEL1_PORT = 0;
        __delay_us(1);
        LED_COLSEL2_PORT = 1;
        __delay_us(1);
    }else{                  // G=>R change
        LED_COLSEL2_PORT = 0;
        __delay_us(1);
        LED_COLSEL1_PORT = 1;
        __delay_us(1);
    }
    return 0;
}

void ledDisable(void){
    LEDcolorR=false;
    LEDcolorG=false;
    LED_COLSEL1_PORT = 0;
    LED_COLSEL2_PORT = 0;
    __delay_us(10);
    return;
}

void ledBright(ledSegmentsData brightData){
    for(uint8_t procSeg = 0; procSeg <= 16; brightData>>=1, procSeg++){
        LED_SREG_DAT_PORT = !(brightData & 0b1);
        LED_SREG_CLK_PORT = 0;
        LED_SREG_CLK_PORT = 1;
        LED_SREG_CLK_PORT = 0;
    }
    LED_SREG_SEND_PORT = 1;
    LED_SREG_SEND_PORT = 0;
    return;
}
