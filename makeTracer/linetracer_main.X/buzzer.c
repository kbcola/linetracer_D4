
#include "buzzer.h"

volatile uint8_t timerIntr = 0;
volatile uint8_t flipNum = 0;

volatile bool isPlay = false;
volatile toneWaitTime twtTh = 0;
volatile tonePlayTime tptTh = 0;
toneBeat ntb = 600;

void tone(toneScale ts) {
    isPlay = true;
    TMR0_SetInterruptHandler(flipWave);
    timerIntr = 0;
    twtTh = 10000 / ts; // (100kHz / nHz) * 10us
    INTCONbits.TMR0IE = 1;
    return;
}

void noTone(void) {
    isPlay = false;
    BUZZ_PORT = 0;
    INTCONbits.TMR0IE = 0;
    TMR0_SetInterruptHandler(NULL);
    return;
}

void setupBeat(toneBeat tb) {
    ntb = tb;
    return;
}

void toneL(toneScale ts, toneLength tl) {
    isPlay = true;
    TMR0_SetInterruptHandler(flipWaveL);
    timerIntr = 0;
    flipNum = 0;
    twtTh = 10000 / ts; // (100kHz / nHz) * 10us
    tptTh = 1000000 * tl;
    INTCONbits.TMR0IE = 1;
    return;
}

void flipWave(void) {
    timerIntr++;
    if (timerIntr >= twtTh) {
        BUZZ_PORT = !BUZZ_PORT;
        timerIntr = 0;
    }
    return;
}

void flipWaveL(void) {
    timerIntr++;
    if (flipNum >= tptTh) {
        noTone();
        return;
    }
    if (timerIntr >= twtTh) {
        BUZZ_PORT = !BUZZ_PORT;
        if (!BUZZ_PORT) flipNum++;
        timerIntr = 0;
    }
    return;
}