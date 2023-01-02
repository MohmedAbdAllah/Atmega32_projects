/*
 * TIMER0_app.c
 *
 * Created: 8/19/2022 6:01:36 PM
 * Author : Eng.Mohamed AbdAllah
 */ 

#include "TIMER0.h"
#include "LCD.h"
#include "SEVEN_SEG.h"


static void OVF_isr(void);
static void COMP_isr(void);
static uint32_t data;
int main(void)
{	
	SEVEN_SEG_init();// configure seven segmant pins
	LCD_init();// configure lcd pins
	SETBIT(DDRA,7);// configure pin7 port a as output
	timer0_ovf_isr = OVF_isr;//point to isr of ovf funtion
	timer0_comp_isr = COMP_isr;//point to isr of compare match funtion
	TIME0_COMP_init(250);// configure time 0 compare match function

	
    /* Replace with your application code */
    while (1) 
    {	
		SEVEN_SEG_write_on2(data); // write on 2 digit seven segment
		LCD_write_command(0x80);//set write position 0x80
		LCD_write_num(data);//write on lcd
    }
}

/*
needed_time = ov_time * count
count = (needed_time / ov_time) = 500 *10^-3/ (256 *C.C)
      = 500/ ((256 * 10^-3)/ 16)
	  = (16 * 10^3)*500/ 256 = 500*10^3/16 = 31250
*/

// Interrupt overflow funtion
static void OVF_isr(void){
	static uint32_t count = 0;
	count++;
	if(count == 31250){
		TOGBIT(PORTA,7);
		count = 0;
	}
}
/*
needed_time = ov_time * count
count = (needed_time / ov_time) = 500--300*10^-3/ (250 *C.C)
      = 500--300/ ((250 * 10^-3)/ 16)
	  = (16 * 10^3)*500--300/ 250 = 32000--19200
*/
/*
PRESCALER = 1024
ov_time = cr * 1024/(16*10^6)
needed_time = ov_time * count
count = (needed_time / ov_time) = 1/ (cr * 1024/(16*10^6))
	  = (16 * 10^6)/ (cr * 1024) = 15625/cr
cr  = count = 125
*/

//Interrupt compare function
static void COMP_isr(void){
	static uint32_t count = 0;
	count++;
	if(count == 19200){
		TOGBIT(PORTA,7);
		if(data < 100)
			data++;
		else
			data = 0;
		count = 0;	
	}
	
}