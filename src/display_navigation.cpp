/**
Version: 0a
Tecnocoli - 10/2021
jcoli - Jeferson Coli - jcoli@teccnocoli.com.br
STM32F407VET6 - Digital ECU Simulator
**/

#include <Arduino.h>
#include "Free_Fonts.h"

#include "defines.h"
#include "io_defines.h"
#include "display.h"
#include "disp_page0.h"
#include "disp_page1.h"

void change_tft_page();

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

extern bool refresh_page;
extern int draw_tab;
extern int draw_page;


void change_tft_page(){
    // if (tft_page != tft_page_ant){
    //     tft_page_ant = tft_page;
        con_en = true;
        con_en_1 = true;
        switch (tft_page) {
            case 0:
                ch_page = true;
                item_to_ch = 0;
                // if (!refresh_page)
                draw_tab = 0;
                draw_page = 0;
                draw_page0();
                Serial.println("Draw 0");
                break;
            case 1:
                ch_page = true;
                item_to_ch = 0;
                // if (!refresh_page) 
                draw_tab = 1;
                draw_page = 1;
                draw_page1();
                Serial.println("Draw 1");
                break;
            case 2:
                ch_page = true;
                item_to_ch = 0;
                if (!refresh_page) draw_tab = 2;
                draw_page = 2;
                // draw_page2();
                // Serial.println("Draw 2");
                break;
            case 3:
                ch_page = true;
                item_to_ch = 0;
                if (!refresh_page) draw_tab = 3;
                draw_page = 3;
                // draw_page3();
                // Serial.println("Draw 3");
                break;
            case 4:
                ch_page = true;
                item_to_ch = 0;
                if (!refresh_page) draw_tab = 4;
                draw_page = 4;
                // draw_page4();
                // Serial.println("Draw 4");
                break;
            case 5:
                ch_page = true;
                item_to_ch = 0;
                if (!refresh_page) draw_tab = 5;
                draw_page = 5;
                // draw_page5();
                // Serial.println("Draw 5");
                break;
            case 6:
                ch_page = true;
                item_to_ch = 0;
                if (!refresh_page) draw_tab = 6;
                draw_page = 6;
                // draw_page6();
                // Serial.println("Draw 6");
                break;                    
        }
    // }
    refresh_page = false;
    draw_tab = 7;
    draw_page = 7;
}