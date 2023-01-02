/*
 * InputCapture_app.c
 *
 * Created: 8/21/2022 10:11:20 PM
 *  Author: Eng.Mohamed AbdAllah
 */ 
#include "TIMER1.h"
#include "LCD.h"
static void InCapture_isr(void);

uint16_t t_arr[3] = {1,2,3};
volatile uint8_t i = 0;
int main(void)
{	
	timer1_InCapture_isr = InCapture_isr;
	TIME1_InCapture_init();//Configure timer 1 to be in input capture mode
	LCD_init();

	
	
    while (1) 
    {	
		if(i == 3){
			LCD_write_command(0x80);
			LCD_write_string((uint8_t*)"Period = ");
			LCD_write_num((t_arr[2] - t_arr[0])/16);
			LCD_write_string((uint8_t*)"us");
			
			LCD_write_command(0xc0);
			LCD_write_string((uint8_t*)"Duty = ");
			LCD_write_num((((float)(t_arr[1] - t_arr[0]))/((float)(t_arr[2] - t_arr[0])))*100);
			LCD_write_string((uint8_t*)"%");
		}
	}
}

static void InCapture_isr(void){

	t_arr[i] = ICR1;
	//Stop global interrupt
	if(i == 2){
		//Stop Timer1 InCapture interrupt
		CLRBIT(TIMSK,TICIE1);
	}
	i++;
	//trigger negative edge
	if(i == 1) {
		CLRBIT(TCCR1B,ICES1);
	}
	//trigger positive edge
	else{
	   SETBIT(TCCR1B,ICES1);
	}
}