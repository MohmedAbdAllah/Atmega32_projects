/*
 * Atmega32_LED_EIB.c
 *
 * Created: 8/8/2022 11:09:45 PM
 * Author : Eng.Mohamed AbdAllah
 */ 

#include "LED_EIB.h"
uint8_t inc = 0;

int main(void)
{
    /* Replace with your application code */
	
	// Configure External Interrupt INT0
	SETBIT(SREG, 7);
	SETBIT(GICR, 6);
	
	// Enable falling Edge at INT0
	CLRBIT(MCUCR, 0);
	SETBIT(MCUCR, 1);
	
	//Making PD2(INT0) input pull up
	CLRBIT(DDRD, 2);
	SETBIT(PORTD, 2);
	//Making PB0 output
	SETBIT(DDRB, 0);
	
    while (1) 
    {
		TOGBIT(PORTB,0);
		
		if(inc == 1){
			_delay_ms(100);
		}
		
		if((inc == 2)){
			_delay_ms(500);
		}
		
    }
}


ISR(INT0_vect){
	inc ++;
	if(inc == 3) inc = 1;
}
