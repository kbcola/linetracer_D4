/* 
 * File:   sensor.c
 * Author: seikin
 *
 * Created on September 19, 2023, 1:31 PM
 */

#include "sensor.h"

/*
 * 
 */
sensorPortNum spnSave = 0;
uint16_t nowDigitalThr = 0x8000;

bool sensorSelector(sensorPortNum spn) {
    if (spn > 3) return 1;
    SENS_SEL1_PORT = spn >> 1; // Upper bit
    SENS_SEL2_PORT = spn % 2; // Lower bit
    spnSave = spn;
    __delay_ms(1); // MUX Wait time
    return 0;
}

ascanResult analogScan(void) {
    ADC_StartConversion();
    while (!ADC_IsConversionDone()) {
    } // wait
    return ADC_GetConversionResult();
}

dscanResult digitalScan(void) {
    return CMP1_GetOutputStatus();
}

ascanResult analogScanP(sensorPortNum spn) {
    SENS_SEL1_PORT = spn >> 1; // Upper bit
    SENS_SEL2_PORT = spn % 2; // Lower bit
    __delay_ms(1); // MUX Wait time
    ADC_StartConversion();
    while (!ADC_IsConversionDone()) {
    } // wait
    ascanResult res = ADC_GetConversionResult();
    SENS_SEL1_PORT = spnSave >> 1; // Upper bit
    SENS_SEL2_PORT = spnSave % 2; // Lower bit
    __delay_ms(1); // MUX Wait time
    return res;
}

dscanResult digitalScanP(sensorPortNum spn) {
    SENS_SEL1_PORT = spn >> 1; // Upper bit
    SENS_SEL2_PORT = spn % 2; // Lower bit
    __delay_ms(1); // MUX Wait time
    dscanResult res = CMP1_GetOutputStatus();
    SENS_SEL1_PORT = spnSave >> 1; // Upper bit
    SENS_SEL2_PORT = spnSave % 2; // Lower bit
    __delay_ms(1); // MUX Wait time
    return res;
}

void changeDigitalThr(uint16_t thr) {
    if (thr > 1023) thr = 1023;
    DAC1_Load10bitInputData(thr);
    return;
}

bool checkDigitalThr(uint16_t thr, sensorPortNum spn) {
    if (thr > 1023) thr = 1023;
    DAC1_Load10bitInputData(thr);
    SENS_SEL1_PORT = spn >> 1; // Upper bit
    SENS_SEL2_PORT = spn % 2; // Lower bit
    __delay_ms(1); // MUX Wait time
    dscanResult res = CMP1_GetOutputStatus();
    SENS_SEL1_PORT = spnSave >> 1; // Upper bit
    SENS_SEL2_PORT = spnSave % 2; // Lower bit
    __delay_ms(1); // MUX Wait time
    return res;
}