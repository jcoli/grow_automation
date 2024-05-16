/**
Version: 0a
Tecnocoli - 04/2024
jcoli - Jeferson Coli - jcoli@tecnocoli.com.br
STM32F407VET6 - Grown
**/

#include <Arduino.h>
#include <Bounce2.h>
#include <RotaryEncoder.h>

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

void buttons_begin();
void checkPosition();
void check_button();

RotaryEncoder encoder1(ENC1_CLK, ENC1_DT, RotaryEncoder::LatchMode::TWO03);
RotaryEncoder encoder2(ENC2_CLK, ENC2_DT, RotaryEncoder::LatchMode::TWO03);

const uint8_t BUTTON_PINS[NUM_BUTTONS] = {BT_01,BT_02,BT_03,BT_04,SW_01,SW_02,SW_03,SW_04,BD_0,BD_1,BD_2,BD_3,BD_4,BTE_1,BTE_2};
Bounce * buttons = new Bounce[NUM_BUTTONS];

extern unsigned long encoderDelay;
extern int enc1oldPos;
extern int enc1newPos;
extern int enc2oldPos;
extern int enc2newPos;



void buttons_begin(){
    for (int i = 0; i < NUM_BUTTONS; i++) {
      buttons[i].attach( BUTTON_PINS[i] , INPUT_PULLUP  );       //setup the bounce instance for the current button
      buttons[i].interval(55);              // interval in ms
    }
    attachInterrupt(digitalPinToInterrupt(ENC1_DT), checkPosition, CHANGE);
    attachInterrupt(digitalPinToInterrupt(ENC1_CLK), checkPosition, CHANGE);
    attachInterrupt(digitalPinToInterrupt(ENC2_DT), checkPosition, CHANGE);
    attachInterrupt(digitalPinToInterrupt(ENC2_CLK), checkPosition, CHANGE);
}

void checkPosition(){
  Serial.println("checkPosition");
  encoder1.tick();
  encoder2.tick(); 
}

void check_button(){
    if ((millis() - encoderDelay > 200)) {
      encoderDelay = millis();
    }  


}
