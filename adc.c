 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.c
 *
 * Author: Basma Walid
 *
 * Date Created : Oct 6,2022
 *
 *
 * Description: source file for the ATmega32 ADC driver
 *
 *
 *******************************************************************************/

#include "avr/io.h" /* To use the ADC Registers */
#include "adc.h"
#include "common_macros.h" /* To use the macros like SET_BIT */

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void ADC_init(const ADC_ConfigType * Config_Ptr)
{
	/* ADMUX Register Bits Description:
	 * 	 * *********************** VOLTAGES CONFIGURATION *********************** *
	 * REFS1:0 = 00 to choose to connect external reference voltage by input this voltage through AREF pin
	 * REFS1:0 = 01 to choose to connect external reference voltage by input this voltage through AVCC pin
	 * REFS1:0 = 10 Reserved
	 * REFS1:0 = 11 Internal 2.56 V voltage reference
	 * ADLAR   = 0 right adjusted
	 * MUX4:0  = 00000 to choose channel 0 as initialization
	 */

	ADMUX = (ADMUX & 0x3F) | ((Config_Ptr->ref_volt)<<6);

	/* ADCSRA Register Bits Description:
	 * ADEN    = 1 Enable ADC
	 * ADIE    = 0 Disable ADC Interrupt
	 * ADATE   = 0 Disable Auto Trigger
	 * *********************** PRESCALER CONFIGURATION *********************** *
	 * ADPS2:0 = 000 to choose ADC_Clock = F_CPU/2 = 1Mhz/2 = 500Khz
	 * ADPS2:0 = 010 to choose ADC_Clock = F_CPU/4 = 1Mhz/4 = 250Khz
	 * ADPS2:0 = 011 to choose ADC_Clock = F_CPU/8 = 1Mhz/8 = 125Khz--> ADC must operate in range 50-200Khz
	 * ADPS2:0 = 100 to choose ADC_Clock = F_CPU/16 = 1Mhz/16 = 62.5Khz
	 * ADPS2:0 = 101 to choose ADC_Clock = F_CPU/32 = 1Mhz/32 = 31.25Khz
	 * ADPS2:0 = 110 to choose ADC_Clock = F_CPU/64 = 1Mhz/64 = 15.625Khz
	 * ADPS2:0 = 111 to choose ADC_Clock = F_CPU/128 = 1Mhz/128 = 7.8125Khz
	 */

	ADCSRA =(1<<ADEN);
	ADCSRA= (ADCSRA & 0xF8) | (Config_Ptr->prescaler) ;
}

uint16 ADC_readChannel(uint8 channel_num)
{
	channel_num &= 0x07; /* Input channel number must be from 0 --> 7 */
	ADMUX &= 0xE0; /* Clear first 5 bits in the ADMUX (channel number MUX4:0 bits) before set the required channel */
	ADMUX = ADMUX | channel_num; /* Choose the correct channel by setting the channel number in MUX4:0 bits */
	SET_BIT(ADCSRA,ADSC); /* Start conversion write '1' to ADSC */
	while(BIT_IS_CLEAR(ADCSRA,ADIF)); /* Wait for conversion to complete, ADIF becomes '1' */
	SET_BIT(ADCSRA,ADIF); /* Clear ADIF by write '1' to it :) */
	return ADC; /* Read the digital value from the data register */
}
