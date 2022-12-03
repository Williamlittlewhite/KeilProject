#include <REGX51.H>
#include "LCD1602.h"
#include "DS1302.h"
#include "Delay.h"
unsigned char second;
void main()
{
	LCD_Init();
	LCD_ShowString(1,1,"RTC");
	DS1302_Init();
//	DS1302_WriteByte(0x8E,0x00);//½â³ýÐ¾Æ¬Ð´±£»¤
	DS1302_WriteByte(0x80,0x03);
	while(1)
	{
//		second = DS1302_ReadByte(0x81);
//		LCD_ShowNum(2,1,second,3);
//		Delay(50);
	}
}