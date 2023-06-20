/*
 * Config.h
 *
 *  Created on: Nov 7, 2022
 *      Author: anh
 */

#ifndef CONFIG_H_
#define CONFIG_H_


#include "PERIPH_USED.h"
#include "PERIPH_STATUS.h"

#include "SYSTEM_F4xx.h"
#include "IT_F4xx.h"
#include "RCC_F4xx.h"
#include "DMA_F4xx.h"
#include "GPIO_F4xx.h"
#include "TIM_F4xx.h"
#include "USART_F4xx.h"
#include "SPI_F4xx.hpp"
#include "I2C_F4xx.h"
#include "STM_LOG.h"

#include "TFT16BIT.h"
#include "SPIFLASH.h"
#include "LORA.h"
#include "DS3231.h"
#include "FT6236.h"
#include "ESP32_API.h"
#include "LoRa_API.h"

#include "lvgl.h"
#include "lv_conf.h"
#include "ui.h"
#include "lib_out.h"
#include "queue"

#ifdef __cplusplus
extern "C"{
#endif


/* LoRa have highest priority */
#define LORA_REQUEST_TIMER_INTERRUPT_PRIORITY 8
#define LORA_PRIORITY 10

#define UART_PRIORITY 4
#define UART_TXDMA_PRIORITY 0

#define SPIFLS_RXDMA_PRIORITY 6

#define LCD_HORIZONTAL 480
#define LCD_VERTICAL   320
#define BUFFOR_SCR_ROWS 10

extern PowerConfig_t pwr;
extern FlashMemConfig_t flash;
extern RCC_Config_t rcc;


extern DMA_Config_t uart_log_TxDma_conf;
extern DMA *uart_log_TxDma;
extern USART_Config_t uart_log_conf;
extern USART *uart_log;
extern volatile uint8_t dma_uart_log_tx_flag;

extern DMA_Config_t fls_spi_RxDma_conf;
extern DMA *fls_spi_RxDma;
extern SPI_Config_t fls_spi_conf;
extern SPI<uint8_t> fls_spi;
extern SPIFLASH spiflash;

extern I2C_Config_t i2c1_conf;
extern I2C i2c1;

extern I2C_Config_t i2c2_conf;
extern I2C i2c2;

extern SPI_Config_t lora_spi_conf;
extern SPI<uint8_t> lora_spi;
extern LoRa lora;

extern TIM_Config_t lora_req_tim_conf;
extern TIM *lora_req_tim;
extern TIM_Config_t lora_resp_tim_conf;
extern TIM *lora_resp_tim;


extern DS3231_Time_t time;
extern TIM_Config_t time_tim_conf;
extern TIM *time_tim;

//extern uint8_t *uart_Rxbuf;
extern std::queue<uint8_t*> Packet_Uart_Queue;

extern volatile bool esp_ok;
extern volatile bool RxFromEsp_Flag;
extern volatile bool LoRa_ReqTimer_Flag;
extern volatile bool GetTime_Flag;
extern volatile uint32_t tick;


extern bool ETH_Connected, WiFi_Connected, MQTT_Connected;
extern char *WF_SSID, *WF_PASS;
extern char *MQTT_URL, *MQTT_USER, *MQTT_PASS;




void Periph_Initialize(void);


void DMA2_Stream0_TranferComplete_CallBack(void *Paramemter, DMA_Event_t event);
void DMA2_Stream7_TranferComplete_CallBack(void *Paramemter, DMA_Event_t event);

void USART1_Event_Callback(void *Parameter, USART_Event_t event);

void LoRa_Request_TimerCallback(void *Parameter, TIM_Event_t event);

void DS3231_TimerCallback(void *Parameter, TIM_Event_t event);

void LVGL_Init(void);
void LV_TFT_Driver(lv_disp_drv_t * drv, const lv_area_t * area,  lv_color_t * color_map);
void lv_Touch_Driver(lv_indev_drv_t * drv, lv_indev_data_t*data);

#ifdef __cplusplus
}
#endif

#endif /* CONFIG_H_ */
