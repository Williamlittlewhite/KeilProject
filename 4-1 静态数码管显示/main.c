#include <REGX51.H>

unsigned char NixieTable[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,
0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71,0x00};

void Nixie(unsigned char Location,unsigned int number)
{
	switch(Location)
	{
		case 1:
			P1_0 = 0;
			P1_1 = 0;
			P1_2 = 0;
			break;
		case 2:
			P1_0 = 1;
			P1_1 = 0;
			P1_2 = 0;
			break;
		case 3:
			P1_0 = 0;
			P1_1 = 1;
			P1_2 = 0;
			break;
		case 4:
			P1_0 = 1;
			P1_1 = 1;
			P1_2 = 0;
			break;
		case 5:
			P1_0 = 0;
			P1_1 = 0;
			P1_2 = 1;
			break;
		case 6:
			P1_0 = 1;
			P1_1 = 0;
			P1_2 = 1;
			break;
		case 7:
			P1_0 = 0;
			P1_1 = 1;
			P1_2 = 1;
			break;
		case 8:
			P1_0 = 1;
			P1_1 = 1;
			P1_2 = 1;
			break;
	}
	P0 = NixieTable[number];
}

void main()
{
	Nixie(5,4);
	while(1)
	{
	}
}