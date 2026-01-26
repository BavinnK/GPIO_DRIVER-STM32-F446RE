#ifndef MYI2C_H
#define MYI2C_H
#include "stm32f446xx.h"
#include <stdint.h>
#include "gpiox.h"

void I2Cx_init(I2C_TypeDef *I2Cx);
void I2Cx_start(I2C_TypeDef *I2Cx);
void I2Cx_stop(I2C_TypeDef *I2Cx);
void I2Cx_write(I2C_TypeDef *I2Cx, uint8_t slave_addr, uint8_t register_addr, uint8_t data);
#endif
