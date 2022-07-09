/************************************************************/
/* author  :Hashim Sobhy                                   **/
/* Date    :2021/5/7                                       **/
/* Version :1.0                                            **/
/* Title   :ADC Driver                                     **/
/* Subtitle:ADC Registers                                  **/
/************************************************************/
#ifndef _ADC_REG_H_
#define _ADC_REG_H_
//ADC Registers
#define ADMUX  *((u8*)0x27)
#define ADCSRA *((u8*)0x26)
#define ADCH   *((u8*)0x25)
#define ADCL   *((u8*)0x24)
#define ADC_D  *((u16*)0x24)
#define SFIOR  *((u8*)0x50)
//ADMUX Reg
#define ADLAR 5
#define REFS0 6
#define REFS1 7
//ADCSRA Reg
#define ADPS0 0
#define ADPS1 1
#define ADPS2 2
#define ADIE  3
#define ADIF  4
#define ADATE 5
#define ADSC  6 
#define ADEN  7

#endif