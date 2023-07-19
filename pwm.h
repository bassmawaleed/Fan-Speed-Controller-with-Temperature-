/******************************************************************************
 *
 * Module: PWM
 *
 * File Name: pwm.h
 *
 * Author: Basma Walid
 *
 * Date Created : Oct 6,2022
 *
 * Description: Header file for the PWM driver
 *
 *******************************************************************************/

#ifndef PWM_H_
#define PWM_H_

#include "std_types.h"

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*Description:
 * The function responsible for triggering the Timer0 with the PWM Mode.
 */
void PWM_Timer0_Start(uint8 set_duty_cycle);
#endif /* PWM_H_ */
