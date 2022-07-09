#ifndef _LCD_CONFIG_H_
#define _LCD_CONFIG_H_

#define DATA_PORT  PORT_C
#define CNRL_PORT  PORT_D


#define ON    1 
#define OFF   0 
// CURSOR DISPLAY 
#define CURSOR_DISPLAY   OFF
// CURSOR BLINK
#define CURSOR_BLINK   OFF


#define ROW_0   0
#define ROW_1   1

//BIT_NUM
#define BIT_0    0
#define BIT_1    1
#define BIT_2    2
#define BIT_3    3
#define BIT_4    4
#define BIT_5    5
#define BIT_6    6
#define BIT_7    7


#define LCD_CLEAR           0x01
#define LCD_HOME            0x80
#define LCD_ENTRYMODE       0x06
#define lCD_DISPLAYOFF      0x08
#define LCD_DISPLAYON       0x0C
#define LCD_FUNSET8BIT      0x38







#endif
