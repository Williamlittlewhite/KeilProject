#include <REGX51.H>

void Timer0Init(void)		
{
	TMOD &= 0xF0;		
	TMOD |= 0x01;		
	TL0 = 0x20;		
	TH0 = 0xD1;		
	TF0 = 0;		
	TR0 = 1;	
	IE = 0x82;
  PT0 = 0;
}
/*
void Timer0_Routine() interrupt 1
{
	static int iCount = 0;
	iCount++;
	if(iCount == 1000)
	{
		P0_2 = ~P0_2;
		iCount = 0;
	}
	TH0 = 64535/256;
	TL0 = 64535%256;
}
*/