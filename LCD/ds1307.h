/*
 * ds1307.h
 *
 * Created: 4/3/2014 12:52:27 PM
 *  Author: Lingga
 */ 


#ifndef DS1307_H_
#define DS1307_H_

#define DS1307_ADDR (0x68<<1)

#define DS1307_I2CINIT 1

void ds1307_init();
uint8_t ds1307_setdate(uint8_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute, uint8_t second);
void ds1307_getdate(uint8_t *year, uint8_t *month, uint8_t *day, uint8_t *hour, uint8_t *minute, uint8_t *second);


#endif /* DS1307_H_ */