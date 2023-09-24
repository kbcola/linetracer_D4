#include "animation.h"

volatile bool anmRG = false;
volatile uint16_t anmRDispData;
volatile uint16_t anmGDispData;
volatile unsigned int anmTimes = 0;

void anmLine(signed int bData, bool RG) {
    bData += 4; // -4 -> 0
    if (bData < 0)bData = 0;
    if (bData > 9)bData = 9;
    uint16_t anmDispData = 0b0000000100000001;
    anmDispData = anmBitshiftRRotation(anmDispData, bData);
    if (RG) {
        anmRDispData = anmDispData;
        anmGDispData = ~anmDispData;
    } else {
        anmGDispData = anmDispData;
        anmRDispData = ~anmDispData;
    }
    TMR3_SetInterruptHandler(anmBright);
    return;
}

void anmRot(uint16_t RData, uint16_t GData) {
    anmRDispData = RData;
    anmGDispData = GData;
    anmTimes = 0;
    TMR3_SetInterruptHandler(anmRotBright);
    return;
}

void anmMeter(uint16_t dData, bool RGHigherColor) {
    uint8_t upperBit = dData >> 12;
    uint8_t lowerBit = 0x0f & (dData >> 8);
    if (RGHigherColor) {
        anmRDispData = 0xffff >> (15 - upperBit);
        anmGDispData = 0xffff >> (15 - lowerBit);
    } else {
        anmGDispData = 0xffff >> (15 - upperBit);
        anmRDispData = 0xffff >> (15 - lowerBit);
    }
    TMR3_SetInterruptHandler(anmBright);
    return;
}

void noAnm(void) {
    ledDisable();
    TMR3_SetInterruptHandler(NULL);
    return;
}

void anmBright(void) {
    anmRG = !anmRG;
    if (anmRG) {
        ledChooseR();
        ledBright(anmRDispData);
    } else {
        ledChooseG();
        ledBright(anmGDispData);
    }
    return;
}

void anmRotBright(void) {
    anmRG = !anmRG;
    if (anmRG) {
        ledChooseR();
        ledBright(anmRDispData);
    } else {
        ledChooseG();
        ledBright(anmGDispData);
    }
    anmTimes++;
    if (anmTimes > ROTATION_TIME) {
        anmRDispData = anmBitshiftRRotation(anmRDispData, 1);
        anmGDispData = anmBitshiftRRotation(anmGDispData, 1);
        anmTimes = 0;
    }
    return;
}

volatile uint16_t anmBitshiftRRotation(volatile uint16_t rotDat, volatile uint8_t rotNum) {
    volatile bool headAnmBSRR = false;
    for (volatile uint8_t rni = 0; rni < rotNum; rni++) {
        headAnmBSRR = rotDat & 0b1;
        rotDat >>= 1;
        rotDat |= (headAnmBSRR << 15);
    }
    return rotDat;
}