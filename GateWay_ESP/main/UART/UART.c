/*
 * UART.c
 *
 *  Created on: Dec 19, 2022
 *      Author: anh
 */


#include "UART.h"



static const char *TAG = "UART";

#define BUF_SIZE (1024)

QueueHandle_t UART_Data_Queue_Handle;

static uart_port_t stm_port;
static uart_port_t log_port;

static QueueHandle_t stm_uart_queue;
static QueueHandle_t log_uart_queue;

void STM_UART_Task(void *param){
    uart_event_t event;

    while(1) {
        if(xQueueReceive(stm_uart_queue, (void * )&event, portMAX_DELAY)) {
            switch(event.type) {
                case UART_DATA:
                	uint8_t* dtmp = (uint8_t*) malloc(event.size + 1);
                    uart_read_bytes(stm_port, dtmp, event.size, portMAX_DELAY);
                    dtmp[event.size] = '\0';
                    char* tmp;
                    asprintf(&tmp, "%s", dtmp);
                    if(!xQueueSend(UART_Data_Queue_Handle, &tmp, 10)){
                        ESP_LOGI(TAG, "Failed to send data to Queue!!!");
                        free(tmp);
                    }
				break;

                case UART_BREAK:
                    ESP_LOGI(TAG, "uart rx break");
				break;

                default:
                    ESP_LOGI(TAG, "uart event type: %d", event.type);
				break;
            }
        }
    }
    vTaskDelete(NULL);
}
void STM_UART_Init(uart_port_t port, int TxPin, int RxPin){
	stm_port = port;

	uart_config_t uart_config = {
        .baud_rate = 115200,
        .data_bits = UART_DATA_8_BITS,
        .parity = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
        .source_clk = UART_SCLK_APB,
    };

    uart_driver_install(stm_port, BUF_SIZE * 2, BUF_SIZE * 2, 20, &stm_uart_queue, 0);
    uart_param_config(stm_port, &uart_config);
    uart_set_pin(stm_port, TxPin, RxPin, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);

    vTaskDelay(10);
    uart_write_bytes(stm_port, (const char*)"ESP OKE", 7);

    UART_Data_Queue_Handle = xQueueCreate(30, sizeof(char*));
}

void LOG_UART_Init(uart_port_t port, int TxPin, int RxPin){
	log_port = port;

	uart_config_t uart_config = {
        .baud_rate = 115200,
        .data_bits = UART_DATA_8_BITS,
        .parity = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
        .source_clk = UART_SCLK_APB,
    };

    uart_driver_install(log_port, BUF_SIZE * 2, BUF_SIZE * 2, 20, &log_uart_queue, 0);
    uart_param_config(log_port, &uart_config);
    uart_set_pin(log_port, TxPin, RxPin, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);
}


int STM_sendData(const char* logName, const char* data){
    const int len = strlen(data);
    const int txBytes = uart_write_bytes(stm_port, data, len);
    ESP_LOGI(logName, "Wrote %d bytes", txBytes);
    return txBytes;
}

void STM_LOG(char *log){
	uart_write_bytes(log_port, log, strlen(log));
}










