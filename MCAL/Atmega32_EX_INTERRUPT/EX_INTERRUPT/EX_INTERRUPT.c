/*
 * EX_INTERRUPT.c
 *
 * Created: 8/26/2022 6:29:41 PM
 *  Author: Eng.Mohamed AbdAllah
 */ 
#include "EX_INTERRUPT.h"
extern void (*INT0_vect_isr)(void);
extern void (*INT1_vect_isr)(void);
/**************************************************************************
* Function Name: EI_INT0_init
* Purpose      : Configure External Interrupt 0
* Parameters   : mode('l'ow level ,'f'alling ,'r'ising ,logical 'c'hange)
* Return value : void
**************************************************************************/
void EI_INT0_init(uint8_t mode){
	// Configure External Interrupt INT0
	SETBIT(GICR, 6);
	
	//select mode
	if (mode == 'l')
	{
		// Enable low level of INT0
		CLRBIT(MCUCR, 0);
		CLRBIT(MCUCR, 1);
	}else if (mode == 'f')
	{
		// Enable falling Edge of INT0
		CLRBIT(MCUCR, 0);
		SETBIT(MCUCR, 1);
	}else if (mode == 'c')
	{
		// Enable any logical change of INT0
		SETBIT(MCUCR, 0);
		CLRBIT(MCUCR, 1);
	}else if (mode == 'r')
	{
		// Enable rising Edge of INT0
		SETBIT(MCUCR, 0);
		SETBIT(MCUCR, 1);
	}
	SETBIT(SREG, 7);

}

/**************************************************************************
* Function Name: EI_INT1_init
* Purpose      : Configure External Interrupt 1
* Parameters   : mode('l'ow level ,'f'alling ,'r'ising ,logical 'c'hange)
* Return value : void
**************************************************************************/
void EI_INT1_init(uint8_t mode){
	// Configure External Interrupt INT1
	
	SETBIT(GICR, 7);
	
	//select mode
	if (mode == 'l')
	{
		// Enable low level of INT1
		CLRBIT(MCUCR, 2);
		SETBIT(MCUCR, 3);
	}else if (mode == 'f')
	{
		// Enable falling Edge of INT1
		CLRBIT(MCUCR, 2);
		SETBIT(MCUCR, 3);
	}else if (mode == 'c')
	{
		// Enable any logical change of INT1
		SETBIT(MCUCR, 2);
		CLRBIT(MCUCR, 3);
	}else if (mode == 'r')
	{
		// Enable rising Edge of INT1
		SETBIT(MCUCR, 2);
		SETBIT(MCUCR, 3);
	}
	SETBIT(SREG, 7);
}


ISR(INT0_vect){
	INT0_vect_isr();
}

ISR(INT1_vect){
	INT1_vect_isr();
}