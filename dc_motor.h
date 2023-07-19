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
 * Description: header file for the Dc Motor driver
 *
 *
 *******************************************************************************/

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "std_types.h"


/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define DcMotor_noMotion 0 /* No Motion */
#define DcMotor_Clockwise 1 /* Motor motion -->Clockwise */
#define DcMotor_AntiClockwise 2 /* Motor motion -->AntiClockwise */

typedef uint8 DcMotor_State ;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/* Description:
 *Function that Initializes the motor state
 *and responsible for setup the direction for the two motor pins through the GPIO driver.
 *It also Stop at the DC-Motor at the beginning through the GPIO driver
 */
void DcMotor_Init(void);



/* Description
 * function responsible for rotating the DC Motor CW/ or A-CW
 * or stopping the motor based on the DcMotor_State value.
 */
void DcMotor_Rotate(DcMotor_State state,uint8 speed);

#endif /* DC_MOTOR_H_ */
