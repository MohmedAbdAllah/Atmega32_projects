/*
 * TIMER1.h
 *
 * Created: 8/21/2022 4:43:16 AM
 *  Author: Eng.Mohamed AbdAllah
 */ 


#ifndef TIMER1_H_
#define TIMER1_H_
#include "std_macros.h"

extern void (*timer1_InCapture_isr)(void);

void TIME1_NORMAL_init(void);
void TIME1_PWM_oc1A_init(void);
void TIME1_PWM_oc1A_duty(uint8_t);
void TIME1_InCapture_init(void);


#endif /* TIMER1_H_ */