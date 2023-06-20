################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../AppLibraries/lvgl/examples/styles/lv_example_style_1.c \
../AppLibraries/lvgl/examples/styles/lv_example_style_10.c \
../AppLibraries/lvgl/examples/styles/lv_example_style_11.c \
../AppLibraries/lvgl/examples/styles/lv_example_style_12.c \
../AppLibraries/lvgl/examples/styles/lv_example_style_13.c \
../AppLibraries/lvgl/examples/styles/lv_example_style_14.c \
../AppLibraries/lvgl/examples/styles/lv_example_style_15.c \
../AppLibraries/lvgl/examples/styles/lv_example_style_2.c \
../AppLibraries/lvgl/examples/styles/lv_example_style_3.c \
../AppLibraries/lvgl/examples/styles/lv_example_style_4.c \
../AppLibraries/lvgl/examples/styles/lv_example_style_5.c \
../AppLibraries/lvgl/examples/styles/lv_example_style_6.c \
../AppLibraries/lvgl/examples/styles/lv_example_style_7.c \
../AppLibraries/lvgl/examples/styles/lv_example_style_8.c \
../AppLibraries/lvgl/examples/styles/lv_example_style_9.c 

C_DEPS += \
./AppLibraries/lvgl/examples/styles/lv_example_style_1.d \
./AppLibraries/lvgl/examples/styles/lv_example_style_10.d \
./AppLibraries/lvgl/examples/styles/lv_example_style_11.d \
./AppLibraries/lvgl/examples/styles/lv_example_style_12.d \
./AppLibraries/lvgl/examples/styles/lv_example_style_13.d \
./AppLibraries/lvgl/examples/styles/lv_example_style_14.d \
./AppLibraries/lvgl/examples/styles/lv_example_style_15.d \
./AppLibraries/lvgl/examples/styles/lv_example_style_2.d \
./AppLibraries/lvgl/examples/styles/lv_example_style_3.d \
./AppLibraries/lvgl/examples/styles/lv_example_style_4.d \
./AppLibraries/lvgl/examples/styles/lv_example_style_5.d \
./AppLibraries/lvgl/examples/styles/lv_example_style_6.d \
./AppLibraries/lvgl/examples/styles/lv_example_style_7.d \
./AppLibraries/lvgl/examples/styles/lv_example_style_8.d \
./AppLibraries/lvgl/examples/styles/lv_example_style_9.d 

OBJS += \
./AppLibraries/lvgl/examples/styles/lv_example_style_1.o \
./AppLibraries/lvgl/examples/styles/lv_example_style_10.o \
./AppLibraries/lvgl/examples/styles/lv_example_style_11.o \
./AppLibraries/lvgl/examples/styles/lv_example_style_12.o \
./AppLibraries/lvgl/examples/styles/lv_example_style_13.o \
./AppLibraries/lvgl/examples/styles/lv_example_style_14.o \
./AppLibraries/lvgl/examples/styles/lv_example_style_15.o \
./AppLibraries/lvgl/examples/styles/lv_example_style_2.o \
./AppLibraries/lvgl/examples/styles/lv_example_style_3.o \
./AppLibraries/lvgl/examples/styles/lv_example_style_4.o \
./AppLibraries/lvgl/examples/styles/lv_example_style_5.o \
./AppLibraries/lvgl/examples/styles/lv_example_style_6.o \
./AppLibraries/lvgl/examples/styles/lv_example_style_7.o \
./AppLibraries/lvgl/examples/styles/lv_example_style_8.o \
./AppLibraries/lvgl/examples/styles/lv_example_style_9.o 


# Each subdirectory must supply rules for building sources it contributes
AppLibraries/lvgl/examples/styles/%.o AppLibraries/lvgl/examples/styles/%.su: ../AppLibraries/lvgl/examples/styles/%.c AppLibraries/lvgl/examples/styles/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F407VGTx -DSTM32F407xx -DHSE_VALUE=25000000UL -c -I../Drivers/Devices -I../AppLibraries/lvgl -I../AppLibraries/User_Interface -I../AppLibraries/GateWay_API -I../AppLibraries/LoRa_API -I../AppLibraries/ESP32_API -I../PeriphLibraries/TIM_F4xx -I../PeriphLibraries/SDMMC_F4xx -I../AppLibraries/DS3231 -I../PeriphLibraries -I../Src/Config -I../PeriphLibraries/STM_LOG -I../PeriphLibraries/SDIOMMC_F4xx -I../PeriphLibraries/PERIPH_STATUS -I../PeriphLibraries/SYSTEM_F4xx -I../PeriphLibraries/USART_F4xx -I../PeriphLibraries/RCC_F4xx -I../PeriphLibraries/SPI_F4xx -I../PeriphLibraries/I2C_F4xx -I../PeriphLibraries/IT_F4xx -I../PeriphLibraries/DMA_F4xx -I../PeriphLibraries/GPIO_F4xx -I../Drivers/CMSIS -I../AppLibraries/SPIFLASH -I../AppLibraries/LORA -I../AppLibraries/FT6236 -I../AppLibraries/TFT16BIT -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-AppLibraries-2f-lvgl-2f-examples-2f-styles

clean-AppLibraries-2f-lvgl-2f-examples-2f-styles:
	-$(RM) ./AppLibraries/lvgl/examples/styles/lv_example_style_1.d ./AppLibraries/lvgl/examples/styles/lv_example_style_1.o ./AppLibraries/lvgl/examples/styles/lv_example_style_1.su ./AppLibraries/lvgl/examples/styles/lv_example_style_10.d ./AppLibraries/lvgl/examples/styles/lv_example_style_10.o ./AppLibraries/lvgl/examples/styles/lv_example_style_10.su ./AppLibraries/lvgl/examples/styles/lv_example_style_11.d ./AppLibraries/lvgl/examples/styles/lv_example_style_11.o ./AppLibraries/lvgl/examples/styles/lv_example_style_11.su ./AppLibraries/lvgl/examples/styles/lv_example_style_12.d ./AppLibraries/lvgl/examples/styles/lv_example_style_12.o ./AppLibraries/lvgl/examples/styles/lv_example_style_12.su ./AppLibraries/lvgl/examples/styles/lv_example_style_13.d ./AppLibraries/lvgl/examples/styles/lv_example_style_13.o ./AppLibraries/lvgl/examples/styles/lv_example_style_13.su ./AppLibraries/lvgl/examples/styles/lv_example_style_14.d ./AppLibraries/lvgl/examples/styles/lv_example_style_14.o ./AppLibraries/lvgl/examples/styles/lv_example_style_14.su ./AppLibraries/lvgl/examples/styles/lv_example_style_15.d ./AppLibraries/lvgl/examples/styles/lv_example_style_15.o ./AppLibraries/lvgl/examples/styles/lv_example_style_15.su ./AppLibraries/lvgl/examples/styles/lv_example_style_2.d ./AppLibraries/lvgl/examples/styles/lv_example_style_2.o ./AppLibraries/lvgl/examples/styles/lv_example_style_2.su ./AppLibraries/lvgl/examples/styles/lv_example_style_3.d ./AppLibraries/lvgl/examples/styles/lv_example_style_3.o ./AppLibraries/lvgl/examples/styles/lv_example_style_3.su ./AppLibraries/lvgl/examples/styles/lv_example_style_4.d ./AppLibraries/lvgl/examples/styles/lv_example_style_4.o ./AppLibraries/lvgl/examples/styles/lv_example_style_4.su ./AppLibraries/lvgl/examples/styles/lv_example_style_5.d ./AppLibraries/lvgl/examples/styles/lv_example_style_5.o ./AppLibraries/lvgl/examples/styles/lv_example_style_5.su ./AppLibraries/lvgl/examples/styles/lv_example_style_6.d ./AppLibraries/lvgl/examples/styles/lv_example_style_6.o ./AppLibraries/lvgl/examples/styles/lv_example_style_6.su ./AppLibraries/lvgl/examples/styles/lv_example_style_7.d ./AppLibraries/lvgl/examples/styles/lv_example_style_7.o ./AppLibraries/lvgl/examples/styles/lv_example_style_7.su ./AppLibraries/lvgl/examples/styles/lv_example_style_8.d ./AppLibraries/lvgl/examples/styles/lv_example_style_8.o ./AppLibraries/lvgl/examples/styles/lv_example_style_8.su ./AppLibraries/lvgl/examples/styles/lv_example_style_9.d ./AppLibraries/lvgl/examples/styles/lv_example_style_9.o ./AppLibraries/lvgl/examples/styles/lv_example_style_9.su

.PHONY: clean-AppLibraries-2f-lvgl-2f-examples-2f-styles

