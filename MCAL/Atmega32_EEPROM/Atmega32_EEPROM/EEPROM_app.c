/*
 * Atmega32-LCD.c
 *
 * Created: 8/12/2022 7:47:06 PM
 * Author : Eng.Mohamed AbdAllah
 */ 

#include "LCD.h"
#include "EEPROM.h"

int main(void)
{
    /* Replace with your application code */
	//EEPROM_write(100,0);
	uint8_t incr = EEPROM_read(100);
	LCD_init();

    while (1)
    { 
		LCD_write_command(0x80);
		LCD_write_num(incr);
		EEPROM_write(100,incr);
		incr++;
		_delay_ms(300);
		if(incr == 256) incr = 0;
    }
}

