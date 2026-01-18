################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/DRIVERS/usart/MyUsart.c \
../Core/DRIVERS/usart/RingBuffer.c \
../Core/DRIVERS/usart/myUSART2.c 

OBJS += \
./Core/DRIVERS/usart/MyUsart.o \
./Core/DRIVERS/usart/RingBuffer.o \
./Core/DRIVERS/usart/myUSART2.o 

C_DEPS += \
./Core/DRIVERS/usart/MyUsart.d \
./Core/DRIVERS/usart/RingBuffer.d \
./Core/DRIVERS/usart/myUSART2.d 


# Each subdirectory must supply rules for building sources it contributes
Core/DRIVERS/usart/%.o Core/DRIVERS/usart/%.su Core/DRIVERS/usart/%.cyclo: ../Core/DRIVERS/usart/%.c Core/DRIVERS/usart/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I"C:/Users/pc/Desktop/STM_PROJECTS/gpio_dri_stm32/Core/DRIVERS" -I"C:/Users/pc/Desktop/STM_PROJECTS/gpio_dri_stm32/Core/EXAMPLE_DRIVERS" -I"C:/Users/pc/Desktop/STM_PROJECTS/gpio_dri_stm32/Core/DRIVERS/hcsr04" -I"C:/Users/pc/Desktop/STM_PROJECTS/gpio_dri_stm32/Core/DRIVERS/pwm" -I"C:/Users/pc/Desktop/STM_PROJECTS/gpio_dri_stm32/Core/DRIVERS/spi" -I"C:/Users/pc/Desktop/STM_PROJECTS/gpio_dri_stm32/Core/DRIVERS/usart" -I"C:/Users/pc/Desktop/STM_PROJECTS/gpio_dri_stm32/Core/DRIVERS/adc" -I"C:/Users/pc/Desktop/STM_PROJECTS/gpio_dri_stm32/Core/DRIVERS/gpio" -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-DRIVERS-2f-usart

clean-Core-2f-DRIVERS-2f-usart:
	-$(RM) ./Core/DRIVERS/usart/MyUsart.cyclo ./Core/DRIVERS/usart/MyUsart.d ./Core/DRIVERS/usart/MyUsart.o ./Core/DRIVERS/usart/MyUsart.su ./Core/DRIVERS/usart/RingBuffer.cyclo ./Core/DRIVERS/usart/RingBuffer.d ./Core/DRIVERS/usart/RingBuffer.o ./Core/DRIVERS/usart/RingBuffer.su ./Core/DRIVERS/usart/myUSART2.cyclo ./Core/DRIVERS/usart/myUSART2.d ./Core/DRIVERS/usart/myUSART2.o ./Core/DRIVERS/usart/myUSART2.su

.PHONY: clean-Core-2f-DRIVERS-2f-usart

