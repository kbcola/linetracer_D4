/* 
 * File:   motordrive.h
 * Author: meumeumeucar
 *
 * Created on September 23, 2023, 11:06 PM
 */

#ifndef MOTORDRIVE_H
#define	MOTORDRIVE_H

#include<stdint.h>
#include "mcc_generated_files/mcc.h"

#ifdef	__cplusplus
extern "C" {
#endif

    void motorSetup(void);

    void steer(uint16_t left, uint16_t right);

#ifdef	__cplusplus
}
#endif

#endif	/* MOTORDRIVE_H */

