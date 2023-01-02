/*
 * SPI.h
 *
 * Created: 8/29/2022 11:20:54 PM
 *  Author: Eng.Mohamed AbdAllah
 */ 


#ifndef SPI_H_
#define SPI_H_

#include "std_macros.h"


void SPI_init_master(void);
void SPI_init_slave(void);
void SPI_mo(uint8_t data);
uint8_t SPI_si(void);
uint8_t SPI_mo_mi(uint8_t);

void (*SPI_stc_vect)(void);


#endif /* SPI_H_ */