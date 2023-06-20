################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../AppLibraries/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_alpha16.c \
../AppLibraries/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_argb.c \
../AppLibraries/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_chroma_keyed.c \
../AppLibraries/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_indexed16.c \
../AppLibraries/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_rgb.c \
../AppLibraries/lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_12_compr_az.c.c \
../AppLibraries/lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_16_compr_az.c.c \
../AppLibraries/lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_28_compr_az.c.c 

C_DEPS += \
./AppLibraries/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_alpha16.d \
./AppLibraries/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_argb.d \
./AppLibraries/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_chroma_keyed.d \
./AppLibraries/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_indexed16.d \
./AppLibraries/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_rgb.d \
./AppLibraries/lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_12_compr_az.c.d \
./AppLibraries/lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_16_compr_az.c.d \
./AppLibraries/lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_28_compr_az.c.d 

OBJS += \
./AppLibraries/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_alpha16.o \
./AppLibraries/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_argb.o \
./AppLibraries/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_chroma_keyed.o \
./AppLibraries/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_indexed16.o \
./AppLibraries/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_rgb.o \
./AppLibraries/lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_12_compr_az.c.o \
./AppLibraries/lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_16_compr_az.c.o \
./AppLibraries/lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_28_compr_az.c.o 


# Each subdirectory must supply rules for building sources it contributes
AppLibraries/lvgl/demos/benchmark/assets/%.o AppLibraries/lvgl/demos/benchmark/assets/%.su: ../AppLibraries/lvgl/demos/benchmark/assets/%.c AppLibraries/lvgl/demos/benchmark/assets/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F407VGTx -DSTM32F407xx -DHSE_VALUE=25000000UL -c -I../Drivers/Devices -I../AppLibraries/lvgl -I../AppLibraries/User_Interface -I../AppLibraries/GateWay_API -I../AppLibraries/LoRa_API -I../AppLibraries/ESP32_API -I../PeriphLibraries/TIM_F4xx -I../PeriphLibraries/SDMMC_F4xx -I../AppLibraries/DS3231 -I../PeriphLibraries -I../Src/Config -I../PeriphLibraries/STM_LOG -I../PeriphLibraries/SDIOMMC_F4xx -I../PeriphLibraries/PERIPH_STATUS -I../PeriphLibraries/SYSTEM_F4xx -I../PeriphLibraries/USART_F4xx -I../PeriphLibraries/RCC_F4xx -I../PeriphLibraries/SPI_F4xx -I../PeriphLibraries/I2C_F4xx -I../PeriphLibraries/IT_F4xx -I../PeriphLibraries/DMA_F4xx -I../PeriphLibraries/GPIO_F4xx -I../Drivers/CMSIS -I../AppLibraries/SPIFLASH -I../AppLibraries/LORA -I../AppLibraries/FT6236 -I../AppLibraries/TFT16BIT -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-AppLibraries-2f-lvgl-2f-demos-2f-benchmark-2f-assets

clean-AppLibraries-2f-lvgl-2f-demos-2f-benchmark-2f-assets:
	-$(RM) ./AppLibraries/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_alpha16.d ./AppLibraries/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_alpha16.o ./AppLibraries/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_alpha16.su ./AppLibraries/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_argb.d ./AppLibraries/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_argb.o ./AppLibraries/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_argb.su ./AppLibraries/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_chroma_keyed.d ./AppLibraries/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_chroma_keyed.o ./AppLibraries/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_chroma_keyed.su ./AppLibraries/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_indexed16.d ./AppLibraries/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_indexed16.o ./AppLibraries/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_indexed16.su ./AppLibraries/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_rgb.d ./AppLibraries/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_rgb.o ./AppLibraries/lvgl/demos/benchmark/assets/img_benchmark_cogwheel_rgb.su ./AppLibraries/lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_12_compr_az.c.d ./AppLibraries/lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_12_compr_az.c.o ./AppLibraries/lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_12_compr_az.c.su ./AppLibraries/lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_16_compr_az.c.d ./AppLibraries/lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_16_compr_az.c.o ./AppLibraries/lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_16_compr_az.c.su ./AppLibraries/lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_28_compr_az.c.d ./AppLibraries/lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_28_compr_az.c.o ./AppLibraries/lvgl/demos/benchmark/assets/lv_font_bechmark_montserrat_28_compr_az.c.su

.PHONY: clean-AppLibraries-2f-lvgl-2f-demos-2f-benchmark-2f-assets

