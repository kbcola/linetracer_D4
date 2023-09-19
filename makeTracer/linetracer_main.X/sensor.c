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
    bool sensorSelector(sensorPortNum spn){
        if(spn>3) return 1;
        SENS_SEL1_PORT = spn>>1; // Upper bit
        SENS_SEL2_PORT = spn%2;  // Lower bit
        spnSave = spn;
        return 0;
    }
    
    ascanResult analogScan(void){
        ADC_StartConversion();
        while(!ADC_IsConversionDone()){}
        return ADC_GetConversionResult(); 
    }

