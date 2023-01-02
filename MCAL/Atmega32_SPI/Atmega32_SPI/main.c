/*
 * Atmega32_SPI.c
 *
 * Created: 8/29/2022 11:19:53 PM
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