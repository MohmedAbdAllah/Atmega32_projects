/*
 * Atmega32_SEVEN_SEG.c
 *
 * Created: 8/16/2022 8:08:01 PM
 * Author : Eng.Mohamed AbdAllah
 */ 

#include "SEVEN_SEG.h"


int main(void)
{
    /* Replace with your application code */
	uint8_t x = 35;
	SEVEN_SEG_init();
    while (1) 
    {
		SEVEN_SEG_write_on2(x);
		//_delay_ms(100);
		//x++;
		//if(x > 99) x = 0;
    }
}

