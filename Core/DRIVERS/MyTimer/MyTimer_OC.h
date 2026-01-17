#ifndef MYTIMER_H
#define MYTIMER_H
#include "MyTimer_Base.h"
#include "stm32f446xx.h"
#include <stdint.h>
#include "gpiox.h"
#include "MyTimer_PWM.h"

typedef enum{
	SET=1,
	RESET,
	TOGGLE
}TIMx_OC_MODE;


#endif
