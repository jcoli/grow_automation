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
#include "display_navigation.h"
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

const uint8_t BUTTON_PINS[NUM_BUTTONS] = {BT_01,BT_02,BT_03,BT_04,SW_01,SW_02,SW_03,SW_04,BD_0,BD_1,BD_2,BD_3,BD_4,BTE_1,BTE_2,DP_01, DP_02};
Bounce * buttons = new Bounce[NUM_BUTTONS];

extern unsigned long encoderDelay;
extern int enc1oldPos;
extern int enc1newPos;
extern int enc2oldPos;
extern int enc2newPos;

extern bool ch_page;
extern bool ch_page_ana;
extern int tft_page;
extern int tft_page_ant;
extern int tft_sub_page;
extern int tft_sub_page_ant;

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
    enc1newPos = encoder1.getPosition(); 
    enc2newPos = encoder2.getPosition(); 

    if (enc1newPos != enc1oldPos) {
          if (enc1oldPos>enc1newPos){
            //  dec_ana();
          }   
          if (enc1oldPos<enc1newPos){
            
          }
          enc1oldPos = enc1newPos;
    }

    if (enc2newPos != enc2oldPos) {
          if (enc2oldPos>enc2newPos){
            //  dec_ana();
          }   
          if (enc2oldPos<enc2newPos){
            // inc_ana();
          }
          enc2oldPos = enc2newPos;
    }


    for (int i = 0; i < NUM_BUTTONS; i++)  {
    buttons[i].update();
    if ( buttons[i].fell() ) {
      switch (i) {
        case 0:
          Serial.println("button0");
          break;
        case 1:
          Serial.println("button1");
          break;
        case 2:
          Serial.println("button2");
          break;
        case 3:
          Serial.println("button3");
          break;
        case 4:
          Serial.println("button4");
          break;
        case 5:
          Serial.println("button5");
          break;  
        case 6:
          Serial.println("button6");
          break;
        case 7:
          Serial.println("button7");
          break;   
        case 8:
          Serial.println("button8");
          break;   
        case 9:
          Serial.println("button9");
          break;
        case 10:
          Serial.println("button10");
          break;     
        case 11:
          Serial.println("button11");
          break;     
        case 12:
          Serial.println("button12");
          break;
        case 13:
          Serial.println("button13");
          break;   
        case 14:
          Serial.println("button14");
          break;    
        case 15:
          tft_page--;
          if (tft_page<0) tft_page=0;
          change_tft_page();
          Serial.println("button15");
          break;    
        case 16:
          tft_page++;
          if (tft_page>1) tft_page=1;
          change_tft_page();
          Serial.println("button16");
          break;    
                
      }
      
      
    } 
  }        


}
