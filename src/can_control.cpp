/**
Version: 0a
Tecnocoli - 08/2024
jcoli - Jeferson Coli - jcoli@tecnocoli.com.br    
STM32F103C8 - Grow Sensors
**/

#include <Arduino.h>
#include <SPI.h>
#include <mcp_can.h>

#include "defines.h"
#include "io_defines.h"


void can_begin();
void can_read();
void can_write(uint64_t canTXId, int frame_type, int data_lenght, byte send_data[8]);

SPIClass SPI_2(PB15,PB14,PB13);
MCP_CAN CAN0(&SPI_2, PA8);

long unsigned int rxId;
unsigned char len = 0;
unsigned char rxBuf[8];
char msgString[128];   
byte data[8] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07};  


void can_begin(){
    if(CAN0.begin(MCP_ANY, CAN_500KBPS, MCP_16MHZ) == CAN_OK) 
      Serial.println("MCP2515 Initialized Successfully!");
    else 
      Serial.println("Error Initializing MCP2515...");

    CAN0.setMode(MCP_NORMAL);   

    pinMode(CAN0_INT, INPUT); 

    attachInterrupt(digitalPinToInterrupt(CAN0_INT), can_read, LOW);

}

void can_read(){
    CAN0.readMsgBuf(&rxId, &len, rxBuf);      // Read data: len = data length, buf = data byte(s)
    
    if((rxId & 0x80000000) == 0x80000000)     // Determine if ID is standard (11 bits) or extended (29 bits)
      sprintf(msgString, "Extended ID: 0x%.8lX  DLC: %1d  Data:", (rxId & 0x1FFFFFFF), len);
    else
      sprintf(msgString, "Standard ID: 0x%.3lX       DLC: %1d  Data:", rxId, len);
  
    Serial.print(msgString);
  
    if((rxId & 0x40000000) == 0x40000000){    // Determine if message is a remote request frame.
      sprintf(msgString, " REMOTE REQUEST FRAME");
      Serial.print(msgString);
    } else {
      for(byte i = 0; i<len; i++){
        sprintf(msgString, " 0x%.2X", rxBuf[i]);
        Serial.print(msgString);
      }
    }
        
    Serial.println();

}

void can_write(uint64_t canTXId, int frame_type, int data_lenght, byte send_data[8]){

    byte sndStat = CAN0.sendMsgBuf(canTXId, frame_type, data_lenght, send_data);
    if(sndStat == CAN_OK){
    Serial.println("Message Sent Successfully!");
    } else {
        Serial.println("Error Sending Message...");
    }

}

