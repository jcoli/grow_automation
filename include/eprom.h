/**
Version: 0a
Tecnocoli - 04/2024
jcoli - Jeferson Coli - jcoli@tecnocoli.com.br
STM32F407VET6 - Grown
**/

#ifndef __EPROM_H__
#define __EPROM_H__

#include <Arduino.h>

void flash_begin();
void flash_write_page(uint32_t addr,uint8_t *buf);
void flash_write(uint32_t addr_start,uint8_t *buf, uint16_t n);
void flash_read(uint8_t *buf, uint32_t addr);
void flashwrite_test();
void flashwrite_test6();
void flashread_test();
void flashread_test6();
void flash_erase();

#endif