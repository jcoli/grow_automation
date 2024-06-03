/**
Version: 0a
Tecnocoli - 04/2024
jcoli - Jeferson Coli - jcoli@tecnocoli.com.br
STM32F407VET6 - Grown
**/
#include <Arduino.h>

#include "defines.h"
#include "io_defines.h"
#include "display.h"
#include "mqtt_controll.h"
#include "sounds.h"
#include "input_digital_control.h"

void split_msg_2(String msg);
void split_msg_3(String msg);
void split_msg_4(String msg);
void split_msg_5(String msg);
void split_msg_6(String msg);

extern String retMsg2[2];
extern String retMsg3[3];
extern String retMsg4[4];
extern String retMsg5[5];
extern String retMsg6[6];

void split_msg_2(String msg){
    retMsg2[0] = "";
    retMsg2[1] = "";
    int j = 0;
    int p = 0;
    for(int i =0; i < msg.length(); i++){
       if(msg.charAt(i) == ','){
           retMsg2[p] = msg.substring(j, i);
           j = i +1;
           p++; 
       }
    }  
}

void split_msg_3(String msg){
    // Serial.println(msg);
    retMsg3[0] = "";
    retMsg3[1] = "";
    retMsg3[2] = "";
    int j = 0;
    int p = 0;
    for(int i =0; i < msg.length(); i++){
       if(msg.charAt(i) == ','){
           retMsg3[p] = msg.substring(j, i);
           j = i +1;
           p++;
       }
    }  
}

void split_msg_4(String msg){
    retMsg4[0] = "";
    retMsg4[1] = "";
    retMsg4[2] = "";
    retMsg4[3] = "";
    int j = 0;
    int p = 0;
    for(int i =0; i < msg.length(); i++){
       if(msg.charAt(i) == ','){
           String st = msg.substring(j, i);
           st.trim();
           retMsg4[p] = st;
           j = i +1;
           p++;
       }
    }  
}

void split_msg_5(String msg){
    retMsg5[0] = "";
    retMsg5[1] = "";
    retMsg5[2] = "";
    retMsg5[3] = "";
    retMsg5[4] = "";
    int j = 0;
    int p = 0;
    for(int i =0; i < msg.length(); i++){
       if(msg.charAt(i) == ','){
           retMsg5[p] = msg.substring(j, i);
           j = i +1;
           p++;
       }
    }  
}

void split_msg_6(String msg){
    retMsg6[0] = "";
    retMsg6[1] = "";
    retMsg6[2] = "";
    retMsg6[3] = "";
    retMsg6[4] = "";
    retMsg6[5] = "";
    int j = 0;
    int p = 0;
    for(int i =0; i < msg.length(); i++){
       if(msg.charAt(i) == ','){
           retMsg6[p] = msg.substring(j, i);
           j = i +1;
           p++;
       }
    }  
}
