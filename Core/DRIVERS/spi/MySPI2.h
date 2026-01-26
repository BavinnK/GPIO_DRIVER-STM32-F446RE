#ifndef MYSPI2_H
#define MYSPI2_H
#include "stdint.h"
#include "stm32f446xx.h"
#include "gpiox.h"
#include "stdlib.h"

typedef enum{
	MSB=1,
	LSB
}spi_frame_format;
void SPI2_init(GPIO_TypeDef *port,uint8_t CS,uint32_t frequency_Mhz,spi_frame_format format);
uint8_t SPI2_Receive_Transmit(GPIO_TypeDef *port,uint8_t CS,uint8_t data);
void SPI2_CS_select(GPIO_TypeDef *port,uint8_t CS);
void SPI2_CS_deselect(GPIO_TypeDef *port,uint8_t CS);

#endif
