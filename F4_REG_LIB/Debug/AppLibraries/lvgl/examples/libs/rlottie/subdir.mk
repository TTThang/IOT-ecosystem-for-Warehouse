################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../AppLibraries/lvgl/examples/libs/rlottie/lv_example_rlottie_1.c \
../AppLibraries/lvgl/examples/libs/rlottie/lv_example_rlottie_2.c \
../AppLibraries/lvgl/examples/libs/rlottie/lv_example_rlottie_approve.c 

C_DEPS += \
./AppLibraries/lvgl/examples/libs/rlottie/lv_example_rlottie_1.d \
./AppLibraries/lvgl/examples/libs/rlottie/lv_example_rlottie_2.d \
./AppLibraries/lvgl/examples/libs/rlottie/lv_example_rlottie_approve.d 

OBJS += \
./AppLibraries/lvgl/examples/libs/rlottie/lv_example_rlottie_1.o \
./AppLibraries/lvgl/examples/libs/rlottie/lv_example_rlottie_2.o \
./AppLibraries/lvgl/examples/libs/rlottie/lv_example_rlottie_approve.o 


# Each subdirectory must supply rules for building sources it contributes
AppLibraries/lvgl/examples/libs/rlottie/%.o AppLibraries/lvgl/examples/libs/rlottie/%.su: ../AppLibraries/lvgl/examples/libs/rlottie/%.c AppLibraries/lvgl/examples/libs/rlottie/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F407VGTx -DSTM32F407xx -DHSE_VALUE=25000000UL -c -I../Drivers/Devices -I../AppLibraries/lvgl -I../AppLibraries/User_Interface -I../AppLibraries/GateWay_API -I../AppLibraries/LoRa_API -I../AppLibraries/ESP32_API -I../PeriphLibraries/TIM_F4xx -I../PeriphLibraries/SDMMC_F4xx -I../AppLibraries/DS3231 -I../PeriphLibraries -I../Src/Config -I../PeriphLibraries/STM_LOG -I../PeriphLibraries/SDIOMMC_F4xx -I../PeriphLibraries/PERIPH_STATUS -I../PeriphLibraries/SYSTEM_F4xx -I../PeriphLibraries/USART_F4xx -I../PeriphLibraries/RCC_F4xx -I../PeriphLibraries/SPI_F4xx -I../PeriphLibraries/I2C_F4xx -I../PeriphLibraries/IT_F4xx -I../PeriphLibraries/DMA_F4xx -I../PeriphLibraries/GPIO_F4xx -I../Drivers/CMSIS -I../AppLibraries/SPIFLASH -I../AppLibraries/LORA -I../AppLibraries/FT6236 -I../AppLibraries/TFT16BIT -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-AppLibraries-2f-lvgl-2f-examples-2f-libs-2f-rlottie

clean-AppLibraries-2f-lvgl-2f-examples-2f-libs-2f-rlottie:
	-$(RM) ./AppLibraries/lvgl/examples/libs/rlottie/lv_example_rlottie_1.d ./AppLibraries/lvgl/examples/libs/rlottie/lv_example_rlottie_1.o ./AppLibraries/lvgl/examples/libs/rlottie/lv_example_rlottie_1.su ./AppLibraries/lvgl/examples/libs/rlottie/lv_example_rlottie_2.d ./AppLibraries/lvgl/examples/libs/rlottie/lv_example_rlottie_2.o ./AppLibraries/lvgl/examples/libs/rlottie/lv_example_rlottie_2.su ./AppLibraries/lvgl/examples/libs/rlottie/lv_example_rlottie_approve.d ./AppLibraries/lvgl/examples/libs/rlottie/lv_example_rlottie_approve.o ./AppLibraries/lvgl/examples/libs/rlottie/lv_example_rlottie_approve.su

.PHONY: clean-AppLibraries-2f-lvgl-2f-examples-2f-libs-2f-rlottie

