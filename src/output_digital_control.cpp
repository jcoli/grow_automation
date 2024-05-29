/**
Version: 0a
Tecnocoli - 11/2023
jcoli - Jeferson Coli - jcoli@tecnocoli.com.br
Pipicow - Clothes Dryer
**/
#include <Arduino.h>
#include <ArduinoHA.h> //MQTT

#include "io_defines.h"
#include "defines.h"
#include "display.h"
#include "sounds.h"
#include "input_digital_control.h"

void io_output_begin();

void io_output_begin(){
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    pinMode(LED01, OUTPUT);
    pinMode(LED02, OUTPUT);
    pinMode(LED03, OUTPUT);
    pinMode(LED04, OUTPUT);
    pinMode(LED05, OUTPUT);
    pinMode(LED06, OUTPUT);

    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);

    digitalWrite(LED01, HIGH);
    delay(300);
    digitalWrite(LED02, HIGH);
    delay(300);
    digitalWrite(LED03, HIGH);
    delay(300);
    digitalWrite(LED04, HIGH);
    delay(300);
    digitalWrite(LED05, HIGH);
    delay(300);
    digitalWrite(LED06, HIGH);

    delay(500);
    digitalWrite(LED01, LOW);
    delay(300);
    digitalWrite(LED02, LOW);
    delay(300);
    digitalWrite(LED03, LOW);
    delay(300);
    digitalWrite(LED04, LOW);
    delay(300);
    digitalWrite(LED05, LOW);
    delay(300);
    digitalWrite(LED06, LOW);
    
    

}
