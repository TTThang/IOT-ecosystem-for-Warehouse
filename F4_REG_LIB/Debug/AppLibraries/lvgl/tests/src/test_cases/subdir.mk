################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../AppLibraries/lvgl/tests/src/test_cases/_test_template.c \
../AppLibraries/lvgl/tests/src/test_cases/test_arc.c \
../AppLibraries/lvgl/tests/src/test_cases/test_bar.c \
../AppLibraries/lvgl/tests/src/test_cases/test_checkbox.c \
../AppLibraries/lvgl/tests/src/test_cases/test_config.c \
../AppLibraries/lvgl/tests/src/test_cases/test_demo_stress.c \
../AppLibraries/lvgl/tests/src/test_cases/test_demo_widgets.c \
../AppLibraries/lvgl/tests/src/test_cases/test_dropdown.c \
../AppLibraries/lvgl/tests/src/test_cases/test_event.c \
../AppLibraries/lvgl/tests/src/test_cases/test_font_loader.c \
../AppLibraries/lvgl/tests/src/test_cases/test_fs.c \
../AppLibraries/lvgl/tests/src/test_cases/test_line.c \
../AppLibraries/lvgl/tests/src/test_cases/test_mem.c \
../AppLibraries/lvgl/tests/src/test_cases/test_obj_tree.c \
../AppLibraries/lvgl/tests/src/test_cases/test_slider.c \
../AppLibraries/lvgl/tests/src/test_cases/test_snapshot.c \
../AppLibraries/lvgl/tests/src/test_cases/test_style.c \
../AppLibraries/lvgl/tests/src/test_cases/test_switch.c \
../AppLibraries/lvgl/tests/src/test_cases/test_table.c \
../AppLibraries/lvgl/tests/src/test_cases/test_textarea.c \
../AppLibraries/lvgl/tests/src/test_cases/test_txt.c 

C_DEPS += \
./AppLibraries/lvgl/tests/src/test_cases/_test_template.d \
./AppLibraries/lvgl/tests/src/test_cases/test_arc.d \
./AppLibraries/lvgl/tests/src/test_cases/test_bar.d \
./AppLibraries/lvgl/tests/src/test_cases/test_checkbox.d \
./AppLibraries/lvgl/tests/src/test_cases/test_config.d \
./AppLibraries/lvgl/tests/src/test_cases/test_demo_stress.d \
./AppLibraries/lvgl/tests/src/test_cases/test_demo_widgets.d \
./AppLibraries/lvgl/tests/src/test_cases/test_dropdown.d \
./AppLibraries/lvgl/tests/src/test_cases/test_event.d \
./AppLibraries/lvgl/tests/src/test_cases/test_font_loader.d \
./AppLibraries/lvgl/tests/src/test_cases/test_fs.d \
./AppLibraries/lvgl/tests/src/test_cases/test_line.d \
./AppLibraries/lvgl/tests/src/test_cases/test_mem.d \
./AppLibraries/lvgl/tests/src/test_cases/test_obj_tree.d \
./AppLibraries/lvgl/tests/src/test_cases/test_slider.d \
./AppLibraries/lvgl/tests/src/test_cases/test_snapshot.d \
./AppLibraries/lvgl/tests/src/test_cases/test_style.d \
./AppLibraries/lvgl/tests/src/test_cases/test_switch.d \
./AppLibraries/lvgl/tests/src/test_cases/test_table.d \
./AppLibraries/lvgl/tests/src/test_cases/test_textarea.d \
./AppLibraries/lvgl/tests/src/test_cases/test_txt.d 

OBJS += \
./AppLibraries/lvgl/tests/src/test_cases/_test_template.o \
./AppLibraries/lvgl/tests/src/test_cases/test_arc.o \
./AppLibraries/lvgl/tests/src/test_cases/test_bar.o \
./AppLibraries/lvgl/tests/src/test_cases/test_checkbox.o \
./AppLibraries/lvgl/tests/src/test_cases/test_config.o \
./AppLibraries/lvgl/tests/src/test_cases/test_demo_stress.o \
./AppLibraries/lvgl/tests/src/test_cases/test_demo_widgets.o \
./AppLibraries/lvgl/tests/src/test_cases/test_dropdown.o \
./AppLibraries/lvgl/tests/src/test_cases/test_event.o \
./AppLibraries/lvgl/tests/src/test_cases/test_font_loader.o \
./AppLibraries/lvgl/tests/src/test_cases/test_fs.o \
./AppLibraries/lvgl/tests/src/test_cases/test_line.o \
./AppLibraries/lvgl/tests/src/test_cases/test_mem.o \
./AppLibraries/lvgl/tests/src/test_cases/test_obj_tree.o \
./AppLibraries/lvgl/tests/src/test_cases/test_slider.o \
./AppLibraries/lvgl/tests/src/test_cases/test_snapshot.o \
./AppLibraries/lvgl/tests/src/test_cases/test_style.o \
./AppLibraries/lvgl/tests/src/test_cases/test_switch.o \
./AppLibraries/lvgl/tests/src/test_cases/test_table.o \
./AppLibraries/lvgl/tests/src/test_cases/test_textarea.o \
./AppLibraries/lvgl/tests/src/test_cases/test_txt.o 


# Each subdirectory must supply rules for building sources it contributes
AppLibraries/lvgl/tests/src/test_cases/%.o AppLibraries/lvgl/tests/src/test_cases/%.su: ../AppLibraries/lvgl/tests/src/test_cases/%.c AppLibraries/lvgl/tests/src/test_cases/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F407VGTx -DSTM32F407xx -DHSE_VALUE=25000000UL -c -I../Drivers/Devices -I../AppLibraries/lvgl -I../AppLibraries/User_Interface -I../AppLibraries/GateWay_API -I../AppLibraries/LoRa_API -I../AppLibraries/ESP32_API -I../PeriphLibraries/TIM_F4xx -I../PeriphLibraries/SDMMC_F4xx -I../AppLibraries/DS3231 -I../PeriphLibraries -I../Src/Config -I../PeriphLibraries/STM_LOG -I../PeriphLibraries/SDIOMMC_F4xx -I../PeriphLibraries/PERIPH_STATUS -I../PeriphLibraries/SYSTEM_F4xx -I../PeriphLibraries/USART_F4xx -I../PeriphLibraries/RCC_F4xx -I../PeriphLibraries/SPI_F4xx -I../PeriphLibraries/I2C_F4xx -I../PeriphLibraries/IT_F4xx -I../PeriphLibraries/DMA_F4xx -I../PeriphLibraries/GPIO_F4xx -I../Drivers/CMSIS -I../AppLibraries/SPIFLASH -I../AppLibraries/LORA -I../AppLibraries/FT6236 -I../AppLibraries/TFT16BIT -Ofast -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-AppLibraries-2f-lvgl-2f-tests-2f-src-2f-test_cases

clean-AppLibraries-2f-lvgl-2f-tests-2f-src-2f-test_cases:
	-$(RM) ./AppLibraries/lvgl/tests/src/test_cases/_test_template.d ./AppLibraries/lvgl/tests/src/test_cases/_test_template.o ./AppLibraries/lvgl/tests/src/test_cases/_test_template.su ./AppLibraries/lvgl/tests/src/test_cases/test_arc.d ./AppLibraries/lvgl/tests/src/test_cases/test_arc.o ./AppLibraries/lvgl/tests/src/test_cases/test_arc.su ./AppLibraries/lvgl/tests/src/test_cases/test_bar.d ./AppLibraries/lvgl/tests/src/test_cases/test_bar.o ./AppLibraries/lvgl/tests/src/test_cases/test_bar.su ./AppLibraries/lvgl/tests/src/test_cases/test_checkbox.d ./AppLibraries/lvgl/tests/src/test_cases/test_checkbox.o ./AppLibraries/lvgl/tests/src/test_cases/test_checkbox.su ./AppLibraries/lvgl/tests/src/test_cases/test_config.d ./AppLibraries/lvgl/tests/src/test_cases/test_config.o ./AppLibraries/lvgl/tests/src/test_cases/test_config.su ./AppLibraries/lvgl/tests/src/test_cases/test_demo_stress.d ./AppLibraries/lvgl/tests/src/test_cases/test_demo_stress.o ./AppLibraries/lvgl/tests/src/test_cases/test_demo_stress.su ./AppLibraries/lvgl/tests/src/test_cases/test_demo_widgets.d ./AppLibraries/lvgl/tests/src/test_cases/test_demo_widgets.o ./AppLibraries/lvgl/tests/src/test_cases/test_demo_widgets.su ./AppLibraries/lvgl/tests/src/test_cases/test_dropdown.d ./AppLibraries/lvgl/tests/src/test_cases/test_dropdown.o ./AppLibraries/lvgl/tests/src/test_cases/test_dropdown.su ./AppLibraries/lvgl/tests/src/test_cases/test_event.d ./AppLibraries/lvgl/tests/src/test_cases/test_event.o ./AppLibraries/lvgl/tests/src/test_cases/test_event.su ./AppLibraries/lvgl/tests/src/test_cases/test_font_loader.d ./AppLibraries/lvgl/tests/src/test_cases/test_font_loader.o ./AppLibraries/lvgl/tests/src/test_cases/test_font_loader.su ./AppLibraries/lvgl/tests/src/test_cases/test_fs.d ./AppLibraries/lvgl/tests/src/test_cases/test_fs.o ./AppLibraries/lvgl/tests/src/test_cases/test_fs.su ./AppLibraries/lvgl/tests/src/test_cases/test_line.d ./AppLibraries/lvgl/tests/src/test_cases/test_line.o ./AppLibraries/lvgl/tests/src/test_cases/test_line.su ./AppLibraries/lvgl/tests/src/test_cases/test_mem.d ./AppLibraries/lvgl/tests/src/test_cases/test_mem.o ./AppLibraries/lvgl/tests/src/test_cases/test_mem.su ./AppLibraries/lvgl/tests/src/test_cases/test_obj_tree.d ./AppLibraries/lvgl/tests/src/test_cases/test_obj_tree.o ./AppLibraries/lvgl/tests/src/test_cases/test_obj_tree.su ./AppLibraries/lvgl/tests/src/test_cases/test_slider.d ./AppLibraries/lvgl/tests/src/test_cases/test_slider.o ./AppLibraries/lvgl/tests/src/test_cases/test_slider.su ./AppLibraries/lvgl/tests/src/test_cases/test_snapshot.d ./AppLibraries/lvgl/tests/src/test_cases/test_snapshot.o ./AppLibraries/lvgl/tests/src/test_cases/test_snapshot.su ./AppLibraries/lvgl/tests/src/test_cases/test_style.d ./AppLibraries/lvgl/tests/src/test_cases/test_style.o ./AppLibraries/lvgl/tests/src/test_cases/test_style.su ./AppLibraries/lvgl/tests/src/test_cases/test_switch.d ./AppLibraries/lvgl/tests/src/test_cases/test_switch.o ./AppLibraries/lvgl/tests/src/test_cases/test_switch.su ./AppLibraries/lvgl/tests/src/test_cases/test_table.d ./AppLibraries/lvgl/tests/src/test_cases/test_table.o ./AppLibraries/lvgl/tests/src/test_cases/test_table.su ./AppLibraries/lvgl/tests/src/test_cases/test_textarea.d ./AppLibraries/lvgl/tests/src/test_cases/test_textarea.o ./AppLibraries/lvgl/tests/src/test_cases/test_textarea.su ./AppLibraries/lvgl/tests/src/test_cases/test_txt.d ./AppLibraries/lvgl/tests/src/test_cases/test_txt.o ./AppLibraries/lvgl/tests/src/test_cases/test_txt.su

.PHONY: clean-AppLibraries-2f-lvgl-2f-tests-2f-src-2f-test_cases

