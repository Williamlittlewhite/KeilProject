#include <REGX51.H>
#include "Delay.h"
#include "MatrixKey.h"
#include "display.h"
unsigned char keynum;
//�õ�Ƭ�����һ���ǻ���
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