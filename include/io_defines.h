/**
Version: 0a
Tecnocoli - 04/2024
jcoli - Jeferson Coli - jcoli@tecnocoli.com.br
STM32F407VET6 - Grown
**/

#ifndef __IO_DEFINES_H__
#define __IO_DEFINES_H__

// TFT Display
// #define TFT_SPI_PORT 2 
// #define TFT_MOSI PB15
// #define TFT_MISO PB14
// #define TFT_SCLK PB13
// #define TFT_CS   PB12 
// #define TFT_DC   PC5  
// #define TFT_RST  PB11 

//EPROM WINBOND W25Q16BV
// #define EP_CS   PA15
// #define EP_DO   PB4
// #define EP_DI   PB5
// #define EP_CLK  PB3

//I2C1
// #define SDA1 PB9
// #define SCL1 PB8

//I2C2
// #define SDA2 PF0
// #define SCL2 PF1

//WiFi
// WIFI_SERIAL(PD6, PD5);

//BlueTooth HC-05
// HC05_SERIAL(PD9, PD8); 
// #define BT_EN   PD10
// #define BT_ST   PD11

//Buttons
#define BT_01   PE2
#define BT_02   PE3
#define BT_03   PE4
#define BT_04   PE5

//Switches
#define SW_01   PC13
#define SW_02   PE6
#define SW_03   PC1
#define SW_04   PC0

// Directional Buttons
#define BD_0 PD7 //direcional >>
#define BD_1 PD6 //direcional||
#define BD_2 PD5 //direcional ^^
#define BD_3 PD4 //direcional center
#define BD_4 PD3 //direcional<<

//Encoder 1
#define ENC1_DT PE8
#define ENC1_CLK PE7
#define BTE_1  PE9

//Encoder 1
#define ENC2_DT PE10
#define ENC2_CLK PE12
#define BTE_2  PE11

//Potentiometers
#define PT_1  PE14
#define PT_2  PE15

//I2C
#define SDA1    PB7
#define SCL1    PB6
#define SDA2    PC9
#define SCL2    PA8 

//
#define BUZZER_PIN PB0
#define LED1    PF9
#define LED2    PF10

#endif