/*
 * GetWay_API.c
 *
 *  Created on: Dec 17, 2022
 *      Author: anh
 */

#include "GateWay_API.h"
#include "string.h"
#include "stdlib.h"
#include "stdio.h"



Packet_t Parse_Packet(char *packet){
	Packet_t pkt;
	pkt.state = Packet_OK;
	pkt.command = Command_Unknown;
	pkt.fullpacket = packet;
	pkt.cmd  = GetCommand(&pkt);
	pkt.data = GetFullData(&pkt);

	if(pkt.cmd == NULL || pkt.data == NULL) pkt.state = Packet_Error;

	if	   (strcmp(pkt.cmd, CMD_WIFI_SCAN) == 0)
		pkt.command = Command_WiFi_Scan;

	else if(strcmp(pkt.cmd, CMD_WIFI_CONNECT) == 0)
		pkt.command = Command_WiFi_Connect;

	else if(strcmp(pkt.cmd, CMD_WIFI_DISCONNECT) == 0)
		pkt.command = Command_WiFi_Disconnect;

	else if(strcmp(pkt.cmd, CMD_WIFI_SETIP) == 0)
		pkt.command = Command_WiFi_SetIP;

	else if(strcmp(pkt.cmd, CMD_WIFI_GETIP) == 0)
		pkt.command = Command_WiFi_GetIP;

	else if(strcmp(pkt.cmd, CMD_ETH_CONNECT) == 0)
		pkt.command = Command_Eth_Connect;

	else if(strcmp(pkt.cmd, CMD_ETH_DISCONNECT) == 0)
		pkt.command = Command_Eth_Disconnect;

	else if(strcmp(pkt.cmd, CMD_ETH_SETIP) == 0)
		pkt.command = Command_Eth_SetIP;

	else if(strcmp(pkt.cmd, CMD_ETH_GETIP) == 0)
		pkt.command = Command_Eth_GetIP;

	else if(strcmp(pkt.cmd, CMD_MQTT_CONFIG) == 0)
		pkt.command = Command_MQTT_Config;

	else if(strcmp(pkt.cmd, CMD_MQTT_START) == 0)
		pkt.command = Command_MQTT_Start;

	else if(strcmp(pkt.cmd, CMD_MQTT_STOP) == 0)
		pkt.command = Command_MQTT_Stop;

	else if(strcmp(pkt.cmd, CMD_NEW_NODE) == 0)
		pkt.command = Command_New_Node;

	else if(strcmp(pkt.cmd, CMD_RELEASE_NODE) == 0)
		pkt.command = Command_Release_Node;

	else if(strcmp(pkt.cmd, CMD_DATA) == 0)
		pkt.command = Command_Data;

	else if(strcmp(pkt.cmd, CMD_CONTROL) == 0)
		pkt.command = Command_Control;

	else if(strcmp(pkt.cmd, CMD_NETWORK_STATE) == 0)
		pkt.command = Command_NetWork_State;


	else if(strcmp(pkt.cmd, CMD_MQTT_STATE) == 0)
		pkt.command = Command_MQTT_State;

	else if(strstr(pkt.cmd, CMD_STM_LOG) == 0)
		pkt.command = Command_Stm_Log;

	else
		pkt.command = Command_Unknown;


	return pkt;
}

void Free_Packet(Packet_t *packet){
	if(packet -> fullpacket != NULL) free(packet -> fullpacket);
	if(packet -> cmd != NULL) 		 free(packet -> cmd);
	if(packet -> data != NULL) 		 free(packet -> data);
}

uint8_t FindChar(char *str, char ch){
	char *chptr = strchr(str, ch);
	if(chptr == NULL) return -1;
	return (int)(chptr - str);
}

char *GetCommand(Packet_t *packet){
	uint8_t index = FindChar(packet -> fullpacket, ':');
    if(index > 0){
    	char *cmd = (char *)malloc(index + 1);
    	strncpy(cmd, packet -> fullpacket, index);
    	cmd[index] = '\0';
    	return cmd;
    }
    return NULL;
}

char *GetFullData(Packet_t *packet){
	uint8_t index = FindChar(packet -> fullpacket, ':') + 2; //= 5
    if(index > 0){
    	uint8_t datalen = strlen(packet -> fullpacket) - index;
    	char *tmp = (char *)malloc(datalen+1);
    	for(uint8_t i = index; i<(strlen(packet -> fullpacket)); i++) tmp[i - index] = packet -> fullpacket[i];
    	tmp[datalen] = '\0';
    	return tmp;
    }
    return NULL;
}

char *GetData(char *data, uint8_t num_of_data, char brch){
	uint8_t index = 0, cmpchr = 0;

	if(num_of_data == 0) goto data0;
	for(index=0; index<strlen(data); index++){
		if(data[index] == brch) {
			cmpchr++;
			if(cmpchr == num_of_data) goto indexOK;
		}
	}
	return NULL;

	indexOK:
	index += 1;
	data0:
	char *dataptr = (char *)(data + index);
	if(dataptr[0] == ' ') {
		dataptr += 1;
		index += 1;
	}

	int olength = FindChar(dataptr, ',');
	if(olength < 0) olength = strlen(data) - index;

	char *buffer = (char *)malloc(olength + 1);
	memcpy(buffer, dataptr, olength);
	buffer[olength] = '\0';

	return buffer;
}

bool Command_with_noData(Packet_t *packet){
	if(!strcmp(packet->data, DATA_NODATA)) return true;
	return false;

}



