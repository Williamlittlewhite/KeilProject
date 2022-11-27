#include <REGX51.H>
#include "Delay.h"
#include "UART.h"
//unsigned char Sec;
void main()
{
	 P0 = 0x00;
	 UART_Init();
	
   while(1)
   {
//      UART_SendByte(Sec);
//			Sec++;
//			Delay(1000);
   }
}

void UART_Routine() interrupt 4
{
	if(RI == 1)
	{
		P0 = SBUF;
		UART_SendByte(SBUF);
		RI = 0;
	}
}