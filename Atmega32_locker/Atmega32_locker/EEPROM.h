/*
 * EEPROM.h
 *
 * Created: 8/13/2022 5:05:09 PM
 *  Author: Eng.Mohamed AbdAllah
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

#include "std_macros.h"
//read data from EEPROM
uint8_t EEPROM_read(uint16_t location);

//write data in EEPROM 
void EEPROM_write(uint16_t location ,uint8_t data);


#endif /* EEPROM_H_ */