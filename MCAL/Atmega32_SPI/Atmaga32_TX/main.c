/*
 * Atmaga32_TX.c
 *
 * Created: 8/29/2022 9:38:11 PM
 * Author : Eng.Mohamed AbdAllah
 */ 

#include "SPI.h"
#include "LCD.h"

int main(void)
{
	uint8_t counter = 0;
	SETBIT(DDRD,PIND7);
	SPI_init_master();
	while (1)
	{	
		SETBIT(PORTB, PB4);
		CLRBIT(PORTD, PD7);
		SPI_mo(counter++);
		_delay_ms(100);
		CLRBIT(PORTB, PB4);
		SETBIT(PORTD, PD7);
		SPI_mo(counter++);
		_delay_ms(100);
		
		if(counter == 255) {counter = 0;LCD_init();}
		
	}
}