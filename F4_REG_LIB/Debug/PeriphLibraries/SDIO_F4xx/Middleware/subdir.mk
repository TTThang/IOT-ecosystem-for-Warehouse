################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../PeriphLibraries/SDIO_F4xx/Middleware/diskio.c \
../PeriphLibraries/SDIO_F4xx/Middleware/ff.c \
../PeriphLibraries/SDIO_F4xx/Middleware/ff_gen_drv.c 

C_DEPS += \
./PeriphLibraries/SDIO_F4xx/Middleware/diskio.d \
./PeriphLibraries/SDIO_F4xx/Middleware/ff.d \
./PeriphLibraries/SDIO_F4xx/Middleware/ff_gen_drv.d 

OBJS += \
./PeriphLibraries/SDIO_F4xx/Middleware/diskio.o \
./PeriphLibraries/SDIO_F4xx/Middleware/ff.o \
./PeriphLibraries/SDIO_F4xx/Middleware/ff_gen_drv.o 


# Each subdirectory must supply rules for building sources it contributes
PeriphLibraries/SDIO_F4xx/Middleware/%.o PeriphLibraries/SDIO_F4xx/Middleware/%.su: ../PeriphLibraries/SDIO_F4xx/Middleware/%.c PeriphLibraries/SDIO_F4xx/Middleware/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F407VGTx -DSTM32F407xx -DHSE_VALUE=25000000UL -c -I../Drivers/Devices -I../AppLibraries/DS3231 -I../PeriphLibraries -I../Src/Config -I../PeriphLibraries/STM_LOG -I../PeriphLibraries/A7602E -I../PeriphLibraries/PERIPH_STATUS -I../PeriphLibraries/SYSTEM_F4xx -I../PeriphLibraries/USART_F4xx -I../PeriphLibraries/RCC_F4xx -I../PeriphLibraries/SPI_F4xx -I../PeriphLibraries/I2C_F4xx -I../PeriphLibraries/IT_F4xx -I../PeriphLibraries/DMA_F4xx -I../PeriphLibraries/GPIO_F4xx -I../Drivers/CMSIS -I../AppLibraries/SPIFLASH -I../AppLibraries/LORA -I../AppLibraries/TFT16BIT -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-PeriphLibraries-2f-SDIO_F4xx-2f-Middleware

clean-PeriphLibraries-2f-SDIO_F4xx-2f-Middleware:
	-$(RM) ./PeriphLibraries/SDIO_F4xx/Middleware/diskio.d ./PeriphLibraries/SDIO_F4xx/Middleware/diskio.o ./PeriphLibraries/SDIO_F4xx/Middleware/diskio.su ./PeriphLibraries/SDIO_F4xx/Middleware/ff.d ./PeriphLibraries/SDIO_F4xx/Middleware/ff.o ./PeriphLibraries/SDIO_F4xx/Middleware/ff.su ./PeriphLibraries/SDIO_F4xx/Middleware/ff_gen_drv.d ./PeriphLibraries/SDIO_F4xx/Middleware/ff_gen_drv.o ./PeriphLibraries/SDIO_F4xx/Middleware/ff_gen_drv.su

.PHONY: clean-PeriphLibraries-2f-SDIO_F4xx-2f-Middleware

