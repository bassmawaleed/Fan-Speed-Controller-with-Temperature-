/******************************************************************************
 *
 * Module: PWM
 *
 * File Name: pwm.c
 *
 * Author: Basma Walid
 *
 * Date Created : Oct 6,2022
 *
 * Description: Source file for the PWM driver
 *
 *******************************************************************************/

#include "pwm.h"
#include "dc_motor.h" /* For the duty cycle shared global variable */
#include<avr/io.h>
#include "gpio.h"

void PWM_Timer0_Start(uint8 set_duty_cycle)
{
	/* Set Timer Initial value */
	TCNT0 = 0;

	/* Set Compare Value */
	OCR0  = set_duty_cycle * 255  / 100 ;

	/* set PB3/OC0 as output pin --> pin where the PWM signal is generated from MC. */
	GPIO_setupPinDirection(PORTB_ID,PIN3_ID,PIN_OUTPUT);

	/* Configure timer control register
	 * 1. Fast PWM mode FOC0=0
	 * 2. Fast PWM Mode WGM01=1 & WGM00=1
	 * 3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1
	 * 4. clock = F_CPU/8 CS00=0 CS01=1 CS02=0
	 */
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);
}


