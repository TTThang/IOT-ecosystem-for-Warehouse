/*
 * Config.cpp
 *
 *  Created on: Nov 7, 2022
 *      Author: anh
 */

#include "Config.h"
#include "string.h"
#include "stdio.h"
#include "vector"


PowerConfig_t pwr = {
	.power_voltscale2 = true,
	.power_clockenable = true,
};

FlashMemConfig_t flash = {
	.rcc_systemclock = 168000000U,
	.flash_latency = 5U,
	.flash_prefetch = true,
	.flash_instructioncache = true,
	.flash_datacache  =true,
};

RCC_Config_t rcc = {
	.rcc_clocksource          = HSE_CRYSTAL,
	.rcc_hsifrequency = HSI_VALUE,
	.rcc_hsitrim        = 16U,
	.rcc_hsefrequency = HSE_VALUE,
	.rcc_clockmux             = PLLCLK,
	.rcc_systemfrequency      = 168000000U,
	.rcc_ahbprescaler  	   = RCC_CFGR_HPRE_DIV1,
	.rcc_apb1prescaler 	   = RCC_CFGR_PPRE1_DIV4,
	.rcc_apb2prescaler 	   = RCC_CFGR_PPRE2_DIV2,
	rcc.rcc_pll.rcc_pllm = 25U,
	rcc.rcc_pll.rcc_plln = 336U,
	rcc.rcc_pll.rcc_pllp = 2U,
	rcc.rcc_pll.rcc_pllq = 7U,
};




DMA_Config_t uart_log_TxDma_conf = {
	.dma = DMA2,
	.dma_stream = DMA2_Stream7,
	.dma_channel = DMA_Channel4,
	.dma_direction = DMA_MEM_TO_PERIPH,
	.dma_mode = DMA_NORMAL,
	.dma_data_size = DMA_DATA8BIT,
	.dma_fifo = DMA_NOFIFO,
	.dma_channel_priority = DMA_CHANNEL_PRIORITY_HIGH,
	.dma_interrupt_select = DMA_TRANSFER_COMPLETE_INTERRUPT,
	.dma_interrupt_priority = UART_TXDMA_PRIORITY,
};
DMA *uart_log_TxDma = &dma2_stream7;

USART_Config_t uart_log_conf = {
	.usart_baudrate = 115200,
	.usart_type = USART_INTERRUPT_DMA,
	.usart_interruptselect = USART_INTR_RX,
	.usart_interruptpriority = UART_PRIORITY,
	.TxPort = GPIOB,
	.TxPin = 6,
	.RxPort = GPIOB,
	.RxPin = 7,
	.TxDma = uart_log_TxDma,
};
USART *uart_log = &usart1;
volatile uint8_t dma_uart_log_tx_flag = 0;






DMA_Config_t fls_spi_RxDma_conf = {
	.dma = DMA2,
	.dma_stream = DMA2_Stream0,
	.dma_channel = DMA_Channel3,
	.dma_direction = DMA_PERIH_TO_MEM,
	.dma_mode = DMA_NORMAL,
	.dma_data_size = DMA_DATA8BIT,
	.dma_fifo = DMA_NOFIFO,
	.dma_channel_priority = DMA_CHANNEL_PRIORITY_LOW,
	.dma_interrupt_select = DMA_TRANSFER_COMPLETE_INTERRUPT,
	.dma_interrupt_priority = SPIFLS_RXDMA_PRIORITY,
};
DMA *fls_spi_RxDma = &dma2_stream0;

SPI_Config_t fls_spi_conf = {
	.spi_mode = SPI_FULLDUPLEXMASTER,
	.spi_type = SPI_NORMAL_DMA,
	.spi_datasize = SPI_DATA8BIT,
	.spi_dataformat = SPI_DATAMSB,
	.spi_clockdivision = SPI_CLOCKDIV4,
	.spi_clocksample = SPI_CPOL0_CPHA0,
	.spi_interruptpriority = 0,
	.spi_irq = SPI1_IRQn,
	.CLKPort = GPIOA,
	.CLKPin = 5,
	.MISOPort = GPIOA,
	.MISOPin = 6,
	.MOSIPort = GPIOA,
	.MOSIPin = 7,
	.RxDma = fls_spi_RxDma,
};
SPI<uint8_t> fls_spi(SPI1);

SPIFLASH spiflash(GPIOE, 1);



TIM_Config_t lora_req_tim_conf = {
	.tim_mode = TIM_BASIC,
	.tim_prescaler = 42000U,
	.tim_reloadvalue = 10000U,
	.tim_direction =TIM_COUNTER_UP,
	.tim_autoreloadpreload = TIM_ARP_DISABLE,
	.tim_interrupt = TIM_INTERRUPT_ENABLE,
	.tim_interruptpriority = LORA_REQUEST_TIMER_INTERRUPT_PRIORITY,
};
TIM *lora_req_tim = &tim2;

SPI_Config_t lora_spi_conf = {
	.spi_mode = SPI_FULLDUPLEXMASTER,
	.spi_type = SPI_NORMAL_DMA,
	.spi_datasize = SPI_DATA8BIT,
	.spi_dataformat = SPI_DATAMSB,
	.spi_clockdivision = SPI_CLOCKDIV4,
	.spi_clocksample = SPI_CPOL0_CPHA0,
	.spi_interruptpriority = 0,
	.spi_irq = SPI3_IRQn,
	.CLKPort = GPIOB,
	.CLKPin = 3,
	.MISOPort = GPIOB,
	.MISOPin = 4,
	.MOSIPort = GPIOB,
	.MOSIPin = 5,
};
SPI<uint8_t> lora_spi(SPI3);

LoRa lora(GPIOA, 8, GPIOA, 10, GPIOD, 3);

TIM_Config_t lora_resp_tim_conf = {
	.tim_mode = TIM_BASIC,
	.tim_prescaler = 42000U,
	.tim_reloadvalue = 10000U,
	.tim_direction =TIM_COUNTER_UP,
	.tim_autoreloadpreload = TIM_ARP_DISABLE,
	.tim_interrupt = TIM_INTERRUPT_ENABLE,
	.tim_interruptpriority = LORA_REQUEST_TIMER_INTERRUPT_PRIORITY,
};
TIM *lora_resp_tim = &tim3;


I2C_Config_t i2c1_conf = {
	.i2c_mode = I2C_FAST_MODE,
	.i2c_frequency = 400000UL,
	.SCLPort = GPIOB,
	.SCLPin = 8,
	.SDAPort = GPIOB,
	.SDAPin = 9,
};
I2C i2c1(I2C1);

DS3231_Time_t time = {
	.seconds = 0,
	.minutes = 49,
	.hour = 18,
	.dayofweek = 7,
	.dayofmonth = 23,
	.month = 12,
	.year = 22,
};

TIM_Config_t time_tim_conf = {
	.tim_mode = TIM_BASIC,
	.tim_prescaler = 42000U,
	.tim_reloadvalue = 2000U,
	.tim_direction =TIM_COUNTER_UP,
	.tim_autoreloadpreload = TIM_ARP_DISABLE,
	.tim_interrupt = TIM_INTERRUPT_ENABLE,
	.tim_interruptpriority = LORA_REQUEST_TIMER_INTERRUPT_PRIORITY,
};
TIM *time_tim = &tim4;


I2C_Config_t i2c2_conf = {
	.i2c_mode = I2C_FAST_MODE,
	.i2c_frequency = 400000UL,
	.SCLPort = GPIOB,
	.SCLPin = 10,
	.SDAPort = GPIOB,
	.SDAPin = 11,
};
I2C i2c2(I2C2);


static Result_t res;
static const char * TAG = "STM32_LOG";
//uint8_t *uart_Rxbuf;
volatile uint32_t count = 0, tick = 0;;
std::queue<uint8_t*> Packet_Uart_Queue;

volatile bool esp_ok = false;
volatile bool RxFromEsp_Flag = false;
volatile bool LoRa_ReqTimer_Flag = false;
volatile bool GetTime_Flag = false;
extern std::vector<char*>Control_list;

static lv_disp_draw_buf_t disp_buf;
static lv_indev_drv_t indev_drv;
static lv_color_t buf_1[LCD_HORIZONTAL * BUFFOR_SCR_ROWS] ;
static lv_color_t buf_2[LCD_HORIZONTAL * BUFFOR_SCR_ROWS] ;
static lv_disp_drv_t disp_drv;

uint16_t touchX = 0, touchY = 0;
uint16_t oldTouchX = 0, oldTouchY = 0;


bool ETH_Connected = false, WiFi_Connected = false, MQTT_Connected = false;
char *WF_SSID, *WF_PASS;
char *MQTT_URL, *MQTT_USER, *MQTT_PASS;



static void STM_LOGSET(char *Buffer);


void Periph_Initialize(void){
	Result_Init(&res, OKE, __LINE__, __FUNCTION__, __FILE__);

	Power_Configuration(&pwr);
	FlashMem_Configuration(&flash);
	RCC_SystemClock_Init(&rcc);


	gettick_Init(RCC_GetTick);
	delay_ms_Init(RCC_Delay_ms);
	Peripheral_Status_Init(gettick);


	GPIO_CLOCKENABLE();
	GPIO_Init(GPIOC, 13, GPIO_OUTPUT_PUSHPULL);
	GPIO_Init(GPIOC,  6, GPIO_OUTPUT_PUSHPULL);
	GPIO_Set(GPIOC, 6);
	GPIO_Init(GPIOD, 12, GPIO_OUTPUT_PUSHPULL);
	GPIO_Set(GPIOD, 12);


	uart_log_TxDma -> Init(&uart_log_TxDma_conf);
	uart_log_TxDma -> Event_Register_Handler(DMA2_Stream7_TranferComplete_CallBack, NULL);
	uart_log -> Init(&uart_log_conf);
	uart_log -> Event_Register_Handler(USART1_Event_Callback, NULL);
	STM_LOG_Init(STM_LOGSET);
	STM_LOG(BOLD_GREEN, TAG, "STM LOG OKE");


	ESP32_API_Init(uart_log, GPIOC, 4, GPIOC, 5);
	uart_log -> ReceiveUntilIdleIT(300);
	while(esp_ok == false){
		GPIO_Set(GPIOC, 13);
		ESP32_Hardware_Reset();
		delay_ms(1000);
	}
	GPIO_Reset(GPIOC, 13);

	fls_spi_RxDma -> Init(&fls_spi_RxDma_conf);
	fls_spi_RxDma -> Event_Register_Handler(DMA2_Stream0_TranferComplete_CallBack, NULL);
	fls_spi.Init(&fls_spi_conf);
	uint32_t ID = spiflash.Init(&fls_spi);
	STM_LOG(BOLD_GREEN, TAG, "Flash Initialize finish, ID: 0x%06x.", ID);


	lora_spi.Init(&lora_spi_conf);
	if(lora.Init(&lora_spi, 433E6, 20, LORA_PRIORITY)) {
		STM_LOG(BOLD_GREEN, TAG, "Lora Initialize OKE.");
	}
	else STM_LOG(BOLD_RED, TAG, "Lora Initialize Failed.");
	lora.setSyncWord(0xDF);
	lora.Event_Register_Handler(NULL, LoRa_Receive_IRQHandler);
	lora.Receive(0);
	lora_req_tim -> Init(&lora_req_tim_conf);
	lora_req_tim -> Event_Register_Handler(LoRa_Request_TimerCallback, NULL);

	lora_resp_tim -> Init(&lora_resp_tim_conf);
	lora_resp_tim -> Event_Register_Handler(LoRa_Response_TimeOutHandler, NULL);
	LoRa_AP_Init(&lora, lora_resp_tim);


	i2c1.Init(&i2c1_conf);
	STM_LOG(BOLD_GREEN, TAG, "I2C1 Start scan.");
	for(uint8_t i=0; i<128; i++){
		res = i2c1.CheckDevices((uint16_t)(i<<1), 3, 5);
		if(CheckResult(res)){
			STM_LOG(BOLD_CYAN, TAG, "Finded devices at 0x%02x", i);
		}
	}
	STM_LOG(BOLD_YELLOW, TAG, "I2C1 End scan.");

	i2c2.Init(&i2c2_conf);
	STM_LOG(BOLD_GREEN, TAG, "I2C2 Start scan.");
	for(uint8_t i=0; i<128; i++){
		res = i2c2.CheckDevices((uint16_t)(i<<1), 3, 5);
		if(CheckResult(res)){
			STM_LOG(BOLD_CYAN, TAG, "Finded devices at 0x%02x", i);
		}
	}
	STM_LOG(BOLD_YELLOW, TAG, "I2C2 End scan.");

	DS3231_Init(&i2c1);
//	DS3231_SetTime(time);

	time_tim -> Init(&time_tim_conf);
	time_tim -> Event_Register_Handler(DS3231_TimerCallback, NULL);

	if(!TouchInit(&i2c2, 40)) STM_LOG(BOLD_RED, TAG, "Touch Init Fail.");

	TFT_Init(480, 320);
	TFT_SetOrientation(TFT_LandScape);
	TFT_FillRectangle(0, 0, 480, 320, BLUE);

	LVGL_Init();
	ui_init();
	init_lib();

	ESP32_WiFi_On("PASS", "23456789 ");
	delay_ms(2000);
	ESP32_MQTT_Config("mqtt://homethang.duckdns.org", "tutru20139", "20139");
	delay_ms(2000);
	ESP32_MQTT_Start();
	delay_ms(2000);

}

static void STM_LOGSET(char *Buffer){
	uart_log -> SendString(Buffer);
//	uart_log -> TransmitDMA((uint8_t *)Buffer, (uint16_t)strlen(Buffer));
//	while(!dma_uart_log_tx_flag);
//	dma_uart_log_tx_flag = 0;
}

void DMA2_Stream0_TranferComplete_CallBack(void *Paramemter, DMA_Event_t event){
	if(event == DMA_Event_Tranfer_Complete)
		dma_flash_rx_flag = 1;
}

void DMA2_Stream7_TranferComplete_CallBack(void *Paramemter, DMA_Event_t event){
	if(event == DMA_Event_Tranfer_Complete){
		dma_uart_log_tx_flag = 1;
		uart_log -> Stop_DMA();
	}
}

void USART1_Event_Callback(void *Parameter, USART_Event_t event){
	switch(event){
		case USART_Event_IdleDetected:{
			GPIO_Set(GPIOC, 13);

			uint8_t* uart_Rxbuf;
			uart_log -> GetBuffer(&uart_Rxbuf);
			RxFromEsp_Flag = true;

			if(strstr((const char *)uart_Rxbuf, "ESP OK") != NULL) {
				if(esp_ok == false) esp_ok = true;
				else{
					ESP32_Ethernet_On();
					delay_ms(1000);
					if(WiFi_Connected == true){
						WiFi_Connected = false;
						ESP32_WiFi_On(WF_SSID, WF_PASS);
						delay_ms(1000);
					}
					if(MQTT_Connected == true){
						MQTT_Connected = false;
						ESP32_MQTT_Stop();
						delay_ms(100);
						ESP32_MQTT_Config(MQTT_URL, MQTT_USER, MQTT_PASS);
						delay_ms(100);
						ESP32_MQTT_Start();
						delay_ms(100);
					}

				}
				RxFromEsp_Flag = false;
			}
			uart_log -> ReceiveUntilIdleIT(300);
			if(uart_Rxbuf != NULL){
				Packet_Uart_Queue.push(uart_Rxbuf);
			}

		}
		break;
		default:
		break;
	}
}

void EXTI_Callback(uint16_t Pin){
	switch(Pin){
		case 3:
			GPIO_Set(GPIOC, 13);
			lora.IRQHandler();

		break;
		default:
		break;
	}
}

void LoRa_Request_TimerCallback(void *Parameter, TIM_Event_t event){
	switch(event){
		case TIM_Update_Event:
			LoRa_ReqTimer_Flag = true;

		break;
		default:
		break;
	}
}

void DS3231_TimerCallback(void *Parameter, TIM_Event_t event){
	switch(event){
		case TIM_Update_Event:
			GetTime_Flag = true;
		break;
		default:
		break;
	}
}

void LVGL_Init(void){
	   lv_init();
	   lv_disp_draw_buf_init(&disp_buf, buf_1, buf_2, LCD_HORIZONTAL * BUFFOR_SCR_ROWS);
	   lv_disp_drv_init(&disp_drv);
	   disp_drv.draw_buf = &disp_buf;
	   disp_drv.flush_cb = LV_TFT_Driver;
	   disp_drv.hor_res = LCD_HORIZONTAL;
	   disp_drv.ver_res = LCD_VERTICAL;
	   lv_disp_drv_register(&disp_drv);

	   lv_indev_drv_init(&indev_drv);
	   indev_drv.type = LV_INDEV_TYPE_POINTER;
	   indev_drv.read_cb = lv_Touch_Driver;
	   lv_indev_drv_register(&indev_drv);

       lv_obj_t * cursor_obj = lv_obj_create(lv_scr_act());
       lv_obj_set_style_bg_color(cursor_obj, lv_palette_main(LV_PALETTE_RED), 0);
       lv_obj_set_style_radius(cursor_obj, LV_RADIUS_CIRCLE, 10);
       lv_obj_set_width(cursor_obj, 12);
       lv_obj_set_height(cursor_obj, 12);

}

void LV_TFT_Driver(lv_disp_drv_t * drv, const lv_area_t * area,  lv_color_t * color_map){
	TFT_SetWindow((uint16_t)area->x1, (uint16_t)area->y1, (uint16_t)area->x2, (uint16_t)area->y2);
	uint32_t size = (area->x2 - area->x1 +1) * (area->y2 - area->y1 +1);
	TFT_PushData((uint16_t *)color_map, size);
	lv_disp_flush_ready(drv);
}

void lv_Touch_Driver(lv_indev_drv_t * drv, lv_indev_data_t*data){
    if(Touched()){
    	GetPoint(0);
		data->state = LV_INDEV_STATE_PRESSED;
		touchX = GetX();
		touchY = GetY();
		data->point.x = 1.2*touchY - 50;
		data->point.y = -1*touchX + 310;
    }
    else{
    	data->state = LV_INDEV_STATE_RELEASED;
		data->point.x = 1.2*touchY - 50;
		data->point.y = -1*touchX + 310;
    }
}




