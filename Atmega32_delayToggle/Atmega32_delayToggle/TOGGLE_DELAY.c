/*
 * Atmega32_delayToggle.c
 *
 * Created: 8/8/2022 7:27:44 PM
 * Author : Eng.Mohamed AbdAllah
 */ 

#include "TOGGLE_DELAY.h"


int main(void)
{
    /* Replace with your application code */
	uint8_t inc = 0;
	CLRBIT(DDRA,1);
	SETBIT(PORTA,1);
	
	SETBIT(DDRB,0);
	CLRBIT(PORTB,0);
	
	while (1)
	{
		if((READBIT(PINA,1) == 0)&&(inc == 0)){
			SETBIT(PORTB,0);
			_delay_ms(100);
			CLRBIT(PORTB,0);
			inc = 1;
		}
		else if((READBIT(PINA,1) == 1)&&(inc == 1)){
			inc = 2;
		}
		
		else if((READBIT(PINA,1) == 0)&&(inc == 2)){
			SETBIT(PORTB,0);
			_delay_ms(500);
			CLRBIT(PORTB,0);
			inc = 3;
		}
		else if((READBIT(PINA,1) == 1)&&(inc == 3)){
			inc = 0;
		}
	}
}

