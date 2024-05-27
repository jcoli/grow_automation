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
// ScioSense_ENS160      ens160(ENS160_I2CADDR_0);
ScioSense_ENS160      ens160(ENS160_I2CADDR_1);

#define SEALEVELPRESSURE_HPA (1013)


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

extern uint32_t subSec;
extern byte seconds;
extern byte minutes;
extern byte hours;
extern byte weekDay;
extern byte day;
extern byte month;
extern byte year;




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
        Serial.println("Could not find a valid BME2801 sensor, check wiring, address, sensor ID!");
        Serial.print("SensorID was: 0x"); Serial.println(bme1.sensorID(),16);
        Serial.print("        ID of 0xFF probably means a bad address, a BMP 180 or BMP 085\n");
        Serial.print("   ID of 0x56-0x58 represents a BMP 280,\n");
        Serial.print("        ID of 0x60 represents a BME 280.\n");
        Serial.print("        ID of 0x61 represents a BME 680.\n");
        
    }

    if (!status2) {
        Serial.println("Could not find a valid BME2802 sensor, check wiring, address, sensor ID!");
        Serial.print("SensorID was: 0x"); Serial.println(bme2.sensorID(),16);
        Serial.print("        ID of 0xFF probably means a bad address, a BMP 180 or BMP 085\n");
        Serial.print("   ID of 0x56-0x58 represents a BMP 280,\n");
        Serial.print("        ID of 0x60 represents a BME 280.\n");
        Serial.print("        ID of 0x61 represents a BME 680.\n");
        
    }

    bool ok = ens160.begin();

    Serial.println(ens160.available() ? "done." : "failed!");
    if (ens160.available()) {
        // Print ENS160 versions
        Serial.print("\tRev: "); Serial.print(ens160.getMajorRev());
        Serial.print("."); Serial.print(ens160.getMinorRev());
        Serial.print("."); Serial.println(ens160.getBuild());
    
        Serial.print("\tStandard mode ");
        Serial.println(ens160.setMode(ENS160_OPMODE_STD) ? "done." : "failed!");
        ens160.measure(true);
        ens160.measureRaw(true);
    }



    
    if (aht.begin()) {
        Serial.println("Found AHT20");
    } else {
        Serial.println("Didn't find AHT20");
    }  
    

}

void read_analog_begin(){
   
}

void read_analog(){

    // Serial.println("Read Analog");
    
    bme1_temp = bme1.readTemperature();
    bme1_hum = bme1.readHumidity();
    bme1_press = bme1.readPressure() / 100.0F;

    // bme2_temp = bme2.readTemperature();
    // bme2_hum = bme2.readHumidity();
    // bme2_press = bme2.readPressure() / 100.0F;

    // Serial.println("Read Analog1");

    sensors_event_t hum, temp;
    aht.getEvent(&hum, &temp);

    aht_temp = temp.temperature;
    aht_hum = hum.relative_humidity;

    int temp_aht = temp.temperature;
    int hum_aht = hum.relative_humidity;

    // Serial.println("Read Analog2");

    delay(1000);

    ens160.set_envdata(bme1_temp, bme1_hum);

    ens160.measure(true);
    ens160.measureRaw(true);

    // Serial.println("Read Analog3");

    ens_aqi = ens160.getAQI();
    ens_tvoc = ens160.getTVOC();
    ens_eco2 = ens160.geteCO2();

    // Serial.println("Read Analog4");

    // Serial.print("AQI: ");Serial.print(ens160.getAQI());Serial.print("\t");
    // Serial.print("TVOC: ");Serial.print(ens160.getTVOC());Serial.print("ppb\t");
    // Serial.print("eCO2: ");Serial.print(ens160.geteCO2());Serial.println("ppm\t");



    // HC05_SERIAL.print("AQI: ");HC05_SERIAL.print(ens160.getAQI());HC05_SERIAL.print("\t");
    // HC05_SERIAL.print("TVOC: ");HC05_SERIAL.print(ens160.getTVOC());HC05_SERIAL.print("ppb\t");
    // HC05_SERIAL.print("eCO2: ");HC05_SERIAL.print(ens160.geteCO2());HC05_SERIAL.println("ppm\t");

    // HC05_SERIAL.println("4,1,0,0,#");
    
   
    
}

void printValues() {

    Serial.printf("%02d/%02d/%02d ", day, month, year);
    Serial.printf("%02d:%02d\n", hours, minutes);

    HC05_SERIAL.printf("%02d/%02d/%02d ", day, month, year);
    HC05_SERIAL.printf("%02d:%02d\n", hours, minutes);

    Serial.print("Temperature = ");
    Serial.print(bme1_temp);
    Serial.println(" °C");
    Serial.print("Pressure = ");
    Serial.print(bme1_press);
    Serial.println(" hPa");
    // Serial.print("Approx. Altitude = ");
    // Serial.print(bme1_);
    // Serial.println(" m");

    Serial.print("Humidity = ");
    Serial.print(bme1_hum);
    Serial.println(" %");
    HC05_SERIAL.println("2,3,1,"+String(bme1_temp)+",#"); 
    HC05_SERIAL.println("2,3,2,"+String(bme1_hum)+",#"); 
    HC05_SERIAL.println("2,3,3,"+String(bme1_press)+",#"); 

    
    Serial.println("========");

    //  Serial.print("Temperature2 = ");
    // Serial.print(bme2.readTemperature());
    // Serial.println(" °C");

    // Serial.print("Pressure = ");

    // Serial.print(bme2.readPressure() / 100.0F);
    // Serial.println(" hPa");

    // Serial.print("Approx. Altitude = ");
    // Serial.print(bme2.readAltitude(SEALEVELPRESSURE_HPA));
    // Serial.println(" m");

    // Serial.print("Humidity = ");
    // Serial.print(bme2.readHumidity());
    // Serial.println(" %");

    Serial.println("AHT");

    Serial.print("Temperature: "); 
    Serial.println(aht_temp); 
    Serial.print("Humidity: "); 
    Serial.println(aht_hum); 

    Serial.print("AQI: ");
    Serial.println(ens_aqi);
    Serial.print("TVOC: ");
    Serial.println(ens_tvoc);
    Serial.print("eCO2: ");
    Serial.println(ens_eco2);

    Serial.println("===================");
    Serial.println("===================");

    
     
    HC05_SERIAL.println("2,1,1,"+String(aht_temp)+",#"); 
    HC05_SERIAL.println("2,1,2,"+String(aht_hum)+",#"); 
    
    HC05_SERIAL.println("2,2,1,"+String(ens_aqi)+",#"); 
    HC05_SERIAL.println("2,1,2,"+String(ens_tvoc)+",#"); 
    HC05_SERIAL.println("2,1,2,"+String(ens_eco2)+",#"); 
    
}