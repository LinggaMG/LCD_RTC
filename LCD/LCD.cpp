/*
 * LCD.cpp
 *
 * Created: 4/2/2014 6:58:38 PM
 *  Author: Lingga
 */ 

#define F_CPU 11059200UL

#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include <inttypes.h>
//#include <pgmspace.h>
#include "lcdLib.h"
#include "ds1307.h"

int main(void)
{
	uint8_t year = 0;
	uint8_t month = 0;
	uint8_t day = 0;
	uint8_t hour = 0;
	uint8_t minute = 0;
	uint8_t second = 0;
	char	temp[]="";
	
	ds1307_init();
	lcd_init();
	lcd_string("NILAI: ");
	
	//ds1307_setdate(14, 4, 3, 13, 9, 30);
	
	
    while(1)
    {
		lcd_clear();
		
		lcd_gotoxy(0,0);
		lcd_string("  RTC+LCD Test");
		
		lcd_gotoxy(0,1);
		ds1307_getdate(&year, &month, &day, &hour, &minute, &second);
		sprintf(temp,"%d-%d-%d", day,month,year);
		lcd_string(temp);
		
		lcd_gotoxy(8,1);
		ds1307_getdate(&year, &month, &day, &hour, &minute, &second);
		sprintf(temp,"%d:%d:%d", hour,minute,second);
		lcd_string(temp);
		_delay_ms(1000);
    }
}