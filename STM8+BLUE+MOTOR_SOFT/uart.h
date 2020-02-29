#ifndef __UART_H
#define __UART_H

#include "stm8s.h"

void Uart1_Init(void);
void UART1_SendByte(u8 data);
void UART1_Sendstr(const unsigned char *p_str);
void Delay(uint16_t nCount);
#endif