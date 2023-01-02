/*
 * LED_Blinking.c
 *
 * Created: 8/6/2022 12:11:29 AM
 * Author : Eng.Mohamed AbdAllah
 */ 

#include "LED_Blinking.h"



int main(void)
{

	// Insert code
	DDRA = 0x01;

	while(1){
		PORTA = 0X00;
		_delay_ms(500);
		PORTA = 0x01;
		_delay_ms(500);

	}

	return 0;
}

