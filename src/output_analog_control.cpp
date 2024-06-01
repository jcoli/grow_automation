/**
Version: 0a
Tecnocoli - 04/2024
jcoli - Jeferson Coli - jcoli@tecnocoli.com.br
STM32F407VET6 - Grown
**/
#include <Arduino.h>

#include "io_defines.h"
#include "defines.h"
#include "display.h"

void ana_output_begin();


extern int dutyCycle1;
extern int dutyCycle2;
extern int dutyCycle3;
extern int dutyCycle4;

// HardwareTimer *tim5 = new HardwareTimer(TIM5);


void ana_output_begin(){
    pinMode(FAN01, OUTPUT);
    // pinMode(FAN02, OUTPUT);
    // pinMode(FAN03, OUTPUT);
    // pinMode(FAN04, OUTPUT);

    // analogWriteResolution(12); 

    // analogWriteFrequency(10000);

    // analogWrite(FAN01, dutyCycle1);
    // analogWrite(FAN02, dutyCycle2);
    // analogWrite(FAN03, dutyCycle3);
    // analogWrite(FAN04, dutyCycle4);

    // TIM_TypeDef *Instance1 = (TIM_TypeDef *)pinmap_peripheral(digitalPinToPinName(FAN01), PinMap_PWM);
    // TIM_TypeDef *Instance2 = (TIM_TypeDef *)pinmap_peripheral(digitalPinToPinName(FAN02), PinMap_PWM);
    // // TIM_TypeDef *Instance3 = (TIM_TypeDef *)pinmap_peripheral(digitalPinToPinName(FAN03), PinMap_PWM);
    // // TIM_TypeDef *Instance4 = (TIM_TypeDef *)pinmap_peripheral(digitalPinToPinName(FAN04), PinMap_PWM);

    // uint32_t channel1 = STM_PIN_CHANNEL(pinmap_function(digitalPinToPinName(FAN01), PinMap_PWM));
    // uint32_t channel2 = STM_PIN_CHANNEL(pinmap_function(digitalPinToPinName(FAN01), PinMap_PWM));
    // // uint32_t channel3 = STM_PIN_CHANNEL(pinmap_function(digitalPinToPinName(FAN01), PinMap_PWM));
    // // uint32_t channel4 = STM_PIN_CHANNEL(pinmap_function(digitalPinToPinName(FAN01), PinMap_PWM));

    // HardwareTimer *Tim1 = new HardwareTimer(Instance1);
    // HardwareTimer *Tim2 = new HardwareTimer(Instance2);
    // // HardwareTimer *Tim3 = new HardwareTimer(Instance3);
    // // HardwareTimer *Tim4 = new HardwareTimer(Instance4);

    // Tim1->setPWM(channel1, FAN01, 10000, 30);
    // Tim2->setPWM(channel2, FAN02, 10000, 20);
    // // Tim1->setPWM(channel3, FAN03, 10000, 30);
    // // Tim1->setPWM(channel4, FAN04, 10000, 40);

    // Tim1->resume();
    // Tim2->resume();

    // tim5->setMode(1, TIMER_OUTPUT_COMPARE_PWM1, FAN01);
    // // tim5->setMode(2, TIMER_OUTPUT_COMPARE_PWM2, FAN02);
    // // tim4->setMode(3, TIMER_OUTPUT_COMPARE_PWM2, FAN03);
    // // tim4->setMode(4, TIMER_OUTPUT_COMPARE_PWM2, FAN04);

    // tim5->setOverflow(1000, HERTZ_FORMAT);
    // tim5->setCaptureCompare(1, 30, RESOLUTION_12B_COMPARE_FORMAT); 
    // tim5->
    // // tim5->setCaptureCompare(2, 60, RESOLUTION_12B_COMPARE_FORMAT); 
    // // tim4->setCaptureCompare(3, 20, RESOLUTION_12B_COMPARE_FORMAT); 
    // // tim4->setCaptureCompare(4, 90, RESOLUTION_12B_COMPARE_FORMAT); 
    // tim5->resume();

    TIM_TypeDef *Instance = (TIM_TypeDef *)pinmap_peripheral(digitalPinToPinName(FAN01), PinMap_PWM);
    uint32_t channel = STM_PIN_CHANNEL(pinmap_function(digitalPinToPinName(FAN01), PinMap_PWM));
    uint32_t channel1 = STM_PIN_CHANNEL(pinmap_function(digitalPinToPinName(FAN02), PinMap_PWM));
    uint32_t channel2 = STM_PIN_CHANNEL(pinmap_function(digitalPinToPinName(FAN03), PinMap_PWM));
    uint32_t channel3 = STM_PIN_CHANNEL(pinmap_function(digitalPinToPinName(FAN04), PinMap_PWM));

    HardwareTimer *Tim5 = new HardwareTimer(Instance);
    Tim5->setPWM(channel, FAN01, 10000, 50);
    Tim5->setPWM(channel1, FAN02, 10000, 30);
    Tim5->setPWM(channel2, FAN03, 10000, 30);
    Tim5->setPWM(channel3, FAN04, 10000, 10);
    Tim5->resume();





}

void setPWM(int pwmChannel){
    switch (pwmChannel) {
        
        case 1:
          Serial.println("pwm1");
          analogWrite(FAN01, dutyCycle1);
          break;
        case 2:
          Serial.println("pwm2");
          analogWrite(FAN02, dutyCycle2);
          break;
        case 3:
          Serial.println("pwm3");
          analogWrite(FAN03, dutyCycle3);
          break;
        case 4:
          Serial.println("pwm4");
          analogWrite(FAN04, dutyCycle4);
          break;  
    }    

}