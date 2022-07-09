/*
 * main.c
 *
 *  Created on: May 22, 2021
 *      Author: Hesha
 */
#include "STD_TYPES.h"
#include "BIT_MATHS.h"
#include "MOTOR_Interface.h"
#include "TIMER_Interface.h"
#include <avr/delay.h>
int main ()
{
	DIO_VoidSetPinDirection(1, 3, 1);
	Timer0_VoidInit();
	while (1)
	{
		PWM_VoidDutyCycle(0);
		_delay_ms(1000);
		PWM_VoidDutyCycle(50);
		_delay_ms(1000);
		PWM_VoidDutyCycle(100);
		_delay_ms(1000);
		PWM_VoidDutyCycle(150);
		_delay_ms(1000);
		PWM_VoidDutyCycle(200);
		_delay_ms(1000);
		PWM_VoidDutyCycle(250);
		_delay_ms(1000);
	}
}
