/* 
 * File:   16x2led.h
 * Author: seikin
 *
 * Created on September 18, 2023, 12:38 AM
 */

#ifndef HEXDLED_H
#define	HEXDLED_H

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include "mcc_generated_files/mcc.h"

#ifdef	__cplusplus
extern "C" {
#endif

    typedef uint16_t ledSegmentsData;


    bool LEDcolorR, LEDcolorG;

    
    void ledChooseR(void);
    
    void ledChooseG(void);
    
    bool ledSwapColor(void);
    
    void ledDisable(void);
    
    void ledBright(ledSegmentsData brightData);
    
#ifdef	__cplusplus
}
#endif

#endif	// HEXDLED_H

