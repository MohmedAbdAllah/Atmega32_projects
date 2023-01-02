/*
 * Atmega32_KEYPAD.c
 *
 * Created: 8/14/2022 9:50:20 PM
 * Author : Eng.Mohamed AbdAllah
 */ 

#include "KEYPAD.h"
#include "LCD.h"


int main(void)
{
    /* Replace with your application code */
	uint8_t LCD_arr[16], inc = 0, x = 0, cursor = 0x80;
	
	LCD_init();
	KEYPAD_init();
	
    while (1) 
    {
		
		x = KEYPAD_read();
	    if(x > 0){
			_delay_ms(1);
			if((x == '\t')&&(inc != 0)){
				inc--;
			}
			LCD_write_command(cursor + inc);
			LCD_write_data(x);
			while(x == KEYPAD_read());
			_delay_ms(1);
			LCD_arr[inc] = x;
			if(x != '\t'){
				inc++;
			}
			//LCD_shift_str(LCD_arr , inc, ptr_cur);
		}
    }
}

