/**
  PWM5 Generated Driver API Header File

  @Company
    Microchip Technology Inc.

  @File Name
    pwm5.h

  @Summary
    This is the generated header file for the PWM5 driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for PWM5.
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

#ifndef PWM5_H
#define PWM5_H

/**
  Section: Included Files
*/

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif

/**
  Section: PWM Module APIs
*/

/**
  @Summary
    Initializes the PWM5

  @Description
    This routine initializes the Initializes the PWM5.
    This routine must be called before any other PWM routine is called.
    This routine should only be called once during system initialization.

  @Preconditions
    None

  @Param
    None

  @Returns
    None

  @Comment
    

  @Example
    <code>
    
    </code>
*/
void PWM5_Initialize(void);

/**
  @Summary
    This function starts the PWM5.

  @Description
    This function starts the PWM5 operation.
    This function must be called after the initialization of PWM5.

  @Preconditions
    Initialize  the PWM5 before calling this function.

   @Param
    None

  @Returns
    None

  @Example
    <code>
    // Initialize PWM5 module

    // Start PWM5
    PWM5_Start();

    // Do something else...
    </code>
*/
void PWM5_Start(void);

/**
  @Summary
    This function stops the PWM5.

  @Description
    This function stops the PWM5 operation.
    This function must be called after the start of PWM5.

  @Preconditions
    Initialize  the PWM5 before calling this function.

  @Param
    None

  @Returns
    None

  @Example
    <code>
    // Initialize PWM5 module

    // Start PWM5
    PWM5_StartTimer();

    // Do something else...

    // Stop PWM5;
    PWM5_Stop();
    </code>
*/
void PWM5_Stop(void);


/**
  @Summary
    This function used to check output status of PWM5.

  @Description
    Check output status of PWM5 as High or Low.    

  @Preconditions
    Start the PWM5 before calling this function.

  @Param
    None

  @Returns
    true - Output High.
	false - Output Low.

  @Example
    <code>
    
    </code>
*/
bool PWM5_CheckOutputStatus(void);

/**
  @Summary
    This function is used to load buffer of PWM5 at the end of period.

  @Description
    load buffer of PWM5 at the end of period.

  @Preconditions
     Initialize  the PWM5 before calling this function.

  @Param
    None

  @Returns
    None

  @Example
    <code>
    
    </code>
*/
void PWM5_LoadBufferSet(void);

/**
  @Summary
    Load required 16 bit phase count

  @Description
    Set the expected phase count

  @Preconditions
    None

  @Param
    Pass 16 bit phase count

  @Returns
    None

  @Example
    <code>
    
    </code>
*/
void PWM5_PhaseSet(uint16_t phaseCount);

/**
  @Summary
    Load required 16 bit Duty Cycle

  @Description
    Set the expected Duty Cycle

  @Preconditions
    None

  @Param
    Pass 16 bit Duty Cycle

  @Returns
    None

  @Example
    <code>
    
    </code>
*/
void PWM5_DutyCycleSet(uint16_t dutyCycleCount);

/**
  @Summary
    Load required 16 bit Period

  @Description
    Set the expected Period

  @Preconditions
    None

  @Param
    Pass 16 bit Period

  @Returns
    None

  @Example
    <code>
    
    </code>
*/
void PWM5_PeriodSet(uint16_t periodCount);

/**
  @Summary
    Load required 16 bit Offset

  @Description
    Set the expected Offset

  @Preconditions
    None

  @Param
    Pass 16 bit Offset

  @Returns
    None

  @Example
    <code>
    
    </code>
*/
void PWM5_OffsetSet(uint16_t offsetCount);

/**
  @Summary
    Read measured Timer count

  @Description    
    Read the measured Timer count
 * 
  @Preconditions
    None

  @Param
    None

  @Returns
    Return 16 bit Timer count

  @Example
    <code>
    
    </code>
*/
uint16_t PWM5_TimerCountGet(void);

/**
  @Summary
    Returns status of Offset interrupt flag bit (OFIF ).

  @Description    
    When PWMTMR = PWMOF value offset flag sets.

  @Preconditions
    None

  @Param
    None

  @Returns
    true - PWMTMR >= PWMOF value
    false - PWMTMR < PWMOF value

  @Example
    <code>
    
    </code>
*/
bool PWM5_IsOffsetMatchOccured(void);

/**
  @Summary
    Returns status of Phase interrupt flag bit (PHIF ).

  @Description    
    When PWMTMR = PWMPH value, Phase flag sets.

  @Preconditions
    None

  @Param
    None

  @Returns
    true - PWMTMR count is >= PWMPH value
    false - PWMTMR count is < PWMPH value

  @Example
    <code>
    
    </code>
*/
bool PWM5_IsPhaseMatchOccured(void);

/**
  @Summary
    Returns status of DutyCycle interrupt flag bit (DCIF ).

  @Description    
    When PWMTMR = PWMDC value DutyCycle flag sets.

  @Preconditions
    None

  @Param
    None

  @Returns
    true - PWMTMR count is >= PWMDC value
    false - PWMTMR count is < PWMDC value

  @Example
    <code>
    
    </code>
*/
bool PWM5_IsDutyCycleMatchOccured(void);

/**
  @Summary
    Returns status of Period interrupt flag bit (PRIF ).

  @Description    
    When PWMTMR = PWMPR value offset flag sets.

  @Preconditions
    None

  @Param
    None

  @Returns
    true - PWMTMR count is >= PWMPR value
    false - PWMTMR count is < PWMPR value

  @Example
    <code>
    
    </code>
*/
bool PWM5_IsPeriodMatchOccured(void);

#endif	/* PWM5_H */
/**
 End of File
*/
