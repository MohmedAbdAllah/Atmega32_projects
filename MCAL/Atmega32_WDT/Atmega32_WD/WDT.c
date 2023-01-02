/*
 * WD.c
 *
 * Created: 8/28/2022 7:22:54 PM
 *  Author: Eng.Mohamed AbdAllah
 */ 
#include "WDT.h"
/**************************************************************************
* Function Name: WD_on
* Purpose      : turn on watch dog timer
* Parameters   : time mode
* Return value : void
**************************************************************************/
void WDT_on(uint8_t time_mode){
	//choose delay time
	if(time_mode == 0) WDTCR|0;
	else if(time_mode == 1) WDTCR|=1;
	else if(time_mode == 2) WDTCR|=2;
	else if(time_mode == 3) WDTCR|=3;
	else if(time_mode == 4) WDTCR|=4;
	else if(time_mode == 5) WDTCR|=5;
	else if(time_mode == 6) WDTCR|=6;
	else if(time_mode == 7) WDTCR|=7;
	
	//enable watch dog timer
	SETBIT(WDTCR,WDE);	
}
/**************************************************************************
* Function Name: WDT_off
* Purpose      : stop watch dog timer
* Parameters   : void
* Return value : void
**************************************************************************/
void WDT_off(void){
	//stop watch dog timer
	WDTCR |= 1<<WDE | 1<<WDTOE;
	CLRBIT(WDTCR,WDE);
}