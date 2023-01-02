/*
 * A_CAL.h
 *
 * Created: 10/7/2022 3:54:27 PM
 *  Author: Eng.Mohamed AbdAllah
 */ 


#ifndef A_CAL_H_
#define A_CAL_H_

#include "std_macros.h"
#include "KEYPAD.h"
#include "LCD.h"

	

/**************************************************************************
* Function Name: CAL_input
* Purpose      : Specify if the user input is argument or operant
* Parameters   : uint8_t -> keypad input
				 uint8_t -> negative flag
* Return value :void
**************************************************************************/
void CAL_input(uint8_t,uint8_t);
/**************************************************************************
* Function Name: CAL_output
* Purpose      : calculate the output of the arithmetic operation
* Parameters   : void
* Return value : void
**************************************************************************/
void CAL_output(void);
/**************************************************************************
* Function Name: CAL_reset
* Purpose      : used to reset the calculator
* Parameters   :void
* Return value :void
**************************************************************************/
void CAL_reset(void);







#endif /* A_CAL_H_ */