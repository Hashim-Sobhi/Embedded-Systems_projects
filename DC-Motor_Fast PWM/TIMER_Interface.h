#ifndef _TIMER_INTERFACE_H_
#define _TIMER_INTERFACE_H_

void Timer0_VoidInit();
void TIMER_VoidSetCallback (void (*ptofun)(void));
void PWM_VoidDutyCycle (u8 dutycycle);
#endif
