
 #include "Ethernet.h"
 #include <string.h>

 #include "freertos/FreeRTOS.h"
 #include "freertos/task.h"

 #include "esp_netif.h"
 #include "esp_check.h"
 #include "esp_event.h"
 #include "esp_log.h"

 #include "esp_mac.h"

 #include "driver/gpio.h"

#include "UART.h"

 static const char *TAG = "ETHERNET";

 uint8_t eth_port_cnt = 0;
 esp_eth_handle_t *eth_handles;


 static void ETH_Event_Handler(void *arg, esp_event_base_t event_base, int32_t event_id, void *event_data);
 static void ETH_GetIP_Event_Handler(void *arg, esp_event_base_t event_base, int32_t event_id, void *event_data);
 static esp_eth_handle_t ETH_Driver_Init(esp_eth_mac_t **mac_out, esp_eth_phy_t **phy_out);


 static void ETH_Event_Handler(void *arg, esp_event_base_t event_base, int32_t event_id, void *event_data){
     uint8_t mac_addr[6] = {0};

     esp_eth_handle_t eth_handle = *(esp_eth_handle_t *)event_data;

     switch (event_id) {
 		case ETHERNET_EVENT_CONNECTED:
 			esp_eth_ioctl(eth_handle, ETH_CMD_G_MAC_ADDR, mac_addr);
 			ESP_LOGI(TAG, "Ethernet Link Up");
 			ESP_LOGI(TAG, "Ethernet HW Addr %02x:%02x:%02x:%02x:%02x:%02x",
 					 mac_addr[0], mac_addr[1], mac_addr[2], mac_addr[3], mac_addr[4], mac_addr[5]);
 		break;

 		case ETHERNET_EVENT_DISCONNECTED:
 			ESP_LOGI(TAG, "Ethernet Link Down");
 			STM_sendData(TAG, "NETWORK: ETH DISCONNECTED");
 		break;

 		case ETHERNET_EVENT_START:
 			ESP_LOGI(TAG, "Ethernet Started");
 		break;

 		case ETHERNET_EVENT_STOP:
 			ESP_LOGI(TAG, "Ethernet Stopped");
 		break;

 		default:
         break;
     }
 }

 static void ETH_GetIP_Event_Handler(void *arg, esp_event_base_t event_base, int32_t event_id, void *event_data){
     ip_event_got_ip_t *event = (ip_event_got_ip_t *) event_data;
     const esp_netif_ip_info_t *ip_info = &event->ip_info;

     ESP_LOGI(TAG, "Ethernet Got IP Address");
     ESP_LOGI(TAG, "~~~~~~~~~~~");
     ESP_LOGI(TAG, "ETHIP:" IPSTR, IP2STR(&ip_info->ip));
     ESP_LOGI(TAG, "ETHMASK:" IPSTR, IP2STR(&ip_info->netmask));
     ESP_LOGI(TAG, "ETHGW:" IPSTR, IP2STR(&ip_info->gw));
     ESP_LOGI(TAG, "~~~~~~~~~~~");

     STM_sendData(TAG, "NETWORK: ETH CONNECTED");
 }

 static esp_eth_handle_t ETH_Driver_Init(esp_eth_mac_t **mac_out, esp_eth_phy_t **phy_out){
     esp_eth_handle_t ret = NULL;

     eth_phy_config_t phy_config = ETH_PHY_DEFAULT_CONFIG();
     phy_config.phy_addr = ETH_PHY_ADDR;
     phy_config.reset_gpio_num = ETH_RST_PIN;

     eth_esp32_emac_config_t esp32_emac_config = ETH_ESP32_EMAC_DEFAULT_CONFIG();
     esp32_emac_config.smi_mdc_gpio_num = ETH_MDC_PIN;
     esp32_emac_config.smi_mdio_gpio_num = ETH_MDIO_PIN;

     eth_mac_config_t mac_config = ETH_MAC_DEFAULT_CONFIG();
     esp_eth_mac_t *mac = esp_eth_mac_new_esp32(&esp32_emac_config, &mac_config);
     esp_eth_phy_t *phy = esp_eth_phy_new_lan87xx(&phy_config);

     esp_eth_handle_t eth_handle = NULL;
     esp_eth_config_t config = ETH_DEFAULT_CONFIG(mac, phy);
     ESP_GOTO_ON_FALSE(esp_eth_driver_install(&config, &eth_handle) == ESP_OK, NULL, err, TAG, "Ethernet driver install failed");

     if (mac_out != NULL) *mac_out = mac;
     if (phy_out != NULL) *phy_out = phy;

     return eth_handle;
 err:
     if (eth_handle != NULL) esp_eth_driver_uninstall(eth_handle);
     if (mac != NULL) mac->del(mac);
     if (phy != NULL) phy->del(phy);


     return ret;
 }

 esp_err_t ETH_Init(void){
     esp_err_t ret = ESP_OK;

     ESP_GOTO_ON_FALSE(&eth_handles != NULL && &eth_port_cnt != NULL, ESP_ERR_INVALID_ARG,
                         err, TAG, "invalid arguments: initialized handles array or number of interfaces");

     eth_handles = calloc(1, sizeof(esp_eth_handle_t));
     ESP_GOTO_ON_FALSE(eth_handles != NULL, ESP_ERR_NO_MEM, err, TAG, "no memory");

     eth_handles[eth_port_cnt] = ETH_Driver_Init(NULL, NULL);
     ESP_GOTO_ON_FALSE(eth_handles[eth_port_cnt], ESP_FAIL, err, TAG, "internal Ethernet init failed");
     eth_port_cnt++;

     ESP_ERROR_CHECK(esp_netif_init());

     if (eth_port_cnt == 1) {
         esp_netif_config_t cfg = ESP_NETIF_DEFAULT_ETH();
         esp_netif_t *eth_netif = esp_netif_new(&cfg);
         ESP_ERROR_CHECK(esp_netif_attach(eth_netif, esp_eth_new_netif_glue(eth_handles[0])));
     }
     else {

         esp_netif_inherent_config_t esp_netif_config = ESP_NETIF_INHERENT_DEFAULT_ETH();
         esp_netif_config_t cfg_spi = {
             .base = &esp_netif_config,
             .stack = ESP_NETIF_NETSTACK_DEFAULT_ETH
         };
         char if_key_str[10];
         char if_desc_str[10];
         char num_str[3];
         for (int i = 0; i < eth_port_cnt; i++) {
             itoa(i, num_str, 10);
             strcat(strcpy(if_key_str, "ETH_"), num_str);
             strcat(strcpy(if_desc_str, "eth"), num_str);
             esp_netif_config.if_key = if_key_str;
             esp_netif_config.if_desc = if_desc_str;
             esp_netif_config.route_prio -= i*5;
             esp_netif_t *eth_netif = esp_netif_new(&cfg_spi);

             ESP_ERROR_CHECK(esp_netif_attach(eth_netif, esp_eth_new_netif_glue(eth_handles[i])));
         }
     }

     ESP_ERROR_CHECK(esp_event_handler_register(ETH_EVENT, ESP_EVENT_ANY_ID, &ETH_Event_Handler, NULL));
     ESP_ERROR_CHECK(esp_event_handler_register(IP_EVENT, IP_EVENT_ETH_GOT_IP, &ETH_GetIP_Event_Handler, NULL));

     for (int i = 0; i < eth_port_cnt; i++)
         ESP_ERROR_CHECK(esp_eth_start(eth_handles[i]));

 err:
     free(eth_handles);
     return ret;
 }

 void ETH_DeInit(void){
 //	esp_eth_stop(*eth_handles);
 //	esp_eth_driver_uninstall(*eth_handles);
 }





