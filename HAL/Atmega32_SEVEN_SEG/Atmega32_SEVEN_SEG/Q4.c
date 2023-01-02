/*
 * Q3.c
 *
 * Created: 8/16/2022 10:46:05 PM
 *  Author: Eng.Mohamed AbdAllah
 */ 
#include "SEVEN_SEG.h"


int main(void)
{
	/* Replace with your application code */
	uint8_t x = 0;
	SEVEN_SEG_init();
	while (1)
	{
		for(uint8_t i = 0 ; i < 10 ; i++)
		{
			SEVEN_SEG_write_on2(x);
		}
		x++;
		if(x > 99) x = 0;
	}
}
