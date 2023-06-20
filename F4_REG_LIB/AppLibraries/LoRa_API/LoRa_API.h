/*
 * LoRa_API.h
 *
 *  Created on: Dec 14, 2022
 *      Author: anh
 */

#ifndef LORA_API_H_
#define LORA_API_H_


#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "LORA.h"
#include "TIM_F4xx.h"
#include "queue"

#include "GateWay_API.h"


#define LORA_NUM_NODE           2
#define MAX_TIME_OUT            3


extern std::queue<char*> Packet_Lora_Queue;
extern bool LoRa_Resp_Flag;
//extern Packet_t LoRa_Resp_Packet;

extern bool Response_State[LORA_NUM_NODE + 1];
extern uint8_t Counter_timeout[LORA_NUM_NODE+1];;
extern uint32_t Node_ID[LORA_NUM_NODE+1];;
extern char Init_id[3];
extern uint32_t Timing_init_node;

extern bool LoRa_Response_TimeOut_Flag;


void LoRa_AP_Init(LoRa *lora, TIM *timer);
void LoRa_Response_TimeOutHandler(void *Parameter, TIM_Event_t event);
void LoRa_Receive_IRQHandler(void *arg, uint8_t len);


void LoRa_SendCommand(const char *command, const char *fomat, ...);
void LoRaTransmit(const char *fomat, ...);

void LoRa_Check_Lost_Data(void);
void LoRa_RequestData(void);
void Init_Node(void);


#endif /* LORA_API_H_ */
