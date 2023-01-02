/*
 * Communication Project.c
 *
 * Created: 11/29/2022 9:44:22 PM
 * Author : Eng.Mohamed AbdAllah
 */ 

#include "MASTER.h"


int main(void)
{
	CLRBIT(DDRA,PINA0);
	SETBIT(PORTA,PINA0);
	//Initialize SPI peripheral.
	SPI_init_master();
	I2C_master_init();
	ADC_init();
	volatile uint8_t Speed = EEPROM_read(50);
	volatile uint8_t temp = 0;
    while (1) 
    {
		temp = (ADC_read(0)*100/206) + 1;
	
		//send data to slave
		if((temp > 35)&&(temp <= 50)){
			Speed = (((temp-35) * 50)/15) + 50;;
			EEPROM_write(50,Speed);
			SPI_mo(Speed);
		}else if(temp > 50){

			I2C_master_start();
			I2C_master_addr(50,0);
			I2C_slave_write(0xFF);
			I2C_master_stop();
			//_delay_ms(400);
		}
		I2C_master_start();
		I2C_master_addr(50,0);
		I2C_slave_write(0);
		I2C_master_stop();
		_delay_ms(10);
		
    }
}

