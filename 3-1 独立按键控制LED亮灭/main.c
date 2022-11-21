#include <REGX51.H>
void main()
{
	P0 = 0x00;
	while(1)
	{
		P0_0 = ~P1_0;
	}
}