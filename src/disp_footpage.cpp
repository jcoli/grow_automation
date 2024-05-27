/**
Version: 0a
Tecnocoli - 10/2021
jcoli - Jeferson Coli - jcoli@teccnocoli.com.br
STM32F407VET6 - Digital ECU Simulator
**/
#include <Arduino.h>
#include <TFT_eSPI.h> // Hardware-specific library

#include "display.h"
#include "Free_Fonts.h"
#include "defines.h"
#include "io_defines.h"
#include "display_navigation.h"

void draw_footpage();

extern int language;

extern volatile bool ch_page;
extern volatile bool ch_page_ana;
extern volatile int tft_page;
extern volatile int tft_page_ant;
extern volatile int tft_sub_page;
extern volatile int tft_sub_page_ant;
extern volatile int item_to_ch;
extern volatile int item_out_dig_select;
extern volatile bool inj_en;
extern volatile bool con_en;
extern volatile bool inj_en;
extern volatile bool con_en;
extern volatile bool inj_en_1;
extern volatile bool con_en_1;
extern volatile bool rpm_en;
extern volatile bool out;

extern volatile bool injectionEnable;
extern volatile bool live;
extern volatile bool bcomm;
extern volatile bool live_1;
extern volatile bool bcomm_1;

extern  TFT_eSPI tft;
// TFT_eSPI tft = TFT_eSPI(); 


void draw_footpage(){
    // Serial.println("Footpage");
  
    
    tft.setTextColor(TFT_SKYBLUE);
    tft.setFreeFont(FF5); 
    tft.setTextSize(0);
    //   PC Connection
    tft.setCursor(215,315);
    tft.print("Hum");
    tft.drawCircle(205,310, 6, TFT_LIGHTGREY);
    if (live){
            tft.fillCircle(205,310, 4, TFT_RED);
        }else{
            tft.fillCircle(205,310, 4, TFT_DARKGREY);
        }
    
    // Injector Connection
    tft.setCursor(275,315);  
    tft.print("Desu"); 
    tft.drawCircle(265,310, 6, TFT_LIGHTGREY);
    if (live_1){
        tft.fillCircle(265,310, 4, TFT_RED);   
    }else{
        tft.fillCircle(265,310, 4, TFT_DARKGREY);   
    }
    
    tft.setCursor(345,315);  
    tft.print("V1"); 
    tft.drawCircle(335,310, 6, TFT_LIGHTGREY);
    if (live_1){
        tft.fillCircle(335,310, 4, TFT_RED);   
    }else{
        tft.fillCircle(335,310, 4, TFT_DARKGREY);   
    }
    
    tft.setCursor(415,315);  
    tft.print("V2"); 
    tft.drawCircle(405,310, 6, TFT_LIGHTGREY);
    if (live_1){
        tft.fillCircle(405,310, 4, TFT_RED);   
    }else{
        tft.fillCircle(405,310, 4, TFT_DARKGREY);   
    }
           
    // Injector Status
    
    

    // lin 50, 30 and 15
    tft.setTextColor(TFT_SKYBLUE);
    tft.setCursor(20,315);
    tft.print("WiFi");
    tft.drawCircle(10,310, 6, TFT_LIGHTGREY);
      
    tft.setCursor(95,315);
    tft.print("BT");
    tft.drawCircle(85,310, 6, TFT_LIGHTGREY);
    
    tft.setCursor(150,315);
    tft.print("Exau");
    tft.drawCircle(140,310, 6, TFT_LIGHTGREY);
    

    // if (out){
    //     if (out_dig_i[0].value){
            tft.fillCircle(10,310, 4, TFT_RED);
        // }else{
        //     tft.fillCircle(10,310, 4, TFT_DARKGREY);
        // }
        // if (out_dig_i[1].value){
            tft.fillCircle(85,310, 4, TFT_RED);  
        // }else{
        //     tft.fillCircle(75,310, 4, TFT_DARKGREY);  
        // }   
        // if (out_dig_i[2].value){ 
        //     tft.fillCircle(140,310, 4, TFT_RED);  
        // }else{
            tft.fillCircle(140,310, 4, TFT_DARKGREY);  
        // }
        // out = false;    
        // }
 
}

