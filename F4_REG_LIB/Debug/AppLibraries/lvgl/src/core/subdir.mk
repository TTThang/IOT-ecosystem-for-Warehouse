################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../AppLibraries/lvgl/src/core/lv_disp.c \
../AppLibraries/lvgl/src/core/lv_event.c \
../AppLibraries/lvgl/src/core/lv_group.c \
../AppLibraries/lvgl/src/core/lv_indev.c \
../AppLibraries/lvgl/src/core/lv_indev_scroll.c \
../AppLibraries/lvgl/src/core/lv_obj.c \
../AppLibraries/lvgl/src/core/lv_obj_class.c \
../AppLibraries/lvgl/src/core/lv_obj_draw.c \
../AppLibraries/lvgl/src/core/lv_obj_pos.c \
../AppLibraries/lvgl/src/core/lv_obj_scroll.c \
../AppLibraries/lvgl/src/core/lv_obj_style.c \
../AppLibraries/lvgl/src/core/lv_obj_style_gen.c \
../AppLibraries/lvgl/src/core/lv_obj_tree.c \
../AppLibraries/lvgl/src/core/lv_refr.c \
../AppLibraries/lvgl/src/core/lv_theme.c 

C_DEPS += \
./AppLibraries/lvgl/src/core/lv_disp.d \
./AppLibraries/lvgl/src/core/lv_event.d \
./AppLibraries/lvgl/src/core/lv_group.d \
./AppLibraries/lvgl/src/core/lv_indev.d \
./AppLibraries/lvgl/src/core/lv_indev_scroll.d \
./AppLibraries/lvgl/src/core/lv_obj.d \
./AppLibraries/lvgl/src/core/lv_obj_class.d \
./AppLibraries/lvgl/src/core/lv_obj_draw.d \
./AppLibraries/lvgl/src/core/lv_obj_pos.d \
./AppLibraries/lvgl/src/core/lv_obj_scroll.d \
./AppLibraries/lvgl/src/core/lv_obj_style.d \
./AppLibraries/lvgl/src/core/lv_obj_style_gen.d \
./AppLibraries/lvgl/src/core/lv_obj_tree.d \
./AppLibraries/lvgl/src/core/lv_refr.d \
./AppLibraries/lvgl/src/core/lv_theme.d 

OBJS += \
./AppLibraries/lvgl/src/core/lv_disp.o \
./AppLibraries/lvgl/src/core/lv_event.o \
./AppLibraries/lvgl/src/core/lv_group.o \
./AppLibraries/lvgl/src/core/lv_indev.o \
./AppLibraries/lvgl/src/core/lv_indev_scroll.o \
./AppLibraries/lvgl/src/core/lv_obj.o \
./AppLibraries/lvgl/src/core/lv_obj_class.o \
./AppLibraries/lvgl/src/core/lv_obj_draw.o \
./AppLibraries/lvgl/src/core/lv_obj_pos.o \
./AppLibraries/lvgl/src/core/lv_obj_scroll.o \
./AppLibraries/lvgl/src/core/lv_obj_style.o \
./AppLibraries/lvgl/src/core/lv_obj_style_gen.o \
./AppLibraries/lvgl/src/core/lv_obj_tree.o \
./AppLibraries/lvgl/src/core/lv_refr.o \
./AppLibraries/lvgl/src/core/lv_theme.o 


# Each subdirectory must supply rules for building sources it contributes
AppLibraries/lvgl/src/core/%.o AppLibraries/lvgl/src/core/%.su: ../AppLibraries/lvgl/src/core/%.c AppLibraries/lvgl/src/core/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F407VGTx -DSTM32F407xx -DHSE_VALUE=25000000UL -c -I../Drivers/Devices -I../AppLibraries/lvgl -I../AppLibraries/User_Interface -I../AppLibraries/GateWay_API -I../AppLibraries/LoRa_API -I../AppLibraries/ESP32_API -I../PeriphLibraries/TIM_F4xx -I../PeriphLibraries/SDMMC_F4xx -I../AppLibraries/DS3231 -I../PeriphLibraries -I../Src/Config -I../PeriphLibraries/STM_LOG -I../PeriphLibraries/SDIOMMC_F4xx -I../PeriphLibraries/PERIPH_STATUS -I../PeriphLibraries/SYSTEM_F4xx -I../PeriphLibraries/USART_F4xx -I../PeriphLibraries/RCC_F4xx -I../PeriphLibraries/SPI_F4xx -I../PeriphLibraries/I2C_F4xx -I../PeriphLibraries/IT_F4xx -I../PeriphLibraries/DMA_F4xx -I../PeriphLibraries/GPIO_F4xx -I../Drivers/CMSIS -I../AppLibraries/SPIFLASH -I../AppLibraries/LORA -I../AppLibraries/FT6236 -I../AppLibraries/TFT16BIT -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-AppLibraries-2f-lvgl-2f-src-2f-core

clean-AppLibraries-2f-lvgl-2f-src-2f-core:
	-$(RM) ./AppLibraries/lvgl/src/core/lv_disp.d ./AppLibraries/lvgl/src/core/lv_disp.o ./AppLibraries/lvgl/src/core/lv_disp.su ./AppLibraries/lvgl/src/core/lv_event.d ./AppLibraries/lvgl/src/core/lv_event.o ./AppLibraries/lvgl/src/core/lv_event.su ./AppLibraries/lvgl/src/core/lv_group.d ./AppLibraries/lvgl/src/core/lv_group.o ./AppLibraries/lvgl/src/core/lv_group.su ./AppLibraries/lvgl/src/core/lv_indev.d ./AppLibraries/lvgl/src/core/lv_indev.o ./AppLibraries/lvgl/src/core/lv_indev.su ./AppLibraries/lvgl/src/core/lv_indev_scroll.d ./AppLibraries/lvgl/src/core/lv_indev_scroll.o ./AppLibraries/lvgl/src/core/lv_indev_scroll.su ./AppLibraries/lvgl/src/core/lv_obj.d ./AppLibraries/lvgl/src/core/lv_obj.o ./AppLibraries/lvgl/src/core/lv_obj.su ./AppLibraries/lvgl/src/core/lv_obj_class.d ./AppLibraries/lvgl/src/core/lv_obj_class.o ./AppLibraries/lvgl/src/core/lv_obj_class.su ./AppLibraries/lvgl/src/core/lv_obj_draw.d ./AppLibraries/lvgl/src/core/lv_obj_draw.o ./AppLibraries/lvgl/src/core/lv_obj_draw.su ./AppLibraries/lvgl/src/core/lv_obj_pos.d ./AppLibraries/lvgl/src/core/lv_obj_pos.o ./AppLibraries/lvgl/src/core/lv_obj_pos.su ./AppLibraries/lvgl/src/core/lv_obj_scroll.d ./AppLibraries/lvgl/src/core/lv_obj_scroll.o ./AppLibraries/lvgl/src/core/lv_obj_scroll.su ./AppLibraries/lvgl/src/core/lv_obj_style.d ./AppLibraries/lvgl/src/core/lv_obj_style.o ./AppLibraries/lvgl/src/core/lv_obj_style.su ./AppLibraries/lvgl/src/core/lv_obj_style_gen.d ./AppLibraries/lvgl/src/core/lv_obj_style_gen.o ./AppLibraries/lvgl/src/core/lv_obj_style_gen.su ./AppLibraries/lvgl/src/core/lv_obj_tree.d ./AppLibraries/lvgl/src/core/lv_obj_tree.o ./AppLibraries/lvgl/src/core/lv_obj_tree.su ./AppLibraries/lvgl/src/core/lv_refr.d ./AppLibraries/lvgl/src/core/lv_refr.o ./AppLibraries/lvgl/src/core/lv_refr.su ./AppLibraries/lvgl/src/core/lv_theme.d ./AppLibraries/lvgl/src/core/lv_theme.o ./AppLibraries/lvgl/src/core/lv_theme.su

.PHONY: clean-AppLibraries-2f-lvgl-2f-src-2f-core

