
idf_component_register(
    					SRCS "main.c"
    						 "WiFi/WiFi.c"
    						 "Ethernet/Ethernet.c" 
    						 "UART/UART.c"
    						 "GateWay_API/GateWay_API.c"   
    						 "MQTT/MQTT.c"     
				INCLUDE_DIRS "."
							 "WiFi"
							 "Ethernet"
							 "UART"
							 "GateWay_API"
							 "MQTT"
)
