#ifndef _TIMER_RIGESTER_H_
#define _TIMER_RIGESTER_H_

#define TIMSK   *((u8*)0x59)
#define TCCR0   *((u8*)0x53)
#define TCNT0   *((u8*)0x52)
#define OCR0    *((u8*)0x5C)
// TCCR0 PINS
#define CS00   0
#define CS01   1
#define CS02   2
#define WGM01  3
#define COM00  4
#define COM01  5
#define WGM00  6
// TIMSK PINS
#define TOIE0  0
#endif