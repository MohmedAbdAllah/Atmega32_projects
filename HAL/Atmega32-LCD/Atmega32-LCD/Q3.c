/*
 * Atmega32-LCD.c
 *
 * Created: 8/12/2022 7:47:06 PM
 * Author : Eng.Mohamed AbdAllah
 */ 

#include "LCD.h"


int main(void)
{
    /* Replace with your application code */
	uint8_t incr = 0;
	LCD_init();

    while (1)
    { 
		LCD_write_command(0x80);
		LCD_write_num(incr);
		_delay_ms(300);
		incr++;
		if(incr == 256) incr = 0;
    }
}

