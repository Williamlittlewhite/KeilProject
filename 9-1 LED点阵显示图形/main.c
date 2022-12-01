#include <REGX51.H>
#include "Delay.h"
sbit RCLK = P3^5;
sbit SER = P3^4;
sbit SRCLK = P3^6;
#define MATRIX_LED_PORT P0
//74HC595移位寄存器扩展IO口 3个口 串行转并行
void _74HC595_WriteByte(unsigned char Byte)	
{
	unsigned char i;
	for(i = 0; i < 8; ++i)
	{
		SER = Byte >> i & 1;
		SRCLK = 1;
		SRCLK = 0;
	}	
		RCLK = 1;
		RCLK = 0;
}
//LED点阵屏显示一列数据  colum选择的列 Data选择每列显示的数据
void MatrixLED_showColumn(unsigned char column, Data)
{
	_74HC595_WriteByte(Data);
	MATRIX_LED_PORT = ~(0x80>>column);
	Delay(1); //消隐 段选-位选-延时-位清零-段选-位选
	MATRIX_LED_PORT = 0xFF;
}

void main()
{
	 RCLK = 0;
	 SRCLK = 0;
	 
   while(1)
   {
     MatrixLED_showColumn(0,0x3C); 
		 MatrixLED_showColumn(1,0x42); 
		 MatrixLED_showColumn(2,0xA9); 
		 MatrixLED_showColumn(3,0x85);
		 MatrixLED_showColumn(4,0x85); 
		 MatrixLED_showColumn(5,0xA9); 
		 MatrixLED_showColumn(6,0x42); 
		 MatrixLED_showColumn(7,0x3C);		 
   }
}