#include <REGX51.H>
#include "Delay.h"
#include "MatrixKey.h"
#include "display.h"
unsigned char keynum;
//该单片机最后一列是坏的
void main()
{
	unsigned char pos = 1;
	while(1)
	{
		keynum = MatrixKey();
		if(keynum)
			display(pos,keynum);
	}
}