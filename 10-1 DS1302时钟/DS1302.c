#include <REGX51.H>
#include "LCD1602.h"
sbit DS1302_SCLK = P3^6;
sbit DS1302_IO = P3^4;
sbit DS1302_CE = P3^5;

#define DS1302_SECOND 0x80
#define DS1302_MINUTE 0x82
#define DS1302_HOUR   0x84
#define DS1302_DATE   0x86
#define DS1302_MONTH  0x88
#define DS1302_DAY    0x8A
#define DS1302_YEAR   0x8C
#define DS1302_WP     0x8E

unsigned char DS1302_TIME[] = {22,12,9,1,12,55,5};

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
		DS1302_IO = Command&(0x01<<i);
		DS1302_SCLK = 1;
		DS1302_SCLK = 0;
	}
	for( i = 0; i < 8; ++i )
	{	
		DS1302_IO = Data&(0x01<<i);
		DS1302_SCLK = 1;
		DS1302_SCLK = 0;
	}
	DS1302_CE = 0;
}

unsigned char DS1302_ReadByte(unsigned char Command)
{
	unsigned char i,Data = 0x00;
	Command |= 0x01; //��ָ��ת��Ϊ��ָ��
	DS1302_CE = 1;//������벻���ڵ�һ�䡣����������
	for( i = 0; i < 8; ++i )
	{	
		
		DS1302_IO = Command >> i & 1;
	//DS1302_IO = Command&(0x01<<i);  //Command<<i&1�������debug�˰��� Ӧ�������� 
		DS1302_SCLK = 0;
		DS1302_SCLK = 1;
	}
	for( i = 0; i < 8; ++i)
	{
		DS1302_SCLK = 1;
		DS1302_SCLK = 0;
		if(DS1302_IO)
		{
			Data |= (0x01 << i); //���ﲻ����Data = Data|| (0x01<<i) Ӧ����|
		}
	}
	DS1302_CE = 0;
	DS1302_IO = 0;  //��ȡ���IO����Ϊ0Ҫ���������
	return Data;
}

void DS1302_SetTime(void)
{
	DS1302_WriteByte(DS1302_WP,0x00);//�ر�д����
	DS1302_WriteByte(DS1302_YEAR,DS1302_TIME[0]/10*16+DS1302_TIME[0]%10);
  DS1302_WriteByte(DS1302_MONTH,DS1302_TIME[1]/10*16+DS1302_TIME[1]%10);
	DS1302_WriteByte(DS1302_DATE,DS1302_TIME[2]/10*16+DS1302_TIME[2]%10);
	DS1302_WriteByte(DS1302_HOUR,DS1302_TIME[3]/10*16+DS1302_TIME[3]%10);
	DS1302_WriteByte(DS1302_MINUTE,DS1302_TIME[4]/10*16+DS1302_TIME[4]%10);
	DS1302_WriteByte(DS1302_SECOND,DS1302_TIME[5]/10*16+DS1302_TIME[5]%10);
	DS1302_WriteByte(DS1302_DAY,DS1302_TIME[6]/10*16+DS1302_TIME[6]%10);
	DS1302_WriteByte(DS1302_WP,0x80);//��д����
}

void DS1302_ReadTime(void)
{
	DS1302_TIME[0] = DS1302_ReadByte(DS1302_YEAR)/16*10 +DS1302_ReadByte(DS1302_YEAR)%16; ;
	DS1302_TIME[1] = DS1302_ReadByte(DS1302_MONTH)/16*10 +DS1302_ReadByte(DS1302_MONTH)%16;
	DS1302_TIME[2] = DS1302_ReadByte(DS1302_DATE)/16*10 +DS1302_ReadByte(DS1302_DATE)%16;
	DS1302_TIME[3] = DS1302_ReadByte(DS1302_HOUR)/16*10 +DS1302_ReadByte(DS1302_HOUR)%16;
	DS1302_TIME[4] = DS1302_ReadByte(DS1302_MINUTE)/16*10 +DS1302_ReadByte(DS1302_MINUTE)%16;
	DS1302_TIME[5] = DS1302_ReadByte(DS1302_SECOND)/16*10 +DS1302_ReadByte(DS1302_SECOND)%16;
	DS1302_TIME[6] = DS1302_ReadByte(DS1302_DAY)/16*10 +DS1302_ReadByte(DS1302_DAY)%16;
}