/*
 * Q5.c
 *
 * Created: 8/16/2022 10:49:23 PM
 *  Author: Eng.Mohamed AbdAllah
 */ 
#include "SEVEN_SEG.h"


int main(void)
{
	/* Replace with your application code */
	uint8_t x = 0;
	SEVEN_SEG_init();
	PORTC |= 0b00000011;
	while (1)
	{
		for(uint8_t i = 0 ; i < 10 ; i++){
			SEVEN_SEG_write_on2(x);
		}
		
		if(READBIT(PINC,0) == 0){
			x++;
			while(READBIT(PINC,0) == 0);
		}
		
		else if(READBIT(PINC,1) == 0){
			 x--;
			 while(READBIT(PINC,1) == 0);
		}
		
		if(x > 99) x = 0;
		else if(x < 0) x = 99;
		
	}
}
