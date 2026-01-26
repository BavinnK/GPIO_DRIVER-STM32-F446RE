#include "MyI2C.h"

static inline void i2c_set(I2C_TypeDef *ptr){
	gpio_set_up SDA_config,SCL_config;
	if(ptr==I2C1){
		RCC->APB1ENR|=(1<<21);
		SCL_config.PINx=6;//PB6
		SCL_config.MODERx=GPIOx_MODER_AF;
		SCL_config.OSPEEDRx=GPIOx_OSPEEDR_HIGH_SP;
		SCL_config.OTYPERx=GPIOx_OTYPER_OD;
		SCL_config.PUPDRx=GPIOx_PUPDR_UP;

		SDA_config.PINx=7;//PB7
		SDA_config.MODERx=GPIOx_MODER_AF;
		SDA_config.OSPEEDRx=GPIOx_OSPEEDR_HIGH_SP;
		SDA_config.OTYPERx=GPIOx_OTYPER_OD;
		SDA_config.PUPDRx=GPIOx_PUPDR_UP;

		gpio_init(GPIOB, &SCL_config);
		gpio_init(GPIOB, &SDA_config);

		GPIOB->AFR[0]&=~((0b1111<<7*4)|(0b1111<<6*4));
		GPIOB->AFR[0]|=(4<<7*4)|(4<<6*4);
	}
	else if(ptr==I2C2){
		RCC->APB1ENR|=(1<<22);
		SCL_config.PINx=10;//PB10
		SCL_config.MODERx=GPIOx_MODER_AF;
		SCL_config.OSPEEDRx=GPIOx_OSPEEDR_HIGH_SP;
		SCL_config.OTYPERx=GPIOx_OTYPER_OD;
		SCL_config.PUPDRx=GPIOx_PUPDR_UP;

		SDA_config.PINx=12;//PC12
		SDA_config.MODERx=GPIOx_MODER_AF;
		SDA_config.OSPEEDRx=GPIOx_OSPEEDR_HIGH_SP;
		SDA_config.OTYPERx=GPIOx_OTYPER_OD;
		SDA_config.PUPDRx=GPIOx_PUPDR_UP;

		gpio_init(GPIOB, &SCL_config);
		gpio_init(GPIOC, &SDA_config);

		GPIOB->AFR[1]&=~((0b1111<<(10-8)*4));
		GPIOC->AFR[1]&=~(0b1111<<(12-8)*4);

		GPIOB->AFR[1]|=(4<<(10-8)*4);
		GPIOC->AFR[1]|=(4<<(12-8)*4);
	}
	else if(ptr==I2C3){
		RCC->APB1ENR|=(1<<23);
		SCL_config.PINx=8;//PA8
		SCL_config.MODERx=GPIOx_MODER_AF;
		SCL_config.OSPEEDRx=GPIOx_OSPEEDR_HIGH_SP;
		SCL_config.OTYPERx=GPIOx_OTYPER_OD;
		SCL_config.PUPDRx=GPIOx_PUPDR_UP;

		SDA_config.PINx=9;//PC9
		SDA_config.MODERx=GPIOx_MODER_AF;
		SDA_config.OSPEEDRx=GPIOx_OSPEEDR_HIGH_SP;
		SDA_config.OTYPERx=GPIOx_OTYPER_OD;
		SDA_config.PUPDRx=GPIOx_PUPDR_UP;

		gpio_init(GPIOA, &SCL_config);
		gpio_init(GPIOC, &SDA_config);

		GPIOA->AFR[1]&=~(0b1111<<0);
		GPIOC->AFR[1]&=~(0b1111<<(9-8)*4);

		GPIOA->AFR[1]|=(4<<0);
		GPIOC->AFR[1]|=(4<<(9-8)*4);
	}
	else while(1);
}
void I2Cx_init(I2C_TypeDef *I2Cx){
	i2c_set(I2Cx);
	I2Cx->CR1&=~(1);//disable prepherial before modify
	I2Cx->CR2|=(42);
	I2Cx->CCR=210;
	I2Cx->TRISE=42;
	I2Cx->CR1|=1;
}
