/******************************************************************************
 *
 * File Name: main.c
 *
 * Author: Basma Walid
 *
 * Date Created : Oct 6,2022
 *
 * Description: File that has Main Function
 *
 *******************************************************************************/
#include "adc.h"
#include "common_macros.h"
#include "dc_motor.h"
#include "gpio.h"
#include "lcd.h"
#include "lm35_sensor.h"
#include "pwm.h"
#include "std_types.h"
#include <util/delay.h>



int main()
{
	uint8 temp_value; /* Temperature Value as read by the Temperature Sensor LM35 */
	ADC_ConfigType c1 ; /* ADC Configuration Structure */

	 /* Assigning values for the ADC configuration
	 * Reference Voltage and Prescaler */
	c1.ref_volt =INTERNAL_VOLTAGE;
	c1.prescaler=PRESCALER_3;

	/* Calling the initialization function of ADC
	 * and passing the configuration structure to it */
	ADC_init(&c1);

	/* Calling the Dc Motor Initialization Structure */
	DcMotor_Init();

	/* Calling the LCD initialization Function */
	LCD_init();

	/* Clearing the LCD Screen */
	LCD_clearScreen();
	while(1)
	{
		/* Reading the temperature value */
		temp_value=LM35_getTemperature();
		if(temp_value < 30)
		{	/*Turn off Fan */
			DcMotor_Rotate(DcMotor_noMotion,0);

			/* Printing the fan condition and the temperature on the LCD */
			LCD_displayStringRowColumn(0,4,"Fan is OFF");
			LCD_displayStringRowColumn(1,4,"Temp = ");
			LCD_intgerToString(temp_value);
			LCD_displayString(" C");
		}
		else if (temp_value >= 120)
		{
			/*Turn on Fan with 100% of its maximum speed*/
			DcMotor_Rotate(DcMotor_Clockwise,100);

			/* Printing the fan condition and the temperature on the LCD */
			LCD_displayStringRowColumn(0,4,"Fan is ON ");
			LCD_displayStringRowColumn(1,4,"Temp = ");
			LCD_intgerToString(temp_value);
			LCD_displayString(" C");
		}
		else if (temp_value >=90)
		{
			/*Turn on Fan with 90% of its maximum speed*/
			DcMotor_Rotate(DcMotor_Clockwise,75);

			/* Printing the fan condition and the temperature on the LCD */
			LCD_displayStringRowColumn(0,4,"Fan is ON ");
			LCD_displayStringRowColumn(1,4,"Temp = ");
			LCD_intgerToString(temp_value);
			LCD_displayString(" C");
		}
		else if (temp_value >= 60)
		{
			/*Turn on Fan with 50% of its maximum speed */
			DcMotor_Rotate(DcMotor_Clockwise,50);

			/* Printing the fan condition and the temperature on the LCD */
			LCD_moveCursor(0,4);
			LCD_displayString("Fan is ON ");
			LCD_displayStringRowColumn(1,4,"Temp = ");
			LCD_intgerToString(temp_value);
			LCD_displayString(" C");
		}
		else if (temp_value >= 30)
		{
			/*Turn on Fan with 25% of its maximum speed */
			DcMotor_Rotate(DcMotor_Clockwise,25);

			/* Printing the fan condition and the temperature on the LCD */
			LCD_displayStringRowColumn(0,4,"Fan is ON ");
			LCD_displayStringRowColumn(1,4,"Temp = ");
			LCD_intgerToString(temp_value);
			LCD_displayString(" C");
		}
	}
}
