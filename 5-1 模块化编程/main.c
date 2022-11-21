#include <REGX51.H>
#include "Delay.h"
void main()
{
	P1_0 = 0;
	P1_1 = 0;
	P1_2 = 0;
	while(1)
	{
		P0 = 0x25;
		Delay(500);
		P0 = 0x52;
		Delay(500);
	}
}