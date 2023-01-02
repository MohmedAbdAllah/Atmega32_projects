/*
 * Cooler system.c
 *
 * Created: 9/8/2022 9:51:02 AM
 * Author : Eng.Mohamed AbdAllah
 */  

#include "ADC.h"
#include "LCD.h"
#include "SEVEN_SEG.h"
#include "TIMER1.h"

int main(void)
{
    LCD_init();
	ADC_init();
	TIME1_PWM_oc1A_init();
	SEVEN_SEG_init();
	uint8_t temp = 0,speed = 0;
	SETBIT(DDRA,PINA7);
    while (1) 
    {
		temp = (ADC_read()*100/206) + 1;
		LCD_write_command(0x80);
		LCD_write_string((uint8_t*)"TEMP = ");
		LCD_write_num(temp);
		SEVEN_SEG_write_on2(temp);
		if((temp >= 35)&&(temp < 50)){
			speed = (((temp-35) * 50)/15) + 50;
			TIME1_PWM_oc1A_duty(speed);
			SETBIT(PORTA,PINA7);
		}else if(temp >= 50){
			TIME1_PWM_oc1A_duty(100);
		}else{
			CLRBIT(PORTA,PINA7);
			TIME1_PWM_oc1A_duty(0);
		}
		LCD_write_command(0x01);
		
		
    }
}

