/*
 * Atmega32_Control_ServoMotor.c
 *
 * Created: 11/19/2022 6:28:44 PM
 * Author : Eng.Mohamed AbdAllah
 */ 

#include "ADC.h"
#include "TIMER0.h"


int main(void)
{
    /* Replace with your application code */
	
	uint32_t ADC_result = 0,ADC_old = 0;
	ADC_init();
	TIME0_PWM_init();
	
    while (1) 
    {
		//the conversion ADC output
		ADC_result = ADC_read();
		
		if(ADC_result != ADC_old)
			OCR0 = ((ADC_result*38)/1024)+31;
		ADC_old = ADC_result;
		
    }
}

