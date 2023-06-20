################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Src/Config/Config.cpp 

OBJS += \
./Src/Config/Config.o 

CPP_DEPS += \
./Src/Config/Config.d 


# Each subdirectory must supply rules for building sources it contributes
Src/Config/%.o Src/Config/%.su: ../Src/Config/%.cpp Src/Config/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F407VGTx -DSTM32F407xx -DHSE_VALUE=25000000UL -c -I../Drivers/CMSIS -I../AppLibraries/User_Interface -I../AppLibraries/lvgl -I../AppLibraries/GateWay_API -I../AppLibraries/LoRa_API -I../AppLibraries/FT6236 -I../PeriphLibraries/TIM_F4xx -I../PeriphLibraries/SDMMC_F4xx -I../AppLibraries/DS3231 -I../AppLibraries/ESP32_API -I../AppLibraries/LORA -I../Src/Config -I../PeriphLibraries/PERIPH_STATUS -I../PeriphLibraries -I../PeriphLibraries/USART_F4xx -I../PeriphLibraries/STM_LOG -I../PeriphLibraries/SPI_F4xx -I../PeriphLibraries/SYSTEM_F4xx -I../PeriphLibraries/IT_F4xx -I../PeriphLibraries/RCC_F4xx -I../PeriphLibraries/GPIO_F4xx -I../PeriphLibraries/I2C_F4xx -I../AppLibraries/TFT16BIT -I../AppLibraries/SPIFLASH -I../PeriphLibraries/DMA_F4xx -I../Drivers/Devices -Ofast -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-Config

clean-Src-2f-Config:
	-$(RM) ./Src/Config/Config.d ./Src/Config/Config.o ./Src/Config/Config.su

.PHONY: clean-Src-2f-Config

