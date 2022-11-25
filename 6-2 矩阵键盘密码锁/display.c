#include <REGX51.H>
unsigned char NixieTable[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,
0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71,0x00};
void display(unsigned char pos,unsigned char num)
{
	switch(pos)
	{
		case 1:
			P2_0 = 0;
			P2_1 = 0;
			P2_2 = 0;
			break;
		case 2:
			P2_0 = 1;
			P2_1 = 0;
			P2_2 = 0;
			break;
		case 3:
			P2_0 = 0;
			P2_1 = 1;
			P2_2 = 0;
			break;
		case 4:
			P2_0 = 1;
			P2_1 = 1;
			P2_2 = 0;
			break;
		case 5:
			P2_0 = 0;
			P2_1 = 0;
			P2_2 = 1;
			break;
		case 6:
			P2_0 = 1;
			P2_1 = 0;
			P2_2 = 1;
			break;
		case 7:
			P2_0 = 0;
			P2_1 = 1;
			P2_2 = 1;
			break;
		case 8:
			P2_0 = 1;
			P2_1 = 1;
			P2_2 = 1;
			break;
	}
	P0 = NixieTable[num];
}