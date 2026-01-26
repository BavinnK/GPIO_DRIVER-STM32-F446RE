################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/DRIVERS/i2c/MyI2C.c 

OBJS += \
./Core/DRIVERS/i2c/MyI2C.o 

C_DEPS += \
./Core/DRIVERS/i2c/MyI2C.d 


# Each subdirectory must supply rules for building sources it contributes
Core/DRIVERS/i2c/%.o Core/DRIVERS/i2c/%.su Core/DRIVERS/i2c/%.cyclo: ../Core/DRIVERS/i2c/%.c Core/DRIVERS/i2c/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I"C:/Users/pc/Desktop/STM_PROJECTS/gpio_dri_stm32/Core/DRIVERS" -I"C:/Users/pc/Desktop/STM_PROJECTS/gpio_dri_stm32/Core/EXAMPLE_DRIVERS" -I"C:/Users/pc/Desktop/STM_PROJECTS/gpio_dri_stm32/Core/DRIVERS/hcsr04" -I"C:/Users/pc/Desktop/STM_PROJECTS/gpio_dri_stm32/Core/DRIVERS/pwm" -I"C:/Users/pc/Desktop/STM_PROJECTS/gpio_dri_stm32/Core/DRIVERS/spi" -I"C:/Users/pc/Desktop/STM_PROJECTS/gpio_dri_stm32/Core/DRIVERS/usart" -I"C:/Users/pc/Desktop/STM_PROJECTS/gpio_dri_stm32/Core/DRIVERS/adc" -I"C:/Users/pc/Desktop/STM_PROJECTS/gpio_dri_stm32/Core/DRIVERS/gpio" -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-DRIVERS-2f-i2c

clean-Core-2f-DRIVERS-2f-i2c:
	-$(RM) ./Core/DRIVERS/i2c/MyI2C.cyclo ./Core/DRIVERS/i2c/MyI2C.d ./Core/DRIVERS/i2c/MyI2C.o ./Core/DRIVERS/i2c/MyI2C.su

.PHONY: clean-Core-2f-DRIVERS-2f-i2c

