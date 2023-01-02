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
	
	
	uint8_t* pos_ptr = 0;
	uint8_t arr[] = "mohamed" ;
	uint8_t x = 0x80;
	pos_ptr = &x;
	LCD_init();
    while (1) 
    { 
		LCD_shift_str(arr ,7,pos_ptr);
	}
}

