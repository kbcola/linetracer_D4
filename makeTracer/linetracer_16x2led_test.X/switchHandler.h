/* 
 * File:   switchHandler.h
 * Author: meumeumeucar
 *
 * Created on September 19, 2023, 11:51 PM
 */

#ifndef SWITCHHANDLER_H
#define	SWITCHHANDLER_H

#include <stdbool.h>
#include "mcc_generated_files/mcc.h"

#ifdef	__cplusplus
extern "C" {
#endif

    void setupSWISR(void);
    
    void SW1SetFunction(void (* SW1Handler)(void));
    
    void SW2SetFunction(void (* SW2Handler)(void));

    void SW1Pushed(void); // CALL: if you pushed SW1

    void SW2Pushed(void); // CALL: if you pushed SW1
    
    void SW1ChatteringFinish(void); // CALL: if TMR4 compared
    
    void SW2ChatteringFinish(void); // CALL: if TMR4 compared


#ifdef	__cplusplus
}
#endif

#endif	/* SWITCHHANDLER_H */

