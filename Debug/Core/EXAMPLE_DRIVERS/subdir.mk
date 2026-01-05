################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/EXAMPLE_DRIVERS/adc_example.c \
../Core/EXAMPLE_DRIVERS/hcsr04_example.c \
../Core/EXAMPLE_DRIVERS/usart_example.c 

OBJS += \
./Core/EXAMPLE_DRIVERS/adc_example.o \
./Core/EXAMPLE_DRIVERS/hcsr04_example.o \
./Core/EXAMPLE_DRIVERS/usart_example.o 

C_DEPS += \
./Core/EXAMPLE_DRIVERS/adc_example.d \
./Core/EXAMPLE_DRIVERS/hcsr04_example.d \
./Core/EXAMPLE_DRIVERS/usart_example.d 


# Each subdirectory must supply rules for building sources it contributes
Core/EXAMPLE_DRIVERS/%.o Core/EXAMPLE_DRIVERS/%.su Core/EXAMPLE_DRIVERS/%.cyclo: ../Core/EXAMPLE_DRIVERS/%.c Core/EXAMPLE_DRIVERS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I"C:/Users/pc/Desktop/STM_PROJECTS/gpio_dri_stm32/Core/DRIVERS/hcsr04" -I"C:/Users/pc/Desktop/STM_PROJECTS/gpio_dri_stm32/Core/DRIVERS/pwm" -I"C:/Users/pc/Desktop/STM_PROJECTS/gpio_dri_stm32/Core/DRIVERS/spi" -I"C:/Users/pc/Desktop/STM_PROJECTS/gpio_dri_stm32/Core/DRIVERS/usart" -I"C:/Users/pc/Desktop/STM_PROJECTS/gpio_dri_stm32/Core/DRIVERS/adc" -I"C:/Users/pc/Desktop/STM_PROJECTS/gpio_dri_stm32/Core/DRIVERS/gpio" -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/pc/Desktop/STM_PROJECTS/gpio_dri_stm32/Core/DRIVERS" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-EXAMPLE_DRIVERS

clean-Core-2f-EXAMPLE_DRIVERS:
	-$(RM) ./Core/EXAMPLE_DRIVERS/adc_example.cyclo ./Core/EXAMPLE_DRIVERS/adc_example.d ./Core/EXAMPLE_DRIVERS/adc_example.o ./Core/EXAMPLE_DRIVERS/adc_example.su ./Core/EXAMPLE_DRIVERS/hcsr04_example.cyclo ./Core/EXAMPLE_DRIVERS/hcsr04_example.d ./Core/EXAMPLE_DRIVERS/hcsr04_example.o ./Core/EXAMPLE_DRIVERS/hcsr04_example.su ./Core/EXAMPLE_DRIVERS/usart_example.cyclo ./Core/EXAMPLE_DRIVERS/usart_example.d ./Core/EXAMPLE_DRIVERS/usart_example.o ./Core/EXAMPLE_DRIVERS/usart_example.su

.PHONY: clean-Core-2f-EXAMPLE_DRIVERS

