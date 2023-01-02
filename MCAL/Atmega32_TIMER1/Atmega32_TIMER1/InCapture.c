/*
 * CFile1.c
 *
 * Created: 8/22/2022 6:12:06 PM
 *  Author: Eng.Mohamed AbdAllah
 */ 
#include "TIMER1.h"
#include "LCD.h"


//uint16_t t_arr[3] = {1,2,3};

int main(void)
{	
	TIME1_InCapture_init();//Configure timer 1 to be in input capture mode
	LCD_init();
	/*
	 period = 1024/16 us 64
	*/
	uint16_t t1,t2,t3,high,period;
    while (1) 
    {	
		TCCR1A = 0;
		TCNT1 = 0;
		TIFR = (1<<ICF1);
		
		TCCR1B = 0x41;
		while((TIFR&(1<<ICF1)) == 0);
		t1 = ICR1;
		TIFR = (1<<ICF1);
		
		TCCR1B = 0x01;
		while((TIFR&(1<<ICF1)) == 0);
		t2 = ICR1;
		TIFR = (1<<ICF1);
		
		TCCR1B = 0x41;
		while((TIFR&(1<<ICF1)) == 0);
		t3 = ICR1;
		TIFR = (1<<ICF1);
		
		TCCR1B = 0;
		
		if(t1<t2 && t2<t3){
			period = t3 - t1;
			high = t2 - t1;
			LCD_write_command(0x80);
			LCD_write_string((uint8_t*)"Period = ");
			LCD_write_num(period);
			LCD_write_string((uint8_t*)"us");
			
			LCD_write_command(0xc0);
			LCD_write_string((uint8_t*)"Duty = ");
			LCD_write_num(((float)high/(float)period)*100);
			LCD_write_string((uint8_t*)"%");
		}
		else{
			_delay_ms(50);
		}
		
		/*LCD_write_command(0x80);
		LCD_write_string((uint8_t*)"Period = ");
		LCD_write_num((t_arr[2] - t_arr[0]));
		LCD_write_string((uint8_t*)"us");
		
		LCD_write_command(0xc0);
		LCD_write_string((uint8_t*)"Duty = ");
		LCD_write_num(((float)((t_arr[1] - t_arr[0])*100))/((float)(t_arr[2] - t_arr[0])));
		LCD_write_string((uint8_t*)"%");*/
	}
}