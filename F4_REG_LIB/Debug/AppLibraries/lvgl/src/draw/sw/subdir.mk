################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../AppLibraries/lvgl/src/draw/sw/lv_draw_sw.c \
../AppLibraries/lvgl/src/draw/sw/lv_draw_sw_arc.c \
../AppLibraries/lvgl/src/draw/sw/lv_draw_sw_blend.c \
../AppLibraries/lvgl/src/draw/sw/lv_draw_sw_dither.c \
../AppLibraries/lvgl/src/draw/sw/lv_draw_sw_gradient.c \
../AppLibraries/lvgl/src/draw/sw/lv_draw_sw_img.c \
../AppLibraries/lvgl/src/draw/sw/lv_draw_sw_letter.c \
../AppLibraries/lvgl/src/draw/sw/lv_draw_sw_line.c \
../AppLibraries/lvgl/src/draw/sw/lv_draw_sw_polygon.c \
../AppLibraries/lvgl/src/draw/sw/lv_draw_sw_rect.c \
../AppLibraries/lvgl/src/draw/sw/lv_draw_sw_transform.c 

C_DEPS += \
./AppLibraries/lvgl/src/draw/sw/lv_draw_sw.d \
./AppLibraries/lvgl/src/draw/sw/lv_draw_sw_arc.d \
./AppLibraries/lvgl/src/draw/sw/lv_draw_sw_blend.d \
./AppLibraries/lvgl/src/draw/sw/lv_draw_sw_dither.d \
./AppLibraries/lvgl/src/draw/sw/lv_draw_sw_gradient.d \
./AppLibraries/lvgl/src/draw/sw/lv_draw_sw_img.d \
./AppLibraries/lvgl/src/draw/sw/lv_draw_sw_letter.d \
./AppLibraries/lvgl/src/draw/sw/lv_draw_sw_line.d \
./AppLibraries/lvgl/src/draw/sw/lv_draw_sw_polygon.d \
./AppLibraries/lvgl/src/draw/sw/lv_draw_sw_rect.d \
./AppLibraries/lvgl/src/draw/sw/lv_draw_sw_transform.d 

OBJS += \
./AppLibraries/lvgl/src/draw/sw/lv_draw_sw.o \
./AppLibraries/lvgl/src/draw/sw/lv_draw_sw_arc.o \
./AppLibraries/lvgl/src/draw/sw/lv_draw_sw_blend.o \
./AppLibraries/lvgl/src/draw/sw/lv_draw_sw_dither.o \
./AppLibraries/lvgl/src/draw/sw/lv_draw_sw_gradient.o \
./AppLibraries/lvgl/src/draw/sw/lv_draw_sw_img.o \
./AppLibraries/lvgl/src/draw/sw/lv_draw_sw_letter.o \
./AppLibraries/lvgl/src/draw/sw/lv_draw_sw_line.o \
./AppLibraries/lvgl/src/draw/sw/lv_draw_sw_polygon.o \
./AppLibraries/lvgl/src/draw/sw/lv_draw_sw_rect.o \
./AppLibraries/lvgl/src/draw/sw/lv_draw_sw_transform.o 


# Each subdirectory must supply rules for building sources it contributes
AppLibraries/lvgl/src/draw/sw/%.o AppLibraries/lvgl/src/draw/sw/%.su: ../AppLibraries/lvgl/src/draw/sw/%.c AppLibraries/lvgl/src/draw/sw/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F407VGTx -DSTM32F407xx -DHSE_VALUE=25000000UL -c -I../Drivers/Devices -I../AppLibraries/lvgl -I../AppLibraries/User_Interface -I../AppLibraries/GateWay_API -I../AppLibraries/LoRa_API -I../AppLibraries/ESP32_API -I../PeriphLibraries/TIM_F4xx -I../PeriphLibraries/SDMMC_F4xx -I../AppLibraries/DS3231 -I../PeriphLibraries -I../Src/Config -I../PeriphLibraries/STM_LOG -I../PeriphLibraries/SDIOMMC_F4xx -I../PeriphLibraries/PERIPH_STATUS -I../PeriphLibraries/SYSTEM_F4xx -I../PeriphLibraries/USART_F4xx -I../PeriphLibraries/RCC_F4xx -I../PeriphLibraries/SPI_F4xx -I../PeriphLibraries/I2C_F4xx -I../PeriphLibraries/IT_F4xx -I../PeriphLibraries/DMA_F4xx -I../PeriphLibraries/GPIO_F4xx -I../Drivers/CMSIS -I../AppLibraries/SPIFLASH -I../AppLibraries/LORA -I../AppLibraries/FT6236 -I../AppLibraries/TFT16BIT -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-AppLibraries-2f-lvgl-2f-src-2f-draw-2f-sw

clean-AppLibraries-2f-lvgl-2f-src-2f-draw-2f-sw:
	-$(RM) ./AppLibraries/lvgl/src/draw/sw/lv_draw_sw.d ./AppLibraries/lvgl/src/draw/sw/lv_draw_sw.o ./AppLibraries/lvgl/src/draw/sw/lv_draw_sw.su ./AppLibraries/lvgl/src/draw/sw/lv_draw_sw_arc.d ./AppLibraries/lvgl/src/draw/sw/lv_draw_sw_arc.o ./AppLibraries/lvgl/src/draw/sw/lv_draw_sw_arc.su ./AppLibraries/lvgl/src/draw/sw/lv_draw_sw_blend.d ./AppLibraries/lvgl/src/draw/sw/lv_draw_sw_blend.o ./AppLibraries/lvgl/src/draw/sw/lv_draw_sw_blend.su ./AppLibraries/lvgl/src/draw/sw/lv_draw_sw_dither.d ./AppLibraries/lvgl/src/draw/sw/lv_draw_sw_dither.o ./AppLibraries/lvgl/src/draw/sw/lv_draw_sw_dither.su ./AppLibraries/lvgl/src/draw/sw/lv_draw_sw_gradient.d ./AppLibraries/lvgl/src/draw/sw/lv_draw_sw_gradient.o ./AppLibraries/lvgl/src/draw/sw/lv_draw_sw_gradient.su ./AppLibraries/lvgl/src/draw/sw/lv_draw_sw_img.d ./AppLibraries/lvgl/src/draw/sw/lv_draw_sw_img.o ./AppLibraries/lvgl/src/draw/sw/lv_draw_sw_img.su ./AppLibraries/lvgl/src/draw/sw/lv_draw_sw_letter.d ./AppLibraries/lvgl/src/draw/sw/lv_draw_sw_letter.o ./AppLibraries/lvgl/src/draw/sw/lv_draw_sw_letter.su ./AppLibraries/lvgl/src/draw/sw/lv_draw_sw_line.d ./AppLibraries/lvgl/src/draw/sw/lv_draw_sw_line.o ./AppLibraries/lvgl/src/draw/sw/lv_draw_sw_line.su ./AppLibraries/lvgl/src/draw/sw/lv_draw_sw_polygon.d ./AppLibraries/lvgl/src/draw/sw/lv_draw_sw_polygon.o ./AppLibraries/lvgl/src/draw/sw/lv_draw_sw_polygon.su ./AppLibraries/lvgl/src/draw/sw/lv_draw_sw_rect.d ./AppLibraries/lvgl/src/draw/sw/lv_draw_sw_rect.o ./AppLibraries/lvgl/src/draw/sw/lv_draw_sw_rect.su ./AppLibraries/lvgl/src/draw/sw/lv_draw_sw_transform.d ./AppLibraries/lvgl/src/draw/sw/lv_draw_sw_transform.o ./AppLibraries/lvgl/src/draw/sw/lv_draw_sw_transform.su

.PHONY: clean-AppLibraries-2f-lvgl-2f-src-2f-draw-2f-sw

