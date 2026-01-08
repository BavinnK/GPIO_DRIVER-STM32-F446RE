#include "MyTimer_PWM.h"
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
static inline void pin_set_tim_chn(TIM_TypeDef *tim,GPIO_TypeDef*port,uint8_t pin,uint8_t chn){
	//this inline func is gonna be ugly as hell but its gonna be readable trust me lol
	if(port==GPIOA && tim==TIM2 && chn==1 && pin==0){//PA0
		port->AFR[0]&=~(0b1111<<(pin*4));
		port->AFR[0]|=(1<<(pin*4));
	}
	else if(port==GPIOA && tim==TIM5 && chn==1 && pin==0){//PA0
		port->AFR[0]&=~(0b1111<<(pin*4));
		port->AFR[0]|=(2<<(pin*4));
	}
	else if(port==GPIOA && tim==TIM2 && chn==2 && pin==1){//PA1
		port->AFR[0]&=~(0b1111<<(pin*4));
		port->AFR[0]|=(1<<(pin*4));
	}
	else if(port==GPIOA && tim==TIM5 && chn==2 && pin==1){//PA1
		port->AFR[0]&=~(0b1111<<(pin*4));
		port->AFR[0]|=(2<<(pin*4));
	}
	else if(port==GPIOA && tim==TIM2 && chn==1 && pin==5){//PA5
		port->AFR[0]&=~(0b1111<<(pin*4));
		port->AFR[0]|=(1<<(pin*4));
	}
	else if(port==GPIOA && tim==TIM13 && chn==1 && pin==6){//PA6
		port->AFR[0]&=~(0b1111<<(pin*4));
		port->AFR[0]|=(0b1001<<(pin*4));
	}
	else if(port==GPIOA && tim==TIM3 && chn==1 && pin==6){//PA6
		port->AFR[0]&=~(0b1111<<(pin*4));
		port->AFR[0]|=(2<<(pin*4));
	}
	else if(port==GPIOA && tim==TIM14 && chn==1 && pin==7){//PA7
		port->AFR[0]&=~(0b1111<<(pin*4));
		port->AFR[0]|=(0b1001<<(pin*4));
	}
	else if(port==GPIOA && tim==TIM3 && chn==2 && pin==7){//PA7
		port->AFR[0]&=~(0b1111<<(pin*4));
		port->AFR[0]|=(0b1001<<(pin*4));
	}
	else if(port==GPIOA && tim==TIM1 && chn==1 && pin==8){//PA8
		port->AFR[1]&=~(0b1111<<(pin*4));
		port->AFR[1]|=(1<<(pin*4));
	}
	else if(port==GPIOA && tim==TIM1 && chn==2 && pin==9){//PA9
		port->AFR[1]&=~(0b1111<<(pin*4));
		port->AFR[1]|=(1<<(pin*4));
	}
	else if(port==GPIOA && tim==TIM1 && chn==3 && pin==10){//PA10
		port->AFR[1]&=~(0b1111<<(pin*4));
		port->AFR[1]|=(1<<(pin*4));
	}
	else if(port==GPIOA && tim==TIM1 && chn==4 && pin==11){//PA11
		port->AFR[1]&=~(0b1111<<(pin*4));
		port->AFR[1]|=(1<<(pin*4));
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void TIMx_pwm_init(TIM_TypeDef * TIMx,GPIO_TypeDef *port,uint8_t pin,uint16_t pcs,uint16_t arr,uint8_t channel,uint8_t duty_cycle){
	gpio_set_up config;
	config.PINx=pin;
	config.MODERx=GPIOx_MODER_AF;
	config.OSPEEDRx=GPIOx_OSPEEDR_HIGH_SP;
	config.OTYPERx=GPIOx_OTYPER_PP;
	config.PUPDRx=GPIOx_PUPDR_NONE;
	gpio_init(port, &config);
	TIMx_base_init(TIMx, pcs, arr);



}
