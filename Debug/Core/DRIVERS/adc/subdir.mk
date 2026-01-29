################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/DRIVERS/adc/MyAdc.c \
../Core/DRIVERS/adc/MyAdcDMA.c 

OBJS += \
./Core/DRIVERS/adc/MyAdc.o \
./Core/DRIVERS/adc/MyAdcDMA.o 

C_DEPS += \
./Core/DRIVERS/adc/MyAdc.d \
./Core/DRIVERS/adc/MyAdcDMA.d 


# Each subdirectory must supply rules for building sources it contributes
Core/DRIVERS/adc/%.o Core/DRIVERS/adc/%.su Core/DRIVERS/adc/%.cyclo: ../Core/DRIVERS/adc/%.c Core/DRIVERS/adc/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I"C:/Users/pc/Desktop/STM_PROJECTS/gpio_dri_stm32/Core/DRIVERS" -I"C:/Users/pc/Desktop/STM_PROJECTS/gpio_dri_stm32/Core/EXAMPLE_DRIVERS" -I"C:/Users/pc/Desktop/STM_PROJECTS/gpio_dri_stm32/Core/DRIVERS/hcsr04" -I"C:/Users/pc/Desktop/STM_PROJECTS/gpio_dri_stm32/Core/DRIVERS/pwm" -I"C:/Users/pc/Desktop/STM_PROJECTS/gpio_dri_stm32/Core/DRIVERS/spi" -I"C:/Users/pc/Desktop/STM_PROJECTS/gpio_dri_stm32/Core/DRIVERS/usart" -I"C:/Users/pc/Desktop/STM_PROJECTS/gpio_dri_stm32/Core/DRIVERS/adc" -I"C:/Users/pc/Desktop/STM_PROJECTS/gpio_dri_stm32/Core/DRIVERS/gpio" -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-DRIVERS-2f-adc

clean-Core-2f-DRIVERS-2f-adc:
	-$(RM) ./Core/DRIVERS/adc/MyAdc.cyclo ./Core/DRIVERS/adc/MyAdc.d ./Core/DRIVERS/adc/MyAdc.o ./Core/DRIVERS/adc/MyAdc.su ./Core/DRIVERS/adc/MyAdcDMA.cyclo ./Core/DRIVERS/adc/MyAdcDMA.d ./Core/DRIVERS/adc/MyAdcDMA.o ./Core/DRIVERS/adc/MyAdcDMA.su

.PHONY: clean-Core-2f-DRIVERS-2f-adc

