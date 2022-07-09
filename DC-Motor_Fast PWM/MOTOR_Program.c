#include "STD_TYPES.h"
#include "BIT_MATHS.h"
#include "TIMER_Interface.h"
#include "DIO_Interface.h"

void MOTOR_VoidSetAngle(u16 angle)
{
	Timer0_VoidInit();
	DIO_VoidSetPinDirection(1, 3, 1);
	PWM_VoidDutyCycle((angle * 20) / 180);
}
