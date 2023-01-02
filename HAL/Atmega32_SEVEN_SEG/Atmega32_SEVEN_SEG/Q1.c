/*
 * Q1.c
 *
 * Created: 8/16/2022 10:44:53 PM
 *  Author: Eng.Mohamed AbdAllah
 */ 
#include "SEVEN_SEG.h"


int main(void)
{
	/* Replace with your application code */
	uint8_t x = 5;
	SEVEN_SEG_init();
	while (1)
	{
		SEVEN_SEG_write(x);
		//_delay_ms(100);
		//x++;
		//if(x > 99) x = 0;
	}
}
