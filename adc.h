 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Author: Basma Walid
 *
 * Date Created : Oct 6,2022
 *
 *
 * Description: header file for the ATmega32 ADC driver
 *
 *
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_RESERVED_VOLT_VALUE  0
#define ADC_REF_VOLT_VALUE   5
#define ADC_INTERNAL_VOLT_VALUE   2.56


#define ADC_PRESCALER_1 2
#define ADC_PRESCALER_2 4
#define ADC_PRESCALER_3 8
#define ADC_PRESCALER_4 16
#define ADC_PRESCALER_5 32
#define ADC_PRESCALER_6 64
#define ADC_PRESCALER_7 128


/*******************************************************************************
 *                                Defined data types                             *
 *******************************************************************************/

/*
 * [enum Name] = ADC_ReferenceVolatge
 * [enum Description]:
 * This enum is used to assign a value to ADC voltage
 */

typedef enum{
	/* First Member: AREF option -->REFS1=0  REFS0=0 */
	/* Second Member : AVCC Voltage -->REFS1=0  REFS0=1 */
	/* Third Member : Reserved Voltage -->REFS1=1  REFS0=0 */
	/* Fourth Member : Internal Voltage -->REFS1=1  REFS0=1 */
	REFERENCE_VOLTAGE,
	AVCC_Voltage,
	RESERVED_VOLTAGE,
	INTERNAL_VOLTAGE
}ADC_ReferenceVolatge;

/*
 * [enum Name] = ADC_ReferenceVolatge
 * [enum Description]:
 * This enum is used to assign a value to Prescaler
 */
typedef enum{
	/* First Member : N = 2 --> ADPS2=0  ADPS1=0 ADPS0=1 */
	/* Second Member : N = 4 --> ADPS2=0  ADPS1=1 ADPS0=0 */
	/* Third Member : N = 8 --> ADPS2=0  ADPS1=1 ADPS0=1 */
	/* Fourth Member : N = 16 --> ADPS2=1  ADPS1=0 ADPS0=0 */
	/* Fifth Member : N = 32  --> ADPS2=1  ADPS1=0 ADPS0=1*/
	/* Sixth Member : N = 64  --> ADPS2=1  ADPS1=1 ADPS0=0*/
	/* Seventh Member : N = 128 --> ADPS2=1  ADPS1=1 ADPS0=1 */

	PRESCALER_1=1,
	PRESCALER_2,
	PRESCALER_3,
	PRESCALER_4,
	PRESCALER_5,
	PRESCALER_6,
	PRESCALER_7
}ADC_Prescaler;


/*
 * [Structure Name] = ADC_ConfigType
 * [Structure Description]:
 * This structure is used for setting up
 * values for the ADC reference voltage
 * and prescaler
 */
typedef struct{
	/* This member describes the ADC reference voltage */
	ADC_ReferenceVolatge ref_volt;

	/* This member describes the prescaler for the ADC */
	ADC_Prescaler prescaler;
}ADC_ConfigType;


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initializing the ADC driver.
 */
void ADC_init(const ADC_ConfigType * Config_Ptr);

/*
 * Description :
 * Function responsible for reading analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
