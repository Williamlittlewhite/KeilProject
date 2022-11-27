#include <REGX51.H>
#include "Timer0.h"
#include "Delay.h"
#include "display.h"
unsigned char number = 0;
void main()
{
	 Timer0Init();
   while(1)
   {
     display(4,number);   
   }
}

void Timer0_Routine() interrupt 1   //中断函数不要嵌套过长的子函数
{
	static int iCount = 0;
	iCount++;
	if(iCount == 500)
	{
		++number;
		//display(4,number);
		iCount = 0;
	}
	TH0 = 0xD1;	
	TL0 = 0x20;
}