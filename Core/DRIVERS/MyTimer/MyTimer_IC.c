#include "MyTimer_IC.h"
#define arr 0xFFFF
static inline void pin_set_tim_chn(TIM_TypeDef *tim,GPIO_TypeDef*port,uint8_t pin,uint8_t chn){//reused this inline func from the PWM driver
	//this inline func is gonna be ugly as hell but its gonna be readable trust me lol
	//GPIOA
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
	else if(port==GPIOA && tim==TIM2 && chn==1 && pin==15){//PA15
		port->AFR[1]&=~(0b1111<<(pin*4));
		port->AFR[1]|=(1<<(pin*4));
	}


	//GPIOB
	else if(port==GPIOB && tim==TIM3 && chn==3 && pin==0){//PB0
		port->AFR[0]&=~(0b1111<<(pin*4));
		port->AFR[0]|=(2<<(pin*4));
	}
	else if(port==GPIOB && tim==TIM2 && chn==2 && pin==2){//PB2
		port->AFR[0]&=~(0b1111<<(pin*4));
		port->AFR[0]|=(1<<(pin*4));
	}
	else if(port==GPIOB && tim==TIM3 && chn==1 && pin==4){//PB4
		port->AFR[0]&=~(0b1111<<(pin*4));
		port->AFR[0]|=(2<<(pin*4));
	}
	else if(port==GPIOB && tim==TIM3 && chn==2 && pin==5){//PB5
		port->AFR[0]&=~(0b1111<<(pin*4));
		port->AFR[0]|=(2<<(pin*4));
	}
	else if(port==GPIOB && tim==TIM4 && chn==1 && pin==6){//PB6
		port->AFR[0]&=~(0b1111<<(pin*4));
		port->AFR[0]|=(2<<(pin*4));
	}
	else if(port==GPIOB && tim==TIM2 && chn==4 && pin==7){//PB7
		port->AFR[0]&=~(0b1111<<(pin*4));
		port->AFR[0]|=(1<<(pin*4));
	}
	else if(port==GPIOB && tim==TIM10 && chn==1 && pin==8){//PB8
		port->AFR[1]&=~(0b1111<<(pin*4));
		port->AFR[1]|=(3<<(pin*4));
	}
	else if(port==GPIOB && tim==TIM2 && chn==1 && pin==8){//PB8
		port->AFR[1]&=~(0b1111<<(pin*4));
		port->AFR[1]|=(1<<(pin*4));
	}
	else if(port==GPIOB && tim==TIM4 && chn==3 && pin==8){//PB8
		port->AFR[1]&=~(0b1111<<(pin*4));
		port->AFR[1]|=(2<<(pin*4));
	}
	else if(port==GPIOB && tim==TIM11 && chn==1 && pin==9){//PB9
		port->AFR[1]&=~(0b1111<<(pin*4));
		port->AFR[1]|=(3<<(pin*4));
	}
	else if(port==GPIOB && tim==TIM2 && chn==2 && pin==9){//PB9
		port->AFR[1]&=~(0b1111<<(pin*4));
		port->AFR[1]|=(1<<(pin*4));
	}
	else if(port==GPIOB && tim==TIM4 && chn==4 && pin==9){//PB9
		port->AFR[1]&=~(0b1111<<(pin*4));
		port->AFR[1]|=(2<<(pin*4));
	}
	else if(port==GPIOB && tim==TIM2 && chn==3 && pin==10){//PB10
		port->AFR[1]&=~(0b1111<<(pin*4));
		port->AFR[1]|=(1<<(pin*4));
	}
	else if(port==GPIOB && tim==TIM12 && chn==1 && pin==14){//PB14
		port->AFR[1]&=~(0b1111<<(pin*4));
		port->AFR[1]|=(0b1001<<(pin*4));
	}
	else if(port==GPIOB && tim==TIM12 && chn==2 && pin==15){//PB15
		port->AFR[1]&=~(0b1111<<(pin*4));
		port->AFR[1]|=(0b1001<<(pin*4));
	}
	//GPIOC
	else if(port==GPIOC && tim==TIM3 && chn==1 && pin==6){//PC6
		port->AFR[0]&=~(0b1111<<(pin*4));
		port->AFR[0]|=(2<<(pin*4));
	}
	else if(port==GPIOC && tim==TIM8 && chn==1 && pin==6){//PC6
		port->AFR[0]&=~(0b1111<<(pin*4));
		port->AFR[0]|=(3<<(pin*4));
	}
	else if(port==GPIOC && tim==TIM3 && chn==2 && pin==7){//PC7
		port->AFR[0]&=~(0b1111<<(pin*4));
		port->AFR[0]|=(2<<(pin*4));
	}
	else if(port==GPIOC && tim==TIM8 && chn==2 && pin==7){//PC7
		port->AFR[0]&=~(0b1111<<(pin*4));
		port->AFR[0]|=(3<<(pin*4));
	}
	else if(port==GPIOC && tim==TIM3 && chn==3 && pin==8){//PC8
		port->AFR[1]&=~(0b1111<<(pin*4));
		port->AFR[1]|=(2<<(pin*4));
	}
	else if(port==GPIOC && tim==TIM8 && chn==3 && pin==8){//PC8
		port->AFR[1]&=~(0b1111<<(pin*4));
		port->AFR[1]|=(3<<(pin*4));
	}
	else if(port==GPIOC && tim==TIM3 && chn==4 && pin==9){//PC9
		port->AFR[1]&=~(0b1111<<(pin*4));
		port->AFR[1]|=(2<<(pin*4));
	}
	else if(port==GPIOC && tim==TIM8 && chn==4 && pin==9){//PC9
		port->AFR[1]&=~(0b1111<<(pin*4));
		port->AFR[1]|=(3<<(pin*4));
	}
}

static inline void set_chn(TIM_TypeDef *tim,uint8_t chn){
	if(chn==1){
		tim->CCMR1&=~(2<<1);
		tim->CCMR1|=(1);
	}
	else if(chn==2){
		tim->CCMR1&=~(2<<8);
		tim->CCMR1|=(1<<8);
	}
	else if(chn==3){
		tim->CCMR2&=~(2<<1);
		tim->CCMR2|=(1);
	}
	else if(chn==4){
		tim->CCMR2&=~(2<<8);
		tim->CCMR2|=(1<<8);
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void TIMx_IC_init(TIM_TypeDef *TIMx,GPIO_TypeDef *port,uint8_t channel,edge_captcure edge,uint8_t pin,uint16_t pcs ){
	gpio_set_up config;
	config.PINx=pin;
	config.MODERx=GPIOx_MODER_AF;
	config.OSPEEDRx=GPIOx_OSPEEDR_HIGH_SP;
	config.OTYPERx=GPIOx_OTYPER_PP;
	config.PUPDRx=GPIOx_PUPDR_NONE;

	gpio_init(port, &config);
	pin_set_tim_chn(TIMx, port, pin, channel);
	TIMx_base_init(TIMx, pcs, arr);

}
