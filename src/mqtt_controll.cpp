/**
Version: 0a
Tecnocoli - 04/2024
jcoli - Jeferson Coli - jcoli@tecnocoli.com.br
STM32F407VET6 - Grown
**/

#include <Arduino.h>
#include <ArduinoHA.h> //MQTT


#include "defines.h"
#include "io_defines.h"
#include "display.h"
#include "program.h"
#include "sounds.h"

void mqtt_begin();
void mqtt_loop();
void mqtt_update();

extern float ens_aqi;
extern float ens_tvoc;
extern float ens_eco2;
extern float aht_hum;
extern float aht_temp;
extern float bme1_temp;
extern float bme1_hum;
extern float bme1_press;
extern float bme2_temp;
extern float bme2_hum;
extern float bme2_press;
extern float light_int;
extern float soil_hum;

extern float pot1;
extern float pot2;

// extern byte mac[6];

byte unique[6];

byte mac1[] = {0x00, 0x10, 0xFA, 0x6E, 0x38, 0x4A};

void mqtt_begin(){
    Serial.println("mqtt");
    // device.enableSharedAvailability();
    
}

void mqtt_loop(){
  
}

void mqtt_update(){
    WIFI_SERIAL.print("3,7,soil_hum,"+String(soil_hum)+",#"); 
    WIFI_SERIAL.print("3,11,light_int,"+String(light_int)+",#"); 
    WIFI_SERIAL.print("3,1,bme1_temp,"+String(bme1_temp)+",#"); 
    WIFI_SERIAL.print("3,2,bme1_hum,"+String(bme1_hum)+",#"); 
    WIFI_SERIAL.print("3,3,bme1_press,"+String(bme1_press)+",#"); 
    WIFI_SERIAL.print("3,1,aht_temp,"+String(aht_temp)+",#"); 
    WIFI_SERIAL.print("3,2,aht_hum,"+String(aht_hum)+",#"); 
    WIFI_SERIAL.print("3,4,ens_eco2,"+String(ens_eco2)+",#");
    WIFI_SERIAL.print("3,4,ens_tvoc,"+String(ens_tvoc)+",#");
    WIFI_SERIAL.print("3,4,ens_aqi,"+String(ens_aqi)+",#"); 
   
}




