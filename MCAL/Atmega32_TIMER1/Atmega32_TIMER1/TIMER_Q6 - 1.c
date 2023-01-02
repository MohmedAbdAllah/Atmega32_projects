/*
 * InputCapture_app.c
 *
 * Created: 8/21/2022 10:11:20 PM
 *  Author: Eng.Mohamed AbdAllah
 */ 
#include "TIMER1.h"
#include "LCD.h"
#include "EX_INTERRUPT.h"

static void INT1_isr(void);

uint16_t t_arr[3] = {0};
volatile uint8_t i = 0;
int main(void)
{	
	INT1_vect_isr = INT1_isr;
	EI_INT1_init('c');//Configure interrupt 1
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
			LCD_write_num((((float)(t_arr[2] - t_arr[1]))/((float)(t_arr[2] - t_arr[0])))*100);
			LCD_write_string((uint8_t*)"%");
		}
	}
}

static void INT1_isr(void){
	if(i == 0)TIME1_NORMAL_init();
	else if(i == 1)t_arr[1] = TCNT1;
	else if(i == 2){
		t_arr[2] = TCNT1;
		CLRBIT(TCCR1B,CS10);
		CLRBIT(GICR, 7);}
	i++;
}