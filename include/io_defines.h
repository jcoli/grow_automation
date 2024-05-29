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
#define BT_01   PE14
#define BT_02   PE15
#define BT_03   PE12
#define BT_04   PE13

//Switches
#define SW_01   PE10
#define SW_02   PE11
#define SW_03   PE8
#define SW_04   PE9

//display buttons
#define DP_01   PB10
#define DP_02   PB11


// Directional Buttons
#define BD_0 PG1 //direcional >>
#define BD_1 PE7 //direcional||
#define BD_2 PG0 //direcional ^^
#define BD_3 PF13 //direcional center
#define BD_4 PF14//direcional<<

//

//Encoder 0
#define ENC1_DT PE1
#define ENC1_CLK PE0
#define BTE_1  PE3

//Encoder 1
#define ENC2_DT PE2
#define ENC2_CLK PE5
#define BTE_2  PE4

//Potentiometers
#define PT_1  PC0
#define PT_2  PC1

//DHT
// #define DHT_1 PB7

//I2C
#define SDA1    PB7
#define SCL1    PB6
// #define SDA2    PC9
// #define SCL2    PA8 

//
#define BUZZER_PIN PB0
#define LED1    PF9
#define LED2    PF10

#define LED01   PF2
#define LED02   PF3
#define LED03   PF4
#define LED04   PF5
#define LED05   PF6
#define LED06   PF7

#endif