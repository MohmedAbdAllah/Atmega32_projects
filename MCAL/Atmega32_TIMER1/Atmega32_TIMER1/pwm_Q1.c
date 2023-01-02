/*
 * Atmega32_TIMER1.c
 *
 * Created: 8/21/2022 4:41:58 AM
 * Author : Eng.Mohamed AbdAllah
 */ 

#include "TIMER1.h"


int main(void)
{
	int8_t i = 0, j = 0;
	TIME1_PWM_oc1A_init();//configure timer1 as PWM
	/*
	 period = 1024/16 us 64
	*/

    while (1) 
    {
		if(i == 101) j = 1;
		else if(i == -1) j = 0;
		
		TIME1_PWM_oc1A_duty(i);
		_delay_ms(30);
		//check if 'i' reach or not
		if(j == 0) i++;
		else if(j == 1) i--;	
    }
}

