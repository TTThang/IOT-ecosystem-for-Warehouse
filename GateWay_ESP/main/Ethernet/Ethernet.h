
#ifndef ETHERNET_H_
#define ETHERNET_H_


#include <stdio.h>
#include "esp_eth.h"


#define ETH_PHY_ADDR  1
#define ETH_RST_PIN   -1
#define ETH_MDC_PIN   23
#define ETH_MDIO_PIN  18



esp_err_t ETH_Init(void);
void ETH_DeInit(void);
#endif /* ETH_H_ */
