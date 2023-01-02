/*
 * Atmega32_WD.c
 *
 * Created: 8/28/2022 7:20:53 PM
 * Author : Eng.Mohamed AbdAllah
 */ 

#include "WDT.h"


int main(void)
{
    /* Replace with your application code */
	SETBIT(DDRA,PINA7);
	
	
	
	
    while (1) 
    {
		WDT_on(3);
		_delay_ms(140);
		WDT_off();
		TOGBIT(PORTA,PINA7);
    }
}

