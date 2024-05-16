/**
Version: 0a
Tecnocoli - 04/2024
jcoli - Jeferson Coli - jcoli@tecnocoli.com.br
STM32F407VET6 - Grown
**/

#include <Arduino.h>
#include <SPIMemory.h>


#include "display.h"
#include "defines.h"
#include "io_defines.h"
#include "tools.h"

SPIFlash flash;

void spi_memory_begin();
void spi_memory_write(String strAddr, String inputString);
void spimemory_read(String strAddr, String outputString);

String strAddr;
String inputString;
String outputString;

void spi_memory_begin(){
    Serial.print("Unique ID: ");
    long _uniqueID = flash.getUniqueID();
    Serial.print("Unique ID: ");
        // if (_uniqueID) {
        //     Serial.print("Unique ID: ");
        //     Serial.print(uint32_t(_uniqueID / 1000000L));
        //     Serial.print(uint32_t(_uniqueID % 1000000L));
        //     Serial.print(", ");
        //     Serial.print("0x");
        //     Serial.print(uint32_t(_uniqueID >> 32), HEX);
        //     Serial.print(uint32_t(_uniqueID), HEX);
        // }


}


void spimemory_write(String strAddr, String inputString){

}

void spimemory_read(String strAddr, String outputString){

}