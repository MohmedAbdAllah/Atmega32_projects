/*
 * TIMER1.c
 *
 * Created: 8/21/2022 4:42:55 AM
 *  Author: Eng.Mohamed AbdAllah
 */ 
#include "TIMER1.h"
void (*timer1_InCapture_isr)(void) = 0;
/**************************************************************************
* Function Name: TIME1_NORMAL_init
* Purpose      : Configure timer 1 OC1A as Normal
* Parameters   : void
* Return value : void
**************************************************************************/
void TIME1_NORMAL_init(void){
	//configure as no prescaling
	SETBIT(TCCR1B,CS10);

	//configure as normal
	CLRBIT(TCCR1B,WGM12);
	CLRBIT(TCCR1A,WGM11);
	CLRBIT(TCCR1A,WGM10);
}
/**************************************************************************
* Function Name: TIME1_PWM_oc1A_init
* Purpose      : Configure timer 1 OC1A in PWM "fast freq" (10 bit,non inverting, no prescaling)
* Parameters   : void
* Return value : void
**************************************************************************/
void TIME1_PWM_oc1A_init(void){
	//Configure as output
	SETBIT(DDRD,5);
	//configure as no prescaling
	SETBIT(TCCR1B,CS10);
	//configure as non inverting mode
	SETBIT(TCCR1A,COM1A1);
	//configure as fast PWM 10 bits
	CLRBIT(TCCR1B,WGM12);
	SETBIT(TCCR1A,WGM11);
	SETBIT(TCCR1A,WGM10);
}
/**************************************************************************
* Function Name: TIME1_PWM_oc1A_duty
* Purpose      : used to modify the pluse width 
* Parameters   : duty : 0-->100 ,DC = duty/100 -- OCR1A = (1023 * DC) 
* Return value : void
**************************************************************************/
void TIME1_PWM_oc1A_duty(uint8_t duty){
	OCR1A = duty * 10.23;
}
/**************************************************************************
* Function Name: TIME1_pwmInCapture_oc1A_init
* Purpose      : Configure timer 1 to be in input capture mode
* Parameters   : void
* Return value : void
**************************************************************************/
void TIME1_InCapture_init(void){

	//configure as no prescaling
	SETBIT(TCCR1B,CS10);
	
	//Configure ICES1 as a rising (positive) edge will trigger the capture
	SETBIT(TCCR1B,ICES1);
	//Enable input capture interrupt
	SETBIT(TIMSK,TICIE1);
	//Enable global interrupt
	SETBIT(SREG,7);
}

ISR(TIMER1_CAPT_vect){
	timer1_InCapture_isr();
}