/* 
 * File:   directLED.c
 * Author: seikin
 *
 * Created on September 22, 2023, 3:40 PM
 */

#include "mcc_generated_files/mcc.h"
#include "directLED.h"

void onG(void){
    LED_R_PORT = 0;
    LED_G_PORT = 1;
    return;
}

void onR(void){
    LED_G_PORT = 0;
    LED_R_PORT = 1;
    return;
}

void offG(void){
    LED_G_PORT = 0;
    return;
}

void offR(void){
    LED_R_PORT = 0;
    return;
}

void flipDL(void){
    if(LED_R_PORT && !LED_G_PORT)      onG();
    else if(LED_G_PORT && !LED_R_PORT) onR();
    return;
}
