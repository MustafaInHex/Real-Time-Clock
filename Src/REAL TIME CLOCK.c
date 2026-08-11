
// I removed delay in KEYPAD_read() and i put the dealys manually before any other KEYPAD_read()

#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "std_macros.h"
#include "DIO.h"
#include "SEVENSEGMENT.h"
#include "LCD.h"
#include "KEYPAD.h"
#include "TIMER2.h"


volatile unsigned char seconds_counter=0;
volatile unsigned char minutes_counter=0;
volatile unsigned char hours_counter=0;
unsigned char first , second;
unsigned char x;

int main()
{
	
	LCD_initialize();
	LCD_writecmd(0x0c);
	
	KEYPAD_initialize();
	SEVENSEGMENT_initialize('B');
	
	LCD_writestring("press 1 to");
	LCD_movecursor(2,1);
	LCD_writestring("set time");
	
	DIO_pindirection('C',0,1);
	DIO_pindirection('C',1,1);
	DIO_pindirection('C',2,1);
	DIO_pindirection('C',3,1);
	DIO_pindirection('C',4,1);
	DIO_pindirection('C',5,1);
	
	TIMER2_OVERFLOW_initialize();

	
	while(1)
	{
		x=KEYPAD_read();
		
		
		if (x!=0xff)
		{
			
			if(x=='1')
			{
				_delay_ms(200);
				LCD_clearscreen();
				LCD_writestring("hours=--");
				do
				{
					first=KEYPAD_read();
				} while (first==0xff);

				_delay_ms(200);
				LCD_movecursor(1,7);
				LCD_writecharacter(first);
				
				do
				{
					second=KEYPAD_read();
				} while (second==0xff);
				
				LCD_writecharacter(second);
				_delay_ms(500);
				hours_counter=(first-48)*10+(second-48);
				LCD_clearscreen();
				
				
				
				LCD_writestring("minutes=--");
				do
				{
					first=KEYPAD_read();
				} while (first==0xff);
				
				_delay_ms(200);
				LCD_movecursor(1,9);
				LCD_writecharacter(first);
				
				do
				{
					second=KEYPAD_read();
				} while (second==0xff);
				
				
				LCD_writecharacter(second);
				_delay_ms(500);
				minutes_counter=(first-48)*10+(second-48);
				LCD_clearscreen();
				
				
				LCD_writestring("seconds=--");
				do
				{
					first=KEYPAD_read();
				} while (first==0xff);
				
				_delay_ms(200);
				LCD_movecursor(1,9);
				LCD_writecharacter(first);
				
				do
				{
					second=KEYPAD_read();
				} while (second==0xff);
				
				LCD_writecharacter(second);
				_delay_ms(500);
				seconds_counter=(first-48)*10+(second-48);
				LCD_clearscreen();
				
				LCD_writestring("press 1 to");
				LCD_movecursor(2,1);
				LCD_writestring("set time");
			}
			

			
			else{
				LCD_clearscreen();
				LCD_writestring("wrong choice");
				_delay_ms(500);
				LCD_clearscreen();
				LCD_writestring("press 1 to");
				LCD_movecursor(2,1);
				LCD_writestring("set time");
			}
			
		}
		
		DIO_writepin('C',0,0);
		DIO_writepin('C',1,1);
		DIO_writepin('C',2,1);
		DIO_writepin('C',3,1);
		DIO_writepin('C',4,1);
		DIO_writepin('C',5,1);
		SEVENSEGMENT_write('B',seconds_counter%10);
		_delay_ms(5);
		
		DIO_writepin('C',0,1);
		DIO_writepin('C',1,0);
		DIO_writepin('C',2,1);
		DIO_writepin('C',3,1);
		DIO_writepin('C',4,1);
		DIO_writepin('C',5,1);
		SEVENSEGMENT_write('B',seconds_counter/10);
		_delay_ms(5);
		
		DIO_writepin('C',0,1);
		DIO_writepin('C',1,1);
		DIO_writepin('C',2,0);
		DIO_writepin('C',3,1);
		DIO_writepin('C',4,1);
		DIO_writepin('C',5,1);
		SEVENSEGMENT_write('B',minutes_counter%10);
		_delay_ms(5);
		
		DIO_writepin('C',0,1);
		DIO_writepin('C',1,1);
		DIO_writepin('C',2,1);
		DIO_writepin('C',3,0);
		DIO_writepin('C',4,1);
		DIO_writepin('C',5,1);
		SEVENSEGMENT_write('B',minutes_counter/10);
		_delay_ms(5);
		
		DIO_writepin('C',0,1);
		DIO_writepin('C',1,1);
		DIO_writepin('C',2,1);
		DIO_writepin('C',3,1);
		DIO_writepin('C',4,0);
		DIO_writepin('C',5,1);
		SEVENSEGMENT_write('B',hours_counter%10);
		_delay_ms(5);
		
		DIO_writepin('C',0,1);
		DIO_writepin('C',1,1);
		DIO_writepin('C',2,1);
		DIO_writepin('C',3,1);
		DIO_writepin('C',4,1);
		DIO_writepin('C',5,0);
		SEVENSEGMENT_write('B',hours_counter/10);
		_delay_ms(5);
		
		if(seconds_counter>=60)
		{
			seconds_counter=0;
			minutes_counter++;
		}
		
		if(minutes_counter>=60)
		{
			minutes_counter=0;
			hours_counter++;
		}
		
		if(hours_counter>=24)
		{
			hours_counter=0;
		}
	}
}

ISR(TIMER2_OVF_vect)
{
	seconds_counter++;
}



























































