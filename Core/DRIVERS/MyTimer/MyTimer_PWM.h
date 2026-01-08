#ifndef MYTIMER_PWM_H_
#define MYTIMER_PWM_H_
#include "MyTimer_Base.h"
#include "stm32f446xx.h"
#include <stdint.h>
#include "gpiox.h"

void TIMx_pwm_init(TIM_TypeDef * TIMx,GPIO_TypeDef *port,uint8_t pin,uint16_t pcs,uint16_t arr,uint8_t channel,uint8_t duty_cycle);

#endif
