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
   
}




