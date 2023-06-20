################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../AppLibraries/lvgl/examples/widgets/chart/lv_example_chart_1.c \
../AppLibraries/lvgl/examples/widgets/chart/lv_example_chart_2.c \
../AppLibraries/lvgl/examples/widgets/chart/lv_example_chart_3.c \
../AppLibraries/lvgl/examples/widgets/chart/lv_example_chart_4.c \
../AppLibraries/lvgl/examples/widgets/chart/lv_example_chart_5.c \
../AppLibraries/lvgl/examples/widgets/chart/lv_example_chart_6.c \
../AppLibraries/lvgl/examples/widgets/chart/lv_example_chart_7.c \
../AppLibraries/lvgl/examples/widgets/chart/lv_example_chart_8.c \
../AppLibraries/lvgl/examples/widgets/chart/lv_example_chart_9.c 

C_DEPS += \
./AppLibraries/lvgl/examples/widgets/chart/lv_example_chart_1.d \
./AppLibraries/lvgl/examples/widgets/chart/lv_example_chart_2.d \
./AppLibraries/lvgl/examples/widgets/chart/lv_example_chart_3.d \
./AppLibraries/lvgl/examples/widgets/chart/lv_example_chart_4.d \
./AppLibraries/lvgl/examples/widgets/chart/lv_example_chart_5.d \
./AppLibraries/lvgl/examples/widgets/chart/lv_example_chart_6.d \
./AppLibraries/lvgl/examples/widgets/chart/lv_example_chart_7.d \
./AppLibraries/lvgl/examples/widgets/chart/lv_example_chart_8.d \
./AppLibraries/lvgl/examples/widgets/chart/lv_example_chart_9.d 

OBJS += \
./AppLibraries/lvgl/examples/widgets/chart/lv_example_chart_1.o \
./AppLibraries/lvgl/examples/widgets/chart/lv_example_chart_2.o \
./AppLibraries/lvgl/examples/widgets/chart/lv_example_chart_3.o \
./AppLibraries/lvgl/examples/widgets/chart/lv_example_chart_4.o \
./AppLibraries/lvgl/examples/widgets/chart/lv_example_chart_5.o \
./AppLibraries/lvgl/examples/widgets/chart/lv_example_chart_6.o \
./AppLibraries/lvgl/examples/widgets/chart/lv_example_chart_7.o \
./AppLibraries/lvgl/examples/widgets/chart/lv_example_chart_8.o \
./AppLibraries/lvgl/examples/widgets/chart/lv_example_chart_9.o 


# Each subdirectory must supply rules for building sources it contributes
AppLibraries/lvgl/examples/widgets/chart/%.o AppLibraries/lvgl/examples/widgets/chart/%.su: ../AppLibraries/lvgl/examples/widgets/chart/%.c AppLibraries/lvgl/examples/widgets/chart/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F407VGTx -DSTM32F407xx -DHSE_VALUE=25000000UL -c -I../Drivers/Devices -I../AppLibraries/lvgl -I../AppLibraries/User_Interface -I../AppLibraries/GateWay_API -I../AppLibraries/LoRa_API -I../AppLibraries/ESP32_API -I../PeriphLibraries/TIM_F4xx -I../PeriphLibraries/SDMMC_F4xx -I../AppLibraries/DS3231 -I../PeriphLibraries -I../Src/Config -I../PeriphLibraries/STM_LOG -I../PeriphLibraries/SDIOMMC_F4xx -I../PeriphLibraries/PERIPH_STATUS -I../PeriphLibraries/SYSTEM_F4xx -I../PeriphLibraries/USART_F4xx -I../PeriphLibraries/RCC_F4xx -I../PeriphLibraries/SPI_F4xx -I../PeriphLibraries/I2C_F4xx -I../PeriphLibraries/IT_F4xx -I../PeriphLibraries/DMA_F4xx -I../PeriphLibraries/GPIO_F4xx -I../Drivers/CMSIS -I../AppLibraries/SPIFLASH -I../AppLibraries/LORA -I../AppLibraries/FT6236 -I../AppLibraries/TFT16BIT -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-AppLibraries-2f-lvgl-2f-examples-2f-widgets-2f-chart

clean-AppLibraries-2f-lvgl-2f-examples-2f-widgets-2f-chart:
	-$(RM) ./AppLibraries/lvgl/examples/widgets/chart/lv_example_chart_1.d ./AppLibraries/lvgl/examples/widgets/chart/lv_example_chart_1.o ./AppLibraries/lvgl/examples/widgets/chart/lv_example_chart_1.su ./AppLibraries/lvgl/examples/widgets/chart/lv_example_chart_2.d ./AppLibraries/lvgl/examples/widgets/chart/lv_example_chart_2.o ./AppLibraries/lvgl/examples/widgets/chart/lv_example_chart_2.su ./AppLibraries/lvgl/examples/widgets/chart/lv_example_chart_3.d ./AppLibraries/lvgl/examples/widgets/chart/lv_example_chart_3.o ./AppLibraries/lvgl/examples/widgets/chart/lv_example_chart_3.su ./AppLibraries/lvgl/examples/widgets/chart/lv_example_chart_4.d ./AppLibraries/lvgl/examples/widgets/chart/lv_example_chart_4.o ./AppLibraries/lvgl/examples/widgets/chart/lv_example_chart_4.su ./AppLibraries/lvgl/examples/widgets/chart/lv_example_chart_5.d ./AppLibraries/lvgl/examples/widgets/chart/lv_example_chart_5.o ./AppLibraries/lvgl/examples/widgets/chart/lv_example_chart_5.su ./AppLibraries/lvgl/examples/widgets/chart/lv_example_chart_6.d ./AppLibraries/lvgl/examples/widgets/chart/lv_example_chart_6.o ./AppLibraries/lvgl/examples/widgets/chart/lv_example_chart_6.su ./AppLibraries/lvgl/examples/widgets/chart/lv_example_chart_7.d ./AppLibraries/lvgl/examples/widgets/chart/lv_example_chart_7.o ./AppLibraries/lvgl/examples/widgets/chart/lv_example_chart_7.su ./AppLibraries/lvgl/examples/widgets/chart/lv_example_chart_8.d ./AppLibraries/lvgl/examples/widgets/chart/lv_example_chart_8.o ./AppLibraries/lvgl/examples/widgets/chart/lv_example_chart_8.su ./AppLibraries/lvgl/examples/widgets/chart/lv_example_chart_9.d ./AppLibraries/lvgl/examples/widgets/chart/lv_example_chart_9.o ./AppLibraries/lvgl/examples/widgets/chart/lv_example_chart_9.su

.PHONY: clean-AppLibraries-2f-lvgl-2f-examples-2f-widgets-2f-chart

