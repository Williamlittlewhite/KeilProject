#include <REGX51.H>
#include <INTRINS.H>
void Delay500ms()
{
	unsigned char i,j,k;
	
	_nop_();
	i = 4;
	j = 205;
	k = 107;
	do{
		do{
			while(--k);
		}while(--j);
	}while(--i);
}
void main()
{
	while(1){
			P1 = 0x01;
			Delay500ms();
			P1 = 0x00;
			Delay500ms();
	}
}