/*
 * Atmega32_Control_ServoMotor.c
 *
 * Created: 11/19/2022 6:28:44 PM
 * Author : Eng.Mohamed AbdAllah
 */ 

#include "DC_MOTOR.h"


int main(void)
{
	//initialize the SPI as a slave
	SPI_init_slave();
	//initialize the fast freq mode in time 0
	TIME0_PWM_init();
	//initialize LCD
	LCD_init();
	// speed
	uint16_t speed = 0,new_speed = 0;
    while (1) 
    {
		//change the speed.
		speed = SPI_si();
		if(new_speed != speed){
			TIME0_PWM_duty(speed);
			new_speed = speed;
			//print in LCD
			LCD_write_command(0x01);
			LCD_write_num(new_speed);
		} 
		
		
    }
}

