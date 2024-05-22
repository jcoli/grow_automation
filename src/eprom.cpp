/**
Version: 0a
Tecnocoli - 04/2024
jcoli - Jeferson Coli - jcoli@tecnocoli.com.br
STM32F407VET6 - Grown
**/

#include <Arduino.h>
#include "winbondflash.h"


#include "display.h"
#include "defines.h"
#include "io_defines.h"
#include "tools.h"

void flash_begin();
void flash_write_page(uint32_t addr,uint8_t *buf);
void flash_write(uint32_t addr_start,uint8_t *buf, uint16_t n);
void flash_read(uint8_t *buf, uint32_t addr);
void flashwrite_test();
void flashwrite_test6();
void flashread_test();
void flashread_test6();
void flash_erase();


winbondFlashSPI mem;

bool first = true;

SPIClass spiToUse(PB4, PB5, PB3); 


void flash_begin() {
  
  // delay(5000);
  Serial.println("===============");
  Serial.println(mem.begin(_W25Q16,spiToUse,SS));
  if (mem.begin(_W25Q16,spiToUse,SS)){
     Serial.println("OK");
     Serial.println(mem.readPartID());
     Serial.println(mem.readUniqueID());
     Serial.println(mem.readManufacturer()); 
     Serial.println(mem.readSR());
  }
  else
  {
    // Serial.println("FAILED");
    
  }


}

void flash_erase(){
    while(mem.busy());
    mem.WE();
    mem.eraseAll();
    long ss = millis();
    while(mem.busy())
    {
      // Serial.print(millis()-ss);
      delay(100);
    }

}

void flash_write_page(uint32_t addr,uint8_t *buf){
    // Serial.println(("Write "));
    while(mem.busy());
    mem.WE();
    // Serial.println(("Write 2 "));
    mem.writePage(addr,buf);
    while(mem.busy())
    {
        // delay(200);
    }

}

void flash_write(uint32_t addr,uint8_t *buf, uint16_t size){
    // Serial.println(("Write "));
    // while(mem.busy());
    mem.WE();
    // Serial.println(("Write 2 "));
    mem.writebyte(addr,buf, size);
    while(mem.busy());
}

void flash_read(uint8_t *buf, uint32_t addr){
    // Serial.println(("Read "));
    uint16_t size = 256;
    char data[size];
    while(mem.busy());
    // Serial.println(("Read 1"));
    mem.read(addr,buf,size);
    int i = 0;
    int k = 0;
    int f = 0;
    // while(k != '\n' && i<size)   //Read until null character
    // {    
    // //   Serial.println(("Read "+i));
    //   k=(char)buf[i];
    //   data[i]=k;
    //     Serial.print((char)k);

    // //    Serial.println(i);
    //   i++;
      
    // }
    // Serial.println(("Read 2"));
    // Serial.println(String(data));
    uint8_t teste;
    // return buf;  


}

void flashwrite_test(){
        // Serial.println(("Write "));
        uint32_t addr = 5;
        // Serial.read();
        uint8_t buf[256];
        String tow = "IN05,0,0,0,RP01,RL Princ,I1,0,CI1,1,Rl Princ,Main Rl \n";
        int _size = 256;
        for(int i = 0; i<_size; i++){
          if ((char)tow[i] != '\n'){
            buf[i] = (char)tow[i];    
          }else{
            buf[i] = 0;  
          }  
          
        }
        // Serial.println((_size));
        while(mem.busy());
        
        mem.WE();
        // Serial.println(("Write 2 "));
        mem.writebyte(addr,buf, _size);
        
        // Serial.println(("OK"));
}
void flashwrite_test6(){
        // Serial.println(("Write "));
        uint32_t addr = 604;
        // Serial.read();
        uint8_t buf[256];
        String tow = "IN06,0,0,0,RP01,RL Princ,I1,0,CI1,1,Rl Princ,Main Rl \n";
        int _size = 256;
        for(int i = 0; i<_size; i++){
          if ((char)tow[i] != '\n'){
            buf[i] = (char)tow[i];    
          }else{
            buf[i] = 0;  
          }  
          
        }
        Serial.println((_size));
        while(mem.busy());
        
        mem.WE();
        Serial.println(("Write 2 "));
        mem.writebyte(addr,buf, _size);
        
        Serial.println(("OK"));
}

void flashread_test(){
    // Serial.println(("Read "));
    char data[256];
    uint32_t addr = 5;
    uint16_t len = 256;
    uint8_t *buf = new uint8_t[len];
    while(mem.busy());
    mem.read(addr,buf,len);
    // Serial.println(("read 1"));
    int i = 0;
    int k = 0;
    while(k != '\n' && i<len)   //Read until null character
    {    
      k=(char)buf[i];
      data[i]=k;
       Serial.print((char)data[i]);
       Serial.println(i);
      i++;
    }
    Serial.print(("read: "));
    for(int i = 0;i < len; i++)
    {
      Serial.print((char)buf[i]);
    }
   
    Serial.println(String(data));
    Serial.println(("OK"));

    delete [] buf;

}

void flashread_test6(){
    // Serial.println(("Read "));
    char data[256];
    uint32_t addr = 604;
    uint16_t len = 256;
    uint8_t *buf = new uint8_t[len];
    while(mem.busy());
    mem.read(addr,buf,len);
    Serial.println(("read 1"));
    int i = 0;
    int k = 0;
    while(k != '\n' && i<len)   //Read until null character
    {    
      k=(char)buf[i];
      data[i]=k;
      // Serial.print((char)data[i]);
      // Serial.println(i);
      i++;
    }
    Serial.print(("read: "));
    // for(int i = 0;i < len; i++)
    // {
    //   Serial.print((char)buf[i]);
    // }
    // Serial.println("");
    Serial.println(String(data));
    // Serial.println(("OK"));

    delete [] buf;

}

