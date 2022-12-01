#ifndef __MatrixLED_H__
#define __MatrixLED_H__
void _74HC595_WriteByte(unsigned char Byte);
void MatrixLED_showColumn(unsigned char column, Data);
void MatrixLED_Init();
#endif
