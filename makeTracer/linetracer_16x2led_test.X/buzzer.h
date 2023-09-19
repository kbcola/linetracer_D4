/* 
 * File:   buzzer.h
 * Author: seikin
 *
 * Created on September 19, 2023, 1:04 PM
 */

#ifndef BUZZER_H
#define	BUZZER_H

#ifdef	__cplusplus
extern "C" {
#endif

    typedef uint16_t toneScale;
    
    void tone(toneScale ts);
    
    void noTone(void);

#ifdef	__cplusplus
}
#endif

#endif	/* BUZZER_H */

