#include "MyUsart.h"

void Usart2_init(uint32_t baudRate){
	gpio_set_up config_RX,config_TX;
	config_RX.PINx=3;
	config_RX.MODERx=GPIOx_MODER_AF;
	config_RX.OSPEEDRx=GPIOx_OSPEEDR_HIGH_SP;
	config_RX.OTYPERx=GPIOx_OTYPER_PP;
	config_RX.PUPDRx=GPIOx_PUPDR_UP;

	config_TX.PINx=2;
	config_TX.MODERx=GPIOx_MODER_AF;
	config_TX.OSPEEDRx=GPIOx_OSPEEDR_HIGH_SP;
	config_TX.OTYPERx=GPIOx_OTYPER_PP;
	config_TX.PUPDRx=GPIOx_PUPDR_NONE;

	gpio_init(GPIOA, &config_TX);
	gpio_init(GPIOA, &config_RX);

	GPIOA->AFR[0]&=((0b1111<<(2*4))|(0b1111<<(3*4)));
	GPIOA->AFR[0]|=(7<<2*4)|(7<<3*4);
}
