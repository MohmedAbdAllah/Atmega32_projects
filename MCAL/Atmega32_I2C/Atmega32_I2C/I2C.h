/*
 * I2C.h
 *
 * Created: 9/1/2022 6:51:22 PM
 *  Author: Eng.Mohamed AbdAllah
 */ 


#ifndef I2C_H_
#define I2C_H_

#include "std_macros.h"

#define SCL_f 400000
#define CPU_f 16000000
#define prescaler 0
#define coff 4^prescaler
#define TWBR_VAL (((CPU_f/SCL_f)-16)/(coff*2))

void I2C_master_init(void);
void I2C_slave_init(uint8_t);

uint8_t I2C_master_start(void);
uint8_t I2C_master_addr(uint8_t,uint8_t);

uint8_t I2C_master_write(uint8_t);
void I2C_slave_write(uint8_t data);

uint8_t I2C_master_read(void);
uint8_t I2C_slave_read(void);

void I2C_master_stop(void);
uint8_t I2C_slave_available(void);



#endif /* I2C_H_ */