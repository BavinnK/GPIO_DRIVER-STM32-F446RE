#ifndef MYUSART2_H
#define MYUSART2_H

#include "stdint.h"
#include "stm32f446xx.h"


void send_str(char * ptr,uint32_t length);
void USART2_init(void);

#endif
