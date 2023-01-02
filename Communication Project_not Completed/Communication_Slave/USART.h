/*
 * USART.h
 *
 * Created: 8/29/2022 8:31:22 PM
 *  Author: Eng.Mohamed AbdAllah
 */ 


#ifndef USART_H_
#define USART_H_

#include "std_macros.h"
#define Baud_rate 9600
#define freq_osc 16000000UL
#define UBRR_reg ((freq_osc/(16UL * Baud_rate)) -1)
void USART_init();
void USART_tx(uint8_t);
uint8_t USART_rx(void);

void (*USART_rxc_vect)(void);

#endif /* USART_H_ */