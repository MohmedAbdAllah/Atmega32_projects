/*
 * EEPROM.c
 *
 * Created: 8/13/2022 5:04:50 PM
 *  Author: Eng.Mohamed AbdAllah
 */ 
#include "EEPROM.h"


/**************************************************************************
* Function Name: EEPROM_read
* Purpose      : read data from EEPROM
* Parameters   : location: address of data you want to read
* Return value :void
**************************************************************************/
uint8_t EEPROM_read(uint16_t location){
	while(READBIT(EECR,EEWE)== 1);
	EEAR = location;
	SETBIT(EECR,EERE);
	return EEDR;
}

/**************************************************************************
* Function Name: EEPROM_write
* Purpose      : write data in EEPROM
* Parameters   : location: address where you want to write , 
				 data    : what you want to write
* Return value :void
**************************************************************************/
void EEPROM_write(uint16_t location ,uint16_t data){
	while(READBIT(EECR,EEWE)== 1);
	EEAR = location;
	EEDR = data;
	if(READBIT(SREG,7)){
		CLRBIT(SREG,7);
		SETBIT(EECR,EEMWE);
		SETBIT(EECR,EEWE);
		SETBIT(SREG,7);
	}else{
		SETBIT(EECR,EEMWE);
		SETBIT(EECR,EEWE);
	}
}