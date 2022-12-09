#include <REGX51.H>
#include "delay.h"
unsigned char Key()
{
	unsigned char KeyNumber = 0;
	
	if(P1_0 == 0) {Delay(20);while(P1_0 == 0);Delay(20);KeyNumber = 1;}
	if(P1_1 == 0) {Delay(20);while(P1_1 == 0);Delay(20);KeyNumber = 2;}
	if(P1_2 == 0) {Delay(20);while(P1_2 == 0);Delay(20);KeyNumber = 3;}
	if(P1_3 == 0) {Delay(20);while(P1_3 == 0);Delay(20);KeyNumber = 4;}
	if(P1_4 == 0) {Delay(20);while(P1_4 == 0);Delay(20);KeyNumber = 5;}
	if(P1_5 == 0) {Delay(20);while(P1_5 == 0);Delay(20);KeyNumber = 6;}
	if(P1_6 == 0) {Delay(20);while(P1_6 == 0);Delay(20);KeyNumber = 7;}
	if(P1_7 == 0) {Delay(20);while(P1_7 == 0);Delay(20);KeyNumber = 8;}
	
	return KeyNumber;
}