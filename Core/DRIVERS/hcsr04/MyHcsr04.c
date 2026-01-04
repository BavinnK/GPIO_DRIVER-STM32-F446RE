#include <MyHcsr04.h>


#define TOP_VAL 0xFFFF
volatile uint32_t start_time = 0, end_time = 0, diffrence = 0;
volatile uint8_t is_first_cap = 0;
static inline void port_init(GPIO_TypeDef *ptr){
	if(ptr==GPIOA){
			RCC->AHB1ENR|=(1<<0);//enable GPIOA
		}
		else if(ptr==GPIOB){
			RCC->AHB1ENR|=(1<<1);//enable GPIOB
		}
		else if(ptr==GPIOC){
			RCC->AHB1ENR|=(1<<2);//enable GPIOC
		}
		else{
			while(1);//error
		}
}
static inline void AFR_init(GPIO_TypeDef *ptr,uint8_t echo_pin){
	if(echo_pin>=0&&echo_pin<=7){
		ptr->AFR[0]&=~((0b1111<<(echo_pin*4)));//clear the bits first
		ptr->AFR[0]|=(1<<echo_pin*4);
	}
	else if(echo_pin>=8&&echo_pin<=15){
		ptr->AFR[1]&=~((0b1111<<((echo_pin-8)*4)));//clear the bits first. you may think why we -8 the ehco pin cuz the high part of AFR reg starts from 0
		ptr->AFR[1]|=(1<<((echo_pin-8)*4));
	}
	else {
		while(1);//error  handler
	}
}
void hcsr04_init(GPIO_TypeDef *trig_port,GPIO_TypeDef *echo_port,uint8_t trig_pin,uint8_t echo_pin) {
	//trigger pin config
	port_init(trig_port);
	gpio_set_up trig_config;
	trig_config.PINx=trig_pin;
	trig_config.MODERx=GPIOx_MODER_OUTPUT;
	trig_config.OSPEEDRx=GPIOx_OSPEEDR_FAST_SP;
	trig_config.OTYPERx=GPIOx_OTYPER_PP;
	trig_config.PUPDRx=GPIOx_PUPDR_NONE;
	gpio_init(trig_port, &trig_config);
	//trig config done


	// echo pin config
	port_init(echo_port);
	gpio_set_up echo_config;
	echo_config.PINx=echo_pin;
	echo_config.MODERx=GPIOx_MODER_AF;
	echo_config.OSPEEDRx=GPIOx_OSPEEDR_HIGH_SP;
	echo_config.OTYPERx=GPIOx_OTYPER_PP;
	echo_config.PUPDRx=GPIOx_PUPDR_NONE;
	gpio_init(echo_port, &echo_config);
	AFR_init(echo_port, echo_pin);

	//TIMER 1 conifuration
	//we will set the freq of the timer to 1Mhz so each tick is 1us
	//and we will set CH1 as normal input mode
	TIM1->PSC = 89;
	TIM1->ARR = 0xFFFF;	//we want the timer to count as long as possible for the 16 bit is 65536
	TIM1->CCMR1 &= ~(0b11);
	TIM1->CCMR1 |= (0b01 << 0);
	TIM1->CCER |= (1 << 3) | (1 << 1) | (1 << 0);
	TIM1->CR1 |= (1 << 0);

	//now for the INT coniguration
	TIM1->DIER |= (1 << 1);
	//NVIC_EnableIRQ(TIM1_CC_IRQn);
}

void TIM1_CC_IRQHandler(void) {

	if (TIM1->SR & (1 << 1)) {
		if (is_first_cap == 0) {
			//when is_first_cap is 0 it means its rising edge
			start_time = TIM1->CCR1;
			is_first_cap = 1;
		} else {
			end_time = TIM1->CCR1;

			if (start_time < end_time) {
				diffrence = end_time - start_time;
			} else if (start_time > end_time) {
				//when this condition is true means that the ARR got overflowed and reseted to zero
				//got this from AI but its genius, we do this
				//first we make the starttime as smaller than the endtime so we dont get a minus value and thats it and we do our calculation
				diffrence = (TOP_VAL - start_time) + end_time;


			}

			is_first_cap = 0;

		}

		TIM1->SR &= ~(1 << 1);//clear manually

	}

}
//the interrupt is done
//quick and dirty delay in us
void delay_us_hc(uint32_t us) {
	for (uint32_t i = 0; i < us * 12; i++) {
		__asm__("nop");
	}
}
void hcsr04_trig_hc(GPIO_TypeDef *trig_port,uint8_t pin) {

	gpio_set(trig_port, pin);//HIGH
	delay_us_hc(10);						//small delay
	gpio_reset(trig_port, pin);//LOW
}
uint32_t  hcsr04_get_pulse_width(void){
	return diffrence;
}
