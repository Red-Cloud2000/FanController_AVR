 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.c
 *
 * Description: Source file for the ADC driver
 *
 * Author: Abdelrahman Hesham
 *
 *******************************************************************************/

#include "common_macros.h"
#include "adc.h"
#include "avr/io.h" /* To use the IO Ports Registers */


/*******************************************************************************
 * [Function Name] : ADC_init
 *
 * [Description]   : function implemented in the ADC session to initialize ADC
 *                   registers to set it up for conversion from analog to digital
 *
 * [Args.]         :
 * [IN]            : ADC_ConfigType *Config_Ptr : a pointer to the configuration structure with
 *                   type ADC_ConfigType to make this driver configurable.
 *******************************************************************************/
void ADC_init(const ADC_ConfigType *Config_Ptr){

	ADMUX  |= ((Config_Ptr -> ref_volt) << 6);
	ADCSRA |=   Config_Ptr -> prescaler;

	SET_BIT(ADCSRA,ADEN);
	CLEAR_BIT(ADCSRA,ADIE);

}

/*******************************************************************************
 * [Function Name] : ADC_readChannel
 *
 * [Description]   : Function to read the analog value from any analog device
 *                   and converts it to digital value
 *
 * [Args.]         :
 * [IN]            : uint8 ch_num : ADC channel number (0 --> 7)

 *******************************************************************************/
uint16 ADC_readChannel(uint8 ch_num){
	/*to deal with the specific bits and not to damage the others*/
	ch_num &= 0x07;
	ADMUX  &= 0xE0;
	ADMUX  = ADMUX|ch_num;

	SET_BIT(ADCSRA,ADSC);
	/*Pooling on interrupt*/
	while(BIT_IS_CLEAR(ADCSRA,ADIF));
	/*clearing interrupt flag by setting that flag bit*/
	SET_BIT(ADCSRA,ADIF);
	return ADC;
}


