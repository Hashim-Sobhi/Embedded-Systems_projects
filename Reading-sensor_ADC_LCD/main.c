/*
 * main.c
 *
 *  Created on: May 8, 2021
 *      Author: Hesha
 */


#include "STD_TYPES.h"
#include "BIT_MATHS.h"
#include "ADC_Interface.h"
#include "LCD_Interface.h"
#include <avr/delay.h>

int main()
{

	ADC_ViodInit();
	LCD_VoidInit();

	u16 DigitalValue,AnalogValue;
	while(1)
	{
		DigitalValue = ADC_U16ReadValue(0);
		AnalogValue = (DigitalValue * (u64)5000)/1024;
		LCD_VoidSetPositin(0,0);
		LCD_VoidSendNum(AnalogValue/10);
		_delay_ms(1000);
	}


}
