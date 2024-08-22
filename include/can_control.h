/**
Version: 0a
Tecnocoli - 08/2024
jcoli - Jeferson Coli - jcoli@tecnocoli.com.br    
STM32F103C8 - Grow Sensors
**/

#ifndef __CAN_CONTROL_H__
#define __CAN_CONTROL_H__
#include <Arduino.h>


void can_begin();
void can_read();
void can_write(uint64_t canTXId, int frame_type, int data_lenght, byte send_data[8]);



#endif