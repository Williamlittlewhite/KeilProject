#include <REGX51.H>
#include <INTRINS.H>
void Delayms(unsigned int xms) //@12.000MHz
{
	unsigned char i,j;
	while(xms)
	{
		i = 2;
		j = 239;
		do{
			while(--j);
		}while(--i);
		--xms;
	}
}
void main()
{
	P1 = 0x01;
	while(1)
	{
		if(P1==0x80)
			P1 = 0x01;
		Delayms(100);
		P1 <<= 1;
	}
}