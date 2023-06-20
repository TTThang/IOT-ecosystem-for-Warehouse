################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../AppLibraries/lvgl/src/misc/lv_anim.c \
../AppLibraries/lvgl/src/misc/lv_anim_timeline.c \
../AppLibraries/lvgl/src/misc/lv_area.c \
../AppLibraries/lvgl/src/misc/lv_async.c \
../AppLibraries/lvgl/src/misc/lv_bidi.c \
../AppLibraries/lvgl/src/misc/lv_color.c \
../AppLibraries/lvgl/src/misc/lv_fs.c \
../AppLibraries/lvgl/src/misc/lv_gc.c \
../AppLibraries/lvgl/src/misc/lv_ll.c \
../AppLibraries/lvgl/src/misc/lv_log.c \
../AppLibraries/lvgl/src/misc/lv_lru.c \
../AppLibraries/lvgl/src/misc/lv_math.c \
../AppLibraries/lvgl/src/misc/lv_mem.c \
../AppLibraries/lvgl/src/misc/lv_printf.c \
../AppLibraries/lvgl/src/misc/lv_style.c \
../AppLibraries/lvgl/src/misc/lv_style_gen.c \
../AppLibraries/lvgl/src/misc/lv_templ.c \
../AppLibraries/lvgl/src/misc/lv_timer.c \
../AppLibraries/lvgl/src/misc/lv_tlsf.c \
../AppLibraries/lvgl/src/misc/lv_txt.c \
../AppLibraries/lvgl/src/misc/lv_txt_ap.c \
../AppLibraries/lvgl/src/misc/lv_utils.c 

C_DEPS += \
./AppLibraries/lvgl/src/misc/lv_anim.d \
./AppLibraries/lvgl/src/misc/lv_anim_timeline.d \
./AppLibraries/lvgl/src/misc/lv_area.d \
./AppLibraries/lvgl/src/misc/lv_async.d \
./AppLibraries/lvgl/src/misc/lv_bidi.d \
./AppLibraries/lvgl/src/misc/lv_color.d \
./AppLibraries/lvgl/src/misc/lv_fs.d \
./AppLibraries/lvgl/src/misc/lv_gc.d \
./AppLibraries/lvgl/src/misc/lv_ll.d \
./AppLibraries/lvgl/src/misc/lv_log.d \
./AppLibraries/lvgl/src/misc/lv_lru.d \
./AppLibraries/lvgl/src/misc/lv_math.d \
./AppLibraries/lvgl/src/misc/lv_mem.d \
./AppLibraries/lvgl/src/misc/lv_printf.d \
./AppLibraries/lvgl/src/misc/lv_style.d \
./AppLibraries/lvgl/src/misc/lv_style_gen.d \
./AppLibraries/lvgl/src/misc/lv_templ.d \
./AppLibraries/lvgl/src/misc/lv_timer.d \
./AppLibraries/lvgl/src/misc/lv_tlsf.d \
./AppLibraries/lvgl/src/misc/lv_txt.d \
./AppLibraries/lvgl/src/misc/lv_txt_ap.d \
./AppLibraries/lvgl/src/misc/lv_utils.d 

OBJS += \
./AppLibraries/lvgl/src/misc/lv_anim.o \
./AppLibraries/lvgl/src/misc/lv_anim_timeline.o \
./AppLibraries/lvgl/src/misc/lv_area.o \
./AppLibraries/lvgl/src/misc/lv_async.o \
./AppLibraries/lvgl/src/misc/lv_bidi.o \
./AppLibraries/lvgl/src/misc/lv_color.o \
./AppLibraries/lvgl/src/misc/lv_fs.o \
./AppLibraries/lvgl/src/misc/lv_gc.o \
./AppLibraries/lvgl/src/misc/lv_ll.o \
./AppLibraries/lvgl/src/misc/lv_log.o \
./AppLibraries/lvgl/src/misc/lv_lru.o \
./AppLibraries/lvgl/src/misc/lv_math.o \
./AppLibraries/lvgl/src/misc/lv_mem.o \
./AppLibraries/lvgl/src/misc/lv_printf.o \
./AppLibraries/lvgl/src/misc/lv_style.o \
./AppLibraries/lvgl/src/misc/lv_style_gen.o \
./AppLibraries/lvgl/src/misc/lv_templ.o \
./AppLibraries/lvgl/src/misc/lv_timer.o \
./AppLibraries/lvgl/src/misc/lv_tlsf.o \
./AppLibraries/lvgl/src/misc/lv_txt.o \
./AppLibraries/lvgl/src/misc/lv_txt_ap.o \
./AppLibraries/lvgl/src/misc/lv_utils.o 


# Each subdirectory must supply rules for building sources it contributes
AppLibraries/lvgl/src/misc/%.o AppLibraries/lvgl/src/misc/%.su: ../AppLibraries/lvgl/src/misc/%.c AppLibraries/lvgl/src/misc/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F407VGTx -DSTM32F407xx -DHSE_VALUE=25000000UL -c -I../Drivers/Devices -I../AppLibraries/lvgl -I../AppLibraries/User_Interface -I../AppLibraries/GateWay_API -I../AppLibraries/LoRa_API -I../AppLibraries/ESP32_API -I../PeriphLibraries/TIM_F4xx -I../PeriphLibraries/SDMMC_F4xx -I../AppLibraries/DS3231 -I../PeriphLibraries -I../Src/Config -I../PeriphLibraries/STM_LOG -I../PeriphLibraries/SDIOMMC_F4xx -I../PeriphLibraries/PERIPH_STATUS -I../PeriphLibraries/SYSTEM_F4xx -I../PeriphLibraries/USART_F4xx -I../PeriphLibraries/RCC_F4xx -I../PeriphLibraries/SPI_F4xx -I../PeriphLibraries/I2C_F4xx -I../PeriphLibraries/IT_F4xx -I../PeriphLibraries/DMA_F4xx -I../PeriphLibraries/GPIO_F4xx -I../Drivers/CMSIS -I../AppLibraries/SPIFLASH -I../AppLibraries/LORA -I../AppLibraries/FT6236 -I../AppLibraries/TFT16BIT -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-AppLibraries-2f-lvgl-2f-src-2f-misc

clean-AppLibraries-2f-lvgl-2f-src-2f-misc:
	-$(RM) ./AppLibraries/lvgl/src/misc/lv_anim.d ./AppLibraries/lvgl/src/misc/lv_anim.o ./AppLibraries/lvgl/src/misc/lv_anim.su ./AppLibraries/lvgl/src/misc/lv_anim_timeline.d ./AppLibraries/lvgl/src/misc/lv_anim_timeline.o ./AppLibraries/lvgl/src/misc/lv_anim_timeline.su ./AppLibraries/lvgl/src/misc/lv_area.d ./AppLibraries/lvgl/src/misc/lv_area.o ./AppLibraries/lvgl/src/misc/lv_area.su ./AppLibraries/lvgl/src/misc/lv_async.d ./AppLibraries/lvgl/src/misc/lv_async.o ./AppLibraries/lvgl/src/misc/lv_async.su ./AppLibraries/lvgl/src/misc/lv_bidi.d ./AppLibraries/lvgl/src/misc/lv_bidi.o ./AppLibraries/lvgl/src/misc/lv_bidi.su ./AppLibraries/lvgl/src/misc/lv_color.d ./AppLibraries/lvgl/src/misc/lv_color.o ./AppLibraries/lvgl/src/misc/lv_color.su ./AppLibraries/lvgl/src/misc/lv_fs.d ./AppLibraries/lvgl/src/misc/lv_fs.o ./AppLibraries/lvgl/src/misc/lv_fs.su ./AppLibraries/lvgl/src/misc/lv_gc.d ./AppLibraries/lvgl/src/misc/lv_gc.o ./AppLibraries/lvgl/src/misc/lv_gc.su ./AppLibraries/lvgl/src/misc/lv_ll.d ./AppLibraries/lvgl/src/misc/lv_ll.o ./AppLibraries/lvgl/src/misc/lv_ll.su ./AppLibraries/lvgl/src/misc/lv_log.d ./AppLibraries/lvgl/src/misc/lv_log.o ./AppLibraries/lvgl/src/misc/lv_log.su ./AppLibraries/lvgl/src/misc/lv_lru.d ./AppLibraries/lvgl/src/misc/lv_lru.o ./AppLibraries/lvgl/src/misc/lv_lru.su ./AppLibraries/lvgl/src/misc/lv_math.d ./AppLibraries/lvgl/src/misc/lv_math.o ./AppLibraries/lvgl/src/misc/lv_math.su ./AppLibraries/lvgl/src/misc/lv_mem.d ./AppLibraries/lvgl/src/misc/lv_mem.o ./AppLibraries/lvgl/src/misc/lv_mem.su ./AppLibraries/lvgl/src/misc/lv_printf.d ./AppLibraries/lvgl/src/misc/lv_printf.o ./AppLibraries/lvgl/src/misc/lv_printf.su ./AppLibraries/lvgl/src/misc/lv_style.d ./AppLibraries/lvgl/src/misc/lv_style.o ./AppLibraries/lvgl/src/misc/lv_style.su ./AppLibraries/lvgl/src/misc/lv_style_gen.d ./AppLibraries/lvgl/src/misc/lv_style_gen.o ./AppLibraries/lvgl/src/misc/lv_style_gen.su ./AppLibraries/lvgl/src/misc/lv_templ.d ./AppLibraries/lvgl/src/misc/lv_templ.o ./AppLibraries/lvgl/src/misc/lv_templ.su ./AppLibraries/lvgl/src/misc/lv_timer.d ./AppLibraries/lvgl/src/misc/lv_timer.o ./AppLibraries/lvgl/src/misc/lv_timer.su ./AppLibraries/lvgl/src/misc/lv_tlsf.d ./AppLibraries/lvgl/src/misc/lv_tlsf.o ./AppLibraries/lvgl/src/misc/lv_tlsf.su ./AppLibraries/lvgl/src/misc/lv_txt.d ./AppLibraries/lvgl/src/misc/lv_txt.o ./AppLibraries/lvgl/src/misc/lv_txt.su ./AppLibraries/lvgl/src/misc/lv_txt_ap.d ./AppLibraries/lvgl/src/misc/lv_txt_ap.o ./AppLibraries/lvgl/src/misc/lv_txt_ap.su ./AppLibraries/lvgl/src/misc/lv_utils.d ./AppLibraries/lvgl/src/misc/lv_utils.o ./AppLibraries/lvgl/src/misc/lv_utils.su

.PHONY: clean-AppLibraries-2f-lvgl-2f-src-2f-misc

