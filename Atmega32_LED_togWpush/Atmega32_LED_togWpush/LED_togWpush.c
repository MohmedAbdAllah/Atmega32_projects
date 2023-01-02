/*
 * Atmega32_LED_togWpush.c
 *
 * Created: 8/9/2022 12:33:27 AM
 * Author : Eng.Mohamed AbdAllah
 */ 

#include "LED_togWpush.h"


int main(void)
{
    /* Replace with your application code */
	// Configure External Interrupt INT0
	SETBIT(SREG, 7);
	SETBIT(GICR, 6);
	
	// Enable falling Edge at INT0
	SETBIT(MCUCR, 0);
	CLRBIT(MCUCR, 1);
	
	//Making PD2(INT0) input pull up
	CLRBIT(DDRD, 2);
	SETBIT(PORTD, 2);
	//Making PB0 output
	SETBIT(DDRB, 0);
	
	
	while (1)
	{
		
	}
}


ISR(INT0_vect){
	TOGBIT(PORTB,0);
}


