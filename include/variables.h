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

#endif