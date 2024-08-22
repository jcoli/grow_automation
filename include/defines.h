/**
Version: 0a
Tecnocoli - 04/2024
jcoli - Jeferson Coli - jcoli@tecnocoli.com.br
STM32F407VET6 - Grown
**/

#ifndef __DEFINES_H__
#define __DEFINES_H__

/* defines */
#define V03_MAX 3.6
#define V05_MAX 5.5
#define V12_MAX 14.5
#define V24_MAX 28.0

#define CALX_TEMP 25
#define V25       760
#define AVG_SLOPE 2500
#define VREFINT   1210

#define LL_ADC_RESOLUTION LL_ADC_RESOLUTION_12B
#define ADC_RANGE 4096

static const char version[] = "1.0a";
static const char develop[] =  "jcoli-Tecnocoli";
static const char email_develop[] = "jcoli@tecnocoli.com.br";
static const char processor[] = "STM32F407VET6";

#define TIMER_INTERVAL_0_1S           100L
#define TIMER_INTERVAL_0_3S           300L
#define TIMER_INTERVAL_1S             1000L
#define TIMER_INTERVAL_1_5S           1500L
#define TIMER_INTERRUPT_DEBUG         0
#define _TIMERINTERRUPT_LOGLEVEL_     0 
#define TIMER_INTERVAL_MS         100
#define HW_TIMER_INTERVAL_MS      50


#define WIFI_SERIAL Serial2
// #define HC05_SERIAL Serial3

#define SEALEVELPRESSURE_HPA (1013)

#define BROKER_ADDR  IPAddress(192,168,61,85)

#define BROKER_USERNAME     "mqtt_user" 
#define BROKER_PASSWORD     "shady55"
#define DEVICE_NAME "Grown"

#define LOCAL_IP IPAddress(192,168,61,115)
#define GATEWAY IPAddress(192, 168, 61, 1)
#define SUBNET IPAddress(255, 255, 255, 0)
#define LOCAL_SSID "IOT-2"
#define LOCAL_PASS "shady6565"

#define CANID 0xAA;

#define NUM_BUTTONS 17

#define channel_red
#define channel_blue
#define channel_grenn
#define channel_white_warn
#define channel_white_cold
#define channel_uv
#define channel_ir

#endif