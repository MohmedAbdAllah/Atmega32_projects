/*
 * I2C.c
 *
 * Created: 9/1/2022 6:51:01 PM
 *  Author: Eng.Mohamed AbdAllah
 */ 
#include "I2C.h"
/**************************************************************************
* Function Name: I2C_master_init
* Purpose      : Configure I2C transmit speed
* Parameters   : void
* Return value : void
**************************************************************************/
void I2C_master_init(void){
	TWBR = TWBR_VAL;
}
/**************************************************************************
* Function Name: I2C_master_start
* Purpose      : Send start condition
* Parameters   : void
* Return value : 0 if the start condition and ack received else return 1
**************************************************************************/
uint8_t I2C_master_start(void){
	
	// transmit START condition
	TWCR |= 1<<TWINT | 1<<TWSTA | 1<<TWEN;
	// wait for end of transmission
	while(READBIT(TWCR,TWINT) == 0);
	if((TWSR & 0xF8) != 0x08) return 0;
	else return 1;
}
/**************************************************************************
* Function Name: I2C_master_addr
* Purpose      : choose the slave which will receive data or will send data
* Parameters   : ID : slave ID
				 RW : receive or transmit
* Return value : the (TWSR&0xF8) of the condition.
**************************************************************************/
uint8_t I2C_master_addr(uint8_t ID ,uint8_t RW){

	TWDR = ID<<1;
	//choose between tr or re
	if(RW == 1) SETBIT(TWDR, 0);
	else CLRBIT(TWDR, 0);
	//transmit data
	TWCR |= 1<<TWINT | 1<<TWEN;
	// wait for end of transmission
	while(READBIT(TWCR,TWINT) == 0);
	
	if(((TWSR&0xF8) == 0x40)||((TWSR&0xF8) == 0x18))return 0;
	else if(((TWSR&0xF8) == 0x48)||((TWSR&0xF8) == 0x20)) return 1;
	else return 2;
}
/**************************************************************************
* Function Name: I2C_master_write
* Purpose      : Set transmit data
* Parameters   : data:transmit data
* Return value : void
**************************************************************************/
uint8_t I2C_master_write(uint8_t data){
	
	// set transmit data in TW data register
	TWDR = data;
	// start transmission of data
	TWCR |= 1<<TWINT | 1<<TWEN;
	// wait for end of transmission
	while(READBIT(TWCR,TWINT) == 0);
	if((TWSR&0xF8) == 0x28) return 0;
	else if((TWSR&0xF8) == 0x30) return 1;
	else return 2;
}
/**************************************************************************
* Function Name: I2C_master_read
* Purpose      : receiving data
* Parameters   : void
* Return value : return receiving data
**************************************************************************/
uint8_t I2C_master_read(void){
	
	// start transmission of data
	TWCR |= 1<<TWINT | 1<<TWEN | 1<<TWEA;
	// wait for end of receiving
	while(READBIT(TWCR,TWINT) == 0);
	return TWDR;
}
/**************************************************************************
* Function Name: I2C_master_stop
* Purpose      : transmit STOP condition 
* Parameters   : void
* Return value : void
**************************************************************************/
void I2C_master_stop(void){
	//// transmit STOP condition
	TWCR |= 1<<TWINT | 1<<TWSTO | 1<<TWEN;
	while(READBIT(TWCR,TWSTO) == 1);
}
/**************************************************************************
* Function Name: I2C_slave_init
* Purpose      : put the slave ID
* Parameters   : My_ID : the slave ID
* Return value : void
**************************************************************************/
void I2C_slave_init(uint8_t My_ID){
	TWAR = My_ID<<1;
	
}
/**************************************************************************
* Function Name: I2C_slave_available
* Purpose      : check if slave available or not
* Parameters   : void
* Return value : return acknowledge
**************************************************************************/
uint8_t I2C_slave_available(void){
	//Enable TWI and enable ack.
	TWCR |= 1<<TWEA | 1<<TWEN | 1<<TWINT;
	while(READBIT(TWCR,TWINT) == 0);
	if(((TWSR&0xF8)==0x60)||((TWSR&0xF8)==0x68))	/* Own SLA+W received &ack returned */
		return 0;			/* Return 0 to indicate ack returned */
	if(((TWSR&0xF8)==0xA8)||((TWSR&0xF8)==0xB0))	/* Own SLA+R received &ack returned */
		return 1;			/* Return 0 to indicate ack returned */
	if(((TWSR&0xF8)==0x70)||((TWSR&0xF8)==0x78))	/* General call received &ack returned */
		return 2;
	else
		return 3;
}
/**************************************************************************
* Function Name: I2C_slave_read
* Purpose      : read transmit data
* Parameters   : void
* Return value : return receive data
**************************************************************************/
uint8_t I2C_slave_read(void){
	TWCR=(1<<TWEN)|(1<<TWEA)|(1<<TWINT);
	while(READBIT(TWCR,TWINT) == 0);
	if(((TWSR&0xF8)==0x80)||((TWSR&0xF8)==0x90))/* Check for data received &ack returned */
		return TWDR;		/* If yes then return received data */
	else return 0;
}
/**************************************************************************
* Function Name: I2C_slave_write
* Purpose      : send data
* Parameters   : data:transmit data
* Return value : void
**************************************************************************/
uint8_t I2C_slave_write(uint8_t data){
	TWDR = data;
	TWCR=(1<<TWEN)|(1<<TWINT)|(1<<TWEA);
	while(READBIT(TWCR,TWINT) == 0);
	if((TWSR&0xF8)==0xB8)		/* Check for data transmitted &ack received */
    	return 0;			/* Return 0 to indicate ack received */
    if((TWSR&0xF8)==0xC0)		/* Check for data transmitted &nack received */
    	return 1;			/* Return 1 to indicate nack received */
	if((TWSR&0xF8)==0xC8)   /* Last byte transmitted with ack received */
		return 2;
    else
    	return 3;
}