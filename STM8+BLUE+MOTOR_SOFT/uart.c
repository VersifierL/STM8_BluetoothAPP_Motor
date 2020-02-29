#include "uart.h"

void Delay(uint16_t nCount)
{
  /* Decrement nCount value */
  while (nCount != 0)
  {   
    nCount--;
  }
}

void Uart1_Init(void)
{
    UART1_DeInit();		/* 将寄存器的值复位 */

	/*
	 * 将UART1配置为：
	 * 波特率 = 115200
	 * 数据位 = 8
	 * 1位停止位
	 * 无校验位
	 * 使能接收和发送
	 * 使能接收中断
	 */

    UART1_Init((u32)9600, UART1_WORDLENGTH_8D, UART1_STOPBITS_1, UART1_PARITY_NO , UART1_SYNCMODE_CLOCK_DISABLE , UART1_MODE_TXRX_ENABLE);
    UART1_ITConfig(UART1_IT_RXNE_OR, ENABLE);
    UART1_Cmd(ENABLE);
}

void UART1_SendByte(u8 data)
{
	UART1_SendData8((unsigned char)data);

	/* 等待传输结束 */
	while (UART1_GetFlagStatus(UART1_FLAG_TXE) == RESET);
}

void UART1_Sendstr(const unsigned char *p_str)
{
//  u8 i = 0;
  while(*p_str != '\0')
  {
    UART1_SendByte(*p_str);
 //   Delay(1000);
    p_str++;
  }
}

