#include <REGX51.H>

void UART_Init()
{
	SCON = 0x50;
	PCON |= 0x80;
	TMOD &= 0x0F;
	TMOD |= 0x20;
	TH1 = 0xF3;
	TL1 = 0xF3;
	IE = 0x90;
	TR1 = 1;
}

void UART_SendByte(unsigned char Byte)
{
	SBUF = Byte;
	while(TI == 0);
	TI = 0;
}

/*
void UART_Routine() interrupt 4
{
	if(RI == 1)
	{
		P0 = SBUF;
		UART_SendByte(SBUF);
		RI = 0;
	}
}
*/