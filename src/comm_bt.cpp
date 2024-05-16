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

void init_bt();
void on_bt_comm();

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



void init_bt(){
    Serial.println("on_bt_init");
    // HC05_SERIAL.println("AT");
    HC05_SERIAL.println("2,0,0,0,#"); 

}

void on_bt_comm(){
    Serial.println("on_bt_comm");
    Serial.println(line2);
    
    

}