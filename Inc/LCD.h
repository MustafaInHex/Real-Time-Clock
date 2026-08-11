#ifndef LCD_H_
#define LCD_H_

#define FOUR_BIT  // 4 BIT OR 8 BIT

#include "DIO.h"
#define F_CPU 8000000UL
#include <util/delay.h>


#define CLEAR_SCREEN 0x01 
#define RETURN_HOME 0x02
#define DISPLAY_ON_CURSOR_ON 0x0E
#define ENTRY_MODE 0x06
#define EIGHT_BIT_MODE 0x38
#define FOUR_BIT_MODE 0x28

#define DATA_PORT 'A'
#define CONTROL_PORT 'A'
#define EN 2
#define RS 3



void LCD_enable();
void LCD_writecmd(unsigned char cmd);
void LCD_initialize();
void LCD_writecharacter(unsigned char data);
void LCD_writestring(char * ptr);
void LCD_clearscreen();   // CONTAINS THE 10MS DELAY 
void LCD_movecursor(char row , char column);



#endif /* LCD_H_ */