/*
 * TIMER0.c
 *
 * Created: 8/19/2022 6:02:16 PM
 *  Author: Eng.Mohamed AbdAllah
 */ 

#include "TIMER0.h"

extern void (*timer0_ovf_isr)(void);
extern void (*timer0_comp_isr)(void);
/**************************************************************************
* Function Name: TIME0_norm_init
* Purpose      : Configure timer 0 in normal mode
* Parameters   : void
* Return value :void
**************************************************************************/
void TIME0_OVF_init(void){
	SETBIT(TCCR0,CS00);// NO PRESCALER
	SETBIT(TCCR0,FOC0);
	
	SETBIT(TIMSK,TOIE0);//ENABLE TIMER OVERFLOW INTERRUPT 
	SETBIT(SREG,7);// ENABLE GLOBAL INTERRUPT
	
	
}
/**************************************************************************
* Function Name: TIME0_COMP_init
* Purpose      : Configure timer 0 in CTC mode
* Parameters   : oc: the compare value"value of OCR0"
* Return value :void
**************************************************************************/
void TIME0_COMP_init(uint8_t oc){
	OCR0 = oc;
	SETBIT(TCCR0,CS00);// NO PRESCALER -- PRESCALER when CS02 set
	SETBIT(TCCR0,CS02);// PRESCALER
	SETBIT(TCCR0,FOC0);// not use PWM
	SETBIT(TCCR0,WGM01);//ENABLE COMPARE MATCH MODE
	
	SETBIT(TIMSK,OCIE0);//ENABLE TIMER COMPARE MATCH INTERRUPT 
	SETBIT(SREG,7);// ENABLE GLOBAL INTERRUPT
}

/**************************************************************************
* Function Name: TIME0_freqGen_init
* Purpose      : Configure timer 0 in Freq Generating mode
* Parameters   : oc: the compare value"value of OCR0"
* Return value :void
**************************************************************************/
void TIME0_freqGen_init(uint8_t oc){
	OCR0 = oc;
	SETBIT(DDRB,3);
	SETBIT(TCCR0,CS00);// NO PRESCALER -- PRESCALER when CS02 set
	//SETBIT(TCCR0,CS02);// PRESCALER 1024
	//SETBIT(TCCR0,CS01);// PRESCALER 64
	SETBIT(TCCR0,FOC0);
	SETBIT(TCCR0,COM00);
	SETBIT(TCCR0,WGM01);//ENABLE COMPARE MATCH MODE
	
}

/**************************************************************************
* Function Name: TIME0_PWM_init
* Purpose      : Configure timer 0  in PWM "fast freq" (non inverting, no prescaling)
* Parameters   : void
* Return value : void
**************************************************************************/
void TIME0_PWM_init(void){
	//Configure as output
	SETBIT(DDRD,5);
	//configure as no prescaling
	SETBIT(TCCR0,CS00);
	
	//configure as non inverting mode
	SETBIT(TCCR0,COM01);
	
	//configure as fast PWM 10 bits
	SETBIT(TCCR0,WGM01);
	SETBIT(TCCR0,WGM00);
}
/**************************************************************************
* Function Name: TIME0_PWM_duty
* Purpose      : used to modify the pluse width
* Parameters   : duty : 0-->100 ,DC = duty/100 -- OCR0 = (255 * DC)
* Return value : void
**************************************************************************/
void TIME0_PWM_duty(uint8_t duty){
	OCR0 = duty * 2.55;
}

ISR(TIMER0_OVF_vect){
	timer0_ovf_isr();
}

ISR(TIMER0_COMP_vect){
	timer0_comp_isr();
}