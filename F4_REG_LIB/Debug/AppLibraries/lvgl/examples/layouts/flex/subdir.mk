################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../AppLibraries/lvgl/examples/layouts/flex/lv_example_flex_1.c \
../AppLibraries/lvgl/examples/layouts/flex/lv_example_flex_2.c \
../AppLibraries/lvgl/examples/layouts/flex/lv_example_flex_3.c \
../AppLibraries/lvgl/examples/layouts/flex/lv_example_flex_4.c \
../AppLibraries/lvgl/examples/layouts/flex/lv_example_flex_5.c \
../AppLibraries/lvgl/examples/layouts/flex/lv_example_flex_6.c 

C_DEPS += \
./AppLibraries/lvgl/examples/layouts/flex/lv_example_flex_1.d \
./AppLibraries/lvgl/examples/layouts/flex/lv_example_flex_2.d \
./AppLibraries/lvgl/examples/layouts/flex/lv_example_flex_3.d \
./AppLibraries/lvgl/examples/layouts/flex/lv_example_flex_4.d \
./AppLibraries/lvgl/examples/layouts/flex/lv_example_flex_5.d \
./AppLibraries/lvgl/examples/layouts/flex/lv_example_flex_6.d 

OBJS += \
./AppLibraries/lvgl/examples/layouts/flex/lv_example_flex_1.o \
./AppLibraries/lvgl/examples/layouts/flex/lv_example_flex_2.o \
./AppLibraries/lvgl/examples/layouts/flex/lv_example_flex_3.o \
./AppLibraries/lvgl/examples/layouts/flex/lv_example_flex_4.o \
./AppLibraries/lvgl/examples/layouts/flex/lv_example_flex_5.o \
./AppLibraries/lvgl/examples/layouts/flex/lv_example_flex_6.o 


# Each subdirectory must supply rules for building sources it contributes
AppLibraries/lvgl/examples/layouts/flex/%.o AppLibraries/lvgl/examples/layouts/flex/%.su: ../AppLibraries/lvgl/examples/layouts/flex/%.c AppLibraries/lvgl/examples/layouts/flex/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F407VGTx -DSTM32F407xx -DHSE_VALUE=25000000UL -c -I../Drivers/Devices -I../AppLibraries/lvgl -I../AppLibraries/User_Interface -I../AppLibraries/GateWay_API -I../AppLibraries/LoRa_API -I../AppLibraries/ESP32_API -I../PeriphLibraries/TIM_F4xx -I../PeriphLibraries/SDMMC_F4xx -I../AppLibraries/DS3231 -I../PeriphLibraries -I../Src/Config -I../PeriphLibraries/STM_LOG -I../PeriphLibraries/SDIOMMC_F4xx -I../PeriphLibraries/PERIPH_STATUS -I../PeriphLibraries/SYSTEM_F4xx -I../PeriphLibraries/USART_F4xx -I../PeriphLibraries/RCC_F4xx -I../PeriphLibraries/SPI_F4xx -I../PeriphLibraries/I2C_F4xx -I../PeriphLibraries/IT_F4xx -I../PeriphLibraries/DMA_F4xx -I../PeriphLibraries/GPIO_F4xx -I../Drivers/CMSIS -I../AppLibraries/SPIFLASH -I../AppLibraries/LORA -I../AppLibraries/FT6236 -I../AppLibraries/TFT16BIT -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-AppLibraries-2f-lvgl-2f-examples-2f-layouts-2f-flex

clean-AppLibraries-2f-lvgl-2f-examples-2f-layouts-2f-flex:
	-$(RM) ./AppLibraries/lvgl/examples/layouts/flex/lv_example_flex_1.d ./AppLibraries/lvgl/examples/layouts/flex/lv_example_flex_1.o ./AppLibraries/lvgl/examples/layouts/flex/lv_example_flex_1.su ./AppLibraries/lvgl/examples/layouts/flex/lv_example_flex_2.d ./AppLibraries/lvgl/examples/layouts/flex/lv_example_flex_2.o ./AppLibraries/lvgl/examples/layouts/flex/lv_example_flex_2.su ./AppLibraries/lvgl/examples/layouts/flex/lv_example_flex_3.d ./AppLibraries/lvgl/examples/layouts/flex/lv_example_flex_3.o ./AppLibraries/lvgl/examples/layouts/flex/lv_example_flex_3.su ./AppLibraries/lvgl/examples/layouts/flex/lv_example_flex_4.d ./AppLibraries/lvgl/examples/layouts/flex/lv_example_flex_4.o ./AppLibraries/lvgl/examples/layouts/flex/lv_example_flex_4.su ./AppLibraries/lvgl/examples/layouts/flex/lv_example_flex_5.d ./AppLibraries/lvgl/examples/layouts/flex/lv_example_flex_5.o ./AppLibraries/lvgl/examples/layouts/flex/lv_example_flex_5.su ./AppLibraries/lvgl/examples/layouts/flex/lv_example_flex_6.d ./AppLibraries/lvgl/examples/layouts/flex/lv_example_flex_6.o ./AppLibraries/lvgl/examples/layouts/flex/lv_example_flex_6.su

.PHONY: clean-AppLibraries-2f-lvgl-2f-examples-2f-layouts-2f-flex

