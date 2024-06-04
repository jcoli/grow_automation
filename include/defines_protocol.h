/**
Version: 0a
Tecnocoli - 06/2024
jcoli - Jeferson Coli - jcoli@tecnocoli.com.br
STM32F407VET6 - Grown
**/

#ifndef __DEFINES_H__
#define __DEFINES_H__

//Devices
#define PRINCIPAL 0
#define WIFI 1
#define BLUETOOTH 2
#define HOMEASSISTANT 3
#define APP_BLUETOOTH 4  

//SubDevices
#define TOP_INT_SENSOR 0
#define LOW_INT_SENSOR 1
#define EXT_SENSOR 2
#define FAN 3
#define EXHAUST 4
#define ROOTER 5
#define HUMIDIFIER 6
#define DEHUMIDIFIER 7
#define WATERING 8
#define FERTILIZER 9
#define PER_PUMP 10

//Function
#define DIG_INP 0
#define ANA_INP 1
#define DIG_OUT 2
#define ANA_INP 3
#define CREDENTIALS 4
#define ON_TIME 5
#define ON_INTENSITY 6

//sUBFunction
#define STATUS 0
#define TEMP 1
#define HUM 2
#define PRESSURE 3
#define CO2 4
#define PWM 5
#define CONNECTED 6
#define SOIL_MOISTURE 7
#define WATER_PH 8
#define SOIL_PH 9
#define PPFD 10
#define TEXT 11



#endif