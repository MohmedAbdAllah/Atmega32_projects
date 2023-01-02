/*
 * Atmega32_locker.c
 *
 * Created: 8/23/2022 11:02:41 PM
 * Author : Eng.Mohamed AbdAllah
 */ 

#include "LOCKER.h"


int main(void)
{	//EEPROM_write(500,0);
	//EEPROM_write(501,0);
	
	SETBIT(DDRA, PINA6);
	CLRBIT(PORTA, PINA7);
	
	SETBIT(DDRA, PINA5);
	
	
	LCD_init();
	KEYPAD_init();
	
    while (1) 
    {	
		if(READBIT(PINA,PINA6) == 0){
			//print indication sentence on screen make user know that the locker opened
			LCD_write_command(0x82);
			LCD_write_string((uint8_t*)"LOCKER OPENED        ");
			//check input from user
			key_input = KEYPAD_read();
			//if there is input
			if (key_input > 0){
				_delay_ms(1);
				//check if the user want to change the password
				if(key_input == NEW_PASS){
					NEW_PASS_fun();
				}
				//check if the user want to close the locker
				else if (key_input == LOCK)
				{	
					//toggle buzzer 100 millisecond
					BUZZER_TOGGLE_fun(100);
					
					SETBIT(PORTA,PINA6);
					LCD_write_command(0x01);

				}
				//this part used to check during run time only"not a part of app"
				else if(key_input == ENTER){
					uint16_t check = EEPROM_read(500) + 100 * EEPROM_read(501);
					CHECK_INPUT_fun(check);
				}
				else{
					//check the inputs
					RESET_PASS_fun();
					if(key_input == 0) key_input = 1;
				}
				//waiting the input to change 
				while(key_input == KEYPAD_read());
				_delay_ms(1);
			}
		
		}
		else if(READBIT(PINA,PINA6) == 1)
		{
			uint16_t pass = EEPROM_read(500) + 100 * EEPROM_read(501);
			//check the password
			CHECK_PASS_fun(pass);
			
			
		}
	}
	
}



