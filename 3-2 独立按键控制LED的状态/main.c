#include <REGX51.H>
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
	
void main()
{
	P0 = 0x00;
	while(1)
	{
		if(P1_0==0)
		{
			Delay(20);//∑¿÷π∞¥º¸∂∂∂Ø
			P0_0 = ~P0_0;
			while(!P1_0);
			Delay(20); //∑¿÷πÀ… ÷∂∂∂Ø
			
		}
	}
}