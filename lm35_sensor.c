/******************************************************************************
 *
 * Module: Temperature Sensor
 *
 * File Name: lm35_sensor.c
 *
 * Author: Basma Walid
 *
 * Date Created : Oct 6,2022
 *
 * Description: Source file for the LM35 Temperature Sensor driver
 *
 *******************************************************************************/

#include "lm35_sensor.h"
#include "adc.h" /* For Using The configured ADC Voltage */

/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 */
uint8 LM35_getTemperature(void)
{
	uint8 temp_value = 0;

	uint16 adc_value = 0;

	/* Read ADC channel where the temperature sensor is connected */
	adc_value = ADC_readChannel(SENSOR_CHANNEL_ID);

	/* Calculate the temperature from the ADC value*/
	temp_value = (uint8)(((uint32)adc_value*SENSOR_MAX_TEMPERATURE*ADC_INTERNAL_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*SENSOR_MAX_VOLT_VALUE));

	return temp_value;
}

