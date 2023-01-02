/*
 * clock_app.c
 *
 * Created: 9/16/2022 11:36:06 AM
 * Author : MO
 */ 
#include "KEYPAD.h"
#include "LCD.h"
#include "clock.h"
#include "TIMER0.h"

uint8_t count_S = 0,count_M = 0,count_H = 0;

static void comp_isr(void);
static void INT2_isr(void);

int main(void)
{	
	
	uint8_t num = 1;
	EI_INT2_init('f');
	KEYPAD_init();
	LCD_init();
	CLRBIT(DDRB,PINA2);
	TIME0_COMP_init(125);
	timer0_comp_isr = comp_isr;//point to isr of ovf function
	INT2_vect_isr = INT2_isr;
	
    while (1) 
    {
		
			SEVEN_SEG_write(count_S,'s');
			SEVEN_SEG_write(count_M,'m');
			SEVEN_SEG_write(count_H,'h');
			
			if(num != count_S){
				LCD_write_command(0x01);
				LCD_write_command(0x85);
				LCD_write_num(count_H);
 				LCD_write_data(':');
 				LCD_write_num(count_M);
 				LCD_write_data(':');
 				LCD_write_num(count_S);
				num = count_S;
				//if(num == 60) num = 0;
				if(count_S == 60){ count_S = 0;count_M++;}
				if(count_M == 60){ count_M = 0;count_H++;}
				if(count_H == 60) count_H = 0;
			}
    }
}
void comp_isr(){
	static uint32_t i = 0;
	i++;
	if(i == 125){
		i = 0;
		count_S++;	
	}
}
void INT2_isr(){
	
}


