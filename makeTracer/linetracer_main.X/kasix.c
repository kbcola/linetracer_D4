#include "kasix.h"

// variables

// flag
bool kasixPhase1Flag = false;
bool kasixPhase2Flag = false;
bool kasixPhase3Flag = false;

bool kasixSW1Flag = false;
bool kasixSW2Flag = false;

// threshold
uint16_t calibedDataHigh[6];
uint16_t calibedDataLow[6];

// ################################################################################################################################
// ################################################################################################################################
// ######################################################## Initialize ############################################################
// ################################################################################################################################
// ################################################################################################################################

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

// ################################################################################################################################
// ################################################################################################################################
// ########################################################## Calibed #############################################################
// ################################################################################################################################
// ################################################################################################################################

void kasixCaliSWPushed(void) {
    kasixSW1Flag = true;
    kasixSW2Flag = true;
    return;
}

void kasixCalibration(void) {
    kasixSW1Flag = false;
    kasixSW2Flag = false;
    SW1SetFunction(kasixCaliSWPushed);
    SW2SetFunction(kasixCaliSWPushed);
    while (!kasixSW1Flag) {
        anmMeter(analogScanP(0), true);
    }
    calibedDataHigh[0] = analogScanP(0);
    calibedDataHigh[1] = analogScanP(1);
    for (uint8_t kasixDigitalPort = 0; kasixDigitalPort < 4; kasixDigitalPort++) {
        uint16_t kasixTestThr = 0;
        DAC1_Load10bitInputData(0);
        while (!digitalScanP(kasixDigitalPort)) {
            kasixTestThr++;
            DAC1_Load10bitInputData(kasixTestThr);
        }
        calibedDataHigh[kasixDigitalPort + 2] = kasixTestThr;
    }
    tone(1000);
    __delay_ms(500);
    noTone();

    kasixSW1Flag = false;
    kasixSW2Flag = false;
    while (!kasixSW1Flag) {
        anmMeter(analogScanP(0), true);
    }
    calibedDataLow[0] = analogScanP(0);
    calibedDataLow[1] = analogScanP(1);
    for (uint8_t kasixDigitalPort = 0; kasixDigitalPort < 4; kasixDigitalPort++) {
        uint16_t kasixTestThr = 0;
        DAC1_Load10bitInputData(0);
        __delay_ms(1);
        while (!digitalScanP(kasixDigitalPort)) {
            DAC1_Load10bitInputData(kasixTestThr);
            kasixTestThr++;
        }
        calibedDataLow[kasixDigitalPort + 2] = kasixTestThr;
    }
    tone(1000);
    __delay_ms(500);
    noTone();
    return;
}

void kasixCalibrationCheck(void) {
    for (uint8_t kasixArraySpecification = 0; kasixArraySpecification < 6; kasixArraySpecification++) {
        anmMeter(calibedDataHigh[kasixArraySpecification], true);
        __delay_ms(500);
        anmMeter(calibedDataLow[kasixArraySpecification], true);
        __delay_ms(500);
    }
    tone(1000);
    __delay_ms(500);
    noTone();
    return;
}


// ################################################################################################################################
// ################################################################################################################################
// ########################################################### Trace ##############################################################
// ################################################################################################################################
// ################################################################################################################################

//void kasixPTrace(void) {
//    uint16_t kasixSRVal;
//    uint16_t kasixSRWidth;
//    kasixSRWidth = kasixSH1 - kasixSL1;
//    double kasixPVal;
//    while (!kasixPhase1) {
//        kasixPTOBThr++;
//        if (kasixPTOBThr > KASIX_PTOB_THR) {
//            kasixPTOBonus++;
//            kasixPTOBThr = 0;
//            onR();
//        }
//        if (kasixPTOBonus > KASIX_PTOB_CEIL) {
//            kasixPTOBonus = KASIX_PTOB_CEIL;
//        }
//        kasixSRVal = analogScanP(0);
//        // 1. ZERO align
//        if (kasixSRVal < kasixSL1)kasixSRVal = kasixSL1; // floor
//        kasixSRVal -= kasixSL1;
//        // 2. WIDTH align
//        kasixPVal = (double) kasixSRVal / (double) kasixSRWidth;
//        // 3. feedback control
//        int16_t kasixPTControlVal = (uint16_t) ((double) (kasixPVal - 0.5) * KASIX_PT_GAIN);
//
//        if (kasixPTControlVal < -0.2) {
//            if (kasixPTOBonus != 0) {
//                kasixPTOBonus--;
//            }
//            kasixPTOBThr = 0;
//            onG();
//        }
//
//        PWM3_LoadDutyValue(((int16_t) __MIN(KASIX_MAXTRACE, __MAX(0, KASIX_MAXTRACE - kasixPTControlVal - kasixPTOBonus))));
//        PWM4_LoadDutyValue(((int16_t) __MIN(KASIX_MAXTRACE, __MAX(0, KASIX_MAXTRACE + kasixPTControlVal))));
//        anmLine((uint16_t) (kasixPVal*-4.0), true);
//    }
//    return;
//}


// ################################################################################################################################
// ################################################################################################################################
// ########################################################### Trace ##############################################################
// ################################################################################################################################
// ################################################################################################################################

void kasixTestSensor(bool digAnn, uint8_t port) {
    if (digAnn) {
        anmMeter(analogScanP(port), true);
    } else {
        uint16_t kasixTestThr = 0;
        while (digitalScanP(port)) {
            DAC1_Load10bitInputData(kasixTestThr);
            kasixTestThr++;
        }
        anmMeter(kasixTestThr, true);
    }
}