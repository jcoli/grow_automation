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

Adafruit_BME280 bme1; 
Adafruit_BME280 bme2; 
Adafruit_AHTX0 aht;
ScioSense_ENS160      ens160(ENS160_I2CADDR_0);

#define SEALEVELPRESSURE_HPA (1013.25)


void read_analog();
void analog_input_begin();
void read_analog_begin();
void printValues();

extern float ens_aqi;
extern float ens_tvoc;
extern float ens_eco2;
extern float aht_hum;
extern float aht_temp;
extern float bme1_temp;
extern float bme1_hum;
extern float bme1_press;
extern float bme2_temp;
extern float bme2_hum;
extern float bme2_press;

extern const float beta;
extern const float r0;
extern const float t0;
extern const float rx;
extern const int nAmostras;
extern const float vcc;
extern const float R;




void analog_input_begin(){
    unsigned status1;
    unsigned status2;
    status1 = bme1.begin(0x77, &Wire);  
    status2 = bme2.begin(0x76, &Wire);  
    //The 7-bit device address is 111011x. The 6 MSB bits are fixed. The last bit is changeable by SDO value and can be changed during operation. 
    //Connecting SDO to GND results in slave address 1110110 (0x76); connection it to VDDIOresults in slaveaddress 1110111 (0x77)
    //The I²C interface uses the following pins:
    //SCK:serial clock (SCL) 
    //SDI:data (SDA)
    //SDO:Slave address LSB (GND = ‘0’, VDDIO= ‘1’)

    if (!status1) {
        Serial.println("Could not find a valid BME280 sensor, check wiring, address, sensor ID!");
        Serial.print("SensorID was: 0x"); Serial.println(bme1.sensorID(),16);
        Serial.print("        ID of 0xFF probably means a bad address, a BMP 180 or BMP 085\n");
        Serial.print("   ID of 0x56-0x58 represents a BMP 280,\n");
        Serial.print("        ID of 0x60 represents a BME 280.\n");
        Serial.print("        ID of 0x61 represents a BME 680.\n");
        
    }

    if (!status2) {
        Serial.println("Could not find a valid BME280 sensor, check wiring, address, sensor ID!");
        Serial.print("SensorID was: 0x"); Serial.println(bme2.sensorID(),16);
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
    Serial.print(bme1.readTemperature());
    Serial.println(" °C");

    Serial.print("Pressure = ");

    Serial.print(bme1.readPressure() / 100.0F);
    Serial.println(" hPa");

    Serial.print("Approx. Altitude = ");
    Serial.print(bme1.readAltitude(SEALEVELPRESSURE_HPA));
    Serial.println(" m");

    Serial.print("Humidity = ");
    Serial.print(bme1.readHumidity());
    Serial.println(" %");

    Serial.println();
}