#include "kasix.h"

void kasixInitialize(void) {
    SWSetupISR(); // DO NOT DELETE IT
    motorSetup(); // DO NOT DELETE IT
    tone(2000);
    __delay_ms(200);
    tone(1000);
    __delay_ms(200);
    noTone();

    //    motorCheck
    PWM3_LoadDutyValue(0);
    PWM4_LoadDutyValue(0);
    L_SEL1_PORT = 1;
    L_SEL2_PORT = 0;
    R_SEL1_PORT = 1;
    R_SEL2_PORT = 0;
    PWM3_LoadDutyValue(0xffff);
    PWM4_LoadDutyValue(0xffff);
    __delay_ms(100);
    PWM3_LoadDutyValue(0x0);
    PWM4_LoadDutyValue(0x0);
}

bool kasixSTCBCF1 = 0, kasixSTCBCF2 = 0;

void kasixSTCBConfirm1(void) {
    kasixSTCBCF1 = true;
}

void kasixSTCBConfirm2(void) {
    kasixSTCBCF2 = true;
}

void kasixDisplaySensors(void) {
    uint16_t kasixSRBuf = analogScan();
    anmMeter(kasixSRBuf, true);
    return;
}

uint16_t kasixSH1, kasixSH2, kasixSL1, kasixSL2;

void kasixSensorThrControl(void) {
    TMR1_SetInterruptHandler(kasixDisplaySensors);

    sensorSelector(0);
    SW1SetFunction(kasixSTCBConfirm1);
    SW2SetFunction(kasixSTCBConfirm1);
    while (!kasixSTCBCF1) {
    }
    kasixSH1 = analogScan();
    tone(2000);
    __delay_ms(1000);
    noTone();
    sensorSelector(0);
    SW1SetFunction(kasixSTCBConfirm2);
    SW2SetFunction(kasixSTCBConfirm2);
    while (!kasixSTCBCF2) {
    }
    kasixSL1 = analogScan();
    tone(4000);
    __delay_ms(1000);
    noTone();

    kasixSTCBCF1 = false;
    kasixSTCBCF2 = false;

    sensorSelector(1);
    SW1SetFunction(kasixSTCBConfirm1);
    SW2SetFunction(kasixSTCBConfirm1);
    while (!kasixSTCBCF1) {
    }
    kasixSH2 = analogScan();
    tone(3000);
    __delay_ms(1000);
    noTone();
    sensorSelector(1);
    SW1SetFunction(kasixSTCBConfirm2);
    SW2SetFunction(kasixSTCBConfirm2);
    while (!kasixSTCBCF2) {
    }
    kasixSL2 = analogScan();
    tone(6000);
    __delay_ms(1000);
    noTone();

    TMR1_SetInterruptHandler(NULL);
}

bool kasixPauseFlag = false;

void kasixPauseTrace(void) {
    PWM3_LoadDutyValue(0);
    PWM4_LoadDutyValue(0);
    kasixPauseFlag = true;
    onR();
    __delay_ms(100);
    volatile uint16_t kasixPTTimer = 0;
    while (kasixPauseFlag) {
        if (SW1_PORT || SW2_PORT) kasixPauseFlag = false;
        if (kasixPTTimer == 0xff) {
            kasixPTTimer = 0;
            flipDL();
        }
        kasixPTTimer++;
    }
    onG();
    __delay_ms(1000);
    SW1SetFunction(kasixPauseTrace);
    SW2SetFunction(kasixPauseTrace);
    return;
}

void kasixBacktoTrace(void) {
    kasixPauseFlag = false;
    return;
}

#define KASIX_MAXTRACE 15
#define KASIX_TRACE1 3
#define KASIX_TRACE2 7
#define KASIX_TRACE3 11

kasixStandardTrace(void) {
    uint16_t kasixSTh1 = (kasixSH1 - kasixSL1) / 4, kasixSTh2 = (kasixSH2 - kasixSL2) / 4;
    uint16_t kasixSRVal1, kasixSRVal2;
    uint16_t kasixSDepth = 0;

    //halt
    SW1SetFunction(kasixPauseTrace);
    SW2SetFunction(kasixPauseTrace);

    while (1) {
        kasixSRVal1 = analogScanP(0);
        kasixSRVal2 = analogScanP(1);
        if (kasixSRVal1 < kasixSL1 + kasixSTh1 && !(kasixSRVal2 < kasixSL2 + kasixSTh2)) {
            PWM3_LoadDutyValue(KASIX_MAXTRACE);
            PWM4_LoadDutyValue(KASIX_TRACE1);
            anmLine(-3, true);
            kasixSDepth = 3;
        } else if (kasixSRVal2 < kasixSL2 + kasixSTh2 && !(kasixSRVal1 < kasixSL1 + kasixSTh1)) {
            PWM3_LoadDutyValue(KASIX_TRACE1);
            PWM4_LoadDutyValue(KASIX_MAXTRACE);
            anmLine(3, true);
            kasixSDepth = 3;
        } else if (kasixSRVal1 < kasixSL1 + 2 * kasixSTh1 && !(kasixSRVal2 < kasixSL2 + 2 * kasixSTh2) && kasixSDepth <= 3) {
            PWM3_LoadDutyValue(KASIX_MAXTRACE);
            PWM4_LoadDutyValue(KASIX_TRACE2);
            anmLine(-2, true);
            kasixSDepth = 2;
        } else if (kasixSRVal2 < kasixSL2 + 2 * kasixSTh2 && !(kasixSRVal1 < kasixSL1 + 2 * kasixSTh1) && kasixSDepth <= 3) {
            PWM3_LoadDutyValue(KASIX_TRACE2);
            PWM4_LoadDutyValue(KASIX_MAXTRACE);
            anmLine(2, true);
            kasixSDepth = 2;
        } else if (kasixSRVal1 < kasixSL1 + 3 * kasixSTh1 && !(kasixSRVal2 < kasixSL2 + 3 * kasixSTh2) && kasixSDepth <= 2) {
            PWM3_LoadDutyValue(KASIX_MAXTRACE);
            PWM4_LoadDutyValue(KASIX_TRACE3);
            anmLine(-1, true);
            kasixSDepth = 1;
        } else if (kasixSRVal2 < kasixSL2 + 3 * kasixSTh2 && !(kasixSRVal1 < kasixSL1 + 3 * kasixSTh1) && kasixSDepth <= 2) {
            PWM3_LoadDutyValue(KASIX_TRACE3);
            PWM4_LoadDutyValue(KASIX_MAXTRACE);
            anmLine(1, true);
            kasixSDepth = 1;
        } else if (kasixSDepth = 0) {
            PWM3_LoadDutyValue(KASIX_MAXTRACE);
            PWM4_LoadDutyValue(KASIX_MAXTRACE);
            anmLine(0, true);
        }
    }
}
