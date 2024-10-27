/*
 * delay.c
 *
 *  Created on: May 9, 2023
 *      Author: Lenovo
 */

#ifndef DELAY_C_
#define DELAY_C_

#include <stdint.h>
#include <stdbool.h>

#include "inc/tm4c123gh6pm.h"
#include "DELAY.h"

void delay(uint32_t delay_ms) {
    // Enable Timer0 module
    SYSCTL_RCGCTIMER_R |= SYSCTL_RCGCTIMER_R0;

    // Disable the Timer0A module
    TIMER0_CTL_R &= ~TIMER_CTL_TAEN;

    // Configure Timer0A as a periodic timer
    TIMER0_CFG_R = TIMER_CFG_32_BIT_TIMER;
    TIMER0_TAMR_R = TIMER_TAMR_TAMR_PERIOD;

    // Set the timer interval
    TIMER0_TAILR_R = (16000 - 1);

    // Clear the timer interrupt flag and reload the timer
    TIMER0_ICR_R = TIMER_ICR_TATOCINT;
    TIMER0_CTL_R |= TIMER_CTL_TAEN;
    uint32_t i;
    // Wait for the specified amount of time
    for (  i = 0; i < delay_ms; i++) {
        while (!(TIMER0_RIS_R & TIMER_RIS_TATORIS));
        TIMER0_ICR_R |= TIMER_ICR_TATOCINT;
    }
}



#endif /* DELAY_C_ */
