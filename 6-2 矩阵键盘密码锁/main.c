#include <REGX51.H>
#include "Delay.h"
#include "MatrixKey.h"
#include "display.h"
#define W 2222  //��ȷ����������������
unsigned char keynum;
unsigned int password;
//��������������������� ������ֻ������0~9  1~9֮��İ���Ϊȷ����
//�õ�Ƭ�����һ���ǻ���
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
					password *= 10;       //������Ӧ�����밴��
					password += keynum;
					display(pos,keynum);
					pos++;
					cnt++;
				}
			else
				{
					if(keynum == 0)   //1~9֮����ܰ�����ʾȷ������
					{
						if(password == W)
						{
							display(7,10);//�������ʾA��ʾ��ȷ
							password = 0;
							cnt = 0;
							pos = 1;
						}
						else
						{
							display(8,15);//�������ʾF��ʾ����
							password = 0;
							cnt = 0;
							pos = 1;
						}
					}
				}
			}	
		}
}