/**
Version: 0a
Tecnocoli - 04/2024
jcoli - Jeferson Coli - jcoli@tecnocoli.com.br
STM32F407VET6 - Grown
**/
#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <Adafruit_AHTX0.h>
#include "ScioSense_ENS160.h" 

#include "io_defines.h"
#include "defines.h"

Adafruit_BME280 bme; 
Adafruit_AHTX0 aht;
ScioSense_ENS160      ens160(ENS160_I2CADDR_0);

#define SEALEVELPRESSURE_HPA (1013.25)


void read_analog();
void analog_input_begin();
void read_analog_begin();
void printValues();


const float beta = 4200.0;
const float r0 = 100000.0;
const float t0 = 273.0 + 25.0;
const float rx = r0 * exp(-beta/t0);
const int nAmostras = 7;
const float vcc = 3.3;
const float R = 85000.0;




void analog_input_begin(){
    unsigned status;
    status = bme.begin();  

    if (!status) {
        Serial.println("Could not find a valid BME280 sensor, check wiring, address, sensor ID!");
        Serial.print("SensorID was: 0x"); Serial.println(bme.sensorID(),16);
        Serial.print("        ID of 0xFF probably means a bad address, a BMP 180 or BMP 085\n");
        Serial.print("   ID of 0x56-0x58 represents a BMP 280,\n");
        Serial.print("        ID of 0x60 represents a BME 280.\n");
        Serial.print("        ID of 0x61 represents a BME 680.\n");
        
    }

    bool ok = ens160.begin();
    Serial.println(ens160.available() ? "done." : "failed!");
    if (aht.begin()) {
        Serial.println("Found AHT20");
    } else {
        Serial.println("Didn't find AHT20");
    }  
    

}

void read_analog_begin(){
   
}

void read_analog(){
    
}

void printValues() {
    Serial.print("Temperature = ");
    Serial.print(bme.readTemperature());
    Serial.println(" °C");

    Serial.print("Pressure = ");

    Serial.print(bme.readPressure() / 100.0F);
    Serial.println(" hPa");

    Serial.print("Approx. Altitude = ");
    Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
    Serial.println(" m");

    Serial.print("Humidity = ");
    Serial.print(bme.readHumidity());
    Serial.println(" %");

    Serial.println();
}