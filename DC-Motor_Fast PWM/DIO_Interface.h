#ifndef _DIO_INTERFACE_H_
#define _DIO_INTERFACE_H_

//PORT_NUM
#define PORT_A  0
#define PORT_B  1
#define PORT_C  2
#define PORT_D  3
//BIT_NUM
#define PIN_0    0
#define PIN_1    1
#define PIN_2    2
#define PIN_3    3
#define PIN_4    4
#define PIN_5    5
#define PIN_6    6
#define PIN_7    7
//VALUE
#define LOW    0
#define HIGH    1
//DIRECTION
#define INPUT_PIN   0
#define OUTPUT_PIN  1
#define INPUT_PORT  0x00
#define OUTPUT_PORT 0xff


void DIO_VoidSetPinDirection(u8 Port,u8 Pin,u8 Direction);
void DIO_VoidSetPortDirection(u8 Port,u8 Dir);
void DIO_VoidSetPinValue(u8 Port,u8 Pin,u8 Value);
void DIO_VoidSetPortValue(u8 Port,u8 Value);
u8 DIO_U8GetPinValue(u8 port,u8 Pin);
void DIO_VoidTogglePin(u8 Port,u8 Pin);

#endif