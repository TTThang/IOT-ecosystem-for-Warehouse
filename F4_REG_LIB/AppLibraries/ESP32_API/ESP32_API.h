/*
 * ESP32_API.h
 *
 *  Created on: Dec 13, 2022
 *      Author: anh
 */

#ifndef ESP32_API_H_
#define ESP32_API_H_

#include "stm32f4xx.h"
#include "USART_F4xx.h"
#include "GPIO_F4xx.h"
#include "RCC_F4xx.h"
#include "GateWay_API.h"


// PC4-PC5
void ESP32_SendCommand(const char *cmd, const char *format, ...);

void ESP32_API_Init(USART *usart, GPIO_TypeDef *rst1_port, uint16_t rst1_pin, GPIO_TypeDef *rst2_port, uint16_t rst2_pin);
void ESP32_Hardware_Reset(void);

void ESP32_WiFi_On(char *SSID, char *PASS);
void ESP32_WiFi_Off(void);
void ESP32_WiFi_Scan(void);
void ESP32_Ethernet_On(void);
void ESP32_Ethernet_Off(void);

void ESP32_MQTT_Config(char *URL, char *USER, char *PASS);
void ESP32_MQTT_Start(void);
void ESP32_MQTT_Stop(void);

void ESP32_SendEnvData(char *Data);



#endif /* ESP32_API_H_ */
