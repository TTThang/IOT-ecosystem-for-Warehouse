################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl.c \
../AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl_arc.c \
../AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl_bg.c \
../AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl_composite.c \
../AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl_img.c \
../AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl_label.c \
../AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl_line.c \
../AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl_mask.c \
../AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl_polygon.c \
../AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl_rect.c \
../AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.c \
../AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.c \
../AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl_utils.c 

C_DEPS += \
./AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl.d \
./AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl_arc.d \
./AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl_bg.d \
./AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl_composite.d \
./AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl_img.d \
./AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl_label.d \
./AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl_line.d \
./AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl_mask.d \
./AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl_polygon.d \
./AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl_rect.d \
./AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.d \
./AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.d \
./AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl_utils.d 

OBJS += \
./AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl.o \
./AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl_arc.o \
./AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl_bg.o \
./AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl_composite.o \
./AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl_img.o \
./AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl_label.o \
./AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl_line.o \
./AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl_mask.o \
./AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl_polygon.o \
./AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl_rect.o \
./AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.o \
./AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.o \
./AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl_utils.o 


# Each subdirectory must supply rules for building sources it contributes
AppLibraries/lvgl/src/draw/sdl/%.o AppLibraries/lvgl/src/draw/sdl/%.su: ../AppLibraries/lvgl/src/draw/sdl/%.c AppLibraries/lvgl/src/draw/sdl/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F407VGTx -DSTM32F407xx -DHSE_VALUE=25000000UL -c -I../Drivers/Devices -I../AppLibraries/lvgl -I../AppLibraries/User_Interface -I../AppLibraries/GateWay_API -I../AppLibraries/LoRa_API -I../AppLibraries/ESP32_API -I../PeriphLibraries/TIM_F4xx -I../PeriphLibraries/SDMMC_F4xx -I../AppLibraries/DS3231 -I../PeriphLibraries -I../Src/Config -I../PeriphLibraries/STM_LOG -I../PeriphLibraries/SDIOMMC_F4xx -I../PeriphLibraries/PERIPH_STATUS -I../PeriphLibraries/SYSTEM_F4xx -I../PeriphLibraries/USART_F4xx -I../PeriphLibraries/RCC_F4xx -I../PeriphLibraries/SPI_F4xx -I../PeriphLibraries/I2C_F4xx -I../PeriphLibraries/IT_F4xx -I../PeriphLibraries/DMA_F4xx -I../PeriphLibraries/GPIO_F4xx -I../Drivers/CMSIS -I../AppLibraries/SPIFLASH -I../AppLibraries/LORA -I../AppLibraries/FT6236 -I../AppLibraries/TFT16BIT -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-AppLibraries-2f-lvgl-2f-src-2f-draw-2f-sdl

clean-AppLibraries-2f-lvgl-2f-src-2f-draw-2f-sdl:
	-$(RM) ./AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl.d ./AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl.o ./AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl.su ./AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl_arc.d ./AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl_arc.o ./AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl_arc.su ./AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl_bg.d ./AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl_bg.o ./AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl_bg.su ./AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl_composite.d ./AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl_composite.o ./AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl_composite.su ./AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl_img.d ./AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl_img.o ./AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl_img.su ./AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl_label.d ./AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl_label.o ./AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl_label.su ./AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl_line.d ./AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl_line.o ./AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl_line.su ./AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl_mask.d ./AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl_mask.o ./AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl_mask.su ./AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl_polygon.d ./AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl_polygon.o ./AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl_polygon.su ./AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl_rect.d ./AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl_rect.o ./AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl_rect.su ./AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.d ./AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.o ./AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl_stack_blur.su ./AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.d ./AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.o ./AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl_texture_cache.su ./AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl_utils.d ./AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl_utils.o ./AppLibraries/lvgl/src/draw/sdl/lv_draw_sdl_utils.su

.PHONY: clean-AppLibraries-2f-lvgl-2f-src-2f-draw-2f-sdl

