################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/DRIVERS/MyTimer/MyTimer_Base.c \
../Core/DRIVERS/MyTimer/MyTimer_PWM.c 

OBJS += \
./Core/DRIVERS/MyTimer/MyTimer_Base.o \
./Core/DRIVERS/MyTimer/MyTimer_PWM.o 

C_DEPS += \
./Core/DRIVERS/MyTimer/MyTimer_Base.d \
./Core/DRIVERS/MyTimer/MyTimer_PWM.d 


# Each subdirectory must supply rules for building sources it contributes
Core/DRIVERS/MyTimer/%.o Core/DRIVERS/MyTimer/%.su Core/DRIVERS/MyTimer/%.cyclo: ../Core/DRIVERS/MyTimer/%.c Core/DRIVERS/MyTimer/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I"C:/Users/pc/Desktop/STM_PROJECTS/gpio_dri_stm32/Core/DRIVERS" -I"C:/Users/pc/Desktop/STM_PROJECTS/gpio_dri_stm32/Core/EXAMPLE_DRIVERS" -I"C:/Users/pc/Desktop/STM_PROJECTS/gpio_dri_stm32/Core/DRIVERS/hcsr04" -I"C:/Users/pc/Desktop/STM_PROJECTS/gpio_dri_stm32/Core/DRIVERS/pwm" -I"C:/Users/pc/Desktop/STM_PROJECTS/gpio_dri_stm32/Core/DRIVERS/spi" -I"C:/Users/pc/Desktop/STM_PROJECTS/gpio_dri_stm32/Core/DRIVERS/usart" -I"C:/Users/pc/Desktop/STM_PROJECTS/gpio_dri_stm32/Core/DRIVERS/adc" -I"C:/Users/pc/Desktop/STM_PROJECTS/gpio_dri_stm32/Core/DRIVERS/gpio" -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-DRIVERS-2f-MyTimer

clean-Core-2f-DRIVERS-2f-MyTimer:
	-$(RM) ./Core/DRIVERS/MyTimer/MyTimer_Base.cyclo ./Core/DRIVERS/MyTimer/MyTimer_Base.d ./Core/DRIVERS/MyTimer/MyTimer_Base.o ./Core/DRIVERS/MyTimer/MyTimer_Base.su ./Core/DRIVERS/MyTimer/MyTimer_PWM.cyclo ./Core/DRIVERS/MyTimer/MyTimer_PWM.d ./Core/DRIVERS/MyTimer/MyTimer_PWM.o ./Core/DRIVERS/MyTimer/MyTimer_PWM.su

.PHONY: clean-Core-2f-DRIVERS-2f-MyTimer

