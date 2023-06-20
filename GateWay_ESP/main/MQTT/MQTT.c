/*
 * MQTT.c
 *
 *  Created on: Dec 19, 2022
 *      Author: anh
 */

#include "esp_event.h"
#include "mqtt_client.h"
#include "driver/gpio.h"
#include "hal/gpio_types.h"

#include "MQTT.h"
#include "UART.h"

#define MAX_NUM_NODE 3


static const char* MQTT = "MQTT_GATEWAY";

bool Node_Id[MAX_NUM_NODE+1] = {};
QueueHandle_t MQTT_Data_Queue_Handle = 0;
esp_mqtt_client_handle_t Client;
esp_mqtt_client_config_t mqtt_cfg = {0};

static void delay(int msec) {
    vTaskDelay(msec / portTICK_PERIOD_MS);
}

bool InitWarehouse(char* index){
	int msg_id;
	char *topic;
	if(1){
		asprintf(&topic, "Warehouse/%s/available", index);
		ESP_LOGE(MQTT,"topic: %s",topic);
		msg_id = esp_mqtt_client_publish(Client, topic,"online", 0, 0, 0);
		delay(10);
		asprintf(&topic, "Warehouse/%s,RELAY1", index);
		msg_id = esp_mqtt_client_subscribe(Client, topic, 0);
	    ESP_LOGI(MQTT, "Sent subscribe to topic: %s successful, msg_id=%d", topic, msg_id);
	    delay(10);
	    asprintf(&topic, "Warehouse/%s,RELAY2", index);
		msg_id = esp_mqtt_client_subscribe(Client, topic, 0);
	    ESP_LOGI(MQTT, "Sent subscribe to topic: %s successful, msg_id=%d", topic, msg_id);
	    delay(10);
	    asprintf(&topic, "Warehouse/%s,RELAY3", index);
		msg_id = esp_mqtt_client_subscribe(Client, topic, 0);
	    ESP_LOGI(MQTT, "Sent subscribe to topic: %s successful, msg_id=%d", topic, msg_id);
	    free(topic);
	    return 1;
	}
	return 0;

}
bool DenitWarehouse(char* index){
	int msg_id;
	char *topic;
	if(1){
		asprintf(&topic, "Warehouse/%s/available", index);
		ESP_LOGE(MQTT,"topic: %s",topic);
		msg_id = esp_mqtt_client_publish(Client, topic,"offline", 0, 0, 0);
		ESP_LOGI(MQTT, "Sent offline to topic: %s successful, msg_id=%d", topic, msg_id);
		delay(10);
		asprintf(&topic, "Warehouse/%s,RELAY1", index);
		msg_id = esp_mqtt_client_unsubscribe(Client, topic);
	    ESP_LOGI(MQTT, "Sent unsubscribe to topic: %s successful, msg_id=%d", topic, msg_id);
	    delay(10);
	    asprintf(&topic, "Warehouse/%s,RELAY2", index);
		msg_id = esp_mqtt_client_unsubscribe(Client, topic);
	    ESP_LOGI(MQTT, "Sent unsubscribe to topic: %s successful, msg_id=%d", topic, msg_id);
	    delay(10);
	    asprintf(&topic, "Warehouse/%s,RELAY3", index);
		msg_id = esp_mqtt_client_unsubscribe(Client, topic);
	    ESP_LOGI(MQTT, "Sent unsubscribe to topic: %s successful, msg_id=%d", topic, msg_id);
	    free(topic);
	    return 1;
	}
	return 0;

}
//Degub error
void log_error_if_nonzero(const char *message, int error_code){
	if(error_code != 0){
		ESP_LOGE(MQTT, "Last error %s: 0x%x", message, error_code);
	}
}
//Function handle mqtt event
void mqtt_event_handler(void *handler_args, esp_event_base_t base, int32_t event_id, void *event_data){
//	ESP_LOGE(MQTT, "Event dispatched from event loop base = %s, event_id = %lu", base, event_id);
	esp_mqtt_event_handle_t event = (esp_mqtt_event_handle_t)event_data;
	esp_mqtt_client_handle_t client = event->client;
	Client = client;
	char* data;
	switch ((esp_mqtt_event_id_t)event_id){
		case MQTT_EVENT_CONNECTED:
			ESP_LOGI(MQTT, "MQTT_EVENT_CONNECTED");
			STM_sendData(MQTT, "MQTT: MQTT CONNECTED");
			for(int i = 1; i <= MAX_NUM_NODE; i++){
				if(Node_Id[i] != 0){
					char* ID;
					asprintf(&ID,"%d",i);
					InitWarehouse(ID);
					free(ID);
				}
			}
			break;
		case MQTT_EVENT_DISCONNECTED:
	        ESP_LOGI(MQTT, "MQTT_EVENT_DISCONNECTED");
	        STM_sendData(MQTT, "MQTT: MQTT DISCONNECTED");
	        break;
	    case MQTT_EVENT_UNSUBSCRIBED:
	        ESP_LOGI(MQTT, "MQTT_EVENT_UNSUBSCRIBED, msg_id=%d", event->msg_id);
	        break;
	    case MQTT_EVENT_PUBLISHED:
	        ESP_LOGI(MQTT, "MQTT_EVENT_PUBLISHED, msg_id=%d", event->msg_id);
	        break;
	    case MQTT_EVENT_DATA:
	        data = (char*)malloc((event->topic_len + 1 + event->data_len + 1 - 1) * sizeof(char)); //"CONTROL: 1,RELAY2,ON"
	        memcpy(data,"CONTROL: ",9);
	        memcpy(data+9,event->topic+10,event->topic_len-10);
	        data[event->topic_len-1] = ',';
	        memcpy(&data[event->topic_len+1-1],event->data,event->data_len);
	        data[event->topic_len + 1 + event->data_len - 1] = '\0';
            if(!xQueueSend(MQTT_Data_Queue_Handle, &data, 10)){
            	ESP_LOGI(MQTT, "Failed to send data to Queue!!!");
            	free(data);
            	//Process deny control when queue full.
            }
	        break;
	    case MQTT_EVENT_ERROR:
	        ESP_LOGI(MQTT, "MQTT_EVENT_ERROR");
	        if (event->error_handle->error_type == MQTT_ERROR_TYPE_TCP_TRANSPORT) {
	            log_error_if_nonzero("reported from esp-tls", event->error_handle->esp_tls_last_esp_err);
	            log_error_if_nonzero("reported from tls stack", event->error_handle->esp_tls_stack_err);
	            log_error_if_nonzero("captured as transport's socket errno",  event->error_handle->esp_transport_sock_errno);
	            ESP_LOGI(MQTT, "Last errno string (%s)", strerror(event->error_handle->esp_transport_sock_errno));

	        }
	        break;
    	default:
	        ESP_LOGI(MQTT, "Other event id:%d", event->event_id);
		break;
	}
}
void mqtt_start(void *arg){
    mqtt_cfg.session.keepalive = 60;

    esp_mqtt_client_handle_t client = esp_mqtt_client_init(&mqtt_cfg);
    esp_mqtt_client_register_event(client, (esp_mqtt_event_id_t)ESP_EVENT_ANY_ID, mqtt_event_handler, NULL);
    esp_mqtt_client_start(client);
}

bool publish_data_sensor(char* id, char* temp, char* humi){
	char* topic;
	char* data;
    asprintf(&topic,"Warehouse/%s/sensor", id);
    asprintf(&data,"{\"temperature\": %s,\"humidity\": %s}", temp, humi);
//    ESP_LOGE(MQTT,"%s %s",topic,data);
    if(esp_mqtt_client_publish(Client, topic, data, 0, 1, 0) != 0){
    	free(topic);
    	free(data);
    	return 1;
    }
    free(topic);
    free(data);
    return 0;
}
bool publish_data_switch(char* id, char* device, char* payload){
	char* topic;
    asprintf(&topic,"Warehouse/%s,%s", id,device);
//    ESP_LOGE(MQTT,"%s %s",topic,payload);
    if(esp_mqtt_client_publish(Client, topic, payload, 0, 0, 0) != 0){
    	free(topic);
    	return 1;
    }
    free(topic);
    return 0;
}
void mqtt_stop(void *arg){
	esp_mqtt_client_stop(Client);
	esp_mqtt_client_disconnect(Client);
	esp_mqtt_client_destroy(Client);
	vTaskDelete(NULL);
}


