#include "motordrive.h"

void motorSetup(void) {
    R_SEL1_PORT = 0;
    R_SEL2_PORT = 0;
    L_SEL1_PORT = 0;
    L_SEL2_PORT = 0;
    return;
}

void steer(uint16_t left, uint16_t right) {
    L_SEL1_PORT = 1;
    L_SEL2_PORT = 0;
    R_SEL1_PORT = 1;
    R_SEL2_PORT = 0;
    PWM3_LoadDutyValue(left);
    PWM4_LoadDutyValue(right);
}
