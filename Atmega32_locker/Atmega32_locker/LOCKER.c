/*
 * LOCKER.c
 *
 * Created: 8/25/2022 1:18:38 PM
 *  Author: Eng.Mohamed AbdAllah
 */ 


#include "LOCKER.h"
volatile uint8_t  inc = 0, cursor = 0xc0, key_input = 0;
/**************************************************************************
* Function Name: NEW_PASS_fun
* Purpose      : Get new password from the user
* Parameters   : void
* Return value : void
**************************************************************************/
void NEW_PASS_fun(void){
	uint16_t new_pass_num = 0;
	key_input = 0;
	//toggle buzzer 3 second
	BUZZER_TOGGLE_fun(3000);
	//clean the screen
	LCD_write_command(0x01);
	//check if the input value equal '/' or if number of input digit more than 4
	while((key_input != NEW_PASS) || (inc != 4)){
		// print indication sentence for user to start input the new password
		LCD_write_command(0x80);
		LCD_write_string((uint8_t*)"Enter New ****         ");
		// get the password number by number
		key_input = KEYPAD_read();
		//check if the user write number of not
		if(key_input > 0){
			//toggle buzzer 100 millisecond
			_delay_ms(1);
			BUZZER_TOGGLE_fun(100);
			//check if the number between 0 to 9
			if((key_input >= '0') && (key_input <= '9')){
				new_pass_num = (key_input - '0') + (new_pass_num * 10);
				LCD_write_command(cursor + inc);
				LCD_write_data(key_input);
				_delay_ms(200);
				LCD_write_command(cursor + inc);
				LCD_write_data('*');
				
				while(key_input == KEYPAD_read());
				_delay_ms(1);
				
				inc++;
			}
			//check if the user want to erase the number or not
			else if(key_input == ERASE){
				ERASE_fun();
				new_pass_num /= 10;
			}	
			//this part used to check during run time only"not a part of app"
			else if(key_input == '='){
				CHECK_INPUT_fun(new_pass_num);
			}
			//check if the user input valid password or not
			else if((key_input == NEW_PASS)&&(inc != 4)){
				LCD_write_command(0x01);
				LCD_write_command(0x80);
				LCD_write_string((uint8_t*)"INVALID PASSWORD       ");
				_delay_ms(1000);
				inc = 0;
				new_pass_num = 0;
				
			}
		}
	}
	//save new password
	if(key_input == NEW_PASS){
		
		EEPROM_write(501,(uint8_t)(new_pass_num/100));
		EEPROM_write(500,(uint8_t)(new_pass_num%100));
		inc = 0;
		LCD_write_command(0x01);
		LCD_write_command(0x80);
		LCD_write_string((uint8_t*)" **** IS CHANGED   ");
		_delay_ms(1000)	;
		LCD_write_command(0x01);
	}
}
/**************************************************************************
* Function Name: RESET_PASS_fun
* Purpose      : reset the password to return to its default
* Parameters   : void
* Return value : void
**************************************************************************/
void RESET_PASS_fun(void){
	uint8_t reset = 0;
	//check if user try to reset the password , want to change the password or want to close the locker
	while((key_input != NEW_PASS) && (inc != 10) && (key_input != LOCK)){
		//check if the user something or not
		if(key_input > 0){
			_delay_ms(1);
			//toggle buzzer 100 ms
			BUZZER_TOGGLE_fun(100);
			//check if the user write number
			if((key_input >= '0') && (key_input <= '9')){
				reset += (key_input - '0');
				LCD_write_command(cursor + inc);
				LCD_write_data(key_input);
				_delay_ms(200);
				LCD_write_command(cursor + inc);
				LCD_write_data('*');
				
				while(key_input == KEYPAD_read());
				_delay_ms(1);
				
				inc++;
			}
			// check if user want to erase
			else if(key_input == ERASE){
				ERASE_fun();
				reset -= key_input;
			}
			//this part used to check during run time only"not a part of app"
			else if(key_input == ENTER){
				CHECK_INPUT_fun(reset);
			}
		}
		key_input = KEYPAD_read();
	}
	//check if user write 10 zeros
	if((reset == 0)&&(inc == 10)){
		//reset password
		EEPROM_write(501,0);
		EEPROM_write(500,0);
		inc = 0;
		LCD_write_command(0x01);
		LCD_write_command(0x80);
		LCD_write_string((uint8_t*)"RESET SUCCESS");
		_delay_ms(1000)	;
		LCD_write_command(0x01);
		
		}
		//if not clear screen
		else{
		LCD_write_command(0x01);
		inc = 0;
		
	}
	
}

/**************************************************************************
* Function Name: CHECK_PASS_fun
* Purpose      : check if the password right or wrong
* Parameters   : void
* Return value : void
**************************************************************************/
void CHECK_PASS_fun(uint16_t pass){
	uint16_t input_num = 0;
	uint8_t reset = 0 ;
	//toggle buzzer 100 millisecond
	BUZZER_TOGGLE_fun(100);
	//clean the screen
	LCD_write_command(0x01);
	//check if the input value equal '/' or if number of input digit more than 4
	while(inc != 10){
		uint8_t flag = 0;
		
		//print indication sentence on screen make user know that the locker opened
		LCD_write_command(0x82);
		LCD_write_string((uint8_t*)"LOCKER CLOSED        ");
		key_input = KEYPAD_read();
		//check if the user write number of not
		if(key_input > 0){
			//toggle buzzer 100 millisecond
			_delay_ms(1);
			BUZZER_TOGGLE_fun(100);
			//check if the number between 0 to 9
			if((key_input >= '0') && (key_input <= '9')){
				input_num = (key_input - '0') + (input_num * 10);
				reset += (key_input - '0');
				LCD_write_command(cursor + inc);
				LCD_write_data(key_input);
				_delay_ms(200);
				LCD_write_command(cursor + inc);
				LCD_write_data('*');
				
				while(key_input == KEYPAD_read());
				_delay_ms(1);
				
				inc++;
			}
			//check if the user want to erase the number or not
			else if(key_input == ERASE){
				ERASE_fun();
				input_num /= 10;	
			}
			//this part used to check during run time only"not a part of app"
			else if(key_input == '='){
				CHECK_INPUT_fun(input_num);
			}
			//check input password
			if(inc == 4){
				key_input = 0;
				uint16_t i;
				//check if the user will input more numbers of not
				for(i = 0 ; i < 550 ; i++)
				{
					key_input = KEYPAD_read();
					if((key_input >= '0') && (key_input <= '9')){
						flag = 1;
						i = 550;
					}
				}
				i = 0;
				// if this is all numbers 
				if(flag == 0){
					flag = 1;
					//if input numbers equal password
					if(input_num == pass){
						CLRBIT(PORTA,PINA6);
						LCD_write_command(0x01);
						
					}
					// if not
					else{
						LCD_write_command(0x01);
						LCD_write_command(0x80);
						LCD_write_string((uint8_t*)"WRONG PASSWORD       ");
						_delay_ms(1000);
						LCD_write_command(0x80);
						LCD_write_string((uint8_t*)"  TRY AGAIN            ");
						_delay_ms(1000);
						inc = 0;
						input_num = 0;
					}
				}
				//reset the flag
				if (READBIT(PORTA,PINA6) == 1) flag = 0;
			}
				
		}
		if(flag == 1) break;
	}
	//check if user write 10 zeros
	if((reset == 0)&&(inc == 10)){
		//reset password
		EEPROM_write(501,0);
		EEPROM_write(500,0);
		inc = 0;
		LCD_write_command(0x01);
		LCD_write_command(0x80);
		LCD_write_string((uint8_t*)"RESET SUCCESS");
		_delay_ms(1500)	;
		LCD_write_command(0x01);
		
	}
	//if not clear screen
	else{
		LCD_write_command(0x01);
		inc = 0;
		
	}
}
/**************************************************************************
* Function Name: ERASE_fun
* Purpose      : Erase key input
* Parameters   : void
* Return value : void
**************************************************************************/	
void ERASE_fun(void){
	inc--;
	LCD_write_command(cursor + inc);
	LCD_write_data(0);
}
/**************************************************************************
* Function Name: CHECK_INPUT_fun
* Purpose      : check the input after saved in variable to sure that is what 
			     we want to save
* Parameters   : input :the varible we want to check it
* Return value : void
**************************************************************************/
void CHECK_INPUT_fun(uint16_t input){
	LCD_write_command(0xcb);
	LCD_write_num(input);
	_delay_ms(500);
	LCD_write_command(0xcb);
	LCD_write_string((uint8_t*)"      ");
}
/**************************************************************************
* Function Name: BUZZER_TOGGLE_fun
* Purpose      : toggle buzzer
* Parameters   : delay_ms we want(3s or 100ms)
* Return value : void
**************************************************************************/
void BUZZER_TOGGLE_fun(uint16_t delay_ms){
	SETBIT(PORTA, PINA5);
	if(delay_ms == 3000)_delay_ms(3000);
	else if(delay_ms == 100)_delay_ms(100);
	CLRBIT(PORTA, PINA5);
}

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	