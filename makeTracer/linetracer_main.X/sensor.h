/* 
 * File:   sensor.h
 * Author: seikin
 *
 * Created on September 19, 2023, 1:22 PM
 */

#ifndef SENSOR_H
#define	SENSOR_H

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include "mcc_generated_files/mcc.h"

#ifdef	__cplusplus
extern "C" {
#endif

    typedef uint8_t sensorPortNum;
    typedef uint16_t ascanResult;
    typedef bool dscanResult;

    bool sensorSelector(sensorPortNum spn);

    ascanResult analogScan(void);

    dscanResult digitalScan(void);

    ascanResult analogScanP(sensorPortNum spn);

    dscanResult digitalScanP(sensorPortNum spn);

    void changeDigitalThr(uint16_t thr);

    bool checkDigitalThr(uint16_t thr, sensorPortNum spn);

#ifdef	__cplusplus
}
#endif

#endif	/* SENSOR_H */

