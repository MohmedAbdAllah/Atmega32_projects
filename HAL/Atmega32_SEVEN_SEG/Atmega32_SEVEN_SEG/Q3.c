/*
 * Q4.c
 *
 * Created: 8/23/2022 12:39:49 AM
 *  Author: Eng.Mohamed AbdAllah
 */ 
#include "ADC.h"
#include "SEVEN_SEG.h"



int main(void)
{
	ADC_init();
	SEVEN_SEG_init();
	float x = 0;
	
	while (1)
	{
		x = ((float)ADC_read() * 99.0)/1023.0;
		SEVEN_SEG_write_on2((uint8_t)x);
	}
}