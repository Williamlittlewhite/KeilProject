#include <REGX51.H>

unsigned char NixieTable[] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,
0x7D,0x07,0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71,0x00};

void Delay(unsigned int xms)
{
	unsigned char i,j;
	while(xms)
	{
		i = 2;
		j = 239;
		do{
			while(--j);
		}while(--i);
		xms--;
	}
}
	
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
	Delay(1); //消影，防止数码管重影 
	//如果不消除，那么位选-段选-位选 第三次位选会沿用第二次段选的信息
	P0 = 0x00;
}

void main()
{
	while(1)
	{
		Nixie(1,1);
		//Delay(200);
		Nixie(2,2);
		//Delay(200);
		Nixie(3,3);
		//Delay(200);
	}
}