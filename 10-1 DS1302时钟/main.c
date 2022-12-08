#include <REGX51.H>
#include "LCD1602.h"
#include "DS1302.h"
#include "Delay.h"


void main()
{
	LCD_Init();
	//LCD_ShowString(1,1,"RTC");
	LCD_ShowString(1,1,"  -  -  ");
	LCD_ShowString(2,1,"  :  :  ");
	DS1302_Init();
	//DS1302_WriteByte(0x8E,0x00);//½â³ýÐ¾Æ¬Ð´±£»¤
	//DS1302_WriteByte(0x80,0x55);
	DS1302_SetTime();
	while(1)
	{
		DS1302_ReadTime();
		LCD_ShowNum(1,1,DS1302_TIME[0],2);  
		LCD_ShowNum(1,4,DS1302_TIME[1],2);
		LCD_ShowNum(1,7,DS1302_TIME[2],2);  
		LCD_ShowNum(2,1,DS1302_TIME[3],2);  
		LCD_ShowNum(2,4,DS1302_TIME[4],2);
		LCD_ShowNum(2,7,DS1302_TIME[5],2);  
	}
}