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
	/* SS ,Set MOSI and SCK output, all others input */
	SETBIT(DDRB,MOSI);
	SETBIT(DDRB,SCK);
	SETBIT(DDRB,PB4);
	/* Enable SPI, Master, set clock rate fck/16 */
	SETBIT(SPCR,SPR0);
	SETBIT(SPCR,MSTR);
	SETBIT(SPCR,SPE);
	
	
}
/**************************************************************************
* Function Name: SPI_init_slave
* Purpose      : Configure SPI port as a master
* Parameters   : void
* Return value : void
**************************************************************************/
void SPI_init_slave(void){
	/* Set MISO output, all others input */
	SETBIT(DDRB,PIND6);
	// ENABLE SPI
	SETBIT(SPCR,SPE);
	// ENABLE GLOBAL INTERRUPT
	SETBIT(SPCR,SPIE);
	SETBIT(SREG,7);
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