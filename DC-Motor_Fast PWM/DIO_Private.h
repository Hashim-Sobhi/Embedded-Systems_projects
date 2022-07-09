#ifndef _DIO_PRIVATE_H_
#define _DIO_PRIVATE_H_
//ENABLE PORTS 
#define DDRA *((u8*)0x3A)
#define DDRB *((u8*)0x37)
#define DDRC *((u8*)0x34)
#define DDRD *((u8*)0x31)
//OUTPUT REGISTER
#define PORTA *((u8*)0x3B)
#define PORTB *((u8*)0x38)
#define PORTC *((u8*)0x35)
#define PORTD *((u8*)0x32)
//INPUT  REGISTER
#define PINA *((u8*)0x39)
#define PINB *((u8*)0x36)
#define PINC *((u8*)0x33)
#define PIND *((u8*)0x30)


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

#endif
