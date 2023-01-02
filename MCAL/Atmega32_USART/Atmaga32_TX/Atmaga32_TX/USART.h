/*
 * USART.h
 *
 * Created: 8/29/2022 8:31:22 PM
 *  Author: Eng.Mohamed AbdAllah
 */ 


#ifndef USART_H_
#define USART_H_

#include "std_macros.h"
void USART_init();
void USART_tx(uint8_t);
uint8_t USART_rx(void);



#endif /* USART_H_ */