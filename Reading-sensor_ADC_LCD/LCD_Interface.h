#ifndef _LCD_INTERFACE_H_
#define _LCD_INTERFACE_H_

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

#define SET 1
#define CLR 0

#define LCD_CLEAR           0x01
#define LCD_HOME            0x80
#define LCD_ENTRYMODE       0x06
#define lCD_DISPLAYOFF      0x08
#define LCD_DISPLAYON       0x0C
#define LCD_FUNSET8BIT      0x38

void LCD_VoidInit(void);
void LCD_VoidSendData(u8 Data);
void LCD_VoidSendCommand(u8 Command);
void LCD_VoidSendString(u8 *String);
void LCD_VoidSendNum(u32 num);
void LCD_VoidSetPositin(u8 Row,u8 Col);
void LCD_VoidShiftRightString(u8 *String);
void LCD_VoidZigzag(u8 *String);


#endif
