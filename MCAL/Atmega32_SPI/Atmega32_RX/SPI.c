/*
 * SPI.c
 *
 * Created: 8/29/2022 11:20:32 PM
 *  Author: Eng.Mohamed AbdAllah
 */ 
#include "SPI.h"

void SPI_init_master(void){
	SETBIT(DDRD,PIND7);
	SETBIT(DDRB,PINB5);
	CLRBIT(DDRB,PINB6);
	SETBIT(DDRB,PINB7);
	
	SETBIT(SPCR,SPR0);
	SETBIT(SPCR,SPR1);
	SETBIT(SPSR,SPI2X);
	
	SETBIT(SPCR,MSTR);
	SETBIT(SPCR,SPE);
	
	
}
void SPI_init_slave(void){
	CLRBIT(DDRD,PIND4);
	CLRBIT(DDRB,PINB5);
	SETBIT(DDRB,PINB6);
	CLRBIT(DDRB,PINB7);
	
	SETBIT(SPCR,SPR0);
	SETBIT(SPCR,SPR1);
	SETBIT(SPSR,SPI2X);
	
	CLRBIT(SPCR,MSTR);
	SETBIT(SPCR,SPE);
	
	
	
}
void SPI_mo(uint8_t data){
	SPDR = data;
	while(READBIT(SPSR,SPIF) == 0);
}
uint8_t SPI_si(void){
	while(READBIT(SPSR,SPIF) == 0);
	return SPDR;
}
uint8_t SPI_mo_mi(uint8_t data){
	SPDR = data;
	while(READBIT(SPSR,SPIF) == 0);
	return SPDR;
}