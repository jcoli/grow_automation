/**
Version: 0a
Tecnocoli - 11/2023
jcoli - Jeferson Coli - jcoli@tecnocoli.com.br
Pipicow - Clothes Dryer
**/
#include <Arduino.h>
#include <SPI.h>
#include <TFT_eSPI.h>

#include "Free_Fonts.h"

#include "defines.h"
#include "io_defines.h"
#include "tools.h"

TFT_eSPI tft = TFT_eSPI(); 

void display_begin();
void show_display();
void change_data();
void drawSplash();


extern bool wifi_connected;


void display_begin(){
    tft.setRotation(3);
    tft.init();
 
     
}

void show_display(){
    
  
} 

void change_data(){
    
}  



void drawSplash(){
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_RED);
  tft.setFreeFont(FMB24); 
  tft.setTextSize(1);
  tft.setCursor(110,100);
  tft.println("TECNOCOLI");
  tft.setFreeFont(FMB12); 
  tft.setTextSize(1);
  tft.setCursor(130,220);
  tft.println("GROW Automation");

}

