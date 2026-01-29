#include <MyAdcDMA.h>

static inline GPIO_TypeDef* channel_setup(uint8_t port){//inline helper func for the GPIO port
	if(port>=0 && port<=7){
		return GPIOA;
	}
	else if(port>=8&&port<=9){
		return GPIOB;
	}
	else if(port>=10&&port<=15){
		return GPIOC;
	}
	else{
		while(1);//error
	}
}
static inline void adc_setuo(ADC_TypeDef *ptr){
	if(ptr==ADC1){
		RCC->APB2ENR|=(1<<8);//enable adc1
	}
	else if(ptr==ADC2){
		RCC->APB2ENR|=(1<<9);//enable adc2
	}
	else if(ptr==ADC3){
		RCC->APB2ENR|=(1<<10);//enable adc3
	}
	else{
		while(1);//error
	}
}
static inline void channel_adc(ADC_TypeDef *adc_port,uint8_t chn,uint8_t sample){
	if(chn>=0&&chn<=9){
		adc_port->SMPR2&=~((0b111<<(chn*3)));
		adc_port->SMPR2|=(sample<<(chn*3));

	}
	else if(chn>=10&&chn<=15){
		adc_port->SMPR1&=~((0b111<<(chn*3)));
		adc_port->SMPR1|=(sample<<(chn*3));
	}
}
void adc_dma_init(ADC_TypeDef *adc_port,adc_config_t *ptr,DMA_TypeDef *DMAx,DMA_config_t* DMAx_config) {

	gpio_set_up config;
	config.MODERx=GPIOx_MODER_ANALOG;
	config.OSPEEDRx=GPIOx_OSPEEDR_LOW_SP;//dont care for adc
	config.OTYPERx=GPIOx_OTYPER_PP;//dont care for adc
	config.PINx=ptr->channel;
	config.PUPDRx=GPIOx_PUPDR_NONE;
	GPIO_TypeDef *port=channel_setup(ptr->channel);
	gpio_init(port, &config);
	adc_setuo(adc_port);

	//enable ADCx
	adc_port->CR2 |= (1 << 0);
	adc_port->CR2&=~(1<<30);//disable conversion
	//small delay to let ADC stabilize
	for (volatile int i = 0; i < 1000; i++);


	adc_port->CR2 |= (3<<8);

	DMAx_init(DMAx, DMAx_config);
	adc_port->CR2|=(1<<30);
}


