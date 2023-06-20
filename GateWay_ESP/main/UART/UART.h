

#ifndef UART_H_
#define UART_H_

#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
	
#include "driver/uart.h"
#include "esp_log.h"
#include "driver/gpio.h"

#ifdef __cplusplus
extern "C" {
#endif

extern QueueHandle_t UART_Data_Queue_Handle;

void STM_UART_Init(uart_port_t port, int TxPin, int RxPin);
void LOG_UART_Init(uart_port_t port, int TxPin, int RxPin);

void STM_UART_Task(void *param);

int STM_sendData(const char* logName, const char* data);
void STM_LOG(char *log);

#ifdef __cplusplus
}
#endif

#endif /* UART_H_ */
