/**
Version: 0a
Tecnocoli - 04/2024
jcoli - Jeferson Coli - jcoli@tecnocoli.com.br
STM32F407VET6 - Grown
**/
#include <Arduino.h>

#include "io_defines.h"
#include "defines.h"

void read_analog();
void analog_input_begin();
void read_analog_begin();


const float beta = 4200.0;
const float r0 = 100000.0;
const float t0 = 273.0 + 25.0;
const float rx = r0 * exp(-beta/t0);
const int nAmostras = 7;
const float vcc = 3.3;
const float R = 85000.0;




void analog_input_begin(){
    

}

void read_analog_begin(){
   
}

void read_analog(){
    
}