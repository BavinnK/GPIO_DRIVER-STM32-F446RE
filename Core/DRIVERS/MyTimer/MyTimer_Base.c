#include "MyTimer_Base.h"
typedef enum{
	TIMER_INVALID=0,
	TIMER1,
	TIMER2,
	TIMER3,
	TIMER4,
	TIMER5,
	TIMER6,
	TIMER7,
	TIMER8,
	TIMER9,
	TIMER10,
	TIMER11,
	TIMER12,
	TIMER13,
	TIMER14
}get_timer_id;
static inline get_timer_id set_timer(TIM_TypeDef *ptr){
	if(ptr==TIM1) return TIMER1;
	else if(ptr==TIM2) return TIMER2;
	else if(ptr==TIM3) return TIMER3;
	else if(ptr==TIM4) return TIMER4;
	else if(ptr==TIM5) return TIMER5;
	else if(ptr==TIM6) return TIMER6;
	else if(ptr==TIM7) return TIMER7;
	else if(ptr==TIM8) return TIMER8;
	else if(ptr==TIM9) return TIMER9;
	else if(ptr==TIM10) return TIMER10;
	else if(ptr==TIM11) return TIMER11;
	else if(ptr==TIM12) return TIMER12;
	else if(ptr==TIM13) return TIMER13;
	else if(ptr==TIM14) return TIMER14;
	else return 0;
}
static inline void tim_init(TIM_TypeDef *ptr){
	uint8_t tim_id=set_timer(ptr);
	switch(tim_id){
	case 1:
		RCC->APB2ENR|=(1<<0);
		break;
	case 2:
		RCC->APB1ENR|=(1<<0);
		break;
	case 3:
		RCC->APB1ENR|=(1<<1);
		break;
	case 4:
		RCC->APB1ENR|=(1<<2);
		break;
	case 5:
		RCC->APB1ENR|=(1<<3);
		break;
	case 6:
		RCC->APB1ENR|=(1<<4);
		break;
	case 7:
		RCC->APB1ENR|=(1<<5);
		break;
	case 8:
		RCC->APB2ENR|=(1<<1);
		break;
	case 9:
		RCC->APB2ENR|=(1<<16);
		break;
	case 10:
		RCC->APB2ENR|=(1<<17);
		break;
	case 11:
		RCC->APB2ENR|=(1<<18);
		break;
	case 12:
		RCC->APB1ENR|=(1<<6);
		break;
	case 13:
		RCC->APB1ENR|=(1<<7);
		break;
	case 14:
		RCC->APB1ENR|=(1<<8);
		break;
	default:
		//invalid timer
		break;
	}
}
void TIMx_base_init(TIM_TypeDef * TIMx,uint16_t pcs,uint16_t arr){
	tim_init(TIMx);
	TIMx->CR1&=~(1<<0);//turn the CNT off
	TIMx->PSC=pcs;
	TIMx->ARR=arr;
	TIMx->EGR|=(1<<0);//update the reg
	TIMx->CNT=0;//reset the counter if there is any data
}
void TIMx_base_start(TIM_TypeDef *TIMx){
	TIMx->CR1|=(1<<0);
}
void TIMx_base_reset(TIM_TypeDef *TIMx){
	TIMx->CNT=0;
}
void TIMx_base_stop(TIM_TypeDef *TIMx){
	TIMx->CR1&=~(1<<0);
}
