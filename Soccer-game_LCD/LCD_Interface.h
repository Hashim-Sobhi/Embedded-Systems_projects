#ifndef _LCD_INTERFACE_H_
#define _LCD_INTERFACE_H_

void LCD_VoidInit(void);
void LCD_VoidSendData(u8 Data);
void LCD_VoidSendCommand(u8 Command);
void LCD_VoidSendString(u8 *String);
void LCD_VoidSendNum(u32 num);
void LCD_VoidSetPositin(u8 Row,u8 Col);
void LCD_VoidShiftRightString(u8 *String);
void LCD_VoidZigzag(u8 *String);


#endif
