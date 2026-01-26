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
void I2Cx_start(I2C_TypeDef *I2Cx){
	I2Cx->CR1|=(1<<8);
	while(!(I2Cx->SR1&(1<<0)));//wait until  I2C is ready
}
void I2Cx_stop(I2C_TypeDef *I2Cx){
	I2Cx->CR1|=(1<<9);
}

void I2Cx_write(I2C_TypeDef *I2Cx, uint8_t slave_addr, uint8_t register_addr, uint8_t data){
	I2Cx_start(I2Cx);

	I2Cx->DR=(slave_addr<<1);//the slave addr should be 7 bit with the first bit which is bit 0 should be zero its called R/W bit
	while(!(I2Cx->SR1&(1<<1)));

	(void)I2Cx->SR1; (void)I2Cx->SR2;//clear ADDR manually

	//we read both registers to clear ADDR bit in SR1

	I2Cx->DR=register_addr;
	while(!(I2Cx->SR1&(1<<7)));

	I2Cx->DR=data;
	while(!(I2Cx->SR1&(1<<7)));

	I2Cx_stop(I2Cx);
}

void I2Cx_read(I2C_TypeDef *I2Cx,uint8_t slave_addr, uint8_t register_addr, uint8_t data_length, uint8_t *buffer){

	I2Cx_start(I2Cx);

	I2Cx->DR=(slave_addr<<1);//the slave addr should be 7 bit with the first bit which is bit 0 should be zero its called R/W bit
	while(!(I2Cx->SR1&(1<<1)));

	(void)I2Cx->SR1; (void)I2Cx->SR2;

	I2Cx->DR=register_addr;
	while(!(I2Cx->SR1&(1<<7)));

	//THEN WE DO REAPETED START

	I2Cx_start(I2Cx);

	I2Cx->DR=(slave_addr<<1)|1;//we send the slave addr again but with R/W = 1
	while(!(I2Cx->SR1&(1<<1)));
	if(data_length==1){
		I2Cx->CR1&=~(1<<10);//send NACK
		(void)I2Cx->SR1; (void)I2Cx->SR2;
		I2Cx_stop(I2Cx);
		while(!(I2Cx->SR1&(1<<6)));
		buffer[0]=I2Cx->DR;
	}
	else if(data_length==2){

	}
	(void)I2Cx->SR1; (void)I2Cx->SR2;

	for(uint8_t i=0;i<data_length;i++){
		if(i==data_length-1){
			I2Cx->CR1&=~(1<<10);//send NACK
			I2Cx_stop(I2Cx);
		}
		else{
			I2Cx->CR1|=(1<<10);//send ACK
		}
		while(!(I2Cx->SR1&(1<<6)));
		buffer[i]=I2Cx->DR;
	}

}
