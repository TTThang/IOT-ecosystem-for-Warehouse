################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../AppLibraries/lvgl/examples/assets/animimg001.c \
../AppLibraries/lvgl/examples/assets/animimg002.c \
../AppLibraries/lvgl/examples/assets/animimg003.c \
../AppLibraries/lvgl/examples/assets/img_caret_down.c \
../AppLibraries/lvgl/examples/assets/img_cogwheel_alpha16.c \
../AppLibraries/lvgl/examples/assets/img_cogwheel_argb.c \
../AppLibraries/lvgl/examples/assets/img_cogwheel_chroma_keyed.c \
../AppLibraries/lvgl/examples/assets/img_cogwheel_indexed16.c \
../AppLibraries/lvgl/examples/assets/img_cogwheel_rgb.c \
../AppLibraries/lvgl/examples/assets/img_hand.c \
../AppLibraries/lvgl/examples/assets/img_skew_strip.c \
../AppLibraries/lvgl/examples/assets/img_star.c \
../AppLibraries/lvgl/examples/assets/imgbtn_left.c \
../AppLibraries/lvgl/examples/assets/imgbtn_mid.c \
../AppLibraries/lvgl/examples/assets/imgbtn_right.c 

C_DEPS += \
./AppLibraries/lvgl/examples/assets/animimg001.d \
./AppLibraries/lvgl/examples/assets/animimg002.d \
./AppLibraries/lvgl/examples/assets/animimg003.d \
./AppLibraries/lvgl/examples/assets/img_caret_down.d \
./AppLibraries/lvgl/examples/assets/img_cogwheel_alpha16.d \
./AppLibraries/lvgl/examples/assets/img_cogwheel_argb.d \
./AppLibraries/lvgl/examples/assets/img_cogwheel_chroma_keyed.d \
./AppLibraries/lvgl/examples/assets/img_cogwheel_indexed16.d \
./AppLibraries/lvgl/examples/assets/img_cogwheel_rgb.d \
./AppLibraries/lvgl/examples/assets/img_hand.d \
./AppLibraries/lvgl/examples/assets/img_skew_strip.d \
./AppLibraries/lvgl/examples/assets/img_star.d \
./AppLibraries/lvgl/examples/assets/imgbtn_left.d \
./AppLibraries/lvgl/examples/assets/imgbtn_mid.d \
./AppLibraries/lvgl/examples/assets/imgbtn_right.d 

OBJS += \
./AppLibraries/lvgl/examples/assets/animimg001.o \
./AppLibraries/lvgl/examples/assets/animimg002.o \
./AppLibraries/lvgl/examples/assets/animimg003.o \
./AppLibraries/lvgl/examples/assets/img_caret_down.o \
./AppLibraries/lvgl/examples/assets/img_cogwheel_alpha16.o \
./AppLibraries/lvgl/examples/assets/img_cogwheel_argb.o \
./AppLibraries/lvgl/examples/assets/img_cogwheel_chroma_keyed.o \
./AppLibraries/lvgl/examples/assets/img_cogwheel_indexed16.o \
./AppLibraries/lvgl/examples/assets/img_cogwheel_rgb.o \
./AppLibraries/lvgl/examples/assets/img_hand.o \
./AppLibraries/lvgl/examples/assets/img_skew_strip.o \
./AppLibraries/lvgl/examples/assets/img_star.o \
./AppLibraries/lvgl/examples/assets/imgbtn_left.o \
./AppLibraries/lvgl/examples/assets/imgbtn_mid.o \
./AppLibraries/lvgl/examples/assets/imgbtn_right.o 


# Each subdirectory must supply rules for building sources it contributes
AppLibraries/lvgl/examples/assets/%.o AppLibraries/lvgl/examples/assets/%.su: ../AppLibraries/lvgl/examples/assets/%.c AppLibraries/lvgl/examples/assets/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F407VGTx -DSTM32F407xx -DHSE_VALUE=25000000UL -c -I../Drivers/Devices -I../AppLibraries/lvgl -I../AppLibraries/User_Interface -I../AppLibraries/GateWay_API -I../AppLibraries/LoRa_API -I../AppLibraries/ESP32_API -I../PeriphLibraries/TIM_F4xx -I../PeriphLibraries/SDMMC_F4xx -I../AppLibraries/DS3231 -I../PeriphLibraries -I../Src/Config -I../PeriphLibraries/STM_LOG -I../PeriphLibraries/SDIOMMC_F4xx -I../PeriphLibraries/PERIPH_STATUS -I../PeriphLibraries/SYSTEM_F4xx -I../PeriphLibraries/USART_F4xx -I../PeriphLibraries/RCC_F4xx -I../PeriphLibraries/SPI_F4xx -I../PeriphLibraries/I2C_F4xx -I../PeriphLibraries/IT_F4xx -I../PeriphLibraries/DMA_F4xx -I../PeriphLibraries/GPIO_F4xx -I../Drivers/CMSIS -I../AppLibraries/SPIFLASH -I../AppLibraries/LORA -I../AppLibraries/FT6236 -I../AppLibraries/TFT16BIT -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-AppLibraries-2f-lvgl-2f-examples-2f-assets

clean-AppLibraries-2f-lvgl-2f-examples-2f-assets:
	-$(RM) ./AppLibraries/lvgl/examples/assets/animimg001.d ./AppLibraries/lvgl/examples/assets/animimg001.o ./AppLibraries/lvgl/examples/assets/animimg001.su ./AppLibraries/lvgl/examples/assets/animimg002.d ./AppLibraries/lvgl/examples/assets/animimg002.o ./AppLibraries/lvgl/examples/assets/animimg002.su ./AppLibraries/lvgl/examples/assets/animimg003.d ./AppLibraries/lvgl/examples/assets/animimg003.o ./AppLibraries/lvgl/examples/assets/animimg003.su ./AppLibraries/lvgl/examples/assets/img_caret_down.d ./AppLibraries/lvgl/examples/assets/img_caret_down.o ./AppLibraries/lvgl/examples/assets/img_caret_down.su ./AppLibraries/lvgl/examples/assets/img_cogwheel_alpha16.d ./AppLibraries/lvgl/examples/assets/img_cogwheel_alpha16.o ./AppLibraries/lvgl/examples/assets/img_cogwheel_alpha16.su ./AppLibraries/lvgl/examples/assets/img_cogwheel_argb.d ./AppLibraries/lvgl/examples/assets/img_cogwheel_argb.o ./AppLibraries/lvgl/examples/assets/img_cogwheel_argb.su ./AppLibraries/lvgl/examples/assets/img_cogwheel_chroma_keyed.d ./AppLibraries/lvgl/examples/assets/img_cogwheel_chroma_keyed.o ./AppLibraries/lvgl/examples/assets/img_cogwheel_chroma_keyed.su ./AppLibraries/lvgl/examples/assets/img_cogwheel_indexed16.d ./AppLibraries/lvgl/examples/assets/img_cogwheel_indexed16.o ./AppLibraries/lvgl/examples/assets/img_cogwheel_indexed16.su ./AppLibraries/lvgl/examples/assets/img_cogwheel_rgb.d ./AppLibraries/lvgl/examples/assets/img_cogwheel_rgb.o ./AppLibraries/lvgl/examples/assets/img_cogwheel_rgb.su ./AppLibraries/lvgl/examples/assets/img_hand.d ./AppLibraries/lvgl/examples/assets/img_hand.o ./AppLibraries/lvgl/examples/assets/img_hand.su ./AppLibraries/lvgl/examples/assets/img_skew_strip.d ./AppLibraries/lvgl/examples/assets/img_skew_strip.o ./AppLibraries/lvgl/examples/assets/img_skew_strip.su ./AppLibraries/lvgl/examples/assets/img_star.d ./AppLibraries/lvgl/examples/assets/img_star.o ./AppLibraries/lvgl/examples/assets/img_star.su ./AppLibraries/lvgl/examples/assets/imgbtn_left.d ./AppLibraries/lvgl/examples/assets/imgbtn_left.o ./AppLibraries/lvgl/examples/assets/imgbtn_left.su ./AppLibraries/lvgl/examples/assets/imgbtn_mid.d ./AppLibraries/lvgl/examples/assets/imgbtn_mid.o ./AppLibraries/lvgl/examples/assets/imgbtn_mid.su ./AppLibraries/lvgl/examples/assets/imgbtn_right.d ./AppLibraries/lvgl/examples/assets/imgbtn_right.o ./AppLibraries/lvgl/examples/assets/imgbtn_right.su

.PHONY: clean-AppLibraries-2f-lvgl-2f-examples-2f-assets

