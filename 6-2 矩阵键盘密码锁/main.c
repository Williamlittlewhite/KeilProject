#include <REGX51.H>
#include "Delay.h"
#include "MatrixKey.h"
#include "display.h"
#define W 2222  //正确的密码设置在这里
unsigned char keynum;
unsigned int password;
//基于译码器的密码锁设计 密码锁只能输入0~9  1~9之外的按键为确定键
//该单片机最后一列是坏的
void main()
{
	unsigned int pos = 1;
	unsigned int cnt = 0;
	while(1)
	{
		keynum = MatrixKey();
		if(keynum)
		{
			if(keynum>=10) keynum = 0;
			if(cnt<4)
				{
					password *= 10;       //生成相应的密码按键
					password += keynum;
					display(pos,keynum);
					pos++;
					cnt++;
				}
			else
				{
					if(keynum == 0)   //1~9之外的密按键表示确定密码
					{
						if(password == W)
						{
							display(7,10);//数码管显示A表示正确
							password = 0;
							cnt = 0;
							pos = 1;
						}
						else
						{
							display(8,15);//数码管显示F表示错误
							password = 0;
							cnt = 0;
							pos = 1;
						}
					}
				}
			}	
		}
}