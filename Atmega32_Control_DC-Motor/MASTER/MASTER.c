/*
 * MASTER.c
 *
 * Created: 11/25/2022 12:27:02 AM
 * Author : Eng.Mohamed AbdAllah
 */ 

#include "MASTER.h"
//initialize the speed variable
uint8_t speed = 0,new_speed = 0;

int main(void)
{
	/* Replace with your application code */
	//make the first three pin in port a input pull up
	PORTA |= 0b00011100;
	//initialize the SPI as a master.
	SPI_init_master();
	while (1){
		//display the new speed on 7 segment
		SEVEN_SEG_write(speed);
		//check the press key and the range of speed.
		if(INC == 0){
			//_delay_ms(250);
			while(INC == 0);
			if(speed <= 99) speed += 10;
		}if(DEC == 0){
			//_delay_ms(250);
			while(DEC == 0);
			if(speed > 0) speed -= 10;
		}if(STOP==0){
			//_delay_ms(250);
			while(STOP == 0);
			speed = 0;
		}
		//send the new speed to the slave.
		if(new_speed != speed){
			SPI_mo(speed);
			new_speed = speed;
		}
			
			
	}
}

