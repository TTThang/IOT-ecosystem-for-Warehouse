#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdarg.h>
#include "esp_log.h"

#include "string.h"
#include "esp_wifi.h"
#include "esp_system.h"
#include "nvs_flash.h"
#include "esp_netif.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/semphr.h"
#include "freertos/queue.h"

#include "driver/gpio.h"

#include "GateWay_API.h"
#include "Ethernet.h"
#include "MQTT.h"
#include "WiFi.h"
#include "UART.h"

static const char* TAG = "GATEWAY";

void Connect_WiFi(char *buf);
void checkQueue_MQTT(void *arg);
void checkQueue_UART(void* arg);


void app_main(){
	STM_UART_Init(UART_NUM_2, GPIO_NUM_17, GPIO_NUM_16);
	LOG_UART_Init(UART_NUM_0, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);

	ESP_ERROR_CHECK(nvs_flash_init());
	ESP_ERROR_CHECK(esp_netif_init());
	ESP_ERROR_CHECK(esp_event_loop_create_default());


	MQTT_Data_Queue_Handle = xQueueCreate(21,sizeof(char*));

	xTaskCreatePinnedToCore(&checkQueue_MQTT,"mqtt_event", 2048,NULL,0,NULL,0);
	xTaskCreatePinnedToCore(&STM_UART_Task,  "UART Event", 2048, NULL, 9, NULL,1);
	xTaskCreatePinnedToCore(&checkQueue_UART, "Queue UART", 9000, NULL, 1, NULL,1);
}


void checkQueue_MQTT(void *arg){
	char* rx_mqtt;
	while(true){
		if(xQueueReceive(MQTT_Data_Queue_Handle,&rx_mqtt, 10)){
			while(STM_sendData(TAG, rx_mqtt) == -1){
				ESP_LOGE(TAG,"Error to send to STM");
				vTaskDelay(1);
			}
//			ESP_LOGI(TAG,"Sended uart: %s", rx_mqtt);
			free(rx_mqtt);
		}
		vTaskDelay(500/portTICK_PERIOD_MS);
	}
}

void Connect_WiFi(char *buf){
	int index = FindChar(buf, ',');
    if(index > 0){
    	char *SSID = GetData(buf, 0, ',');
    	char *PASS = GetData(buf, 1, ',');
    	if(SSID == NULL || PASS == NULL){
    		ESP_LOGE(TAG, "INCORRECT SSID OR PASSWORD");
    		return;
    	}

    	ESP_LOGI(TAG, "SSID len: %d, PASS len: %d", strlen(SSID), strlen(PASS));

		while(WiFi_GetState() == WIFI_CONNECT_FAILED){
			WiFi_STA_Connect((char *)SSID, (char *)PASS, WIFI_AUTH_WPA2_PSK);
		};
		char *sta_ip = LocalIP();
		ESP_LOGW("STATION IP", "%s", sta_ip);
		free(sta_ip);

		free(SSID);
		free(PASS);
    }
}

void checkQueue_UART(void* arg){
 	char* rx_uart;
 	while(true){
 		if(xQueueReceive(UART_Data_Queue_Handle, &rx_uart, 10)){
// 			ESP_LOGI(TAG, "UART receive: %s", rx_uart);
			Packet_t packet = Parse_Packet(rx_uart);
			if(packet.state == Packet_Error) {
				ESP_LOGE(TAG, "PACKET FROM STM ERROR!!!!!!!!!!!!!!!!!!!!!");
				Free_Packet(&packet);
				continue;
			}
//			ESP_LOGI("CMD ", "%s, length: %d", packet.cmd, strlen(packet.cmd));
//			ESP_LOGI("DATA", "%s, length: %d", packet.data, strlen(packet.data));

			switch(packet.command){
				case Command_Unknown:{

				}
				break;

				case Command_Stm_Log:{
					STM_LOG(rx_uart);
				}
				break;

				case Command_WiFi_Scan:{
					if(Command_with_noData(&packet)){
						uint8_t num_wifi = WiFi_STA_Scan();
						ESP_LOGI(TAG, "Find %d Access point.", num_wifi);

						uint16_t total_len = 0;
						uint16_t final_num_wifi = num_wifi;
						for(uint8_t i=0; i<num_wifi; i++){
							char *SCAN_SSID = WiFi_STA_Scan_Get_SSID(i);
							total_len += strlen(SCAN_SSID);
							if(strlen(SCAN_SSID) == 0) final_num_wifi--;
							free(SCAN_SSID);
						}

						total_len -= 5;
						ESP_LOGI("SSID TOTAL LENGTH", "%d", total_len);
						char *SSID = (char *)malloc(total_len * sizeof(char) + 25);
						memset(SSID, '\0', total_len + 25);
						memcpy(SSID, CMD_WIFI_SCAN, strlen(CMD_WIFI_SCAN));
						char len_str[9];
						sprintf(len_str, ": %02d,", final_num_wifi);
						strcat(SSID, len_str);

						for(uint8_t i=0; i<final_num_wifi; i++){
							char *ssidi = WiFi_STA_Scan_Get_SSID(i);
							strcat(SSID, ssidi);
							strcat(SSID, ",");
							vTaskDelay(2/portTICK_PERIOD_MS);
						}
						STM_sendData(TAG, SSID);
					} else ESP_LOGE(TAG, "COMMAND ERROR");
				}
				break;

				case Command_WiFi_Connect:{
					if(!Command_with_noData(&packet)){
						Connect_WiFi(packet.data);
						ESP_LOGI(TAG, "WiFi Connected.");
					} else ESP_LOGE(TAG, "COMMAND ERROR");
				}
				break;

				case Command_WiFi_Disconnect:{
					if(Command_with_noData(&packet)){
						WiFi_STA_Disconnect();
						ESP_LOGI(TAG, "WiFi Disconnected.");
					} else ESP_LOGE(TAG, "COMMAND ERROR");
				}
				break;
/*
				case Command_WiFi_SetIP:{
					char *IPADDR  = GetData(packet.data, 0, ',');
					char *NETMASK = GetData(packet.data, 1, ',');
					char *GETWAY  = GetData(packet.data, 2, ',');
					if(!Command_with_noData(&packet)){
						if(IPADDR != NULL && NETMASK != NULL && GETWAY != NULL){
							WiFi_STA_Set_IPV4(IPADDR, NETMASK, GETWAY);
							free(IPADDR);
							free(NETMASK);
							free(GETWAY);

							ESP_LOGI(TAG, "WiFi Changed IP");
							char *sta_ip = LocalIP();
							ESP_LOGI("STATION IP", "%s", sta_ip);
							free(sta_ip);
						} else ESP_LOGE(TAG, "COMMAND ERROR");
					} else ESP_LOGE(TAG, "COMMAND ERROR");
				}
				break;

				case Command_WiFi_GetIP:{
					if(Command_with_noData(&packet)){
						char *sta_ip = LocalIP();
						ESP_LOGI("STATION IP", "%s", sta_ip);
						free(sta_ip);
					} else ESP_LOGE(TAG, "COMMAND ERROR");
				}
				break;
*/
				case Command_Eth_Connect:
					 if(Command_with_noData(&packet)){
					 	ETH_Init();
					 	ESP_LOGI(TAG, "ETHERNET CONNECT.");
					 } else ESP_LOGE(TAG, "COMMAND ERROR");
				break;

				case Command_Eth_Disconnect:
					 if(Command_with_noData(&packet)){
					 	ETH_DeInit();
					 	ESP_LOGI(TAG, "ETHERNET DISCONNECT.");
					 } else ESP_LOGE(TAG, "COMMAND ERROR");

				break;
/*
				case Command_Eth_SetIP:
					 ESP_LOGI(TAG, "ETHERNET SET IP.");
				break;

				case Command_Eth_GetIP:
					 ESP_LOGI(TAG, "ETHERNET GET IP.");
				break;
*/
				case Command_MQTT_Config:{
					char *URL       = GetData(packet.data, 0, ',');
					char *USERNAME  = GetData(packet.data, 1, ',');
					char *PASSWORD  = GetData(packet.data, 2, ',');
					if(!Command_with_noData(&packet)){
						if(URL != NULL && USERNAME != NULL && PASSWORD != NULL){
							ESP_LOGI(TAG, "MQTT SERVER CONFIG:");

							ESP_LOGI(TAG, "SERVER URL: %s", URL);
							mqtt_cfg.broker.address.uri = URL;

							ESP_LOGI(TAG, "USAERNAME:  %s", USERNAME);
							mqtt_cfg.credentials.username = USERNAME;

							ESP_LOGI(TAG, "PASSWORD:   %s", PASSWORD);
							mqtt_cfg.credentials.authentication.password = PASSWORD;

						} else ESP_LOGE(TAG, "COMMAND ERROR");
					} else ESP_LOGE(TAG, "COMMAND ERROR");
				}
				break;

				case Command_MQTT_Start:{
					mqtt_start();
					ESP_LOGI(TAG, "MQTT START.");
				}
				break;

				case Command_MQTT_Stop:{
					if(Command_with_noData(&packet)){
						mqtt_stop();
						// mqtt_stop();
						ESP_LOGI(TAG, "MQTT STOP.");
					} else ESP_LOGE(TAG, "COMMAND ERROR");
				}
				break;

				case Command_New_Node:{
					ESP_LOGI(TAG, "NEW NODE.");
					char *newnode = GetData(packet.data, 0, ',');
					Node_Id[atoi(newnode)] = 1;
					InitWarehouse(newnode);
					ESP_LOGI(TAG, "ADD NEW NODE WITH ID %s", newnode);
					free(newnode);
				}
				break;

				case Command_Release_Node:{
					ESP_LOGI(TAG, "RELEASE NODE.");
					char *releasenode = GetData(packet.data, 0, ',');
					Node_Id[atoi(releasenode)] = 0;
					DenitWarehouse(releasenode);
					ESP_LOGI(TAG, "RELEASE NODE ID %s", releasenode);
					free(releasenode);
				}
				break;

				case Command_Data:{
					char *device_id   = GetData(packet.data, 0, ',');
					char *device_temp = GetData(packet.data, 1, ',');
					char *device_humi = GetData(packet.data, 2, ',');

					for(int i = 0; i < 3; i++){
						if(publish_data_sensor(device_id, device_temp, device_humi)){
							break;
						}
						if(i == 2){
							ESP_LOGE(TAG,"Failed to publish data to server!!!");
						}
					}
					free(device_id);
					free(device_temp);
					free(device_humi);
				}
				break;

				case Command_Control:{
					char *device_id     = GetData(packet.data, 0, ',');
					char *device_rl     = GetData(packet.data, 1, ',');
					char *device_rl_stt = GetData(packet.data, 2, ',');
					ESP_LOGE(TAG, "CONTROL device %s %s %s", device_id, device_rl, device_rl_stt);

					for(int i = 0; i < 3; i++){
						if(publish_data_switch(device_id, device_rl, device_rl_stt)) break;
						if(i == 2) ESP_LOGE(TAG, "Failed to publish data to server!!!");
					}

					free(device_id);
					free(device_rl);
					free(device_rl_stt);
				}
				break;

				case Command_NetWork_State:
				break;

				case Command_MQTT_State:
				break;

			}
			Free_Packet(&packet);
 		}
 		vTaskDelay(1);
 	}
}
