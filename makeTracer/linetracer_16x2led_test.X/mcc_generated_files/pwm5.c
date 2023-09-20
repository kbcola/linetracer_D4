/**
  PWM5 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    pwm5.c

  @Summary
    This is the generated driver implementation file for the PWM5 driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides implementations for driver APIs for PWM5.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC16F1778
        Driver Version    :  2.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.36 and above or later
        MPLAB             :  MPLAB X 6.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

/**
  Section: Included Files
*/

#include <xc.h>
#include "pwm5.h"

/**
  Section: PWM5 APIs
*/

void PWM5_Initialize(void)
{
    // set the PWM5 to the options selected in the User Interface

     //PHIE disabled; DCIE disabled; OFIE disabled; PRIE disabled; 
    PWM5INTE = 0x00;

     //PHIF cleared; OFIF cleared; DCIF cleared; PRIF cleared; 
    PWM5INTF = 0x00;

     //PS No_Prescalar; CS FOSC; 
    PWM5CLKCON = 0x00;

     //LDS LD6_trigger; LDT disabled; LDA do_not_load; 
    PWM5LDCON = 0x01;

     //OFM independent_run; OFS OF6_match; OFO match_incrementing; 
    PWM5OFCON = 0x01;

     //PWM5PHH 0; 
    PWM5PHH = 0x00;

     //PWM5PHL 0; 
    PWM5PHL = 0x00;

     //PWM5DCH 0; 
    PWM5DCH = 0x00;

     //PWM5DCL 0; 
    PWM5DCL = 0x00;

     //PWM5PRH 0; 
    PWM5PRH = 0x00;

     //PWM5PRL 3; 
    PWM5PRL = 0x03;

     //PWM5OFH 0; 
    PWM5OFH = 0x00;

     //PWM5OFL 1; 
    PWM5OFL = 0x01;

     //PWM5TMRH 0; 
    PWM5TMRH = 0x00;

     //PWM5TMRL 0; 
    PWM5TMRL = 0x00;

     //MODE standard_PWM; POL active_hi; EN enabled; 
    PWM5CON = 0x80;

}    


void PWM5_Start(void)
{
    PWM5CONbits.EN = 1;		
}

void PWM5_Stop(void)
{
    PWM5CONbits.EN = 0;		
}

bool PWM5_CheckOutputStatus(void)
{
    return (PWM5CONbits.OUT);		
}

void PWM5_LoadBufferSet(void)
{
    PWM5LDCONbits.LDA = 1;		
}

void PWM5_PhaseSet(uint16_t phaseCount)
{
    PWM5PHH = (phaseCount>>8);        //writing 8 MSBs to PWMPHH register
    PWM5PHL = (phaseCount);           //writing 8 LSBs to PWMPHL register
}

void PWM5_DutyCycleSet(uint16_t dutyCycleCount)
{
    PWM5DCH = (dutyCycleCount>>8);	//writing 8 MSBs to PWMDCH register
    PWM5DCL = (dutyCycleCount);	//writing 8 LSBs to PWMDCL register		
}

void PWM5_PeriodSet(uint16_t periodCount)
{
    PWM5PRH = (periodCount>>8);	//writing 8 MSBs to PWMPRH register
    PWM5PRL = (periodCount);	//writing 8 LSBs to PWMPRL register		
}

void PWM5_OffsetSet(uint16_t offsetCount)
{
    PWM5OFH = (offsetCount>>8);	//writing 8 MSBs to PWMOFH register
    PWM5OFL = (offsetCount);	//writing 8 LSBs to PWMOFL register		
}

uint16_t PWM5_TimerCountGet(void)
{
    return ((uint16_t)((PWM5TMRH<<8) | PWM5TMRL));       		
}

bool PWM5_IsOffsetMatchOccured(void)
{
    return (PWM5INTFbits.OFIF);		
}

bool PWM5_IsPhaseMatchOccured(void)
{
    return (PWM5INTFbits.PHIF);	
}

bool PWM5_IsDutyCycleMatchOccured(void)
{
    return (PWM5INTFbits.DCIF);		
}

bool PWM5_IsPeriodMatchOccured(void)
{
    return (PWM5INTFbits.PRIF);		
}

/**
 End of File
*/


