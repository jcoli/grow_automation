/**
Version: 0a
Tecnocoli - 04/2024
jcoli - Jeferson Coli - jcoli@tecnocoli.com.br
STM32F407VET6 - Grown
**/

#include <Arduino.h>

#include "display.h"
#include "defines.h"
#include "io_defines.h"
#include "tools.h"
#include "input_analog_control.h"
#include "input_digital_control.h"
#include "mqtt_controll.h"
#include "output_digital_control.h"
#include "pitches.h"
#include "sounds.h"
#include "program.h"
#include "comm_bt.h"
#include "comm_wifi.h"

void init_wifi();
void on_wifi_comm();
void addlistNetworks();
void listNetworks();
void call_list_net();

extern String line;
extern String line1;
extern String line2;
extern String retMsg2[2];
extern String retMsg3[3];
extern String retMsg4[4];
extern String retMsg5[5];

extern String Ssid[2][10];


extern int list_size;
extern int ind_list_size;

void init_wifi(){
    Serial.println("on_wifi_init");
    WIFI_SERIAL.print("0,0,0,0,#");
}

void call_list_net(){
    Serial.println("on_call_list");
    WIFI_SERIAL.print("1,0,0,0,#");
}

void on_wifi_comm(){
    // Serial.println("on_wifi_comm");
    // Serial.println(line1); 

    split_msg_5(line1);

    int i = retMsg5[0].toInt();
    switch (i) {
        case 0:
        //   Serial.println("wifi - case 0");
          addlistNetworks();
          break;
        case 1:
        //   Serial.println("wifi - case 1");
          list_size = retMsg5[3].toInt();
          // Serial.println("wifi - case 1: "+retMsg5[3]+" - "+ list_size);
          ind_list_size = 0;
          break;
        case 2:
          listNetworks();
          // Serial.println("wifi - case 2");
          break;
        case 3:
          Serial.println("wifi - case 3");
          break;
        case 4:
          Serial.println("wifi - case 4");
          break;
        case 5:
          Serial.println("wifi - case 5");
          break;  
    }    
}


void addlistNetworks() {
    // Serial.println("wifi - case 0: "+retMsg5[3]+" - "+ list_size+" - "+ ind_list_size);
    
    if (ind_list_size <= list_size){
      Ssid[0][ind_list_size] = retMsg5[2];
      Ssid[1][ind_list_size] = retMsg5[3];
      ind_list_size++;
    }
        
        // Serial.println("SSID: "+Ssid[0][ind_list_size-1]+" RSSI: "+Ssid[1][ind_list_size-1]); 
        // Serial.print(ind_list_size);
        // Serial.print("::::");
        // Serial.println(list_size);
        
    // }
}  

void listNetworks(){    
      
      delay(500);
      for (int i = 0; i<list_size; i++ ){
          // Serial.println("SSID: "+Ssid[0][i]+" RSSI: "+Ssid[1][i]);
          // HC05_SERIAL.println("SSID: "+Ssid[0][i]+" RSSI: "+Ssid[1][i]); 
      }
      // HC05_SERIAL.println("4,1,0,0,#");
      Serial.println("===================");
      Serial.println("");
}





