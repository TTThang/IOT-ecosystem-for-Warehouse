################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../PeriphLibraries/SDIOMMC_F4xx/SDIOMMC_F4xx.cpp 

OBJS += \
./PeriphLibraries/SDIOMMC_F4xx/SDIOMMC_F4xx.o 

CPP_DEPS += \
./PeriphLibraries/SDIOMMC_F4xx/SDIOMMC_F4xx.d 


# Each subdirectory must supply rules for building sources it contributes
PeriphLibraries/SDIOMMC_F4xx/%.o PeriphLibraries/SDIOMMC_F4xx/%.su: ../PeriphLibraries/SDIOMMC_F4xx/%.cpp PeriphLibraries/SDIOMMC_F4xx/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F407VGTx -DSTM32F407xx -DHSE_VALUE=25000000UL -c -I../Drivers/CMSIS -I../PeriphLibraries/SDIOMMC_F4xx/Middleware -I../PeriphLibraries/SDIOMMC_F4xx/SDIOMMC_Driver -I../PeriphLibraries/SDIOMMC_F4xx -I../PeriphLibraries/SDIOMMC_F4xx/Application -I../AppLibraries/DS3231 -I../AppLibraries/LORA -I../Src/Config -I../PeriphLibraries/PERIPH_STATUS -I../PeriphLibraries -I../PeriphLibraries/USART_F4xx -I../PeriphLibraries/STM_LOG -I../PeriphLibraries/SPI_F4xx -I../PeriphLibraries/SYSTEM_F4xx -I../PeriphLibraries/IT_F4xx -I../PeriphLibraries/RCC_F4xx -I../PeriphLibraries/GPIO_F4xx -I../PeriphLibraries/I2C_F4xx -I../AppLibraries/TFT16BIT -I../AppLibraries/SPIFLASH -I../PeriphLibraries/DMA_F4xx -I../Drivers/Devices -O1 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-PeriphLibraries-2f-SDIOMMC_F4xx

clean-PeriphLibraries-2f-SDIOMMC_F4xx:
	-$(RM) ./PeriphLibraries/SDIOMMC_F4xx/SDIOMMC_F4xx.d ./PeriphLibraries/SDIOMMC_F4xx/SDIOMMC_F4xx.o ./PeriphLibraries/SDIOMMC_F4xx/SDIOMMC_F4xx.su

.PHONY: clean-PeriphLibraries-2f-SDIOMMC_F4xx

