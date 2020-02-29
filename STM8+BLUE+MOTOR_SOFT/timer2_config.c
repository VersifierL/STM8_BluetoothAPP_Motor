#include "timer2_config.h"
#include "uart.h"
//#define CCR1_Val  ((uint16_t)1500)
/***************************************
*               TIMER1初始化
*           检测外部频率和脉冲
***************************************/
void timer2_init(int value)
{

  TIM2_DeInit();  
  
  TIM2_TimeBaseInit(TIM2_PRESCALER_16, 20000-1);
//  TIM2_OC2Init(TIM2_OCMODE_PWM1, TIM2_OUTPUTSTATE_ENABLE, 800, TIM2_OCPOLARITY_HIGH);
  TIM2_OC1Init(TIM2_OCMODE_PWM1, TIM2_OUTPUTSTATE_ENABLE, value, TIM2_OCPOLARITY_HIGH);

  /* TIM1 counter enable */
  TIM2_Cmd(ENABLE);
  
}



