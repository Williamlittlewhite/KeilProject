#include <REGX51.H>
#include "LCD1602.h"
sbit DS1302_SCLK = P3^6;
sbit DS1302_IO = P3^4;
sbit DS1302_CE = P3^5;

void DS1302_Init()
{
	DS1302_CE = 0;
	DS1302_SCLK = 0;
}

void DS1302_WriteByte(unsigned char Command,unsigned char Data)
{
	unsigned char i;
	DS1302_CE = 1; //������벻���ڵ�һ�䡣����������
	for( i = 0; i < 8; ++i )
	{	
		DS1302_IO = Command << i & 1;
		DS1302_SCLK = 1;
		DS1302_SCLK = 0;
	}
	for( i = 0; i < 8; ++i )
	{	
		DS1302_IO = Data << i & 1;
		DS1302_SCLK = 1;
		DS1302_SCLK = 0;
	}
	DS1302_CE = 0;
}

unsigned char DS1302_ReadByte(unsigned char Command)
{
	unsigned char i = 0,Data = 0x00;
	Command |= 0x01; //��ָ��ת��Ϊ��ָ��
	DS1302_CE = 1;//������벻���ڵ�һ�䡣����������
	for( i = 0; i < 8; ++i )
	{	
		DS1302_IO = Command << i & 1;
		DS1302_SCLK = 0;
		DS1302_SCLK = 1;
	}
	for( i = 0; i < 8; ++i)
	{
		DS1302_SCLK = 1;
		DS1302_SCLK = 0;
		if(DS1302_IO)
		{
			Data = Data || (0x01 << i);
		}
	}
	DS1302_CE = 0;
	DS1302_IO = 0;  //��ȡ���IO����Ϊ0Ҫ���������
	LCD_ShowNum(2,1,Data,3);
	return Data;
}