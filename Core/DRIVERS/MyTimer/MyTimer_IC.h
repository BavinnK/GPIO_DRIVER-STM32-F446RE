#ifndef MYTIMER_IC_H
#define MYTIMER_IC_H
#include "MyTimer_Base.h"
#include "stm32f446xx.h"
#include <stdint.h>
#include "gpiox.h"
#include "MyTimer_PWM.h"

typedef enum{
	FALLING_EDGE=1,
	RISING_EDGE,
	BOTH_EDGES
}edge_captcure;
void TIMx_IC_init(TIM_TypeDef *TIMx,GPIO_TypeDef *port,uint8_t channel,edge_captcure edge,uint8_t pin,uint16_t pcs);
#endif
