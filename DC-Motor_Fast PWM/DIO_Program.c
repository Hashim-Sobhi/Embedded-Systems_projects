#include "STD_TYPES.h"
#include "BIT_MATHS.h"
#include "DIO_Private.h"
#include "DIO_Config.h"

void DIO_VoidSetPinDirection(u8 Port,u8 Pin,u8 Direction)
{
	if (OUTPUT_PIN == Direction)//output
	{
		switch(Port)
		{
			case PORT_A: SET_BIT(DDRA,Pin); break;
			case PORT_B: SET_BIT(DDRB,Pin); break;
			case PORT_C: SET_BIT(DDRC,Pin); break;
			case PORT_D: SET_BIT(DDRD,Pin); break;
		}
	}
	else if(INPUT_PIN == Direction) //input
	{
		switch(Port)
		{
			case PORT_A: CLR_BIT(DDRA,Pin); break;
			case PORT_B: CLR_BIT(DDRB,Pin); break;
			case PORT_C: CLR_BIT(DDRC,Pin); break;
			case PORT_D: CLR_BIT(DDRD,Pin); break;
			
		}
	}
}

void DIO_VoidSetPortDirection(u8 Port,u8 Direction)
{
	switch(Port)
	{
		case PORT_A: DDRA=Direction; break;
		case PORT_B: DDRB=Direction; break;
		case PORT_C: DDRC=Direction; break;
		case PORT_D: DDRD=Direction; break;
	}
}


void DIO_VoidSetPinValue(u8 Port,u8 Pin,u8 Value)
{
	if (HIGH==Value)//set
	{
		switch(Port)
		{
			case PORT_A: SET_BIT(PORTA,Pin); break;
			case PORT_B: SET_BIT(PORTB,Pin); break;
			case PORT_C: SET_BIT(PORTC,Pin); break;
			case PORT_D: SET_BIT(PORTD,Pin); break;
		}
	}
	else if(LOW == Value) //clr
	{
		switch(Port)
		{
			case PORT_A: CLR_BIT(PORTA,Pin); break;
			case PORT_B: CLR_BIT(PORTB,Pin); break;
			case PORT_C: CLR_BIT(PORTC,Pin); break;
			case PORT_D: CLR_BIT(PORTD,Pin); break;
		}
	}
}

void DIO_VoidSetPortValue(u8 Port,u8 Value)
{
	switch(Port)
	{
		case PORT_A: PORTA=Value; break;
		case PORT_B: PORTB=Value; break;
		case PORT_C: PORTC=Value; break;
		case PORT_D: PORTD=Value; break;			
	}
}
u8 DIO_U8GetPinValue(u8 Port,u8 Pin)
{
	u8 x;
	switch(Port)
	{
		case PORT_A: x = GET_BIT(PINA,Pin); break;
		case PORT_B: x = GET_BIT(PINB,Pin); break;
		case PORT_C: x = GET_BIT(PINC,Pin); break;
		case PORT_D: x = GET_BIT(PIND,Pin); break;
	}
	return x;
}
void DIO_VoidTogglePin(u8 Port,u8 Pin)
{
		switch(Port)
	{
		case PORT_A: TOG_BIT(PORTA,Pin); break;
		case PORT_B: TOG_BIT(PORTB,Pin); break;
		case PORT_C: TOG_BIT(PORTC,Pin); break;
		case PORT_D: TOG_BIT(PORTD,Pin); break;
	}
}