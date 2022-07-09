#include "STD_TYPES.h"
#include "BIT_MATHS.h"
#include "TIMER_Register.h"
#include "TIMER_Config.h"
#include "DIO_Interface.h"
#include <stdio.h>
u16 counter;
// OV_Mode (normal)
#if TIMER0_MODE == OV_MODE
void Timer0_VoidInit()
{
	// select timer mode -> OV mode (normal)
	CLR_BIT(TCCR0, WGM00);
	CLR_BIT(TCCR0, WGM01);
	// prescallar value /256
	CLR_BIT(TCCR0, CS00);
	CLR_BIT(TCCR0, CS01);
	SET_BIT(TCCR0, CS02);
	// preload
	TCNT0 = 238;
	// Enable PIE
	SET_BIT(TIMSK, TOIE0);
}
#elif TIMER0_MODE == FAST_PWM
void Timer0_VoidInit()
{
	// select timer mode -> fast pwm
	SET_BIT(TCCR0, WGM00);
	SET_BIT(TCCR0, WGM01);
	//compare mode clear oc0, set at top
	SET_BIT(TCCR0, COM01);
	CLR_BIT(TCCR0, COM00);
	// prescallar value /1024
	SET_BIT(TCCR0, CS00);
	SET_BIT(TCCR0, CS01);
	CLR_BIT(TCCR0, CS02);
}
#endif
void __vector_11(void) __attribute__((signal));

void (*TIMER0_Callback) (void) = NULL;

void TIMER0_VoidSetCallback (void (*ptofun)(void))
{
	TIMER0_Callback = ptofun;
}
void PWM_VoidDutyCycle (u8 dutycycle)
{
	OCR0 = dutycycle;
}

void __vector_11(void)
{
	TIMER0_Callback();
}
