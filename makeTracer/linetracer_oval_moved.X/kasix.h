/* 
 * File:   kasix.h
 * Author: meumeumeucar
 *
 * Created on September 24, 2023, 9:55 PM
 */

#ifndef KASIX_H
#define	KASIX_H

#include "mcc_generated_files/mcc.h"
#include "16x2led.h"
#include "animation.h"
#include "buzzer.h"
#include "directLED.h"
#include "motordrive.h"
#include "sensor.h"
#include "switchHandler.h"

#ifdef	__cplusplus
extern "C" {
#endif

    void kasixInitialize(void);

    void kasixSensorThrControl(void);


#ifdef	__cplusplus
}
#endif

#endif	/* KASIX_H */

