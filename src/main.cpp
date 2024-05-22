/**
Version: 0a
Tecnocoli - 04/2024
jcoli - Jeferson Coli - jcoli@tecnocoli.com.br    
STM32F407VET6 - Grow Controller, Analysys and Monitoring
**/

#include <Arduino.h>
#include "stm32yyxx_ll_adc.h"
#include <SPI.h>
#include <TFT_eSPI.h>

#include "display.h"
#include "defines.h"
#include "io_defines.h"
#include "variables.h"
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
#include "buttons.h"
#include "eprom.h"

#include "disp_page0.h"

#define CALX_TEMP 25
#define V25       760
#define AVG_SLOPE 2500
#define VREFINT   1210

#define LL_ADC_RESOLUTION LL_ADC_RESOLUTION_12B
#define ADC_RANGE 4096


HardwareSerial WIFI_SERIAL(PA3, PA2);
HardwareSerial HC05_SERIAL(PC11, PC10); 

static int32_t readVref();
static int32_t readTempSensor(int32_t VRef);
void serialEvent();
void serialEvent2();
void serialEvent3();
void serialEventRun(void);


void serialEventRun(void)
{
  // #if defined(HAVE_HWSERIAL2)
    if (serialEvent2 && WIFI_SERIAL.available()) {
      serialEvent2();
     
    }
  // #endif
  // #if defined(USBCON)
    if (serialEvent && Serial.available()) {
      serialEvent();
    }
  // #endif
  // #if defined(HAVE_HWSERIAL3)  
    if (serialEvent3 && HC05_SERIAL.available()) {
      serialEvent3();
    }
  // #endif
}


// char version[8] = "1.0a";

void setup() {
  
  Serial.begin(115200); //PC
  WIFI_SERIAL.begin(38400); //Sim
  HC05_SERIAL.begin(38400); //Slave
  Serial.println("page0"); 

  analogReadResolution(12);
  delay(5000);
  display_begin();
  drawSplash();
  delay(1000);
  
  init_bt();
  delay(500);
  init_wifi();
  delay(3000);
  call_list_net();
  delay(5000);
  buttons_begin();
  flash_begin();
  // flashwrite_test6();
  flashread_test6();
  
  delay(1000); 
  tft_page = 0;
  ch_page = true;
  draw_tab = 0;
  draw_page = 0;
  draw_page0();
  Serial.println("page0"); 
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
}

void loop() {

  check_button();

  if (HC05_SERIAL.available()){
    serialEvent3();

  }
  if (millis() - loopDelay > 50000){
    loopDelay = millis();
    call_list_net();
    delay(5000);
    init_bt();
    // init_wifi();
    // WIFI_SERIAL.print("90,send,testwifi,4,#");
    // HC05_SERIAL.println("90,0,0,0,#");
    // HC05_SERIAL.print("AT+NAME");
    //  delay(2000);
    flashread_test6();
    VRef = readVref();
    intTemp = readTempSensor(VRef);
    ch_page = true;
    draw_tab = 0;
    draw_page = 0;
    draw_page0();
    
   
    Serial.println("loop"); 
   }
  if (millis() - loopDelay_analog > 400){ 
    loopDelay_analog = millis();
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    delay(100);
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH);
   
  } 
  
}

void serialEvent(){
  while(Serial.available()){
    char inChar = (char)Serial.read();
    line += inChar;
    if (inChar == '#'){
      stringComplete = true;
      // on_loop();
      Serial.println(line);
      HC05_SERIAL.print(line);
      
    }
    // Serial.println("SerialEvent + "+line);
  }
  if (stringComplete){
      Serial.println("SerialEvent + "+line);
      stringComplete = false;
      line = "";
      
    }
}

void serialEvent2(){
  // Serial.print("serial 1: ");
  while(WIFI_SERIAL.available()){
    
    char inChar = (char)WIFI_SERIAL.read();
    line1 += inChar;
    // Serial.println(line1);
    if (inChar == '#'){
      string1Complete = true;
      // on_loop();
      
    }

    if (string1Complete){
      // Serial.print("serial 2: ");
      // Serial.println(line1);
      on_wifi_comm();
      string1Complete = false;
      line1 = "";
      
    }
    
  }
 
  // Serial.println("SerialEvent2 + "+line1);
}

void serialEvent3(){
  // Serial.print("serial 3: ");
  while(HC05_SERIAL.available()){
    // Serial.println("serial 3-1: ");
    // Serial.println(line2);
    char inChar = (char)HC05_SERIAL.read();
    line2 += inChar;
    // Serial.println(line2);
    if (inChar == '#'){
      string2Complete = true;
    }
    if (string2Complete){
      // Serial.print("serial 3: ");
      // Serial.println(line2);
      on_bt_comm();
      string2Complete = false;
      line2 = "";

    }
  }
}


static int32_t readVref()
{
#ifdef __LL_ADC_CALC_VREFANALOG_VOLTAGE
#ifdef STM32U5xx
  return (__LL_ADC_CALC_VREFANALOG_VOLTAGE(ADC1, analogRead(AVREF), LL_ADC_RESOLUTION));
#else
  return (__LL_ADC_CALC_VREFANALOG_VOLTAGE(analogRead(AVREF), LL_ADC_RESOLUTION));
#endif
#else
  return (VREFINT * ADC_RANGE / analogRead(AVREF)); // ADC sample to mV
#endif
}

#ifdef ATEMP
static int32_t readTempSensor(int32_t VRef)
{
#ifdef __LL_ADC_CALC_TEMPERATURE
#ifdef STM32U5xx
  return (__LL_ADC_CALC_TEMPERATURE(ADC1, VRef, analogRead(ATEMP), LL_ADC_RESOLUTION));
#else
  return (__LL_ADC_CALC_TEMPERATURE(VRef, analogRead(ATEMP), LL_ADC_RESOLUTION));
#endif
#elif defined(__LL_ADC_CALC_TEMPERATURE_TYP_PARAMS)
  return (__LL_ADC_CALC_TEMPERATURE_TYP_PARAMS(AVG_SLOPE, V25, CALX_TEMP, VRef, analogRead(ATEMP), LL_ADC_RESOLUTION));
#else
  return 0;
#endif
}
#endif

static int32_t readVoltage(int32_t VRef, uint32_t pin)
{
#ifdef STM32U5xx
  return (__LL_ADC_CALC_DATA_TO_VOLTAGE(ADC1, VRef, analogRead(pin), LL_ADC_RESOLUTION));
#else
  return (__LL_ADC_CALC_DATA_TO_VOLTAGE(VRef, analogRead(pin), LL_ADC_RESOLUTION));
#endif
}