/*
 * Q4_5.c
 *
 * Created: 8/20/2022 1:27:52 AM
 *  Author: Eng.Mohamed AbdAllah
 */ 


#include "TIMER0.h"
static void COMP_isr(void);

int main(void)
{	
	SETBIT(DDRB,3);
	timer0_comp_isr = COMP_isr;//point to isr of compare match funtion
	TIME0_COMP_init(156);//configure time 0 compare match function

	
    /* Replace with your application code */
    while (1) 
    {	

    }
}
/*
ov_time = (156 *1024 * 10^-6)/16 
needed_time = ov_time * count
count = (needed_time / ov_time) = (50 * 10^3)/ (156*1024 /16)
	  = (16 * 50*10^3)/ 1024*cr-->156  
cr  = count = 5.008
*/
//Interrupt compare function
static void COMP_isr(void){
	static uint32_t count = 0;
	count++;
	if(count == 10){
		SETBIT(PORTB,3);
	}else if(count == 15){
		CLRBIT(PORTB,3);
		count = 0;
	}
	
}