#ifndef MYTIMER_PWM_H
#define MYTIMER_PWM_H
#include "MyTimer_Base.h"
#include "stm32f446xx.h"
#include <stdint.h>
#include "gpiox.h"

void TIMx_pwm_init(TIM_TypeDef * TIMx,GPIO_TypeDef *port,uint8_t pin,uint16_t pcs,uint16_t arr,uint8_t channel,uint8_t duty_cycle);
uint32_t TIMx_get_data(TIM_TypeDef *TIMx,uint8_t channel);
void pin_set_tim_chn(TIM_TypeDef *tim,GPIO_TypeDef*port,uint8_t pin,uint8_t chn);
#endif
