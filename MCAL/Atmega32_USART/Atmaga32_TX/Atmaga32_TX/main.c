/*
 * Atmaga32_TX.c
 *
 * Created: 8/29/2022 9:38:11 PM
 * Author : Eng.Mohamed AbdAllah
 */ 

#include "USART.h"


int main(void)
{
	USART_init();

	uint8_t x = 0;
	while (1)
	{
		USART_tx(x++);
		if(x == 255) x =0;
		_delay_ms(200);
	}
}

