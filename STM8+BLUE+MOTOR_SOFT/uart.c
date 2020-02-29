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
    UART1_DeInit();		/* ���Ĵ�����ֵ��λ */

	/*
	 * ��UART1����Ϊ��
	 * ������ = 115200
	 * ����λ = 8
	 * 1λֹͣλ
	 * ��У��λ
	 * ʹ�ܽ��պͷ���
	 * ʹ�ܽ����ж�
	 */

    UART1_Init((u32)9600, UART1_WORDLENGTH_8D, UART1_STOPBITS_1, UART1_PARITY_NO , UART1_SYNCMODE_CLOCK_DISABLE , UART1_MODE_TXRX_ENABLE);
    UART1_ITConfig(UART1_IT_RXNE_OR, ENABLE);
    UART1_Cmd(ENABLE);
}

void UART1_SendByte(u8 data)
{
	UART1_SendData8((unsigned char)data);

	/* �ȴ�������� */
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

