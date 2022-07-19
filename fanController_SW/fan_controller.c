/*============================================================================
 Name        : fan_controller.c
 Author      : Abdelrahman Hesham
 Created on  : May 26, 2022
 Description : A program to control a fan speed depending on temperature
 ============================================================================
 */
#include "adc.h"
#include "lcd.h"
#include "lm35_sensor.h"
#include "motor.h"
#include "util/delay.h"

int main(void){
	uint8 temp;
	DcMotor_Init();   /*Motor initialization*/
	LCD_init();       /*LCD initialization*/

	ADC_ConfigType Config_Ptr = {INTERNAL_VOLTAGE_REFERENCE,F_CPU8};
	ADC_init(&Config_Ptr); /*Passing configuration structure elements using a pointer to structure*/

	_delay_ms(1000);   /*wait a little bit for the reading to stabilize*/

	LCD_displayStringRowColumn(0,4,"FAN IS ");
	LCD_displayStringRowColumn(1,4,"Temp. =   C");

	while(1){
		temp = LM35_getTemperature();   /*getting temperature value*/
        /*Handling conditions of speed and displaying*/
		if(temp>=120){
			DcMotor_Rotate(A_CW,100);
			LCD_displayStringRowColumn(0,11,"ON ");
		}
		else if(temp>=90){
			DcMotor_Rotate(A_CW,75);
			LCD_displayStringRowColumn(0,11,"ON ");
		}
		else if(temp>=60){
			DcMotor_Rotate(A_CW,50);
			LCD_displayStringRowColumn(0,11,"ON ");
		}
		else if(temp>=30){
			DcMotor_Rotate(A_CW,25);
			LCD_displayStringRowColumn(0,11,"ON ");
		}
		else if(temp<30){
			DcMotor_Rotate(stop,0);
			LCD_displayStringRowColumn(0,11,"OFF");

		}
        /*print space to handle ( <100) numbers after a ( >=100) number*/
		LCD_moveCursor(1,11);
		if(temp >= 100)
		{
			LCD_intgerToString(temp);
		}
		else
		{
			LCD_intgerToString(temp);
			/* In case the digital value is two or one digits print space in the next digit place */
			LCD_displayCharacter(' ');
		}


	}


}
