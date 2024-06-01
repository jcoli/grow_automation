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
    digitalWrite(LED02, HIGH);
    digitalWrite(LED03, HIGH);
    digitalWrite(LED04, HIGH);
    digitalWrite(LED05, HIGH);
    digitalWrite(LED06, HIGH);

    delay(500);
    digitalWrite(LED01, LOW);
    digitalWrite(LED02, LOW);
    digitalWrite(LED03, LOW);
    digitalWrite(LED04, LOW);
    digitalWrite(LED05, LOW);
    digitalWrite(LED06, LOW);
}
