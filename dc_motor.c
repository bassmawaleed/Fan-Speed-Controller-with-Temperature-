/******************************************************************************
 *
 * Module: Dc_Motor
 *
 * File Name: dc_motor.h
 *
 * Author: Basma Walid
 *
 * Date Created : Oct 6,2022
 *
 *
 * Description: source file for the Dc Motor driver
 *
 *
 *******************************************************************************/
#include "dc_motor.h"
#include "gpio.h"
#include "pwm.h"

void DcMotor_Init(void)
{
	 /*Setting up the direction for the pins of the motor
	 * PB0(B)-->OUTPUT PIN
	 * PB1(A)-->OUTPUT PIN
	 * Clearing both pins at the beginning to stop the dc-motor
	 * CLEAR PB0
	 * CLEAR PB1
	 */
	GPIO_setupPinDirection(PORTB_ID, PIN0_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(PORTB_ID, PIN1_ID, PIN_OUTPUT);
	GPIO_writePin(PORTB_ID , PIN0_ID,LOGIC_LOW);
	GPIO_writePin(PORTB_ID , PIN1_ID,LOGIC_LOW);
}
void DcMotor_Rotate(DcMotor_State state,uint8 speed)
{
	#if ( speed>100 | speed <0 )
	{
		#error "Speed Value isn't correct "
	}
	#endif

	/* First : Handling the state of the motor */
	if(state == DcMotor_noMotion )
	{
		/* A --> 0 , B--> 0 */
		GPIO_writePin(PORTB_ID , PIN0_ID,LOGIC_LOW);
		GPIO_writePin(PORTB_ID , PIN1_ID,LOGIC_LOW);
	}
	else if (state == DcMotor_Clockwise)
	{
		/* A--> 1 , B--> 0 */
		GPIO_writePin(PORTB_ID , PIN0_ID,LOGIC_HIGH);
		GPIO_writePin(PORTB_ID , PIN1_ID,LOGIC_LOW);
	}
	else if (state == DcMotor_AntiClockwise)
	{
		/* A -->0 , B-->1 */
		GPIO_writePin(PORTB_ID , PIN0_ID,LOGIC_LOW);
		GPIO_writePin(PORTB_ID , PIN1_ID,LOGIC_HIGH);
	}

	/* Second : Handling the Speed of the motor */
		PWM_Timer0_Start(speed);

}
