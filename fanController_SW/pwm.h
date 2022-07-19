 /******************************************************************************
 *
 * Module: PWM
 *
 * File Name: pwm.h
 *
 * Description: Header file for the PWM driver
 *
 * Author: Abdelrahman Hesham
 *
 *******************************************************************************/

#ifndef PWM_H_
#define PWM_H_

#define PWM_PORT_ID                   PORTB_ID
#define PWM_PIN_ID                    PIN3_ID



void PWM_Timer0_Start(unsigned char set_duty_cycle);



#endif /* PWM_H_ */
