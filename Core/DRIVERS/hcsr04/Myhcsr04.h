#ifndef HCSR04_H_
#define HCSR04_H_

#include "stm32f446xx.h"
#include <stdint.h>
#include "gpiox.h"

void hcsr04_init(GPIO_TypeDef *trig_port,GPIO_TypeDef *echo_port,uint8_t trig_pin,uint8_t echo_pin);
void hcsr04_trig_hc(GPIO_TypeDef *trig_port,uint8_t pin);
uint32_t hcsr04_get_pulse_width(void);
void delay_us_hc(uint32_t us);


#endif
