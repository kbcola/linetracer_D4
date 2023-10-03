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


// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>[[[[[[[[[[[[[Interface]]]]]]]]]]]]]<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


//bool kasixMenuEntry
//void kasixIConfirm(void) {
//
//}
//
//void kasixInterfaceMainmenu(void) {
//    SW1SetFunction();
//}

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>[[[[[[[[[[[[[[Sensors]]]]]]]]]]]]]]<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

void kasixWarning(void) {
    for (uint8_t kasixSWFi = 0; kasixSWFi != 100; kasixSWFi++) {
        tone(1000 + 100 * (kasixSWFi % 10));
        __delay_ms(20);
    }
    noTone();
    return;
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

uint16_t kasixSH1 = 480 << 6, kasixSH2 = 480 << 6, kasixSL1 = 32 << 6, kasixSL2 = 32 << 6;

void kasixSensorThrControl(void) {
    TMR1_SetInterruptHandler(kasixDisplaySensors);

    sensorSelector(0);
    SW1SetFunction(kasixSTCBConfirm1);
    SW2SetFunction(kasixSTCBConfirm1);
    while (!kasixSTCBCF1) {
    }
    kasixSH1 = analogScan();
    tone(2000);
    __delay_ms(500);
    noTone();
    sensorSelector(0);
    SW1SetFunction(kasixSTCBConfirm2);
    SW2SetFunction(kasixSTCBConfirm2);
    while (!kasixSTCBCF2) {
    }
    kasixSL1 = analogScan();
    tone(4000);
    __delay_ms(500);
    noTone();

    if (kasixSH1 < kasixSL1) {
        kasixWarning();
    }

    kasixSTCBCF1 = false;
    kasixSTCBCF2 = false;

    sensorSelector(1);
    SW1SetFunction(kasixSTCBConfirm1);
    SW2SetFunction(kasixSTCBConfirm1);
    while (!kasixSTCBCF1) {
    }
    kasixSH2 = analogScan();
    tone(2500);
    __delay_ms(500);
    noTone();
    sensorSelector(1);
    SW1SetFunction(kasixSTCBConfirm2);
    SW2SetFunction(kasixSTCBConfirm2);
    while (!kasixSTCBCF2) {
    }
    kasixSL2 = analogScan();
    tone(5000);
    __delay_ms(500);
    noTone();

    if (kasixSH1 < kasixSL1) {
        kasixWarning();
    }

    TMR1_SetInterruptHandler(NULL);
}

uint16_t kasixSDThr[4] = {480, 480, 480, 480};

void kasixSensorDThrControl(void) {
    uint16_t kasixSDTCDacTest = 0, kasixSDTCSetValue, kasixSDTCHigh, kasixSDTCLow;
    for (uint8_t kasixSDTCPort = 0; kasixSDTCPort < 4; kasixSDTCPort++) {
        kasixSTCBCF1 = false;
        kasixSTCBCF2 = false;
        SW1SetFunction(kasixSTCBConfirm1);
        SW2SetFunction(kasixSTCBConfirm1);
        while (!kasixSTCBCF1) {
            sensorSelector(kasixSDTCPort);
            DAC1_Load10bitInputData(kasixSDTCDacTest);
            if (digitalScan()) {
                anmMeter(kasixSDTCDacTest << 6, true);
                kasixSDTCSetValue = kasixSDTCDacTest;
                kasixSDTCDacTest = 0;
                tone(1500);
                __delay_ms(100);
                noTone();
            }
            if (kasixSDTCDacTest == 0b1111111111) kasixSDTCDacTest = 0xffff;
            kasixSDTCDacTest++;
            __delay_us(1);
        }
        kasixSDTCHigh = kasixSDTCSetValue;
        tone(3000);
        __delay_ms(500);
        noTone();
        kasixSTCBCF1 = false;
        while (!kasixSTCBCF1) {
            sensorSelector(kasixSDTCPort);
            DAC1_Load10bitInputData(kasixSDTCDacTest);
            if (digitalScan()) {
                anmMeter(kasixSDTCDacTest << 6, true);
                kasixSDTCSetValue = kasixSDTCDacTest;
                kasixSDTCDacTest = 0;
                tone(1500);
                __delay_ms(100);
                noTone();
            }
            if (kasixSDTCDacTest == 0b1111111111) kasixSDTCDacTest = 0xffff;
            kasixSDTCDacTest++;
            __delay_us(1);
        }
        kasixSDTCLow = kasixSDTCSetValue;
        kasixSDTCDacTest = (kasixSDTCLow + (kasixSDTCHigh - kasixSDTCLow) / 2); // Half Thr
        anmMeter(kasixSDTCDacTest << 6, true);
        DAC1_Load10bitInputData(kasixSDTCDacTest);
        SW1SetFunction(NULL);
        SW2SetFunction(kasixSTCBConfirm2);
        tone(1500);
        __delay_ms(500);
        noTone();
        while (!kasixSTCBCF2) {
            if (!SW1_PORT) {
                tone(1000);
                __delay_ms(1000);
                noTone();
                kasixSDTCPort--;
                break;
            }
            sensorSelector(kasixSDTCPort);
            if (digitalScan()) {
                onG();
            } else {
                onR();
            }
        }
        kasixSDThr[kasixSDTCPort] = kasixSDTCDacTest;
        tone(2000);
        __delay_ms(500);
        noTone();
    }
    return;
}

#define KASIX_SDTHR_CONFIG 10

void kasixCalibration(void) {
    if (SW1_PORT && SW2_PORT) {
        return;
    }
    kasixSTCBCF1 = false;
    kasixSTCBCF2 = false;

    TMR1_SetInterruptHandler(kasixDisplaySensors);

    sensorSelector(0);
    SW1SetFunction(kasixSTCBConfirm1);
    SW2SetFunction(kasixSTCBConfirm1);
    while (!kasixSTCBCF1) {
    }
    onG();

    kasixSH1 = analogScanP(0);
    kasixSH2 = analogScanP(1);

    uint16_t kasixCalibSDThrH[4];
    for (uint8_t kasixArrayIndex = 0; kasixArrayIndex < 4; kasixArrayIndex++) {
        for (uint16_t kasixSDThrTest = 0; kasixSDThrTest < 1024; kasixSDThrTest++) {
            DAC1_Load10bitInputData(kasixSDThrTest);
            if (digitalScanP(kasixArrayIndex)) {
                kasixCalibSDThrH[kasixArrayIndex] = kasixSDThrTest;
                break;
            }
        }
    }

    tone(2000);
    __delay_ms(500);
    noTone();

    sensorSelector(0);
    SW1SetFunction(kasixSTCBConfirm2);
    SW2SetFunction(kasixSTCBConfirm2);
    while (!kasixSTCBCF2) {
    }
    onR();


    kasixSL1 = analogScanP(0);
    kasixSL2 = analogScanP(1);

    uint16_t kasixCalibSDThrL[4];
    for (uint8_t kasixArrayIndex = 0; kasixArrayIndex < 4; kasixArrayIndex++) {
        for (uint16_t kasixSDThrTest = 0; kasixSDThrTest < 1024; kasixSDThrTest++) {
            DAC1_Load10bitInputData(kasixSDThrTest);
            if (digitalScanP(kasixArrayIndex)) {
                kasixCalibSDThrL[kasixArrayIndex] = kasixSDThrTest;
                break;
            }
        }
    }

    tone(4000);
    __delay_ms(500);
    noTone();

    for (uint8_t kasixArrayIndex; kasixArrayIndex < 4; kasixArrayIndex++) {
        kasixSDThr[kasixArrayIndex] = kasixCalibSDThrL[kasixArrayIndex] + KASIX_SDTHR_CONFIG;
    }

    if (kasixSH1 < kasixSL1) {
        kasixWarning();
    }

    TMR1_SetInterruptHandler(NULL);
    return;
}

bool kasixTraceStart = false;

void kasixTraceGo() {
    kasixTraceStart = true;
    return;
}

void kasixReadyTrace(void) {
    tone(1000);
    __delay_ms(250);
    tone(2000);
    __delay_ms(250);
    tone(1000);
    __delay_ms(250);
    tone(2000);
    __delay_ms(250);
    noTone();

    SW1SetFunction(kasixTraceGo);
    SW2SetFunction(kasixTraceGo);
    while (!kasixTraceStart) {
        anmLine(((uint16_t) (8.0 * (double) analogScanP(0) / (double) (kasixSH1 - kasixSL1)) - 4), true);
    }
    tone(3000);
    __delay_ms(1000);
    noTone();

    return;
}

void kasixReadyTraceRside(void) {
    tone(1000);
    __delay_ms(100);
    tone(2000);
    __delay_ms(100);
    tone(1000);
    __delay_ms(100);
    tone(2000);
    __delay_ms(100);
    noTone();

    SW1SetFunction(kasixTraceGo);
    SW2SetFunction(kasixTraceGo);
    while (!kasixTraceStart) {
        anmLine(((uint16_t) (8.0 * (double) analogScanP(1) / (double) (kasixSH1 - kasixSL1)) - 4), true);
    }
    tone(3000);
    __delay_ms(1000);
    noTone();

    return;
}

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>[[[[[[[[[[[[[[[Traces]]]]]]]]]]]]]]]<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

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

#define KASIX_MAXTRACE 24
#define KASIX_TRACE1 3
#define KASIX_TRACE2 7
#define KASIX_TRACE3 11

void kasixStandardTrace(void) {
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

#define KASIX_PT_GAIN 48.0
#define KASIX_S1_AMPL 1.0
#define KASIX_S2_AMPL 1.2

void kasixProportionalTrace(void) {
    uint16_t kasixSRVal1, kasixSRVal2;
    uint16_t kasixSRWidth1, kasixSRWidth2;
    kasixSRWidth1 = kasixSH1 - kasixSL1;
    kasixSRWidth2 = kasixSH2 - kasixSL2;
    double kasixPTVal1, kasixPTVal2, kasixPVal;
    double kasixPFBDelta;
    while (1) {
        kasixSRVal1 = analogScanP(0);
        kasixSRVal2 = analogScanP(1);
        // 1. ZERO align
        if (kasixSRVal1 < kasixSL1)kasixSRVal1 = kasixSL1; // floor
        if (kasixSRVal2 < kasixSL2)kasixSRVal2 = kasixSL2; // floor
        kasixSRVal1 -= kasixSL1;
        kasixSRVal2 -= kasixSL2;
        // 2. WIDTH align
        kasixPTVal1 = (double) kasixSRVal1 / (double) kasixSRWidth1;
        kasixPTVal2 = (double) kasixSRVal2 / (double) kasixSRWidth2;
        kasixPVal = (kasixPTVal2 * KASIX_S2_AMPL) - (kasixPTVal1 * KASIX_S1_AMPL);
        // 3. feedback control
        uint16_t kasixPTControlVal = (uint16_t) ((double) kasixPVal * KASIX_PT_GAIN);
        if (kasixPTControlVal > 0) {
            PWM3_LoadDutyValue(KASIX_MAXTRACE);
            PWM4_LoadDutyValue(KASIX_MAXTRACE - __MAX(KASIX_MAXTRACE, kasixPTControlVal));
        } else {
            PWM3_LoadDutyValue(KASIX_MAXTRACE + __MIN(-1 * KASIX_MAXTRACE, kasixPTControlVal));
            PWM4_LoadDutyValue(KASIX_MAXTRACE);
        }
        anmLine((uint16_t) ((kasixPTVal2 - kasixPTVal1)*-4.0), true);
    }
}

#define KASIX_PTOB_CEIL KASIX_MAXTRACE
#define KASIX_PTOB_THR 0xeff
#define KASIX_PTOB_INR 0x07
#define KASIX_BIAS_LOW 64
#define KASIX_PTOB_DCR 0x01
#define KASIX_SIGNAL_THR 0x01

uint16_t kasixSignalDetect = 0;

uint16_t kasixPTOBonus = 0, kasixPTOBThr = 0;

bool kasixPhase1 = 0, kasixPhase2 = 0;

void kasixProportionalTraceOneside(void) {
    uint16_t kasixSRVal;
    uint16_t kasixSRWidth;
    kasixSignalDetect = 0;
    kasixSRWidth = kasixSH1 - kasixSL1;
    double kasixPVal;
    while (!kasixPhase1) {
        kasixPTOBThr++;
        if (kasixPTOBThr > KASIX_PTOB_THR) {
            kasixPTOBonus++;
            kasixPTOBThr = 0;
            onR();
        }
        if (kasixPTOBonus > KASIX_PTOB_CEIL) {
            kasixPTOBonus = KASIX_PTOB_CEIL;
        }
        kasixSRVal = analogScanP(0);
        // 1. ZERO align
        if (kasixSRVal < kasixSL1)kasixSRVal = kasixSL1; // floor
        kasixSRVal -= kasixSL1;
        // 2. WIDTH align
        kasixPVal = (double) kasixSRVal / (double) kasixSRWidth;
        // 3. feedback control
        int16_t kasixPTControlVal = (uint16_t) ((double) (kasixPVal - 0.5) * KASIX_PT_GAIN);

        if (kasixPTControlVal < -0.2) {
            if (kasixPTOBonus != 0) {
                kasixPTOBonus--;
            }
            kasixPTOBThr = 0;
            onG();
        }

        PWM3_LoadDutyValue(((int16_t) __MIN(KASIX_MAXTRACE, __MAX(0, KASIX_MAXTRACE - kasixPTControlVal - kasixPTOBonus))));
        PWM4_LoadDutyValue(((int16_t) __MIN(KASIX_MAXTRACE, __MAX(0, KASIX_MAXTRACE + kasixPTControlVal))));
        anmLine((uint16_t) (kasixPVal*-4.0), true);
        if (digitalScanP(0)) {
            kasixSignalDetect += KASIX_PTOB_INR;
            if (kasixSignalDetect > KASIX_SIGNAL_THR) {
                while (1) {
                    anmRot(0x3456, 0x1a2c);
                }
            }
        } else {
            if (kasixSignalDetect) kasixSignalDetect = 1;
            kasixSignalDetect -= KASIX_PTOB_DCR;
        }
    }
    return;
}

void kasixGoLaneChange(void) {
    kasixPhase1 = true;

    return;
}

void kasixProportionalTraceOnesideRside(void) {
    uint16_t kasixSRVal;
    uint16_t kasixSRWidth;
    kasixSignalDetect = 0;
    kasixSRWidth = kasixSH2 - kasixSL2;
    double kasixPVal;
    while (!kasixPhase1) {
        kasixPTOBThr++;
        if (kasixPTOBThr > KASIX_PTOB_THR) {
            kasixPTOBonus++;
            kasixPTOBThr = 0;
            onR();
        }
        if (kasixPTOBonus > KASIX_PTOB_CEIL) {
            kasixPTOBonus = KASIX_PTOB_CEIL;
        }
        kasixSRVal = analogScanP(1);
        // 1. ZERO align
        if (kasixSRVal < kasixSL1)kasixSRVal = kasixSL1; // floor
        kasixSRVal -= kasixSL2;
        // 2. WIDTH align
        kasixPVal = (double) kasixSRVal / (double) kasixSRWidth;
        // 3. feedback control
        int16_t kasixPTControlVal = (uint16_t) ((double) (kasixPVal - 0.5) * KASIX_PT_GAIN);

        if (kasixPTControlVal < -0.2) {
            if (kasixPTOBonus != 0) {
                kasixPTOBonus--;
            }
            kasixPTOBThr = 0;
            onG();
        }

        PWM3_LoadDutyValue(((int16_t) __MIN(KASIX_MAXTRACE, __MAX(0, KASIX_MAXTRACE + kasixPTControlVal))));
        PWM4_LoadDutyValue(((int16_t) __MIN(KASIX_MAXTRACE, __MAX(0, KASIX_MAXTRACE - kasixPTControlVal - kasixPTOBonus))));
        anmLine((uint16_t) (kasixPVal*-4.0), true);
        //        if (analogScanP(0) >= kasixSH1 - KASIX_BIAS_LOW && analogScanP(1) >= kasixSH2 - KASIX_BIAS_LOW) {
        changeDigitalThr(kasixSDThr[0]);
        if (digitalScanP(0)) {
            return;
            //            kasixSignalDetect++;
            //            if (kasixSignalDetect > KASIX_SIGNAL_THR) {
            //                return;
            //                //                TMR5_SetInterruptHandler(kasixGoLaneChange); // 500ms
            //            }
        } else {
            if (kasixSignalDetect) kasixSignalDetect = 1;
            kasixSignalDetect--;
        }
    }
    return;
}

bool kasixLaneChangeFlag = false, kasixFinder = false;

void kasixEnableFind(void) {
    kasixFinder = true;

    return;
}

void kasixLaneChange(void) {
    anmRot(0b0011001100110011, ~0b0011001100110011);
    PWM3_LoadDutyValue(KASIX_MAXTRACE);
    PWM4_LoadDutyValue(0);
    __delay_ms(300);
    kasixFinder = false;
    TMR5_Reload();
    TMR5_SetInterruptHandler(kasixEnableFind);
    while (!(analogScanP(1) < (kasixSL1 + KASIX_BIAS_LOW)) && !kasixFinder) {
        PWM3_LoadDutyValue(KASIX_MAXTRACE);
        PWM4_LoadDutyValue(KASIX_MAXTRACE);
    }
    return;
}

#define KASIX_SUPERCURVE_CURVER 4
#define KASIX_SUPERCURVE_TIMEMS 500

void kasixSuperCurve(void) {
    kasixFinder = false;
    TMR5_SetInterruptHandler(kasixEnableFind); // 500ms
    uint16_t kasixSRVal;
    uint16_t kasixSRWidth;
    kasixSRWidth = kasixSH1 - kasixSL1;
    double kasixPVal;

    while ((analogScanP(1) < kasixSL1 + KASIX_BIAS_LOW) && kasixFinder) {
        PWM3_LoadDutyValue(KASIX_SUPERCURVE_CURVER);
        PWM3_LoadDutyValue(KASIX_MAXTRACE);
    }

    return;
}

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>[[[[[[[[[[[[[[[[Test]]]]]]]]]]]]]]]]<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

#define KASIX_TEST_PWM1 15
#define KASIX_TEST_PWM2 15

void kasixMotorTester(void) {
    while (1) {
        PWM3_LoadDutyValue(KASIX_TEST_PWM1);
        PWM4_LoadDutyValue(KASIX_TEST_PWM2);
    }
    return;
}

bool kasixMemoryTestWait = false;

void kasixMemoryTestAgree(void) {
    kasixMemoryTestWait = false;
    return;
}

void kasixMemoryTestDisplay(void) {

}

void kasixMemoryTest(void) {
    uint8_t kasixMemAddr = 0;
    while (1) {
        uint16_t kasixMemData = FLASH_ReadWord(kasixMemAddr);
        kasixMemoryTestWait = true;
        SW1SetFunction(kasixMemoryTestAgree);
        SW2SetFunction(NULL);
        while (kasixMemoryTestWait) {
            anmMeter(kasixMemData, true);
            if (!SW2_PORT) {
                kasixMemData++;
                tone(3450);
                __delay_ms(50);
                noTone();
            }
        }
        uint16_t kasixMemoryBuf[ERASE_FLASH_BLOCKSIZE];

        FLASH_WriteWord(kasixMemAddr, kasixMemoryBuf, kasixMemData);
        kasixMemAddr += 2;
        kasixMemAddr %= 128;
    }
    return;
}