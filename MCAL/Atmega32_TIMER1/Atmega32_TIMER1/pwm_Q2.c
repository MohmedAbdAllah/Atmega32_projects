/*
 * Q2.c
 *
 * Created: 8/21/2022 6:25:40 AM
 *  Author: Eng.Mohamed AbdAllah
 */ 
#include "TIMER1.h"


int main(void)
{	
	CLRBIT(DDRA,0);
	CLRBIT(DDRA,1);
	SETBIT(PORTA,0);
	SETBIT(PORTA,1);
	
	
	
	uint8_t i = 0;
	TIME1_PWM_oc1A_init();//configure timer1 as PWM
	/*
	 period = 1024/16 us 64
	*/
	
    while (1) 
    {	
		TIME1_PWM_oc1A_duty(i);
		
		if(READBIT(PINA,0) == 0){
			i = i + 10;
			while(READBIT(PINA,0) == 0);
		} 
		if(READBIT(PINA,1) == 0){
			i = i - 10;
			while(READBIT(PINA,1) == 0);
		}  
		
	}
}

