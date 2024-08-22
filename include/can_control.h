/**
Version: 0a
Tecnocoli - 08/2024
jcoli - Jeferson Coli - jcoli@tecnocoli.com.br    
STM32F103C8 - Grow Sensors
**/

#include <Arduino.h>
#include <SPI.h>
#include <mcp_can.h>

void can_begin();

SPIClass SPI_2(PB15,PB14,PB13);


MCP_CAN CAN0(&SPI_2, PA8);


void can_begin(){
     if(CAN0.begin(MCP_ANY, CAN_500KBPS, MCP_16MHZ) == CAN_OK) 
      Serial.println("MCP2515 Initialized Successfully!");
    else 
      Serial.println("Error Initializing MCP2515...");

    CAN0.setMode(MCP_NORMAL);   // Change to normal mode to allow messages to be transmitted

}
