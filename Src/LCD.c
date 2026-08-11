#include "LCD.h"

void LCD_enable()
{
	DIO_writepin(CONTROL_PORT,EN,1);
	_delay_ms(2);
	DIO_writepin(CONTROL_PORT,EN,0);
	_delay_ms(2);
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void LCD_writecmd(unsigned char cmd)
{
	#if defined EIGHT_BIT
	{
		DIO_writeport(DATA_PORT,cmd);
		DIO_writepin(CONTROL_PORT,RS,0);
		LCD_enable();
	}
	
	#elif defined FOUR_BIT
	{
		
		DIO_highnibblewrite(DATA_PORT,cmd>>4);
		DIO_writepin(CONTROL_PORT,RS,0);
		LCD_enable();
		DIO_highnibblewrite(DATA_PORT,cmd);
		LCD_enable();
	}
	
	#endif
	_delay_ms(1);
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void LCD_initialize()
{
	_delay_ms(200);
	#if defined EIGHT_BIT
	{
		DIO_portdirection(DATA_PORT,1);
		DIO_pindirection(CONTROL_PORT,RS,1);
		DIO_pindirection(CONTROL_PORT,EN,1);
		
		LCD_writecmd(EIGHT_BIT_MODE);
		LCD_writecmd(DISPLAY_ON_CURSOR_ON);
		LCD_writecmd(CLEAR_SCREEN);
		_delay_ms(10);
		LCD_writecmd(ENTRY_MODE);
	}
	
	#elif defined FOUR_BIT
	{
		DIO_pindirection(DATA_PORT,4,1);
		DIO_pindirection(DATA_PORT,5,1);
		DIO_pindirection(DATA_PORT,6,1);
		DIO_pindirection(DATA_PORT,7,1);
		
		DIO_pindirection(CONTROL_PORT,RS,1);
		DIO_pindirection(CONTROL_PORT,EN,1);
		
		LCD_writecmd(RETURN_HOME);
		_delay_ms(10);
		LCD_writecmd(FOUR_BIT_MODE);
		LCD_writecmd(DISPLAY_ON_CURSOR_ON);
		LCD_writecmd(CLEAR_SCREEN);
		_delay_ms(10);
		LCD_writecmd(ENTRY_MODE);
	}
	
	#endif
	
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void LCD_writecharacter(unsigned char data)
{
	#if defined EIGHT_BIT
	{
		DIO_writeport(DATA_PORT,data);
		DIO_writepin(CONTROL_PORT,RS,1);
		LCD_enable();
		
	}
	
	#elif defined FOUR_BIT
	{
		
		DIO_highnibblewrite(DATA_PORT,data>>4);
		DIO_writepin(CONTROL_PORT,RS,1);
		LCD_enable();
		DIO_highnibblewrite(DATA_PORT,data);
		LCD_enable();
	}
	
	#endif
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void LCD_writestring(char * ptr)
{
	int i=0;
	while (ptr[i] != '\0')
	{
		LCD_writecharacter(ptr[i]);
		i++;
	}
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void LCD_movecursor(char row , char column)
{
	int move;
	if(row<1 || row>2 || column<1 || column>16 )
	{
		move=0x80;
	}
	else if (row==1)
	{
		move=0x80+column-1;
	}
	else if (row==2)
	{
		move=0xC0+column-1;
	}
	LCD_writecmd(move);
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


LCD_clearscreen()
{
	LCD_writecmd(CLEAR_SCREEN);
	_delay_ms(10);
}