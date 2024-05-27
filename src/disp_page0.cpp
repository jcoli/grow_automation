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
#include "disp_footpage.h"

void draw_page0();
void draw_menu0();


extern uint32_t subSec;
extern byte seconds;
extern byte minutes;
extern byte hours;
extern byte weekDay;
extern byte day;
extern byte month;
extern byte year;

extern int language;

extern bool ch_page;
extern bool ch_page_ana;
extern int tft_page;
extern int tft_page_ant;
extern int tft_sub_page;
extern int tft_sub_page_ant;
extern int item_to_ch;
extern int item_out_dig_select;
extern bool inj_en;
extern bool con_en;
extern bool inj_en;
extern bool con_en;
extern bool inj_en_1;
extern bool con_en_1;
extern bool rpm_en;
extern bool out;

extern int draw_tab;
extern int draw_page;

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


extern  TFT_eSPI tft;
// TFT_eSPI tft = TFT_eSPI(); 

extern float VRef;
extern float intTemp;


void draw_page0(){
  Serial.println("Draw 0");
  if ((tft_page == 0) && (ch_page)){

      int t_line = 16 + 28;
      int t_line_space = 27;
      int t_line_1 = 55;
      int t_line_2 = t_line_1 + t_line_space;
      int t_line_3 = t_line_2 + t_line_space;
      int t_line_4 = t_line_3 + t_line_space;
      int t_line_5 = t_line_4 + t_line_space;
      int t_line_6 = t_line_5 + t_line_space;
      int t_line_7 = t_line_6 + t_line_space;
      int t_line_8 = t_line_7 + t_line_space;
      int t_line_9 = t_line_8 + t_line_space;
      int t_line_10 = t_line_9 + t_line_space;
      int t_line_11 = t_line_10 + t_line_space;

      int c_line_1 = 50;
      int c_line_space = 27;
      int c_line_2 = c_line_1 + c_line_space;
      int c_line_3 = c_line_2 + c_line_space;
      int c_line_4 = c_line_3 + c_line_space;
      int c_line_5 = c_line_4 + c_line_space;
      int c_line_6 = c_line_5 + c_line_space;
      int c_line_7 = c_line_6 + c_line_space;
      int c_line_8 = c_line_7 + c_line_space;
      int c_line_9 = c_line_8 + c_line_space;
      int c_line_10 = c_line_9 + c_line_space;
      int c_line_11 = c_line_10 + c_line_space;

  

    if (draw_tab == 0){

        tft.fillScreen(TFT_BLACK);
        
        tft.setFreeFont(FMB9); 
        tft.setTextSize(0);
        tft.setTextColor(TFT_LIGHTBLUE);
        tft.fillRoundRect(0,0,68,30, 5, TFT_LIGHTBLUE);
        tft.setCursor(5,18);
        tft.setTextColor(TFT_BLACK);
        tft.println("Princ.");
        tft.drawRoundRect(68,0,68,30, 5, TFT_SKYBLUE);
        tft.setCursor(73,18);
        tft.setTextColor(TFT_LIGHTBLUE);
        tft.println("Contr.");
        tft.drawRoundRect(136,0,68,30, 5, TFT_SKYBLUE);
        tft.setCursor(141,18);
        tft.println("Ilum.");
        tft.drawRoundRect(204,0,68,30, 5, TFT_SKYBLUE);
        tft.setCursor(209,18);
        tft.println("Comm.");
        tft.drawRoundRect(272,0,68,30, 5, TFT_SKYBLUE);
        tft.setCursor(277,18);
        tft.println("Vent.");
        tft.drawRoundRect(340,0,68,30, 5, TFT_SKYBLUE);
        tft.setCursor(346,18);
        tft.println("Irr.");
        tft.drawRoundRect(408,0,68,30, 5, TFT_SKYBLUE);
        tft.setCursor(415,18);
        tft.println("Info");
        // tft.drawFastHLine(4, 29,  470, TFT_SKYBLUE);
        
    }

    if (draw_page == 0){  
        
        tft.setFreeFont(FMB9);
        tft.setTextColor(TFT_YELLOW); 
        tft.setTextSize(0);

        tft.setCursor(5,60);
        tft.print("Temp CPU:");
        tft.setCursor(5,80);
        tft.print("Tensao CPU:");
        tft.setCursor(5,100);
        tft.print("Temp bme1:");
        tft.setCursor(5,120);
        tft.print("Temp bme2:");
        tft.setCursor(5,140);
        tft.print("Temp aht:");
        tft.setCursor(5,160);
        tft.print("CO2:");

        tft.setCursor(230,100);
        tft.print("Hum bme1:");
        tft.setCursor(230,120);
        tft.print("Hum bme2:");
        tft.setCursor(230,140);
        tft.print("Hum aht:");
        tft.setCursor(230,160);
        tft.print("TVOC:");



        tft.setTextColor(TFT_RED); 
        tft.setCursor(320,60);
        tft.printf("%02d/%02d/%02d ", day, month, year);
        tft.setCursor(420,60);
        tft.printf("%02d:%02d\n", hours, minutes);


        tft.setTextColor(TFT_SKYBLUE);

        tft.setCursor(130,60);
        tft.print(intTemp,2);
        tft.setCursor(190,60);
        tft.println("°C");
        tft.setCursor(140,80);
        tft.print(VRef/1000);
        tft.setCursor(190,80);
        tft.println("V");

        tft.setCursor(130,100);
        tft.print(bme1_temp,2);
        tft.setCursor(140,120);
        tft.print(bme2_temp,2);
        tft.setCursor(130,140);
        tft.print(aht_temp,2);
        tft.setCursor(120,160);
        tft.print(ens_eco2,2);

        tft.setCursor(355,100);
        tft.print(bme1_hum,2);
        tft.setCursor(365,120);
        tft.print(bme2_hum,2);
        tft.setCursor(355,140);
        tft.print(aht_hum,2);
        tft.setCursor(355,160);
        tft.print(ens_tvoc,2);

        
        inj_en = true;
        out=true;
        con_en = true;
        con_en_1 = true;
        draw_footpage();
        ch_page = false;
      }  
  }
}  

