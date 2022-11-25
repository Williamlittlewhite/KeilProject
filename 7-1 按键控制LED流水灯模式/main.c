#include <REGX51.H>
//#include "Timer0.h"
#include "Key.h"
#include "INTRINS.H"
unsigned char KeyNum,LEDMode;
void main()
{
	P0 = 0x01;
  Timer0Init();
	while(1)
	{
		KeyNum = Key();
		
		if(KeyNum == 1) 
		{
			LEDMode++;
			if(LEDMode == 2) LEDMode = 0;
		}
		if(KeyNum == 2) P0_1 = ~P0_1;
		if(KeyNum == 3) P0_2 = ~P0_2;
		if(KeyNum == 4) P0_3 = ~P0_3;
		
	}
}


void Timer0_Routine() interrupt 1
{
	static int iCount = 0;
	iCount++;
	if(iCount == 500)
	{
		iCount = 0;
		if(LEDMode == 0)
			P0 = _crol_(P0,1);
		if(LEDMode == 1)
			P0 = _cror_(P0,1);
	}
	TH0 = 64535/256;
	TL0 = 64535%256;
}