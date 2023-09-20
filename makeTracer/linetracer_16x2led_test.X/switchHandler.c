#include "switchHandler.h"

bool isSW1Chating = false;
bool isSW2Chating = false;

void (*SW1_InterruptHandler)(void);
void (*SW2_InterruptHandler)(void);

void setupSWISR(void){
    IOCAF4_SetInterruptHandler(SW1Pushed);
    IOCAF5_SetInterruptHandler(SW2Pushed);
}

void SW1SetFunction(void (* handler)(void)){
    SW1_InterruptHandler = handler;
}
    
void SW2SetFunction(void (* handler)(void)){
    SW2_InterruptHandler = handler;
}

void SW1Pushed() {
    if(isSW1Chating) return;
    SW1_InterruptHandler();
    isSW1Chating = true;
    if(isSW2Chating){ // double interrupt is covered by TMR4
        
    }
    return;
}

void SW2Pushed(){
    
}

void SW1ChatteringFinish(void){
        
}
    
void SW2ChatteringFinish(void){
        
}
