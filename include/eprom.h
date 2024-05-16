/**
Version: 0a
Tecnocoli - 04/2024
jcoli - Jeferson Coli - jcoli@tecnocoli.com.br
STM32F407VET6 - Grown
**/

#ifndef __EPROM_H__
#define __EPROM_H__

#include <Arduino.h>

void spi_memory_begin();
void spi_memory_write(String strAddr, String inputString);
void spimemory_read(String strAddr, String outputString);

#endif