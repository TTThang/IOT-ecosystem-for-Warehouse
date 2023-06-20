/*
 * GetWay_API.h
 *
 *  Created on: Dec 17, 2022
 *      Author: anh
 */

#ifndef GETWAY_API_H_
#define GETWAY_API_H_

#include "stdio.h"
#include "stdbool.h"


#define CMD_WIFI_CONNECT 		"WIFI CONNECT"     // WIFI CONNECT: PASS, 03112002
#define CMD_WIFI_DISCONNECT 	"WIFI DISCONNECT"
#define CMD_WIFI_SCAN 			"WIFI SCAN"
#define CMD_WIFI_SETIP 			"WIFI SET IP"
#define CMD_WIFI_GETIP 			"WIFI GET IP"

#define CMD_ETH_CONNECT 		"ETH CONNECT"
#define CMD_ETH_DISCONNECT 		"ETH DISCONNECT"
#define CMD_ETH_SETIP 			"ETH SET IP"
#define CMD_ETH_GETIP 			"ETH GET IP"

#define CMD_NETWORK_STATE       "NETWORK"
#define CMD_MQTT_STATE          "MQTT"

#define CMD_MQTT_CONFIG         "MQTT CONFIG"       // MQTT CONFIG: mqtt://homethang.duckdns.org, tutru20139, 20139
#define CMD_MQTT_START          "MQTT START"        // MQTT START: *
#define CMD_MQTT_STOP           "MQTT STOP"

#define CMD_NEW_NODE            "NEW"
#define CMD_RELEASE_NODE        "RELEASE"
#define CMD_DATA                "DATA"
#define CMD_CONTROL             "CONTROL"

#define CMD_STM_LOG             "STM32_LOG"

#define DATA_NODATA   			"*"
#define DATA_RELAY1             "RELAY1"
#define DATA_RELAY2             "RELAY2"
#define DATA_RELAY3             "RELAY3"

#define DATA_ETH_CONNECTED      "ETH CONNECTED"
#define DATA_ETH_DISCONNECTED   "ETH DISCONNECTED"
#define DATA_WIFI_CONNECTED     "WIFI CONNECTED"
#define DATA_WIFI_DISCONNECTED  "WIFI DISCONNECTED"

#define DATA_MQTT_CONNECT       "MQTT CONNECTED"
#define DATA_MQTT_DISCONNECT    "MQTT DISCONNECTED"

typedef enum{
	Command_Unknown,

	Command_Stm_Log,

	Command_WiFi_Scan,
	Command_WiFi_Connect,
	Command_WiFi_Disconnect,
	Command_WiFi_SetIP,
	Command_WiFi_GetIP,

	Command_Eth_Connect,
	Command_Eth_Disconnect,
	Command_Eth_SetIP,
	Command_Eth_GetIP,

	Command_MQTT_Config,
	Command_MQTT_Start,
	Command_MQTT_Stop,

	Command_New_Node,
	Command_Release_Node,
	Command_Data,
	Command_Control,

	Command_NetWork_State,
	Command_MQTT_State,


} API_Command_t;

typedef enum{
	Packet_Error,
	Packet_OK,
} Packet_State_t;

typedef struct{
	char *fullpacket;
	Packet_State_t state;
	char *cmd;
	char *data;
	API_Command_t command;
} Packet_t;

uint8_t FindChar(char *str, char ch);

Packet_t Parse_Packet(char *packet);
void Free_Packet(Packet_t *packet);

char *GetCommand(Packet_t *packet);
char *GetFullData(Packet_t *packet);
char *GetData(char *data, uint8_t num_of_data, char brch);

bool Command_with_noData(Packet_t *packet);

#endif /* GETWAY_API_H_ */
