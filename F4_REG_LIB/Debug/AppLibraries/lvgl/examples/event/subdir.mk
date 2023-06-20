################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../AppLibraries/lvgl/examples/event/lv_example_event_1.c \
../AppLibraries/lvgl/examples/event/lv_example_event_2.c \
../AppLibraries/lvgl/examples/event/lv_example_event_3.c \
../AppLibraries/lvgl/examples/event/lv_example_event_4.c 

C_DEPS += \
./AppLibraries/lvgl/examples/event/lv_example_event_1.d \
./AppLibraries/lvgl/examples/event/lv_example_event_2.d \
./AppLibraries/lvgl/examples/event/lv_example_event_3.d \
./AppLibraries/lvgl/examples/event/lv_example_event_4.d 

OBJS += \
./AppLibraries/lvgl/examples/event/lv_example_event_1.o \
./AppLibraries/lvgl/examples/event/lv_example_event_2.o \
./AppLibraries/lvgl/examples/event/lv_example_event_3.o \
./AppLibraries/lvgl/examples/event/lv_example_event_4.o 


# Each subdirectory must supply rules for building sources it contributes
AppLibraries/lvgl/examples/event/%.o AppLibraries/lvgl/examples/event/%.su: ../AppLibraries/lvgl/examples/event/%.c AppLibraries/lvgl/examples/event/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F407VGTx -DSTM32F407xx -DHSE_VALUE=25000000UL -c -I../Drivers/Devices -I../AppLibraries/lvgl -I../AppLibraries/User_Interface -I../AppLibraries/GateWay_API -I../AppLibraries/LoRa_API -I../AppLibraries/ESP32_API -I../PeriphLibraries/TIM_F4xx -I../PeriphLibraries/SDMMC_F4xx -I../AppLibraries/DS3231 -I../PeriphLibraries -I../Src/Config -I../PeriphLibraries/STM_LOG -I../PeriphLibraries/SDIOMMC_F4xx -I../PeriphLibraries/PERIPH_STATUS -I../PeriphLibraries/SYSTEM_F4xx -I../PeriphLibraries/USART_F4xx -I../PeriphLibraries/RCC_F4xx -I../PeriphLibraries/SPI_F4xx -I../PeriphLibraries/I2C_F4xx -I../PeriphLibraries/IT_F4xx -I../PeriphLibraries/DMA_F4xx -I../PeriphLibraries/GPIO_F4xx -I../Drivers/CMSIS -I../AppLibraries/SPIFLASH -I../AppLibraries/LORA -I../AppLibraries/FT6236 -I../AppLibraries/TFT16BIT -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-AppLibraries-2f-lvgl-2f-examples-2f-event

clean-AppLibraries-2f-lvgl-2f-examples-2f-event:
	-$(RM) ./AppLibraries/lvgl/examples/event/lv_example_event_1.d ./AppLibraries/lvgl/examples/event/lv_example_event_1.o ./AppLibraries/lvgl/examples/event/lv_example_event_1.su ./AppLibraries/lvgl/examples/event/lv_example_event_2.d ./AppLibraries/lvgl/examples/event/lv_example_event_2.o ./AppLibraries/lvgl/examples/event/lv_example_event_2.su ./AppLibraries/lvgl/examples/event/lv_example_event_3.d ./AppLibraries/lvgl/examples/event/lv_example_event_3.o ./AppLibraries/lvgl/examples/event/lv_example_event_3.su ./AppLibraries/lvgl/examples/event/lv_example_event_4.d ./AppLibraries/lvgl/examples/event/lv_example_event_4.o ./AppLibraries/lvgl/examples/event/lv_example_event_4.su

.PHONY: clean-AppLibraries-2f-lvgl-2f-examples-2f-event

