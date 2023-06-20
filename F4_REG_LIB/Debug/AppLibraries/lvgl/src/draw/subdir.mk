################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../AppLibraries/lvgl/src/draw/lv_draw.c \
../AppLibraries/lvgl/src/draw/lv_draw_arc.c \
../AppLibraries/lvgl/src/draw/lv_draw_img.c \
../AppLibraries/lvgl/src/draw/lv_draw_label.c \
../AppLibraries/lvgl/src/draw/lv_draw_line.c \
../AppLibraries/lvgl/src/draw/lv_draw_mask.c \
../AppLibraries/lvgl/src/draw/lv_draw_rect.c \
../AppLibraries/lvgl/src/draw/lv_draw_transform.c \
../AppLibraries/lvgl/src/draw/lv_draw_triangle.c \
../AppLibraries/lvgl/src/draw/lv_img_buf.c \
../AppLibraries/lvgl/src/draw/lv_img_cache.c \
../AppLibraries/lvgl/src/draw/lv_img_decoder.c 

C_DEPS += \
./AppLibraries/lvgl/src/draw/lv_draw.d \
./AppLibraries/lvgl/src/draw/lv_draw_arc.d \
./AppLibraries/lvgl/src/draw/lv_draw_img.d \
./AppLibraries/lvgl/src/draw/lv_draw_label.d \
./AppLibraries/lvgl/src/draw/lv_draw_line.d \
./AppLibraries/lvgl/src/draw/lv_draw_mask.d \
./AppLibraries/lvgl/src/draw/lv_draw_rect.d \
./AppLibraries/lvgl/src/draw/lv_draw_transform.d \
./AppLibraries/lvgl/src/draw/lv_draw_triangle.d \
./AppLibraries/lvgl/src/draw/lv_img_buf.d \
./AppLibraries/lvgl/src/draw/lv_img_cache.d \
./AppLibraries/lvgl/src/draw/lv_img_decoder.d 

OBJS += \
./AppLibraries/lvgl/src/draw/lv_draw.o \
./AppLibraries/lvgl/src/draw/lv_draw_arc.o \
./AppLibraries/lvgl/src/draw/lv_draw_img.o \
./AppLibraries/lvgl/src/draw/lv_draw_label.o \
./AppLibraries/lvgl/src/draw/lv_draw_line.o \
./AppLibraries/lvgl/src/draw/lv_draw_mask.o \
./AppLibraries/lvgl/src/draw/lv_draw_rect.o \
./AppLibraries/lvgl/src/draw/lv_draw_transform.o \
./AppLibraries/lvgl/src/draw/lv_draw_triangle.o \
./AppLibraries/lvgl/src/draw/lv_img_buf.o \
./AppLibraries/lvgl/src/draw/lv_img_cache.o \
./AppLibraries/lvgl/src/draw/lv_img_decoder.o 


# Each subdirectory must supply rules for building sources it contributes
AppLibraries/lvgl/src/draw/%.o AppLibraries/lvgl/src/draw/%.su: ../AppLibraries/lvgl/src/draw/%.c AppLibraries/lvgl/src/draw/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F407VGTx -DSTM32F407xx -DHSE_VALUE=25000000UL -c -I../Drivers/Devices -I../AppLibraries/lvgl -I../AppLibraries/User_Interface -I../AppLibraries/GateWay_API -I../AppLibraries/LoRa_API -I../AppLibraries/ESP32_API -I../PeriphLibraries/TIM_F4xx -I../PeriphLibraries/SDMMC_F4xx -I../AppLibraries/DS3231 -I../PeriphLibraries -I../Src/Config -I../PeriphLibraries/STM_LOG -I../PeriphLibraries/SDIOMMC_F4xx -I../PeriphLibraries/PERIPH_STATUS -I../PeriphLibraries/SYSTEM_F4xx -I../PeriphLibraries/USART_F4xx -I../PeriphLibraries/RCC_F4xx -I../PeriphLibraries/SPI_F4xx -I../PeriphLibraries/I2C_F4xx -I../PeriphLibraries/IT_F4xx -I../PeriphLibraries/DMA_F4xx -I../PeriphLibraries/GPIO_F4xx -I../Drivers/CMSIS -I../AppLibraries/SPIFLASH -I../AppLibraries/LORA -I../AppLibraries/FT6236 -I../AppLibraries/TFT16BIT -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-AppLibraries-2f-lvgl-2f-src-2f-draw

clean-AppLibraries-2f-lvgl-2f-src-2f-draw:
	-$(RM) ./AppLibraries/lvgl/src/draw/lv_draw.d ./AppLibraries/lvgl/src/draw/lv_draw.o ./AppLibraries/lvgl/src/draw/lv_draw.su ./AppLibraries/lvgl/src/draw/lv_draw_arc.d ./AppLibraries/lvgl/src/draw/lv_draw_arc.o ./AppLibraries/lvgl/src/draw/lv_draw_arc.su ./AppLibraries/lvgl/src/draw/lv_draw_img.d ./AppLibraries/lvgl/src/draw/lv_draw_img.o ./AppLibraries/lvgl/src/draw/lv_draw_img.su ./AppLibraries/lvgl/src/draw/lv_draw_label.d ./AppLibraries/lvgl/src/draw/lv_draw_label.o ./AppLibraries/lvgl/src/draw/lv_draw_label.su ./AppLibraries/lvgl/src/draw/lv_draw_line.d ./AppLibraries/lvgl/src/draw/lv_draw_line.o ./AppLibraries/lvgl/src/draw/lv_draw_line.su ./AppLibraries/lvgl/src/draw/lv_draw_mask.d ./AppLibraries/lvgl/src/draw/lv_draw_mask.o ./AppLibraries/lvgl/src/draw/lv_draw_mask.su ./AppLibraries/lvgl/src/draw/lv_draw_rect.d ./AppLibraries/lvgl/src/draw/lv_draw_rect.o ./AppLibraries/lvgl/src/draw/lv_draw_rect.su ./AppLibraries/lvgl/src/draw/lv_draw_transform.d ./AppLibraries/lvgl/src/draw/lv_draw_transform.o ./AppLibraries/lvgl/src/draw/lv_draw_transform.su ./AppLibraries/lvgl/src/draw/lv_draw_triangle.d ./AppLibraries/lvgl/src/draw/lv_draw_triangle.o ./AppLibraries/lvgl/src/draw/lv_draw_triangle.su ./AppLibraries/lvgl/src/draw/lv_img_buf.d ./AppLibraries/lvgl/src/draw/lv_img_buf.o ./AppLibraries/lvgl/src/draw/lv_img_buf.su ./AppLibraries/lvgl/src/draw/lv_img_cache.d ./AppLibraries/lvgl/src/draw/lv_img_cache.o ./AppLibraries/lvgl/src/draw/lv_img_cache.su ./AppLibraries/lvgl/src/draw/lv_img_decoder.d ./AppLibraries/lvgl/src/draw/lv_img_decoder.o ./AppLibraries/lvgl/src/draw/lv_img_decoder.su

.PHONY: clean-AppLibraries-2f-lvgl-2f-src-2f-draw

