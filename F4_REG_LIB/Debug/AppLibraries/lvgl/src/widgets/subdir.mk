################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../AppLibraries/lvgl/src/widgets/lv_arc.c \
../AppLibraries/lvgl/src/widgets/lv_bar.c \
../AppLibraries/lvgl/src/widgets/lv_btn.c \
../AppLibraries/lvgl/src/widgets/lv_btnmatrix.c \
../AppLibraries/lvgl/src/widgets/lv_canvas.c \
../AppLibraries/lvgl/src/widgets/lv_checkbox.c \
../AppLibraries/lvgl/src/widgets/lv_dropdown.c \
../AppLibraries/lvgl/src/widgets/lv_img.c \
../AppLibraries/lvgl/src/widgets/lv_label.c \
../AppLibraries/lvgl/src/widgets/lv_line.c \
../AppLibraries/lvgl/src/widgets/lv_objx_templ.c \
../AppLibraries/lvgl/src/widgets/lv_roller.c \
../AppLibraries/lvgl/src/widgets/lv_slider.c \
../AppLibraries/lvgl/src/widgets/lv_switch.c \
../AppLibraries/lvgl/src/widgets/lv_table.c \
../AppLibraries/lvgl/src/widgets/lv_textarea.c 

C_DEPS += \
./AppLibraries/lvgl/src/widgets/lv_arc.d \
./AppLibraries/lvgl/src/widgets/lv_bar.d \
./AppLibraries/lvgl/src/widgets/lv_btn.d \
./AppLibraries/lvgl/src/widgets/lv_btnmatrix.d \
./AppLibraries/lvgl/src/widgets/lv_canvas.d \
./AppLibraries/lvgl/src/widgets/lv_checkbox.d \
./AppLibraries/lvgl/src/widgets/lv_dropdown.d \
./AppLibraries/lvgl/src/widgets/lv_img.d \
./AppLibraries/lvgl/src/widgets/lv_label.d \
./AppLibraries/lvgl/src/widgets/lv_line.d \
./AppLibraries/lvgl/src/widgets/lv_objx_templ.d \
./AppLibraries/lvgl/src/widgets/lv_roller.d \
./AppLibraries/lvgl/src/widgets/lv_slider.d \
./AppLibraries/lvgl/src/widgets/lv_switch.d \
./AppLibraries/lvgl/src/widgets/lv_table.d \
./AppLibraries/lvgl/src/widgets/lv_textarea.d 

OBJS += \
./AppLibraries/lvgl/src/widgets/lv_arc.o \
./AppLibraries/lvgl/src/widgets/lv_bar.o \
./AppLibraries/lvgl/src/widgets/lv_btn.o \
./AppLibraries/lvgl/src/widgets/lv_btnmatrix.o \
./AppLibraries/lvgl/src/widgets/lv_canvas.o \
./AppLibraries/lvgl/src/widgets/lv_checkbox.o \
./AppLibraries/lvgl/src/widgets/lv_dropdown.o \
./AppLibraries/lvgl/src/widgets/lv_img.o \
./AppLibraries/lvgl/src/widgets/lv_label.o \
./AppLibraries/lvgl/src/widgets/lv_line.o \
./AppLibraries/lvgl/src/widgets/lv_objx_templ.o \
./AppLibraries/lvgl/src/widgets/lv_roller.o \
./AppLibraries/lvgl/src/widgets/lv_slider.o \
./AppLibraries/lvgl/src/widgets/lv_switch.o \
./AppLibraries/lvgl/src/widgets/lv_table.o \
./AppLibraries/lvgl/src/widgets/lv_textarea.o 


# Each subdirectory must supply rules for building sources it contributes
AppLibraries/lvgl/src/widgets/%.o AppLibraries/lvgl/src/widgets/%.su: ../AppLibraries/lvgl/src/widgets/%.c AppLibraries/lvgl/src/widgets/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F407VGTx -DSTM32F407xx -DHSE_VALUE=25000000UL -c -I../Drivers/Devices -I../AppLibraries/lvgl -I../AppLibraries/User_Interface -I../AppLibraries/GateWay_API -I../AppLibraries/LoRa_API -I../AppLibraries/ESP32_API -I../PeriphLibraries/TIM_F4xx -I../PeriphLibraries/SDMMC_F4xx -I../AppLibraries/DS3231 -I../PeriphLibraries -I../Src/Config -I../PeriphLibraries/STM_LOG -I../PeriphLibraries/SDIOMMC_F4xx -I../PeriphLibraries/PERIPH_STATUS -I../PeriphLibraries/SYSTEM_F4xx -I../PeriphLibraries/USART_F4xx -I../PeriphLibraries/RCC_F4xx -I../PeriphLibraries/SPI_F4xx -I../PeriphLibraries/I2C_F4xx -I../PeriphLibraries/IT_F4xx -I../PeriphLibraries/DMA_F4xx -I../PeriphLibraries/GPIO_F4xx -I../Drivers/CMSIS -I../AppLibraries/SPIFLASH -I../AppLibraries/LORA -I../AppLibraries/FT6236 -I../AppLibraries/TFT16BIT -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-AppLibraries-2f-lvgl-2f-src-2f-widgets

clean-AppLibraries-2f-lvgl-2f-src-2f-widgets:
	-$(RM) ./AppLibraries/lvgl/src/widgets/lv_arc.d ./AppLibraries/lvgl/src/widgets/lv_arc.o ./AppLibraries/lvgl/src/widgets/lv_arc.su ./AppLibraries/lvgl/src/widgets/lv_bar.d ./AppLibraries/lvgl/src/widgets/lv_bar.o ./AppLibraries/lvgl/src/widgets/lv_bar.su ./AppLibraries/lvgl/src/widgets/lv_btn.d ./AppLibraries/lvgl/src/widgets/lv_btn.o ./AppLibraries/lvgl/src/widgets/lv_btn.su ./AppLibraries/lvgl/src/widgets/lv_btnmatrix.d ./AppLibraries/lvgl/src/widgets/lv_btnmatrix.o ./AppLibraries/lvgl/src/widgets/lv_btnmatrix.su ./AppLibraries/lvgl/src/widgets/lv_canvas.d ./AppLibraries/lvgl/src/widgets/lv_canvas.o ./AppLibraries/lvgl/src/widgets/lv_canvas.su ./AppLibraries/lvgl/src/widgets/lv_checkbox.d ./AppLibraries/lvgl/src/widgets/lv_checkbox.o ./AppLibraries/lvgl/src/widgets/lv_checkbox.su ./AppLibraries/lvgl/src/widgets/lv_dropdown.d ./AppLibraries/lvgl/src/widgets/lv_dropdown.o ./AppLibraries/lvgl/src/widgets/lv_dropdown.su ./AppLibraries/lvgl/src/widgets/lv_img.d ./AppLibraries/lvgl/src/widgets/lv_img.o ./AppLibraries/lvgl/src/widgets/lv_img.su ./AppLibraries/lvgl/src/widgets/lv_label.d ./AppLibraries/lvgl/src/widgets/lv_label.o ./AppLibraries/lvgl/src/widgets/lv_label.su ./AppLibraries/lvgl/src/widgets/lv_line.d ./AppLibraries/lvgl/src/widgets/lv_line.o ./AppLibraries/lvgl/src/widgets/lv_line.su ./AppLibraries/lvgl/src/widgets/lv_objx_templ.d ./AppLibraries/lvgl/src/widgets/lv_objx_templ.o ./AppLibraries/lvgl/src/widgets/lv_objx_templ.su ./AppLibraries/lvgl/src/widgets/lv_roller.d ./AppLibraries/lvgl/src/widgets/lv_roller.o ./AppLibraries/lvgl/src/widgets/lv_roller.su ./AppLibraries/lvgl/src/widgets/lv_slider.d ./AppLibraries/lvgl/src/widgets/lv_slider.o ./AppLibraries/lvgl/src/widgets/lv_slider.su ./AppLibraries/lvgl/src/widgets/lv_switch.d ./AppLibraries/lvgl/src/widgets/lv_switch.o ./AppLibraries/lvgl/src/widgets/lv_switch.su ./AppLibraries/lvgl/src/widgets/lv_table.d ./AppLibraries/lvgl/src/widgets/lv_table.o ./AppLibraries/lvgl/src/widgets/lv_table.su ./AppLibraries/lvgl/src/widgets/lv_textarea.d ./AppLibraries/lvgl/src/widgets/lv_textarea.o ./AppLibraries/lvgl/src/widgets/lv_textarea.su

.PHONY: clean-AppLibraries-2f-lvgl-2f-src-2f-widgets

