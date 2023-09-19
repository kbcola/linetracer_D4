/* 
 * File:   buzzer.h
 * Author: seikin
 *
 * Created on September 19, 2023, 1:04 PM
 */

#ifndef BUZZER_H
#define	BUZZER_H

#include <stdbool.h>
#include <stdint.h>
#include "mcc_generated_files/mcc.h"

#ifdef	__cplusplus
extern "C" {
#endif

    typedef uint16_t toneScale;
    typedef uint16_t toneWaitTime;
    typedef uint16_t tonePlayTime;
    typedef uint16_t toneBeat;
    typedef uint16_t toneLength;

    void tone(toneScale ts);

    void noTone(void);

    void setupBeat(toneBeat tb);

    void toneL(toneScale ts, toneLength tl);

    void flipWave(void);

    void flipWaveL(void);

#ifdef	__cplusplus
}
#endif

#endif	/* BUZZER_H */

