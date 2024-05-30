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


void ana_output_begin(){
    pinMode(FAN01, OUTPUT);
    pinMode(FAN02, OUTPUT);
    pinMode(FAN03, OUTPUT);
    pinMode(FAN04, OUTPUT);

    analogWriteResolution(12); 

    analogWriteFrequency(10000);

    analogWrite(FAN01, dutyCycle1);
    analogWrite(FAN02, dutyCycle2);
    analogWrite(FAN03, dutyCycle3);
    analogWrite(FAN04, dutyCycle4);

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