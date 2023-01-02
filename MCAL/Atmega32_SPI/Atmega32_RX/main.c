/*
 * Atmega32_RX.c
 *
 * Created: 8/30/2022 10:36:50 PM
 * Author : Eng.Mohamed AbdAllah
 */ 

#include "SPI.h"
#include "LCD.h"

int main(void)
{
	
	SPI_init_slave();
	LCD_init();
	while (1)
	{
		LCD_write_command(0x80);
		LCD_write_num(SPI_si());
		
	}
}