/* 
 * File:   animation.h
 * Author: meumeumeucar
 *
 * Created on September 23, 2023, 11:11 PM
 */

#ifndef ANIMATION_H
#define	ANIMATION_H

#include<stdbool.h>
#include<stdint.h>
#include "mcc_generated_files/mcc.h"
#include "16x2led.h"

#ifdef	__cplusplus
extern "C" {
#endif

#define ROTATION_TIME 16

    void anmLine(signed int bData, bool RG);

    void anmRot(uint16_t RData, uint16_t BData);

    void anmMeter(uint16_t dData, bool RGHigherColor);

    void noAnm(void);

    void anmBright(void);

    void anmRotBright(void);

    volatile uint16_t anmBitshiftRRotation(uint16_t rotDat, uint8_t rotNum);


#ifdef	__cplusplus
}
#endif

#endif	/* ANIMATION_H */

