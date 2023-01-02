/*
 * Communication Main Master.c
 *
 * Created: 12/4/2022 6:59:33 PM
 * Author : Eng.Mohamed AbdAllah
 */ 

#include "M_MASTER.h"
static void usart_rxc_vect(void);
static uint16_t USART_data = 0;
int main(void)
{
    /* Replace with your application code */
	CLRBIT(DDRA,PINA1);
	SETBIT(PORTA,PINA1);
	USART_rxc_vect = usart_rxc_vect;
	KEYPAD_init();
	LCD_init();
	USART_init();
	I2C_slave_init(50);
	
	volatile uint8_t I2C_data = 0;
	volatile uint8_t KEYPAD_data = 0;
	//get the last speed from EEPROM
	volatile uint8_t INPUT_SPEED = EEPROM_read(50);;
    while (1) 
    {
		//check if there is a new data reach from the TWI
		if(I2C_slave_available() == 0){
			//save the new data in I2C_data variable
			I2C_data = I2C_slave_read();
			//check if there is an error "the temperature exceed the control limitation" or not
			if(I2C_data == TEMP_ERROR){
				//Stop the motor
				INPUT_SPEED = 0;
				//clear the screen
				LCD_write_command(0x01);
				//Display the Error in the LCD
				LCD_write_command(0xC0);
				LCD_write_string((uint8_t*)"ERROR: HIGH TEMP");
			}
		}else{
			//Check If there is input from the KEYPAD
			KEYPAD_data = KEYPAD_read();
			if(KEYPAD_data > 0){ // if yes
				while(KEYPAD_data == KEYPAD_read());
				_delay_us(50);
				//Check if the user want to input new speed or not
				if(KEYPAD_data == '='){
					//Display massage and start get the speed
					LCD_write_command(0x01);
					LCD_write_command(0x80);
					LCD_write_string((uint8_t*)"Input Speed : ");
					do{
						KEYPAD_data = KEYPAD_read();
						if(KEYPAD_data > 0){
							LCD_write_data(KEYPAD_data);
							while(KEYPAD_data == KEYPAD_read());
							_delay_us(50);
							if((KEYPAD_data >= '0')&&(KEYPAD_data <= '9')){
								INPUT_SPEED = (KEYPAD_data-48) +(INPUT_SPEED*10);
							}else if(KEYPAD_data == '='){
								//if the user put the speed exceed the max-speed chance it to max-speed
								if(INPUT_SPEED > 99){
									INPUT_SPEED = 99;
								}
							}
						}
					}while(KEYPAD_data != '=');
					//clear the screen
					LCD_write_command(0x01);
				}
			}
			//save the new speed in EEPROM
			EEPROM_write(50,INPUT_SPEED);
			//send the new speed to the motor controller.
			USART_tx((uint8_t)INPUT_SPEED);
			//save the new speed in EEPROM
			EEPROM_write(50,USART_data);
			LCD_write_command(0x80);
			//Display the active speed.
			LCD_write_string((uint8_t*)"Speed :  ");
			LCD_write_num(USART_data);
			//save the new speed in EEPROM
			EEPROM_write(50,USART_data);
		}
		
    }
}

static void usart_rxc_vect(){
	USART_data = UDR;
}