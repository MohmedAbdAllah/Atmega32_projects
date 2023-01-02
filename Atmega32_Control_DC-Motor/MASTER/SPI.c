/*
 * SPI.c
 *
 * Created: 8/29/2022 11:20:32 PM
 *  Author: Eng.Mohamed AbdAllah
 */ 
#include "SPI.h"

extern void (*SPI_stc_vect)(void);
/**************************************************************************
* Function Name: SPI_init_master
* Purpose      : Configure SPI port as a master
* Parameters   : void
* Return value : void
**************************************************************************/
void SPI_init_master(void){
	SETBIT(DDRB,PIND4);
	SETBIT(DDRB,PIND5);
	CLRBIT(DDRB,PIND6);
	SETBIT(DDRB,PIND7);
	
	//SETBIT(SPCR,SPR0);
	//SETBIT(SPCR,SPR1);
	//SETBIT(SPSR,SPI2X);
	
	//SETBIT(SPCR,MSTR);
	//SETBIT(SPCR,SPE);
	SPCR = 0x50;
	
	
}
/**************************************************************************
* Function Name: SPI_init_slave
* Purpose      : Configure SPI port as a master
* Parameters   : void
* Return value : void
**************************************************************************/
void SPI_init_slave(void){
	CLRBIT(DDRB,PIND4);
	CLRBIT(DDRB,PIND5);
	SETBIT(DDRB,PIND6);
	CLRBIT(DDRB,PIND7);
	
	//SETBIT(SPCR,SPR0);
	//SETBIT(SPCR,SPR1);
	//SETBIT(SPSR,SPI2X);
	
	//CLRBIT(SPCR,MSTR);
	SETBIT(SPCR,SPE);
	//SPCR = 0x50;
	/*SETBIT(SPCR,SPIE);
	SETBIT(SREG,7);// ENABLE GLOBAL INTERRUPT*/
}
/**************************************************************************
* Function Name: SPI_mo
* Purpose      : used to pass the master sending data
* Parameters   : data: data that the user want to send
* Return value : void
**************************************************************************/
void SPI_mo(uint8_t data){
	CLRBIT(PORTB,PIND4);
	SPDR = data;
	while(READBIT(SPSR,SPIF) == 0);
	SETBIT(PORTB,PIND4);
	
}
/**************************************************************************
* Function Name: SPI_si
* Purpose      : used to receive sent data from the master
* Parameters   : void
* Return value : void
**************************************************************************/
uint8_t SPI_si(void){
	while(READBIT(SPSR,SPIF) == 0);
	return SPDR;
}
/**************************************************************************
* Function Name: SPI_mo_mi
* Purpose      : the function used to send and receive data 
				 (to and from) the slave 
* Parameters   : void
* Return value : void
**************************************************************************/
uint8_t SPI_mo_mi(uint8_t data){
	CLRBIT(PORTB,PIND4);
	SPDR = data;
	while(READBIT(SPSR,SPIF) == 0);
	SETBIT(PORTB,PIND4);
	return SPDR;
}
ISR(SPI_STC_vect){
	SPI_stc_vect();
}