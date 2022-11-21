#include <REGX51.H>

void delay(unsigned int xms)
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

void main()
{
	P0 = 0x01;
	while(1)
	{
		if(P1_0 == 0)
		{
			delay(20);
			while(P1_0 == 0);
			delay(20);
			P0 <<= 1;
			if(!P0)
				P0 = 0x01;
		}
		if(P1_1 == 0)
		{
			delay(20);
			while(P1_1 == 0);
			delay(20);
			P0 >>= 1;
			if(!P0)
				P0 = 0x80;
		}
	}
	
}
