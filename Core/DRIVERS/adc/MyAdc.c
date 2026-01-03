#include <MYadc.h>

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
void adc_init(ADC_TypeDef *adc_port,adc_config_t *ptr) {

	gpio_set_up config;
	config.MODERx=GPIOx_MODER_ANALOG;
	config.OSPEEDRx=GPIOx_OSPEEDR_LOW_SP;//dont care for adc
	config.OTYPERx=GPIOx_OTYPER_PP;//dont care for adc
	config.PINx=ptr->channel;
	config.PUPDRx=GPIOx_PUPDR_NONE;
	GPIO_TypeDef *port=channel_setup(ptr->channel);
	gpio_init(port, &config);
	adc_setuo(adc_port);

	// Enable ADCx
	adc_port->CR2 |= (1 << 0);

	// Small delay to let ADC stabilize
	for (volatile int i = 0; i < 10000; i++);

	// Calibrate ADC (IMPORTANT to remove offset error)
	adc_port->CR2 |= (1 << 3);
	while (adc_port->CR2 & (1 << 3));	// wait until calibration finishes
}

uint16_t adc_read(ADC_TypeDef *adc_port,uint8_t channel) {

	// Clear SQ1 (we use only one conversion)
	adc_port->SQR3 &= ~(0b11111);


	adc_port->SQR3 |= channel;

	// Start conversion by software
	adc_port->CR2 &= ~(1 << 30);	// reset state
	adc_port->CR2 |= (1 << 30);		// start conversion

	// Wait until conversion is complete
	while (!(adc_port->SR & (1 << 1)));

	// Reading DR clears EOC flag automatically
	return adc_port->DR;
}
