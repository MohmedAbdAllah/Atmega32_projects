/*
 * Atmega32_TOGGLE_LED.c
 *
 * Created: 8/6/2022 10:04:44 PM
 * Author : Eng.Mohamed AbdAllah
 */ 

#include "TOGGLE_LED.h"


int main(void)
{
    /* Replace with your application code */
	uint8_t inc = 2;
	CLRBIT(DDRA,1);
	SETBIT(PORTA,1);
	
	SETBIT(DDRB,0);
	CLRBIT(PORTB,0);
	
    while (1) 
    {
		if((READBIT(PINA,1) == 0)&&(inc == 2)){
			SETBIT(PORTB,0);
			inc = 1;
			while(!READBIT(PINA,PINA1));
		}
		
		if((READBIT(PINA,1) == 0)&&(inc == 1)){
			CLRBIT(PORTB,0);
			inc = 2;
			while(!READBIT(PINA,PINA1));
		}
	}
}

