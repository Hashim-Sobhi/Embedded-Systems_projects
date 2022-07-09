#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include "DIO_Config.h"
#include "LCD_Register.h"
#include "LCD_Config.h"
#include <avr/delay.h>
#include "BIT_MATHS.h"

void LCD_VoidInit(void)
{
	//POWER ON
	//ENABLE PORT DATA
	DIO_VoidSetPortDirection(DATA_PORT,0xFF);
	//ENABLE RS 
	DIO_VoidSetPinDirection(CNRL_PORT,PIN_0,OUTPUT_PIN);
	//ENABLE R/W
	DIO_VoidSetPinDirection(CNRL_PORT,PIN_1,OUTPUT_PIN);
	//ENABLE E
	DIO_VoidSetPinDirection(CNRL_PORT,PIN_2,OUTPUT_PIN);
	_delay_ms(40);
	// function set 
	LCD_VoidSendCommand(LCD_FUNSET8BIT);
	_delay_us(100);
	//display On/off control
	u8 Display_Control=LCD_DISPLAYON;
	//CURSOR DISPLAY 
	#if CURSOR_DISPLAY == ON 
	SET_BIT(Display_Control,BIT_1);
	#elif CURSOR_DISPLAY == OFF
	CLR_BIT(Display_Control,BIT_1);
	#endif
	//CURSOR BLINK
	#if CURSOR_BLINK == ON 
	SET_BIT(Display_Control,BIT_0);
	#elif CURSOR_BLINK == OFF
	CLR_BIT(Display_Control,BIT_0);
	#endif
	LCD_VoidSendCommand(Display_Control);
	_delay_us(100);
	// display clear
	LCD_VoidSendCommand(LCD_CLEAR);
	_delay_ms(2);	
}
void LCD_VoidSendData(u8 Data)
{
	//  Rs =1 to write data
	DIO_VoidSetPinValue(CNRL_PORT,PIN_0,SET);
	// R/W =0 to write
	DIO_VoidSetPinValue(CNRL_PORT,PIN_1,CLR);
	// send command to data port
	DIO_VoidSetPortValue(DATA_PORT,Data);
	//Enable sequence
	DIO_VoidSetPinValue(CNRL_PORT,PIN_2,SET);
	_delay_ms(1);
	DIO_VoidSetPinValue(CNRL_PORT,PIN_2,CLR);
	_delay_ms(2);
	
}
void LCD_VoidSendCommand(u8 Command)
{
	//  Rs =0 to write command
	DIO_VoidSetPinValue(CNRL_PORT,PIN_0,CLR);
	// R/W =0 to write
	DIO_VoidSetPinValue(CNRL_PORT,PIN_1,CLR);
	// send command to data port
	DIO_VoidSetPortValue(DATA_PORT,Command);
	//Enable sequence
	DIO_VoidSetPinValue(CNRL_PORT,PIN_2,SET);
	_delay_ms(1);
	DIO_VoidSetPinValue(CNRL_PORT,PIN_2,CLR);
	_delay_ms(2);
}
void LCD_VoidSendString(u8 *String)
{
	u8 i=0;
	while(String[i]!='\0')
	{
		LCD_VoidSendData(String[i]);
		i++;
	}
}
void LCD_VoidSendNum(u32 Num)
{
	u8 x=0;
	u32 rev=1;
	if (Num ==0)
	{
		LCD_VoidSendData('0');
	}
	else
	{
		while(Num!=0)
		{
			rev=(rev*10) + (Num%10);
			Num/=10;
		}

		while (rev!=1)
		{
			x= rev%10;
			rev=rev/10;
			LCD_VoidSendData(x+48);
		}
	}
}
void LCD_VoidShiftRightString(u8 *String)
{

	u8 size_of_String=0;
	while(String[size_of_String]!='\0')
	{
		size_of_String++;
	}
	// ShOW CHARS FROM LEFT TO RIGHT
	for (u8 i=size_of_String-1;i>=0;i--)
	{
		for (u8 j=i;String[j]!='\0';j++)
		{
			LCD_VoidSendData(String[j]);
		}
		_delay_ms(500);
		//to clean window
		LCD_VoidSendCommand(LCD_CLEAR);
		if (0==i)
			break;
	}
	// SHIFTING STRING
	for (u8 i=1;i<17;i++)
	{
		LCD_VoidSetPositin(ROW_0,i);

		for (u8 j=0;String[j]!='\0';j++)
		{
			LCD_VoidSendData(String[j]);
		}
		_delay_ms(500);
		//to clean window
		LCD_VoidSendCommand(LCD_CLEAR);
	}
}
void LCD_VoidSetPositin(u8 Row,u8 Col)
{
	if (ROW_0 == Row)
	{
		LCD_VoidSendCommand(128+Col);
	}
	else if(ROW_1 == Row)
	{
		LCD_VoidSendCommand(128+64+Col);
	}
}
void LCD_VoidZigzag(u8 *String)
{
	u8 row=0;

	u8 size_of_String=0;
	while(String[size_of_String]!='\0')
	{
		size_of_String++;
	}
	for(u8 i=0;16-i>=size_of_String;i+=(size_of_String/2))
	{
		LCD_VoidSetPositin(row,i);
		for (u8 j=0;String[j]!='\0';j++)
			{
				LCD_VoidSendData(String[j]);
			}
		_delay_ms(500);
		TOG_BIT(row,BIT_0);
		//to clean window
		LCD_VoidSendCommand(LCD_CLEAR);
	}
}
