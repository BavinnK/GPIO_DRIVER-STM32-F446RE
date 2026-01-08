#ifndef MYTIMER_BASE_H_
#define MYTIMER_BASE_H_

#include "stm32f446xx.h"
#include <stdint.h>
#include "gpiox.h"//we might need this lib too but not sure yet

void TIM_base_init(TIM_TypeDef * TIMx,uint16_t pcs,uint16_t arr);
void TIM_base_start(TIM_TypeDef *TIMx);
void TIM_base_reset(TIM_TypeDef *TIMx);
void TIM_base_stop(TIM_TypeDef *TIMx);






#endif
