

#include <stdint.h>
#include "stm32f4xx.h"
#include "Config.h"
#include "string.h"
#include "vector"

const char *TAG = "STM32_LOG";
std::queue<char*> Control_list [LORA_NUM_NODE+1][4];
int Count_Node = 0;
int Count_Control = 0;

float Node1_Temp = 0.0, Node1_Humi = 0.0;
float Node2_Temp = 0.0, Node2_Humi = 0.0;

__IO uint32_t vectortime = 0;
int id_index = 1;
int relay_index = 0;

void Refresh_Screen(void){
	if(gettick() - tick >= 2){
		lv_task_handler();
		lv_tick_get();
		tick = gettick();
	}
}

int main (void){

	Periph_Initialize();
	tick = gettick();
	vectortime = gettick();
	while(1){
		Refresh_Screen();
		GPIO_Reset(GPIOC, 13);

		if(LoRa_ReqTimer_Flag == true && Count_Node != 0){
			LoRa_Check_Lost_Data();
			LoRa_RequestData();
			LoRa_ReqTimer_Flag = false;
		}

		if(!Packet_Uart_Queue.empty()){
			uint8_t* packet = Packet_Uart_Queue.front();
			Packet_t RxPacket = Parse_Packet((char *)packet);

			if(RxPacket.state != Packet_Error){
				switch(RxPacket.command){
					case Command_Control:{
						LoRaTransmit(RxPacket.fullpacket);
						char *id_str = GetData(RxPacket.data, 0, ',');
						char *rl     = GetData(RxPacket.data, 1, ',');
						char *stt    = GetData(RxPacket.data, 2, ',');
						int id = atoi(id_str);
						int index_relay = atoi(&rl[5]);
						Set_Control_Switch(id, rl, stt);
						int length = strlen(RxPacket.fullpacket)+1;
						char* tmp = (char*)malloc(length);
						memcpy(tmp, RxPacket.fullpacket,length);
						tmp[length] = '\0';
						if(strlen(tmp)>19){
							Control_list[id][index_relay].push(tmp);
							Count_Control++;
						}
						else if(tmp != NULL){
							free(tmp);
						}
						if(id_str != NULL){
							free(id_str);
						}
						if(rl != NULL){
							free(rl);
						}
						if(stt != NULL){
							free(stt);
						}
					}
					break;

					case Command_WiFi_Scan:{
						Set_ShowWiFi(RxPacket.data);
					}
					break;

					case Command_NetWork_State:
						if(strcmp(RxPacket.data, DATA_ETH_CONNECTED) == 0)    	   ETH_Connected = true;
						else if(strcmp(RxPacket.data, DATA_ETH_DISCONNECTED) == 0) ETH_Connected = false;

						if(strcmp(RxPacket.data, DATA_WIFI_CONNECTED) == 0)    		WiFi_Connected = true;
						else if(strcmp(RxPacket.data, DATA_WIFI_DISCONNECTED) == 0) WiFi_Connected = false;

						if(!WiFi_Connected && !ETH_Connected){
							Set_NetWork_State((char *)"No Internet");
							lv_label_set_text(ui_avaiableLabel, "No connect");
						}
						else if(WiFi_Connected && !ETH_Connected) Set_NetWork_State((char *)LV_SYMBOL_WIFI);
						else Set_NetWork_State((char *)"Eth");
					break;

					case Command_MQTT_State:
						if(strcmp(RxPacket.data, DATA_MQTT_CONNECT) == 0)    	  MQTT_Connected = true;
						else if(strcmp(RxPacket.data, DATA_MQTT_DISCONNECT) == 0) MQTT_Connected = false;
					break;

					default:
					break;
				}
			}
			Packet_Uart_Queue.pop();
			Free_Packet(&RxPacket);
			if(packet != NULL){
				free(packet);
			}
		}

		if(!Packet_Lora_Queue.empty()){
			char *packet = Packet_Lora_Queue.front();
			Packet_t LoRa_Resp_Packet = Parse_Packet(packet);
			if(LoRa_Resp_Packet.state != Packet_Error){
				switch(LoRa_Resp_Packet.command){

					case Command_New_Node:{
						if(!strcmp(LoRa_Resp_Packet.data, "*")){
							Init_Node();
						}
						if(strcmp(LoRa_Resp_Packet.data, Init_id)==0){
							Node_ID[atoi(Init_id)] = gettick() - Timing_init_node;
							ESP32_SendCommand(CMD_NEW_NODE, "%s", Init_id);
							int id = atoi(Init_id);
							Count_Node++;
						}
					}

					break;

					case Command_Data:{
						if(strcmp(LoRa_Resp_Packet.data, "OK") != 0)
							ESP32_SendEnvData(LoRa_Resp_Packet.data);

						char *id_str   = GetData(LoRa_Resp_Packet.data, 0, ',');
						char *temp_str = GetData(LoRa_Resp_Packet.data, 1, ',');
						char *humi_str = GetData(LoRa_Resp_Packet.data, 2, ',');
						int id = atoi(id_str);

						if(id == 1){
							Node1_Temp = atof(temp_str);
							Node1_Humi = atof(humi_str);
							Set_ShowNode1(Node1_Temp, Node1_Humi);
							update_Chart_Node1(Node1_Temp, Node1_Humi);
						}
						else if(id == 2){
							Node2_Temp = atof(temp_str);
							Node2_Humi = atof(humi_str);
							Set_ShowNode2(Node2_Temp, Node2_Humi);
							update_Chart_Node2(Node2_Temp, Node2_Humi);
						}

						Response_State[id] = true;
						Counter_timeout[id] = 0;
						if(id_str != NULL){
							free(id_str);
						}
						if(temp_str != NULL){
							free(temp_str);
						}
						if(humi_str != NULL){
							free(humi_str);
						}
					}
					break;

					case Command_Control:{
						char *id_str = GetData(LoRa_Resp_Packet.data, 0, ',');
						char *rl     = GetData(LoRa_Resp_Packet.data, 1, ',');
						int id = atoi(id_str);
						int index_relay = atoi(&rl[5]);
						if(!Control_list[id][index_relay].empty()){
							if(!strcmp(Control_list[id][index_relay].front(),LoRa_Resp_Packet.fullpacket)){
								Counter_timeout[id] = 0;
								Count_Control--;
								if(Control_list[id][index_relay].front() != NULL){
									free(Control_list[id][index_relay].front());
								}
								Control_list[id][index_relay].pop();
								if(id_str != NULL){
									free(id_str);
								}
								if(rl != NULL){
									free(rl);
								}
							}
						}
					}
					break;
					default:
					break;
				}
				if(packet != NULL){
					free(packet);
				}
				Free_Packet(&LoRa_Resp_Packet);
				Packet_Lora_Queue.pop();
			}
		}

 		if(GetTime_Flag == true){
			Set_Show_Time();
			GetTime_Flag = false;
		}

		if(gettick() - vectortime >= 371 && Count_Control != 0){
			if(relay_index >= 3){
				relay_index = 1;
				if(id_index >= LORA_NUM_NODE){
					id_index = 1;
				}
				else{
					id_index++;
				}
			}
			else{
				relay_index++;
			}
			if(!Control_list[id_index][relay_index].empty()){
				LoRaTransmit(Control_list[id_index][relay_index].front());
			}
			vectortime = gettick();
		}
	}
}





















