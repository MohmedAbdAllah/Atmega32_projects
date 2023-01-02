/*
 * Q4.c
 *
 * Created: 8/23/2022 12:39:49 AM
 *  Author: Eng.Mohamed AbdAllah
 */ 
#include "ADC.h"
#include "TIMER0.h"


int main(void)
{
	ADC_init();
	TIME0_PWM_init();
	uint8_t duty = 0;
	
	while (1)
	{
		duty = (ADC_read() * 100)/1023;
		TIME0_PWM_duty(duty);
		
	}
}