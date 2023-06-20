/*
 * LoRa_API.cpp
 *
 *  Created on: Dec 14, 2022
 *      Author: anh
 */
#include "LoRa_API.h"
#include "TIM_F4xx.h"
#include "STM_LOG.h"
#include "ESP32_API.h"
#include "lib_out.h"

static LoRa *_lora;
static TIM  *_tim;

static const char * TAG = "STM32_LOG";


bool LoRa_Resp_Flag = false;
std::queue<char*> Packet_Lora_Queue;
extern std::queue<char*> Control_list [LORA_NUM_NODE+1][4];
extern int Count_Control;
//Packet_t LoRa_Resp_Packet;

bool Response_State[LORA_NUM_NODE + 1] = {false};
uint8_t Counter_timeout[LORA_NUM_NODE+1] = {};
uint32_t Node_ID[LORA_NUM_NODE+1] = {0};
char Init_id[3];
uint32_t Timing_init_node = 0;
extern int Count_Node;

bool LoRa_Response_TimeOut_Flag = false;


void LoRa_AP_Init(LoRa *lora, TIM *timer){
	_lora = lora;
	_tim = timer;
}



void LoRa_SendCommand(const char *command, const char *fomat, ...){
	char *Temp_buffer = NULL;
	va_list args;
	va_start(args, fomat);

	uint16_t length = vsnprintf(Temp_buffer, 0, fomat, args);
	Temp_buffer = (char *)malloc(length * sizeof(char));
	vsprintf(Temp_buffer, fomat, args);
	va_end(args);

	char *Out_buffer = (char *)malloc((strlen(command) + 2 + length)*sizeof(char));
	sprintf(Out_buffer, "%s: %s", command, Temp_buffer);

	_lora -> setSyncWord(0xFF);
	_lora -> beginPacket();
	_lora -> write((uint8_t*)Out_buffer, (size_t)strlen(Out_buffer) );
	_lora -> endPacket();
	_lora -> setSyncWord(0xDF);
	_lora -> Receive(0);

	free(Out_buffer);
	free(Temp_buffer);
}

void LoRaTransmit(const char *fomat, ...){
	char *Temp_buffer = NULL;
	va_list args;
	va_start(args, fomat);

	uint16_t length = vsnprintf(Temp_buffer, 0, fomat, args);
	Temp_buffer = (char *)malloc(length * sizeof(char));
	vsprintf(Temp_buffer, fomat, args);
	va_end(args);

	_lora -> setSyncWord(0xFF);
	_lora -> beginPacket();
	_lora -> write((uint8_t*)Temp_buffer, (size_t)strlen(Temp_buffer) );
	_lora -> endPacket();
	_lora -> setSyncWord(0xDF);
	_lora -> Receive(0);

	free(Temp_buffer);
}

void Init_Node(void){
	for(int i=1; i<=LORA_NUM_NODE; i++){
		if(Node_ID[i]==0){
			LoRaTransmit("%d", i);
			Timing_init_node = gettick();
			sprintf(Init_id, "%d", i);
			return;
		}
	}
}

void LoRa_RequestData(void){
	memset(Response_State, false, sizeof(Response_State));
	LoRa_SendCommand(CMD_DATA, DATA_NODATA);
	_tim -> ResetCounter();
}


void LoRa_Check_Lost_Data(void){
	for(int i=1; i <= LORA_NUM_NODE; i++){
		if(Node_ID[i] != 0){
			if(Response_State[i] == false){
				if(Counter_timeout[i] <= MAX_TIME_OUT){
					Counter_timeout[i]++;
				}
				else{
					Node_ID[i] = 0;
					ESP32_SendCommand(CMD_RELEASE_NODE, "%d", i);
					for(int index_relay=1; index_relay<=3; index_relay++){
						while(!Control_list[i][index_relay].empty()){
							if(Control_list[i][index_relay].front() != NULL){
								free(Control_list[i][index_relay].front());
							}
							Control_list[i][index_relay].pop();
							Count_Control--;
						}
					}
					Counter_timeout[i] = 0;
					Count_Node--;
				}
			}
		}
	}
}


void LoRa_Receive_IRQHandler(void *arg, uint8_t len){
	GPIO_Set(GPIOC, 13);
	LoRa *lr = (LoRa *)arg;
	uint8_t packetSize = len;
	if(packetSize){
		char *lora_RxBuf;
		lora_RxBuf = (char *)malloc(packetSize+1);
		for (int i = 0; i < packetSize; i++) lora_RxBuf[i] = lr -> read();
		lora_RxBuf[packetSize] = '\0';
		if(lora_RxBuf != NULL){
			Packet_Lora_Queue.push(lora_RxBuf);
		}
//		LoRa_Resp_Packet = Parse_Packet(lora_RxBuf);
//		LoRa_Resp_Flag = true;

		STM_LOG(BOLD_YELLOW, TAG, "Node response: %s", lora_RxBuf);


//		free(lora_RxBuf);
	}
}

void LoRa_Response_TimeOutHandler(void *Parameter, TIM_Event_t event){
	switch(event){
		case TIM_Update_Event:
			LoRa_Response_TimeOut_Flag = true;

		break;
		default:
		break;
	}
}




