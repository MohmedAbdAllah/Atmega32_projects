/*
 * AC.c
 *
 * Created: 8/27/2022 10:26:08 PM
 *  Author: Eng.Mohamed AbdAllah
 */ 
#include "AC.h"

void (*AC_isr)(void);
/**************************************************************************
* Function Name: AC_init
* Purpose      : initialize analog comparator and its interrupt service rotuine
* Parameters   : analog comparator interrupt mode
* Return value : void
**************************************************************************/
void AC_init(uint8_t mode){
	//AIN1 as negative input
	SETBIT(SFIOR,ACME);
	//CLRBIT(ADCSRA,ADEN);

	CLRBIT(ACSR, ACIE);

	if(mode == 't'){
		CLRBIT(ACSR, ACIS0);
		CLRBIT(ACSR, ACIS1);
	}else if(mode == 'f'){
		CLRBIT(ACSR, ACIS0);
		SETBIT(ACSR, ACIS1);
	}else if(mode == 'r'){
		SETBIT(ACSR, ACIS0);
		SETBIT(ACSR, ACIS1);
	}
	//SETBIT(SFIOR, ACME);
	SETBIT(ACSR, ACIE);
	SETBIT(SREG, 7);
}

ISR(ANA_COMP_vect){
	AC_isr();
}