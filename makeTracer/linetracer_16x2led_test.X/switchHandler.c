#include "switchHandler.h"

#define defaultTime 0x7C // 1ms (8us x 125)

volatile bool isSW1Chating = false;
volatile bool isSW2Chating = false;
volatile uint8_t newStartTime = 0x7C; // 1ms (8us x n times)

void (*SW1_InterruptHandler)(void);
void (*SW2_InterruptHandler)(void);

void SWSetupISR(void) {
    IOCAF4_SetInterruptHandler(SW1Pushed);
    IOCAF5_SetInterruptHandler(SW2Pushed);
}

void SW1SetFunction(void (* handler)(void)) {
    SW1_InterruptHandler = handler;
}

void SW2SetFunction(void (* handler)(void)) {
    SW2_InterruptHandler = handler;
}

void SW1Pushed() {
    if (isSW1Chating) return;
    SW1_InterruptHandler();
    isSW1Chating = true;
    if (isSW2Chating) { // double interrupt is covered by TMR4
        uint8_t nowtime = TMR4_ReadTimer();
        newStartTime = defaultTime - nowtime;
    } else {
        TMR4_Counter8BitSet(0);
        TMR4_SetInterruptHandler(SW1ChatteringFinish);
    }
    return;
}

void SW2Pushed() {
    if (isSW2Chating) return;
    SW2_InterruptHandler();
    isSW2Chating = true;
    if (isSW1Chating) { // double interrupt is covered by TMR4
        uint8_t nowtime = TMR4_ReadTimer();
        newStartTime = defaultTime - nowtime;
    } else {
        TMR4_Counter8BitSet(0);
        TMR4_SetInterruptHandler(SW2ChatteringFinish);
    }
    return;
}

void SW1ChatteringFinish(void) {
    isSW1Chating = false;
    if (isSW2Chating) {
        TMR4_Period8BitSet(newStartTime); // 1ms - elapsedTime
        TMR4_SetInterruptHandler(SW2ChatteringFinish);
    } else {
        TMR4_Period8BitSet(defaultTime); // 1ms
        TMR4_SetInterruptHandler(NULL);
    }
    return;
}

void SW2ChatteringFinish(void) {
    isSW2Chating = false;
    if (isSW1Chating) {
        TMR4_Period8BitSet(newStartTime); // 1ms - elapsedTime
        TMR4_SetInterruptHandler(SW1ChatteringFinish);
    } else {
        TMR4_Period8BitSet(defaultTime); // 1ms
        TMR4_SetInterruptHandler(NULL);
    }
    return;
}
