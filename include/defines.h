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
#define HC05_SERIAL Serial3


#define BROKER_ADDR  IPAddress(192,168,61,85)
#define BROKER_USERNAME     "mqtt_user" 
#define BROKER_PASSWORD     "shady55"
#define DEVICE_NAME "Grown"

#define LOCAL_IP IPAddress(192,168,61,115)
#define GATEWAY IPAddress(192, 168, 61, 1)
#define SUBNET IPAddress(255, 255, 255, 0)
#define LOCAL_SSID "Area51"
#define LOCAL_PASS "shady6565"

#define NUM_BUTTONS 15

#endif