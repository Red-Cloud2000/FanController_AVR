 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: Header file for the ADC driver
 *
 * Author: Abdelrahman Hesham
 *
 *******************************************************************************/

#include "std_types.h"

#ifndef ADC_H_
#define ADC_H_



#define ADC_REF_VOLT_VALUE            2.56
#define ADC_MAXIMUM_VALUE             1023

typedef enum{
    AREF,AVCC,INTERNAL_VOLTAGE_REFERENCE = 3
}ADC_ReferenceVoltage;

typedef enum{
    NO_PRESCALER,F_CPU2,F_CPU4,F_CPU8,F_CPU16,F_CPU32,F_CPU64,F_CPU128
}ADC_Prescaler;

typedef struct{
ADC_ReferenceVoltage ref_volt;
ADC_Prescaler prescaler;
}ADC_ConfigType;

void ADC_init(const ADC_ConfigType *Config_Ptr);

uint16 ADC_readChannel(uint8 ch_num);


#endif /* ADC_H_ */
