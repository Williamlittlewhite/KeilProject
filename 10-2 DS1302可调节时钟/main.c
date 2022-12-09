#include <REGX51.H>
#include "LCD1602.h"
#include "DS1302.h"
#include "Delay.h"
#include "Key.h"
#include "Timer0.h"
unsigned char KeyNum,MODE,TimeSetSelect,timesetflashflag;

void Timer0_Routine() interrupt 1
{
	static int iCount = 0;
	iCount++;
	if(iCount == 500)
	{
		timesetflashflag = !timesetflashflag;
		iCount = 0;
	}
	TH0 = 0xFC;	
	TL0 = 0x18;
}

void TimeShow()
{
		DS1302_ReadTime();
		LCD_ShowNum(1,1,DS1302_TIME[0],2);  
		LCD_ShowNum(1,4,DS1302_TIME[1],2);
		LCD_ShowNum(1,7,DS1302_TIME[2],2);  
		LCD_ShowNum(2,1,DS1302_TIME[3],2);  
		LCD_ShowNum(2,4,DS1302_TIME[4],2);
		LCD_ShowNum(2,7,DS1302_TIME[5],2);  
}

void TimeSet(void)
{
	if(KeyNum == 2)
	{
		TimeSetSelect++;
		TimeSetSelect%=6; //超过5清零
	}
	if(KeyNum == 3)
	{
		DS1302_TIME[TimeSetSelect]++;
		DS1302_TIME[0]%=100;
		if(DS1302_TIME[1] > 12){DS1302_TIME[1] = 1;}
		if(DS1302_TIME[1] == 1 || DS1302_TIME[1] == 3 || DS1302_TIME[1] == 5 || 
			DS1302_TIME[1] == 7 || DS1302_TIME[1] == 8 || DS1302_TIME[1] == 10 || DS1302_TIME[1] == 12)
		{
			if(DS1302_TIME[2] > 31){DS1302_TIME[2] = 1;}
		}
		else if(DS1302_TIME[1] == 4 || DS1302_TIME[1] == 6 
			|| DS1302_TIME[1] == 9 || DS1302_TIME[1] == 11 )
		{
			if(DS1302_TIME[2] > 30){DS1302_TIME[2] = 1;}
		}
		else if(DS1302_TIME[1] == 2)
		{
			if(DS1302_TIME[0]%4 == 0)
			{
				if(DS1302_TIME[2]>29)
						DS1302_TIME[2] = 1;
			}
			else
			{
				if(DS1302_TIME[2]>28)
						DS1302_TIME[2] = 1;
			}
		}
		if(DS1302_TIME[3] > 23){DS1302_TIME[3] = 0;}
		if(DS1302_TIME[4] > 59){DS1302_TIME[4] = 0;}
		if(DS1302_TIME[5] > 59){DS1302_TIME[5] = 0;}
	}
	if(KeyNum == 4)
	{
		DS1302_TIME[TimeSetSelect]--;
		if(DS1302_TIME[0] < 0) {DS1302_TIME[0] = 99;}
		if(DS1302_TIME[1] < 1){DS1302_TIME[1] = 12;}
		if(DS1302_TIME[1] == 1 || DS1302_TIME[1] == 3 || DS1302_TIME[1] == 5 || 
			DS1302_TIME[1] == 7 || DS1302_TIME[1] == 8 || DS1302_TIME[1] == 10 || DS1302_TIME[1] == 12)
		{
			if(DS1302_TIME[2] < 1){DS1302_TIME[2] = 31;}
			if(DS1302_TIME[2] > 31){DS1302_TIME[2] = 1;}
		}
		else if(DS1302_TIME[1] == 4 || DS1302_TIME[1] == 6 
			|| DS1302_TIME[1] == 9 || DS1302_TIME[1] == 11 )
		{
			if(DS1302_TIME[2] < 1){DS1302_TIME[2] = 30;}
			if(DS1302_TIME[2] > 30){DS1302_TIME[2] = 1;}
		}
		else if(DS1302_TIME[1] == 2)
		{
			if(DS1302_TIME[0]%4 == 0)
			{
				if(DS1302_TIME[2] < 1) DS1302_TIME[2] = 29;
				if(DS1302_TIME[2] > 29) DS1302_TIME[2] = 1;
			}
			else
			{
				if(DS1302_TIME[2] < 1) DS1302_TIME[2] = 28;
				if(DS1302_TIME[2] > 28) DS1302_TIME[2] = 1;
			}
		}
		if(DS1302_TIME[3] < 0){DS1302_TIME[3] = 23;}
		if(DS1302_TIME[4] < 0){DS1302_TIME[4] = 59;}
		if(DS1302_TIME[5] < 0){DS1302_TIME[5] = 59;}
	}

		if(TimeSetSelect == 0 && timesetflashflag == 1){LCD_ShowString(1,1,"  ");}
		else LCD_ShowNum(1,1,DS1302_TIME[0],2);  
		if(TimeSetSelect == 1 && timesetflashflag == 1){LCD_ShowString(1,4,"  ");}
		else LCD_ShowNum(1,4,DS1302_TIME[1],2);
		if(TimeSetSelect == 2 && timesetflashflag == 1){LCD_ShowString(1,7,"  ");}
		else LCD_ShowNum(1,7,DS1302_TIME[2],2);  
		if(TimeSetSelect == 3 && timesetflashflag == 1){LCD_ShowString(2,1,"  ");}
		else LCD_ShowNum(2,1,DS1302_TIME[3],2);  
		if(TimeSetSelect == 4 && timesetflashflag == 1){LCD_ShowString(2,4,"  ");}
		else LCD_ShowNum(2,4,DS1302_TIME[4],2);
		if(TimeSetSelect == 5 && timesetflashflag == 1){LCD_ShowString(2,7,"  ");}
		else LCD_ShowNum(2,7,DS1302_TIME[5],2);  
		
//		LCD_ShowNum(2,13,timesetflashflag,2); 
//		LCD_ShowNum(2,10,TimeSetSelect,2);
}
void main()
{
	LCD_Init();
	Timer0Init();
	//LCD_ShowString(1,1,"RTC");
	LCD_ShowString(1,1,"  -  -  ");
	LCD_ShowString(2,1,"  :  :  ");
	DS1302_Init();
	//DS1302_WriteByte(0x8E,0x00);//解除芯片写保护
	//DS1302_WriteByte(0x80,0x55);
	DS1302_SetTime();
	while(1)
	{
		KeyNum = Key();
		if(KeyNum == 1)
		{
			if(MODE == 0){MODE = 1;}
			else if(MODE == 1){MODE = 0; DS1302_SetTime();}
		}
		switch (MODE)
		{	
			case 0:TimeShow(); break;
			case 1:TimeSet();  break;
		}
	}
}