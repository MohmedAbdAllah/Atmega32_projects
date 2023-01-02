/*
 * Q3.c
 *
 * Created: 8/23/2022 12:27:07 AM
 *  Author: Eng.Mohamed AbdAllah
 */ 
#include "ADC.h"



int main(void)
{
	ADC_init();
	SETBIT(DDRA,7);
	
	while (1)
	{
		
		if(ADC_read() > 512	) SETBIT(PORTA,7);
		else CLRBIT(PORTA,7);
	}
}