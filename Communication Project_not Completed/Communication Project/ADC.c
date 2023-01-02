/*
 * ADC.c
 *
 * Created: 8/22/2022 7:24:14 PM
 *  Author: Eng.Mohamed AbdAllah
 */ 
#include "ADC.h"
/**************************************************************************
* Function Name: ADC_init
* Purpose      : initialize ADC
* Parameters   : void
* Return value : void
**************************************************************************/
void ADC_init(void){
	//AVCC with external capacitor at AREF pin
	SETBIT(ADMUX,REFS0);
	//Enable ADC
	SETBIT(ADCSRA,ADEN);
	//freq mode 128
	SETBIT(ADCSRA,ADPS0);
	SETBIT(ADCSRA,ADPS1);
	SETBIT(ADCSRA,ADPS2);
}
/**************************************************************************
* Function Name: ADC_read
* Purpose      : read output value from ADC 
* Parameters   : void
* Return value : converting value from ADC register
**************************************************************************/
uint16_t ADC_read(uint8_t channel){
	//choose the channel
	//ADMUX = ADMUX |(channel & 0x0f);
	//Start single conversion mode
	SETBIT(ADCSRA,ADSC);
	//check if the conversion complete or not
	while(READBIT(ADCSRA,ADSC) == 1);
	//read the ADC
	return ADC;
	
	
}