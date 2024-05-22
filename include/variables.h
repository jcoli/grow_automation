/**
Version: 0a
Tecnocoli - 04/2024
jcoli - Jeferson Coli - jcoli@tecnocoli.com.br
STM32F407VET6 - Grown
**/


#ifndef __VARIABLES_H__
#define __VARIABLES_H__
#include <Arduino.h>

float tempIn = 0;
float tempOut = 0;
float tempCpu = 0;
float deltaTemp = 0;

bool dryerState = false;
bool heaterState = false;
bool heaterEnable = false;
bool fan1State = false;
bool fan1Enable = false; 
bool dryerOn = false;
bool doorState = true;
bool lastDoorState = false;
bool cooling = false;
bool sleeping = false;

String ipaddress;
long rssi;
bool led_out = false;
bool door = false;
bool wifi_connected = false;
bool mqtt_connected = false;

String line = "";
String line1 = "";
String line2 = "";
bool stringComplete = false;
bool string1Complete = false;
bool string2Complete = false;

String Ssid[2][10];
int list_size = 0;
int ind_list_size = 0;

String retMsg2[2] = {"", ""};
String retMsg3[3] = {"", "", ""};
String retMsg4[4] = {"", "", "", ""};
String retMsg5[5] = {"", "", "", "", ""};

unsigned long loopDelay = millis();
unsigned long loopDelay_analog = millis();
unsigned long loopDelay_input = millis();
unsigned long loopDelay_mqtt = millis();
unsigned long lastAvailabilityToggleAt = millis();

unsigned long encoderDelay = millis();

int enc1oldPos  = 0;
int enc1newPos  = 0;
int enc2oldPos  = 0;
int enc2newPos  = 0;


bool init_comm = true;
bool live = false;
bool bcomm = false;
bool live_1 = false;
bool bcomm_1 = false;
int conn_timeout = 20;
int livebit_tmp = 0;
int livebit_inj_tmp = 0;
int conn_timeout_1 = 10;
int livebit_tmp_1 = 0;
int livebit_inj_tmp_1 = 0;
bool injectionEnable = false;
bool inj_en = false;
bool con_en = false;
bool inj_en_1 = false;
bool con_en_1 = false;
bool rpm_en = false;
bool out = false;
bool ch_page = true;
bool ch_page_ana = false;
int tft_page = 0;
int tft_page_ant = 0;
int tft_sub_page = 0;
int tft_sub_page_ant = 0;
int item_to_ch = 0;
int item_out_dig_select = 0;
int item_out_ana_select = 0;
int last_item_ana_select = 0;
int last_item_out_select =0;
float temp_ana_value = 1.00;
int pot = 0;

bool draw_test = true;
bool refresh_page = false;
int draw_tab = 0;
int draw_page = 0;

float VRef = 0.00;
float intTemp = 10.00;


#endif